#! /bin/bash
echo "Script for installing the librealsense2 on Ubuntu 18.04 LTS (VCS-1)"
echo "Updating the OS..."
sudo apt update 
sudo apt upgrade -y
echo "Installing dependencies..."
sudo apt install git libssl-dev libusb-1.0-0-dev pkg-config libgtk-3-dev -y

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

echo "Configuring CMAKE with python support ... this will take a couple of minutes minutes..."
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

export CC=/usr/local/bin/gcc-6
export CXX=/usr/local/bin/g++-6
cmake -D CMAKE_BUILD_TYPE="Release"\
      -D FORCE_LIBUVC=ON \
      -D BUILD_PYTHON_BINDINGS=ON \
      -D BUILD_EXAMPLES=OFF  ..

echo "Compiling OpenCV 4.0.1 ... this will take several minutes..."
make -j2
sudo make install
sudo ldconfig
echo "Done!"

