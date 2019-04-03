#!/bin/bash
# Create the .bif file (ZU+) based on relative path
file="./FM191_RPI_ZU4CG.bif"
echo "//arch = zynqmp; split = false; format = BIN" > $file
echo "the_ROM_image:" >> $file
echo "{" >> $file
echo "	[fsbl_config]a53_x64" >> $file
echo "	[bootloader]$PWD/FM191_RPI_ZU4CG/FM191_RPI_ZU4CG.sdk/FSBL/Debug/FSBL.elf" >> $file
echo "	[destination_device = pl]$PWD/FM191_RPI_ZU4CG/FM191_RPI_ZU4CG.sdk/HardwarePlatform/design_1_wrapper.bit" >> $file
echo "	[destination_cpu = a53-0]$PWD/FM191_RPI_ZU4CG/FM191_RPI_ZU4CG.sdk/FM191_RPI_ZU4CG/Debug/FM191_RPI_ZU4CG.elf" >> $file
echo "}" >> $file
cat $file
# Run XSDK
source /home/Xilinx/SDK/2018.3/settings64.sh
xsdk -batch

