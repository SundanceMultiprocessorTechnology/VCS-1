#!/bin/bash
# Create the .bif file (ZU+) based on relative path
file="./FM191_Z7030.bif"
echo "//arch = zynq; split = false; format = BIN" > $file
echo "the_ROM_image:" >> $file
echo "{" >> $file
echo "	[bootloader]$PWD/FM191_Z7030/FM191_Z7030.sdk/FSBL/Debug/FSBL.elf" >> $file
echo "	$PWD/FM191_Z7030/FM191_Z7030.sdk/HardwarePlatform/design_1_wrapper.bit" >> $file
echo "	$PWD/FM191_Z7030/FM191_Z7030.sdk/FM191_Z7030/Debug/FM191_Z7030.elf" >> $file
echo "}" >> $file
cat $file
# Run XSDK
source /home/Xilinx/SDK/2018.3/settings64.sh
xsdk -batch

