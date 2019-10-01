-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
-- Date        : Mon Jul  1 11:06:12 2019
-- Host        : SUN-Lin01 running 64-bit Ubuntu 16.04.6 LTS
-- Command     : write_vhdl -force -mode funcsim
--               /home/pedro/Development/VCS-1/Hardware/Xilinx/Firmware/2018.3/ZU3EG/FM191-RU/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_SPI_US_Buffering_0_0/design_1_SPI_US_Buffering_0_0_sim_netlist.vhdl
-- Design      : design_1_SPI_US_Buffering_0_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xczu3eg-sfvc784-1-e
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_SPI_US_Buffering_0_0_SPI_US_Buffering is
  port (
    SPI_CLK : out STD_LOGIC;
    SPI_MOSI : out STD_LOGIC;
    emio_spi0_m_i : out STD_LOGIC;
    SPI_CS : out STD_LOGIC;
    emio_spi0_sclk_o : in STD_LOGIC;
    emio_spi0_sclk_t : in STD_LOGIC;
    emio_spi0_m_o : in STD_LOGIC;
    emio_spi0_mo_t : in STD_LOGIC;
    SPI_MISO : in STD_LOGIC;
    emio_spi0_ss_o_n : in STD_LOGIC;
    emio_spi0_ss_n_t : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of design_1_SPI_US_Buffering_0_0_SPI_US_Buffering : entity is "SPI_US_Buffering";
end design_1_SPI_US_Buffering_0_0_SPI_US_Buffering;

architecture STRUCTURE of design_1_SPI_US_Buffering_0_0_SPI_US_Buffering is
  signal T : STD_LOGIC;
  attribute CAPACITANCE : string;
  attribute CAPACITANCE of SPI0_MISO_inst : label is "DONT_CARE";
  attribute IBUF_DELAY_VALUE : string;
  attribute IBUF_DELAY_VALUE of SPI0_MISO_inst : label is "0";
  attribute IFD_DELAY_VALUE : string;
  attribute IFD_DELAY_VALUE of SPI0_MISO_inst : label is "AUTO";
  attribute box_type : string;
  attribute box_type of SPI0_MISO_inst : label is "PRIMITIVE";
  attribute CAPACITANCE of SPI0_MOSI_inst : label is "DONT_CARE";
  attribute box_type of SPI0_MOSI_inst : label is "PRIMITIVE";
  attribute CAPACITANCE of SPI0_SCLK_inst : label is "DONT_CARE";
  attribute box_type of SPI0_SCLK_inst : label is "PRIMITIVE";
  attribute CAPACITANCE of SPI0_SS_inst : label is "DONT_CARE";
  attribute box_type of SPI0_SS_inst : label is "PRIMITIVE";
begin
SPI0_MISO_inst: unisim.vcomponents.IBUF
    generic map(
      IOSTANDARD => "DEFAULT"
    )
        port map (
      I => SPI_MISO,
      O => emio_spi0_m_i
    );
SPI0_MOSI_inst: unisim.vcomponents.OBUFT
    generic map(
      IOSTANDARD => "DEFAULT"
    )
        port map (
      I => emio_spi0_m_o,
      O => SPI_MOSI,
      T => emio_spi0_mo_t
    );
SPI0_SCLK_inst: unisim.vcomponents.OBUFT
    generic map(
      IOSTANDARD => "DEFAULT"
    )
        port map (
      I => emio_spi0_sclk_o,
      O => SPI_CLK,
      T => emio_spi0_sclk_t
    );
SPI0_SS_inst: unisim.vcomponents.OBUFT
    generic map(
      IOSTANDARD => "DEFAULT"
    )
        port map (
      I => emio_spi0_ss_o_n,
      O => SPI_CS,
      T => T
    );
SPI0_SS_inst_i_1: unisim.vcomponents.LUT1
    generic map(
      INIT => X"1"
    )
        port map (
      I0 => emio_spi0_ss_n_t,
      O => T
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_SPI_US_Buffering_0_0 is
  port (
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
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of design_1_SPI_US_Buffering_0_0 : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of design_1_SPI_US_Buffering_0_0 : entity is "design_1_SPI_US_Buffering_0_0,SPI_US_Buffering,{}";
  attribute downgradeipidentifiedwarnings : string;
  attribute downgradeipidentifiedwarnings of design_1_SPI_US_Buffering_0_0 : entity is "yes";
  attribute ip_definition_source : string;
  attribute ip_definition_source of design_1_SPI_US_Buffering_0_0 : entity is "package_project";
  attribute x_core_info : string;
  attribute x_core_info of design_1_SPI_US_Buffering_0_0 : entity is "SPI_US_Buffering,Vivado 2018.3";
end design_1_SPI_US_Buffering_0_0;

architecture STRUCTURE of design_1_SPI_US_Buffering_0_0 is
  signal \<const0>\ : STD_LOGIC;
  attribute x_interface_info : string;
  attribute x_interface_info of SPI_CLK : signal is "sundance.com:user:SPI:1.0 SPI SPI_CLK";
  attribute x_interface_info of SPI_CS : signal is "sundance.com:user:SPI:1.0 SPI SPI_CS";
  attribute x_interface_info of SPI_MISO : signal is "sundance.com:user:SPI:1.0 SPI SPI_MISO";
  attribute x_interface_info of SPI_MOSI : signal is "sundance.com:user:SPI:1.0 SPI SPI_MOSI";
  attribute x_interface_info of emio_spi0_m_i : signal is "xilinx.com:interface:spi:1.0 SPI_S IO1_I";
  attribute x_interface_info of emio_spi0_m_o : signal is "xilinx.com:interface:spi:1.0 SPI_S IO0_O";
  attribute x_interface_info of emio_spi0_mo_t : signal is "xilinx.com:interface:spi:1.0 SPI_S IO0_T";
  attribute x_interface_info of emio_spi0_s_i : signal is "xilinx.com:interface:spi:1.0 SPI_S IO0_I";
  attribute x_interface_info of emio_spi0_s_o : signal is "xilinx.com:interface:spi:1.0 SPI_S IO1_O";
  attribute x_interface_info of emio_spi0_sclk_i : signal is "xilinx.com:interface:spi:1.0 SPI_S SCK_I";
  attribute x_interface_info of emio_spi0_sclk_o : signal is "xilinx.com:interface:spi:1.0 SPI_S SCK_O";
  attribute x_interface_info of emio_spi0_sclk_t : signal is "xilinx.com:interface:spi:1.0 SPI_S SCK_T";
  attribute x_interface_info of emio_spi0_so_t : signal is "xilinx.com:interface:spi:1.0 SPI_S IO1_T";
  attribute x_interface_info of emio_spi0_ss_i_n : signal is "xilinx.com:interface:spi:1.0 SPI_S SS_I";
  attribute x_interface_info of emio_spi0_ss_n_t : signal is "xilinx.com:interface:spi:1.0 SPI_S SS_T";
  attribute x_interface_info of emio_spi0_ss_o_n : signal is "xilinx.com:interface:spi:1.0 SPI_S SS_O";
begin
  emio_spi0_sclk_i <= \<const0>\;
  emio_spi0_ss_i_n <= \<const0>\;
  emio_spi0_s_i <= 'Z';
GND: unisim.vcomponents.GND
     port map (
      G => \<const0>\
    );
U0: entity work.design_1_SPI_US_Buffering_0_0_SPI_US_Buffering
     port map (
      SPI_CLK => SPI_CLK,
      SPI_CS => SPI_CS,
      SPI_MISO => SPI_MISO,
      SPI_MOSI => SPI_MOSI,
      emio_spi0_m_i => emio_spi0_m_i,
      emio_spi0_m_o => emio_spi0_m_o,
      emio_spi0_mo_t => emio_spi0_mo_t,
      emio_spi0_sclk_o => emio_spi0_sclk_o,
      emio_spi0_sclk_t => emio_spi0_sclk_t,
      emio_spi0_ss_n_t => emio_spi0_ss_n_t,
      emio_spi0_ss_o_n => emio_spi0_ss_o_n
    );
end STRUCTURE;
