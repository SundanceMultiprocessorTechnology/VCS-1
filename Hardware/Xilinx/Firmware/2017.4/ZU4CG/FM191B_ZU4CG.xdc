##############################################################################################
## FM191_ZU4CG Constraints file
##############################################################################################

##############################################################################################
# SPI (DAC)
#Pins
set_property PACKAGE_PIN F7 [get_ports DAC_SPI_spi_clk]
set_property PACKAGE_PIN G8 [get_ports DAC_SPI_spi_mosi]
set_property PACKAGE_PIN E2 [get_ports DAC_SPI_spi_miso]
set_property PACKAGE_PIN F2 [get_ports DAC_SPI_spi_cs]
#IO Standards
set_property IOSTANDARD LVCMOS18 [get_ports DAC_SPI_spi_clk]
set_property IOSTANDARD LVCMOS18 [get_ports DAC_SPI_spi_cs]
set_property IOSTANDARD LVCMOS18 [get_ports DAC_SPI_spi_miso]
set_property IOSTANDARD LVCMOS18 [get_ports DAC_SPI_spi_mosi]

# SPI (GPIO)
#Pins
set_property PACKAGE_PIN C4 [get_ports GPIO_SPI_spi_clk]
set_property PACKAGE_PIN AG6 [get_ports GPIO_SPI_spi_mosi]
set_property PACKAGE_PIN AG5 [get_ports GPIO_SPI_spi_miso]
set_property PACKAGE_PIN AF3 [get_ports GPIO_SPI_spi_cs]
#IO Standards
set_property IOSTANDARD LVCMOS18 [get_ports GPIO_SPI_spi_clk]
set_property IOSTANDARD LVCMOS18 [get_ports GPIO_SPI_spi_cs]
set_property IOSTANDARD LVCMOS18 [get_ports GPIO_SPI_spi_miso]
set_property IOSTANDARD LVCMOS18 [get_ports GPIO_SPI_spi_mosi]
##############################################################################################

