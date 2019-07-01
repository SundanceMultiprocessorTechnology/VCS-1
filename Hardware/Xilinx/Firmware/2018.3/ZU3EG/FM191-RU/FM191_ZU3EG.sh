#!/usr/bin/tclsh
# Script to generate HW Platform, FSBL, and App standalone based on .hdf file. 

#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]
# Create workspace 
setws $script_path/FM191_ZU3EG/FM191_ZU3EG.sdk
# Create Hardware Platform project
createhw -name HardwarePlatform -hwspec $script_path/FM191_ZU3EG/FM191_ZU3EG.sdk/design_1_wrapper.hdf
# Create FSBL project
createapp -name FSBL -app {Zynq MP FSBL} -proc psu_cortexa53_0 -hwproject HardwarePlatform -os standalone
# Create Hello World project
createapp -name FM191_ZU3EG -app {Hello World} -proc psu_cortexa53_0 -hwproject HardwarePlatform -os standalone
# Delete helloworld.c
file delete -force $script_path/FM191_ZU3EG/FM191_ZU3EG.sdk/FM191_ZU3EG/src/helloworld.c
# Add application and eeprom.h
cd $script_path
file copy -force ./FM191_ZU3EG.c ./FM191_ZU3EG/FM191_ZU3EG.sdk/FM191_ZU3EG/src
file copy -force ./eeprom.h ./FM191_ZU3EG/FM191_ZU3EG.sdk/FM191_ZU3EG/src
#Add math.h library
configapp -app FM191_ZU3EG libraries m
# Build projects
projects -build
exec bootgen -arch zynqmp -image FM191_ZU3EG.bif -w -o BOOT.bin
exit
