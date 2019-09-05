#! /bin/bash
ver=4.1.1
echo "Script for installing the OpenCV $ver on Ubuntu 18.04 LTS"
echo "Updating the OS..."
sudo apt update 
sudo apt upgrade -y
echo "Installing dependencies..."
sudo apt install build-essential cmake unzip pkg-config -y
sudo apt install libjpeg-dev libpng-dev libtiff-dev -y
sudo apt install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev -y
sudo apt install libxvidcore-dev libx264-dev -y
sudo apt install libgtk-3-dev -y
sudo apt install libatlas-base-dev gfortran -y
sudo apt install python3-dev python-dev -y

echo "Fetching and unpacking OpenCV $ver..."
mkdir -p $HOME/repositories
cd $HOME/repositories
wget -O opencv.zip https://github.com/opencv/opencv/archive/$ver.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/$ver.zip
wget https://bootstrap.pypa.io/get-pip.py
sudo python3 get-pip.py
sudo python2 get-pip.py
sudo -H pip3 install pip numpy matplotlib imutils -U
sudo -H pip install pip numpy matplotlib imutils -U
unzip opencv.zip
unzip opencv_contrib.zip
rm opencv.zip
rm opencv_contrib.zip
cd opencv-$ver
mkdir -p build
cd build

echo "Compiling OpenCV $ver... this will take several minutes..."
rm CMakeCache.txt
hostname=$(sudo cat /etc/hostname)
cmake -D CMAKE_BUILD_TYPE=RELEASE \
	-D CMAKE_INSTALL_PREFIX=/usr/local \
	-D INSTALL_PYTHON_EXAMPLES=ON \
	-D INSTALL_C_EXAMPLES=OFF \
	-D OPENCV_ENABLE_NONFREE=ON \
	-D ENABLE_PRECOMPILED_HEADERS=OFF \
	-D OPENCV_EXTRA_MODULES_PATH=~/repositories/opencv_contrib-$ver/modules \
	-D PYTHON_EXECUTABLE=/usr/bin/python3 \
	-D BUILD_EXAMPLES=ON ..
echo "Compilation has started ..."
make -j4
echo "Installing OpenCV $ver ..."
sudo make install
sudo ldconfig
source $HOME/.bashrc
echo "Installation complete"
