--Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
--Date        : Mon Jul  1 10:21:59 2019
--Host        : SUN-Lin01 running 64-bit Ubuntu 16.04.6 LTS
--Command     : generate_target design_1_wrapper.bd
--Design      : design_1_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_wrapper is
  port (
    C_Board_LEDs_tri_o : out STD_LOGIC_VECTOR ( 1 downto 0 );
    DIO_tri_io : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    GPIO_tri_io : inout STD_LOGIC_VECTOR ( 27 downto 0 );
    I2C_scl_io : inout STD_LOGIC;
    I2C_sda_io : inout STD_LOGIC;
    M_Board_LEDs_tri_o : out STD_LOGIC_VECTOR ( 3 downto 0 );
    PHY_LED : out STD_LOGIC_VECTOR ( 1 downto 0 );
    PHY_LED_TE : in STD_LOGIC_VECTOR ( 1 downto 0 );
    SPI_spi_clk : out STD_LOGIC;
    SPI_spi_cs : out STD_LOGIC;
    SPI_spi_miso : in STD_LOGIC;
    SPI_spi_mosi : out STD_LOGIC;
    UART_1_rxd : in STD_LOGIC;
    UART_1_txd : out STD_LOGIC;
    UART_2_rxd : in STD_LOGIC;
    UART_2_txd : out STD_LOGIC;
    UART_3_rxd : in STD_LOGIC;
    UART_3_txd : out STD_LOGIC;
    UART_RQ_tri_i : in STD_LOGIC_VECTOR ( 2 downto 0 );
    cec_clk : out STD_LOGIC_VECTOR ( 0 to 0 );
    ct_hpd : out STD_LOGIC_VECTOR ( 0 to 0 );
    hdmi_out_clk : out STD_LOGIC;
    hdmi_out_data : out STD_LOGIC_VECTOR ( 11 downto 0 );
    hdmi_out_de : out STD_LOGIC;
    hdmi_out_hsync : out STD_LOGIC;
    hdmi_out_vsync : out STD_LOGIC;
    ls_oe : out STD_LOGIC_VECTOR ( 0 to 0 )
  );
end design_1_wrapper;

architecture STRUCTURE of design_1_wrapper is
  component design_1 is
  port (
    PHY_LED_TE : in STD_LOGIC_VECTOR ( 1 downto 0 );
    PHY_LED : out STD_LOGIC_VECTOR ( 1 downto 0 );
    SPI_spi_clk : out STD_LOGIC;
    SPI_spi_mosi : out STD_LOGIC;
    SPI_spi_miso : in STD_LOGIC;
    SPI_spi_cs : out STD_LOGIC;
    DIO_tri_i : in STD_LOGIC_VECTOR ( 14 downto 0 );
    DIO_tri_o : out STD_LOGIC_VECTOR ( 14 downto 0 );
    DIO_tri_t : out STD_LOGIC_VECTOR ( 14 downto 0 );
    GPIO_tri_i : in STD_LOGIC_VECTOR ( 27 downto 0 );
    GPIO_tri_o : out STD_LOGIC_VECTOR ( 27 downto 0 );
    GPIO_tri_t : out STD_LOGIC_VECTOR ( 27 downto 0 );
    M_Board_LEDs_tri_o : out STD_LOGIC_VECTOR ( 3 downto 0 );
    C_Board_LEDs_tri_o : out STD_LOGIC_VECTOR ( 1 downto 0 );
    UART_RQ_tri_i : in STD_LOGIC_VECTOR ( 2 downto 0 );
    UART_1_rxd : in STD_LOGIC;
    UART_1_txd : out STD_LOGIC;
    UART_2_rxd : in STD_LOGIC;
    UART_2_txd : out STD_LOGIC;
    UART_3_rxd : in STD_LOGIC;
    UART_3_txd : out STD_LOGIC;
    I2C_scl_i : in STD_LOGIC;
    I2C_scl_o : out STD_LOGIC;
    I2C_scl_t : out STD_LOGIC;
    I2C_sda_i : in STD_LOGIC;
    I2C_sda_o : out STD_LOGIC;
    I2C_sda_t : out STD_LOGIC;
    ct_hpd : out STD_LOGIC_VECTOR ( 0 to 0 );
    cec_clk : out STD_LOGIC_VECTOR ( 0 to 0 );
    ls_oe : out STD_LOGIC_VECTOR ( 0 to 0 );
    hdmi_out_de : out STD_LOGIC;
    hdmi_out_clk : out STD_LOGIC;
    hdmi_out_vsync : out STD_LOGIC;
    hdmi_out_data : out STD_LOGIC_VECTOR ( 11 downto 0 );
    hdmi_out_hsync : out STD_LOGIC
  );
  end component design_1;
  component IOBUF is
  port (
    I : in STD_LOGIC;
    O : out STD_LOGIC;
    T : in STD_LOGIC;
    IO : inout STD_LOGIC
  );
  end component IOBUF;
  signal DIO_tri_i_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal DIO_tri_i_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal DIO_tri_i_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal DIO_tri_i_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal DIO_tri_i_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal DIO_tri_i_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal DIO_tri_i_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal DIO_tri_i_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal DIO_tri_i_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal DIO_tri_i_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal DIO_tri_i_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal DIO_tri_i_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal DIO_tri_i_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal DIO_tri_i_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal DIO_tri_i_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal DIO_tri_io_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal DIO_tri_io_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal DIO_tri_io_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal DIO_tri_io_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal DIO_tri_io_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal DIO_tri_io_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal DIO_tri_io_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal DIO_tri_io_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal DIO_tri_io_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal DIO_tri_io_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal DIO_tri_io_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal DIO_tri_io_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal DIO_tri_io_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal DIO_tri_io_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal DIO_tri_io_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal DIO_tri_o_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal DIO_tri_o_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal DIO_tri_o_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal DIO_tri_o_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal DIO_tri_o_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal DIO_tri_o_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal DIO_tri_o_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal DIO_tri_o_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal DIO_tri_o_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal DIO_tri_o_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal DIO_tri_o_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal DIO_tri_o_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal DIO_tri_o_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal DIO_tri_o_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal DIO_tri_o_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal DIO_tri_t_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal DIO_tri_t_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal DIO_tri_t_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal DIO_tri_t_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal DIO_tri_t_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal DIO_tri_t_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal DIO_tri_t_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal DIO_tri_t_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal DIO_tri_t_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal DIO_tri_t_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal DIO_tri_t_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal DIO_tri_t_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal DIO_tri_t_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal DIO_tri_t_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal DIO_tri_t_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal GPIO_tri_i_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal GPIO_tri_i_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal GPIO_tri_i_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal GPIO_tri_i_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal GPIO_tri_i_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal GPIO_tri_i_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal GPIO_tri_i_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal GPIO_tri_i_15 : STD_LOGIC_VECTOR ( 15 to 15 );
  signal GPIO_tri_i_16 : STD_LOGIC_VECTOR ( 16 to 16 );
  signal GPIO_tri_i_17 : STD_LOGIC_VECTOR ( 17 to 17 );
  signal GPIO_tri_i_18 : STD_LOGIC_VECTOR ( 18 to 18 );
  signal GPIO_tri_i_19 : STD_LOGIC_VECTOR ( 19 to 19 );
  signal GPIO_tri_i_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal GPIO_tri_i_20 : STD_LOGIC_VECTOR ( 20 to 20 );
  signal GPIO_tri_i_21 : STD_LOGIC_VECTOR ( 21 to 21 );
  signal GPIO_tri_i_22 : STD_LOGIC_VECTOR ( 22 to 22 );
  signal GPIO_tri_i_23 : STD_LOGIC_VECTOR ( 23 to 23 );
  signal GPIO_tri_i_24 : STD_LOGIC_VECTOR ( 24 to 24 );
  signal GPIO_tri_i_25 : STD_LOGIC_VECTOR ( 25 to 25 );
  signal GPIO_tri_i_26 : STD_LOGIC_VECTOR ( 26 to 26 );
  signal GPIO_tri_i_27 : STD_LOGIC_VECTOR ( 27 to 27 );
  signal GPIO_tri_i_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal GPIO_tri_i_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal GPIO_tri_i_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal GPIO_tri_i_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal GPIO_tri_i_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal GPIO_tri_i_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal GPIO_tri_i_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal GPIO_tri_io_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal GPIO_tri_io_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal GPIO_tri_io_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal GPIO_tri_io_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal GPIO_tri_io_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal GPIO_tri_io_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal GPIO_tri_io_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal GPIO_tri_io_15 : STD_LOGIC_VECTOR ( 15 to 15 );
  signal GPIO_tri_io_16 : STD_LOGIC_VECTOR ( 16 to 16 );
  signal GPIO_tri_io_17 : STD_LOGIC_VECTOR ( 17 to 17 );
  signal GPIO_tri_io_18 : STD_LOGIC_VECTOR ( 18 to 18 );
  signal GPIO_tri_io_19 : STD_LOGIC_VECTOR ( 19 to 19 );
  signal GPIO_tri_io_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal GPIO_tri_io_20 : STD_LOGIC_VECTOR ( 20 to 20 );
  signal GPIO_tri_io_21 : STD_LOGIC_VECTOR ( 21 to 21 );
  signal GPIO_tri_io_22 : STD_LOGIC_VECTOR ( 22 to 22 );
  signal GPIO_tri_io_23 : STD_LOGIC_VECTOR ( 23 to 23 );
  signal GPIO_tri_io_24 : STD_LOGIC_VECTOR ( 24 to 24 );
  signal GPIO_tri_io_25 : STD_LOGIC_VECTOR ( 25 to 25 );
  signal GPIO_tri_io_26 : STD_LOGIC_VECTOR ( 26 to 26 );
  signal GPIO_tri_io_27 : STD_LOGIC_VECTOR ( 27 to 27 );
  signal GPIO_tri_io_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal GPIO_tri_io_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal GPIO_tri_io_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal GPIO_tri_io_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal GPIO_tri_io_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal GPIO_tri_io_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal GPIO_tri_io_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal GPIO_tri_o_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal GPIO_tri_o_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal GPIO_tri_o_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal GPIO_tri_o_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal GPIO_tri_o_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal GPIO_tri_o_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal GPIO_tri_o_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal GPIO_tri_o_15 : STD_LOGIC_VECTOR ( 15 to 15 );
  signal GPIO_tri_o_16 : STD_LOGIC_VECTOR ( 16 to 16 );
  signal GPIO_tri_o_17 : STD_LOGIC_VECTOR ( 17 to 17 );
  signal GPIO_tri_o_18 : STD_LOGIC_VECTOR ( 18 to 18 );
  signal GPIO_tri_o_19 : STD_LOGIC_VECTOR ( 19 to 19 );
  signal GPIO_tri_o_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal GPIO_tri_o_20 : STD_LOGIC_VECTOR ( 20 to 20 );
  signal GPIO_tri_o_21 : STD_LOGIC_VECTOR ( 21 to 21 );
  signal GPIO_tri_o_22 : STD_LOGIC_VECTOR ( 22 to 22 );
  signal GPIO_tri_o_23 : STD_LOGIC_VECTOR ( 23 to 23 );
  signal GPIO_tri_o_24 : STD_LOGIC_VECTOR ( 24 to 24 );
  signal GPIO_tri_o_25 : STD_LOGIC_VECTOR ( 25 to 25 );
  signal GPIO_tri_o_26 : STD_LOGIC_VECTOR ( 26 to 26 );
  signal GPIO_tri_o_27 : STD_LOGIC_VECTOR ( 27 to 27 );
  signal GPIO_tri_o_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal GPIO_tri_o_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal GPIO_tri_o_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal GPIO_tri_o_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal GPIO_tri_o_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal GPIO_tri_o_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal GPIO_tri_o_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal GPIO_tri_t_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal GPIO_tri_t_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal GPIO_tri_t_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal GPIO_tri_t_11 : STD_LOGIC_VECTOR ( 11 to 11 );
  signal GPIO_tri_t_12 : STD_LOGIC_VECTOR ( 12 to 12 );
  signal GPIO_tri_t_13 : STD_LOGIC_VECTOR ( 13 to 13 );
  signal GPIO_tri_t_14 : STD_LOGIC_VECTOR ( 14 to 14 );
  signal GPIO_tri_t_15 : STD_LOGIC_VECTOR ( 15 to 15 );
  signal GPIO_tri_t_16 : STD_LOGIC_VECTOR ( 16 to 16 );
  signal GPIO_tri_t_17 : STD_LOGIC_VECTOR ( 17 to 17 );
  signal GPIO_tri_t_18 : STD_LOGIC_VECTOR ( 18 to 18 );
  signal GPIO_tri_t_19 : STD_LOGIC_VECTOR ( 19 to 19 );
  signal GPIO_tri_t_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal GPIO_tri_t_20 : STD_LOGIC_VECTOR ( 20 to 20 );
  signal GPIO_tri_t_21 : STD_LOGIC_VECTOR ( 21 to 21 );
  signal GPIO_tri_t_22 : STD_LOGIC_VECTOR ( 22 to 22 );
  signal GPIO_tri_t_23 : STD_LOGIC_VECTOR ( 23 to 23 );
  signal GPIO_tri_t_24 : STD_LOGIC_VECTOR ( 24 to 24 );
  signal GPIO_tri_t_25 : STD_LOGIC_VECTOR ( 25 to 25 );
  signal GPIO_tri_t_26 : STD_LOGIC_VECTOR ( 26 to 26 );
  signal GPIO_tri_t_27 : STD_LOGIC_VECTOR ( 27 to 27 );
  signal GPIO_tri_t_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal GPIO_tri_t_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal GPIO_tri_t_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal GPIO_tri_t_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal GPIO_tri_t_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal GPIO_tri_t_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal GPIO_tri_t_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal I2C_scl_i : STD_LOGIC;
  signal I2C_scl_o : STD_LOGIC;
  signal I2C_scl_t : STD_LOGIC;
  signal I2C_sda_i : STD_LOGIC;
  signal I2C_sda_o : STD_LOGIC;
  signal I2C_sda_t : STD_LOGIC;
begin
DIO_tri_iobuf_0: component IOBUF
     port map (
      I => DIO_tri_o_0(0),
      IO => DIO_tri_io(0),
      O => DIO_tri_i_0(0),
      T => DIO_tri_t_0(0)
    );
DIO_tri_iobuf_1: component IOBUF
     port map (
      I => DIO_tri_o_1(1),
      IO => DIO_tri_io(1),
      O => DIO_tri_i_1(1),
      T => DIO_tri_t_1(1)
    );
DIO_tri_iobuf_10: component IOBUF
     port map (
      I => DIO_tri_o_10(10),
      IO => DIO_tri_io(10),
      O => DIO_tri_i_10(10),
      T => DIO_tri_t_10(10)
    );
DIO_tri_iobuf_11: component IOBUF
     port map (
      I => DIO_tri_o_11(11),
      IO => DIO_tri_io(11),
      O => DIO_tri_i_11(11),
      T => DIO_tri_t_11(11)
    );
DIO_tri_iobuf_12: component IOBUF
     port map (
      I => DIO_tri_o_12(12),
      IO => DIO_tri_io(12),
      O => DIO_tri_i_12(12),
      T => DIO_tri_t_12(12)
    );
DIO_tri_iobuf_13: component IOBUF
     port map (
      I => DIO_tri_o_13(13),
      IO => DIO_tri_io(13),
      O => DIO_tri_i_13(13),
      T => DIO_tri_t_13(13)
    );
DIO_tri_iobuf_14: component IOBUF
     port map (
      I => DIO_tri_o_14(14),
      IO => DIO_tri_io(14),
      O => DIO_tri_i_14(14),
      T => DIO_tri_t_14(14)
    );
DIO_tri_iobuf_2: component IOBUF
     port map (
      I => DIO_tri_o_2(2),
      IO => DIO_tri_io(2),
      O => DIO_tri_i_2(2),
      T => DIO_tri_t_2(2)
    );
DIO_tri_iobuf_3: component IOBUF
     port map (
      I => DIO_tri_o_3(3),
      IO => DIO_tri_io(3),
      O => DIO_tri_i_3(3),
      T => DIO_tri_t_3(3)
    );
DIO_tri_iobuf_4: component IOBUF
     port map (
      I => DIO_tri_o_4(4),
      IO => DIO_tri_io(4),
      O => DIO_tri_i_4(4),
      T => DIO_tri_t_4(4)
    );
DIO_tri_iobuf_5: component IOBUF
     port map (
      I => DIO_tri_o_5(5),
      IO => DIO_tri_io(5),
      O => DIO_tri_i_5(5),
      T => DIO_tri_t_5(5)
    );
DIO_tri_iobuf_6: component IOBUF
     port map (
      I => DIO_tri_o_6(6),
      IO => DIO_tri_io(6),
      O => DIO_tri_i_6(6),
      T => DIO_tri_t_6(6)
    );
DIO_tri_iobuf_7: component IOBUF
     port map (
      I => DIO_tri_o_7(7),
      IO => DIO_tri_io(7),
      O => DIO_tri_i_7(7),
      T => DIO_tri_t_7(7)
    );
DIO_tri_iobuf_8: component IOBUF
     port map (
      I => DIO_tri_o_8(8),
      IO => DIO_tri_io(8),
      O => DIO_tri_i_8(8),
      T => DIO_tri_t_8(8)
    );
DIO_tri_iobuf_9: component IOBUF
     port map (
      I => DIO_tri_o_9(9),
      IO => DIO_tri_io(9),
      O => DIO_tri_i_9(9),
      T => DIO_tri_t_9(9)
    );
GPIO_tri_iobuf_0: component IOBUF
     port map (
      I => GPIO_tri_o_0(0),
      IO => GPIO_tri_io(0),
      O => GPIO_tri_i_0(0),
      T => GPIO_tri_t_0(0)
    );
GPIO_tri_iobuf_1: component IOBUF
     port map (
      I => GPIO_tri_o_1(1),
      IO => GPIO_tri_io(1),
      O => GPIO_tri_i_1(1),
      T => GPIO_tri_t_1(1)
    );
GPIO_tri_iobuf_10: component IOBUF
     port map (
      I => GPIO_tri_o_10(10),
      IO => GPIO_tri_io(10),
      O => GPIO_tri_i_10(10),
      T => GPIO_tri_t_10(10)
    );
GPIO_tri_iobuf_11: component IOBUF
     port map (
      I => GPIO_tri_o_11(11),
      IO => GPIO_tri_io(11),
      O => GPIO_tri_i_11(11),
      T => GPIO_tri_t_11(11)
    );
GPIO_tri_iobuf_12: component IOBUF
     port map (
      I => GPIO_tri_o_12(12),
      IO => GPIO_tri_io(12),
      O => GPIO_tri_i_12(12),
      T => GPIO_tri_t_12(12)
    );
GPIO_tri_iobuf_13: component IOBUF
     port map (
      I => GPIO_tri_o_13(13),
      IO => GPIO_tri_io(13),
      O => GPIO_tri_i_13(13),
      T => GPIO_tri_t_13(13)
    );
GPIO_tri_iobuf_14: component IOBUF
     port map (
      I => GPIO_tri_o_14(14),
      IO => GPIO_tri_io(14),
      O => GPIO_tri_i_14(14),
      T => GPIO_tri_t_14(14)
    );
GPIO_tri_iobuf_15: component IOBUF
     port map (
      I => GPIO_tri_o_15(15),
      IO => GPIO_tri_io(15),
      O => GPIO_tri_i_15(15),
      T => GPIO_tri_t_15(15)
    );
GPIO_tri_iobuf_16: component IOBUF
     port map (
      I => GPIO_tri_o_16(16),
      IO => GPIO_tri_io(16),
      O => GPIO_tri_i_16(16),
      T => GPIO_tri_t_16(16)
    );
GPIO_tri_iobuf_17: component IOBUF
     port map (
      I => GPIO_tri_o_17(17),
      IO => GPIO_tri_io(17),
      O => GPIO_tri_i_17(17),
      T => GPIO_tri_t_17(17)
    );
GPIO_tri_iobuf_18: component IOBUF
     port map (
      I => GPIO_tri_o_18(18),
      IO => GPIO_tri_io(18),
      O => GPIO_tri_i_18(18),
      T => GPIO_tri_t_18(18)
    );
GPIO_tri_iobuf_19: component IOBUF
     port map (
      I => GPIO_tri_o_19(19),
      IO => GPIO_tri_io(19),
      O => GPIO_tri_i_19(19),
      T => GPIO_tri_t_19(19)
    );
GPIO_tri_iobuf_2: component IOBUF
     port map (
      I => GPIO_tri_o_2(2),
      IO => GPIO_tri_io(2),
      O => GPIO_tri_i_2(2),
      T => GPIO_tri_t_2(2)
    );
GPIO_tri_iobuf_20: component IOBUF
     port map (
      I => GPIO_tri_o_20(20),
      IO => GPIO_tri_io(20),
      O => GPIO_tri_i_20(20),
      T => GPIO_tri_t_20(20)
    );
GPIO_tri_iobuf_21: component IOBUF
     port map (
      I => GPIO_tri_o_21(21),
      IO => GPIO_tri_io(21),
      O => GPIO_tri_i_21(21),
      T => GPIO_tri_t_21(21)
    );
GPIO_tri_iobuf_22: component IOBUF
     port map (
      I => GPIO_tri_o_22(22),
      IO => GPIO_tri_io(22),
      O => GPIO_tri_i_22(22),
      T => GPIO_tri_t_22(22)
    );
GPIO_tri_iobuf_23: component IOBUF
     port map (
      I => GPIO_tri_o_23(23),
      IO => GPIO_tri_io(23),
      O => GPIO_tri_i_23(23),
      T => GPIO_tri_t_23(23)
    );
GPIO_tri_iobuf_24: component IOBUF
     port map (
      I => GPIO_tri_o_24(24),
      IO => GPIO_tri_io(24),
      O => GPIO_tri_i_24(24),
      T => GPIO_tri_t_24(24)
    );
GPIO_tri_iobuf_25: component IOBUF
     port map (
      I => GPIO_tri_o_25(25),
      IO => GPIO_tri_io(25),
      O => GPIO_tri_i_25(25),
      T => GPIO_tri_t_25(25)
    );
GPIO_tri_iobuf_26: component IOBUF
     port map (
      I => GPIO_tri_o_26(26),
      IO => GPIO_tri_io(26),
      O => GPIO_tri_i_26(26),
      T => GPIO_tri_t_26(26)
    );
GPIO_tri_iobuf_27: component IOBUF
     port map (
      I => GPIO_tri_o_27(27),
      IO => GPIO_tri_io(27),
      O => GPIO_tri_i_27(27),
      T => GPIO_tri_t_27(27)
    );
GPIO_tri_iobuf_3: component IOBUF
     port map (
      I => GPIO_tri_o_3(3),
      IO => GPIO_tri_io(3),
      O => GPIO_tri_i_3(3),
      T => GPIO_tri_t_3(3)
    );
GPIO_tri_iobuf_4: component IOBUF
     port map (
      I => GPIO_tri_o_4(4),
      IO => GPIO_tri_io(4),
      O => GPIO_tri_i_4(4),
      T => GPIO_tri_t_4(4)
    );
GPIO_tri_iobuf_5: component IOBUF
     port map (
      I => GPIO_tri_o_5(5),
      IO => GPIO_tri_io(5),
      O => GPIO_tri_i_5(5),
      T => GPIO_tri_t_5(5)
    );
GPIO_tri_iobuf_6: component IOBUF
     port map (
      I => GPIO_tri_o_6(6),
      IO => GPIO_tri_io(6),
      O => GPIO_tri_i_6(6),
      T => GPIO_tri_t_6(6)
    );
GPIO_tri_iobuf_7: component IOBUF
     port map (
      I => GPIO_tri_o_7(7),
      IO => GPIO_tri_io(7),
      O => GPIO_tri_i_7(7),
      T => GPIO_tri_t_7(7)
    );
GPIO_tri_iobuf_8: component IOBUF
     port map (
      I => GPIO_tri_o_8(8),
      IO => GPIO_tri_io(8),
      O => GPIO_tri_i_8(8),
      T => GPIO_tri_t_8(8)
    );
GPIO_tri_iobuf_9: component IOBUF
     port map (
      I => GPIO_tri_o_9(9),
      IO => GPIO_tri_io(9),
      O => GPIO_tri_i_9(9),
      T => GPIO_tri_t_9(9)
    );
I2C_scl_iobuf: component IOBUF
     port map (
      I => I2C_scl_o,
      IO => I2C_scl_io,
      O => I2C_scl_i,
      T => I2C_scl_t
    );
I2C_sda_iobuf: component IOBUF
     port map (
      I => I2C_sda_o,
      IO => I2C_sda_io,
      O => I2C_sda_i,
      T => I2C_sda_t
    );
design_1_i: component design_1
     port map (
      C_Board_LEDs_tri_o(1 downto 0) => C_Board_LEDs_tri_o(1 downto 0),
      DIO_tri_i(14) => DIO_tri_i_14(14),
      DIO_tri_i(13) => DIO_tri_i_13(13),
      DIO_tri_i(12) => DIO_tri_i_12(12),
      DIO_tri_i(11) => DIO_tri_i_11(11),
      DIO_tri_i(10) => DIO_tri_i_10(10),
      DIO_tri_i(9) => DIO_tri_i_9(9),
      DIO_tri_i(8) => DIO_tri_i_8(8),
      DIO_tri_i(7) => DIO_tri_i_7(7),
      DIO_tri_i(6) => DIO_tri_i_6(6),
      DIO_tri_i(5) => DIO_tri_i_5(5),
      DIO_tri_i(4) => DIO_tri_i_4(4),
      DIO_tri_i(3) => DIO_tri_i_3(3),
      DIO_tri_i(2) => DIO_tri_i_2(2),
      DIO_tri_i(1) => DIO_tri_i_1(1),
      DIO_tri_i(0) => DIO_tri_i_0(0),
      DIO_tri_o(14) => DIO_tri_o_14(14),
      DIO_tri_o(13) => DIO_tri_o_13(13),
      DIO_tri_o(12) => DIO_tri_o_12(12),
      DIO_tri_o(11) => DIO_tri_o_11(11),
      DIO_tri_o(10) => DIO_tri_o_10(10),
      DIO_tri_o(9) => DIO_tri_o_9(9),
      DIO_tri_o(8) => DIO_tri_o_8(8),
      DIO_tri_o(7) => DIO_tri_o_7(7),
      DIO_tri_o(6) => DIO_tri_o_6(6),
      DIO_tri_o(5) => DIO_tri_o_5(5),
      DIO_tri_o(4) => DIO_tri_o_4(4),
      DIO_tri_o(3) => DIO_tri_o_3(3),
      DIO_tri_o(2) => DIO_tri_o_2(2),
      DIO_tri_o(1) => DIO_tri_o_1(1),
      DIO_tri_o(0) => DIO_tri_o_0(0),
      DIO_tri_t(14) => DIO_tri_t_14(14),
      DIO_tri_t(13) => DIO_tri_t_13(13),
      DIO_tri_t(12) => DIO_tri_t_12(12),
      DIO_tri_t(11) => DIO_tri_t_11(11),
      DIO_tri_t(10) => DIO_tri_t_10(10),
      DIO_tri_t(9) => DIO_tri_t_9(9),
      DIO_tri_t(8) => DIO_tri_t_8(8),
      DIO_tri_t(7) => DIO_tri_t_7(7),
      DIO_tri_t(6) => DIO_tri_t_6(6),
      DIO_tri_t(5) => DIO_tri_t_5(5),
      DIO_tri_t(4) => DIO_tri_t_4(4),
      DIO_tri_t(3) => DIO_tri_t_3(3),
      DIO_tri_t(2) => DIO_tri_t_2(2),
      DIO_tri_t(1) => DIO_tri_t_1(1),
      DIO_tri_t(0) => DIO_tri_t_0(0),
      GPIO_tri_i(27) => GPIO_tri_i_27(27),
      GPIO_tri_i(26) => GPIO_tri_i_26(26),
      GPIO_tri_i(25) => GPIO_tri_i_25(25),
      GPIO_tri_i(24) => GPIO_tri_i_24(24),
      GPIO_tri_i(23) => GPIO_tri_i_23(23),
      GPIO_tri_i(22) => GPIO_tri_i_22(22),
      GPIO_tri_i(21) => GPIO_tri_i_21(21),
      GPIO_tri_i(20) => GPIO_tri_i_20(20),
      GPIO_tri_i(19) => GPIO_tri_i_19(19),
      GPIO_tri_i(18) => GPIO_tri_i_18(18),
      GPIO_tri_i(17) => GPIO_tri_i_17(17),
      GPIO_tri_i(16) => GPIO_tri_i_16(16),
      GPIO_tri_i(15) => GPIO_tri_i_15(15),
      GPIO_tri_i(14) => GPIO_tri_i_14(14),
      GPIO_tri_i(13) => GPIO_tri_i_13(13),
      GPIO_tri_i(12) => GPIO_tri_i_12(12),
      GPIO_tri_i(11) => GPIO_tri_i_11(11),
      GPIO_tri_i(10) => GPIO_tri_i_10(10),
      GPIO_tri_i(9) => GPIO_tri_i_9(9),
      GPIO_tri_i(8) => GPIO_tri_i_8(8),
      GPIO_tri_i(7) => GPIO_tri_i_7(7),
      GPIO_tri_i(6) => GPIO_tri_i_6(6),
      GPIO_tri_i(5) => GPIO_tri_i_5(5),
      GPIO_tri_i(4) => GPIO_tri_i_4(4),
      GPIO_tri_i(3) => GPIO_tri_i_3(3),
      GPIO_tri_i(2) => GPIO_tri_i_2(2),
      GPIO_tri_i(1) => GPIO_tri_i_1(1),
      GPIO_tri_i(0) => GPIO_tri_i_0(0),
      GPIO_tri_o(27) => GPIO_tri_o_27(27),
      GPIO_tri_o(26) => GPIO_tri_o_26(26),
      GPIO_tri_o(25) => GPIO_tri_o_25(25),
      GPIO_tri_o(24) => GPIO_tri_o_24(24),
      GPIO_tri_o(23) => GPIO_tri_o_23(23),
      GPIO_tri_o(22) => GPIO_tri_o_22(22),
      GPIO_tri_o(21) => GPIO_tri_o_21(21),
      GPIO_tri_o(20) => GPIO_tri_o_20(20),
      GPIO_tri_o(19) => GPIO_tri_o_19(19),
      GPIO_tri_o(18) => GPIO_tri_o_18(18),
      GPIO_tri_o(17) => GPIO_tri_o_17(17),
      GPIO_tri_o(16) => GPIO_tri_o_16(16),
      GPIO_tri_o(15) => GPIO_tri_o_15(15),
      GPIO_tri_o(14) => GPIO_tri_o_14(14),
      GPIO_tri_o(13) => GPIO_tri_o_13(13),
      GPIO_tri_o(12) => GPIO_tri_o_12(12),
      GPIO_tri_o(11) => GPIO_tri_o_11(11),
      GPIO_tri_o(10) => GPIO_tri_o_10(10),
      GPIO_tri_o(9) => GPIO_tri_o_9(9),
      GPIO_tri_o(8) => GPIO_tri_o_8(8),
      GPIO_tri_o(7) => GPIO_tri_o_7(7),
      GPIO_tri_o(6) => GPIO_tri_o_6(6),
      GPIO_tri_o(5) => GPIO_tri_o_5(5),
      GPIO_tri_o(4) => GPIO_tri_o_4(4),
      GPIO_tri_o(3) => GPIO_tri_o_3(3),
      GPIO_tri_o(2) => GPIO_tri_o_2(2),
      GPIO_tri_o(1) => GPIO_tri_o_1(1),
      GPIO_tri_o(0) => GPIO_tri_o_0(0),
      GPIO_tri_t(27) => GPIO_tri_t_27(27),
      GPIO_tri_t(26) => GPIO_tri_t_26(26),
      GPIO_tri_t(25) => GPIO_tri_t_25(25),
      GPIO_tri_t(24) => GPIO_tri_t_24(24),
      GPIO_tri_t(23) => GPIO_tri_t_23(23),
      GPIO_tri_t(22) => GPIO_tri_t_22(22),
      GPIO_tri_t(21) => GPIO_tri_t_21(21),
      GPIO_tri_t(20) => GPIO_tri_t_20(20),
      GPIO_tri_t(19) => GPIO_tri_t_19(19),
      GPIO_tri_t(18) => GPIO_tri_t_18(18),
      GPIO_tri_t(17) => GPIO_tri_t_17(17),
      GPIO_tri_t(16) => GPIO_tri_t_16(16),
      GPIO_tri_t(15) => GPIO_tri_t_15(15),
      GPIO_tri_t(14) => GPIO_tri_t_14(14),
      GPIO_tri_t(13) => GPIO_tri_t_13(13),
      GPIO_tri_t(12) => GPIO_tri_t_12(12),
      GPIO_tri_t(11) => GPIO_tri_t_11(11),
      GPIO_tri_t(10) => GPIO_tri_t_10(10),
      GPIO_tri_t(9) => GPIO_tri_t_9(9),
      GPIO_tri_t(8) => GPIO_tri_t_8(8),
      GPIO_tri_t(7) => GPIO_tri_t_7(7),
      GPIO_tri_t(6) => GPIO_tri_t_6(6),
      GPIO_tri_t(5) => GPIO_tri_t_5(5),
      GPIO_tri_t(4) => GPIO_tri_t_4(4),
      GPIO_tri_t(3) => GPIO_tri_t_3(3),
      GPIO_tri_t(2) => GPIO_tri_t_2(2),
      GPIO_tri_t(1) => GPIO_tri_t_1(1),
      GPIO_tri_t(0) => GPIO_tri_t_0(0),
      I2C_scl_i => I2C_scl_i,
      I2C_scl_o => I2C_scl_o,
      I2C_scl_t => I2C_scl_t,
      I2C_sda_i => I2C_sda_i,
      I2C_sda_o => I2C_sda_o,
      I2C_sda_t => I2C_sda_t,
      M_Board_LEDs_tri_o(3 downto 0) => M_Board_LEDs_tri_o(3 downto 0),
      PHY_LED(1 downto 0) => PHY_LED(1 downto 0),
      PHY_LED_TE(1 downto 0) => PHY_LED_TE(1 downto 0),
      SPI_spi_clk => SPI_spi_clk,
      SPI_spi_cs => SPI_spi_cs,
      SPI_spi_miso => SPI_spi_miso,
      SPI_spi_mosi => SPI_spi_mosi,
      UART_1_rxd => UART_1_rxd,
      UART_1_txd => UART_1_txd,
      UART_2_rxd => UART_2_rxd,
      UART_2_txd => UART_2_txd,
      UART_3_rxd => UART_3_rxd,
      UART_3_txd => UART_3_txd,
      UART_RQ_tri_i(2 downto 0) => UART_RQ_tri_i(2 downto 0),
      cec_clk(0) => cec_clk(0),
      ct_hpd(0) => ct_hpd(0),
      hdmi_out_clk => hdmi_out_clk,
      hdmi_out_data(11 downto 0) => hdmi_out_data(11 downto 0),
      hdmi_out_de => hdmi_out_de,
      hdmi_out_hsync => hdmi_out_hsync,
      hdmi_out_vsync => hdmi_out_vsync,
      ls_oe(0) => ls_oe(0)
    );
end STRUCTURE;
