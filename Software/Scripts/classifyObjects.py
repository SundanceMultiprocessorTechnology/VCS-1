#! /usr/bin/python3
#===============================================================================
# IMPORT STATEMENTS
#===============================================================================

import numpy as np
import time
import cv2
import os
import time


#===============================================================================
# GLOBAL VARIABLES DECLARATIONS
#===============================================================================


TRAIN_PATH="parameters/"
conf=0.5
threshold=0.3
stackFlag=True
rsFlag=False
import socket
if socket.gethostname()=='VCS-1':
	invColor=True
	classes_index = 1  # default 0
else:
	invColor=False
	classes_index = 0  # default 0
classes=["coco.names","coco.names"]
weights=["yolov3.weights","yolov3-tiny.weights"]
config=["yolov3.cfg","yolov3-tiny.cfg"]
if rsFlag:
	import d435

#===============================================================================
# METHODS
#===============================================================================



def files(path):
	files=[]
	for file in os.listdir(path):
		if os.path.isfile(os.path.join(path, file)):
			files.append(file)
	return files

def main():
	if rsFlag:
		camera=d435.d435()
		pipeline, align, clipping_distance, NIR=camera.setup()
	else:
		camera = cv2.VideoCapture(0)

	# load the COCO class labels our YOLO model was trained on
	labelsPath = TRAIN_PATH + classes[classes_index]
	LABELS = open(labelsPath).read().strip().split("\n")

	# initialize a list of colors to represent each possible class label
	np.random.seed(42)
	COLORS = np.random.randint(0, 255, size=(len(LABELS), 3),
							   dtype="uint8")

	# derive the paths to the YOLO weights and model configuration
	if not os.path.isfile(TRAIN_PATH + weights[classes_index]):
		os.system(TRAIN_PATH + "getWeights.sh")
	weightsPath = TRAIN_PATH + weights[classes_index]
	configPath = TRAIN_PATH + config[classes_index]

	# load our YOLO object detector trained on COCO dataset (80 classes)
	#print("[INFO] loading YOLO from disk...")
	net = cv2.dnn.readNetFromDarknet(configPath, weightsPath)

	try:
		while True:
			if rsFlag:
				# Wait for a coherent pair of frames: depth and color
				frames = pipeline.wait_for_frames()

				# Align the depth frame to color frame
				aligned_frames = align.process(frames)

				# Get aligned frames
				aligned_depth_frame = aligned_frames.get_depth_frame()  # aligned_depth_frame is a 640x480 depth image
				color_aligned_frame = aligned_frames.get_color_frame()

				if NIR:
					nir_lf_frame = frames.get_infrared_frame(1)
					nir_rg_frame = frames.get_infrared_frame(2)

				if NIR:
					if not aligned_depth_frame or not color_aligned_frame or not nir_lf_frame or not nir_rg_frame:
						continue
				else:
					if not aligned_depth_frame or not color_aligned_frame:
						continue

				# Convert images to numpy arrays
				depth_image = np.asanyarray(aligned_depth_frame.get_data())
				image = np.asanyarray(color_aligned_frame.get_data())

				# Remove background - Set pixels further than clipping_distance to grey
				grey_color = 153
				depth_image_3d = np.dstack(
					(depth_image, depth_image, depth_image))  # depth image is 1 channel, color is 3 channels
				bg_removed = np.where((depth_image_3d > clipping_distance) | (depth_image_3d <= 0), grey_color, image)

				if NIR:
					nir_lf_image = np.asanyarray(nir_lf_frame.get_data())
					nir_rg_image = np.asanyarray(nir_rg_frame.get_data())
				# Apply colormap on depth image (image must be converted to 8-bit per pixel first)
				depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)
			else:
				# Capture frame-by-frame
				ret, image = camera.read()
			(H, W) = image.shape[:2]
			if invColor:
				image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

			# determine only the *output* layer names that we need from YOLO
			ln = net.getLayerNames()
			ln = [ln[i[0] - 1] for i in net.getUnconnectedOutLayers()]

			# construct a blob from the input image and then perform a forward
			# pass of the YOLO object detector, giving us our bounding boxes and
			# associated probabilities
			blob = cv2.dnn.blobFromImage(image, 1 / 255.0, (416, 416), swapRB=True, crop=False)
			net.setInput(blob)
			start = time.time()
			layerOutputs = net.forward(ln)
			end = time.time()

			# show timing information on YOLO
			# print("[INFO] YOLO took {:.6f} seconds".format(end - start))

			# initialize our lists of detected bounding boxes, confidences, and
			# class IDs, respectively
			boxes = []
			confidences = []
			classIDs = []

			# loop over each of the layer outputs
			for output in layerOutputs:
				# loop over each of the detections
				for detection in output:
					# extract the class ID and confidence (i.e., probability) of
					# the current object detection
					scores = detection[5:]
					classID = np.argmax(scores)
					confidence = scores[classID]

					# filter out weak predictions by ensuring the detected
					# probability is greater than the minimum probability
					if confidence > conf:
						# scale the bounding box coordinates back relative to the
						# size of the image, keeping in mind that YOLO actually
						# returns the center (x, y)-coordinates of the bounding
						# box followed by the boxes' width and height
						box = detection[0:4] * np.array([W, H, W, H])
						(centerX, centerY, width, height) = box.astype("int")

						# use the center (x, y)-coordinates to derive the top and
						# and left corner of the bounding box
						x = int(centerX - (width / 2))
						y = int(centerY - (height / 2))

						# update our list of bounding box coordinates, confidences,
						# and class IDs
						boxes.append([x, y, int(width), int(height)])
						confidences.append(float(confidence))
						classIDs.append(classID)

			# apply non-maxima suppression to suppress weak, overlapping bounding
			# boxes
			idxs = cv2.dnn.NMSBoxes(boxes, confidences, conf,
									threshold)

			# ensure at least one detection exists
			if len(idxs) > 0:
				# loop over the indexes we are keeping
				for i in idxs.flatten():
					# extract the bounding box coordinates
					(x, y) = (boxes[i][0], boxes[i][1])
					(w, h) = (boxes[i][2], boxes[i][3])

					# draw a bounding box rectangle and label on the image
					color = [int(c) for c in COLORS[classIDs[i]]]
					cv2.rectangle(image, (x, y), (x + w, y + h), color, 2)
					text = "{}: {:.4f}".format(LABELS[classIDs[i]], confidences[i])
					cv2.putText(image, text, (x, y - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
					if rsFlag:
						cv2.rectangle(depth_colormap, (x, y), (x + w, y + h), color, 2)
						cv2.putText(depth_colormap, text, (x, y - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
			# show the output image
			if rsFlag and stackFlag:
				images1 = np.hstack((image, depth_colormap))
				cv2.imshow("Intel RealSense D435 RGB and Depth Map ", images1)
				if NIR:
					images2 = np.hstack((nir_lf_image, nir_rg_image))
					cv2.imshow("Intel RealSense D435 NIRs Left and Right ", images2)

			elif rsFlag and not stackFlag:
				cv2.imshow("Intel RealSense D435 RGB ", image)
				cv2.imshow("Intel RealSense D435 depth map ", depth_colormap)
				if NIR:
					cv2.imshow("Intel RealSense D435 NIR Left ", nir_lf_image)
					cv2.imshow("Intel RealSense D435 NIR Right ", nir_rg_image)
			else:
				cv2.imshow("Camera ", image)
			if cv2.waitKey(1) == 27:
				break  # esc to quit
		cv2.destroyAllWindows()

	finally:
		# Stop streaming
		if rsFlag:
			pipeline.stop()
			del camera
		else:
			camera.release()

#===============================================================================
#  TESTING AREA
#===============================================================================


#===============================================================================
# MAIN METHOD
#===============================================================================
if __name__ == '__main__':
    main()
