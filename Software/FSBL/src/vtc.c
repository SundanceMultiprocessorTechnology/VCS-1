/*
 */

#include "xil_printf.h"
//#include "sleep.h"

#include "vtc.h"

XVtc Vtc;

int vtc_init(short DeviceID)
{
	XVtc_Config *Config;
	int Status;


	Config = XVtc_LookupConfig(DeviceID);
	if (NULL == Config) {
		xil_printf("XVtc_LookupConfig failure\r\n");
		return XST_FAILURE;
	}

	Status = XVtc_CfgInitialize(&Vtc, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		xil_printf("XVtc_CfgInitialize failure\r\n");
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

/*void XVtc_dump()
{
	int rd = 0;
	printf("ADDR 0x%x\n", Vtc.Config.BaseAddress);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_CTL				); printf("XVTC_CTL				 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_ISR	      ); printf("XVTC_ISR	       0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_ERROR	    ); printf("XVTC_ERROR	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_IER	      ); printf("XVTC_IER	       0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_VER	      ); printf("XVTC_VER	       0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DASIZE	    ); printf("XVTC_DASIZE	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DTSTAT	    ); printf("XVTC_DTSTAT	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DFENC	    ); printf("XVTC_DFENC	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DPOL	      ); printf("XVTC_DPOL	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DHSIZE	    ); printf("XVTC_DHSIZE	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVSIZE	    ); printf("XVTC_DVSIZE	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DHSYNC	    ); printf("XVTC_DHSYNC	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVBHOFF	  ); printf("XVTC_DVBHOFF	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVSYNC	    ); printf("XVTC_DVSYNC	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVSHOFF	  ); printf("XVTC_DVSHOFF	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVBHOFF_F1	); printf("XVTC_DVBHOFF_F1 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVSYNC_F1	); printf("XVTC_DVSYNC_F1	 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_DVSHOFF_F1	); printf("XVTC_DVSHOFF_F1 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GASIZE	    ); printf("XVTC_GASIZE	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GTSTAT	    ); printf("XVTC_GTSTAT	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GFENC	    ); printf("XVTC_GFENC	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GPOL	      ); printf("XVTC_GPOL	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GHSIZE	    ); printf("XVTC_GHSIZE	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVSIZE	    ); printf("XVTC_GVSIZE	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GHSYNC	    ); printf("XVTC_GHSYNC	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVBHOFF	  ); printf("XVTC_GVBHOFF	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVSYNC	    ); printf("XVTC_GVSYNC	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVSHOFF	  ); printf("XVTC_GVSHOFF	   0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVBHOFF_F1	); printf("XVTC_GVBHOFF_F1 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVSYNC_F1	); printf("XVTC_GVSYNC_F1	 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GVSHOFF_F1	); printf("XVTC_GVSHOFF_F1 0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS00	      ); printf("XVTC_FS00	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS01	      ); printf("XVTC_FS01	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS02	      ); printf("XVTC_FS02	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS03	      ); printf("XVTC_FS03	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS04	      ); printf("XVTC_FS04	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS05	      ); printf("XVTC_FS05	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS06	      ); printf("XVTC_FS06	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS07	      ); printf("XVTC_FS07	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS08	      ); printf("XVTC_FS08	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS09	      ); printf("XVTC_FS09	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS10	      ); printf("XVTC_FS10	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS11	      ); printf("XVTC_FS11	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS12	      ); printf("XVTC_FS12	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS13	      ); printf("XVTC_FS13	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS14	      ); printf("XVTC_FS14	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_FS15	      ); printf("XVTC_FS15	     0x%x\n", rd);
	rd = XVtc_ReadReg(Vtc.Config.BaseAddress, XVTC_GGD	      ); printf("XVTC_GGD	       0x%x\n", rd);
}*/


