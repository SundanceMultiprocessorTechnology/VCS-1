# Script to generate HW Platform, FSBL, and App standalone based on .hdf file. 

###!/usr/bin/bash
##script_path="$( cd "$( script_pathname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
##source /home/Xilinx/SDK/2018.3/settings64.sh
##xsdk -batch

#!/usr/bin/tclsh
#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]
# Create workspace 
setws $script_path/FM191_ZU4CG/FM191_ZU4CG.sdk
# Create Hardware Platform project
createhw -name HardwarePlatform -hwspec $script_path/FM191_ZU4CG/FM191_ZU4CG.sdk/design_1_wrapper.hdf
# Create FSBL project
createapp -name FSBL -app {Zynq MP FSBL} -proc psu_cortexa53_0 -hwproject HardwarePlatform -os standalone
# Create Hello World project
createapp -name FM191_ZU4CG -app {Hello World} -proc psu_cortexa53_0 -hwproject HardwarePlatform -os standalone
# Delete helloworld.c
file delete -force $script_path/FM191_ZU4CG/FM191_ZU4CG.sdk/FM191_ZU4CG/src/helloworld.c
# Add application and eeprom.h
cd $script_path
file copy -force ./FM191_ZU4CG.c ./FM191_ZU4CG/FM191_ZU4CG.sdk/FM191_ZU4CG/src
file copy -force ./eeprom.h ./FM191_ZU4CG/FM191_ZU4CG.sdk/FM191_ZU4CG/src
#Add math.h library
configapp -app FM191_ZU4CG libraries m
# Build projects
projects -build
exec bootgen -arch zynqmp -image FM191_ZU4CG.bif -w -o BOOT.bin
exit