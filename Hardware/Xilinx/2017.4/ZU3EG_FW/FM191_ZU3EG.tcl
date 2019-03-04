################################################################################################
# Change <path> along this file for the desired path where IP_Repo should be placed, and the project will be created
# Board files must be added to <installation_path>/Xilinx/Vivado/201X.X/data/boards/board_files
################################################################################################

#Create project for Firmware FM191. 
create_project FM191_ZU3EG <path>/FM191_ZU3EG -part xczu3eg-sfvc784-1-e

#Board part selection
set_property board_part sundance.com:emc2-dp_te0820_3eg_1e:part0:1.0 [current_project]
set_property board_connections {fmc_lpc_connector sundance:fm191-ru:fmc_lpc_connector:1.0} [current_project]

#Add repositories at IP Catalog
set_property  ip_repo_paths  <path>/IP_Repo [current_project]
update_ip_catalog

#Set target to VHDL
set_property target_language VHDL [current_project]

#Create block design in IP Integrator
create_bd_design "design_1"

#Add Zynq IP. Enable interrupts. Set SPI0 clk to 20MHz
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:zynq_ultra_ps_e:3.1 zynq_ultra_ps_e_0
endgroup
apply_bd_automation -rule xilinx.com:bd_rule:zynq_ultra_ps_e -config {apply_board_preset "1" }  [get_bd_cells zynq_ultra_ps_e_0]
set_property -dict [list CONFIG.PSU__USE__IRQ0 {1} CONFIG.PSU__CRL_APB__SPI0_REF_CTRL__FREQMHZ {20}] [get_bd_cells zynq_ultra_ps_e_0]

#Add SPI_Buffering IP. Connect to Zynq PS. Make output external
startgroup
create_bd_cell -type ip -vlnv sundance.com:user:SPI_US_Buffering:1.0 SPI_US_Buffering_0
endgroup
connect_bd_intf_net [get_bd_intf_pins zynq_ultra_ps_e_0/SPI_0] [get_bd_intf_pins SPI_US_Buffering_0/SPI_S]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins SPI_US_Buffering_0/SPI]
endgroup
set_property name SPI [get_bd_intf_ports SPI_0]
set_property name SPI_US_Buffering [get_bd_cells SPI_US_Buffering_0]

#Add GPIO Controller for DIOs and GPIOs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
apply_board_connection -board_interface "fmc_lpc_connector_dios" -ip_intf "axi_gpio_0/GPIO" -diagram "design_1" 
endgroup
set_property name DIOs [get_bd_intf_ports fmc_lpc_connector_dios]
set_property name DIO [get_bd_intf_ports DIOs]
apply_board_connection -board_interface "fmc_lpc_connector_onboardgpios" -ip_intf "/axi_gpio_0/GPIO2" -diagram "design_1" 
set_property name GPIO [get_bd_intf_ports fmc_lpc_connector_onboardgpios]
set_property name IOs [get_bd_cells axi_gpio_0]

#Add GPIO Controller for M_LEDs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
apply_board_connection -board_interface "fmc_lpc_connector_onboardleds" -ip_intf "axi_gpio_0/GPIO" -diagram "design_1" 
endgroup
set_property name M_Board_LEDs [get_bd_intf_ports fmc_lpc_connector_onboardleds]
set_property name M_LEDs [get_bd_cells axi_gpio_0]

#Add GPIO Controller for C_LEDs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
apply_board_connection -board_interface "onboardleds" -ip_intf "axi_gpio_0/GPIO" -diagram "design_1" 
endgroup
apply_board_connection -board_interface "phyleds" -ip_intf "/axi_gpio_0/GPIO2" -diagram "design_1" 
set_property name C_Board_LEDs [get_bd_intf_ports onboardleds]
set_property name C_Eth_LEDs [get_bd_intf_ports phyleds]
set_property name C_LEDs [get_bd_cells axi_gpio_0]

#Add GPIO Controller for ADC_UART_RQs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
apply_board_connection -board_interface "fmc_lpc_connector_adc_uart_rq" -ip_intf "axi_gpio_0/GPIO" -diagram "design_1" 
endgroup
set_property name UART_RQ [get_bd_intf_ports fmc_lpc_connector_adc_uart_rq]
set_property name ADC_UART_RQs [get_bd_cells axi_gpio_0]

#Add UART Controller for ADC_UART_1
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0
apply_board_connection -board_interface "fmc_lpc_connector_adc_uart_1" -ip_intf "axi_uartlite_0/UART" -diagram "design_1" 
endgroup
set_property name UART_1 [get_bd_intf_ports fmc_lpc_connector_adc_uart_1]
set_property name ADC_UART_1 [get_bd_cells axi_uartlite_0]

#Add UART Controller for ADC_UART_2
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0
apply_board_connection -board_interface "fmc_lpc_connector_adc_uart_2" -ip_intf "axi_uartlite_0/UART" -diagram "design_1" 
endgroup
set_property name UART_2 [get_bd_intf_ports fmc_lpc_connector_adc_uart_2]
set_property name ADC_UART_2 [get_bd_cells axi_uartlite_0]

#Add UART Controller for ADC_UART_3
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0
apply_board_connection -board_interface "fmc_lpc_connector_adc_uart_3" -ip_intf "axi_uartlite_0/UART" -diagram "design_1" 
endgroup
set_property name UART_3 [get_bd_intf_ports fmc_lpc_connector_adc_uart_3]
set_property name ADC_UART_3 [get_bd_cells axi_uartlite_0]

#Add I2C Controller for FMC I2C bus
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_iic:2.0 axi_iic_0
apply_board_connection -board_interface "fmc_lpc_connector_i2c_fmcbus" -ip_intf "axi_iic_0/IIC" -diagram "design_1" 
endgroup
set_property name I2C [get_bd_intf_ports fmc_lpc_connector_i2c_fmcbus]
set_property name FMC_I2C [get_bd_cells axi_iic_0]
set_property -dict [list CONFIG.C_GPO_WIDTH {1} CONFIG.IIC_FREQ_KHZ {400}] [get_bd_cells FMC_I2C]

#Apply AXI connections
startgroup
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins IOs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins M_LEDs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins C_LEDs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_RQs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_1/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_2/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_3/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/zynq_ultra_ps_e_0/M_AXI_HPM0_LPD" intc_ip "/ps8_0_axi_periph" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins FMC_I2C/S_AXI]
endgroup

#Connect interrupts to PS
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:xlconcat:2.1 xlconcat_0
endgroup
set_property name PLPS_INT [get_bd_cells xlconcat_0]
set_property -dict [list CONFIG.IN0_WIDTH.VALUE_SRC USER CONFIG.IN2_WIDTH.VALUE_SRC USER CONFIG.IN1_WIDTH.VALUE_SRC USER] [get_bd_cells PLPS_INT]
set_property -dict [list CONFIG.NUM_PORTS {4}] [get_bd_cells PLPS_INT]
connect_bd_net [get_bd_pins ADC_UART_1/interrupt] [get_bd_pins PLPS_INT/In0]
connect_bd_net [get_bd_pins ADC_UART_2/interrupt] [get_bd_pins PLPS_INT/In1]
connect_bd_net [get_bd_pins ADC_UART_3/interrupt] [get_bd_pins PLPS_INT/In2]
connect_bd_net [get_bd_pins FMC_I2C/iic2intc_irpt] [get_bd_pins PLPS_INT/In3]
connect_bd_net [get_bd_pins PLPS_INT/dout] [get_bd_pins zynq_ultra_ps_e_0/pl_ps_irq0]

#Regenerate layout
regenerate_bd_layout
regenerate_bd_layout -routing

#Create VHDL wrapper
make_wrapper -files [get_files <path>/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/design_1.bd] -top
add_files -norecurse <path>/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd

#Add constraints file
add_files -fileset constrs_1 -norecurse <path>/FM191_ZU3EG.xdc

#Build project and generate bitstream
launch_runs impl_1 -to_step write_bitstream -jobs 2
wait_on_run impl_1

#Export .hdf and .bit
file mkdir <path>/FM191_ZU3EG/FM191_ZU3EG.sdk
file copy -force <path>/FM191_ZU3EG/FM191_ZU3EG.runs/impl_1/design_1_wrapper.sysdef <path>/FM191_ZU3EG/FM191_ZU3EG.sdk/design_1_wrapper.hdf

