################################################################################################
# Company:        Sundance Multiprocessor Technology LTD
# Engineer:       Timoteo Garcia Bertoa
# Design Name:    FM191_Z7030
# Tool Versions:  Vivado 17.4
################################################################################################

#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]

#Create project for FM191_Z7030
create_project FM191_Z7030 $script_path/FM191_Z7030 -part xc7z030sbg485-1

#Board part selection
set_property board_part sundance.com:emc2-dp_te0715_30_1c:part0:1.0 [current_project]
set_property board_connections {fmc_lpc_connector sundance:fm191-ru:fmc_lpc_connector:1.0} [current_project]

#Add repositories at IP Catalog
set_property  ip_repo_paths  $script_path/../../IP_Repo_7S [current_project]
update_ip_catalog

#Set target to VHDL
set_property target_language VHDL [current_project]

#Create block design in IP Integrator
create_bd_design "design_1"

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
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/IOs/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins IOs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/M_LEDs/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins M_LEDs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/C_LEDs/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins C_LEDs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/ADC_UART_RQs/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins ADC_UART_RQs/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/ADC_UART_1/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins ADC_UART_1/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/ADC_UART_2/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins ADC_UART_2/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/ADC_UART_3/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins ADC_UART_3/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config { Clk_master {Auto} Clk_slave {Auto} Clk_xbar {Auto} Master {/processing_system7_0/M_AXI_GP0} Slave {/FMC_I2C/S_AXI} intc_ip {New AXI Interconnect} master_apm {0}}  [get_bd_intf_pins FMC_I2C/S_AXI]
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
connect_bd_net [get_bd_pins PLPS_INT/dout] [get_bd_pins processing_system7_0/IRQ_F2P]

#Regenerate layout
regenerate_bd_layout
regenerate_bd_layout -routing

#Create VHDL wrapper
make_wrapper -files [get_files $script_path/FM191_Z7030/FM191_Z7030.srcs/sources_1/bd/design_1/design_1.bd] -top
add_files -norecurse $script_path/FM191_Z7030/FM191_Z7030.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd

#Add constraints file
add_files -fileset constrs_1 -norecurse $script_path/FM191_Z7030.xdc

#Build project and generate bitstream
launch_runs impl_1 -to_step write_bitstream -jobs 2
wait_on_run impl_1

#Export .hdf and .bit
file mkdir $script_path/FM191_Z7030/FM191_Z7030.sdk
file copy -force $script_path/FM191_Z7030/FM191_Z7030.runs/impl_1/design_1_wrapper.sysdef $script_path/FM191_Z7030/FM191_Z7030.sdk/design_1_wrapper.hdf

