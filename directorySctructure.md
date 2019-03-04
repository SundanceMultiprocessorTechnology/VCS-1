# Directory Structure
```
../VCS-1
├── directorySctructure.md
├── Documentation
├── Documents
│   ├── FM191_DESIGN_SPECIFICATION_(QCF51)_V1_3_1.pdf
│   └── FM191_Schematics_v1-1.pdf
├── Figures
│   ├── Power_dif.jpg
│   └── VS2.png
├── Hardware
│   ├── SD_BOOT
│   │   ├── README.md
│   │   ├── TE820_3EG
│   │   │   ├── BOOT.BIN
│   │   │   └── image.ub
│   │   ├── TE820_4CG
│   │   │   ├── BOOT.BIN
│   │   │   └── image.ub
│   │   ├── TE820_4CG_HDMI
│   │   │   ├── BOOT.BIN
│   │   │   ├── design_1_wrapper.bit
│   │   │   ├── image.ub
│   │   │   └── zynqmp_fsbl.elf
│   │   ├── TE820_4EV
│   │   │   ├── BOOT.BIN
│   │   │   └── image.ub
│   │   └── TE820_4EV_HMDI
│   │       ├── BOOT.BIN
│   │       └── image.ub
│   └── Xilinx
│       ├── BoardFiles
│       │   ├── 2017.4
│       │   │   ├── EMC2-DP_TE0715_30_1C
│       │   │   │   └── 1.0
│       │   │   │       ├── board.xml
│       │   │   │       ├── EMC2-DP_TE0715-30-1C.png
│       │   │   │       ├── part0_pins.xml
│       │   │   │       └── preset.xml
│       │   │   ├── EMC2-DP_TE0820_3EG_1E
│       │   │   │   └── 1.0
│       │   │   │       ├── board.xml
│       │   │   │       ├── EMC2_DP_TE0820_3EG_1E.png
│       │   │   │       ├── part0_pins.xml
│       │   │   │       └── preset.xml
│       │   │   ├── EMC2-DP_TE0820_4EV_1E
│       │   │   │   └── 1.0
│       │   │   │       ├── board.xml
│       │   │   │       ├── EMC2-DP_TE0820_4EV_1E.png
│       │   │   │       ├── part0_pins.xml
│       │   │   │       └── preset.xml
│       │   │   ├── FM191-RU
│       │   │   │   └── 1.0
│       │   │   │       ├── board.xml
│       │   │   │       └── preset.xml
│       │   │   └── README.md
│       │   └── 2018.3
│       │       └── placeholder
│       ├── Firmware
│       │   ├── 2017.4
│       │   │   ├── Z7030
│       │   │   │   ├── BOOT.bin
│       │   │   │   ├── design_1_wrapper.hdf
│       │   │   │   ├── Firmware_FM191.c
│       │   │   │   ├── FM191.tcl
│       │   │   │   ├── FM191.xdc
│       │   │   │   ├── IP_Repo
│       │   │   │   │   ├── SPI_Buffering
│       │   │   │   │   │   ├── component.xml
│       │   │   │   │   │   ├── constrs_1
│       │   │   │   │   │   │   └── new
│       │   │   │   │   │   │       └── SMT-FMC-R_Constraints.xdc
│       │   │   │   │   │   ├── sources_1
│       │   │   │   │   │   │   └── new
│       │   │   │   │   │   │       └── SPI_Buffering.vhd
│       │   │   │   │   │   ├── SPI_rtl.xml
│       │   │   │   │   │   ├── SPI.xml
│       │   │   │   │   │   └── xgui
│       │   │   │   │   │       └── SPI_Buffering_v1_0.tcl
│       │   │   │   │   └── sundance.com_user_SPI_Buffering_1.0.zip
│       │   │   │   ├── README.md
│       │   │   │   ├── SDK_Script.sh
│       │   │   │   └── TE0715_30_1C
│       │   │   │       ├── 1.0
│       │   │   │       │   ├── board.xml
│       │   │   │       │   ├── part0_pins.xml
│       │   │   │       │   ├── preset.xml
│       │   │   │       │   └── TE0715_board.jpg
│       │   │   │       └── 1.1
│       │   │   │           ├── board.xml
│       │   │   │           ├── part0_pins.xml
│       │   │   │           ├── preset.xml
│       │   │   │           └── TE0715_board.jpg
│       │   │   ├── ZU3EG
│       │   │   │   ├── EMC2-DP_TE0820_3EG_1E
│       │   │   │   │   └── 1.0
│       │   │   │   │       ├── board.xml
│       │   │   │   │       ├── EMC2_DP_TE0820_3EG_1E.png
│       │   │   │   │       ├── part0_pins.xml
│       │   │   │   │       └── preset.xml
│       │   │   │   ├── FM191-RU
│       │   │   │   │   └── 1.0
│       │   │   │   │       ├── board.xml
│       │   │   │   │       └── preset.xml
│       │   │   │   ├── FM191_ZU3EG.tcl
│       │   │   │   ├── FM191_ZU3EG.xdc
│       │   │   │   ├── IP_Repo
│       │   │   │   │   ├── Interfaces
│       │   │   │   │   │   └── spi_custom
│       │   │   │   │   │       ├── SPI_rtl.xml
│       │   │   │   │   │       └── SPI.xml
│       │   │   │   │   └── ip
│       │   │   │   │       └── SPI_US_Buffering
│       │   │   │   │           ├── component.xml
│       │   │   │   │           ├── SPI_US_Buffering.vhd
│       │   │   │   │           └── xgui
│       │   │   │   │               └── SPI_US_Buffering_v1_0.tcl
│       │   │   │   └── README.md
│       │   │   ├── ZU4CG
│       │   │   │   ├── design_1_wrapper.bit
│       │   │   │   ├── design_1_wrapper.hdf
│       │   │   │   ├── EMC2-DP_TE0820_4CG_1EA
│       │   │   │   │   └── 1.0
│       │   │   │   │       ├── board.xml
│       │   │   │   │       ├── EMC2_DP_TE0820_4CG_1EA.png
│       │   │   │   │       ├── part0_pins.xml
│       │   │   │   │       └── preset.xml
│       │   │   │   ├── FM191B_ZU4CG.tcl
│       │   │   │   ├── FM191B_ZU4CG.xdc
│       │   │   │   ├── FM191-RU_REVB
│       │   │   │   │   └── 1.0
│       │   │   │   │       ├── board.xml
│       │   │   │   │       └── preset.xml
│       │   │   │   └── README.md
│       │   │   ├── ZU4CG_HDMI
│       │   │   │   ├── IP_Repo
│       │   │   │   │   ├── Interfaces
│       │   │   │   │   │   └── spi_custom
│       │   │   │   │   │       ├── SPI_rtl.xml
│       │   │   │   │   │       └── SPI.xml
│       │   │   │   │   └── ip
│       │   │   │   │       ├── axis_fb_conv_1.0
│       │   │   │   │       │   ├── bd
│       │   │   │   │       │   │   └── bd.tcl
│       │   │   │   │       │   ├── component.xml
│       │   │   │   │       │   ├── src
│       │   │   │   │       │   │   └── axis_fb_conv_v1_0.vhd
│       │   │   │   │       │   └── xgui
│       │   │   │   │       │       └── axis_fb_conv_v1_0.tcl
│       │   │   │   │       ├── SPI_US_Buffering
│       │   │   │   │       │   ├── component.xml
│       │   │   │   │       │   ├── SPI_US_Buffering.vhd
│       │   │   │   │       │   └── xgui
│       │   │   │   │       │       └── SPI_US_Buffering_v1_0.tcl
│       │   │   │   │       └── video_io_to_hdmi
│       │   │   │   │           ├── component.xml
│       │   │   │   │           ├── video_io_to_hdmi.vhd
│       │   │   │   │           └── xgui
│       │   │   │   │               └── video_io_to_hdmi_v1_0.tcl
│       │   │   │   ├── README.md
│       │   │   │   └── VCS-1_FM191-ZU4CG_HDMI_FW.xpr.zip
│       │   │   ├── ZU4EV
│       │   │   │   ├── BOOT.bin
│       │   │   │   ├── design_1_wrapper.hdf
│       │   │   │   ├── EMC2-DP_TE0820_4EV_1E
│       │   │   │   │   └── 1.0
│       │   │   │   │       ├── board.xml
│       │   │   │   │       ├── EMC2-DP_TE0820_4EV_1E.png
│       │   │   │   │       ├── part0_pins.xml
│       │   │   │   │       └── preset.xml
│       │   │   │   ├── FM191_ZU4EV.tcl
│       │   │   │   ├── FM191_ZU4EV.xdc
│       │   │   │   ├── IP_Repo
│       │   │   │   │   ├── Interfaces
│       │   │   │   │   │   └── spi_custom
│       │   │   │   │   │       ├── SPI_rtl.xml
│       │   │   │   │   │       └── SPI.xml
│       │   │   │   │   └── ip
│       │   │   │   │       └── SPI_US_Buffering
│       │   │   │   │           ├── component.xml
│       │   │   │   │           ├── SPI_US_Buffering.vhd
│       │   │   │   │           └── xgui
│       │   │   │   │               └── SPI_US_Buffering_v1_0.tcl
│       │   │   │   ├── README.md
│       │   │   │   ├── SDK_Script.sh
│       │   │   │   └── Test.c
│       │   │   └── ZU4EV_HDMI
│       │   │       ├── FM191_ZU4EVVCS-1_FM191-ZU4EV_HDMI_FW.xpr.zip
│       │   │       ├── IP_Repo
│       │   │       │   ├── Interfaces
│       │   │       │   │   └── spi_custom
│       │   │       │   │       ├── SPI_rtl.xml
│       │   │       │   │       └── SPI.xml
│       │   │       │   └── ip
│       │   │       │       ├── axis_fb_conv_1.0
│       │   │       │       │   ├── bd
│       │   │       │       │   │   └── bd.tcl
│       │   │       │       │   ├── component.xml
│       │   │       │       │   ├── src
│       │   │       │       │   │   └── axis_fb_conv_v1_0.vhd
│       │   │       │       │   └── xgui
│       │   │       │       │       └── axis_fb_conv_v1_0.tcl
│       │   │       │       ├── SPI_US_Buffering
│       │   │       │       │   ├── component.xml
│       │   │       │       │   ├── SPI_US_Buffering.vhd
│       │   │       │       │   └── xgui
│       │   │       │       │       └── SPI_US_Buffering_v1_0.tcl
│       │   │       │       └── video_io_to_hdmi
│       │   │       │           ├── component.xml
│       │   │       │           ├── video_io_to_hdmi.vhd
│       │   │       │           └── xgui
│       │   │       │               └── video_io_to_hdmi_v1_0.tcl
│       │   │       └── README.md
│       │   └── 2018.3
│       │       └── placeholder
│       └── Petalinux
│           ├── 2017.4
│           │   ├── FM191_4EV
│           │   │   └── zynqmp_fsbl.elf
│           │   ├── FM191_4EV.bsp
│           │   ├── FM191_7030.bsp
│           │   ├── FM191B_4CG
│           │   │   └── zynqmp_fsbl.elf
│           │   ├── FM191B_4CG.bsp
│           │   ├── FM191_HDMI_4EV
│           │   │   └── zynqmp_fsbl.elf
│           │   ├── FM191_HDMI_4EV.bsp
│           │   └── README.md
│           └── 2018.4
│               └── placeholder
├── LICENSE.md
├── push.sh
├── README.md
└── Software
    ├── ARM_NN
    │   ├── armnn-dist-caffe.tar.xz
    │   ├── armnn-dist.tar.gz
    │   ├── installNNVCS-1.sh
    │   ├── LICENSE.md
    │   ├── push.sh
    │   └── README.md
    ├── FM191_SDK
    │   ├── examples
    │   │   └── FM191_test
    │   │       ├── FM191_test
    │   │       ├── FM191_test.cpp
    │   │       └── Makefile
    │   ├── include
    │   │   └── FM191.hpp
    │   ├── lib
    │   │   └── libFM191.a
    │   ├── python
    │   │   ├── buildPythonWrappers.sh
    │   │   ├── fm191.cpp
    │   │   ├── fm191.hpp
    │   │   ├── fm191.hpp.gch
    │   │   ├── fm191.i
    │   │   ├── fm191.py
    │   │   ├── fm191.pyc
    │   │   ├── _fm191.so
    │   │   ├── fm191_wrap.cxx
    │   │   ├── gpio.cpp
    │   │   ├── gpio.hpp
    │   │   ├── gpio.hpp.gch
    │   │   ├── Makefile
    │   │   ├── spi.cpp
    │   │   ├── spi.hpp
    │   │   ├── spi.hpp.gch
    │   │   ├── uart.cpp
    │   │   ├── uart.hpp
    │   │   └── uart.hpp.gch
    │   ├── README.md
    │   └── src
    │       ├── fm191.cpp
    │       ├── FM191.o
    │       ├── gpio.cpp
    │       ├── gpio.hpp
    │       ├── gpio.o
    │       ├── Makefile
    │       ├── spi.cpp
    │       ├── spi.hpp
    │       ├── spi.o
    │       ├── uart.cpp
    │       ├── uart.hpp
    │       └── uart.o
    ├── FM191_standalone
    │   ├── Apogee
    │   │   └── src
    │   │       ├── main.ino
    │   │       ├── SDI12.cpp
    │   │       └── SDI12.h
    │   ├── eeprom.cpp
    │   ├── eeprom.hpp
    │   ├── emc2-vs1
    │   ├── emc2-vs1.cpp
    │   ├── FM191.cpp
    │   ├── FM191.hpp
    │   ├── GPIO
    │   │   ├── Makefile
    │   │   ├── testGPIO
    │   │   └── testGPIO.cpp
    │   ├── gpio.cpp
    │   ├── gpio.hpp
    │   ├── Makefile
    │   ├── pwm.cpp
    │   ├── pwm.hpp
    │   ├── README.md
    │   ├── SPI
    │   │   ├── Makefile
    │   │   ├── test_spi
    │   │   └── testSPI.cpp
    │   ├── spi.cpp
    │   ├── spi.hpp
    │   ├── UART
    │   │   ├── Makefile
    │   │   ├── test_uart
    │   │   └── test_uart.cpp
    │   ├── uart.cpp
    │   └── uart.hpp
    ├── getSerialNumber
    │   ├── BOOT.bin
    │   ├── README.md
    │   ├── SD
    │   │   ├── design_1_wrapper.bit
    │   │   ├── eeprom_serialnb.elf
    │   │   ├── fsbl.elf
    │   │   ├── output.bif
    │   │   └── pmufw.elf
    │   └── src
    │       ├── eeprom_serialnb.c
    │       ├── lscript.ld
    │       ├── platform.c
    │       ├── platform_config.h
    │       └── platform.h
    ├── RealSense2
    │   ├── readme.md
    │   └── realsense_setup.sh
    ├── Scripts
    │   ├── captuteImageOpenCV.sh
    │   ├── classifyObjects.py
    │   ├── d435.py
    │   ├── install_opencv4-0-1.sh
    │   ├── parameters
    │   │   ├── coco.names
    │   │   ├── getWeights.sh
    │   │   ├── yolov3.cfg
    │   │   └── yolov3.weights
    │   └── README.md
    ├── VCS-1_FM191_SerialNumber
    └── VCS-1_SDK
        ├── README.md
        └── src
            ├── emc2-fm191.cpp
            ├── FM191.cpp
            ├── FM191.hpp
            └── Makefile

117 directories, 237 files
```
