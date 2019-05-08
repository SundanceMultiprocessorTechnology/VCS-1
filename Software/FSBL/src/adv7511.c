
#include "adv7511.h"
#include "xil_printf.h"
#include "sleep.h"

XIicPs Iic;

int adv7511_write(XIicPs *InstancePtr, char Addr, char Data)
{
	int Status;
	u8 SendBuffer[2];

	SendBuffer[0] = Addr;
	SendBuffer[1] = Data;
	Status = XIicPs_MasterSendPolled(InstancePtr, SendBuffer, 2, ADV7511_ADDR);
	while (XIicPs_BusIsBusy(InstancePtr));

	return Status;
}



char adv7511_read(XIicPs *InstancePtr, char Addr)
{
	u8 wr_data, rd_data=0;

	wr_data = Addr;
	InstancePtr->IsRepeatedStart = 0x01;  // Set flag to not issue Stop condition
	XIicPs_MasterSendPolled(InstancePtr, &wr_data, 1, ADV7511_ADDR);
	InstancePtr->IsRepeatedStart = 0x00; // Clear the flag to end the I2C xaction after this read
	XIicPs_MasterRecvPolled(InstancePtr, &rd_data, 1, ADV7511_ADDR);
	while (XIicPs_BusIsBusy(InstancePtr));
	return rd_data;
}

int adv7511_init(short DeviceID, char Bus, char ChipAddr)
{
	XIicPs_Config *Config;
	u8 test_addr, test_data;
	int Status;


	Config = XIicPs_LookupConfig(DeviceID);
	if (NULL == Config) {
		xil_printf("XIicPs_LookupConfig failure\r\n");
		return XST_FAILURE;
	}

	Status = XIicPs_CfgInitialize(&Iic, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		xil_printf("XIicPs_CfgInitialize failure\r\n");
		return XST_FAILURE;
	}
	XIicPs_SetSClk(&Iic, IIC_SCLK_RATE);


	// ADV7511

	test_addr = 0;		// Address of test register
	Status = XIicPs_MasterSendPolled(&Iic, &test_addr, 1, ChipAddr);
	if (Status != XST_SUCCESS) {
		xil_printf("ADV7511 XIicPs_MasterSendPolled failure\r\n");
		return XST_FAILURE;
	}
	Status = XIicPs_MasterRecvPolled(&Iic, &test_data, 1, ChipAddr);
	if (Status != XST_SUCCESS) {
		xil_printf("ADV7511 XIicPs_MasterRecvPolled failure\r\n");
		return XST_FAILURE;
	}
	while (XIicPs_BusIsBusy(&Iic));	// Wait
	xil_printf("\r\nADV7511 Initialization\t\t");

	// Initialize...

	adv7511_write(&Iic,  0x15, 0x05); // ID 5
	// xxxx_xx1x first on rising
	// xxxx_01xx style 01 => 2, 10 => 1, 11 => 3
	// xx11_xxxx color depth 8
	adv7511_write(&Iic,  0x16, 0x38); // 8, style 1, falling

	adv7511_write(&Iic,  0x48, 0x08); // align right, right justified, DDR low bits, normal bus order


	adv7511_write(&Iic,  0x55, 0x12); // AVI AVI valid, RGB, PC
	adv7511_write(&Iic,  0x56, 0x28); //

	adv7511_write(&Iic,  0x17, 0x00); // DE gen disabled, aspec 4:3

	adv7511_write(&Iic,  0xBA, 0x60); // - 0.8ns
	adv7511_write(&Iic,  0xD0, 0x8C); // inv clk ?


	adv7511_write(&Iic,  0xAF, 0x04); // no HDCP

	// Conversion matrix IN=OUT
	adv7511_write(&Iic,  0x18, 0xA8);
	adv7511_write(&Iic,  0x19, 0x00);
	adv7511_write(&Iic,  0x1A, 0x00);
	adv7511_write(&Iic,  0x1B, 0x00);
	adv7511_write(&Iic,  0x1C, 0x00);
	adv7511_write(&Iic,  0x1D, 0x00);
	adv7511_write(&Iic,  0x1E, 0x00);
	adv7511_write(&Iic,  0x1F, 0x00);
	adv7511_write(&Iic,  0x20, 0x00);
	adv7511_write(&Iic,  0x21, 0x00);
	adv7511_write(&Iic,  0x22, 0x08);
	adv7511_write(&Iic,  0x23, 0x00);
	adv7511_write(&Iic,  0x24, 0x00);
	adv7511_write(&Iic,  0x25, 0x00);
	adv7511_write(&Iic,  0x26, 0x00);
	adv7511_write(&Iic,  0x27, 0x00);
	adv7511_write(&Iic,  0x28, 0x00);
	adv7511_write(&Iic,  0x29, 0x00);
	adv7511_write(&Iic,  0x2A, 0x00);
	adv7511_write(&Iic,  0x2B, 0x00);
	adv7511_write(&Iic,  0x2C, 0x08);
	adv7511_write(&Iic,  0x2D, 0x00);
	adv7511_write(&Iic,  0x2E, 0x00);
	adv7511_write(&Iic,  0x2F, 0x00);
    // ------------------------

	adv7511_write(&Iic,  0x41, 0x10);

	adv7511_write(&Iic,  0x98, 0x03); // FIXED 0x03
	adv7511_write(&Iic,  0x9A, 0xE0); // FIXED 0xE0
	adv7511_write(&Iic,  0x9C, 0x30); // FIXED 0x30 PLL
	adv7511_write(&Iic,  0x9D, 0x61); // xxxx_xx01 CLK Div
	adv7511_write(&Iic,  0xA2, 0xA4); // FIXED
	adv7511_write(&Iic,  0xA3, 0xA4); // FIXED

	adv7511_write(&Iic,  0xE0, 0xD0); // FIXED
	adv7511_write(&Iic,  0xF9, 0x00);

	adv7511_write(&Iic,  0xFF, 0xFF);
	/*{
		char c = adv7511_read(&Iic, 0x97);printf("0x97 0x%x\n", c);
		c = adv7511_read(&Iic, 0xc8);printf("0xc8 0x%x\n", c);
		c = adv7511_read(&Iic, 0x9e);printf("0x9e 0x%x\n", c);
	}*/


	xil_printf("Done\r\n");
	return XST_SUCCESS;
}


/*void adv7511_read_test()
{

	char c = adv7511_read(&Iic, 0x97);printf("0x97 0x%x\n", c);
	c = adv7511_read(&Iic, 0xc8);printf("0xc8 0x%x\n", c);
	c = adv7511_read(&Iic, 0x9e);printf("0x9e 0x%x\n", c);

}*/

