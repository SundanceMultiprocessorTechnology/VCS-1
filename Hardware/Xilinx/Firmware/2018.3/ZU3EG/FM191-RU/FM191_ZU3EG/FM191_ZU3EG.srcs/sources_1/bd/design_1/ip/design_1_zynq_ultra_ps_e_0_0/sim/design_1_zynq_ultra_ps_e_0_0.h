#ifndef IP_DESIGN_1_ZYNQ_ULTRA_PS_E_0_0_H_
#define IP_DESIGN_1_ZYNQ_ULTRA_PS_E_0_0_H_

// (c) Copyright 1995-2019 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.

#ifndef XTLM
#include "xtlm.h"
#endif

#ifndef SYSTEMC_H
#include "systemc.h"
#endif

class zynq_ultra_ps_e_tlm;

class design_1_zynq_ultra_ps_e_0_0 : public sc_module
{
public:

  design_1_zynq_ultra_ps_e_0_0(const sc_module_name& nm);
  virtual ~design_1_zynq_ultra_ps_e_0_0();

public: // module pin-to-pin RTL interface

  sc_in< bool > maxihpm0_fpd_aclk;
  sc_out< sc_bv<16> > maxigp0_awid;
  sc_out< sc_bv<40> > maxigp0_awaddr;
  sc_out< sc_bv<8> > maxigp0_awlen;
  sc_out< sc_bv<3> > maxigp0_awsize;
  sc_out< sc_bv<2> > maxigp0_awburst;
  sc_out< bool > maxigp0_awlock;
  sc_out< sc_bv<4> > maxigp0_awcache;
  sc_out< sc_bv<3> > maxigp0_awprot;
  sc_out< bool > maxigp0_awvalid;
  sc_out< sc_bv<16> > maxigp0_awuser;
  sc_in< bool > maxigp0_awready;
  sc_out< sc_bv<128> > maxigp0_wdata;
  sc_out< sc_bv<16> > maxigp0_wstrb;
  sc_out< bool > maxigp0_wlast;
  sc_out< bool > maxigp0_wvalid;
  sc_in< bool > maxigp0_wready;
  sc_in< sc_bv<16> > maxigp0_bid;
  sc_in< sc_bv<2> > maxigp0_bresp;
  sc_in< bool > maxigp0_bvalid;
  sc_out< bool > maxigp0_bready;
  sc_out< sc_bv<16> > maxigp0_arid;
  sc_out< sc_bv<40> > maxigp0_araddr;
  sc_out< sc_bv<8> > maxigp0_arlen;
  sc_out< sc_bv<3> > maxigp0_arsize;
  sc_out< sc_bv<2> > maxigp0_arburst;
  sc_out< bool > maxigp0_arlock;
  sc_out< sc_bv<4> > maxigp0_arcache;
  sc_out< sc_bv<3> > maxigp0_arprot;
  sc_out< bool > maxigp0_arvalid;
  sc_out< sc_bv<16> > maxigp0_aruser;
  sc_in< bool > maxigp0_arready;
  sc_in< sc_bv<16> > maxigp0_rid;
  sc_in< sc_bv<128> > maxigp0_rdata;
  sc_in< sc_bv<2> > maxigp0_rresp;
  sc_in< bool > maxigp0_rlast;
  sc_in< bool > maxigp0_rvalid;
  sc_out< bool > maxigp0_rready;
  sc_out< sc_bv<4> > maxigp0_awqos;
  sc_out< sc_bv<4> > maxigp0_arqos;
  sc_in< bool > maxihpm1_fpd_aclk;
  sc_out< sc_bv<16> > maxigp1_awid;
  sc_out< sc_bv<40> > maxigp1_awaddr;
  sc_out< sc_bv<8> > maxigp1_awlen;
  sc_out< sc_bv<3> > maxigp1_awsize;
  sc_out< sc_bv<2> > maxigp1_awburst;
  sc_out< bool > maxigp1_awlock;
  sc_out< sc_bv<4> > maxigp1_awcache;
  sc_out< sc_bv<3> > maxigp1_awprot;
  sc_out< bool > maxigp1_awvalid;
  sc_out< sc_bv<16> > maxigp1_awuser;
  sc_in< bool > maxigp1_awready;
  sc_out< sc_bv<32> > maxigp1_wdata;
  sc_out< sc_bv<4> > maxigp1_wstrb;
  sc_out< bool > maxigp1_wlast;
  sc_out< bool > maxigp1_wvalid;
  sc_in< bool > maxigp1_wready;
  sc_in< sc_bv<16> > maxigp1_bid;
  sc_in< sc_bv<2> > maxigp1_bresp;
  sc_in< bool > maxigp1_bvalid;
  sc_out< bool > maxigp1_bready;
  sc_out< sc_bv<16> > maxigp1_arid;
  sc_out< sc_bv<40> > maxigp1_araddr;
  sc_out< sc_bv<8> > maxigp1_arlen;
  sc_out< sc_bv<3> > maxigp1_arsize;
  sc_out< sc_bv<2> > maxigp1_arburst;
  sc_out< bool > maxigp1_arlock;
  sc_out< sc_bv<4> > maxigp1_arcache;
  sc_out< sc_bv<3> > maxigp1_arprot;
  sc_out< bool > maxigp1_arvalid;
  sc_out< sc_bv<16> > maxigp1_aruser;
  sc_in< bool > maxigp1_arready;
  sc_in< sc_bv<16> > maxigp1_rid;
  sc_in< sc_bv<32> > maxigp1_rdata;
  sc_in< sc_bv<2> > maxigp1_rresp;
  sc_in< bool > maxigp1_rlast;
  sc_in< bool > maxigp1_rvalid;
  sc_out< bool > maxigp1_rready;
  sc_out< sc_bv<4> > maxigp1_awqos;
  sc_out< sc_bv<4> > maxigp1_arqos;
  sc_in< bool > maxihpm0_lpd_aclk;
  sc_out< sc_bv<16> > maxigp2_awid;
  sc_out< sc_bv<40> > maxigp2_awaddr;
  sc_out< sc_bv<8> > maxigp2_awlen;
  sc_out< sc_bv<3> > maxigp2_awsize;
  sc_out< sc_bv<2> > maxigp2_awburst;
  sc_out< bool > maxigp2_awlock;
  sc_out< sc_bv<4> > maxigp2_awcache;
  sc_out< sc_bv<3> > maxigp2_awprot;
  sc_out< bool > maxigp2_awvalid;
  sc_out< sc_bv<16> > maxigp2_awuser;
  sc_in< bool > maxigp2_awready;
  sc_out< sc_bv<32> > maxigp2_wdata;
  sc_out< sc_bv<4> > maxigp2_wstrb;
  sc_out< bool > maxigp2_wlast;
  sc_out< bool > maxigp2_wvalid;
  sc_in< bool > maxigp2_wready;
  sc_in< sc_bv<16> > maxigp2_bid;
  sc_in< sc_bv<2> > maxigp2_bresp;
  sc_in< bool > maxigp2_bvalid;
  sc_out< bool > maxigp2_bready;
  sc_out< sc_bv<16> > maxigp2_arid;
  sc_out< sc_bv<40> > maxigp2_araddr;
  sc_out< sc_bv<8> > maxigp2_arlen;
  sc_out< sc_bv<3> > maxigp2_arsize;
  sc_out< sc_bv<2> > maxigp2_arburst;
  sc_out< bool > maxigp2_arlock;
  sc_out< sc_bv<4> > maxigp2_arcache;
  sc_out< sc_bv<3> > maxigp2_arprot;
  sc_out< bool > maxigp2_arvalid;
  sc_out< sc_bv<16> > maxigp2_aruser;
  sc_in< bool > maxigp2_arready;
  sc_in< sc_bv<16> > maxigp2_rid;
  sc_in< sc_bv<32> > maxigp2_rdata;
  sc_in< sc_bv<2> > maxigp2_rresp;
  sc_in< bool > maxigp2_rlast;
  sc_in< bool > maxigp2_rvalid;
  sc_out< bool > maxigp2_rready;
  sc_out< sc_bv<4> > maxigp2_awqos;
  sc_out< sc_bv<4> > maxigp2_arqos;
  sc_in< bool > saxihp0_fpd_aclk;
  sc_in< bool > saxigp2_aruser;
  sc_in< bool > saxigp2_awuser;
  sc_in< sc_bv<6> > saxigp2_awid;
  sc_in< sc_bv<49> > saxigp2_awaddr;
  sc_in< sc_bv<8> > saxigp2_awlen;
  sc_in< sc_bv<3> > saxigp2_awsize;
  sc_in< sc_bv<2> > saxigp2_awburst;
  sc_in< bool > saxigp2_awlock;
  sc_in< sc_bv<4> > saxigp2_awcache;
  sc_in< sc_bv<3> > saxigp2_awprot;
  sc_in< bool > saxigp2_awvalid;
  sc_out< bool > saxigp2_awready;
  sc_in< sc_bv<128> > saxigp2_wdata;
  sc_in< sc_bv<16> > saxigp2_wstrb;
  sc_in< bool > saxigp2_wlast;
  sc_in< bool > saxigp2_wvalid;
  sc_out< bool > saxigp2_wready;
  sc_out< sc_bv<6> > saxigp2_bid;
  sc_out< sc_bv<2> > saxigp2_bresp;
  sc_out< bool > saxigp2_bvalid;
  sc_in< bool > saxigp2_bready;
  sc_in< sc_bv<6> > saxigp2_arid;
  sc_in< sc_bv<49> > saxigp2_araddr;
  sc_in< sc_bv<8> > saxigp2_arlen;
  sc_in< sc_bv<3> > saxigp2_arsize;
  sc_in< sc_bv<2> > saxigp2_arburst;
  sc_in< bool > saxigp2_arlock;
  sc_in< sc_bv<4> > saxigp2_arcache;
  sc_in< sc_bv<3> > saxigp2_arprot;
  sc_in< bool > saxigp2_arvalid;
  sc_out< bool > saxigp2_arready;
  sc_out< sc_bv<6> > saxigp2_rid;
  sc_out< sc_bv<128> > saxigp2_rdata;
  sc_out< sc_bv<2> > saxigp2_rresp;
  sc_out< bool > saxigp2_rlast;
  sc_out< bool > saxigp2_rvalid;
  sc_in< bool > saxigp2_rready;
  sc_in< sc_bv<4> > saxigp2_awqos;
  sc_in< sc_bv<4> > saxigp2_arqos;
  sc_in< bool > saxihp1_fpd_aclk;
  sc_in< bool > saxigp3_aruser;
  sc_in< bool > saxigp3_awuser;
  sc_in< sc_bv<6> > saxigp3_awid;
  sc_in< sc_bv<49> > saxigp3_awaddr;
  sc_in< sc_bv<8> > saxigp3_awlen;
  sc_in< sc_bv<3> > saxigp3_awsize;
  sc_in< sc_bv<2> > saxigp3_awburst;
  sc_in< bool > saxigp3_awlock;
  sc_in< sc_bv<4> > saxigp3_awcache;
  sc_in< sc_bv<3> > saxigp3_awprot;
  sc_in< bool > saxigp3_awvalid;
  sc_out< bool > saxigp3_awready;
  sc_in< sc_bv<128> > saxigp3_wdata;
  sc_in< sc_bv<16> > saxigp3_wstrb;
  sc_in< bool > saxigp3_wlast;
  sc_in< bool > saxigp3_wvalid;
  sc_out< bool > saxigp3_wready;
  sc_out< sc_bv<6> > saxigp3_bid;
  sc_out< sc_bv<2> > saxigp3_bresp;
  sc_out< bool > saxigp3_bvalid;
  sc_in< bool > saxigp3_bready;
  sc_in< sc_bv<6> > saxigp3_arid;
  sc_in< sc_bv<49> > saxigp3_araddr;
  sc_in< sc_bv<8> > saxigp3_arlen;
  sc_in< sc_bv<3> > saxigp3_arsize;
  sc_in< sc_bv<2> > saxigp3_arburst;
  sc_in< bool > saxigp3_arlock;
  sc_in< sc_bv<4> > saxigp3_arcache;
  sc_in< sc_bv<3> > saxigp3_arprot;
  sc_in< bool > saxigp3_arvalid;
  sc_out< bool > saxigp3_arready;
  sc_out< sc_bv<6> > saxigp3_rid;
  sc_out< sc_bv<128> > saxigp3_rdata;
  sc_out< sc_bv<2> > saxigp3_rresp;
  sc_out< bool > saxigp3_rlast;
  sc_out< bool > saxigp3_rvalid;
  sc_in< bool > saxigp3_rready;
  sc_in< sc_bv<4> > saxigp3_awqos;
  sc_in< sc_bv<4> > saxigp3_arqos;
  sc_in< bool > saxihp2_fpd_aclk;
  sc_in< bool > saxigp4_aruser;
  sc_in< bool > saxigp4_awuser;
  sc_in< sc_bv<6> > saxigp4_awid;
  sc_in< sc_bv<49> > saxigp4_awaddr;
  sc_in< sc_bv<8> > saxigp4_awlen;
  sc_in< sc_bv<3> > saxigp4_awsize;
  sc_in< sc_bv<2> > saxigp4_awburst;
  sc_in< bool > saxigp4_awlock;
  sc_in< sc_bv<4> > saxigp4_awcache;
  sc_in< sc_bv<3> > saxigp4_awprot;
  sc_in< bool > saxigp4_awvalid;
  sc_out< bool > saxigp4_awready;
  sc_in< sc_bv<128> > saxigp4_wdata;
  sc_in< sc_bv<16> > saxigp4_wstrb;
  sc_in< bool > saxigp4_wlast;
  sc_in< bool > saxigp4_wvalid;
  sc_out< bool > saxigp4_wready;
  sc_out< sc_bv<6> > saxigp4_bid;
  sc_out< sc_bv<2> > saxigp4_bresp;
  sc_out< bool > saxigp4_bvalid;
  sc_in< bool > saxigp4_bready;
  sc_in< sc_bv<6> > saxigp4_arid;
  sc_in< sc_bv<49> > saxigp4_araddr;
  sc_in< sc_bv<8> > saxigp4_arlen;
  sc_in< sc_bv<3> > saxigp4_arsize;
  sc_in< sc_bv<2> > saxigp4_arburst;
  sc_in< bool > saxigp4_arlock;
  sc_in< sc_bv<4> > saxigp4_arcache;
  sc_in< sc_bv<3> > saxigp4_arprot;
  sc_in< bool > saxigp4_arvalid;
  sc_out< bool > saxigp4_arready;
  sc_out< sc_bv<6> > saxigp4_rid;
  sc_out< sc_bv<128> > saxigp4_rdata;
  sc_out< sc_bv<2> > saxigp4_rresp;
  sc_out< bool > saxigp4_rlast;
  sc_out< bool > saxigp4_rvalid;
  sc_in< bool > saxigp4_rready;
  sc_in< sc_bv<4> > saxigp4_awqos;
  sc_in< sc_bv<4> > saxigp4_arqos;
  sc_in< bool > saxi_lpd_aclk;
  sc_in< bool > saxigp6_aruser;
  sc_in< bool > saxigp6_awuser;
  sc_in< sc_bv<6> > saxigp6_awid;
  sc_in< sc_bv<49> > saxigp6_awaddr;
  sc_in< sc_bv<8> > saxigp6_awlen;
  sc_in< sc_bv<3> > saxigp6_awsize;
  sc_in< sc_bv<2> > saxigp6_awburst;
  sc_in< bool > saxigp6_awlock;
  sc_in< sc_bv<4> > saxigp6_awcache;
  sc_in< sc_bv<3> > saxigp6_awprot;
  sc_in< bool > saxigp6_awvalid;
  sc_out< bool > saxigp6_awready;
  sc_in< sc_bv<128> > saxigp6_wdata;
  sc_in< sc_bv<16> > saxigp6_wstrb;
  sc_in< bool > saxigp6_wlast;
  sc_in< bool > saxigp6_wvalid;
  sc_out< bool > saxigp6_wready;
  sc_out< sc_bv<6> > saxigp6_bid;
  sc_out< sc_bv<2> > saxigp6_bresp;
  sc_out< bool > saxigp6_bvalid;
  sc_in< bool > saxigp6_bready;
  sc_in< sc_bv<6> > saxigp6_arid;
  sc_in< sc_bv<49> > saxigp6_araddr;
  sc_in< sc_bv<8> > saxigp6_arlen;
  sc_in< sc_bv<3> > saxigp6_arsize;
  sc_in< sc_bv<2> > saxigp6_arburst;
  sc_in< bool > saxigp6_arlock;
  sc_in< sc_bv<4> > saxigp6_arcache;
  sc_in< sc_bv<3> > saxigp6_arprot;
  sc_in< bool > saxigp6_arvalid;
  sc_out< bool > saxigp6_arready;
  sc_out< sc_bv<6> > saxigp6_rid;
  sc_out< sc_bv<128> > saxigp6_rdata;
  sc_out< sc_bv<2> > saxigp6_rresp;
  sc_out< bool > saxigp6_rlast;
  sc_out< bool > saxigp6_rvalid;
  sc_in< bool > saxigp6_rready;
  sc_in< sc_bv<4> > saxigp6_awqos;
  sc_in< sc_bv<4> > saxigp6_arqos;
  sc_in< bool > emio_spi0_sclk_i;
  sc_out< bool > emio_spi0_sclk_o;
  sc_out< bool > emio_spi0_sclk_t;
  sc_in< bool > emio_spi0_m_i;
  sc_out< bool > emio_spi0_m_o;
  sc_out< bool > emio_spi0_mo_t;
  sc_in< bool > emio_spi0_s_i;
  sc_out< bool > emio_spi0_s_o;
  sc_out< bool > emio_spi0_so_t;
  sc_in< bool > emio_spi0_ss_i_n;
  sc_out< bool > emio_spi0_ss_o_n;
  sc_out< bool > emio_spi0_ss_n_t;
  sc_in< sc_bv<4> > pl_ps_irq0;
  sc_in< sc_bv<4> > pl_ps_irq1;
  sc_out< bool > pl_resetn0;
  sc_out< bool > pl_clk0;
  sc_out< bool > pl_clk1;

public: // module socket-to-socket TLM interface

  xtlm::xtlm_aximm_initiator_socket* M_AXI_HPM0_FPD_wr_socket;
  xtlm::xtlm_aximm_initiator_socket* M_AXI_HPM0_FPD_rd_socket;
  xtlm::xtlm_aximm_initiator_socket* M_AXI_HPM1_FPD_wr_socket;
  xtlm::xtlm_aximm_initiator_socket* M_AXI_HPM1_FPD_rd_socket;
  xtlm::xtlm_aximm_initiator_socket* M_AXI_HPM0_LPD_wr_socket;
  xtlm::xtlm_aximm_initiator_socket* M_AXI_HPM0_LPD_rd_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_HP0_FPD_wr_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_HP0_FPD_rd_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_HP1_FPD_wr_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_HP1_FPD_rd_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_HP2_FPD_wr_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_HP2_FPD_rd_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_LPD_wr_socket;
  xtlm::xtlm_aximm_target_socket* S_AXI_LPD_rd_socket;

protected:

  virtual void before_end_of_elaboration();

private:

  design_1_zynq_ultra_ps_e_0_0(const design_1_zynq_ultra_ps_e_0_0&);
  const design_1_zynq_ultra_ps_e_0_0& operator=(const design_1_zynq_ultra_ps_e_0_0&);

  zynq_ultra_ps_e_tlm* mp_impl;

  xtlm::xaximm_xtlm2pin_t<128,40,16,16,1,1,16,1>* mp_M_AXI_HPM0_FPD_transactor;
  sc_signal< bool > m_M_AXI_HPM0_FPD_transactor_rst_signal;

  xtlm::xaximm_xtlm2pin_t<32,40,16,16,1,1,16,1>* mp_M_AXI_HPM1_FPD_transactor;
  sc_signal< bool > m_M_AXI_HPM1_FPD_transactor_rst_signal;

  xtlm::xaximm_xtlm2pin_t<32,40,16,16,1,1,16,1>* mp_M_AXI_HPM0_LPD_transactor;
  sc_signal< bool > m_M_AXI_HPM0_LPD_transactor_rst_signal;

  xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>* mp_S_AXI_HP0_FPD_transactor;
  xsc::common::scalar2vector_converter* mp_saxigp2_aruser_converter;
  sc_signal< sc_bv<1> > m_saxigp2_aruser_converter_signal;
  xsc::common::scalar2vector_converter* mp_saxigp2_awuser_converter;
  sc_signal< sc_bv<1> > m_saxigp2_awuser_converter_signal;
  sc_signal< bool > m_S_AXI_HP0_FPD_transactor_rst_signal;

  xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>* mp_S_AXI_HP1_FPD_transactor;
  xsc::common::scalar2vector_converter* mp_saxigp3_aruser_converter;
  sc_signal< sc_bv<1> > m_saxigp3_aruser_converter_signal;
  xsc::common::scalar2vector_converter* mp_saxigp3_awuser_converter;
  sc_signal< sc_bv<1> > m_saxigp3_awuser_converter_signal;
  sc_signal< bool > m_S_AXI_HP1_FPD_transactor_rst_signal;

  xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>* mp_S_AXI_HP2_FPD_transactor;
  xsc::common::scalar2vector_converter* mp_saxigp4_aruser_converter;
  sc_signal< sc_bv<1> > m_saxigp4_aruser_converter_signal;
  xsc::common::scalar2vector_converter* mp_saxigp4_awuser_converter;
  sc_signal< sc_bv<1> > m_saxigp4_awuser_converter_signal;
  sc_signal< bool > m_S_AXI_HP2_FPD_transactor_rst_signal;

  xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>* mp_S_AXI_LPD_transactor;
  xsc::common::scalar2vector_converter* mp_saxigp6_aruser_converter;
  sc_signal< sc_bv<1> > m_saxigp6_aruser_converter_signal;
  xsc::common::scalar2vector_converter* mp_saxigp6_awuser_converter;
  sc_signal< sc_bv<1> > m_saxigp6_awuser_converter_signal;
  sc_signal< bool > m_S_AXI_LPD_transactor_rst_signal;

};

#endif // IP_DESIGN_1_ZYNQ_ULTRA_PS_E_0_0_H_
