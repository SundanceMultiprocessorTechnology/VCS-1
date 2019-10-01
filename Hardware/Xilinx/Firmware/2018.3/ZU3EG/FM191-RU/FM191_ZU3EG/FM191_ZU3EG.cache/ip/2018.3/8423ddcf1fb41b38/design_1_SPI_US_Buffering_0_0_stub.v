// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
// Date        : Mon Jul  1 11:06:11 2019
// Host        : SUN-Lin01 running 64-bit Ubuntu 16.04.6 LTS
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_1_SPI_US_Buffering_0_0_stub.v
// Design      : design_1_SPI_US_Buffering_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu3eg-sfvc784-1-e
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "SPI_US_Buffering,Vivado 2018.3" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(emio_spi0_m_i, emio_spi0_m_o, emio_spi0_mo_t, 
  emio_spi0_s_i, emio_spi0_s_o, emio_spi0_so_t, emio_spi0_sclk_i, emio_spi0_sclk_o, 
  emio_spi0_sclk_t, emio_spi0_ss_i_n, emio_spi0_ss_o_n, emio_spi0_ss_n_t, SPI_CLK, SPI_MOSI, 
  SPI_MISO, SPI_CS)
/* synthesis syn_black_box black_box_pad_pin="emio_spi0_m_i,emio_spi0_m_o,emio_spi0_mo_t,emio_spi0_s_i,emio_spi0_s_o,emio_spi0_so_t,emio_spi0_sclk_i,emio_spi0_sclk_o,emio_spi0_sclk_t,emio_spi0_ss_i_n,emio_spi0_ss_o_n,emio_spi0_ss_n_t,SPI_CLK,SPI_MOSI,SPI_MISO,SPI_CS" */;
  output emio_spi0_m_i;
  input emio_spi0_m_o;
  input emio_spi0_mo_t;
  output emio_spi0_s_i;
  input emio_spi0_s_o;
  input emio_spi0_so_t;
  output emio_spi0_sclk_i;
  input emio_spi0_sclk_o;
  input emio_spi0_sclk_t;
  output emio_spi0_ss_i_n;
  input emio_spi0_ss_o_n;
  input emio_spi0_ss_n_t;
  output SPI_CLK;
  output SPI_MOSI;
  input SPI_MISO;
  output SPI_CS;
endmodule
