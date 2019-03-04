----------------------------------------------------------------------------------------------------
--! @file axis_fb_conv_v1_0.vhd
--! @brief Simple remapper to convert 16 or 32 bit AXI4-Stream into Xilinx 24 bit Video Stream 
--! @author Antti Lukats
--! @version 1.0
--! @date 2015
--! @copyright Copyright 2015 Trenz Electronic GmbH
--! @license BSD
--! @pre Vivado 2014.4+
--! @pre Xilinx VDMA configured with 16 or 32 bit output
----------------------------------------------------------------------------------------------------

--! Use standard library
library ieee;
--! Use logic elements
    use ieee.std_logic_1164.all;

--! AXI4-Stream Remapper to be used with:
--! Linux Simple Frame Buffer driver,
--! Xilinx VDMA and Xilinx AXI4-stream to Video Out IP Cores.
entity axis_fb_conv_v1_0 is
	generic (
        --! Format: The format of the framebuffer surface. Valid values are:
        --! r5g6b5 (16-bit pixels, d[15:11]=r, d[10:5]=g, d[4:0]=b).
        --! a8b8g8r8 (32-bit pixels, d[31:24]=a, d[23:16]=b, d[15:8]=g, d[7:0]=r).		
		C_FB_MODE	: integer range 0 to 1	:= 1 --! Mode is set as: 0 = r5g6b5, 1 = a8b8g8r8  
	);
	port (
		s_axis_aclk	     : in std_logic; --! not used
		s_axis_aresetn	 : in std_logic; --! not used
		---------------------------------------------------------------------
		s_axis_tready	 : out std_logic; --! direct bypass
		s_axis_tdata	 : in std_logic_vector(C_FB_MODE*16+16-1 downto 0); --! Pixel data from VDMA IP Core
		s_axis_tlast	 : in std_logic; --! end of line: direct bypass
		s_axis_tuser	 : in std_logic; --! SOF: direct bypass
		s_axis_tvalid	 : in std_logic; --! direct bypass
        ---------------------------------------------------------------------
		video_out_tvalid : out std_logic; --! direct from input Stream TVALID
		video_out_tdata	 : out std_logic_vector(23 downto 0); --! Remapped TDATA
		video_out_tlast	 : out std_logic; --! direct from input Stream TLAST
		video_out_tuser	 : out std_logic; --! direct from input Stream TUSER
		video_out_tready : in std_logic --! direct to input Stream TREADY
	);
end axis_fb_conv_v1_0;

--! Simple remapper, only function is remap, there is no other logic used
architecture arch_imp of axis_fb_conv_v1_0 is

signal r	: std_logic_vector(7 downto 0) := (others => '0'); --! Red Component
signal g	: std_logic_vector(7 downto 0) := (others => '0'); --! Green Component
signal b	: std_logic_vector(7 downto 0) := (others => '0'); --! Blue Component
signal a	: std_logic_vector(7 downto 0) := (others => '0'); --! Transparency, not used currently

begin
    video_out_tvalid  <= s_axis_tvalid; -- Direct bypass
    video_out_tlast   <= s_axis_tlast; -- Direct bypass
    video_out_tuser   <= s_axis_tuser; -- Direct bypass
    s_axis_tready     <= video_out_tready; -- Direct bypass

-- r5g6b5 (16-bit pixels, d[15:11]=r, d[10:5]=g, d[4:0]=b).
Video_16_bit_Gen: if C_FB_MODE = 0 generate
    r(7 downto 3) <= s_axis_tdata(15 downto 11); 
    g(7 downto 2) <= s_axis_tdata(10 downto 5);
    b(7 downto 3) <= s_axis_tdata(4 downto 0);
end generate Video_16_bit_Gen;

-- a8b8g8r8 (32-bit pixels, d[31:24]=a, d[23:16]=b, d[15:8]=g, d[7:0]=r).		
Video_32_bit_Gen: if C_FB_MODE = 1 generate
    b(7 downto 0) <= s_axis_tdata(23 downto 16); 
    g(7 downto 0) <= s_axis_tdata(15 downto 8);
    r(7 downto 0) <= s_axis_tdata(7 downto 0);
end generate Video_32_bit_Gen;

-- construct Xilinx Video RGB format
-- R B G, see PG044
video_out_tdata(23 downto 0) <= r & b & g;

end arch_imp;
