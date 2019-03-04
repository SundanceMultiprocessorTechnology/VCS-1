#include "uart.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

unsigned int menu()
{
	unsigned int d;

	printf("Enter the type of acquisition to perform:\n");
	printf("\t1- Automatic single shot (used for the Vinescout)\n");
	printf("\t2- Automatic continuous\n");
	printf("\t3- Manual single shot\n");
	printf("\t4- Manual continuous\n");
	scanf("%d", &d);

	return d;
}

void automatic_singleshot(UART_ADC* uart)
{
	int val = 0;
	int n = 0;

	for (;;) {
		uart->start();	
		n = uart->readVal(val);
		if (n<0) printf("\tRead value failed\n");
		else printf("\tRead ouput 0x%x %d (%0.3fV)\n", val, val,(float)((float)(val*5)/0x7FFFFF));
		sleep(2);
	}
	return;
}

void automatic_continuous(UART_ADC* uart)
{
	if (!uart) return;
	int val = 0;
	int n = 0;

	uart->start();		
	for (;;) {
		n = uart->readVal(val);
		if (n<0) printf("\tRead value failed\n");
		else printf("\tRead ouput 0x%x (%0.3fV)\n", val, (float)((float)(val*5)/0x7FFFFF));
	}
}

void manual_singleshot(UART_ADC* uart)
{
	if (!uart) return;
	int val = 0;
	char res = 0;
	int n = 0;

	for (;;) {
		uart->start();
		while ((res>>7)==0) n = uart->readReg(2, &res); //polling the DRDY
		res = 0;
		uart->readData();
		//uart->start();	
		n = uart->readVal(val);
		if (n<0) printf("\tRead value failed\n");
		else printf("\tRead ouput 0x%x - %d (%0.3fV)\n", val, val, (float)((float)(val*5)/0x7FFFFF));
		sleep(2);
	}
	return;
	
}

void manual_continuous(UART_ADC* uart)
{
	if (!uart) return;
	int val = 0;
	char res = 0;
	int n = 0;

	uart->start();	
		
	for (;;) {
		while ((res>>7)==0) n = uart->readReg(2, &res); //polling the DRDY
		res = 0;
		uart->readData();
		n = uart->readVal(val);
		if (n<0) printf("\tRead value failed\n");
		else printf("\tRead ouput 0x%x (%0.3fV)\n", val, (float)((float)(val*5)/0x7FFFFF));
	}
	return;
}

void setReg(UART_ADC* uart, unsigned int gain, unsigned int mux, unsigned int ref, bool continuous, bool automatic)
{
	if (!uart) return;
	int n = 0;
	uart->reset();
	
	uart->setReg0Value(gain, mux); 	
	printf("\tWriting to register 0 0x%x\n", uart->getRegValue(0));
	n = uart->writeReg(0);
	if (n<0) printf("\tWrite reg 0 failed (error %d)\n", n);

	uart->setReg1Value(ref, continuous);
	printf("\tWriting to register 1 0x%x\n", uart->getRegValue(1));
	n = uart->writeReg(1);
	if (n<0) printf("\tWrite reg 1 failed (error %d)\n", n);

	uart->setReg3Value(automatic);
	printf("\tWriting to register 3 0x%x\n", uart->getRegValue(3));
	n = uart->writeReg(3);
	if (n<0) printf("\tWrite reg 3 failed (error %d)\n", n);

	char res =0;
	char reg = 0;
		
	for (int j=0; j<5; j++) {
		n = uart->readReg(j, &res);
		if (n<0) printf("\tFailed to read register %d (error %d)\n", j, n);
		else printf("\tRead reg %d: 0x%x\n", j, res);
		if ((reg=uart->getRegValue(j)) != res) printf("\t!!!ERROR: expected 0x%x but register %d = 0x%x\n", reg, j, res);
	}

	return;

}

int main(int argc, char const *argv[])
{
	int i;
	printf("Enter the UART number 1 to 3\n");
	scanf("%d",&i);

	char portname[16];
	sprintf(portname, "/dev/ttyUL%d", i);
	UART_ADC uart(portname, B115200, 0, 0);

	unsigned int gain = 1;
	unsigned int mux = 2;
	unsigned int ch = 0;
	unsigned int ref = 2;
	
	printf("Enter the channel number 0 to 3\n");
	scanf("%d",&ch);
	mux = (ch + 1)&0x3;
	
	printf("\nStarting UART%d testing...\n", i);	
	printf("\n\t*** CHANNEL %d ***\n",mux);

	unsigned int d = menu();

	switch (d) {
		case 1: {
			printf("Automatic single shot mode\n");
			setReg(&uart, gain, mux, ref, 0, 1);
			automatic_singleshot(&uart);
		} break;

		case 2: {
			printf("Automatic continuous mode\n");
			setReg(&uart, gain, mux, ref, 1, 1);
			automatic_continuous(&uart);
		} break;


		case 3: {
			printf("manual single shot mode\n");
			setReg(&uart, gain, mux, ref, 0, 0);
			manual_singleshot(&uart);
		} break;


		case 4: {
			printf("manual continuous mode\n");
			setReg(&uart, gain, mux, ref, 1, 0);
			manual_continuous(&uart);
		} break;


		default: printf("wrong selection\n");
	}

  	printf("\nTest done\n");
	
	return 0;
}


