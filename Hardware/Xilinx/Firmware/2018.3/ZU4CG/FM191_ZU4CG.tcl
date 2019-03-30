################################################################################################
# Company:        Sundance Multiprocessor Technology LTD
# Engineer:       Timoteo Garcia Bertoa
# Design Name:    FM191_ZU4CG
# Tool Versions:  Vivado 18.3
################################################################################################

#Use script's path as project's path
set script_path [file dirname [file normalize [info script]]]

#Create project for FM191_ZU4CG 
create_project FM191_ZU4CG $script_path/FM191_ZU4CG -part xcZU4CG-sfvc784-1-e

#Board part selection
set_property board_part sundance.com:emc2-dp_te0820_3eg_1e:part0:1.0 [current_project]
set_property board_connections {fmc_lpc_connector sundance:fm191-ru:fmc_lpc_connector:1.0} [current_project]

#Add repositories at IP Catalog
set_property  ip_repo_paths  $script_path/IP_Repo [current_project]
update_ip_catalog

#Set target to VHDL
set_property target_language VHDL [current_project]

#Create block design in IP Integrator
create_bd_design "design_1"

#Add Zynq IP. Enable interrupts. Set SPI0 clk to 20MHz
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:zynq_ultra_ps_e:3.2 zynq_ultra_ps_e_0
endgroup
apply_bd_automation -rule xilinx.com:bd_rule:zynq_ultra_ps_e -config {apply_board_preset "1" }  [get_bd_cells zynq_ultra_ps_e_0]

#Enable IRQ, SPI and SATA. Set I2C0 to 38..39
set_property -dict [list CONFIG.PSU__USE__IRQ0 {1} CONFIG.PSU__CRL_APB__SPI0_REF_CTRL__FREQMHZ {20} CONFIG.PSU__SATA__PERIPHERAL__ENABLE {1} CONFIG.PSU__I2C0__PERIPHERAL__IO {MIO 38 .. 39}] [get_bd_cells zynq_ultra_ps_e_0]

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

#----------------------------------------------------------------------------------#
# Adding HDMI support. Comment out this part of the script if not required # BEGIN #
#----------------------------------------------------------------------------------#

#Adding Test Pattern Generator
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:v_tpg:8.0 v_tpg_0
endgroup
set_property -dict [list CONFIG.MAX_COLS {1280} CONFIG.MAX_ROWS {720} CONFIG.HAS_AXI4S_SLAVE {1} CONFIG.FOREGROUND {1}] [get_bd_cells v_tpg_0]

#Adding AXI4 Stream to Video Out
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:v_axi4s_vid_out:4.0 v_axi4s_vid_out_0
endgroup
set_property -dict [list CONFIG.C_HAS_ASYNC_CLK {1} CONFIG.C_VTG_MASTER_SLAVE {0}] [get_bd_cells v_axi4s_vid_out_0]

#Adding Video I/O to HDMI
startgroup
create_bd_cell -type ip -vlnv trenz.biz:user:video_io_to_hdmi:1.0 video_io_to_hdmi_0
endgroup

#Adding Video Timing Controller
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:v_tc:6.1 v_tc_0
endgroup
set_property -dict [list CONFIG.max_clocks_per_line {2048} CONFIG.max_lines_per_frame {2048} CONFIG.enable_detection {false}] [get_bd_cells v_tc_0]

#Adding Axis FB Conv
startgroup
create_bd_cell -type ip -vlnv trenz.biz:user:axis_fb_conv:1.0 axis_fb_conv_0
endgroup

#Adding VDMA
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_vdma:6.3 axi_vdma_0
endgroup
set_property -dict [list CONFIG.c_num_fstores {1} CONFIG.c_mm2s_genlock_mode {0} CONFIG.c_s2mm_genlock_mode {0} CONFIG.c_mm2s_linebuffer_depth {2048} CONFIG.c_include_s2mm {0} CONFIG.c_include_mm2s_dre {1}] [get_bd_cells axi_vdma_0]

#Adding Zynq MP IP AXI ports
startgroup
set_property -dict [list CONFIG.PSU__USE__M_AXI_GP0 {1} CONFIG.PSU__USE__S_AXI_GP2 {1}] [get_bd_cells zynq_ultra_ps_e_0]
endgroup

#Setting second clock to 75MHz
startgroup
set_property -dict [list CONFIG.PSU__CRL_APB__PL1_REF_CTRL__FREQMHZ {75}] [get_bd_cells zynq_ultra_ps_e_0]
endgroup

#Adding secondary AXI Interconnect
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_interconnect_0
endgroup
set_property name axi_interconnect_mem [get_bd_cells axi_interconnect_0]
set_property -dict [list CONFIG.NUM_MI {1}] [get_bd_cells axi_interconnect_mem]

#Adding secondary Reset block
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 proc_sys_reset_0
endgroup
set_property name rst_ps8_0_75M [get_bd_cells proc_sys_reset_0]
set_property -dict [list CONFIG.C_AUX_RESET_HIGH.VALUE_SRC USER] [get_bd_cells rst_ps8_0_75M]
set_property -dict [list CONFIG.C_AUX_RESET_HIGH {0}] [get_bd_cells rst_ps8_0_75M]

#Adding GND and VCC constants
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:xlconstant:1.1 xlconstant_0
endgroup
set_property -dict [list CONFIG.CONST_VAL {0}] [get_bd_cells xlconstant_0]
set_property name GND [get_bd_cells xlconstant_0]
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:xlconstant:1.1 xlconstant_0
endgroup
set_property name VCC [get_bd_cells xlconstant_0]

#Creating ports
create_bd_port -dir O -from 0 -to 0 ct_hpd
create_bd_port -dir O -from 0 -to 0 cec_clk
create_bd_port -dir O -from 0 -to 0 ls_oe

#Adding AXI Interconnect ports
startgroup
set_property -dict [list CONFIG.NUM_SI {2} CONFIG.NUM_MI {11} CONFIG.NUM_MI {11}] [get_bd_cells ps8_0_axi_periph]
endgroup

#Adding Interrupt ports
startgroup
set_property -dict [list CONFIG.NUM_PORTS {7}] [get_bd_cells PLPS_INT]
endgroup

#Making connections
startgroup
make_bd_intf_pins_external  [get_bd_intf_pins video_io_to_hdmi_0/hdmi_out]
endgroup
set_property name hdmi_out [get_bd_intf_ports hdmi_out_0]
connect_bd_intf_net [get_bd_intf_pins axis_fb_conv_0/video_out] [get_bd_intf_pins v_tpg_0/s_axis_video]
connect_bd_intf_net [get_bd_intf_pins axi_vdma_0/M_AXIS_MM2S] [get_bd_intf_pins axis_fb_conv_0/S_AXIS]
connect_bd_intf_net [get_bd_intf_pins video_io_to_hdmi_0/vid_io_in] [get_bd_intf_pins v_axi4s_vid_out_0/vid_io_out]
connect_bd_intf_net [get_bd_intf_pins v_tc_0/vtiming_out] [get_bd_intf_pins v_axi4s_vid_out_0/vtiming_in]
connect_bd_intf_net [get_bd_intf_pins v_tpg_0/m_axis_video] [get_bd_intf_pins v_axi4s_vid_out_0/video_in]
connect_bd_intf_net -boundary_type upper [get_bd_intf_pins ps8_0_axi_periph/M08_AXI] [get_bd_intf_pins axi_vdma_0/S_AXI_LITE]
connect_bd_intf_net -boundary_type upper [get_bd_intf_pins ps8_0_axi_periph/M09_AXI] [get_bd_intf_pins v_tc_0/ctrl]
connect_bd_intf_net -boundary_type upper [get_bd_intf_pins ps8_0_axi_periph/M10_AXI] [get_bd_intf_pins v_tpg_0/s_axi_CTRL]
connect_bd_intf_net [get_bd_intf_pins zynq_ultra_ps_e_0/M_AXI_HPM0_FPD] -boundary_type upper [get_bd_intf_pins ps8_0_axi_periph/S01_AXI]
connect_bd_intf_net -boundary_type upper [get_bd_intf_pins axi_interconnect_mem/M00_AXI] [get_bd_intf_pins zynq_ultra_ps_e_0/S_AXI_HP0_FPD]
connect_bd_intf_net [get_bd_intf_pins axi_vdma_0/M_AXI_MM2S] -boundary_type upper [get_bd_intf_pins axi_interconnect_mem/S00_AXI]
connect_bd_net [get_bd_pins v_axi4s_vid_out_0/vtg_ce] [get_bd_pins v_tc_0/gen_clken]
connect_bd_net [get_bd_ports cec_clk] [get_bd_pins GND/dout]
connect_bd_net [get_bd_pins GND/dout] [get_bd_pins v_axi4s_vid_out_0/fid]
connect_bd_net [get_bd_ports ls_oe] [get_bd_pins VCC/dout]
connect_bd_net [get_bd_ports ct_hpd] [get_bd_pins VCC/dout]
connect_bd_net [get_bd_pins VCC/dout] [get_bd_pins v_axi4s_vid_out_0/aclken]
connect_bd_net [get_bd_pins VCC/dout] [get_bd_pins v_axi4s_vid_out_0/vid_io_out_ce]
connect_bd_net [get_bd_pins VCC/dout] [get_bd_pins v_tc_0/clken]
connect_bd_net [get_bd_pins VCC/dout] [get_bd_pins v_tc_0/s_axi_aclken]
connect_bd_net [get_bd_pins PLPS_INT/In4] [get_bd_pins v_tc_0/irq]
connect_bd_net [get_bd_pins PLPS_INT/In5] [get_bd_pins v_tpg_0/interrupt]
connect_bd_net [get_bd_pins PLPS_INT/In6] [get_bd_pins axi_vdma_0/mm2s_introut]

#Connecting clock 100MHz
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins ps8_0_axi_periph/S01_ACLK]
connect_bd_net [get_bd_pins ps8_0_axi_periph/M08_ACLK] [get_bd_pins zynq_ultra_ps_e_0/pl_clk0]
connect_bd_net [get_bd_pins ps8_0_axi_periph/M09_ACLK] [get_bd_pins zynq_ultra_ps_e_0/pl_clk0]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins zynq_ultra_ps_e_0/saxihp0_fpd_aclk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins zynq_ultra_ps_e_0/maxihpm0_fpd_aclk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins axi_interconnect_mem/ACLK]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins axi_interconnect_mem/S00_ACLK]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins axi_interconnect_mem/M00_ACLK]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins axi_vdma_0/s_axi_lite_aclk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins axi_vdma_0/m_axi_mm2s_aclk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] [get_bd_pins v_tc_0/s_axi_aclk]

#Connecting clock 75MHz
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins ps8_0_axi_periph/M10_ACLK]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins axis_fb_conv_0/s_axis_aclk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins v_tpg_0/ap_clk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins v_tc_0/clk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins v_axi4s_vid_out_0/aclk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins v_axi4s_vid_out_0/vid_io_out_clk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins video_io_to_hdmi_0/vid_io_in_clk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins rst_ps8_0_75M/slowest_sync_clk]
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk1] [get_bd_pins axi_vdma_0/m_axis_mm2s_aclk]

#Connecting reset 100MHz domain
connect_bd_net [get_bd_pins rst_ps8_0_99M/interconnect_aresetn] [get_bd_pins axi_interconnect_mem/ARESETN]
disconnect_bd_net /rst_ps8_0_99M_peripheral_aresetn [get_bd_pins ps8_0_axi_periph/ARESETN]
connect_bd_net [get_bd_pins ps8_0_axi_periph/ARESETN] [get_bd_pins rst_ps8_0_99M/interconnect_aresetn]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins axi_vdma_0/axi_resetn]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins axi_interconnect_mem/S00_ARESETN]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins axi_interconnect_mem/M00_ARESETN]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins ps8_0_axi_periph/S01_ARESETN]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins ps8_0_axi_periph/M08_ARESETN]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins ps8_0_axi_periph/M09_ARESETN]
connect_bd_net [get_bd_pins rst_ps8_0_99M/peripheral_aresetn] [get_bd_pins v_tc_0/s_axi_aresetn]

#Connecting reset 75MHz domain
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_resetn0] [get_bd_pins rst_ps8_0_75M/ext_reset_in]
connect_bd_net [get_bd_pins rst_ps8_0_75M/peripheral_reset] [get_bd_pins v_axi4s_vid_out_0/vid_io_out_reset]
connect_bd_net [get_bd_pins rst_ps8_0_75M/interconnect_aresetn] [get_bd_pins axis_fb_conv_0/s_axis_aresetn]
connect_bd_net [get_bd_pins rst_ps8_0_75M/peripheral_aresetn] [get_bd_pins ps8_0_axi_periph/M10_ARESETN]
connect_bd_net [get_bd_pins rst_ps8_0_75M/peripheral_aresetn] [get_bd_pins v_tpg_0/ap_rst_n]
connect_bd_net [get_bd_pins rst_ps8_0_75M/peripheral_aresetn] [get_bd_pins v_axi4s_vid_out_0/aresetn]
connect_bd_net [get_bd_pins rst_ps8_0_75M/peripheral_aresetn] [get_bd_pins v_tc_0/resetn]

#Assigning addresses
assign_bd_address
include_bd_addr_seg [get_bd_addr_segs -excluded axi_vdma_0/Data_MM2S/SEG_zynq_ultra_ps_e_0_HP0_LPS_OCM]

#----------------------------------------------------------------------------------#
# Adding HDMI support. Comment out this part of the script if not required #  END  #
#----------------------------------------------------------------------------------#

#Regenerate layout
regenerate_bd_layout
regenerate_bd_layout -routing

#Create VHDL wrapper
make_wrapper -files [get_files $script_path/FM191_ZU4CG/FM191_ZU4CG.srcs/sources_1/bd/design_1/design_1.bd] -top
add_files -norecurse $script_path/FM191_ZU4CG/FM191_ZU4CG.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd

#Add constraints file
add_files -fileset constrs_1 -norecurse $script_path/FM191_ZU4CG.xdc

#Build project and generate bitstream
launch_runs impl_1 -to_step write_bitstream -jobs 2
wait_on_run impl_1

#Export .hdf and .bit
file mkdir $script_path/FM191_ZU4CG/FM191_ZU4CG.sdk
file copy -force $script_path/FM191_ZU4CG/FM191_ZU4CG.runs/impl_1/design_1_wrapper.sysdef $script_path/FM191_ZU4CG/FM191_ZU4CG.sdk/design_1_wrapper.hdf

