#! /bin/bash
#
# Script to install the realsense library on the VCS-1 with Python bindings
#
echo "Preparing to install librealsense. This could take up to two hours and sudo password will be prompted."
echo "NOTE: Installation files will be deleted after successful installation."

#
# Pre-requisites
#
sudo apt update
sudo apt upgrade
sudo apt-get install python3 python3-dev git linux-generic-lts-xenial xserver-xorg-core-lts-xenial xserver-xorg-lts-xenial xserver-xorg-video-all-lts-xenial xserver-xorg-input-all-lts-xenial libwayland-egl1-mesa-lts-xenial libssl-dev libusb-1.0-0-dev pkg-config libgtk-3-dev libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev

git clone https://github.com/IntelRealSense/librealsense.git
mkdir librealsense/build
cmake librealsense -DBUILD_PYTHON_BINDINGS=bool:true

# Make with two jobs: more jobs causes the RAM to swap a lot, increasing the overall execution time.
cd librealsense/build && make -j2
cd librealsemse/build && sudo make install

echo "Updating PYTHONPATH in .bashrc file"
echo "export PYTHONPATH=$PYTHONPATH:/usr/local/lib" >> ~/.bashrc
export PYTHONPATH=$PYTHONPATH:/usr/local/lib

echo 
echo 
echo "Testing python3 installation..."
python3 -c "import pyrealsense2" 2> /dev/null
if [ $? -ne 0 ] 
then
    echo "Installation failed."
else 
    echo "Installation succeeded!"
    rm -rf librealsense
fi
