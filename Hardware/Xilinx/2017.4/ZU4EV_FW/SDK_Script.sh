# Script to generate HW Platform, FSBL, and App standalone based on .hdf file. 
# Replace <path> for your project path

#!/usr/bin/tclsh
# Create workspace 
set_workspace <path>/FM191_ZU4EV/FM191_ZU4EV.sdk
# Create Hardware Platform project
createhw -name HardwarePlatform -hwspec <path>/FM191_ZU4EV/FM191_ZU4EV.sdk/design_1_wrapper.hdf
# Create FSBL project
createapp -name FSBL -app {Zynq FSBL} -proc ps7_cortexa9_0 -hwproject HardwarePlatform -os standalone
# Create Hello World project
createapp -name Standalone_test -app {Hello World} -proc ps7_cortexa9_0 -hwproject HardwarePlatform -os standalone
# Delete helloworld.c
file delete -force <path>/FM191_ZU4EV/FM191_ZU4EV.sdk/Standalone_test/src/helloworld.c
cd <path>
file copy -force ./Test.c ./FM191_ZU4EV/FM191_ZU4EV.sdk/Standalone_test/src
projects -build
exec bootgen -arch zynq -image output.bif -w -o BOOT.bin
exit
