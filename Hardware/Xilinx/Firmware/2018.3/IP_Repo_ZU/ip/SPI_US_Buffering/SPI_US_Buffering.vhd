----------------------------------------------------------------------------------
-- Company: Sundance Multiprocessor Technology LTD
-- Engineer: Timoteo Garcia Bertoa
-- 
-- Design Name: EMC2-V2_FM191-RU
-- Module Name: SPI_US_Buffering
-- Project Name: VineScout
-- Target Devices: EMC2-ZU3EG (xczu3cg-sfvc784-1-e)
-- Tool Versions: Vivado 2017.4
--
-- Additional Comments:
--
-- This design follows the description in Figure 17-8 of the TRM of Zynq-7000 by Xilinx 
-- http://www.cl.cam.ac.uk/research/srg/han/ACS-P35/zynq/Zynq-7000-TRM.pdf (page 541)
-- Names of the signals based on  
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
entity SPI_US_Buffering is
    Port( 
        --SPI from PS-EMIO
        emio_spi0_m_i       : out std_logic;
        emio_spi0_m_o       : in std_logic;    
        emio_spi0_mo_t      : in std_logic;
        emio_spi0_s_i       : out std_logic;
        emio_spi0_s_o       : in std_logic;
        emio_spi0_so_t      : in std_logic;
        emio_spi0_sclk_i    : out std_logic;
        emio_spi0_sclk_o    : in std_logic;
        emio_spi0_sclk_t    : in std_logic;
        emio_spi0_ss_i_n    : out std_logic;
        emio_spi0_ss_o_n    : in std_logic;
        emio_spi0_ss_n_t    : in std_logic;
        --SPI PL
        SPI_CLK     : out std_logic;
        SPI_MOSI    : out std_logic;    
        SPI_MISO    : in std_logic;
        SPI_CS      : out std_logic
    );
end SPI_US_Buffering;

----------------------------------------------------------------------------------------
--ARCHITECTURE
----------------------------------------------------------------------------------------
architecture RTL of SPI_US_Buffering is 

    signal emio_spi0_sclk_tn : std_logic;
    signal emio_spi0_mo_tn   : std_logic;
    signal emio_spi0_ss_n_tn : std_logic;
    signal iemio_spi0_m_i    : std_logic;
    
begin

emio_spi0_sclk_i <= '0';
emio_spi0_sclk_tn <= emio_spi0_sclk_t;
emio_spi0_mo_tn <= emio_spi0_mo_t;
emio_spi0_ss_i_n <= '0';
emio_spi0_ss_n_tn <= not(emio_spi0_ss_n_t);

    SPI0_SCLK_inst : OBUFT
        port map (
            O => SPI_CLK, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => emio_spi0_sclk_o, -- 1-bit input: Buffer input
            T => emio_spi0_sclk_tn  -- 1-bit input: 3-state enable input
        );
   
    SPI0_MOSI_inst : OBUFT
        port map (
            O => SPI_MOSI, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => emio_spi0_m_o, -- 1-bit input: Buffer input
            T => emio_spi0_mo_tn  -- 1-bit input: 3-state enable input
        );

    SPI0_MISO_inst : IBUF
        port map (
            O => emio_spi0_m_i, -- 1-bit output: Buffer output
            I => SPI_MISO  -- 1-bit input: Buffer input
        );
    
    SPI0_SS_inst : OBUFT
        port map (
            O => SPI_CS, -- 1-bit output: Buffer output (connect directly to top-level port)
            I => emio_spi0_ss_o_n, -- 1-bit input: Buffer input
            T => emio_spi0_ss_n_tn  -- 1-bit input: 3-state enable input
        );            
           
end RTL;
