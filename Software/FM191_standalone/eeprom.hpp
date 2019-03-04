#ifndef EEPROM_HPP_
#define EEPROM_HPP_


#define I2C_SLAVE_FORCE 0x0706
#define I2C_SLAVE	0x0703	/* Change slave address			*/
#define I2C_FUNCS	0x0705	/* Get the adapter functionality */
#define I2C_RDWR	0x0707	/* Combined R/W transfer (one stop only)*/

#define EEPROM_ADDR			0x50
#define PAGESIZE 16

#define TRACE 0
#define dbg(format, arg...) if (TRACE) printf("DBG: " format "\n" , ## arg)

class EEPROM 
{
	public:
		EEPROM(const char *portname);
		~EEPROM();	
	
    int IicRead(unsigned char *data, unsigned int size);
    int IicWrite(unsigned char *data, unsigned int size);
	
	private:	 
		unsigned char ReadEepromData(unsigned char ReadBuffer[], unsigned char NoOfBytes);
    unsigned char WriteEepromData(unsigned char ReadBuffer[], unsigned char NoOfBytes);
    const char *name;		// device file name
		int eeprom;						// file descriptor
    unsigned char AddressType;
};

#endif //EEPROM_HPP_
