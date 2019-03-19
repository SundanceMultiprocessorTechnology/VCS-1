##############################################################################################
## FM191_ZU4EV Constraints file
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