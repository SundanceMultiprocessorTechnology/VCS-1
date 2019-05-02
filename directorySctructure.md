# Directory Structure
```
../VCS-1
├── directorySctructure.md
├── Documents
│   ├── EMC2-DP Design Specification (QCF51) v3-4.pdf
│   ├── EMC2-DP Starter's Guide v3.1 (QCF32).pdf
│   ├── FM191_DESIGN_SPECIFICATION_(QCF51)_V1_3_2.pdf
│   ├── FM191_Schematics_v1-1.pdf
│   ├── README.md
│   ├── TRM-TE0820-03.pdf
│   └── VCS-1.pdf
├── Figures
│   ├── Power_dif.jpg
│   └── VS2.png
├── Hardware
│   ├── README.md
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
│       │   ├── EMC2-DP_TE0715_30_1C
│       │   │   └── 1.0
│       │   │       ├── board.xml
│       │   │       ├── EMC2-DP_TE0715-30-1C.png
│       │   │       ├── part0_pins.xml
│       │   │       └── preset.xml
│       │   ├── EMC2-DP_TE0820_3EG_1E
│       │   │   └── 1.0
│       │   │       ├── board.xml
│       │   │       ├── EMC2_DP_TE0820_3EG_1E.png
│       │   │       ├── part0_pins.xml
│       │   │       └── preset.xml
│       │   ├── EMC2-DP_TE0820_4CG_1EA
│       │   │   └── 1.0
│       │   │       ├── board.xml
│       │   │       ├── EMC2_DP_TE0820_4CG_1EA.png
│       │   │       ├── part0_pins.xml
│       │   │       └── preset.xml
│       │   ├── EMC2-DP_TE0820_4EV_1E
│       │   │   └── 1.0
│       │   │       ├── board.xml
│       │   │       ├── EMC2-DP_TE0820_4EV_1E.png
│       │   │       ├── part0_pins.xml
│       │   │       └── preset.xml
│       │   ├── FM191-RU
│       │   │   └── 1.0
│       │   │       ├── board.xml
│       │   │       └── preset.xml
│       │   ├── FM191-RU_RPI
│       │   │   └── 1.0
│       │   │       ├── board.xml
│       │   │       └── preset.xml
│       │   └── README.md
│       ├── Firmware
│       │   ├── 2017.4
│       │   │   ├── IP_Repo_7S
│       │   │   │   ├── SPI_Buffering
│       │   │   │   │   ├── component.xml
│       │   │   │   │   ├── constrs_1
│       │   │   │   │   │   └── new
│       │   │   │   │   │       └── SMT-FMC-R_Constraints.xdc
│       │   │   │   │   ├── sources_1
│       │   │   │   │   │   └── new
│       │   │   │   │   │       └── SPI_Buffering.vhd
│       │   │   │   │   ├── SPI_rtl.xml
│       │   │   │   │   ├── SPI.xml
│       │   │   │   │   └── xgui
│       │   │   │   │       └── SPI_Buffering_v1_0.tcl
│       │   │   │   └── sundance.com_user_SPI_Buffering_1.0.zip
│       │   │   ├── IP_Repo_ZU
│       │   │   │   ├── Interfaces
│       │   │   │   │   └── spi_custom
│       │   │   │   │       ├── SPI_rtl.xml
│       │   │   │   │       └── SPI.xml
│       │   │   │   └── ip
│       │   │   │       ├── axis_fb_conv_1.0
│       │   │   │       │   ├── bd
│       │   │   │       │   │   └── bd.tcl
│       │   │   │       │   ├── component.xml
│       │   │   │       │   ├── src
│       │   │   │       │   │   └── axis_fb_conv_v1_0.vhd
│       │   │   │       │   └── xgui
│       │   │   │       │       └── axis_fb_conv_v1_0.tcl
│       │   │   │       ├── SPI_US_Buffering
│       │   │   │       │   ├── component.xml
│       │   │   │       │   ├── SPI_US_Buffering.vhd
│       │   │   │       │   └── xgui
│       │   │   │       │       └── SPI_US_Buffering_v1_0.tcl
│       │   │   │       └── video_io_to_hdmi
│       │   │   │           ├── component.xml
│       │   │   │           ├── video_io_to_hdmi.vhd
│       │   │   │           └── xgui
│       │   │   │               └── video_io_to_hdmi_v1_0.tcl
│       │   │   ├── README.md
│       │   │   ├── Z7030
│       │   │   │   └── FM191-RU
│       │   │   │       ├── FM191_Z7030_BIF.sh
│       │   │   │       ├── FM191_Z7030.c
│       │   │   │       ├── FM191_Z7030.sh
│       │   │   │       ├── FM191_Z7030.tcl
│       │   │   │       ├── FM191_Z7030.xdc
│       │   │   │       └── README.md
│       │   │   ├── ZU3EG
│       │   │   │   ├── FM191-RU
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_ZU3EG_BIF.sh
│       │   │   │   │   ├── FM191_ZU3EG.c
│       │   │   │   │   ├── FM191_ZU3EG.sh
│       │   │   │   │   ├── FM191_ZU3EG.tcl
│       │   │   │   │   ├── FM191_ZU3EG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   ├── FM191-RU_RPI
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_RPI_ZU3EG_BIF.sh
│       │   │   │   │   ├── FM191_RPI_ZU3EG.c
│       │   │   │   │   ├── FM191_RPI_ZU3EG.sh
│       │   │   │   │   ├── FM191_RPI_ZU3EG.TCL
│       │   │   │   │   ├── FM191_RPI_ZU3EG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   └── README.md
│       │   │   ├── ZU4CG
│       │   │   │   ├── FM191-RU
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_ZU4CG_BIF.sh
│       │   │   │   │   ├── FM191_ZU4CG.c
│       │   │   │   │   ├── FM191_ZU4CG.sh
│       │   │   │   │   ├── FM191_ZU4CG.tcl
│       │   │   │   │   ├── FM191_ZU4CG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   ├── FM191-RU_RPI
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_RPI_ZU4CG_BIF.sh
│       │   │   │   │   ├── FM191_RPI_ZU4CG.c
│       │   │   │   │   ├── FM191_RPI_ZU4CG.sh
│       │   │   │   │   ├── FM191_RPI_ZU4CG.TCL
│       │   │   │   │   ├── FM191_RPI_ZU4CG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   └── README.md
│       │   │   └── ZU4EV
│       │   │       ├── FM191-RU
│       │   │       │   ├── eeprom.h
│       │   │       │   ├── FM191_ZU4EV_BIF.sh
│       │   │       │   ├── FM191_ZU4EV.c
│       │   │       │   ├── FM191_ZU4EV.sh
│       │   │       │   ├── FM191_ZU4EV.tcl
│       │   │       │   ├── FM191_ZU4EV.xdc
│       │   │       │   ├── Prebuilt
│       │   │       │   │   ├── BOOT.bin
│       │   │       │   │   ├── design_1_wrapper.bit
│       │   │       │   │   └── design_1_wrapper.hdf
│       │   │       │   └── README.md
│       │   │       ├── FM191-RU_RPI
│       │   │       │   ├── eeprom.h
│       │   │       │   ├── FM191_RPI_ZU4EV_BIF.sh
│       │   │       │   ├── FM191_RPI_ZU4EV.c
│       │   │       │   ├── FM191_RPI_ZU4EV.sh
│       │   │       │   ├── FM191_RPI_ZU4EV.TCL
│       │   │       │   ├── FM191_RPI_ZU4EV.xdc
│       │   │       │   ├── Prebuilt
│       │   │       │   │   ├── BOOT.bin
│       │   │       │   │   ├── design_1_wrapper.bit
│       │   │       │   │   └── design_1_wrapper.hdf
│       │   │       │   └── README.md
│       │   │       └── README.md
│       │   ├── 2018.3
│       │   │   ├── IP_Repo_7S
│       │   │   │   ├── SPI_Buffering
│       │   │   │   │   ├── component.xml
│       │   │   │   │   ├── constrs_1
│       │   │   │   │   │   └── new
│       │   │   │   │   │       └── SMT-FMC-R_Constraints.xdc
│       │   │   │   │   ├── sources_1
│       │   │   │   │   │   └── new
│       │   │   │   │   │       └── SPI_Buffering.vhd
│       │   │   │   │   ├── SPI_rtl.xml
│       │   │   │   │   ├── SPI.xml
│       │   │   │   │   └── xgui
│       │   │   │   │       └── SPI_Buffering_v1_0.tcl
│       │   │   │   └── sundance.com_user_SPI_Buffering_1.0.zip
│       │   │   ├── IP_Repo_ZU
│       │   │   │   ├── Interfaces
│       │   │   │   │   └── spi_custom
│       │   │   │   │       ├── SPI_rtl.xml
│       │   │   │   │       └── SPI.xml
│       │   │   │   └── ip
│       │   │   │       ├── axis_fb_conv_1.0
│       │   │   │       │   ├── bd
│       │   │   │       │   │   └── bd.tcl
│       │   │   │       │   ├── component.xml
│       │   │   │       │   ├── src
│       │   │   │       │   │   └── axis_fb_conv_v1_0.vhd
│       │   │   │       │   └── xgui
│       │   │   │       │       └── axis_fb_conv_v1_0.tcl
│       │   │   │       ├── dpu_ip
│       │   │   │       │   └── dpu
│       │   │   │       │       ├── bd
│       │   │   │       │       │   └── bd.tcl
│       │   │   │       │       ├── component.xml
│       │   │   │       │       ├── doc
│       │   │   │       │       │   └── dpu_eu_v0_0_53_changelog.txt
│       │   │   │       │       ├── gui
│       │   │   │       │       │   └── dpu_eu_v0_0_53.gtcl
│       │   │   │       │       ├── hdl
│       │   │   │       │       │   └── dpu_eu_v0_0_53_vl_rfs.v
│       │   │   │       │       ├── inc
│       │   │   │       │       │   ├── arch_def.vh
│       │   │   │       │       │   ├── arch_para.vh
│       │   │   │       │       │   └── function.vh
│       │   │   │       │       ├── xdc
│       │   │   │       │       │   ├── timing_clocks.xdc
│       │   │   │       │       │   └── timing_impl_clocks.xdc
│       │   │   │       │       └── xgui
│       │   │   │       │           └── dpu_eu_v0_0_53.tcl
│       │   │   │       ├── SPI_US_Buffering
│       │   │   │       │   ├── component.xml
│       │   │   │       │   ├── SPI_US_Buffering.vhd
│       │   │   │       │   └── xgui
│       │   │   │       │       └── SPI_US_Buffering_v1_0.tcl
│       │   │   │       └── video_io_to_hdmi
│       │   │   │           ├── component.xml
│       │   │   │           ├── video_io_to_hdmi.vhd
│       │   │   │           └── xgui
│       │   │   │               └── video_io_to_hdmi_v1_0.tcl
│       │   │   ├── README.md
│       │   │   ├── Z7030
│       │   │   │   └── FM191-RU
│       │   │   │       ├── FM191_Z7030_BIF.sh
│       │   │   │       ├── FM191_Z7030.c
│       │   │   │       ├── FM191_Z7030.sh
│       │   │   │       ├── FM191_Z7030.tcl
│       │   │   │       ├── FM191_Z7030.xdc
│       │   │   │       ├── Prebuilt
│       │   │   │       │   ├── BOOT.bin
│       │   │   │       │   ├── design_1_wrapper.bit
│       │   │   │       │   └── design_1_wrapper.hdf
│       │   │   │       └── README.md
│       │   │   ├── ZU3EG
│       │   │   │   ├── FM191-RU
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_ZU3EG_BIF.sh
│       │   │   │   │   ├── FM191_ZU3EG.c
│       │   │   │   │   ├── FM191_ZU3EG.sh
│       │   │   │   │   ├── FM191_ZU3EG.tcl
│       │   │   │   │   ├── FM191_ZU3EG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   ├── Prebuilt_DPU
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   ├── FM191-RU_RPI
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_RPI_ZU3EG_BIF.sh
│       │   │   │   │   ├── FM191_RPI_ZU3EG.c
│       │   │   │   │   ├── FM191_RPI_ZU3EG.sh
│       │   │   │   │   ├── FM191_RPI_ZU3EG.TCL
│       │   │   │   │   ├── FM191_RPI_ZU3EG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   ├── Prebuilt_DPU
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   └── README.md
│       │   │   ├── ZU4CG
│       │   │   │   ├── FM191-RU
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_ZU4CG_BIF.sh
│       │   │   │   │   ├── FM191_ZU4CG.c
│       │   │   │   │   ├── FM191_ZU4CG.sh
│       │   │   │   │   ├── FM191_ZU4CG.tcl
│       │   │   │   │   ├── FM191_ZU4CG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   ├── Prebuilt_DPU
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   ├── FM191-RU_RPI
│       │   │   │   │   ├── eeprom.h
│       │   │   │   │   ├── FM191_RPI_ZU4CG_BIF.sh
│       │   │   │   │   ├── FM191_RPI_ZU4CG.c
│       │   │   │   │   ├── FM191_RPI_ZU4CG.sh
│       │   │   │   │   ├── FM191_RPI_ZU4CG.TCL
│       │   │   │   │   ├── FM191_RPI_ZU4CG.xdc
│       │   │   │   │   ├── Prebuilt
│       │   │   │   │   │   ├── BOOT.bin
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   ├── Prebuilt_DPU
│       │   │   │   │   │   ├── design_1_wrapper.bit
│       │   │   │   │   │   └── design_1_wrapper.hdf
│       │   │   │   │   └── README.md
│       │   │   │   └── README.md
│       │   │   └── ZU4EV
│       │   │       ├── FM191-RU
│       │   │       │   ├── eeprom.h
│       │   │       │   ├── FM191_ZU4EV_BIF.sh
│       │   │       │   ├── FM191_ZU4EV.c
│       │   │       │   ├── FM191_ZU4EV.sh
│       │   │       │   ├── FM191_ZU4EV.tcl
│       │   │       │   ├── FM191_ZU4EV.xdc
│       │   │       │   ├── Prebuilt
│       │   │       │   │   ├── BOOT.bin
│       │   │       │   │   ├── design_1_wrapper.bit
│       │   │       │   │   └── design_1_wrapper.hdf
│       │   │       │   ├── Prebuilt_DPU
│       │   │       │   │   ├── design_1_wrapper.bit
│       │   │       │   │   └── design_1_wrapper.hdf
│       │   │       │   └── README.md
│       │   │       ├── FM191-RU_RPI
│       │   │       │   ├── eeprom.h
│       │   │       │   ├── FM191_RPI_ZU4EV_BIF.sh
│       │   │       │   ├── FM191_RPI_ZU4EV.c
│       │   │       │   ├── FM191_RPI_ZU4EV.sh
│       │   │       │   ├── FM191_RPI_ZU4EV.TCL
│       │   │       │   ├── FM191_RPI_ZU4EV.xdc
│       │   │       │   ├── Prebuilt
│       │   │       │   │   ├── BOOT.bin
│       │   │       │   │   ├── design_1_wrapper.bit
│       │   │       │   │   └── design_1_wrapper.hdf
│       │   │       │   ├── Prebuilt_DPU
│       │   │       │   │   ├── design_1_wrapper.bit
│       │   │       │   │   └── design_1_wrapper.hdf
│       │   │       │   └── README.md
│       │   │       └── README.md
│       │   └── README.md
│       ├── Petalinux
│       │   ├── 2017.4
│       │   │   ├── FM191_4EV
│       │   │   │   └── zynqmp_fsbl.elf
│       │   │   ├── FM191_4EV.bsp
│       │   │   ├── FM191_7030.bsp
│       │   │   ├── FM191B_4CG
│       │   │   │   └── zynqmp_fsbl.elf
│       │   │   ├── FM191B_4CG.bsp
│       │   │   ├── FM191_HDMI_4EV
│       │   │   │   └── zynqmp_fsbl.elf
│       │   │   ├── FM191_HDMI_4EV.bsp
│       │   │   └── README.md
│       │   └── 2018.3
│       │       └── placeholder
│       ├── Pinout
│       │   ├── EMC2-DP+TE0820+FM191_Pinout.xlsx
│       │   └── README.md
│       └── README.md
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
    ├── Image_processing
    │   ├── demos
    │   │   ├── README.md
    │   │   ├── yolo3_cpp
    │   │   │   ├── CMakeLists.txt
    │   │   │   ├── README.md
    │   │   │   └── src
    │   │   │       ├── classifyObjects_64.cpp
    │   │   │       └── classifyObjects_arm.cpp
    │   │   ├── YOLO3_parameters
    │   │   │   ├── coco.names
    │   │   │   ├── getWeights.sh
    │   │   │   ├── yolov3.cfg
    │   │   │   ├── yolov3-tiny.cfg
    │   │   │   └── yolov3-tiny.weights
    │   │   └── yolo3_python
    │   │       ├── captureCameraImage.py
    │   │       ├── classifyObjects.py
    │   │       ├── d435i.py
    │   │       ├── d435.py
    │   │       ├── IMU_capture_D435i.py
    │   │       ├── __init__.py
    │   │       ├── __pycache__
    │   │       │   └── d435.cpython-36.pyc
    │   │       └── README.md
    │   ├── laptop
    │   │   └── install_opencv4-0-1_laptop.sh
    │   ├── README.md
    │   └── VCS-1
    │       ├── install_opencv4-0-1_VCS-1.sh
    │       └── install_realsense2_VCS-1.sh
    └── VCS-1_SDK
        ├── README.md
        └── src
            ├── emc2-fm191.cpp
            ├── FM191.cpp
            ├── FM191.hpp
            └── Makefile

150 directories, 375 files
```
