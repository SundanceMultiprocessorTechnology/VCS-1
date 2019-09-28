##############################################################################################      ##                     #
## FM191_ZU4EV Constraints file                                                                      ##   S U N D A N C E  #
##############################################################################################         ###                 #
# Company:        Sundance Multiprocessor Technology LTD                                                  ####             #
# Engineer:       Timoteo Garcia Bertoa                                                                      ####          #
# Design Name:    FM191_ZU4EV                                                                                    #####     #
# Tool Versions:  Vivado 18.3                                                                                         ######
##############################################################################################                                                                                                         
                                                                                                                                          
##############################################################################################               
# SPI (DAC)
#Pins
set_property PACKAGE_PIN F7 [get_ports SPI_spi_clk]
set_property PACKAGE_PIN G8 [get_ports SPI_spi_mosi]
set_property PACKAGE_PIN E2 [get_ports SPI_spi_miso]
set_property PACKAGE_PIN F2 [get_ports SPI_spi_cs]
#IO Standards
set_property IOSTANDARD LVCMOS18 [get_ports SPI_spi_clk]
set_property IOSTANDARD LVCMOS18 [get_ports SPI_spi_cs]
set_property IOSTANDARD LVCMOS18 [get_ports SPI_spi_miso]
set_property IOSTANDARD LVCMOS18 [get_ports SPI_spi_mosi]
##############################################################################################

##############################################################################################               
# Ethernet LEDs
#Pins
set_property PACKAGE_PIN K8 [get_ports {PHY_LED_TE[0]}]
set_property SLEW FAST [get_ports {PHY_LED_TE[0]}]
set_property PACKAGE_PIN J1 [get_ports {PHY_LED_TE[1]}]
set_property SLEW FAST [get_ports {PHY_LED_TE[1]}]
set_property PACKAGE_PIN A2 [get_ports {PHY_LED[0]}]
set_property SLEW FAST [get_ports {PHY_LED[0]}]
set_property PACKAGE_PIN A1 [get_ports {PHY_LED[1]}]
set_property SLEW FAST [get_ports {PHY_LED[1]}]
#IO Standards
set_property IOSTANDARD LVCMOS18 [get_ports PHY_*]
##############################################################################################

##############################################################################################
# HDMI INTERFACE

#ADV7511
set_property PACKAGE_PIN K3 [get_ports hdmi_out_vsync]
set_property SLEW FAST [get_ports hdmi_out_vsync]
#set_property DRIVE 16 [get_ports hdmi_out_vsync]

set_property PACKAGE_PIN K4 [get_ports hdmi_out_hsync]
set_property SLEW FAST [get_ports hdmi_out_hsync]
#set_property DRIVE 16 [get_ports hdmi_out_hsync]

set_property PACKAGE_PIN L6 [get_ports hdmi_out_clk]
set_property SLEW FAST [get_ports hdmi_out_clk]
#set_property DRIVE 16 [get_ports hdmi_out_clk]

set_property PACKAGE_PIN L7 [get_ports hdmi_out_de]
set_property SLEW FAST [get_ports hdmi_out_de]
#set_property DRIVE 16 [get_ports hdmi_out_de]

set_property PACKAGE_PIN M8 [get_ports {cec_clk[0]}]
set_property IOSTANDARD LVCMOS18 [get_ports {cec_clk[0]}]

##TPD12S016
set_property PACKAGE_PIN L2 [get_ports {ct_hpd[0]}]
set_property PACKAGE_PIN L8 [get_ports {ls_oe[0]}]

set_property IOSTANDARD LVCMOS18 [get_ports {ct_hpd[0]}]
set_property IOSTANDARD LVCMOS18 [get_ports {ls_oe[0]}]

#DATA
set_property PACKAGE_PIN T6 [get_ports {hdmi_out_data[0]}]
set_property PACKAGE_PIN R6 [get_ports {hdmi_out_data[1]}]
set_property PACKAGE_PIN V9 [get_ports {hdmi_out_data[2]}]
set_property PACKAGE_PIN U9 [get_ports {hdmi_out_data[3]}]
set_property PACKAGE_PIN T7 [get_ports {hdmi_out_data[4]}]
set_property PACKAGE_PIN N8 [get_ports {hdmi_out_data[5]}]
set_property PACKAGE_PIN R7 [get_ports {hdmi_out_data[6]}]
set_property PACKAGE_PIN N9 [get_ports {hdmi_out_data[7]}]
set_property PACKAGE_PIN Y8 [get_ports {hdmi_out_data[8]}]
set_property PACKAGE_PIN V8 [get_ports {hdmi_out_data[9]}]
set_property PACKAGE_PIN W8 [get_ports {hdmi_out_data[10]}]
set_property PACKAGE_PIN U8 [get_ports {hdmi_out_data[11]}]

set_property SLEW FAST [get_ports {hdmi_out_data[11]}]
set_property SLEW FAST [get_ports {hdmi_out_data[10]}]
set_property SLEW FAST [get_ports {hdmi_out_data[9]}]
set_property SLEW FAST [get_ports {hdmi_out_data[8]}]
set_property SLEW FAST [get_ports {hdmi_out_data[7]}]
set_property SLEW FAST [get_ports {hdmi_out_data[6]}]
set_property SLEW FAST [get_ports {hdmi_out_data[5]}]
set_property SLEW FAST [get_ports {hdmi_out_data[4]}]
set_property SLEW FAST [get_ports {hdmi_out_data[3]}]
set_property SLEW FAST [get_ports {hdmi_out_data[2]}]
set_property SLEW FAST [get_ports {hdmi_out_data[1]}]
set_property SLEW FAST [get_ports {hdmi_out_data[0]}]

set_property IOSTANDARD LVCMOS18 [get_ports hdmi_*]

#set_property DRIVE 16 [get_ports {hdmi_out_data[11]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[10]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[9]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[8]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[7]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[6]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[5]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[4]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[3]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[2]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[1]}]
#set_property DRIVE 16 [get_ports {hdmi_out_data[0]}]
##############################################################################################
