----------------------------------------------------------------------------------
-- Company: Sundance Multiprocessor Technology LTD
-- Engineer: Timoteo Garcia Bertoa
-- 
-- Design Name: EMC2-V2_FM191-RU
-- Module Name: SPI_Buffering
-- Project Name: VineScout
-- Target Devices: EMC²-Z7030 (xc7z030sbg485-1)
-- Tool Versions: Vivado 2016.2
--
-- Additional Comments:
--
-- This design follows the description in Figure 17-8 of the TRM of Zynq-7000 by Xilinx 
-- http://www.cl.cam.ac.uk/research/srg/han/ACS-P35/zynq/Zynq-7000-TRM.pdf (page 541)
--
----------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------
--LIBRARIES
----------------------------------------------------------------------------------------
library IEEE;
    USE IEEE.STD_LOGIC_1164.ALL;
    USE IEEE.NUMERIC_STD.ALL;
library UNISIM;
    use UNISIM.VCOMPONENTS.ALL;
----------------------------------------------------------------------------------------
--ENTITY
----------------------------------------------------------------------------------------
entity SPI_Buffering is
    Port( 
        --SPI from PS-EMIO
        SPI0_SCLK_I : out std_logic; 
        SPI0_SCLK_O : in std_logic; 
        SPI0_SCLK_T : in std_logic; 
        SPI0_MOSI_I : out std_logic; 
        SPI0_MOSI_O : in std_logic; 
        SPI0_MOSI_T : in std_logic; 
        SPI0_MISO_I : out std_logic; 
        SPI0_MISO_O : in std_logic; 
        SPI0_MISO_T : in std_logic; 
        SPI0_SS_I   : out std_logic; 
        SPI0_SS_O   : in std_logic; 
        SPI0_SS1_O  : in std_logic; 
        SPI0_SS2_O  : in std_logic; 
        SPI0_SS_T   : in std_logic;
        --SPI PL
        SPI_CLK     : out std_logic;
        SPI_MOSI    : out std_logic;    
        SPI_MISO    : in std_logic;
        SPI_CS      : out std_logic
    );
end SPI_Buffering;

----------------------------------------------------------------------------------------
--ARCHITECTURE
----------------------------------------------------------------------------------------
architecture RTL of SPI_Buffering is

begin
      
SPI0_SCLK_I <= '0';
SPI0_SS_I <= '1';

    SPI0_SCLK_inst : OBUFT
        port map (
            O => SPI_CLK, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => SPI0_SCLK_O, -- 1-bit input: Buffer input
            T => SPI0_SCLK_T  -- 1-bit input: 3-state enable input
        );
   
    SPI0_MOSI_inst : OBUFT
        port map (
            O => SPI_MOSI, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => SPI0_MOSI_O, -- 1-bit input: Buffer input
            T => SPI0_MOSI_T  -- 1-bit input: 3-state enable input
        );

    SPI0_MISO_inst : IBUF
        port map (
            O => SPI0_MISO_I, -- 1-bit output: Buffer output
            I => SPI_MISO  -- 1-bit input: Buffer input
        );
      
    SPI0_SS_inst : OBUFT
        port map (
            O => SPI_CS, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => SPI0_SS_O, -- 1-bit input: Buffer input
            T => SPI0_SS_T  -- 1-bit input: 3-state enable input
        );    
        
    SPI0_SS1_inst : OBUFT
        port map (
            O => open, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => SPI0_SS1_O, -- 1-bit input: Buffer input
            T => SPI0_SS_T  -- 1-bit input: 3-state enable input
        ); 
            
    SPI0_SS2_inst : OBUFT
        port map (
            O => open, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => SPI0_SS2_O, -- 1-bit input: Buffer input
            T => SPI0_SS_T  -- 1-bit input: 3-state enable input
        );                
           
end RTL;
