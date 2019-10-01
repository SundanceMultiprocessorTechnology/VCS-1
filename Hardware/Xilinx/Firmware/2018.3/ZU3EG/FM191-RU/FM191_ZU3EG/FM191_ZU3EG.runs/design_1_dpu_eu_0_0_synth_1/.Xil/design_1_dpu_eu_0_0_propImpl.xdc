set_property SRC_FILE_INFO {cfile:/home/pedro/Development/VCS-1/Hardware/Xilinx/Firmware/2018.3/ZU3EG/FM191-RU/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_dpu_eu_0_0/xdc/timing_clocks.xdc rfile:../../../FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_dpu_eu_0_0/xdc/timing_clocks.xdc id:1 order:LATE scoped_inst:inst} [current_design]
current_instance inst
set_property src_info {type:SCOPED_XDC file:1 line:53 export:INPUT save:INPUT read:READ} [current_design]
set_multicycle_path 2 -setup -start -from [get_clocks -of_objects [get_ports dpu_2x_clk]] -to [get_clocks -of_objects [get_ports m_axi_dpu_aclk]]
set_property src_info {type:SCOPED_XDC file:1 line:54 export:INPUT save:INPUT read:READ} [current_design]
set_multicycle_path 2 -setup -end   -from [get_clocks -of_objects [get_ports m_axi_dpu_aclk]] -to [get_clocks -of_objects [get_ports dpu_2x_clk]]
set_property src_info {type:SCOPED_XDC file:1 line:60 export:INPUT save:INPUT read:READ} [current_design]
set clk_indpd [get_property S_AXI_CLK_INDEPENDENT [get_cells -of_objects [get_ports -scoped_to_current_instance m_axi_dpu_aclk  ]]]
set_property src_info {type:SCOPED_XDC file:1 line:61 export:INPUT save:INPUT read:READ} [current_design]
set clk_rs [expr {($clk_indpd=={1})?[get_clocks -of_objects [get_ports -scoped_to_current_instance s_axi_aclk]]:{}}]
set_property src_info {type:SCOPED_XDC file:1 line:62 export:INPUT save:INPUT read:READ} [current_design]
expr {(($clk_rs!={})&&($clk_rs!=$clk_1x))?[set_false_path -from $clk_1x  -to $clk_rs]:{}}
set_property src_info {type:SCOPED_XDC file:1 line:63 export:INPUT save:INPUT read:READ} [current_design]
expr {(($clk_rs!={})&&($clk_rs!=$clk_1x))?[set_false_path -from $clk_rs  -to $clk_1x]:{}}
