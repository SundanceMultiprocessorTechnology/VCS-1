#! /bin/bash
VERSION="4.1.2"
echo "Script for installing the OpenCV $VERSION on Ubuntu 18.04 LTS (VCS-1)"
echo "Updating the OS..."
sudo apt update 
sudo apt upgrade -y
echo "Installing dependencies..."
sudo apt install build-essential git cmake unzip pkg-config -y
sudo apt install libjpeg-dev libpng-dev libtiff-dev -y
sudo apt install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev -y
sudo apt install libxvidcore-dev libx264-dev -y
sudo apt install libgtk-3-dev -y
sudo apt install libatlas-base-dev gfortran -y
sudo apt install python3-dev python-dev python-numpy python3-numpy -y
sudo apt install libtbb-dev wget -y

echo "Fetching and unpacking OpenCV $VERSION..."
mkdir -p $HOME/repositories
cd $HOME/repositories
wget -O opencv.zip https://github.com/opencv/opencv/archive/$VERSION.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/$VERSION.zip
wget https://bootstrap.pypa.io/get-pip.py
sudo python3 get-pip.py
sudo python2 get-pip.py
sudo -H pip3 install pip numpy matplotlib imutils -U
sudo -H pip2 install pip numpy matplotlib imutils -U
unzip opencv.zip
unzip opencv_contrib.zip
rm opencv.zip
rm opencv_contrib.zip
cd opencv-$VERSION
mkdir -p build
cd build

echo "Compiling OpenCV $VERSION ... this will take several minutes..."
cmake -D CMAKE_BUILD_TYPE=RELEASE \
	-D CMAKE_INSTALL_PREFIX=/usr/local \
	-D INSTALL_PYTHON_EXAMPLES=OFF \
	-D BUILD_EXAMPLES=OFF \
	-D BUILD_TESTS=OFF \
	-D CPU_BASELINE="VFPV4" \
	-D ENABLE_NEON=OFF \
	-D OPENCV_ENABLE_NONFREE=ON \
	-D WITH_OPENMP=ON \
	-D PYTHON_EXECUTABLE=/usr/bin/python2 \
	-D WITH_TBB=ON BUILD_TBB=ON \
	-D ENABLE_PRECOMPILED_HEADERS=OFF\
	-D OPENCV_GENERATE_PKGCONFIG=ON \
	-D BUILD_opencv_python2=ON \
	-D BUILD_opencv_python3=ON \
	-D OPENCV_PC_FILE_NAME=opencv.pc \
	-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-${VERSION}/modules ..
echo "Compilation has started ..."
make -j4
echo "Installing OpenCV $VERSION ..."
sudo make install
sudo ldconfig
source $HOME/.bashrc
echo "Installation complete"
