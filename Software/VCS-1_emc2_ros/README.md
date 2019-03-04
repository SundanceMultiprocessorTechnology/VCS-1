# ROS on the VCS-1 (emc2-Z7030-fm191)

The EMC2-ROS Microsoft Windows SDK is made available using the the GPLv3 open source license.

## The emc2-Z7030-fm191-ros image 

1. Download the emc2-Z7030-fm191-ros image from [here](https://tinyurl.com/emc2-fm191-ros-img-gz).

2. Restore the image into a 16GB uSD card by following the instructions below:
```
$ sudo su
$ bzcat <<path to file>>/emc2-fm191-ros-img-gz | dd of=/dev/mmcblk1
$ rm <<path to file>>/emc2-fm191-ros-img-gz
```
    
NOTE 1: The process of restoring the image will take several minutes (+/- 1h)

NOTE 2: This procedure was tested in Ubuntu 16.04 LTS
    
## Documentation

Online documentation can be found [here](https://github.com/SundanceMultiprocessorTechnology/emc2-ros/wiki)

## Sundance contacts:

* Software and Firmware: Emilie Wheatley <emilie.w@sundance.com>

* Software and Hardware: Pedro Machado <pedro.m@sundance.com>

* Firmware and Hardware: Timoteo Garcia Bertoa <timoteo.gb@sundance.com>



2018, [Sundance Multiprocessor Technologies Ltd.](http://sundance.com) (c) GPLv3
