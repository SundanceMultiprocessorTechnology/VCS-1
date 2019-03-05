#! /usr/bin/python3
import numpy as np
import cv2
from imutils.video import WebcamVideoStream
import sys

camera_index=0

# open the video stream 
camera = WebcamVideoStream(camera_index).start()

while(True):
	# Capture frame-by-frame
	img = camera.read()
	
	# Display the resulting frame
	cv2.imshow('Camera',img)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break

# When everything done, release the capture
camera.stop()
cv2.destroyAllWindows()

