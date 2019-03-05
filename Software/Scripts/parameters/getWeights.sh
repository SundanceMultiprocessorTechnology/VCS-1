#! /bin/bash
cd parameters
wget https://pjreddie.com/media/files/yolov3.weights
cd ..
echo "parameters/yolov3.weights" > .gitignore
