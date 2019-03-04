#ifndef SUN_GPIO_HPP_
#define SUN_GPIO_HPP_

#define GPIO_ADDR 		0x41210000
#define GPIO_DATA    	0x0 // 0x0000    // Channel 1 AXI GPIO Data Register.
#define GPIO_TRI     	0x1 // 0x0004    // Channel 1 AXI GPIO 3-state Control Register.
#define GPIO2_DATA   	0x2 // 0x0008    // Channel 2 AXI GPIO Data Register.
#define GPIO2_TRI    	0x3 // 0x000C    // Channel 2 AXI GPIO 3-state Control.
#define GIER         	0x011C    // Global Interrupt Enable Register.
#define IP_IER       	0x0128    // IP Interrupt Enable Register (IP IER).
#define IP_ISR       	0x0120    // IP Interrupt Status Register.

#define ERR_GPIO_OK          (0)
#define ERR_GPIO_WRONG_TYPE 	(-1)
#define ERR_GPIO_WRONG_PORT	(-2)
#define ERR_GPIO_NO_DEV_FILE (-3)
#define ERR_GPIO_MMAP        (-4)

class SUN_GPIO 
{
	public:
		SUN_GPIO(const char *devname, unsigned int gpioTri, unsigned int gpioData, unsigned int nbPort);
		~SUN_GPIO();	

		int transfer(bool read, unsigned int pin, bool &data);
		char* getError();
			
	private:
    int err_code;
    char err_msg[256];
    unsigned int gpioTri; 
    unsigned int gpioData;
    const char *devName;
    unsigned int nbPort;
};

#endif //SUN_GPIO_HPP_

