-- (c) Copyright 1995-2019 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: sundance.com:user:SPI_US_Buffering:1.0
-- IP Revision: 3

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_SPI_US_Buffering_0_0 IS
  PORT (
    emio_spi0_m_i : OUT STD_LOGIC;
    emio_spi0_m_o : IN STD_LOGIC;
    emio_spi0_mo_t : IN STD_LOGIC;
    emio_spi0_s_i : OUT STD_LOGIC;
    emio_spi0_s_o : IN STD_LOGIC;
    emio_spi0_so_t : IN STD_LOGIC;
    emio_spi0_sclk_i : OUT STD_LOGIC;
    emio_spi0_sclk_o : IN STD_LOGIC;
    emio_spi0_sclk_t : IN STD_LOGIC;
    emio_spi0_ss_i_n : OUT STD_LOGIC;
    emio_spi0_ss_o_n : IN STD_LOGIC;
    emio_spi0_ss_n_t : IN STD_LOGIC;
    SPI_CLK : OUT STD_LOGIC;
    SPI_MOSI : OUT STD_LOGIC;
    SPI_MISO : IN STD_LOGIC;
    SPI_CS : OUT STD_LOGIC
  );
END design_1_SPI_US_Buffering_0_0;

ARCHITECTURE design_1_SPI_US_Buffering_0_0_arch OF design_1_SPI_US_Buffering_0_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_SPI_US_Buffering_0_0_arch: ARCHITECTURE IS "yes";
  COMPONENT SPI_US_Buffering IS
    PORT (
      emio_spi0_m_i : OUT STD_LOGIC;
      emio_spi0_m_o : IN STD_LOGIC;
      emio_spi0_mo_t : IN STD_LOGIC;
      emio_spi0_s_i : OUT STD_LOGIC;
      emio_spi0_s_o : IN STD_LOGIC;
      emio_spi0_so_t : IN STD_LOGIC;
      emio_spi0_sclk_i : OUT STD_LOGIC;
      emio_spi0_sclk_o : IN STD_LOGIC;
      emio_spi0_sclk_t : IN STD_LOGIC;
      emio_spi0_ss_i_n : OUT STD_LOGIC;
      emio_spi0_ss_o_n : IN STD_LOGIC;
      emio_spi0_ss_n_t : IN STD_LOGIC;
      SPI_CLK : OUT STD_LOGIC;
      SPI_MOSI : OUT STD_LOGIC;
      SPI_MISO : IN STD_LOGIC;
      SPI_CS : OUT STD_LOGIC
    );
  END COMPONENT SPI_US_Buffering;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF design_1_SPI_US_Buffering_0_0_arch: ARCHITECTURE IS "SPI_US_Buffering,Vivado 2018.3";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF design_1_SPI_US_Buffering_0_0_arch : ARCHITECTURE IS "design_1_SPI_US_Buffering_0_0,SPI_US_Buffering,{}";
  ATTRIBUTE IP_DEFINITION_SOURCE : STRING;
  ATTRIBUTE IP_DEFINITION_SOURCE OF design_1_SPI_US_Buffering_0_0_arch: ARCHITECTURE IS "package_project";
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_INFO OF SPI_CS: SIGNAL IS "sundance.com:user:SPI:1.0 SPI SPI_CS";
  ATTRIBUTE X_INTERFACE_INFO OF SPI_MISO: SIGNAL IS "sundance.com:user:SPI:1.0 SPI SPI_MISO";
  ATTRIBUTE X_INTERFACE_INFO OF SPI_MOSI: SIGNAL IS "sundance.com:user:SPI:1.0 SPI SPI_MOSI";
  ATTRIBUTE X_INTERFACE_INFO OF SPI_CLK: SIGNAL IS "sundance.com:user:SPI:1.0 SPI SPI_CLK";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_ss_n_t: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S SS_T";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_ss_o_n: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S SS_O";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_ss_i_n: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S SS_I";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_sclk_t: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S SCK_T";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_sclk_o: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S SCK_O";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_sclk_i: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S SCK_I";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_so_t: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S IO1_T";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_s_o: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S IO1_O";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_s_i: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S IO0_I";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_mo_t: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S IO0_T";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_m_o: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S IO0_O";
  ATTRIBUTE X_INTERFACE_INFO OF emio_spi0_m_i: SIGNAL IS "xilinx.com:interface:spi:1.0 SPI_S IO1_I";
BEGIN
  U0 : SPI_US_Buffering
    PORT MAP (
      emio_spi0_m_i => emio_spi0_m_i,
      emio_spi0_m_o => emio_spi0_m_o,
      emio_spi0_mo_t => emio_spi0_mo_t,
      emio_spi0_s_i => emio_spi0_s_i,
      emio_spi0_s_o => emio_spi0_s_o,
      emio_spi0_so_t => emio_spi0_so_t,
      emio_spi0_sclk_i => emio_spi0_sclk_i,
      emio_spi0_sclk_o => emio_spi0_sclk_o,
      emio_spi0_sclk_t => emio_spi0_sclk_t,
      emio_spi0_ss_i_n => emio_spi0_ss_i_n,
      emio_spi0_ss_o_n => emio_spi0_ss_o_n,
      emio_spi0_ss_n_t => emio_spi0_ss_n_t,
      SPI_CLK => SPI_CLK,
      SPI_MOSI => SPI_MOSI,
      SPI_MISO => SPI_MISO,
      SPI_CS => SPI_CS
    );
END design_1_SPI_US_Buffering_0_0_arch;
