-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
-- Date        : Mon Jul  1 12:00:39 2019
-- Host        : SUN-Lin01 running 64-bit unknown
-- Command     : write_vhdl -force -mode synth_stub
--               /home/pedro/Development/VCS-1/Hardware/Xilinx/Firmware/2018.3/ZU3EG/FM191-RU/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_clk_wiz_0_0/design_1_clk_wiz_0_0_stub.vhdl
-- Design      : design_1_clk_wiz_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xczu3eg-sfvc784-1-e
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_clk_wiz_0_0 is
  Port ( 
    clk_666m : out STD_LOGIC;
    clk_333m : out STD_LOGIC;
    clk_100m : out STD_LOGIC;
    clk_in1 : in STD_LOGIC
  );

end design_1_clk_wiz_0_0;

architecture stub of design_1_clk_wiz_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk_666m,clk_333m,clk_100m,clk_in1";
begin
end;
