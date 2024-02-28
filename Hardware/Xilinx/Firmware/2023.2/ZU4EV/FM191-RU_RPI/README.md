# VCS-1 FM191 Firmware
This repository contains the required files to generate a hardware design for EMC2-DP using TE0820-4EV + FM191-RU (RPI), and generate a linux kernel.

Software used:
* Vivado 2023.2
* Vitis 2023.2
* Petalinux 2023.3 (Running on Ubuntu 18.04)

The instructions can be found [here](https://github.com/SundanceMultiprocessorTechnology/VCS-1/wiki/Build-Firmware).

or 
To create the vivado project:
>source FM191_RPI_ZU4EV.tcl

To create the vitis project and boot.bin
>./FM191_RPI_ZU4EV_BIF.sh (to create the .bif file)
>exec /tools/Xilinx/Vitis/2023.2/bin/xsct
>source FM191_RPI_ZU4EV_xsct.tcl

Sundance contact: 
* Emilie Wheatley emilie.w@sundance.com

2023, [Sundance Multiprocessor Technologies Ltd.](http://www.sundance.technology/) (c) All rights reserved
