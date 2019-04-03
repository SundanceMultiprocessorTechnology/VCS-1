//////////////////////////////////////////////////////////////
// Company: Sundance Multiprocessor Technology LTD
// Engineer: Timoteo Garcia Bertoa
//
// Design Name: EMC2-DP + FM191-RU (RPI)
// Module Name: Test
// Project Name: Standalone_test
// Target Devices: xczu4ev-sfvc784-1-e
// Tool Versions: Xilinx SDK 18.3
//
// Additional Comments: Test for LEDs, DIOs, GPIOs onboard, ADCs, DAC, EEPROM
//
//////////////////////////////////////////////////////////////

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include "xspips.h"
#include "xuartlite.h"
#include "eeprom.h"
#include <math.h>

#define LED_CHANNEL 1
#define LEDs_DEVICE_ID	XPAR_M_LEDS_DEVICE_ID
#define DIOs_DEVICE_ID	XPAR_IOS_DEVICE_ID
#define GPIOs_DEVICE_ID	XPAR_IOS_DEVICE_ID
#define SPI_DEVICE_ID 	XPAR_PSU_SPI_0_DEVICE_ID
#define ADC0_DEVICE_ID	XPAR_UARTLITE_0_DEVICE_ID
#define ADC1_DEVICE_ID	XPAR_UARTLITE_1_DEVICE_ID
#define ADC2_DEVICE_ID	XPAR_UARTLITE_2_DEVICE_ID
#define DAC_SPI_SELECT	0x00
#define MAX 4294967295

XSpiPs_Config *SpiConfig;
static XSpiPs SpiInstance;

XUartLite UartLite;
u8 SendBuffer[3];
u8 RecvBuffer[3];

XGpio GpioOutput;
XGpio GpioInput;

int ledsmask, diosmask, gpiosmask;

int clean_stdin()
{
    while (getchar()!='\r');
    return 1;
}

int writeleds(int num, int state)
{
	int Status;

	Status = XGpio_Initialize(&GpioOutput, LEDs_DEVICE_ID);
	if (Status != XST_SUCCESS)  {
		return XST_FAILURE;
	}

	if(state == 1){
		ledsmask = ledsmask + (int)(pow(2,num-2));
		XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
		XGpio_DiscreteWrite(&GpioOutput, 1, ledsmask);
	} else {
		ledsmask = ledsmask & (MAX - (int)(pow(2,num-2)));
		XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
		XGpio_DiscreteWrite(&GpioOutput, 1, ledsmask);
	}
	return XST_SUCCESS;
}

int writedios(int num, int state)
{
	int Status;

	Status = XGpio_Initialize(&GpioOutput, DIOs_DEVICE_ID);
	if (Status != XST_SUCCESS)  {
		return XST_FAILURE;
	}
	if(state == 1){
		diosmask = diosmask + (int)(pow(2,num));
		XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
		XGpio_DiscreteWrite(&GpioOutput, 1, diosmask);
	} else {
		diosmask = diosmask & (MAX - (int)(pow(2,num)));
		XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
		XGpio_DiscreteWrite(&GpioOutput, 1, diosmask);
	}
	return XST_SUCCESS;
}
int writegpios(int num, int state)
{
	int Status;

	Status = XGpio_Initialize(&GpioOutput, GPIOs_DEVICE_ID);
	if (Status != XST_SUCCESS)  {
		return XST_FAILURE;
	}
	if(state == 1){
		gpiosmask = gpiosmask + (int)(pow(2,num));
		XGpio_SetDataDirection(&GpioOutput, 2, 0x0);
		XGpio_DiscreteWrite(&GpioOutput, 2, gpiosmask);
	} else {
		gpiosmask = gpiosmask & (MAX - (int)(pow(2,num)));
		XGpio_SetDataDirection(&GpioOutput, 2, 0x0);
		XGpio_DiscreteWrite(&GpioOutput, 2, gpiosmask);
	}
	return XST_SUCCESS;
}

int readdios(int num)
{
	int Status, result;

	Status = XGpio_Initialize(&GpioInput, DIOs_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XGpio_SetDataDirection(&GpioInput, 1, 0xFFFFFFFF);
	result = 0;
	result = XGpio_DiscreteRead(&GpioInput, 1);
	result = result & (int)(pow(2,(num)));
	if(result == (int)(pow(2,(num)))){
		result = 1;
	} else {
		result = 0;
	}

	return result;
}

int readgpios(int num)
{
	int Status, result;

	Status = XGpio_Initialize(&GpioInput, DIOs_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XGpio_SetDataDirection(&GpioInput, 2, 0xFFFFFFFF);
	result = 0;
	result = XGpio_DiscreteRead(&GpioInput, 2);
	result = result & (int)(pow(2,(num)));
	if(result == (int)(pow(2,(num)))){
		result = 1;
	} else {
		result = 0;
	}

	return result;
}

void dacreset()
{
	u8 DACWriteBuffer[3];

	//Execute a reset to the chip (0x000A into register 0x05)
	DACWriteBuffer[0] = 0x05;
	DACWriteBuffer[1] = 0x00;
	DACWriteBuffer[2] = 0x0A;
	XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
	XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);
	DACWriteBuffer[0] = 0x05;
	DACWriteBuffer[1] = 0x00;
	DACWriteBuffer[2] = 0x00;
	XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
	XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);
}

void generatesine(int num)
{
	int reg;
	int counter;
	u8 DACWriteBuffer[3];

	reg = 0x08 + num;

	counter = 0;
	for(counter=0; counter<=8000; counter++) {
		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0x80;
		DACWriteBuffer[2] = 0x00;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0xDA;
		DACWriteBuffer[2] = 0x82;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0xFF;
		DACWriteBuffer[2] = 0xFF;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0xDA;
		DACWriteBuffer[2] = 0x82;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0x80;
		DACWriteBuffer[2] = 0x00;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0x25;
		DACWriteBuffer[2] = 0x7D;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0x00;
		DACWriteBuffer[2] = 0x00;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);

		DACWriteBuffer[0] = reg;
		DACWriteBuffer[1] = 0x25;
		DACWriteBuffer[2] = 0x7D;
		XSpiPs_SetSlaveSelect(&SpiInstance, DAC_SPI_SELECT);
		XSpiPs_PolledTransfer(&SpiInstance, DACWriteBuffer, NULL, 3);
	}
}

int adcsreset()
{
	int Status;
	unsigned int SentCount;

	//ADC0
	Status = XUartLite_Initialize(&UartLite, ADC0_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x06;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 2);
	if (SentCount != 2) {
		return XST_FAILURE;
	}
	//ADC1
	Status = XUartLite_Initialize(&UartLite, ADC1_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x06;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 2);
	if (SentCount != 2) {
		return XST_FAILURE;
	}
	//ADC2
	Status = XUartLite_Initialize(&UartLite, ADC2_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x06;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 2);
	if (SentCount != 2) {
		return XST_FAILURE;
	}

	return 0;
}

int adcread(int num)
{
	int Status, reg, counter;
	unsigned int SentCount, ReceivedCount = 0;
	int value;
	u16 device = 0;

	//SELECT CHANNEL
	unsigned int mux = ((num%4) + 1) & 0x3;
	unsigned int gain = 1;
	unsigned int pgaBypass = 0x1;
	reg = 0x80 | ((mux&0x3)<<4) | (gain&0x6) | pgaBypass;

	if(num>=0 && num<4) {
		device = ADC0_DEVICE_ID;
	} else if(num>=4 && num<8) {
		device = ADC1_DEVICE_ID;
	} else if(num>=8 && num<12) {
		device = ADC2_DEVICE_ID;
	}

	Status = XUartLite_Initialize(&UartLite, device);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	//CONFIGURE REG 0, SELECTING CHANNEL
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x40;
	SendBuffer[2] = reg;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 3);
	if (SentCount != 3) {
		return XST_FAILURE;
	}

	//SELECT CONTINUOUS MODE
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x42;
	SendBuffer[2] = 0x0c; //0x4;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 3);
	if (SentCount != 3) {
		return XST_FAILURE;
	}

	//SELECT AUTOMATIC MODE
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x46;
	SendBuffer[2] = 0x01;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 3);
	if (SentCount != 3) {
		return XST_FAILURE;
	}

	//START
	SendBuffer[0] = 0x55;
	SendBuffer[1] = 0x08;
	SentCount = XUartLite_Send(&UartLite, SendBuffer, 2);
	if (SentCount != 2) {
		return XST_FAILURE;
	}

	//READ
	RecvBuffer[0] = 0;
	RecvBuffer[1] = 0;
	RecvBuffer[2] = 0;

	counter = 0;
	//for(counter=0; counter==8000; counter++)
	for(counter=0; counter<=8000; counter++)
	{
		ReceivedCount += XUartLite_Recv(&UartLite, RecvBuffer, 3);
		value = RecvBuffer[0];
		value = value << 8;
		value = value + RecvBuffer[1];
		value = value << 8;
		value = value + RecvBuffer[2];
		printf("Value: %#08x\n\r", value);
	}

	return XST_SUCCESS;
}

int main()
{
	int selection;
	int lednum, dionum, gpionum, dacnum, adcnum;
	int onoff, value;
	int Status;
	int scan = 0;

    init_platform();

    ledsmask = 0x0;
    diosmask = 0x0;
	gpiosmask = 0x0;

    printf("\n\r****------------------------------------------------****\n\r");
    printf(" ***Sundance Multiprocessor Technology Ltd. (c) 2018*** \n\r");
    printf("  **------------------------------------------------**  \n\r");
    printf("    Vivado 17.4\n\r");
    printf("    Timoteo Garcia Bertoa  -timoteo.gb@sundance.com-\n\n\r");
    printf("    Test to control write/read commands to LEDs, DIOs, GPIOs\n\n\r");

    //MENU
    while(1){
selection = 0;
		printf("Test menu: \n\r");
		printf("    1. Write to LED \n\r");
		printf("    2. Write to DIO \n\r");
		printf("    3. Write to GPIO \n\r");
		printf("    4. Read from DIO \n\r");
		printf("    5. Read from GPIO \n\r");
		printf("    6. Write all ones \n\r");
		printf("    7. Write all zeroes \n\r");
		printf("    8. Test DAC. Generate an 8-point sine wave \n\r");
		printf("    9. Test ADCs. Read values from inputs \n\r");
		printf("    10. Test EEPROM. Read Serial Number \n\r");
		printf("Please, select which test you want to run: ");
		scan = scanf("%i", &selection);
		if (scan!=1) {selection=0;clean_stdin();}

		switch(selection){
			case 1 : //WRITE TO LED
				lednum = 0;
				onoff = 0;
				printf("\n\rWhich LED? (2,3,4,5): ");
				scan = scanf("%i", &lednum);
				if (scan!=1) {lednum=0;clean_stdin();}
				if((lednum < 2) | (lednum > 5)){ printf("\n\rError\n\r"); break; }
				printf("\n\rTurn on (1) or turn off (0)? ");
				scan = scanf("%i", &onoff);
				if (scan!=1) {onoff=2;clean_stdin();}
				if((onoff < 0) | (onoff > 1)){ printf("\n\rError\n\r"); break; }
				writeleds(lednum, onoff);
				break;
			case 2 : //WRITE TO DIO
				dionum = 0;
				onoff = 0;
				printf("\n\rWhich DIO? (0..14): ");
				scan = scanf("%i", &dionum);
				if (scan!=1) {dionum=15;clean_stdin();}
				if((dionum < 0) | (dionum > 14)){ printf("\n\rError\n\r"); break; }
				printf("\n\rTurn on (1) or turn off (0)? ");
				scan = scanf("%i", &onoff);
				if (scan!=1) {onoff=2;clean_stdin();}
				if((onoff < 0) | (onoff > 1)){ printf("\n\rError\n\r"); break; }
				writedios(dionum, onoff);
				break;
			case 3 : //WRITE TO GPIO
				gpionum = 0;
				onoff = 0;
				printf("\n\rWhich GPIO? (0..27): ");
				scan = scanf("%i", &gpionum);
				if (scan!=1) {gpionum=30;clean_stdin();}
				if((gpionum < 0) | (gpionum > 27)){ printf("\n\rError\n\r"); break; }
				printf("\n\rTurn on (1) or turn off (0)? ");
				scan = scanf("%i", &onoff);
				if (scan!=1) {onoff=2;clean_stdin();}
				if((onoff < 0) | (onoff > 1)){ printf("\n\rError\n\r"); break; }
				writegpios(gpionum, onoff);
				break;
			case 4 : //READ FROM DIO
				dionum = 0;
				onoff = 0;
				printf("\n\rWhich DIO? (0..14): ");
				scan = scanf("%i", &dionum);
				if (scan!=1) {dionum=15;clean_stdin();}
				if((dionum < 0) | (dionum > 14)){ printf("\n\rError\n\r"); break; }
				value = readdios(dionum);
				printf("\n\rThe value is %i!\n\r", value);
				break;
			case 5 : //READ FROM GPIO
				dionum = 0;
				onoff = 0;
				printf("\n\rWhich GPIO? (0..27): ");
				scan = scanf("%i", &gpionum);
				if (scan!=1) {gpionum=30;clean_stdin();}
				if((gpionum < 0) | (gpionum > 27)){ printf("\n\rError\n\r"); break; }
				value = readgpios(gpionum);
				printf("\n\rThe value is %i!\n\r", value);
				break;
			case 6 : //WRITE ALL 1s
				Status = XGpio_Initialize(&GpioOutput, LEDs_DEVICE_ID);
					if (Status != XST_SUCCESS)  {
						return XST_FAILURE;
					}
				XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
				XGpio_DiscreteWrite(&GpioOutput, 1, 0xFFFFFFFF);

				Status = XGpio_Initialize(&GpioOutput, DIOs_DEVICE_ID);
					if (Status != XST_SUCCESS)  {
						return XST_FAILURE;
					}
				XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
				XGpio_DiscreteWrite(&GpioOutput, 1, 0xFFFFFFFF);

				Status = XGpio_Initialize(&GpioOutput, GPIOs_DEVICE_ID);
					if (Status != XST_SUCCESS)  {
						return XST_FAILURE;
					}
				XGpio_SetDataDirection(&GpioOutput, 2, 0x0);
				XGpio_DiscreteWrite(&GpioOutput, 2, 0xFFFFFFFF);

				ledsmask = 0xFFFFFFFF;
				diosmask = 0xFFFFFFFF;
			    gpiosmask = 0xFFFFFFFF;

				break;
			case 7 : //WRITE ALL 0s
				Status = XGpio_Initialize(&GpioOutput, LEDs_DEVICE_ID);
					if (Status != XST_SUCCESS)  {
						return XST_FAILURE;
					}
				XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
				XGpio_DiscreteWrite(&GpioOutput, 1, 0x0);

				Status = XGpio_Initialize(&GpioOutput, DIOs_DEVICE_ID);
					if (Status != XST_SUCCESS)  {
						return XST_FAILURE;
					}
				XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
				XGpio_DiscreteWrite(&GpioOutput, 1, 0x0);

				Status = XGpio_Initialize(&GpioOutput, GPIOs_DEVICE_ID);
					if (Status != XST_SUCCESS)  {
						return XST_FAILURE;
					}
				XGpio_SetDataDirection(&GpioOutput, 2, 0x0);
				XGpio_DiscreteWrite(&GpioOutput, 2, 0x0);

				ledsmask = 0x0;
				diosmask = 0x0;
				gpiosmask = 0x0;

				break;
			case 8 : //TEST DAC
				SpiConfig = XSpiPs_LookupConfig(SPI_DEVICE_ID);
				if (NULL == SpiConfig) {
					return XST_FAILURE;
				}
				Status = XSpiPs_CfgInitialize(&SpiInstance, SpiConfig,
								   SpiConfig->BaseAddress);
				if (Status != XST_SUCCESS) {
					return XST_FAILURE;
				}
				XSpiPs_SetOptions(&SpiInstance, XSPIPS_MASTER_OPTION |
						   XSPIPS_FORCE_SSELECT_OPTION | XSPIPS_CLK_ACTIVE_LOW_OPTION);
				XSpiPs_SetClkPrescaler(&SpiInstance, XSPIPS_CLK_PRESCALE_256);

				dacnum = 0;
				printf("\n\rWhich Output? (0..7): ");
				scan = scanf("%i", &dacnum);
				if (scan!=1) {dacnum=8;clean_stdin();}
				if((dacnum < 0) | (dacnum > 7)){ printf("\n\rError\n\r"); break; }

				dacreset();
				generatesine(dacnum);

				break;
			case 9 : //TEST ADC
				adcsreset();
				adcnum = 0;
				printf("\n\rWhich Input? (0..11): ");
				scan = scanf("%i", &adcnum);
				if (scan!=1) {adcnum=12;clean_stdin();}
				if((adcnum < 0) | (adcnum > 11)){ printf("\n\rError\n\r"); break; }
				adcread(adcnum);

				break;
			case 10 : //EEPROM TEST
				xil_printf("################################################\r\n");
				xil_printf("##############  FM191 serial number ############\r\n");
				xil_printf("################################################\r\n");

				Status = IicEepromProg();
				if (Status != XST_SUCCESS) {
					xil_printf("IIC EEPROM programming Failed\r\n");
					return XST_FAILURE;
				}

				break;
			default : //INVALID
				printf("Invalid number\n\r");
		}
	}
    return 0;
}
