// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
// Date        : Mon Jul  1 11:06:12 2019
// Host        : SUN-Lin01 running 64-bit Ubuntu 16.04.6 LTS
// Command     : write_verilog -force -mode funcsim
//               /home/pedro/Development/VCS-1/Hardware/Xilinx/Firmware/2018.3/ZU3EG/FM191-RU/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_SPI_US_Buffering_0_0/design_1_SPI_US_Buffering_0_0_sim_netlist.v
// Design      : design_1_SPI_US_Buffering_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xczu3eg-sfvc784-1-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "design_1_SPI_US_Buffering_0_0,SPI_US_Buffering,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* ip_definition_source = "package_project" *) 
(* x_core_info = "SPI_US_Buffering,Vivado 2018.3" *) 
(* NotValidForBitStream *)
module design_1_SPI_US_Buffering_0_0
   (emio_spi0_m_i,
    emio_spi0_m_o,
    emio_spi0_mo_t,
    emio_spi0_s_i,
    emio_spi0_s_o,
    emio_spi0_so_t,
    emio_spi0_sclk_i,
    emio_spi0_sclk_o,
    emio_spi0_sclk_t,
    emio_spi0_ss_i_n,
    emio_spi0_ss_o_n,
    emio_spi0_ss_n_t,
    SPI_CLK,
    SPI_MOSI,
    SPI_MISO,
    SPI_CS);
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S IO1_I" *) output emio_spi0_m_i;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S IO0_O" *) input emio_spi0_m_o;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S IO0_T" *) input emio_spi0_mo_t;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S IO0_I" *) output emio_spi0_s_i;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S IO1_O" *) input emio_spi0_s_o;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S IO1_T" *) input emio_spi0_so_t;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S SCK_I" *) output emio_spi0_sclk_i;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S SCK_O" *) input emio_spi0_sclk_o;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S SCK_T" *) input emio_spi0_sclk_t;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S SS_I" *) output emio_spi0_ss_i_n;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S SS_O" *) input emio_spi0_ss_o_n;
  (* x_interface_info = "xilinx.com:interface:spi:1.0 SPI_S SS_T" *) input emio_spi0_ss_n_t;
  (* x_interface_info = "sundance.com:user:SPI:1.0 SPI SPI_CLK" *) output SPI_CLK;
  (* x_interface_info = "sundance.com:user:SPI:1.0 SPI SPI_MOSI" *) output SPI_MOSI;
  (* x_interface_info = "sundance.com:user:SPI:1.0 SPI SPI_MISO" *) input SPI_MISO;
  (* x_interface_info = "sundance.com:user:SPI:1.0 SPI SPI_CS" *) output SPI_CS;

  wire \<const0> ;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire SPI_CLK;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire SPI_CS;
  (* IBUF_LOW_PWR *) wire SPI_MISO;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire SPI_MOSI;
  (* IBUF_LOW_PWR *) wire emio_spi0_m_i;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire emio_spi0_m_o;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire emio_spi0_mo_t;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire emio_spi0_sclk_o;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire emio_spi0_sclk_t;
  wire emio_spi0_ss_n_t;
  (* DRIVE = "12" *) (* SLEW = "SLOW" *) wire emio_spi0_ss_o_n;

  assign emio_spi0_sclk_i = \<const0> ;
  assign emio_spi0_ss_i_n = \<const0> ;
  GND GND
       (.G(\<const0> ));
  design_1_SPI_US_Buffering_0_0_SPI_US_Buffering U0
       (.SPI_CLK(SPI_CLK),
        .SPI_CS(SPI_CS),
        .SPI_MISO(SPI_MISO),
        .SPI_MOSI(SPI_MOSI),
        .emio_spi0_m_i(emio_spi0_m_i),
        .emio_spi0_m_o(emio_spi0_m_o),
        .emio_spi0_mo_t(emio_spi0_mo_t),
        .emio_spi0_sclk_o(emio_spi0_sclk_o),
        .emio_spi0_sclk_t(emio_spi0_sclk_t),
        .emio_spi0_ss_n_t(emio_spi0_ss_n_t),
        .emio_spi0_ss_o_n(emio_spi0_ss_o_n));
endmodule

(* ORIG_REF_NAME = "SPI_US_Buffering" *) 
module design_1_SPI_US_Buffering_0_0_SPI_US_Buffering
   (SPI_CLK,
    SPI_MOSI,
    emio_spi0_m_i,
    SPI_CS,
    emio_spi0_sclk_o,
    emio_spi0_sclk_t,
    emio_spi0_m_o,
    emio_spi0_mo_t,
    SPI_MISO,
    emio_spi0_ss_o_n,
    emio_spi0_ss_n_t);
  output SPI_CLK;
  output SPI_MOSI;
  output emio_spi0_m_i;
  output SPI_CS;
  input emio_spi0_sclk_o;
  input emio_spi0_sclk_t;
  input emio_spi0_m_o;
  input emio_spi0_mo_t;
  input SPI_MISO;
  input emio_spi0_ss_o_n;
  input emio_spi0_ss_n_t;

  wire SPI_CLK;
  wire SPI_CS;
  wire SPI_MISO;
  wire SPI_MOSI;
  wire T;
  wire emio_spi0_m_i;
  wire emio_spi0_m_o;
  wire emio_spi0_mo_t;
  wire emio_spi0_sclk_o;
  wire emio_spi0_sclk_t;
  wire emio_spi0_ss_n_t;
  wire emio_spi0_ss_o_n;

  (* CAPACITANCE = "DONT_CARE" *) 
  (* IBUF_DELAY_VALUE = "0" *) 
  (* IFD_DELAY_VALUE = "AUTO" *) 
  (* box_type = "PRIMITIVE" *) 
  IBUF #(
    .IOSTANDARD("DEFAULT")) 
    SPI0_MISO_inst
       (.I(SPI_MISO),
        .O(emio_spi0_m_i));
  (* CAPACITANCE = "DONT_CARE" *) 
  (* box_type = "PRIMITIVE" *) 
  OBUFT #(
    .IOSTANDARD("DEFAULT")) 
    SPI0_MOSI_inst
       (.I(emio_spi0_m_o),
        .O(SPI_MOSI),
        .T(emio_spi0_mo_t));
  (* CAPACITANCE = "DONT_CARE" *) 
  (* box_type = "PRIMITIVE" *) 
  OBUFT #(
    .IOSTANDARD("DEFAULT")) 
    SPI0_SCLK_inst
       (.I(emio_spi0_sclk_o),
        .O(SPI_CLK),
        .T(emio_spi0_sclk_t));
  (* CAPACITANCE = "DONT_CARE" *) 
  (* box_type = "PRIMITIVE" *) 
  OBUFT #(
    .IOSTANDARD("DEFAULT")) 
    SPI0_SS_inst
       (.I(emio_spi0_ss_o_n),
        .O(SPI_CS),
        .T(T));
  LUT1 #(
    .INIT(2'h1)) 
    SPI0_SS_inst_i_1
       (.I0(emio_spi0_ss_n_t),
        .O(T));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
