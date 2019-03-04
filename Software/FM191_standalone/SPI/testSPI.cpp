#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <errno.h>
#include "../spi.hpp"


int main(int argc, char *argv[])
{
	SPI_DAC spi("/dev/spidev1.0", SPI_CPOL, 8, 78000); //32766.0

	
	spi.writeData(DAC_TRIGGER_REG, 0xA);
	spi.writeData(DAC_TRIGGER_REG, 0x0);

	printf("Select DAC\n");
	int dac = 0;
	scanf("%d", &dac);
	printf("The AO%d selected\n", dac);
	switch(dac) {
		case 0: dac = DAC_DAC0_REG; break;
		case 1: dac = DAC_DAC1_REG; break;
		case 2: dac = DAC_DAC2_REG; break;
		case 3: dac = DAC_DAC3_REG; break;
		case 4: dac = DAC_DAC4_REG; break;
		case 5: dac = DAC_DAC5_REG; break;
		case 6: dac = DAC_DAC6_REG; break;
		case 7: dac = DAC_DAC7_REG; break;
	}

	for (;;) {
		spi.writeData(dac, 0x800);
		spi.writeData(dac, 0xDA8);
		spi.writeData(dac, 0xFFF);
		spi.writeData(dac, 0xDA8);
		spi.writeData(dac, 0x800);
		spi.writeData(dac, 0x257);
		spi.writeData(dac, 0x000);
		spi.writeData(dac, 0x257);
	}
}
