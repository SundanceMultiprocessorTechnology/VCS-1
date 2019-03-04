#ifndef SPI_HPP_
#define SPI_HPP_

#include <cstdint>
#include <linux/spi/spidev.h>
#include "FM191.hpp"

//#define dbg(format, arg...) if (TRACE) printf("DBG: " format "\n" , ## arg)

#define CMD_RD            (1<<7) //DAC read operation
#define CMD_WR            (0<<7) //DAC write operation
#define DAC_NOP_REG     0x0			//W                   
#define DAC_ID_REG      0x1			//R                   
#define DAC_SYNC_REG    0x2			//R/W reset = 0xFF00  
#define DAC_CONFIG_REG  0x3			//R/W reset = 0x0000  
#define DAC_GAIN_REG    0x4			//R/W                 
#define DAC_TRIGGER_REG 0x5			//W 	reset = 0x0000  
#define DAC_BRDCAST_REG 0x6			//R/W reset = 0x0000  
#define DAC_STATUS_REG  0x7			//R  	reset = 0x0000  
#define DAC_DAC0_REG    0x8			//R/W	reset = 0x0000  
#define DAC_DAC1_REG    0x9			//R/W	reset = 0x0000  
#define DAC_DAC2_REG    0xA			//R/W	reset = 0x0000  
#define DAC_DAC3_REG    0xB			//R/W	reset = 0x0000  
#define DAC_DAC4_REG    0xC			//R/W	reset = 0x0000  
#define DAC_DAC5_REG    0xD			//R/W	reset = 0x0000  
#define DAC_DAC6_REG    0xE			//R/W	reset = 0x0000  
#define DAC_DAC7_REG    0xF			//R/W	reset = 0x0000  

class SPI_DAC 
{
	public:
		SPI_DAC(const char *portname, uint32_t mode, uint8_t bits, uint32_t speed);
		~SPI_DAC();	
	
		int writeData(int reg, int data);
		int readData(int reg, int &data);
	
	private:	 
		const char *name;		// device file name
		int spi;						// file descriptor
	
		int configureSPI(uint32_t mode, uint8_t bits, uint32_t speed);
};
#endif //SPI_HPP_
