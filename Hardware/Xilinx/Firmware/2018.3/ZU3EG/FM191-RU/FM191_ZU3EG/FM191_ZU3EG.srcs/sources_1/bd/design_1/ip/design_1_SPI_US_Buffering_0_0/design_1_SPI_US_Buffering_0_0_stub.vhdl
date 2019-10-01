-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
-- Date        : Mon Jul  1 11:06:12 2019
-- Host        : SUN-Lin01 running 64-bit Ubuntu 16.04.6 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/pedro/Development/VCS-1/Hardware/Xilinx/Firmware/2018.3/ZU3EG/FM191-RU/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_SPI_US_Buffering_0_0/design_1_SPI_US_Buffering_0_0_stub.vhdl
-- Design      : design_1_SPI_US_Buffering_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xczu3eg-sfvc784-1-e
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_SPI_US_Buffering_0_0 is
  Port ( 
    emio_spi0_m_i : out STD_LOGIC;
    emio_spi0_m_o : in STD_LOGIC;
    emio_spi0_mo_t : in STD_LOGIC;
    emio_spi0_s_i : out STD_LOGIC;
    emio_spi0_s_o : in STD_LOGIC;
    emio_spi0_so_t : in STD_LOGIC;
    emio_spi0_sclk_i : out STD_LOGIC;
    emio_spi0_sclk_o : in STD_LOGIC;
    emio_spi0_sclk_t : in STD_LOGIC;
    emio_spi0_ss_i_n : out STD_LOGIC;
    emio_spi0_ss_o_n : in STD_LOGIC;
    emio_spi0_ss_n_t : in STD_LOGIC;
    SPI_CLK : out STD_LOGIC;
    SPI_MOSI : out STD_LOGIC;
    SPI_MISO : in STD_LOGIC;
    SPI_CS : out STD_LOGIC
  );

end design_1_SPI_US_Buffering_0_0;

architecture stub of design_1_SPI_US_Buffering_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "emio_spi0_m_i,emio_spi0_m_o,emio_spi0_mo_t,emio_spi0_s_i,emio_spi0_s_o,emio_spi0_so_t,emio_spi0_sclk_i,emio_spi0_sclk_o,emio_spi0_sclk_t,emio_spi0_ss_i_n,emio_spi0_ss_o_n,emio_spi0_ss_n_t,SPI_CLK,SPI_MOSI,SPI_MISO,SPI_CS";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "SPI_US_Buffering,Vivado 2018.3";
begin
end;
