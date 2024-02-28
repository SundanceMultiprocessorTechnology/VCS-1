/*
 */

#include "xil_printf.h"
//#include "sleep.h"

#include "tpg.h"

XV_tpg Tpg;

int tpg_init(short DeviceID)
{
	XV_tpg_Config *Config;
	int Status;



	Config = XV_tpg_LookupConfig(DeviceID);
	if (NULL == Config) {
		xil_printf("XIpg_LookupConfig failure\r\n");
		return XST_FAILURE;
	}


	Status = XV_tpg_CfgInitialize(&Tpg, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		xil_printf("XTpg_CfgInitialize failure\r\n");
		return XST_FAILURE;
	}

	// bypass
	XV_tpg_Set_height(&Tpg, 720);
	XV_tpg_Set_width(&Tpg, 1280);
	XV_tpg_Set_colorFormat(&Tpg, 0);
	XV_tpg_Set_bckgndId(&Tpg, XTPG_BKGND_COLOR_BARS);
	XV_tpg_Set_ovrlayId(&Tpg, 0);
	XV_tpg_Set_enableInput(&Tpg, 1);
	XV_tpg_Set_passthruStartX(&Tpg, 0);
	XV_tpg_Set_passthruStartY(&Tpg, 0);
	XV_tpg_Set_passthruEndX(&Tpg, 1280);
	XV_tpg_Set_passthruEndY(&Tpg, 720);
	XV_tpg_WriteReg(Config->BaseAddress, XV_TPG_CTRL_ADDR_AP_CTRL, 0x81);

	return XST_SUCCESS;
}



