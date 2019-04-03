#!/bin/bash
# Create the .bif file (ZU+) based on relative path
file="./FM191_ZU3EG.bif"
echo "//arch = zynqmp; split = false; format = BIN" > $file
echo "the_ROM_image:" >> $file
echo "{" >> $file
echo "	[fsbl_config]a53_x64" >> $file
echo "	[bootloader]$PWD/FM191_ZU3EG/FM191_ZU3EG.sdk/FSBL/Debug/FSBL.elf" >> $file
echo "	[destination_device = pl]$PWD/FM191_ZU3EG/FM191_ZU3EG.sdk/HardwarePlatform/design_1_wrapper.bit" >> $file
echo "	[destination_cpu = a53-0]$PWD/FM191_ZU3EG/FM191_ZU3EG.sdk/FM191_ZU3EG/Debug/FM191_ZU3EG.elf" >> $file
echo "}" >> $file
cat $file
# Run XSDK
source /home/Xilinx/SDK/2018.3/settings64.sh
xsdk -batch

