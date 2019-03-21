# Script to generate HW Platform, FSBL, and App standalone based on .hdf file. 

#!/usr/bin/tclsh
#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]
# Create workspace 
setws $script_path/FM191_Z7030/FM191_Z7030.sdk
# Create Hardware Platform project
createhw -name HardwarePlatform -hwspec $script_path/FM191_Z7030/FM191_Z7030.sdk/design_1_wrapper.hdf
# Create FSBL project
createapp -name FSBL -app {Zynq FSBL} -proc ps7_cortexa9_0 -hwproject HardwarePlatform -os standalone
# Create Hello World project
createapp -name FM191_Z7030 -app {Hello World} -proc ps7_cortexa9_0 -hwproject HardwarePlatform -os standalone
# Delete helloworld.c
file delete -force $script_path/FM191_Z7030/FM191_Z7030.sdk/FM191_Z7030/src/helloworld.c
cd $script_path
file copy -force ./FM191_Z7030.c ./FM191_Z7030/FM191_Z7030.sdk/FM191_Z7030/src
#Add math.h library
configapp -app FM191_Z7030 libraries m
# Build projects
projects -build
exec bootgen -arch zynq -image FM191_Z7030.bif -w -o BOOT.bin
exit
