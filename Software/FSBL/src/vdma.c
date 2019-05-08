/*
 */

#include "xil_printf.h"
//#include "sleep.h"


#include "vdma.h"

XAxiVdma Vdma;

XAxiVdma_DmaSetup ReadCfg;

u32 vdma_version() {
	return XAxiVdma_GetVersion(&Vdma);
}

int vdma_start() {
	   int Status;

	   // MM2S Startup
	   Status = XAxiVdma_DmaStart(&Vdma, XAXIVDMA_READ);
	   if (Status != XST_SUCCESS)
	   {
	      xil_printf("Start read transfer failed %d\n\r", Status);
	      return XST_FAILURE;
	   }

	   return XST_SUCCESS;
}


int vdma_stop() {
	   XAxiVdma_DmaStop(&Vdma, XAXIVDMA_READ);
	   return XST_SUCCESS;
}


int vdma_init(short DeviceID)
{
	XAxiVdma_Config *Config;
	
	int Status;

	Config = XAxiVdma_LookupConfig(DeviceID);
	if (NULL == Config) {
		xil_printf("XAxiVdma_LookupConfig failure\r\n");
		return XST_FAILURE;
	}

	Status = XAxiVdma_CfgInitialize(&Vdma, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		xil_printf("XAxiVdma_CfgInitialize failure\r\n");
		return XST_FAILURE;
	}

	ReadCfg.EnableCircularBuf = 1;

	ReadCfg.EnableFrameCounter = 0;
	ReadCfg.FixedFrameStoreAddr = 0;

	ReadCfg.EnableSync = 1;
	ReadCfg.PointNum = 1;

	ReadCfg.FrameDelay = 0;

	ReadCfg.VertSizeInput = 720;
	ReadCfg.HoriSizeInput = 1280 << 2;
	ReadCfg.Stride = ReadCfg.HoriSizeInput;

	Status = XAxiVdma_DmaConfig(&Vdma, XAXIVDMA_READ, &ReadCfg);
	if (Status != XST_SUCCESS) {
			xdbg_printf(XDBG_DEBUG_ERROR,
				"Read channel config failed %d\r\n", Status);

			return XST_FAILURE;
	}

	ReadCfg.FrameStoreStartAddr[0] = 0x7FC00000;

	Status = XAxiVdma_DmaSetBufferAddr(&Vdma, XAXIVDMA_READ, ReadCfg.FrameStoreStartAddr);
	if (Status != XST_SUCCESS) {
			xdbg_printf(XDBG_DEBUG_ERROR,"Read channel set buffer address failed %d\r\n", Status);
			return XST_FAILURE;
	}

	Status = vdma_start();
	if (Status != XST_SUCCESS) {
		   xil_printf("error starting VDMA..!");
		   return Status;
	}

	//XAxiVdma_DmaRegisterDump(&Vdma, XAXIVDMA_READ);

	return XST_SUCCESS;

}

