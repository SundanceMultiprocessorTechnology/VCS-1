#include "spi.hpp"


#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
//#include <linux/spi/spidev.h>
#include <errno.h>

///////////////////////////////////////////////////////////////////////////////////
// Constructor:
//  Get the device's file descriptor and configure the serial interface
//
// Parameters:
//  portname: device file name
//  mode: SPI mode
//               SPI_LOOP //loopback
//               SPI_CPHA //clock phase
//               SPI_CPOL //clock polarity
//               SPI_LSB_FIRST
//               SPI_CS_HIGH //chip select active high
//               SPI_3WIRE //SI/SO signals shared
//               SPI_NO_CS //no chip select
//               SPI_READY //slave pulls low to pause
//               SPI_TX_DUAL //dual transfer
//               SPI_TX_QUAD //quad transfer
//  bits: SPI device word length
//  speed: SPI default maximum speed 
///////////////////////////////////////////////////////////////////////////////////	
SPI_DAC::SPI_DAC(const char *portname, uint32_t mode, uint8_t bits, uint32_t speed)
							: name(portname)
								
{
	spi = open (name, O_RDWR | O_NOCTTY | O_SYNC);
	if (spi){
		configureSPI(mode, bits, speed);          
	} else {
		printf("SPI error(return %d, error code %d)\n", spi, errno);
	}
}

SPI_DAC::~SPI_DAC() 
{
	if (spi>0) close(spi);
}

///////////////////////////////////////////////////////////////////////////////////
// configureSPI:
//  configure the serial interface
//
// Parameters:
//  mode: SPI mode
//               SPI_LOOP //loopback
//               SPI_CPHA //clock phase
//               SPI_CPOL //clock polarity
//               SPI_LSB_FIRST
//               SPI_CS_HIGH //chip select active high
//               SPI_3WIRE //SI/SO signals shared
//               SPI_NO_CS //no chip select
//               SPI_READY //slave pulls low to pause
//               SPI_TX_DUAL //dual transfer
//               SPI_TX_QUAD //quad transfer
//  bits: SPI device word length
//  speed: SPI default maximum speed 
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int SPI_DAC::configureSPI(uint32_t mode, uint8_t bits, uint32_t speed)
{
	if (spi<0) return -1;
		
	// spi mode
	int ret = ioctl(spi, SPI_IOC_WR_MODE32, &mode);
	ret = ioctl(spi, SPI_IOC_RD_MODE32, &mode);
	if (ret == -1) {
		dbg("can't read spi mode (%d)\n", errno);
		return -2;
	}	

	// bits per word
	ret = ioctl(spi, SPI_IOC_WR_BITS_PER_WORD, &bits);
	ret = ioctl(spi, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1) {
		dbg("can't read bits per word (%d)\n", errno);
		return -3;
	}

	// max speed hz
	ret = ioctl(spi, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	ret = ioctl(spi, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1) {
		dbg("can't read max speed hz (%d)\n", errno);
		return -4;
	}

//	printf("SPI controller configuration: MODE 0x%x, BIT %d, SPEED %d\n", mode, bits, speed);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// writeData:
//  write data to the DAC
//
// Parameters:
//  data: data to write to the DAC
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int SPI_DAC::writeData(int reg, int data)
{
	if (spi<0) return -1;

	char tx[3];
	tx[0] = CMD_WR | reg;
	tx[1] = (data>>4) & 0xff; //12 bit resolution
	tx[2] = data & 0xf;

	struct spi_ioc_transfer tr;
	memset(&tr, 0, sizeof(tr));
	tr.tx_buf = (unsigned long)&tx; // Holds pointer to userspace buffer with transmit data, or null.
	tr.rx_buf = 0;                  // Holds pointer to userspace buffer for receive data, or null.
	tr.len = sizeof(tx);            // Length of tx and rx buffers, in bytes.
	tr.delay_usecs = 0;             // If nonzero, how long to delay after the last bit transfer before optionally deselecting the device before the next transfer.
	//tr.speed_hz = 78000;          // Temporary override of the device's bitrate.
	//tr.bits_per_word = 8;	        // Temporary override of the device's wordsize.
	tr.cs_change = false;           //True to deselect device before starting the next transfer.
	tr.tx_nbits = 1;

	int ret = ioctl(spi, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1) {
		dbg("WRITE can't send spi message (%d)\n", errno);printf("Error\n");
		return -2;
	}
		
	return 0;	
}


int SPI_DAC::readData(int reg, int &data)
{
	if (spi<0) return -1;
	
	char tx[3];data=0;
	tx[0] = CMD_RD | reg;
	tx[1] = 0;
	tx[2] = 0;

	struct spi_ioc_transfer tr;
	memset(&tr, 0, sizeof(tr));
	tr.tx_buf = (unsigned long)&tx; // Holds pointer to userspace buffer with transmit data, or null.
	tr.rx_buf = (unsigned long)&data;       // Holds pointer to userspace buffer for receive data, or null.
	tr.len = sizeof(tx);            // Length of tx and rx buffers, in bytes.
	tr.delay_usecs = 0;         // If nonzero, how long to delay after the last bit transfer before optionally deselecting the device before the next transfer.
	//tr.speed_hz = 18000000;            // Temporary override of the device's bitrate.
	//tr.bits_per_word = 8;	      // Temporary override of the device's wordsize.
	tr.cs_change = false;           //True to deselect device before starting the next transfer.
 	tr.tx_nbits = 1;

	int ret = ioctl(spi, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1) {
		dbg("READ can't send spi message (%d)\n", errno);
		return -2;
	}


	ret = ioctl(spi, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1) {
		dbg("READ can't send spi message (%d)\n", errno);
		return -2;
	}

	return 0;	
}

