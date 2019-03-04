#! /bin/bash

echo "Generating the wrapper code from fm191.i.."
swig -python -c++ fm191.i
echo "Compile the code.."
g++ -fpic -c fm191.hpp fm191_wrap.cxx fm191.cpp uart.hpp uart.cpp spi.hpp spi.cpp gpio.cpp gpio.hpp -I$HOME/intel/intelpython2/include/python2.7/
echo "Link and Build.."
gcc -shared fm191_wrap.o fm191.o uart.o spi.o gpio.o -o _fm191.so -lstdc++
echo "Removing temporary files.."
rm *.o
