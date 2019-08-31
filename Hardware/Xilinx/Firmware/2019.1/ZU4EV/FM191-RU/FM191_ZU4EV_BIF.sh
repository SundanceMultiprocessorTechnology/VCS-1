#!/bin/bash
# Create the .bif file (ZU+) based on relative path
file="./FM191_ZU4EV.bif"
echo "//arch = zynqmp; split = false; format = BIN" > $file
echo "the_ROM_image:" >> $file
echo "{" >> $file
echo "	[fsbl_config]a53_x64" >> $file
echo "	[bootloader]$PWD/FM191_ZU4EV/FM191_ZU4EV.sdk/FSBL/Debug/FSBL.elf" >> $file
echo "	[destination_device = pl]$PWD/FM191_ZU4EV/FM191_ZU4EV.sdk/HardwarePlatform/design_1_wrapper.bit" >> $file
echo "	[destination_cpu = a53-0]$PWD/FM191_ZU4EV/FM191_ZU4EV.sdk/FM191_ZU4EV/Debug/FM191_ZU4EV.elf" >> $file
echo "}" >> $file
cat $file
# Run XSDK
source $HOME/Xilinx/Scout/2019.1/settings64.sh
xsdk -batch

