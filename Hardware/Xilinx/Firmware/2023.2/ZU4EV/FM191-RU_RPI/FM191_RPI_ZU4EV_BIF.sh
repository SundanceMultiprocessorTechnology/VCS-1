#!/bin/bash
# Create the .bif file (ZU+) based on relative path
file="./FM191_RPI_ZU4EV.bif"
echo "//arch = zynqmp; split = false; format = BIN" > $file
echo "the_ROM_image:" >> $file
echo "{" >> $file
echo "	[bootloader , destination_cpu = a53-0]$PWD/FM191_RPI_ZU4EV/vitis/FSBL/Debug/FSBL.elf" >> $file
echo "	[destination_device = pl]$PWD/FM191_RPI_ZU4EV/vitis/HardwarePlatform/hw/design_1_wrapper.bit" >> $file
echo "	[destination_cpu = a53-0]$PWD/FM191_RPI_ZU4EV/vitis/FM191_RPI_ZU4EV/Debug/FM191_RPI_ZU4EV.elf" >> $file
echo "}" >> $file
cat $file

