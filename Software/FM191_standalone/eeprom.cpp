#include "eeprom.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/types.h>

EEPROM::EEPROM(const char *portname)
							: name(portname)
{
  eeprom = open(name, O_RDWR);
  if (eeprom < 0) {
		printf("EEPROM error(return %d, error code %d)\n", eeprom, errno);
	}
}

EEPROM::~EEPROM() 
{
	if (eeprom>0) close(eeprom);
}


/*****************************************************************************/
/**
*
* Read the data from the EEPROM.
*
* @param    TestLoops - indicates the number of time to execute the test.
*
* @return   Status of the read from EEPROM
*
* @note     None.
*
******************************************************************************/
int EEPROM::IicRead(unsigned char *data, unsigned int size)
{
	unsigned char WriteBuffer [2];	/* Buffer to hold location address.*/
	unsigned char ReadBuffer [PAGESIZE];	/* Buffer to hold data read.*/
	unsigned short BytesToRead=(size<=PAGESIZE) ? size :PAGESIZE;
	unsigned char BytesRead=0;			/* Number of Bytes read from the IIC device. */
	unsigned short OffsetAddr = 0x0;	/* Address offset in EEPROM to be written. */
	unsigned char ReadBytes = 0;
	int Status = 0;

  if (!eeprom) { printf("EEPROM device is not open!\n"); return 1; }

	Status = ioctl(eeprom, I2C_SLAVE_FORCE, EEPROM_ADDR);
	if(Status < 0) {
		printf("\n Unable to set the EEPROM address\n");
		return -1;
	}

	dbg("\n Set EEPROM address 0x%x\n", EEPROM_ADDR);

	OffsetAddr = EEPROM_ADDR;
	if(sizeof(AddressType) == 1) {
		WriteBuffer[0] = (unsigned char)(OffsetAddr);
	} else {
		WriteBuffer[0] = (unsigned char)(OffsetAddr >> 8);
		WriteBuffer[1] = (unsigned char)(OffsetAddr);
	}

	/*
	 * Position the address pointer in EEPROM.
	 */
	dbg("\n Position the address pointer in EEPROM\n");
	write(eeprom, WriteBuffer, sizeof(AddressType));

  dbg("Done\n");

	/*
	 * limit the bytes to be read to the Page size.
	 */
	if(BytesToRead > PAGESIZE) {
		ReadBytes = PAGESIZE;
	} else {
		ReadBytes = BytesToRead;
	}

	/*
	 * Read the bytes.
	 */
	while(BytesToRead > 0) {
		dbg ("Performing Read operation\n");
		BytesRead = ReadEepromData(ReadBuffer, ReadBytes);
    for (int i = 0; i<BytesToRead; i++) data[i] = ReadBuffer[i];
		if(BytesRead != ReadBytes) {
			printf("\nITP_IIC_TEST1: Test Failed in read\n");  

			return -1;
		}

		/*
		 * Update the read counter.
		 */
		BytesToRead -= BytesRead;
		if(BytesToRead > PAGESIZE) {
			ReadBytes = PAGESIZE;
		} else {
			ReadBytes = BytesToRead;
		}

	}

	dbg("\nRead EEPROM Successful\n");

	return 0;
}

/*****************************************************************************/
/**
*
* Write data to the EEPROM.
*
* @param    TestLoops - indicates the number of time to execute the test.
*
* @return   None.
*
* @note     None.
*
******************************************************************************/
int EEPROM::IicWrite(unsigned char *data, unsigned int size)
{
	unsigned char WriteBuffer[PAGESIZE + sizeof(AddressType)]; /* Buffer to hold data to be written */
	unsigned short BytesToWrite = (size<=PAGESIZE) ? size : PAGESIZE;
	unsigned char BytesWritten;	/* Number of Bytes written to the IIC device. */
	unsigned short Index;				/* Loop variable. */
	unsigned short OffsetAddr = 0x0;	/* Address offset in EEPROM to be written. */
	unsigned char WriteBytes;
	unsigned char Data = 0x0;
	int Status = 0;

  if (!eeprom) { printf("EEPROM device is not open!\n"); return 1; }

	Status = ioctl(eeprom, I2C_SLAVE_FORCE, EEPROM_ADDR);
	if (Status < 0) {
		printf("\n Unable to set the EEPROM address\n");
		return -1;
	}

	Data = 0x11;
	OffsetAddr = EEPROM_ADDR;
	/*
	 * Load the offset address inside EEPROM where data need to be written.
	 */
  if(sizeof(AddressType) == 1) {
		WriteBuffer[0] = (unsigned char)(OffsetAddr);
 	} else {
		WriteBuffer[0] = (unsigned char)(OffsetAddr >> 8);
		WriteBuffer[1] = (unsigned char)(OffsetAddr);
	}

	/*
	 * Load the data to be written into the buffer.
	 */
	for(Index = 0; Index < BytesToWrite/*PAGESIZE*/; Index++) {
		WriteBuffer[Index + sizeof(AddressType)] = data[Index];
	}

	/*
	 * Limit the number of bytes to the page size.
	 */
	if (BytesToWrite > PAGESIZE) {
		WriteBytes = PAGESIZE + sizeof(AddressType);
	} else {
		WriteBytes = BytesToWrite + sizeof(AddressType);
	}

	while (BytesToWrite > 0) {
		/*
		 * Write the data.
		 */
		BytesWritten = WriteEepromData(WriteBuffer, WriteBytes);
		if  (BytesWritten != WriteBytes) {
			printf("\nTest Failed in write (ask to write %d but wrote %d)\n", WriteBytes, BytesWritten);
			return -1;
		}

		/*
		 * Update the write counter.
		 */
		BytesToWrite -= (BytesWritten - sizeof(AddressType));
		if (BytesToWrite > PAGESIZE) {
			WriteBytes = PAGESIZE + sizeof(AddressType);
		} else {
			WriteBytes = BytesToWrite + sizeof(AddressType);
		}

		/*
		 * Increment the offset address.
		 */
		OffsetAddr += PAGESIZE;

		 
		/*
		 * load the new offset address.
		 */
		if (sizeof(AddressType) == 1) {
			WriteBuffer[0] = (unsigned char)(OffsetAddr);
		} else {
			WriteBuffer[0] = (unsigned char)(OffsetAddr >> 8);
			WriteBuffer[1] = (unsigned char)(OffsetAddr);
	 	}

		/*
		 * load the new data into buffer.
		 */
		for(Index = 0; Index < BytesToWrite/*PAGESIZE*/; Index++) {
			WriteBuffer[Index + sizeof(AddressType)] = data[Index];
		}
	}

	dbg("\nWrite EEPROM Successful\n");

	return 0;
}



/*****************************************************************************/
/**
*
* Write the data to the Slave device.
*
* @param    WriteBuffer - Buffer to hold the data to be transmitted on the Bus.
* @param	NoOfBytes	- Number of bytes to be written onto the bus.
*
* @return   Number of bytes written onto the bus.
*
* @note     None.
*
******************************************************************************/
unsigned char EEPROM::WriteEepromData(unsigned char WriteBuffer[], unsigned char NoOfBytes)
{
	unsigned char BytesWritten;	/* Number of Bytes written to the IIC device. */

  if (!eeprom) { printf("EEPROM device is not open!\n"); return 1; }
	/*
	 * Write the bytes onto the bus.
	 */
	BytesWritten = write(eeprom, WriteBuffer, NoOfBytes);

	/*
	 * Wait till the EEPROM internally completes the write cycle.
	 */
	sleep(1);

	return BytesWritten;
}

/*****************************************************************************/
/**
*
* Read the data from the Slave device.
*
* @param    ReadBuffer  - Buffer to hold the data received on the bus.
* @param	NoOfBytes	- Number of bytes to be read from the bus.
*
* @return   Number of bytes read from the bus.
*
* @note     None.
*
******************************************************************************/
unsigned char EEPROM::ReadEepromData(unsigned char ReadBuffer[], unsigned char NoOfBytes)
{
	unsigned char BytesRead;	/* Number of Bytes read from the device. */
  if (!eeprom) { printf("EEPROM device is not open!\n"); return 1; }

	/*
	 * Read the bytes from the bus.
	 */
	BytesRead = read(eeprom, ReadBuffer, NoOfBytes);

	return BytesRead;
}



