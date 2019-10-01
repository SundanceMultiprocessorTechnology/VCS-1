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

-- IP VLNV: trenz.biz:user:video_io_to_hdmi:1.0
-- IP Revision: 5

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_video_io_to_hdmi_0_0 IS
  PORT (
    vid_data : IN STD_LOGIC_VECTOR(23 DOWNTO 0);
    vid_active_video : IN STD_LOGIC;
    vid_hsync : IN STD_LOGIC;
    vid_vsync : IN STD_LOGIC;
    vid_io_in_clk : IN STD_LOGIC;
    hdmi_data : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    hdmi_de : OUT STD_LOGIC;
    hdmi_clk : OUT STD_LOGIC;
    hdmi_hsync : OUT STD_LOGIC;
    hdmi_vsync : OUT STD_LOGIC
  );
END design_1_video_io_to_hdmi_0_0;

ARCHITECTURE design_1_video_io_to_hdmi_0_0_arch OF design_1_video_io_to_hdmi_0_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_video_io_to_hdmi_0_0_arch: ARCHITECTURE IS "yes";
  COMPONENT video_io_to_hdmi IS
    PORT (
      vid_data : IN STD_LOGIC_VECTOR(23 DOWNTO 0);
      vid_active_video : IN STD_LOGIC;
      vid_hsync : IN STD_LOGIC;
      vid_vsync : IN STD_LOGIC;
      vid_io_in_clk : IN STD_LOGIC;
      hdmi_data : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
      hdmi_de : OUT STD_LOGIC;
      hdmi_clk : OUT STD_LOGIC;
      hdmi_hsync : OUT STD_LOGIC;
      hdmi_vsync : OUT STD_LOGIC
    );
  END COMPONENT video_io_to_hdmi;
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER : STRING;
  ATTRIBUTE X_INTERFACE_INFO OF hdmi_vsync: SIGNAL IS "xilinx.com:interface:hdmi:1.0 hdmi_out VSYNC";
  ATTRIBUTE X_INTERFACE_INFO OF hdmi_hsync: SIGNAL IS "xilinx.com:interface:hdmi:1.0 hdmi_out HSYNC";
  ATTRIBUTE X_INTERFACE_INFO OF hdmi_clk: SIGNAL IS "xilinx.com:interface:hdmi:1.0 hdmi_out CLK";
  ATTRIBUTE X_INTERFACE_INFO OF hdmi_de: SIGNAL IS "xilinx.com:interface:hdmi:1.0 hdmi_out DE";
  ATTRIBUTE X_INTERFACE_INFO OF hdmi_data: SIGNAL IS "xilinx.com:interface:hdmi:1.0 hdmi_out DATA";
  ATTRIBUTE X_INTERFACE_PARAMETER OF vid_io_in_clk: SIGNAL IS "XIL_INTERFACENAME vid_io_in_signal_clock, ASSOCIATED_BUSIF video_io_in, FREQ_HZ 72727264, PHASE 0.000, CLK_DOMAIN design_1_zynq_ultra_ps_e_0_0_pl_clk1, INSERT_VIP 0";
  ATTRIBUTE X_INTERFACE_INFO OF vid_io_in_clk: SIGNAL IS "xilinx.com:signal:clock:1.0 vid_io_in_signal_clock CLK";
  ATTRIBUTE X_INTERFACE_INFO OF vid_vsync: SIGNAL IS "xilinx.com:interface:vid_io:1.0 vid_io_in VSYNC";
  ATTRIBUTE X_INTERFACE_INFO OF vid_hsync: SIGNAL IS "xilinx.com:interface:vid_io:1.0 vid_io_in HSYNC";
  ATTRIBUTE X_INTERFACE_INFO OF vid_active_video: SIGNAL IS "xilinx.com:interface:vid_io:1.0 vid_io_in ACTIVE_VIDEO";
  ATTRIBUTE X_INTERFACE_INFO OF vid_data: SIGNAL IS "xilinx.com:interface:vid_io:1.0 vid_io_in DATA";
BEGIN
  U0 : video_io_to_hdmi
    PORT MAP (
      vid_data => vid_data,
      vid_active_video => vid_active_video,
      vid_hsync => vid_hsync,
      vid_vsync => vid_vsync,
      vid_io_in_clk => vid_io_in_clk,
      hdmi_data => hdmi_data,
      hdmi_de => hdmi_de,
      hdmi_clk => hdmi_clk,
      hdmi_hsync => hdmi_hsync,
      hdmi_vsync => hdmi_vsync
    );
END design_1_video_io_to_hdmi_0_0_arch;
