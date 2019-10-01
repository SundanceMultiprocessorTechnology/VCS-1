# Script to generate HW Platform, FSBL, and App standalone based on .hdf file. 

#!/usr/bin/tclsh
#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]
# Create workspace 
setws $script_path/FM191_RPI_ZU4EV/FM191_RPI_ZU4EV.sdk
# Create Hardware Platform project
createhw -name HardwarePlatform -hwspec $script_path/FM191_RPI_ZU4EV/FM191_RPI_ZU4EV.sdk/design_1_wrapper.hdf
# Create FSBL project
createapp -name FSBL -app {Zynq MP FSBL} -proc psu_cortexa53_0 -hwproject HardwarePlatform -os standalone
# Create Hello World project
createapp -name FM191_RPI_ZU4EV -app {Hello World} -proc psu_cortexa53_0 -hwproject HardwarePlatform -os standalone
# Delete helloworld.c
file delete -force $script_path/FM191_RPI_ZU4EV/FM191_RPI_ZU4EV.sdk/FM191_RPI_ZU4EV/src/helloworld.c
# Add application and eeprom.h
cd $script_path
file copy -force ./FM191_RPI_ZU4EV.c ./FM191_RPI_ZU4EV/FM191_RPI_ZU4EV.sdk/FM191_RPI_ZU4EV/src
file copy -force ./eeprom.h ./FM191_RPI_ZU4EV/FM191_RPI_ZU4EV.sdk/FM191_RPI_ZU4EV/src
#Add math.h library
configapp -app FM191_RPI_ZU4EV libraries m
# Build projects
projects -build
exec bootgen -arch zynqmp -image FM191_RPI_ZU4EV.bif -w -o BOOT.bin
exit
