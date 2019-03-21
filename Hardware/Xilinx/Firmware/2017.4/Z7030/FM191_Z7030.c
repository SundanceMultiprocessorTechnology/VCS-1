//////////////////////////////////////////////////////////////
// Company: Sundance Multiprocessor Technology LTD
// Engineer: Timoteo Garcia Bertoa
//
// Design Name: EMC2-DP + FM191-RU
// Module Name: Test
// Project Name: FM191_Standalone
// Target Devices: xc7z030sbg485-1
// Tool Versions: Xilinx SDK 17.4
//
// Additional Comments: Test for LEDs, DIOs, GPIOs onboard
//
//////////////////////////////////////////////////////////////

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include <math.h>

#define LED_CHANNEL 1
#define LEDs_DEVICE_ID	XPAR_M_LEDS_DEVICE_ID
#define DIOs_DEVICE_ID	XPAR_IOS_DEVICE_ID
#define GPIOs_DEVICE_ID	XPAR_IOS_DEVICE_ID
#define MAX 4294967295

XGpio GpioOutput; /* The driver instance for GPIO Device configured as O/P */
XGpio GpioInput;  /* The driver instance for GPIO Device configured as I/P */

int ledsmask, diosmask, gpiosmask;

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

int main()
{
	int selection;
	int lednum, dionum, gpionum;
	int onoff, value;
	int Status, x;

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
		printf("Please, select which test you want to run: ");
		scanf("%i", &selection);

		switch(selection){
			case 1 : //WRITE TO LED
				lednum = 0;
				onoff = 0;
				printf("\n\rWhich LED? (2,3,4,5): ");
				scanf("%i", &lednum);
				if((lednum < 2) | (lednum > 5)){ printf("\n\rError\n\r"); break; }
				printf("\n\rTurn on (1) or turn off (0)? ");
				scanf("%i", &onoff);
				if((onoff < 0) | (onoff > 1)){ printf("\n\rError\n\r"); break; }
				writeleds(lednum, onoff);
				break;
			case 2 : //WRITE TO DIO
				dionum = 0;
				onoff = 0;
				printf("\n\rWhich DIO? (0..14): ");
				scanf("%i", &dionum);
				if((dionum < 0) | (dionum > 14)){ printf("\n\rError\n\r"); break; }
				printf("\n\rTurn on (1) or turn off (0)? ");
				scanf("%i", &onoff);
				if((onoff < 0) | (onoff > 1)){ printf("\n\rError\n\r"); break; }
				writedios(dionum, onoff);
				break;
			case 3 : //WRITE TO GPIO
				gpionum = 0;
				onoff = 0;
				printf("\n\rWhich GPIO? (0..27): ");
				scanf("%i", &gpionum);
				if((gpionum < 0) | (gpionum > 27)){ printf("\n\rError\n\r"); break; }
				printf("\n\rTurn on (1) or turn off (0)? ");
				scanf("%i", &onoff);
				if((onoff < 0) | (onoff > 1)){ printf("\n\rError\n\r"); break; }
				writegpios(gpionum, onoff);
				break;
			case 4 : //READ FROM DIO
				dionum = 0;
				onoff = 0;
				printf("\n\rWhich DIO? (0..14): ");
				scanf("%i", &dionum);
				if((dionum < 0) | (dionum > 14)){ printf("\n\rError\n\r"); break; }
				value = readdios(dionum);
				printf("\n\rThe value is %i!\n\r", value);
				break;
			case 5 : //READ FROM GPIO
				dionum = 0;
				onoff = 0;
				printf("\n\rWhich GPIO? (0..27): ");
				scanf("%i", &gpionum);
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
			default : //INVALID
				printf("Invalid number\n\r");
		}

	}

    return 0;
}

