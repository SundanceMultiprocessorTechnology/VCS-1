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

#include "design_1_zynq_ultra_ps_e_0_0.h"

#include "zynq_ultra_ps_e_tlm.h"

#include <map>
#include <string>

design_1_zynq_ultra_ps_e_0_0::design_1_zynq_ultra_ps_e_0_0(const sc_module_name& nm) : sc_module(nm), mp_impl(NULL)
{
  // configure connectivity manager
  xsc::utils::xsc_sim_manager::addInstance("design_1_zynq_ultra_ps_e_0_0", this);

  // initialize module
  xsc::common_cpp::properties model_param_props;
  model_param_props.addLong("C_DP_USE_AUDIO", "0");
  model_param_props.addLong("C_DP_USE_VIDEO", "0");
  model_param_props.addLong("C_MAXIGP0_DATA_WIDTH", "128");
  model_param_props.addLong("C_MAXIGP1_DATA_WIDTH", "32");
  model_param_props.addLong("C_MAXIGP2_DATA_WIDTH", "32");
  model_param_props.addLong("C_SAXIGP0_DATA_WIDTH", "128");
  model_param_props.addLong("C_SAXIGP1_DATA_WIDTH", "128");
  model_param_props.addLong("C_SAXIGP2_DATA_WIDTH", "128");
  model_param_props.addLong("C_SAXIGP3_DATA_WIDTH", "128");
  model_param_props.addLong("C_SAXIGP4_DATA_WIDTH", "128");
  model_param_props.addLong("C_SAXIGP5_DATA_WIDTH", "128");
  model_param_props.addLong("C_SAXIGP6_DATA_WIDTH", "128");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP0", "0");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP1", "0");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP2", "0");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP3", "0");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP4", "0");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP5", "0");
  model_param_props.addLong("C_USE_DIFF_RW_CLK_GP6", "0");
  model_param_props.addLong("C_TRACE_PIPELINE_WIDTH", "8");
  model_param_props.addLong("C_EN_EMIO_TRACE", "0");
  model_param_props.addLong("C_TRACE_DATA_WIDTH", "32");
  model_param_props.addLong("C_USE_DEBUG_TEST", "0");
  model_param_props.addLong("C_SD0_INTERNAL_BUS_WIDTH", "8");
  model_param_props.addLong("C_SD1_INTERNAL_BUS_WIDTH", "4");
  model_param_props.addLong("C_NUM_F2P_0_INTR_INPUTS", "4");
  model_param_props.addLong("C_NUM_F2P_1_INTR_INPUTS", "4");
  model_param_props.addLong("C_EMIO_GPIO_WIDTH", "1");
  model_param_props.addLong("C_NUM_FABRIC_RESETS", "1");
  model_param_props.addString("C_EN_FIFO_ENET0", "0");
  model_param_props.addString("C_EN_FIFO_ENET1", "0");
  model_param_props.addString("C_EN_FIFO_ENET2", "0");
  model_param_props.addString("C_EN_FIFO_ENET3", "0");
  model_param_props.addString("C_PL_CLK0_BUF", "TRUE");
  model_param_props.addString("C_PL_CLK1_BUF", "TRUE");
  model_param_props.addString("C_PL_CLK2_BUF", "FALSE");
  model_param_props.addString("C_PL_CLK3_BUF", "FALSE");
  mp_impl = new zynq_ultra_ps_e_tlm("inst", model_param_props);

  // initialize sockets
  M_AXI_HPM0_FPD_wr_socket = mp_impl->M_AXI_HPM0_FPD_wr_socket;
  M_AXI_HPM0_FPD_rd_socket = mp_impl->M_AXI_HPM0_FPD_rd_socket;
  M_AXI_HPM1_FPD_wr_socket = mp_impl->M_AXI_HPM1_FPD_wr_socket;
  M_AXI_HPM1_FPD_rd_socket = mp_impl->M_AXI_HPM1_FPD_rd_socket;
  M_AXI_HPM0_LPD_wr_socket = mp_impl->M_AXI_HPM0_LPD_wr_socket;
  M_AXI_HPM0_LPD_rd_socket = mp_impl->M_AXI_HPM0_LPD_rd_socket;
  S_AXI_HP0_FPD_wr_socket = mp_impl->S_AXI_HP0_FPD_wr_socket;
  S_AXI_HP0_FPD_rd_socket = mp_impl->S_AXI_HP0_FPD_rd_socket;
  S_AXI_HP1_FPD_wr_socket = mp_impl->S_AXI_HP1_FPD_wr_socket;
  S_AXI_HP1_FPD_rd_socket = mp_impl->S_AXI_HP1_FPD_rd_socket;
  S_AXI_HP2_FPD_wr_socket = mp_impl->S_AXI_HP2_FPD_wr_socket;
  S_AXI_HP2_FPD_rd_socket = mp_impl->S_AXI_HP2_FPD_rd_socket;
  S_AXI_LPD_wr_socket = mp_impl->S_AXI_LPD_wr_socket;
  S_AXI_LPD_rd_socket = mp_impl->S_AXI_LPD_rd_socket;

  // initialize pins
  mp_impl->maxihpm0_fpd_aclk(maxihpm0_fpd_aclk);
  mp_impl->maxihpm1_fpd_aclk(maxihpm1_fpd_aclk);
  mp_impl->maxihpm0_lpd_aclk(maxihpm0_lpd_aclk);
  mp_impl->saxihp0_fpd_aclk(saxihp0_fpd_aclk);
  mp_impl->saxihp1_fpd_aclk(saxihp1_fpd_aclk);
  mp_impl->saxihp2_fpd_aclk(saxihp2_fpd_aclk);
  mp_impl->saxi_lpd_aclk(saxi_lpd_aclk);
  mp_impl->emio_spi0_sclk_i(emio_spi0_sclk_i);
  mp_impl->emio_spi0_sclk_o(emio_spi0_sclk_o);
  mp_impl->emio_spi0_sclk_t(emio_spi0_sclk_t);
  mp_impl->emio_spi0_m_i(emio_spi0_m_i);
  mp_impl->emio_spi0_m_o(emio_spi0_m_o);
  mp_impl->emio_spi0_mo_t(emio_spi0_mo_t);
  mp_impl->emio_spi0_s_i(emio_spi0_s_i);
  mp_impl->emio_spi0_s_o(emio_spi0_s_o);
  mp_impl->emio_spi0_so_t(emio_spi0_so_t);
  mp_impl->emio_spi0_ss_i_n(emio_spi0_ss_i_n);
  mp_impl->emio_spi0_ss_o_n(emio_spi0_ss_o_n);
  mp_impl->emio_spi0_ss_n_t(emio_spi0_ss_n_t);
  mp_impl->pl_ps_irq0(pl_ps_irq0);
  mp_impl->pl_ps_irq1(pl_ps_irq1);
  mp_impl->pl_resetn0(pl_resetn0);
  mp_impl->pl_clk0(pl_clk0);
  mp_impl->pl_clk1(pl_clk1);

  // initialize transactors
  mp_M_AXI_HPM0_FPD_transactor = NULL;
  mp_M_AXI_HPM1_FPD_transactor = NULL;
  mp_M_AXI_HPM0_LPD_transactor = NULL;
  mp_S_AXI_HP0_FPD_transactor = NULL;
  mp_saxigp2_aruser_converter = NULL;
  mp_saxigp2_awuser_converter = NULL;
  mp_S_AXI_HP1_FPD_transactor = NULL;
  mp_saxigp3_aruser_converter = NULL;
  mp_saxigp3_awuser_converter = NULL;
  mp_S_AXI_HP2_FPD_transactor = NULL;
  mp_saxigp4_aruser_converter = NULL;
  mp_saxigp4_awuser_converter = NULL;
  mp_S_AXI_LPD_transactor = NULL;
  mp_saxigp6_aruser_converter = NULL;
  mp_saxigp6_awuser_converter = NULL;
}

void design_1_zynq_ultra_ps_e_0_0::before_end_of_elaboration()
{
  // configure 'M_AXI_HPM0_FPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "M_AXI_HPM0_FPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties M_AXI_HPM0_FPD_transactor_param_props;
    M_AXI_HPM0_FPD_transactor_param_props.addLong("DATA_WIDTH", "128");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("FREQ_HZ", "99999985");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("ID_WIDTH", "16");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("ADDR_WIDTH", "40");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("AWUSER_WIDTH", "16");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("ARUSER_WIDTH", "16");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_BURST", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_LOCK", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_CACHE", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_QOS", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "1");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "256");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_HPM0_FPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_HPM0_FPD_transactor_param_props.addFloat("PHASE", "0.000");
    M_AXI_HPM0_FPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_HPM0_FPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "8");
    M_AXI_HPM0_FPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    M_AXI_HPM0_FPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_HPM0_FPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_zynq_ultra_ps_e_0_0_pl_clk0");
    mp_M_AXI_HPM0_FPD_transactor = new xtlm::xaximm_xtlm2pin_t<128,40,16,16,1,1,16,1>("M_AXI_HPM0_FPD_transactor", M_AXI_HPM0_FPD_transactor_param_props);
    mp_M_AXI_HPM0_FPD_transactor->AWID(maxigp0_awid);
    mp_M_AXI_HPM0_FPD_transactor->AWADDR(maxigp0_awaddr);
    mp_M_AXI_HPM0_FPD_transactor->AWLEN(maxigp0_awlen);
    mp_M_AXI_HPM0_FPD_transactor->AWSIZE(maxigp0_awsize);
    mp_M_AXI_HPM0_FPD_transactor->AWBURST(maxigp0_awburst);
    mp_M_AXI_HPM0_FPD_transactor->AWLOCK(maxigp0_awlock);
    mp_M_AXI_HPM0_FPD_transactor->AWCACHE(maxigp0_awcache);
    mp_M_AXI_HPM0_FPD_transactor->AWPROT(maxigp0_awprot);
    mp_M_AXI_HPM0_FPD_transactor->AWVALID(maxigp0_awvalid);
    mp_M_AXI_HPM0_FPD_transactor->AWUSER(maxigp0_awuser);
    mp_M_AXI_HPM0_FPD_transactor->AWREADY(maxigp0_awready);
    mp_M_AXI_HPM0_FPD_transactor->WDATA(maxigp0_wdata);
    mp_M_AXI_HPM0_FPD_transactor->WSTRB(maxigp0_wstrb);
    mp_M_AXI_HPM0_FPD_transactor->WLAST(maxigp0_wlast);
    mp_M_AXI_HPM0_FPD_transactor->WVALID(maxigp0_wvalid);
    mp_M_AXI_HPM0_FPD_transactor->WREADY(maxigp0_wready);
    mp_M_AXI_HPM0_FPD_transactor->BID(maxigp0_bid);
    mp_M_AXI_HPM0_FPD_transactor->BRESP(maxigp0_bresp);
    mp_M_AXI_HPM0_FPD_transactor->BVALID(maxigp0_bvalid);
    mp_M_AXI_HPM0_FPD_transactor->BREADY(maxigp0_bready);
    mp_M_AXI_HPM0_FPD_transactor->ARID(maxigp0_arid);
    mp_M_AXI_HPM0_FPD_transactor->ARADDR(maxigp0_araddr);
    mp_M_AXI_HPM0_FPD_transactor->ARLEN(maxigp0_arlen);
    mp_M_AXI_HPM0_FPD_transactor->ARSIZE(maxigp0_arsize);
    mp_M_AXI_HPM0_FPD_transactor->ARBURST(maxigp0_arburst);
    mp_M_AXI_HPM0_FPD_transactor->ARLOCK(maxigp0_arlock);
    mp_M_AXI_HPM0_FPD_transactor->ARCACHE(maxigp0_arcache);
    mp_M_AXI_HPM0_FPD_transactor->ARPROT(maxigp0_arprot);
    mp_M_AXI_HPM0_FPD_transactor->ARVALID(maxigp0_arvalid);
    mp_M_AXI_HPM0_FPD_transactor->ARUSER(maxigp0_aruser);
    mp_M_AXI_HPM0_FPD_transactor->ARREADY(maxigp0_arready);
    mp_M_AXI_HPM0_FPD_transactor->RID(maxigp0_rid);
    mp_M_AXI_HPM0_FPD_transactor->RDATA(maxigp0_rdata);
    mp_M_AXI_HPM0_FPD_transactor->RRESP(maxigp0_rresp);
    mp_M_AXI_HPM0_FPD_transactor->RLAST(maxigp0_rlast);
    mp_M_AXI_HPM0_FPD_transactor->RVALID(maxigp0_rvalid);
    mp_M_AXI_HPM0_FPD_transactor->RREADY(maxigp0_rready);
    mp_M_AXI_HPM0_FPD_transactor->AWQOS(maxigp0_awqos);
    mp_M_AXI_HPM0_FPD_transactor->ARQOS(maxigp0_arqos);
    mp_M_AXI_HPM0_FPD_transactor->CLK(maxihpm0_fpd_aclk);
    m_M_AXI_HPM0_FPD_transactor_rst_signal.write(1);
    mp_M_AXI_HPM0_FPD_transactor->RST(m_M_AXI_HPM0_FPD_transactor_rst_signal);

    mp_impl->M_AXI_HPM0_FPD_wr_socket->bind(*(mp_M_AXI_HPM0_FPD_transactor->wr_socket));
    mp_impl->M_AXI_HPM0_FPD_rd_socket->bind(*(mp_M_AXI_HPM0_FPD_transactor->rd_socket));
  }
  // configure 'M_AXI_HPM1_FPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "M_AXI_HPM1_FPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties M_AXI_HPM1_FPD_transactor_param_props;
    M_AXI_HPM1_FPD_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("FREQ_HZ", "102457264");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("ID_WIDTH", "16");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("ADDR_WIDTH", "40");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("AWUSER_WIDTH", "16");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("ARUSER_WIDTH", "16");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_BURST", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_LOCK", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_CACHE", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_QOS", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "1");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "256");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_HPM1_FPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_HPM1_FPD_transactor_param_props.addFloat("PHASE", "0.0");
    M_AXI_HPM1_FPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_HPM1_FPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "8");
    M_AXI_HPM1_FPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    M_AXI_HPM1_FPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_HPM1_FPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_clk_wiz_0_0_clk_666m");
    mp_M_AXI_HPM1_FPD_transactor = new xtlm::xaximm_xtlm2pin_t<32,40,16,16,1,1,16,1>("M_AXI_HPM1_FPD_transactor", M_AXI_HPM1_FPD_transactor_param_props);
    mp_M_AXI_HPM1_FPD_transactor->AWID(maxigp1_awid);
    mp_M_AXI_HPM1_FPD_transactor->AWADDR(maxigp1_awaddr);
    mp_M_AXI_HPM1_FPD_transactor->AWLEN(maxigp1_awlen);
    mp_M_AXI_HPM1_FPD_transactor->AWSIZE(maxigp1_awsize);
    mp_M_AXI_HPM1_FPD_transactor->AWBURST(maxigp1_awburst);
    mp_M_AXI_HPM1_FPD_transactor->AWLOCK(maxigp1_awlock);
    mp_M_AXI_HPM1_FPD_transactor->AWCACHE(maxigp1_awcache);
    mp_M_AXI_HPM1_FPD_transactor->AWPROT(maxigp1_awprot);
    mp_M_AXI_HPM1_FPD_transactor->AWVALID(maxigp1_awvalid);
    mp_M_AXI_HPM1_FPD_transactor->AWUSER(maxigp1_awuser);
    mp_M_AXI_HPM1_FPD_transactor->AWREADY(maxigp1_awready);
    mp_M_AXI_HPM1_FPD_transactor->WDATA(maxigp1_wdata);
    mp_M_AXI_HPM1_FPD_transactor->WSTRB(maxigp1_wstrb);
    mp_M_AXI_HPM1_FPD_transactor->WLAST(maxigp1_wlast);
    mp_M_AXI_HPM1_FPD_transactor->WVALID(maxigp1_wvalid);
    mp_M_AXI_HPM1_FPD_transactor->WREADY(maxigp1_wready);
    mp_M_AXI_HPM1_FPD_transactor->BID(maxigp1_bid);
    mp_M_AXI_HPM1_FPD_transactor->BRESP(maxigp1_bresp);
    mp_M_AXI_HPM1_FPD_transactor->BVALID(maxigp1_bvalid);
    mp_M_AXI_HPM1_FPD_transactor->BREADY(maxigp1_bready);
    mp_M_AXI_HPM1_FPD_transactor->ARID(maxigp1_arid);
    mp_M_AXI_HPM1_FPD_transactor->ARADDR(maxigp1_araddr);
    mp_M_AXI_HPM1_FPD_transactor->ARLEN(maxigp1_arlen);
    mp_M_AXI_HPM1_FPD_transactor->ARSIZE(maxigp1_arsize);
    mp_M_AXI_HPM1_FPD_transactor->ARBURST(maxigp1_arburst);
    mp_M_AXI_HPM1_FPD_transactor->ARLOCK(maxigp1_arlock);
    mp_M_AXI_HPM1_FPD_transactor->ARCACHE(maxigp1_arcache);
    mp_M_AXI_HPM1_FPD_transactor->ARPROT(maxigp1_arprot);
    mp_M_AXI_HPM1_FPD_transactor->ARVALID(maxigp1_arvalid);
    mp_M_AXI_HPM1_FPD_transactor->ARUSER(maxigp1_aruser);
    mp_M_AXI_HPM1_FPD_transactor->ARREADY(maxigp1_arready);
    mp_M_AXI_HPM1_FPD_transactor->RID(maxigp1_rid);
    mp_M_AXI_HPM1_FPD_transactor->RDATA(maxigp1_rdata);
    mp_M_AXI_HPM1_FPD_transactor->RRESP(maxigp1_rresp);
    mp_M_AXI_HPM1_FPD_transactor->RLAST(maxigp1_rlast);
    mp_M_AXI_HPM1_FPD_transactor->RVALID(maxigp1_rvalid);
    mp_M_AXI_HPM1_FPD_transactor->RREADY(maxigp1_rready);
    mp_M_AXI_HPM1_FPD_transactor->AWQOS(maxigp1_awqos);
    mp_M_AXI_HPM1_FPD_transactor->ARQOS(maxigp1_arqos);
    mp_M_AXI_HPM1_FPD_transactor->CLK(maxihpm1_fpd_aclk);
    m_M_AXI_HPM1_FPD_transactor_rst_signal.write(1);
    mp_M_AXI_HPM1_FPD_transactor->RST(m_M_AXI_HPM1_FPD_transactor_rst_signal);

    mp_impl->M_AXI_HPM1_FPD_wr_socket->bind(*(mp_M_AXI_HPM1_FPD_transactor->wr_socket));
    mp_impl->M_AXI_HPM1_FPD_rd_socket->bind(*(mp_M_AXI_HPM1_FPD_transactor->rd_socket));
  }
  // configure 'M_AXI_HPM0_LPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "M_AXI_HPM0_LPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties M_AXI_HPM0_LPD_transactor_param_props;
    M_AXI_HPM0_LPD_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("FREQ_HZ", "99999985");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("ID_WIDTH", "16");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("ADDR_WIDTH", "40");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("AWUSER_WIDTH", "16");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("ARUSER_WIDTH", "16");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_BURST", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_LOCK", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_CACHE", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_QOS", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "1");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "256");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_HPM0_LPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_HPM0_LPD_transactor_param_props.addFloat("PHASE", "0.000");
    M_AXI_HPM0_LPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_HPM0_LPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "8");
    M_AXI_HPM0_LPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    M_AXI_HPM0_LPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_HPM0_LPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_zynq_ultra_ps_e_0_0_pl_clk0");
    mp_M_AXI_HPM0_LPD_transactor = new xtlm::xaximm_xtlm2pin_t<32,40,16,16,1,1,16,1>("M_AXI_HPM0_LPD_transactor", M_AXI_HPM0_LPD_transactor_param_props);
    mp_M_AXI_HPM0_LPD_transactor->AWID(maxigp2_awid);
    mp_M_AXI_HPM0_LPD_transactor->AWADDR(maxigp2_awaddr);
    mp_M_AXI_HPM0_LPD_transactor->AWLEN(maxigp2_awlen);
    mp_M_AXI_HPM0_LPD_transactor->AWSIZE(maxigp2_awsize);
    mp_M_AXI_HPM0_LPD_transactor->AWBURST(maxigp2_awburst);
    mp_M_AXI_HPM0_LPD_transactor->AWLOCK(maxigp2_awlock);
    mp_M_AXI_HPM0_LPD_transactor->AWCACHE(maxigp2_awcache);
    mp_M_AXI_HPM0_LPD_transactor->AWPROT(maxigp2_awprot);
    mp_M_AXI_HPM0_LPD_transactor->AWVALID(maxigp2_awvalid);
    mp_M_AXI_HPM0_LPD_transactor->AWUSER(maxigp2_awuser);
    mp_M_AXI_HPM0_LPD_transactor->AWREADY(maxigp2_awready);
    mp_M_AXI_HPM0_LPD_transactor->WDATA(maxigp2_wdata);
    mp_M_AXI_HPM0_LPD_transactor->WSTRB(maxigp2_wstrb);
    mp_M_AXI_HPM0_LPD_transactor->WLAST(maxigp2_wlast);
    mp_M_AXI_HPM0_LPD_transactor->WVALID(maxigp2_wvalid);
    mp_M_AXI_HPM0_LPD_transactor->WREADY(maxigp2_wready);
    mp_M_AXI_HPM0_LPD_transactor->BID(maxigp2_bid);
    mp_M_AXI_HPM0_LPD_transactor->BRESP(maxigp2_bresp);
    mp_M_AXI_HPM0_LPD_transactor->BVALID(maxigp2_bvalid);
    mp_M_AXI_HPM0_LPD_transactor->BREADY(maxigp2_bready);
    mp_M_AXI_HPM0_LPD_transactor->ARID(maxigp2_arid);
    mp_M_AXI_HPM0_LPD_transactor->ARADDR(maxigp2_araddr);
    mp_M_AXI_HPM0_LPD_transactor->ARLEN(maxigp2_arlen);
    mp_M_AXI_HPM0_LPD_transactor->ARSIZE(maxigp2_arsize);
    mp_M_AXI_HPM0_LPD_transactor->ARBURST(maxigp2_arburst);
    mp_M_AXI_HPM0_LPD_transactor->ARLOCK(maxigp2_arlock);
    mp_M_AXI_HPM0_LPD_transactor->ARCACHE(maxigp2_arcache);
    mp_M_AXI_HPM0_LPD_transactor->ARPROT(maxigp2_arprot);
    mp_M_AXI_HPM0_LPD_transactor->ARVALID(maxigp2_arvalid);
    mp_M_AXI_HPM0_LPD_transactor->ARUSER(maxigp2_aruser);
    mp_M_AXI_HPM0_LPD_transactor->ARREADY(maxigp2_arready);
    mp_M_AXI_HPM0_LPD_transactor->RID(maxigp2_rid);
    mp_M_AXI_HPM0_LPD_transactor->RDATA(maxigp2_rdata);
    mp_M_AXI_HPM0_LPD_transactor->RRESP(maxigp2_rresp);
    mp_M_AXI_HPM0_LPD_transactor->RLAST(maxigp2_rlast);
    mp_M_AXI_HPM0_LPD_transactor->RVALID(maxigp2_rvalid);
    mp_M_AXI_HPM0_LPD_transactor->RREADY(maxigp2_rready);
    mp_M_AXI_HPM0_LPD_transactor->AWQOS(maxigp2_awqos);
    mp_M_AXI_HPM0_LPD_transactor->ARQOS(maxigp2_arqos);
    mp_M_AXI_HPM0_LPD_transactor->CLK(maxihpm0_lpd_aclk);
    m_M_AXI_HPM0_LPD_transactor_rst_signal.write(1);
    mp_M_AXI_HPM0_LPD_transactor->RST(m_M_AXI_HPM0_LPD_transactor_rst_signal);

    mp_impl->M_AXI_HPM0_LPD_wr_socket->bind(*(mp_M_AXI_HPM0_LPD_transactor->wr_socket));
    mp_impl->M_AXI_HPM0_LPD_rd_socket->bind(*(mp_M_AXI_HPM0_LPD_transactor->rd_socket));
  }
  // configure 'S_AXI_HP0_FPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "S_AXI_HP0_FPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties S_AXI_HP0_FPD_transactor_param_props;
    S_AXI_HP0_FPD_transactor_param_props.addLong("DATA_WIDTH", "128");
    S_AXI_HP0_FPD_transactor_param_props.addLong("FREQ_HZ", "99999985");
    S_AXI_HP0_FPD_transactor_param_props.addLong("ID_WIDTH", "6");
    S_AXI_HP0_FPD_transactor_param_props.addLong("ADDR_WIDTH", "49");
    S_AXI_HP0_FPD_transactor_param_props.addLong("AWUSER_WIDTH", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("ARUSER_WIDTH", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_HP0_FPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_HP0_FPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    S_AXI_HP0_FPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "4");
    S_AXI_HP0_FPD_transactor_param_props.addLong("NUM_READ_THREADS", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "1");
    S_AXI_HP0_FPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_HP0_FPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_HP0_FPD_transactor_param_props.addFloat("PHASE", "0.000");
    S_AXI_HP0_FPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "16");
    S_AXI_HP0_FPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "16");
    S_AXI_HP0_FPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    S_AXI_HP0_FPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_HP0_FPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_zynq_ultra_ps_e_0_0_pl_clk0");
    mp_S_AXI_HP0_FPD_transactor = new xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>("S_AXI_HP0_FPD_transactor", S_AXI_HP0_FPD_transactor_param_props);
    mp_saxigp2_aruser_converter = new xsc::common::scalar2vector_converter("saxigp2_aruser_converter");
    mp_saxigp2_aruser_converter->scalar_in(saxigp2_aruser);
    mp_saxigp2_aruser_converter->vector_out(m_saxigp2_aruser_converter_signal);
    mp_S_AXI_HP0_FPD_transactor->ARUSER(m_saxigp2_aruser_converter_signal);
    mp_saxigp2_awuser_converter = new xsc::common::scalar2vector_converter("saxigp2_awuser_converter");
    mp_saxigp2_awuser_converter->scalar_in(saxigp2_awuser);
    mp_saxigp2_awuser_converter->vector_out(m_saxigp2_awuser_converter_signal);
    mp_S_AXI_HP0_FPD_transactor->AWUSER(m_saxigp2_awuser_converter_signal);
    mp_S_AXI_HP0_FPD_transactor->AWID(saxigp2_awid);
    mp_S_AXI_HP0_FPD_transactor->AWADDR(saxigp2_awaddr);
    mp_S_AXI_HP0_FPD_transactor->AWLEN(saxigp2_awlen);
    mp_S_AXI_HP0_FPD_transactor->AWSIZE(saxigp2_awsize);
    mp_S_AXI_HP0_FPD_transactor->AWBURST(saxigp2_awburst);
    mp_S_AXI_HP0_FPD_transactor->AWLOCK(saxigp2_awlock);
    mp_S_AXI_HP0_FPD_transactor->AWCACHE(saxigp2_awcache);
    mp_S_AXI_HP0_FPD_transactor->AWPROT(saxigp2_awprot);
    mp_S_AXI_HP0_FPD_transactor->AWVALID(saxigp2_awvalid);
    mp_S_AXI_HP0_FPD_transactor->AWREADY(saxigp2_awready);
    mp_S_AXI_HP0_FPD_transactor->WDATA(saxigp2_wdata);
    mp_S_AXI_HP0_FPD_transactor->WSTRB(saxigp2_wstrb);
    mp_S_AXI_HP0_FPD_transactor->WLAST(saxigp2_wlast);
    mp_S_AXI_HP0_FPD_transactor->WVALID(saxigp2_wvalid);
    mp_S_AXI_HP0_FPD_transactor->WREADY(saxigp2_wready);
    mp_S_AXI_HP0_FPD_transactor->BID(saxigp2_bid);
    mp_S_AXI_HP0_FPD_transactor->BRESP(saxigp2_bresp);
    mp_S_AXI_HP0_FPD_transactor->BVALID(saxigp2_bvalid);
    mp_S_AXI_HP0_FPD_transactor->BREADY(saxigp2_bready);
    mp_S_AXI_HP0_FPD_transactor->ARID(saxigp2_arid);
    mp_S_AXI_HP0_FPD_transactor->ARADDR(saxigp2_araddr);
    mp_S_AXI_HP0_FPD_transactor->ARLEN(saxigp2_arlen);
    mp_S_AXI_HP0_FPD_transactor->ARSIZE(saxigp2_arsize);
    mp_S_AXI_HP0_FPD_transactor->ARBURST(saxigp2_arburst);
    mp_S_AXI_HP0_FPD_transactor->ARLOCK(saxigp2_arlock);
    mp_S_AXI_HP0_FPD_transactor->ARCACHE(saxigp2_arcache);
    mp_S_AXI_HP0_FPD_transactor->ARPROT(saxigp2_arprot);
    mp_S_AXI_HP0_FPD_transactor->ARVALID(saxigp2_arvalid);
    mp_S_AXI_HP0_FPD_transactor->ARREADY(saxigp2_arready);
    mp_S_AXI_HP0_FPD_transactor->RID(saxigp2_rid);
    mp_S_AXI_HP0_FPD_transactor->RDATA(saxigp2_rdata);
    mp_S_AXI_HP0_FPD_transactor->RRESP(saxigp2_rresp);
    mp_S_AXI_HP0_FPD_transactor->RLAST(saxigp2_rlast);
    mp_S_AXI_HP0_FPD_transactor->RVALID(saxigp2_rvalid);
    mp_S_AXI_HP0_FPD_transactor->RREADY(saxigp2_rready);
    mp_S_AXI_HP0_FPD_transactor->AWQOS(saxigp2_awqos);
    mp_S_AXI_HP0_FPD_transactor->ARQOS(saxigp2_arqos);
    mp_S_AXI_HP0_FPD_transactor->CLK(saxihp0_fpd_aclk);
    m_S_AXI_HP0_FPD_transactor_rst_signal.write(1);
    mp_S_AXI_HP0_FPD_transactor->RST(m_S_AXI_HP0_FPD_transactor_rst_signal);

    mp_impl->S_AXI_HP0_FPD_wr_socket->bind(*(mp_S_AXI_HP0_FPD_transactor->wr_socket));
    mp_impl->S_AXI_HP0_FPD_rd_socket->bind(*(mp_S_AXI_HP0_FPD_transactor->rd_socket));
  }
  // configure 'S_AXI_HP1_FPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "S_AXI_HP1_FPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties S_AXI_HP1_FPD_transactor_param_props;
    S_AXI_HP1_FPD_transactor_param_props.addLong("DATA_WIDTH", "128");
    S_AXI_HP1_FPD_transactor_param_props.addLong("FREQ_HZ", "332986111");
    S_AXI_HP1_FPD_transactor_param_props.addLong("ID_WIDTH", "6");
    S_AXI_HP1_FPD_transactor_param_props.addLong("ADDR_WIDTH", "49");
    S_AXI_HP1_FPD_transactor_param_props.addLong("AWUSER_WIDTH", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("ARUSER_WIDTH", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_HP1_FPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_HP1_FPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "256");
    S_AXI_HP1_FPD_transactor_param_props.addLong("NUM_READ_THREADS", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "1");
    S_AXI_HP1_FPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_HP1_FPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_HP1_FPD_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_HP1_FPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "16");
    S_AXI_HP1_FPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "16");
    S_AXI_HP1_FPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    S_AXI_HP1_FPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_HP1_FPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_clk_wiz_0_0_clk_666m");
    mp_S_AXI_HP1_FPD_transactor = new xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>("S_AXI_HP1_FPD_transactor", S_AXI_HP1_FPD_transactor_param_props);
    mp_saxigp3_aruser_converter = new xsc::common::scalar2vector_converter("saxigp3_aruser_converter");
    mp_saxigp3_aruser_converter->scalar_in(saxigp3_aruser);
    mp_saxigp3_aruser_converter->vector_out(m_saxigp3_aruser_converter_signal);
    mp_S_AXI_HP1_FPD_transactor->ARUSER(m_saxigp3_aruser_converter_signal);
    mp_saxigp3_awuser_converter = new xsc::common::scalar2vector_converter("saxigp3_awuser_converter");
    mp_saxigp3_awuser_converter->scalar_in(saxigp3_awuser);
    mp_saxigp3_awuser_converter->vector_out(m_saxigp3_awuser_converter_signal);
    mp_S_AXI_HP1_FPD_transactor->AWUSER(m_saxigp3_awuser_converter_signal);
    mp_S_AXI_HP1_FPD_transactor->AWID(saxigp3_awid);
    mp_S_AXI_HP1_FPD_transactor->AWADDR(saxigp3_awaddr);
    mp_S_AXI_HP1_FPD_transactor->AWLEN(saxigp3_awlen);
    mp_S_AXI_HP1_FPD_transactor->AWSIZE(saxigp3_awsize);
    mp_S_AXI_HP1_FPD_transactor->AWBURST(saxigp3_awburst);
    mp_S_AXI_HP1_FPD_transactor->AWLOCK(saxigp3_awlock);
    mp_S_AXI_HP1_FPD_transactor->AWCACHE(saxigp3_awcache);
    mp_S_AXI_HP1_FPD_transactor->AWPROT(saxigp3_awprot);
    mp_S_AXI_HP1_FPD_transactor->AWVALID(saxigp3_awvalid);
    mp_S_AXI_HP1_FPD_transactor->AWREADY(saxigp3_awready);
    mp_S_AXI_HP1_FPD_transactor->WDATA(saxigp3_wdata);
    mp_S_AXI_HP1_FPD_transactor->WSTRB(saxigp3_wstrb);
    mp_S_AXI_HP1_FPD_transactor->WLAST(saxigp3_wlast);
    mp_S_AXI_HP1_FPD_transactor->WVALID(saxigp3_wvalid);
    mp_S_AXI_HP1_FPD_transactor->WREADY(saxigp3_wready);
    mp_S_AXI_HP1_FPD_transactor->BID(saxigp3_bid);
    mp_S_AXI_HP1_FPD_transactor->BRESP(saxigp3_bresp);
    mp_S_AXI_HP1_FPD_transactor->BVALID(saxigp3_bvalid);
    mp_S_AXI_HP1_FPD_transactor->BREADY(saxigp3_bready);
    mp_S_AXI_HP1_FPD_transactor->ARID(saxigp3_arid);
    mp_S_AXI_HP1_FPD_transactor->ARADDR(saxigp3_araddr);
    mp_S_AXI_HP1_FPD_transactor->ARLEN(saxigp3_arlen);
    mp_S_AXI_HP1_FPD_transactor->ARSIZE(saxigp3_arsize);
    mp_S_AXI_HP1_FPD_transactor->ARBURST(saxigp3_arburst);
    mp_S_AXI_HP1_FPD_transactor->ARLOCK(saxigp3_arlock);
    mp_S_AXI_HP1_FPD_transactor->ARCACHE(saxigp3_arcache);
    mp_S_AXI_HP1_FPD_transactor->ARPROT(saxigp3_arprot);
    mp_S_AXI_HP1_FPD_transactor->ARVALID(saxigp3_arvalid);
    mp_S_AXI_HP1_FPD_transactor->ARREADY(saxigp3_arready);
    mp_S_AXI_HP1_FPD_transactor->RID(saxigp3_rid);
    mp_S_AXI_HP1_FPD_transactor->RDATA(saxigp3_rdata);
    mp_S_AXI_HP1_FPD_transactor->RRESP(saxigp3_rresp);
    mp_S_AXI_HP1_FPD_transactor->RLAST(saxigp3_rlast);
    mp_S_AXI_HP1_FPD_transactor->RVALID(saxigp3_rvalid);
    mp_S_AXI_HP1_FPD_transactor->RREADY(saxigp3_rready);
    mp_S_AXI_HP1_FPD_transactor->AWQOS(saxigp3_awqos);
    mp_S_AXI_HP1_FPD_transactor->ARQOS(saxigp3_arqos);
    mp_S_AXI_HP1_FPD_transactor->CLK(saxihp1_fpd_aclk);
    m_S_AXI_HP1_FPD_transactor_rst_signal.write(1);
    mp_S_AXI_HP1_FPD_transactor->RST(m_S_AXI_HP1_FPD_transactor_rst_signal);

    mp_impl->S_AXI_HP1_FPD_wr_socket->bind(*(mp_S_AXI_HP1_FPD_transactor->wr_socket));
    mp_impl->S_AXI_HP1_FPD_rd_socket->bind(*(mp_S_AXI_HP1_FPD_transactor->rd_socket));
  }
  // configure 'S_AXI_HP2_FPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "S_AXI_HP2_FPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties S_AXI_HP2_FPD_transactor_param_props;
    S_AXI_HP2_FPD_transactor_param_props.addLong("DATA_WIDTH", "128");
    S_AXI_HP2_FPD_transactor_param_props.addLong("FREQ_HZ", "332986111");
    S_AXI_HP2_FPD_transactor_param_props.addLong("ID_WIDTH", "6");
    S_AXI_HP2_FPD_transactor_param_props.addLong("ADDR_WIDTH", "49");
    S_AXI_HP2_FPD_transactor_param_props.addLong("AWUSER_WIDTH", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("ARUSER_WIDTH", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_HP2_FPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_HP2_FPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "256");
    S_AXI_HP2_FPD_transactor_param_props.addLong("NUM_READ_THREADS", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "1");
    S_AXI_HP2_FPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_HP2_FPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_HP2_FPD_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_HP2_FPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "16");
    S_AXI_HP2_FPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "16");
    S_AXI_HP2_FPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    S_AXI_HP2_FPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_HP2_FPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_clk_wiz_0_0_clk_666m");
    mp_S_AXI_HP2_FPD_transactor = new xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>("S_AXI_HP2_FPD_transactor", S_AXI_HP2_FPD_transactor_param_props);
    mp_saxigp4_aruser_converter = new xsc::common::scalar2vector_converter("saxigp4_aruser_converter");
    mp_saxigp4_aruser_converter->scalar_in(saxigp4_aruser);
    mp_saxigp4_aruser_converter->vector_out(m_saxigp4_aruser_converter_signal);
    mp_S_AXI_HP2_FPD_transactor->ARUSER(m_saxigp4_aruser_converter_signal);
    mp_saxigp4_awuser_converter = new xsc::common::scalar2vector_converter("saxigp4_awuser_converter");
    mp_saxigp4_awuser_converter->scalar_in(saxigp4_awuser);
    mp_saxigp4_awuser_converter->vector_out(m_saxigp4_awuser_converter_signal);
    mp_S_AXI_HP2_FPD_transactor->AWUSER(m_saxigp4_awuser_converter_signal);
    mp_S_AXI_HP2_FPD_transactor->AWID(saxigp4_awid);
    mp_S_AXI_HP2_FPD_transactor->AWADDR(saxigp4_awaddr);
    mp_S_AXI_HP2_FPD_transactor->AWLEN(saxigp4_awlen);
    mp_S_AXI_HP2_FPD_transactor->AWSIZE(saxigp4_awsize);
    mp_S_AXI_HP2_FPD_transactor->AWBURST(saxigp4_awburst);
    mp_S_AXI_HP2_FPD_transactor->AWLOCK(saxigp4_awlock);
    mp_S_AXI_HP2_FPD_transactor->AWCACHE(saxigp4_awcache);
    mp_S_AXI_HP2_FPD_transactor->AWPROT(saxigp4_awprot);
    mp_S_AXI_HP2_FPD_transactor->AWVALID(saxigp4_awvalid);
    mp_S_AXI_HP2_FPD_transactor->AWREADY(saxigp4_awready);
    mp_S_AXI_HP2_FPD_transactor->WDATA(saxigp4_wdata);
    mp_S_AXI_HP2_FPD_transactor->WSTRB(saxigp4_wstrb);
    mp_S_AXI_HP2_FPD_transactor->WLAST(saxigp4_wlast);
    mp_S_AXI_HP2_FPD_transactor->WVALID(saxigp4_wvalid);
    mp_S_AXI_HP2_FPD_transactor->WREADY(saxigp4_wready);
    mp_S_AXI_HP2_FPD_transactor->BID(saxigp4_bid);
    mp_S_AXI_HP2_FPD_transactor->BRESP(saxigp4_bresp);
    mp_S_AXI_HP2_FPD_transactor->BVALID(saxigp4_bvalid);
    mp_S_AXI_HP2_FPD_transactor->BREADY(saxigp4_bready);
    mp_S_AXI_HP2_FPD_transactor->ARID(saxigp4_arid);
    mp_S_AXI_HP2_FPD_transactor->ARADDR(saxigp4_araddr);
    mp_S_AXI_HP2_FPD_transactor->ARLEN(saxigp4_arlen);
    mp_S_AXI_HP2_FPD_transactor->ARSIZE(saxigp4_arsize);
    mp_S_AXI_HP2_FPD_transactor->ARBURST(saxigp4_arburst);
    mp_S_AXI_HP2_FPD_transactor->ARLOCK(saxigp4_arlock);
    mp_S_AXI_HP2_FPD_transactor->ARCACHE(saxigp4_arcache);
    mp_S_AXI_HP2_FPD_transactor->ARPROT(saxigp4_arprot);
    mp_S_AXI_HP2_FPD_transactor->ARVALID(saxigp4_arvalid);
    mp_S_AXI_HP2_FPD_transactor->ARREADY(saxigp4_arready);
    mp_S_AXI_HP2_FPD_transactor->RID(saxigp4_rid);
    mp_S_AXI_HP2_FPD_transactor->RDATA(saxigp4_rdata);
    mp_S_AXI_HP2_FPD_transactor->RRESP(saxigp4_rresp);
    mp_S_AXI_HP2_FPD_transactor->RLAST(saxigp4_rlast);
    mp_S_AXI_HP2_FPD_transactor->RVALID(saxigp4_rvalid);
    mp_S_AXI_HP2_FPD_transactor->RREADY(saxigp4_rready);
    mp_S_AXI_HP2_FPD_transactor->AWQOS(saxigp4_awqos);
    mp_S_AXI_HP2_FPD_transactor->ARQOS(saxigp4_arqos);
    mp_S_AXI_HP2_FPD_transactor->CLK(saxihp2_fpd_aclk);
    m_S_AXI_HP2_FPD_transactor_rst_signal.write(1);
    mp_S_AXI_HP2_FPD_transactor->RST(m_S_AXI_HP2_FPD_transactor_rst_signal);

    mp_impl->S_AXI_HP2_FPD_wr_socket->bind(*(mp_S_AXI_HP2_FPD_transactor->wr_socket));
    mp_impl->S_AXI_HP2_FPD_rd_socket->bind(*(mp_S_AXI_HP2_FPD_transactor->rd_socket));
  }
  // configure 'S_AXI_LPD' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_zynq_ultra_ps_e_0_0", "S_AXI_LPD_TLM_MODE") != 1)
  {
    xsc::common_cpp::properties S_AXI_LPD_transactor_param_props;
    S_AXI_LPD_transactor_param_props.addLong("DATA_WIDTH", "128");
    S_AXI_LPD_transactor_param_props.addLong("FREQ_HZ", "102457264");
    S_AXI_LPD_transactor_param_props.addLong("ID_WIDTH", "6");
    S_AXI_LPD_transactor_param_props.addLong("ADDR_WIDTH", "49");
    S_AXI_LPD_transactor_param_props.addLong("AWUSER_WIDTH", "1");
    S_AXI_LPD_transactor_param_props.addLong("ARUSER_WIDTH", "1");
    S_AXI_LPD_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_LPD_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_LPD_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_LPD_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_LPD_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_LPD_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_LPD_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "1");
    S_AXI_LPD_transactor_param_props.addLong("MAX_BURST_LENGTH", "256");
    S_AXI_LPD_transactor_param_props.addLong("NUM_READ_THREADS", "1");
    S_AXI_LPD_transactor_param_props.addLong("NUM_WRITE_THREADS", "1");
    S_AXI_LPD_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_LPD_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_LPD_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_LPD_transactor_param_props.addString("NUM_WRITE_OUTSTANDING", "16");
    S_AXI_LPD_transactor_param_props.addString("NUM_READ_OUTSTANDING", "16");
    S_AXI_LPD_transactor_param_props.addString("PROTOCOL", "AXI4");
    S_AXI_LPD_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_LPD_transactor_param_props.addString("CLK_DOMAIN", "design_1_clk_wiz_0_0_clk_666m");
    mp_S_AXI_LPD_transactor = new xtlm::xaximm_pin2xtlm_t<128,49,6,1,1,1,1,1>("S_AXI_LPD_transactor", S_AXI_LPD_transactor_param_props);
    mp_saxigp6_aruser_converter = new xsc::common::scalar2vector_converter("saxigp6_aruser_converter");
    mp_saxigp6_aruser_converter->scalar_in(saxigp6_aruser);
    mp_saxigp6_aruser_converter->vector_out(m_saxigp6_aruser_converter_signal);
    mp_S_AXI_LPD_transactor->ARUSER(m_saxigp6_aruser_converter_signal);
    mp_saxigp6_awuser_converter = new xsc::common::scalar2vector_converter("saxigp6_awuser_converter");
    mp_saxigp6_awuser_converter->scalar_in(saxigp6_awuser);
    mp_saxigp6_awuser_converter->vector_out(m_saxigp6_awuser_converter_signal);
    mp_S_AXI_LPD_transactor->AWUSER(m_saxigp6_awuser_converter_signal);
    mp_S_AXI_LPD_transactor->AWID(saxigp6_awid);
    mp_S_AXI_LPD_transactor->AWADDR(saxigp6_awaddr);
    mp_S_AXI_LPD_transactor->AWLEN(saxigp6_awlen);
    mp_S_AXI_LPD_transactor->AWSIZE(saxigp6_awsize);
    mp_S_AXI_LPD_transactor->AWBURST(saxigp6_awburst);
    mp_S_AXI_LPD_transactor->AWLOCK(saxigp6_awlock);
    mp_S_AXI_LPD_transactor->AWCACHE(saxigp6_awcache);
    mp_S_AXI_LPD_transactor->AWPROT(saxigp6_awprot);
    mp_S_AXI_LPD_transactor->AWVALID(saxigp6_awvalid);
    mp_S_AXI_LPD_transactor->AWREADY(saxigp6_awready);
    mp_S_AXI_LPD_transactor->WDATA(saxigp6_wdata);
    mp_S_AXI_LPD_transactor->WSTRB(saxigp6_wstrb);
    mp_S_AXI_LPD_transactor->WLAST(saxigp6_wlast);
    mp_S_AXI_LPD_transactor->WVALID(saxigp6_wvalid);
    mp_S_AXI_LPD_transactor->WREADY(saxigp6_wready);
    mp_S_AXI_LPD_transactor->BID(saxigp6_bid);
    mp_S_AXI_LPD_transactor->BRESP(saxigp6_bresp);
    mp_S_AXI_LPD_transactor->BVALID(saxigp6_bvalid);
    mp_S_AXI_LPD_transactor->BREADY(saxigp6_bready);
    mp_S_AXI_LPD_transactor->ARID(saxigp6_arid);
    mp_S_AXI_LPD_transactor->ARADDR(saxigp6_araddr);
    mp_S_AXI_LPD_transactor->ARLEN(saxigp6_arlen);
    mp_S_AXI_LPD_transactor->ARSIZE(saxigp6_arsize);
    mp_S_AXI_LPD_transactor->ARBURST(saxigp6_arburst);
    mp_S_AXI_LPD_transactor->ARLOCK(saxigp6_arlock);
    mp_S_AXI_LPD_transactor->ARCACHE(saxigp6_arcache);
    mp_S_AXI_LPD_transactor->ARPROT(saxigp6_arprot);
    mp_S_AXI_LPD_transactor->ARVALID(saxigp6_arvalid);
    mp_S_AXI_LPD_transactor->ARREADY(saxigp6_arready);
    mp_S_AXI_LPD_transactor->RID(saxigp6_rid);
    mp_S_AXI_LPD_transactor->RDATA(saxigp6_rdata);
    mp_S_AXI_LPD_transactor->RRESP(saxigp6_rresp);
    mp_S_AXI_LPD_transactor->RLAST(saxigp6_rlast);
    mp_S_AXI_LPD_transactor->RVALID(saxigp6_rvalid);
    mp_S_AXI_LPD_transactor->RREADY(saxigp6_rready);
    mp_S_AXI_LPD_transactor->AWQOS(saxigp6_awqos);
    mp_S_AXI_LPD_transactor->ARQOS(saxigp6_arqos);
    mp_S_AXI_LPD_transactor->CLK(saxi_lpd_aclk);
    m_S_AXI_LPD_transactor_rst_signal.write(1);
    mp_S_AXI_LPD_transactor->RST(m_S_AXI_LPD_transactor_rst_signal);

    mp_impl->S_AXI_LPD_wr_socket->bind(*(mp_S_AXI_LPD_transactor->wr_socket));
    mp_impl->S_AXI_LPD_rd_socket->bind(*(mp_S_AXI_LPD_transactor->rd_socket));
  }
}

design_1_zynq_ultra_ps_e_0_0::~design_1_zynq_ultra_ps_e_0_0()
{
  xsc::utils::xsc_sim_manager::clean();

  delete mp_impl;
  delete mp_M_AXI_HPM0_FPD_transactor;
  delete mp_M_AXI_HPM1_FPD_transactor;
  delete mp_M_AXI_HPM0_LPD_transactor;
  delete mp_S_AXI_HP0_FPD_transactor;
  delete mp_saxigp2_aruser_converter;
  delete mp_saxigp2_awuser_converter;
  delete mp_S_AXI_HP1_FPD_transactor;
  delete mp_saxigp3_aruser_converter;
  delete mp_saxigp3_awuser_converter;
  delete mp_S_AXI_HP2_FPD_transactor;
  delete mp_saxigp4_aruser_converter;
  delete mp_saxigp4_awuser_converter;
  delete mp_S_AXI_LPD_transactor;
  delete mp_saxigp6_aruser_converter;
  delete mp_saxigp6_awuser_converter;
}

#ifdef MTI_SYSTEMC
SC_MODULE_EXPORT(design_1_zynq_ultra_ps_e_0_0);
#endif
