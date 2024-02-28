# Script to generate HW Platform, FSBL, and App standalone based on .hdf file. 

#!/usr/bin/tclsh
#exec /tools/Xilinx/Vitis/2023.2/bin/xsct

#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]
# Create workspace 
setws $script_path/FM191_RPI_ZU4EV/vitis
# Create Hardware Platform project
platform create -name {HardwarePlatform} -hw {./FM191_RPI_ZU4EV/design_1_wrapper.xsa} -proc {psu_cortexa53_0} -os {standalone} -arch {64-bit} -out {./FM191_RPI_ZU4EV/vitis} -no-boot-bsp;
platform write
platform read {./FM191_RPI_ZU4EV/vitis/HardwarePlatform/platform.spr}
platform active {HardwarePlatform}
bsp reload
bsp setlib -name xilffs -ver 5.1
bsp setlib -name xilpm -ver 5.1
bsp setlib -name xilsecure -ver 5.2
bsp config -append extra_compiler_flags "-DNDEBUG "
bsp write
bsp reload
bsp regenerate
platform generate 
# Create FSBL project
app create -name FSBL -platform HardwarePlatform -proc psu_cortexa53_0 -os standalone -template "Zynq MP FSBL"
# Create Hello World project
app create -name FM191_RPI_ZU4EV -platform HardwarePlatform -proc psu_cortexa53_0 -os standalone -template "Hello World"
# Delete helloworld.c
file delete -force $script_path/FM191_RPI_ZU4EV/vitis/FM191_RPI_ZU4EV/src/helloworld.c
# Add application and eeprom.h
cd $script_path
file copy -force ./xfsbl_config.h ./FM191_RPI_ZU4EV/vitis/FSBL/src
file copy -force ./FM191_RPI_ZU4EV.c ./FM191_RPI_ZU4EV/vitis/FM191_RPI_ZU4EV/src
file copy -force ./eeprom.h ./FM191_RPI_ZU4EV/vitis/FM191_RPI_ZU4EV/src
#Add math.h library
app config -name FM191_RPI_ZU4EV libraries m
# Build projects
projects -build
exec bootgen -arch zynqmp -image FM191_RPI_ZU4EV.bif -w -o BOOT.bin
#exit



