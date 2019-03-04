----------------------------------------------------------------------------------
-- Company: Trenz Electronic GmbH
-- Engineer: Antti Lukats
-- 
-- Create Date: 
-- Design Name: 
-- Module Name: 
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity video_io_to_hdmi is Port ( 
        vid_data: in STD_LOGIC_VECTOR(23 downto 0);
        vid_active_video : in STD_LOGIC;
        vid_hsync : in STD_LOGIC;
        vid_vsync : in STD_LOGIC;
        
        vid_io_in_clk : in STD_LOGIC;

        hdmi_data: out STD_LOGIC_VECTOR(11 downto 0);
        hdmi_de : out STD_LOGIC;
        hdmi_clk : out STD_LOGIC;
        hdmi_hsync : out STD_LOGIC;
        hdmi_vsync : out STD_LOGIC


	);
end video_io_to_hdmi;

architecture Behavioral of video_io_to_hdmi is

constant Low : std_logic := '0';
constant High : std_logic := '1';

signal vid_data_i : std_logic_vector(23 downto 0);

signal DE_i : std_logic;
signal active_video_d : std_logic;

begin
   -- Swap G and B
    vid_data_i(7 downto 0) <= vid_data(15 downto 8);
    vid_data_i(15 downto 8) <= vid_data(7 downto 0);
    vid_data_i(23 downto 16) <= vid_data(23 downto 16);
    
   
    --
    -- delay DE 1 clock? 
    --
    DE_FF_inst : FDRE
    generic map (
       INIT => '0') -- Initial value of register ('0' or '1')  
    port map (
       Q => active_video_d,      -- Data output
       C => vid_io_in_clk,      -- Clock input
       CE => High,    -- Clock enable input
       R => Low,      -- Synchronous reset input
       D => vid_active_video       -- Data input
    );    
    
    -- make DE start 1 clock later
    DE_i <= active_video_d and vid_active_video;
    
    CLK_ODDR_inst : ODDRE1
    generic map(
        IS_C_INVERTED => '0', 
        IS_D1_INVERTED => '0', 
        IS_D2_INVERTED => '0',
        SRVAL => '0' 
    )
    port map (
        Q => hdmi_clk,   	-- 1-bit DDR output
        C => vid_io_in_clk,    	-- 1-bit clock input
        D1 => High,  	-- 1-bit data input (positive edge)
        D2 => Low,  	-- 1-bit data input (negative edge)
        SR => Low    	-- 1-bit reset input
    );

    gen_hdmi_io: for i in 0 to 11 generate
        IO_ODDR_inst : ODDRE1
        generic map(
            IS_C_INVERTED => '0', 
            IS_D1_INVERTED => '0', 
            IS_D2_INVERTED => '0',
            SRVAL => '0' 
        )
        port map (
            Q => hdmi_data(i),       -- 1-bit DDR output
            C => vid_io_in_clk,        -- 1-bit clock input
            D1 => vid_data_i(i),      -- 1-bit data input (positive edge)
            D2 => vid_data_i(i + 12),      -- 1-bit data input (negative edge)
            SR => Low        -- 1-bit reset input
       );
    end generate gen_hdmi_io;

    VSYNC_ODDR_inst : ODDRE1
    generic map(
        IS_C_INVERTED => '0', 
        IS_D1_INVERTED => '0', 
        IS_D2_INVERTED => '0',
        SRVAL => '0' 
    )
    port map (
        Q => hdmi_vsync,   	-- 1-bit DDR output
        C => vid_io_in_clk,    	-- 1-bit clock input
        D1 => vid_vsync,  	-- 1-bit data input (positive edge)
        D2 => vid_vsync,  	-- 1-bit data input (negative edge)
        SR => Low    	-- 1-bit reset input
    );

    HSYNC_ODDR_inst : ODDRE1
    generic map(
        IS_C_INVERTED => '0', 
        IS_D1_INVERTED => '0', 
        IS_D2_INVERTED => '0',
        SRVAL => '0' 
    )
    port map (
        Q => hdmi_hsync,   	-- 1-bit DDR output
        C => vid_io_in_clk,    	-- 1-bit clock input
        D1 => vid_hsync,  	-- 1-bit data input (positive edge)
        D2 => vid_hsync,  	-- 1-bit data input (negative edge)
        SR => Low    	-- 1-bit reset input
    );

    DE_ODDR_inst : ODDRE1
    generic map(
        IS_C_INVERTED => '0', 
        IS_D1_INVERTED => '0', 
        IS_D2_INVERTED => '0',
        SRVAL => '0' 
    )
    port map (
        Q => hdmi_de,   	-- 1-bit DDR output
        C => vid_io_in_clk,    	-- 1-bit clock input
        D1 => DE_i,  	-- 1-bit data input (positive edge)
        D2 => DE_i,  	-- 1-bit data input (negative edge)
        SR => Low    	-- 1-bit reset input
    );



		
end Behavioral;
