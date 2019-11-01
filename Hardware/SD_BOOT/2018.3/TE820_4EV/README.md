# VCS-1 FM191 Firmware
This folder contains the boot files for the VCS-1 ZU4EV tested on Ubuntu 18.04 LTS

## Procedure:

### Step 1: Download and unzip file
```
$ mkdir -p $HOME/tmp
$ cd $HOME/tmp
$ wget https://github.com/SundanceMultiprocessorTechnology/VCS-1/raw/master/Hardware/SD_BOOT/2018.3/TE820_4EV/boot_files_ZU4EV.zip
$ unzip boot_files_ZU4EV.zip
```
### Step 2: Copy files to the sd card
```
$ cp BOOT/* <sd_card_path>/BOOT
$ sudo cp -r rootfs/* <sd_card_path>/rootfs
```
### Step 3: Remove temporary folders
```
$ cd $HOME
$ rm -rf tmp
```
Sundance contact: 
* Pedro Machado <pedro.m@sundance.com>

2019, [Sundance Multiprocessor Technologies Ltd.](http://www.sundance.technology/) (c) All rights reserved
