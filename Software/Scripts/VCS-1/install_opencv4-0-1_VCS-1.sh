#! /bin/bash
echo "Script for installing the OpenCV 4.0.1 on Ubuntu 18.04 LTS (VCS-1)"
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
sudo apt install python3-dev -y
sudo apt install libtbb-dev -y

echo "Fetching and unpacking OpenCV 4.0.1..."
mkdir -p $HOME/repositories
cd $HOME/repositories
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.0.1.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.0.1.zip
wget https://bootstrap.pypa.io/get-pip.py
sudo python3 get-pip.py
sudo -H pip3 install numpy matplotlib imutils -u
unzip opencv.zip
unzip opencv_contrib.zip
rm opencv.zip
rm opencv_contrib.zip
cd opencv-4.0.1
mkdir -p build
cd build

echo "Compiling OpenCV 4.0.1 ... this will take several minutes..."
rm CMakeCache.txt
hostname=$(sudo cat /etc/hostname)
cmake -D CMAKE_BUILD_TYPE=RELEASE \
	-D CMAKE_INSTALL_PREFIX=/usr/local \
	-D INSTALL_PYTHON_EXAMPLES=OFF \
	-D BUILD_EXAMPLES=OFF \
	-D BUILD_TESTS=OFF \
	-D CPU_BASELINE="VFPV4" \
	-D ENABLE_NEON=OFF \
	-D OPENCV_ENABLE_NONFREE=ON \
	-D WITH_OPENMP=ON \
	-D PYTHON_EXECUTABLE=/usr/bin/python3 \
	-D WITH_TBB=ON BUILD_TBB=ON \
	-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.0.1/modules ..
echo "Compilation has started ..."
make -j2
echo "Installing OpenCV 4.0.1 ..."
sudo make install
sudo ldconfig
source $HOME/.bashrc
echo "Installation complete"
