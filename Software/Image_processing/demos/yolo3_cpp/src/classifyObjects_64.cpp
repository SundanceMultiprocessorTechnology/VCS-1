//YOLOv3 on OpenCV4.0.1
//reference: https://www.learnopencv.com/deep-learning-based-object-detection-using-yolov3-with-opencv-python-c/

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>



// Remove the bounding boxes with low confidence using non-maxima suppression
void postprocess(cv::Mat& frame, std::vector<cv::Mat>& outs);

// Get the names of the output layers
std::vector<cv::String> getOutputsNames(const cv::dnn::Net& net);

// Draw the predicted bounding box
void drawPred(int classId, float conf, int left, int top, int right, int bottom, cv::Mat& frame);

// Initialize the parameters
float confThreshold = 0.5; // Confidence threshold
float nmsThreshold = 0.4;  // Non-maximum suppression threshold
int inpWidth = 416;        // Width of network's input image
int inpHeight = 416;       // Height of network's input image

static const char* about =
"This sample uses You only look once (YOLO)-Detector (https://arxiv.org/abs/1612.08242) to detect objects on camera/video/image.\n"
"Models can be downloaded here: https://pjreddie.com/darknet/yolo/\n"
"Default network is 416x416.\n"
"Class names can be downloaded here: https://github.com/pjreddie/darknet/tree/master/data\n";

static const char* params =
"{ help         | false              | ./yolo_opencv -source=../data/3.avi }" 
"{ source       | test.jpg           | image or video files for detection  }" 
"{ device       | 0                  | Camera for detection                }"
"{ save         | false              | save result                         }";


std::vector<std::string> classes;
std::string PARAM_PATH="../../YOLO3_parameters/";

int main(int argc, char** argv)
{
    cv::CommandLineParser parser(argc, argv, params);
    // Load names of classes
    std::string classesFile = PARAM_PATH+"coco.names"; 
    std::ifstream classNamesFile(classesFile.c_str());
    if (classNamesFile.is_open())
    {
        std::string className = "";
        while (std::getline(classNamesFile, className))
            classes.push_back(className);
    }
    else{
        std::cout<<"can not open classNamesFile"<<std::endl;
    }
 
    // Give the configuration and weight files for the model
    cv::String modelConfiguration = PARAM_PATH+"yolov3.cfg";
    cv::String modelWeights = PARAM_PATH+"yolov3.weights";
 
    // Load the network
    cv::dnn::Net net = cv::dnn::readNetFromDarknet(modelConfiguration, modelWeights);
    std::cout<<"Read Darknet..."<<std::endl;
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

    cv::VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

// Process frames.
std::cout <<"Processing..."<<std::endl;
cv::Mat frame;
while (1)
{
    // get frame from the video
    cap >> frame;

    // Create a 4D blob from a frame.
    cv::Mat blob;
    cv::dnn::blobFromImage(frame, blob, 1/255.0, cv::Size(inpWidth, inpHeight), cv::Scalar(0,0,0), true, false);
     
    //Sets the input to the network
    net.setInput(blob);
     
    // Runs the forward pass to get output of the output layers
    std::vector<cv::Mat> outs;
    net.forward(outs, getOutputsNames(net));
     
    // Remove the bounding boxes with low confidence
    postprocess(frame, outs);
     
    // Put efficiency information. The function getPerfProfile returns the 
    // overall time for inference(t) and the timings for each of the layers(in layersTimes)
    std::vector<double> layersTimes;
    double freq = cv::getTickFrequency() / 1000;
    double t = net.getPerfProfile(layersTimes) / freq;
    std::string label = cv::format("Inference time for a frame : %.2f ms", t);
    cv::putText(frame, label, cv::Point(0, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255));
     
    // Write the frame with the detection boxes
    cv::Mat detectedFrame;
    frame.convertTo(detectedFrame, CV_8U);
    //show detectedFrame
    cv::imshow("detectedFrame",detectedFrame);

    if(cv::waitKey(10)==27)
    {
        break;
    }
  
}
    std::cout<<"Esc..."<<std::endl;
    return 0;
}


// Get the names of the output layers
std::vector<cv::String> getOutputsNames(const cv::dnn::Net& net)
{
    static std::vector<cv::String> names;
    if (names.empty())
    {
        //Get the indices of the output layers, i.e. the layers with unconnected outputs
        std::vector<int> outLayers = net.getUnconnectedOutLayers();
         
        //get the names of all the layers in the network
        std::vector<cv::String> layersNames = net.getLayerNames();
         
        // Get the names of the output layers in names
        names.resize(outLayers.size());
        for (size_t i = 0; i < outLayers.size(); ++i)
        names[i] = layersNames[outLayers[i] - 1];
    }
    return names;
}


// Remove the bounding boxes with low confidence using non-maxima suppression
void postprocess(cv::Mat& frame, std::vector<cv::Mat>& outs)
{
    std::vector<int> classIds;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;
     
    for (size_t i = 0; i < outs.size(); ++i)
    {
        // Scan through all the bounding boxes output from the network and keep only the
        // ones with high confidence scores. Assign the box's class label as the class
        // with the highest score for the box.
        float* data = (float*)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
        {
            cv::Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            cv::Point classIdPoint;
            double confidence;
            // Get the value and location of the maximum score
            cv::minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);

            if (confidence > confThreshold)
            {
                int centerX = (int)(data[0] * frame.cols);
                int centerY = (int)(data[1] * frame.rows);
                int width = (int)(data[2] * frame.cols);
                int height = (int)(data[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;
                 
                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(cv::Rect(left, top, width, height));
            }
        }
    }

    
    // Perform non maximum suppression to eliminate redundant overlapping boxes with
    // lower confidences
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
    for (size_t i = 0; i < indices.size(); ++i)
    {
        int idx = indices[i];
        cv::Rect box = boxes[idx];
        drawPred(classIds[idx], confidences[idx], box.x, box.y,
                 box.x + box.width, box.y + box.height, frame);
    }
}

// Draw the predicted bounding box
void drawPred(int classId, float conf, int left, int top, int right, int bottom, cv::Mat& frame)
{
    //Draw a rectangle displaying the bounding box
    cv::rectangle(frame, cv::Point(left, top), cv::Point(right, bottom), cv::Scalar(0, 0, 255));
     
    //Get the label for the class name and its confidence
    std::string label = cv::format("%.2f", conf);
    if (!classes.empty())
    {
        CV_Assert(classId < (int)classes.size());
        label = classes[classId] + ":" + label;
    }
    else
    {
        std::cout<<"classes is empty..."<<std::endl;
    }
     
    //Display the label at the top of the bounding box
    int baseLine;
    cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = std::max(top, labelSize.height);
    cv::putText(frame, label, cv::Point(left, top), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,255,255));
}
