################################################################################################
# Change <path> along this file for the desired path where IP_Repo should be placed, and the project will be created
# Board files must be added to <installation_path>/Xilinx/Vivado/201X.X/data/boards/board_files
################################################################################################

#Create project for Firmware FM191. 
create_project Firmware_FM191 <path>/Firmware_FM191 -part xc7z030sbg485-1

#Board part selection
set_property board_part trenz.biz:te0715_04_30_1c:part0:1.1 [current_project]

#Set target to VHDL
set_property target_language VHDL [current_project]

#Create block design in IP Integrator
create_bd_design "design_1"
update_compile_order -fileset sources_1

#Add repositories at IP Catalog
set_property  ip_repo_paths  <path>/IP_Repo [current_project]
update_ip_catalog

#Open IPI
open_bd_design {<path>/Firmware_FM191/Firmware_FM191.srcs/sources_1/bd/design_1/design_1.bd}

#Add Zynq IP. Activate SPI_0 through EMIO, add interrupts and M_AXI_GP0
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 processing_system7_0
endgroup
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" apply_board_preset "1" Master "Disable" Slave "Disable" }  [get_bd_cells processing_system7_0]
startgroup
set_property -dict [list CONFIG.PCW_USE_M_AXI_GP0 {1} CONFIG.PCW_USE_FABRIC_INTERRUPT {1} CONFIG.PCW_IRQ_F2P_INTR {1} CONFIG.PCW_QSPI_GRP_SINGLE_SS_ENABLE {1} CONFIG.PCW_SPI0_PERIPHERAL_ENABLE {1}] [get_bd_cells processing_system7_0]
endgroup

#Add SPI_Buffering IP. Connect to Zynq PS. Make output external
startgroup
create_bd_cell -type ip -vlnv sundance.com:user:SPI_Buffering:1.0 SPI_Buffering_0
endgroup
connect_bd_intf_net [get_bd_intf_pins SPI_Buffering_0/EMIO_SPI] [get_bd_intf_pins processing_system7_0/SPI_0]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins SPI_Buffering_0/SPI]
endgroup
set_property name SPI [get_bd_intf_ports SPI_0]

#Add GPIO Controller for DIOs and GPIOs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
endgroup
set_property name IOs [get_bd_cells axi_gpio_0]
set_property -dict [list CONFIG.C_GPIO_WIDTH {15} CONFIG.C_GPIO2_WIDTH {28} CONFIG.C_IS_DUAL {1} CONFIG.C_ALL_INPUTS_2 {0} CONFIG.C_ALL_OUTPUTS {0}] [get_bd_cells IOs]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins IOs/GPIO]
endgroup
set_property name DIO [get_bd_intf_ports GPIO_0]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins IOs/GPIO2]
endgroup
set_property name GPIO [get_bd_intf_ports GPIO2_0]

#Add GPIO Controller for GPO_LEDs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
endgroup
set_property name GPO_LEDs [get_bd_cells axi_gpio_0]  
set_property -dict [list CONFIG.C_GPIO_WIDTH {4} CONFIG.C_ALL_OUTPUTS {1}] [get_bd_cells GPO_LEDs]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins GPO_LEDs/GPIO]
endgroup
set_property name LEDs [get_bd_intf_ports GPIO_0]

#Add GPIO Controller for ADC_UART_RQs
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
endgroup
set_property name ADC_UART_RQs [get_bd_cells axi_gpio_0]
set_property -dict [list CONFIG.C_GPIO_WIDTH {3} CONFIG.C_ALL_INPUTS {1}] [get_bd_cells ADC_UART_RQs]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins ADC_UART_RQs/GPIO]
endgroup
set_property name UART_RQ [get_bd_intf_ports GPIO_0]

#Add UART Controller for ADC_UART_1
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0
endgroup
set_property name ADC_UART_1 [get_bd_cells axi_uartlite_0]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins ADC_UART_1/UART]
endgroup
set_property name UART_1 [get_bd_intf_ports UART_0]

#Add UART Controller for ADC_UART_2
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0
endgroup
set_property name ADC_UART_2 [get_bd_cells axi_uartlite_0]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins ADC_UART_2/UART]
endgroup
set_property name UART_2 [get_bd_intf_ports UART_0]

#Add UART Controller for ADC_UART_3
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0
endgroup
set_property name ADC_UART_3 [get_bd_cells axi_uartlite_0]
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins ADC_UART_3/UART]
endgroup
set_property name UART_3 [get_bd_intf_ports UART_0]

#Apply AXI connections
startgroup
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_1/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_2/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_3/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins ADC_UART_RQs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins IOs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" intc_ip "New AXI Interconnect" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins GPO_LEDs/S_AXI]
endgroup

#Connect interrupts to PS
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:xlconcat:2.1 xlconcat_0
endgroup
set_property name UART_INT [get_bd_cells xlconcat_0]
set_property -dict [list CONFIG.IN0_WIDTH.VALUE_SRC USER CONFIG.IN2_WIDTH.VALUE_SRC USER CONFIG.IN1_WIDTH.VALUE_SRC USER] [get_bd_cells UART_INT]
set_property -dict [list CONFIG.NUM_PORTS {3}] [get_bd_cells UART_INT]
connect_bd_net [get_bd_pins ADC_UART_1/interrupt] [get_bd_pins UART_INT/In0]
connect_bd_net [get_bd_pins ADC_UART_2/interrupt] [get_bd_pins UART_INT/In1]
connect_bd_net [get_bd_pins ADC_UART_3/interrupt] [get_bd_pins UART_INT/In2]
connect_bd_net [get_bd_pins UART_INT/dout] [get_bd_pins processing_system7_0/IRQ_F2P]

#Regenerate layout
regenerate_bd_layout
regenerate_bd_layout -routing

#Validate
validate_bd_design

#Create VHDL wrapper
make_wrapper -files [get_files <path>/Firmware_FM191/Firmware_FM191.srcs/sources_1/bd/design_1/design_1.bd] -top
add_files -norecurse <path>/Firmware_FM191/Firmware_FM191.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd

#Add constraints file
add_files -fileset constrs_1 -norecurse <path>/FM191.xdc

#Build project and generate bitstream
launch_runs impl_1 -to_step write_bitstream -jobs 2
wait_on_run impl_1

#Export .hdf and .bit
file mkdir <path>/Firmware_FM191/Firmware_FM191.sdk
file copy -force <path>/Firmware_FM191/Firmware_FM191.runs/impl_1/design_1_wrapper.sysdef <path>/Firmware_FM191/Firmware_FM191.sdk/design_1_wrapper.hdf


