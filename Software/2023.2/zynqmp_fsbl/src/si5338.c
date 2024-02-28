/*
-- Company: 		Trenz Electronic
-- Engineer: 		Oleksandr Kiyenko
-- Modified Engineer: 		John Hartfiel
 */
#include "si5338.h"
#include "xiicps.h"
#include "xil_printf.h"
#define code
#include "register_map_mod.h"
XIicPs IicPs;		/**< Instance of the IIC Device */

int i2c_init(void){
  XIicPs_Config *I2cCfgPtr;
	int Status = I2C_SUCCESS;

	xil_printf("SI5338 Init Function\r\n");
   	I2cCfgPtr = XIicPs_LookupConfig(XPAR_XIICPS_0_DEVICE_ID);

    if (I2cCfgPtr == NULL){
    xil_printf("XIicPs_LookupConfig failure\r\n");
		return I2C_INIT_ERR;
	}
	
    Status = XIicPs_CfgInitialize(&IicPs, I2cCfgPtr, I2cCfgPtr->BaseAddress);
    if (Status != I2C_SUCCESS) {
      xil_printf("XIicPs_CfgInitialize failure\r\n");
      return Status;
    }
	
    XIicPs_SetSClk(&IicPs, IIC_SCLK_RATE);


	return Status;
}


int i2c_write(unsigned char chip_addr, char Addr, char Data)
{
	int Status;
	u8 SendBuffer[2];

	SendBuffer[0] = Addr;
	SendBuffer[1] = Data;
	Status = XIicPs_MasterSendPolled(&IicPs, SendBuffer, 2, chip_addr);
	while (XIicPs_BusIsBusy(&IicPs));

	return Status;
}

int si5338_write(XIicPs *InstancePtr, char Addr, char Data)
{
	int Status;
	u8 SendBuffer[2];

	SendBuffer[0] = Addr;
	SendBuffer[1] = Data;
	Status = XIicPs_MasterSendPolled(InstancePtr,SendBuffer, 2, IIC_ADDR);
	while (XIicPs_BusIsBusy(InstancePtr));

	return Status;
}

char si5338_read(XIicPs *InstancePtr, char Addr)
{
	u8 wr_data, rd_data;

	wr_data = Addr;
	XIicPs_MasterSendPolled(InstancePtr, &wr_data, 1, IIC_ADDR);
	XIicPs_MasterRecvPolled(InstancePtr, &rd_data, 1, IIC_ADDR);
	while (XIicPs_BusIsBusy(InstancePtr));
	return rd_data;
}

int si5338_write_mask(XIicPs *InstancePtr, char Addr, char Data, char Mask)
{
	u8 reg_val;

	if(Mask == 0xFF){	// All bits
		si5338_write(InstancePtr, Addr, Data);
	}
	else{						// Write by mask
		reg_val = si5338_read(InstancePtr, Addr);
		reg_val &= ~Mask;	// Clear bits to write
		reg_val |= Data & Mask;	// Set bits by mask
		si5338_write(InstancePtr, Addr, reg_val);
	}
	return XST_SUCCESS;
}

int si5338_delay(int delay_ms)
{
	volatile int i;
	for(i=0;i<(delay_ms*1000000);i++);
	return XST_SUCCESS;
}

int si5338_init()
{
	int Status, i;
	Reg_Data rd;
	u8 reg_val, test_addr, test_data;
	// Check chip by reading Revision reg 0x00
	test_addr = 0x00;		// Address of test register
	Status = XIicPs_MasterSendPolled(&IicPs, &test_addr, 1, IIC_ADDR);
	if (Status != XST_SUCCESS) {
		xil_printf("Si5338 XIicPs_MasterSendPolled failure\r\n");
		return XST_FAILURE;
	}
	Status = XIicPs_MasterRecvPolled(&IicPs, &test_data, 1, IIC_ADDR);
	if (Status != XST_SUCCESS) {
		xil_printf("Si5338 XIicPs_MasterRecvPolled failure\r\n");
		return XST_FAILURE;
	}
	while (XIicPs_BusIsBusy(&IicPs));	// Wait
	xil_printf("Si5338 Rev %d Initialization\t\t",test_data);

	// I2C Programming Procedure
	si5338_write(&IicPs, 246, 0x01);					//Hard reset
	// Disable Outputs
	si5338_write_mask(&IicPs, 230, EOB_ALL, EOB_ALL);	// EOB_ALL = 1
	// Pause LOL
	si5338_write_mask(&IicPs, 241, DIS_LOL, DIS_LOL);	// DIS_LOL = 1
	// Write new configuration to device accounting for the write-allowed mask
	for(i=0; i<NUM_REGS_MAX; i++){
		rd = Reg_Store[i];
		si5338_write_mask(&IicPs, rd.Reg_Addr, rd.Reg_Val, rd.Reg_Mask);
	}
	// Validate clock input status
	reg_val = si5338_read(&IicPs, 218) & LOS_MASK;
	while(reg_val != 0){
		reg_val = si5338_read(&IicPs, 218) & LOS_MASK;
	}
	// Configure PLL for locking
	si5338_write_mask(&IicPs, 49, 0, FCAL_OVRD_EN);	//FCAL_OVRD_EN = 0
	// Initiate Locking of PLL
	si5338_write(&IicPs, 246, SOFT_RESET);			//SOFT_RESET = 1
	si5338_delay(25);								// Wait 25 ms
	// Restart LOL
	si5338_write_mask(&IicPs, 241, 0, DIS_LOL);		// DIS_LOL = 0
	si5338_write(&IicPs, 241, 0x65);					// Set reg 241 = 0x65
	// Confirm PLL lock status
	reg_val = si5338_read(&IicPs, 218) & LOCK_MASK;
	while(reg_val != 0){
		reg_val = si5338_read(&IicPs, 218) & LOCK_MASK;
	}
	//copy FCAL values to active registers
	si5338_write_mask(&IicPs, 47, si5338_read(&IicPs, 237), 0x03);	// 237[1:0] to 47[1:0]
	si5338_write(&IicPs, 46, si5338_read(&IicPs, 236));	// 236[7:0] to 46[7:0]
	si5338_write(&IicPs, 45, si5338_read(&IicPs, 235));	// 235[7:0] to 45[7:0]
	si5338_write_mask(&IicPs, 47, 0x14, 0xFC);		// Set 47[7:2] = 000101b
	// Set PLL to use FCAL values
	si5338_write_mask(&IicPs, 49, FCAL_OVRD_EN, FCAL_OVRD_EN);	//FCAL_OVRD_EN = 1
	// Enable Outputs
	si5338_write(&IicPs, 230, 0x00);					//EOB_ALL = 0
	xil_printf("Done\r\n");
	return XST_SUCCESS;
}

