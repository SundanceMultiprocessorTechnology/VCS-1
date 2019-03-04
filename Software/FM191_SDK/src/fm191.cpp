#include "FM191.hpp"
#include "uart.hpp"
#include "gpio.hpp"
#include "spi.hpp"

int err_code;
char err_msg[256];

int digital_read(unsigned int type, unsigned int port, bool &data)
{
  err_code = ERR_OK;
  sprintf(err_msg, "No error\n");
    
  if (type>= NB_TYPE_RD) {
    err_code = ERR_WRONG_TYPE;
    sprintf(err_msg, "Wrong type, only valid type are 0 (DIO) and 1(GPIO)\n");
    return err_code;
  }
  
  const char *devName = "/dev/uio1";
  unsigned int gpioTri = 0;
  unsigned int gpioData = 0;
  unsigned int nbPort = 0;
  
  switch (type) {
    case 0: {devName = "/dev/uio1"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA; nbPort = DIO;} break; //DIO
    case 1: {devName = "/dev/uio1"; gpioTri = GPIO2_TRI; gpioData = GPIO2_DATA; nbPort = GPIO;} break; //GPIO
  }  
  
  SUN_GPIO gpio(devName, gpioTri, gpioData, nbPort);  
  unsigned int read = 1;
  int err = gpio.transfer(read, port, data);
  if (err) {
    sprintf(err_msg, "%s (%d)\n", gpio.getError(), err);
    err_code = ERR_DIGITAL_RD_FAIL;
  }
    
  return err;
}

int digital_write(unsigned int type, unsigned int port, bool data)
{
  err_code = ERR_OK;
  sprintf(err_msg, "No error\n");
  
  if (type>= NB_TYPE) {
    err_code = ERR_WRONG_TYPE;
    sprintf(err_msg, "Wrong type, only valid type are 0 (DIO), 1(GPIO), 2(FM191 LED), 3(EMC2 LED) and 4(EMC2 ethernet LED)\n");
    return err_code;
  }
  
  const char *devName = "/dev/uio1";
  unsigned int gpioTri = 0;
  unsigned int gpioData = 0;
  unsigned int nbPort = 0;
  
  switch (type) {
    case 0: {devName = "/dev/uio1"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA; nbPort = DIO;} break; //DIO
    case 1: {devName = "/dev/uio1"; gpioTri = GPIO2_TRI; gpioData = GPIO2_DATA; nbPort = GPIO;} break; //GPIO
    case 2: {devName = "/dev/uio2"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA; nbPort = LED;} break; //FM191 LED
    case 3: {devName = "/dev/uio0"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA; nbPort = LED;} break; // EMC2 LED
    case 4: {devName = "/dev/uio0"; gpioTri = GPIO2_TRI; gpioData = GPIO2_DATA; nbPort = LED_PHY;} break; //ethernet LED
  }  
  
  SUN_GPIO gpio(devName, gpioTri, gpioData, nbPort);
  unsigned int read = 0;
  int err = gpio.transfer(read, port, data);
  if (err) {
    sprintf(err_msg, "%s (%d)\n", gpio.getError(), err);
    err_code = ERR_DIGITAL_WR_FAIL;
  } 
 
  return err;
}

int analog_read(unsigned int port, int &data) 
{
  err_code = ERR_OK;
  sprintf(err_msg, "No error\n");
  
  if (port>AI) {
    err_code = ERR_WRONG_PORT;
    sprintf(err_msg, "Wrong port number, the port number should be between 0 - %hd\n", AI-1);
    return err_code;
  }

  char portname[16];
  sprintf(portname, "/dev/ttyUL%d", (port/4)+1); //ttyULx devices are numbered from 1		
  UART_ADC uart(portname, B115200, 0, 0); // set speed to 115,200 bps, 8n1 (no parity), no blocking  
  
  unsigned int mux = ((port%4) + 1) & 0x3;
  uart.setReg0Value(1, mux); //gain 1																
  uart.setReg1Value(2, 0); // Analog supply (AVDD / AVSS) used as reference, single shot mode
  uart.setReg3Value(1); // automatic read mode

  int err = 0;
  err = uart.writeReg(0); if (err<0) {sprintf(err_msg, "\tWrite reg 0 failed (error %d)\n", err); err_code = ERR_ANALOG_RD_FAIL; return err_code;}
  err = uart.writeReg(1); if (err<0) {sprintf(err_msg, "\tWrite reg 1 failed (error %d)\n", err); err_code = ERR_ANALOG_RD_FAIL; return err_code;}
  err = uart.writeReg(3); if (err<0) {sprintf(err_msg, "\tWrite reg 3 failed (error %d)\n", err); err_code = ERR_ANALOG_RD_FAIL; return err_code;}

  uart.start();
  err = uart.readVal(data);
	if (err<0) {
		sprintf(err_msg, "\tRead value failed (error %d)\n", err); 
		err_code = ERR_ANALOG_RD_FAIL; 
		return err_code;
  }
  return err_code;
}

int analog_write(unsigned int port, float data) 
{	
  err_code = ERR_OK;
  sprintf(err_msg, "No error\n");
  
  if (port>AO) {
    err_code = ERR_WRONG_PORT;
    sprintf(err_msg, "Wrong port number, the port number should be between 0 - %hd\n", AO-1);
    return err_code;
  }

  unsigned int gain = 1;  // DAC default value
  unsigned int div = 1;   // DAC default value
  unsigned int n = 12;    // DAC resolution in bits
  float vref = 2.5;       // DAC reference voltage in volts
  float code = (data*div*pow(2,n))/(vref*gain);
  unsigned int value = (unsigned int)code;
  if (data>=2.5) value = 0xFFF;
	//printf("AO%d at %0.3fV (code 0x%x)\n", port, value, data);  
  
  // Access the SPI interface to write the DACs
  SPI_DAC spi("/dev/spidev1.0", SPI_CPOL, 8, 78000);
  int err = spi.writeData(DAC_TRIGGER_REG, 0xA);
  if (err<0) {
		sprintf(err_msg, "\tWrite to trigger register failed (error %d)\n", err); 
		err_code = ERR_ANALOG_WR_FAIL; 
		return err_code;
  }
  
  //	spi.writeData(DAC_TRIGGER_REG, 0x0);
  usleep(100000);
  
  err = spi.writeData(port+0x8, value);
  if (err<0) {
		sprintf(err_msg, "\tWrite value failed (error %d)\n", err); 
		err_code = ERR_ANALOG_WR_FAIL; 
		return err_code;
  }

  return ERR_OK;
}

char* getErrMsg()
{
  return err_msg;
}
