#! /bin/bash

echo "2019 (c) Sundance Multiprocessor Technology Ltd."
echo "script version 1.0"
echo "Installing ARMNN to $HOME/armnn-dist"

export LD_LIBRARY_PATH=$HOME/armnn-dist/armnn/lib
cd $HOME/Development/VCS-1_ARMNN
cp armnn-dist.tar.gz $HOME/
cd $HOME
tar -xzf armnn-dist.tar.gz

echo "Updating repositories..."
sudo apt update
sudo apt upgrade -y
sudo apt dist-upgrade -y
sudo apt autoclean -y
sudo apt autoremove -y
sudo apt install git build-essential cmake cmake-extras default-jre htop openssh* terminator libevent-pthreads-2.1-6 libpthread-stubs0-dev libevent-pthreads-2.1-6 -y

echo "Compiling a simple sample"
cd $HOME/armnn-dist
echo "SimpleSample.cpp -I$HOME/armnn-dist/armnn/include -I$HOME/armnn-dist/boost/include -L$HOME/armnn-dist/armnn/lib -Wall -larmnn -larmnnTfParser -lpthread -lprotobuf -o SimpleSample" | xargs g++
echo "export LD_LIBRARY_PATH='$HOME/armnn-dist/armnn/lib'" >> $HOME/.bashrc
source $HOME/.bashrc
sudo /sbin/ldconfig -v

echo "Running a simple example"
./SimpleSample

echo "Running unit tests"
./UnitTests

echo "Building MNIST demo"
cd mnist-demo
make test

cd ~
rm armnn-dist.tar.gz


