# Scripts
This folder contains automatic scripts to install/configure environments.

## Scripts list

### VCS-1
* install_openCV4-0-1_VCS-1.sh - script for download, compile and install openCV 4.0.1 on the VCS-1 (Arm A53)
```
$ install_openCV4-0-1_VCS-1.sh
```
* install_librealsense2_VCS-1.sh - script for download, compile and install openCV 4.0.1 on the VCS-1 (Arm A53)
```
$ install_librealsense2_VCS-1.sh
```
Please make sure that the VCS-1 have at least 2GB of swap memory. One can had a usb stick formated as swap and issue the command
`sudo swapon /dev/sdXY`where X is the char corresponding to the device and Y is the number **e.g /dev/sdb1**. One can check the device using `lsblk`  

### laptop
* install_openCV4-0-1.sh - script for download, compile and install openCV 4.0.1 in Laptops/Workstations
```
$ install_openCV4-0-1.sh
```

### demos/YOLO3_OpenCV
* captureImageOpenCV.sh - script for capturing an image from camera and display it
```
$ ./captureImageOpenCV.sh
```
* classifyObjects.py - Classification using YOLO3 by default and the tiny YOLO3 on the VCS-1
```
$ ./classifyObjects.py
```
