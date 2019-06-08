#! /bin/bash
echo "Script for installing the librealsense2 on Ubuntu 18.04 LTS (VCS-1)"
echo "Updating the OS..."
sudo apt update 
sudo apt upgrade -y
echo "Installing dependencies..."
sudo apt install git libssl-dev libusb-1.0-0-dev pkg-config libgtk-3-dev gcc-6 g++-6 -y

echo "Fetching and unpacking librealsense2 ..."
mkdir -p $HOME/repositories
cd $HOME/repositories
if [ -d librealsense]; then
	cd librealsense
	git pull
else
	git clone https://github.com/IntelRealSense/librealsense.git
	cd librealsense
fi


echo "Installing udev rules ..."
sudo cp config/99-realsense-libusb.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && udevadm trigger

echo "Configuring CMAKE with python support ... this will take a couple of minutes..."
mkdir build
cd build
if [ -f install_manifest.txt ]; then
	echo "Removing old files."
	xarg sudo rm < install_manifest.txt
fi
if [ -f CMakeCache.txt ]; then
	echo "Removing CMakeCache.txt"
	rm CMakeCache.txt
fi
# Compile using gcc-6 by default
export CC=/usr/bin/gcc-6
export CXX=/usr/bin/g++-6
# Cross-compile using gcc-7 by default
# sudo apt install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf -y
# export CC=/usr/bin/arm-linux-gnueabi-gcc-7
# export CXX=/usr/bin/arm-linux-gnueabi-g++-7
cmake -D CMAKE_BUILD_TYPE="Release"\
      -D FORCE_LIBUVC=ON \
      -D BUILD_PYTHON_BINDINGS=ON \
      -D PYTHON_EXECUTABLE=/usr/bin/python3 \
      -D BUILD_EXAMPLES=ON  ..
# Edit CMakeCache.txt and replace O3 flags by O2 when using gcc-7 and g++-7

echo "Compiling librealsense 2... this will take several minutes..."
make -j2
sudo make install
echo 'export PYTHONPATH="$PYTHONPATH:/usr/local/lib"' >> ~/.bashrc
sudo ldconfig
echo "Done!"

