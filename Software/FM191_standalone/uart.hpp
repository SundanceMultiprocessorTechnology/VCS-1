#ifndef UART_HPP_
#define UART_HPP_

#include "FM191.hpp"

//#define dbg(format, arg...) if (TRACE) printf("DGB: " format "\n" , ## arg)


class UART_ADC 
{
	public:
		UART_ADC(const char *portname, int speed, int parity, int should_block);
		~UART_ADC();	
	
		void setReg0Value(unsigned int gain, unsigned int mux); 	
		void setReg1Value(unsigned int ref, bool continuous); 
		void setReg3Value(bool automatic);
		char getRegValue(unsigned int reg);
		int writeReg(unsigned int reg);
		int readReg(unsigned int reg, char *res);
		int readVal(int &val);	// 24-bit value	
		int reset();
		int start();
		int powerdown();
		int readData();
	
	private:	 
		const char *name;		// device file name
		char regVal[5]; 	
		int uart;						// file descriptor
		
		const unsigned int ADC_RESET      = 0x06;     //Reset the device
		const unsigned int ADC_START_SYNC = 0x08;     //Start or restart conversions
		const unsigned int ADC_POWERDOWN  = 0x02;     //Enter power-down mode 
		const unsigned int ADC_RDATA      = 0x10;     //Read data by command 
		const unsigned int ADC_SYNC_CMD   = 0x55;     //synchronization word to the device 
		
		unsigned int getRdRegAddress(unsigned int reg) {return (reg<5) ?  (0x20|((reg<<1)&0xe)) : 0;} 
		unsigned int getWrRegAddress(unsigned int reg) {return (reg<5) ?  (0x40|((reg<<1)&0xe)) : 0;}
	
		int setInterfaceAttribs(int speed, int parity);
		int setBlocking (int should_block);	
		
		int writeCommand(unsigned int cmd);

};
#endif //UART_HPP_
