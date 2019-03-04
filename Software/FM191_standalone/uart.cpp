#include "uart.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>

///////////////////////////////////////////////////////////////////////////////////
// Constructor:
//  Get the device's file descriptor and configure the serial interface
//
// Parameters:
//  portname: device file name
//  speed: baud rate
//  parity: 0: disable 1:enable
//  should_block: 0:non-block read 1: block read
///////////////////////////////////////////////////////////////////////////////////	
UART_ADC::UART_ADC(const char *portname, int speed, int parity, int should_block)
							: name(portname)
								
{
	regVal[0] = 0x81; // PGA bypass, gain 1, AINP = AIN0
	regVal[1] = 0x4;  // Analog supply (AVDD / AVSS) used as reference
	regVal[2] = 0x0;
	regVal[3] = 0x1;  // Automatic data read mode
	regVal[4] = 0x0;
	
	uart = open (name, O_RDWR | O_NOCTTY | O_SYNC);
	if (uart){
		setInterfaceAttribs(speed, parity);  
		setBlocking(should_block);            
	}
}

UART_ADC::~UART_ADC() 
{
//Send the synchronization word (55h);
//Send the POWERDOWN command (02h) to stop conversions and put the device in power-down mode;
	
	if (uart>0) close(uart);
}

///////////////////////////////////////////////////////////////////////////////////
// setInterfaceAttribs:
//  configure the serial interface
//
// Parameters:
//  speed: baud rate
//  parity: 0: disable 1:enable
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int UART_ADC::setInterfaceAttribs(int speed, int parity)
{
	struct termios tty;
	
	memset (&tty, 0, sizeof tty);
	if (tcgetattr (uart, &tty) != 0) {
		dbg("error %d from tcgetattr", errno);
		return -1;
	}
	
	/* Set Baud Rate */
	cfsetospeed (&tty, speed);
	cfsetispeed (&tty, speed);
	
	/* other settings */
	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars disable IGNBRK for mismatched speed tests; otherwise receive break as \000 chars
	tty.c_iflag &= ~IGNBRK;         								// disable break processing
	tty.c_lflag = 0;                								// no signaling chars, no echo, no canonical processing
	tty.c_oflag = 0;                								// no remapping, no delays
	tty.c_cc[VMIN]  = 0;            								// read doesn't block // 1??
	tty.c_cc[VTIME] = 5;            								// 0.5 seconds read timeout
	tty.c_iflag &= ~(IXON | IXOFF | IXANY); 				// shut off xon/xoff ctrl
	tty.c_cflag |= (CLOCAL | CREAD);								// ignore modem controls,enable reading
	tty.c_cflag &= ~(PARENB | PARODD);      				// shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;												// no flow control
	
	/* apply attributes */
	if (tcsetattr (uart, TCSANOW, &tty) != 0) {
		dbg("error %d from tcsetattr", errno);
		return -2;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// setBlocking:
//  set VMIn to block or non-block the serial read
//
// Parameters:
//  should_block: 0:non-block read 1: block read
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int UART_ADC::setBlocking (int should_block)
{
	struct termios tty;
	
	memset (&tty, 0, sizeof tty);
	
	if (tcgetattr (uart, &tty) != 0) {
		dbg("error %d from tggetattr", errno);
		return -1;
	}
	
	tty.c_cc[VMIN]  = should_block ? 1 : 0;
	tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
	
	if (tcsetattr (uart, TCSANOW, &tty) != 0) {
		dbg("error %d setting term attributes", errno);
		return -2;
	}
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// writeReg:
//  write the value regVal[reg], where reg is the register number, to ADC register reg
//
// Parameters:
//  reg: register number from 0 to 4
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int UART_ADC::writeReg(unsigned int reg)
{
	if ((reg>5) || (uart<0)) return -1;
	
	char wr[3];
	wr[0]=ADC_SYNC_CMD;
	wr[1]=getWrRegAddress(reg);
	wr[2]=regVal[reg];
	int n = write(uart, wr, sizeof(wr));
	if (n<0) return -2;
		
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// readReg:
//  read the value of the ADC register reg
//
// Parameters:
//  reg: register number from 0 to 4
//  res: value read from the register
//
// Return:
//  0 if success, <0 if error 
///////////////////////////////////////////////////////////////////////////////////	
int UART_ADC::readReg(unsigned int reg, char *res)
{
	if ((reg>5) || (uart<0)) return -1;
	
	char wr[2];
	wr[0]=ADC_SYNC_CMD;
	wr[1]=getRdRegAddress(reg);
	int n = write(uart, wr, sizeof(wr));
	if (n<0) return -2;
	n = read(uart, res, 1);
	if (n<0) return -3;
		
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// readVal:
//  read the ADC ouput
//
// Parameters:
//  val: ADC output value
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int UART_ADC::readVal(int &val)
{
	if (uart<0) return -1;
	
	char c[3];
	for (int i=0; i<3 ; i++) {
		int n = read(uart, c+i, 1);
		if (n<0) return -2;
	}
	val = (c[2]<<16) | (c[1]<<8) | c[0];

	return 0;	
}

///////////////////////////////////////////////////////////////////////////////////
// writeCommand:
//  write a command to the ADC
//
// parameter:
//  cmd: command to send to the ADC
//
// Return:
//  0 if success, <0 if error
///////////////////////////////////////////////////////////////////////////////////	
int UART_ADC::writeCommand(unsigned int cmd)
{
	if (uart<0) return -1;
		
	char wr[2];
	wr[0]=ADC_SYNC_CMD;
	wr[1]=cmd;
	int n = write(uart, wr, sizeof(wr));
	if (n<0) return -2;
		
	return 0;	
}

//Reset the ADC
int UART_ADC::reset()
{
	return writeCommand(ADC_RESET);
}

//Start or restart ADC conversions
int UART_ADC::start()
{
	return writeCommand(ADC_START_SYNC);
}

//Enter ADC power-down mode 
int UART_ADC::powerdown()
{
	return writeCommand(ADC_POWERDOWN);
}

//Read ADC data in manual mode 
int UART_ADC::readData()
{
	return writeCommand(ADC_RDATA);
}

///////////////////////////////////////////////////////////////////////////////////
// setReg0Value:
//  initialise the ADC register 0 value regVal[0]
//
// Parameters:
//  gain: ADC gain 1 to 4
//  mux: ADC mux 0 to 3 to select the input as such :
//            0: AINP = AIN0, 1: AINP = AIN1, 2: AINP = AIN2, 3: AINP = AIN3
//            with AINN = AVSS
///////////////////////////////////////////////////////////////////////////////////	
void UART_ADC::setReg0Value(unsigned int gain, unsigned int mux)
{
	if ((gain!=10) || (gain!=2) || (gain!=4)) gain = 1;
	if (mux>3) mux = 0;
		
	unsigned int pgaBypass = 0x1;
		
	regVal[0] = 0x80 | ((mux&0x3)<<4) | (gain&0x6) | pgaBypass; 
}
																													
///////////////////////////////////////////////////////////////////////////////////
// setReg1Value:
//  initialise the ADC register 1 value regVal[1]
//
// Parameters:
//  ref: selec the ADC voltage reference source
//    0: Internal 2.048-V reference selected (default)
//    1: External reference selected using the REFP and REFN inputs
//    2: Analog supply (AVDD – AVSS) used as reference
// continuous: set the ADC convertion mode
//    0: single-shot conversion mode (default)
//    1: continuous conversion mode
///////////////////////////////////////////////////////////////////////////////////	
void UART_ADC::setReg1Value(unsigned int ref, bool continuous) 
{
	if ((ref!=1) && (ref!=2)) ref = 0;
	regVal[1] = (continuous<<3) | ((ref<<1)&0x6);
}

///////////////////////////////////////////////////////////////////////////////////
// setReg3Value:
//  initialise the ADC register 3 value regVal[3]
//
// Parameters:
//  automatic: selec the ADC read mode
//    0: manual mode (default)
//    1: automatic mode
///////////////////////////////////////////////////////////////////////////////////	

void UART_ADC::setReg3Value(bool automatic)
{
	regVal[3] = automatic;
}

///////////////////////////////////////////////////////////////////////////////////
// getRegValue:
//  read the member variable regVal
//
// Parameters:
//  reg: register number from 0 to 4
//
// Return:
//  the value of regVal[reg]
///////////////////////////////////////////////////////////////////////////////////	
char UART_ADC::getRegValue(unsigned int reg)
{
	if (reg>5) reg = 0;
	return regVal[reg];
}

