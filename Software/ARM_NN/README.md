# VCS-1_ARMNN
This repository stores the installation source files and describes the steps to install the [arm nn](https://developer.arm.com/technologies/machine-learning-on-arm/developer-material/how-to-guides/cross-compiling-arm-nn-for-the-raspberry-pi-and-tensorflow/single-page)  on the VCS-1

## Requirements

### Software
* Ubuntu 18.04 LTS (aarch64)

### Hardware
* VCS-1
* any Zynq Ultrascale+ 

## Installation steps:

### Step 1 Update the OS

```
$ sudo apt update
$ sudo apt upgrade -y
$ sudo apt dist-upgrade -y
$ sudo apt autoclean -y
$ sudo apt autoremove -y
```

### Step 2 Install the base packages

```
$ sudo apt install git build-essential cmake cmake-extras default-jre htop openssh* terminator -y
```

### Step 3 Download and clone the repository
```
$ mkdir -p ~/Development
$ cd ~/Development
$ git clone https://github.com/SundanceMultiprocessorTechnology/VCS-1_ARMNN.git
$ cd VCS-1_ARMNN
```

### Step 4 Install the ARM NN on the VCS-1
```
$ cd ~/Development/VCS-1_ARMNN
$ sudo chmod +X installNNVCS-1.sh
$ ./installNNVCS-1.sh
```
Adapted from [arm.com](https://developer.arm.com/technologies/machine-learning-on-arm/developer-material/how-to-guides/cross-compiling-arm-nn-for-the-raspberry-pi-and-tensorflow/single-page).
## Contacts
* Fatima Kishwar <fatima.k@sundance.com>
* Pedro Machado <pedro.m@sundance.com>

2019 (c) GPLv3 - Sundance Multiprocessor Technology Ltd. 


