// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
// Date        : Mon Jul  1 11:15:01 2019
// Host        : SUN-Lin01 running 64-bit Ubuntu 16.04.6 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/pedro/Development/VCS-1/Hardware/Xilinx/Firmware/2018.3/ZU3EG/FM191-RU/FM191_ZU3EG/FM191_ZU3EG.srcs/sources_1/bd/design_1/ip/design_1_axis_fb_conv_0_0/design_1_axis_fb_conv_0_0_stub.v
// Design      : design_1_axis_fb_conv_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu3eg-sfvc784-1-e
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "axis_fb_conv_v1_0,Vivado 2018.3" *)
module design_1_axis_fb_conv_0_0(s_axis_tdata, s_axis_tlast, s_axis_tuser, 
  s_axis_tvalid, s_axis_tready, s_axis_aclk, s_axis_aresetn, video_out_tdata, 
  video_out_tlast, video_out_tuser, video_out_tvalid, video_out_tready)
/* synthesis syn_black_box black_box_pad_pin="s_axis_tdata[31:0],s_axis_tlast,s_axis_tuser,s_axis_tvalid,s_axis_tready,s_axis_aclk,s_axis_aresetn,video_out_tdata[23:0],video_out_tlast,video_out_tuser,video_out_tvalid,video_out_tready" */;
  input [31:0]s_axis_tdata;
  input s_axis_tlast;
  input s_axis_tuser;
  input s_axis_tvalid;
  output s_axis_tready;
  input s_axis_aclk;
  input s_axis_aresetn;
  output [23:0]video_out_tdata;
  output video_out_tlast;
  output video_out_tuser;
  output video_out_tvalid;
  input video_out_tready;
endmodule
