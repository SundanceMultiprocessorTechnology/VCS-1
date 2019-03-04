#include "uart.hpp"
#include "gpio.hpp"
#include "spi.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <math.h>
#include <unistd.h>
#include <termios.h>

#define DIO         15
#define GPIO        28
#define LED         4
#define LED_PHY     2
#define NB_TYPE     5  // DIO 0 - GPIO 1 - LEDS 2
#define NB_TYPE_RD  2
#define AI          12
#define AO          8

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

int test_gpio_read()
{
  bool read = 1; // reading
  bool data = 0;
  unsigned int port = 0;
  unsigned int type = 0;
  unsigned int type_size = 0;
  std::string s = "";

  printf("Reading all the DIOs and GPIOs\n");
  data = 0;

  for (type=0; type<NB_TYPE_RD; type++)  {
    switch (type) {
      case 0: {type_size=DIO; s = "DIO"; }break;
      case 1: {type_size=GPIO; s = "GPIO"; }break;
    }

    for (port=0; port<type_size; port++) {
      gpioAccess(port, read, type, data);
      printf("%s%d:\t%d\n", s.c_str(), port, data);
    }
    
  }

  printf("DIOs and GPIOs read test done\n");

  return 0;

}

int test_gpio_write()
{
  bool read = 0; // writing
  bool data = 0;
  unsigned int port = 0;
  unsigned int type = 0;
  unsigned int type_size = 0;

  printf("Set all the DIOs, GPIOs and LEDs to 0\n");
  data = 0;

  for (type=0; type<NB_TYPE; type++)  {
    switch (type) {
      case 0: type_size=DIO; break;
      case 1: type_size=GPIO; break;
      case 2: type_size=LED; break; // module LEDs (FM191)
      case 3: type_size=LED; break; // carrier LEDs (EMC2)
      case 4: type_size=LED_PHY; break;
    }

    for (port=0; port<type_size; port++) gpioAccess(port, read, type, data);
  }


  printf("Starting test for the DIOs, GPIOs, FM191_LEDS, EMC2_LEDS, EMC2_PHY_LEDS\n");
  for (type=0; type<NB_TYPE; type++)  {
    switch (type) {
      case 0: type_size=DIO; break;
      case 1: type_size=GPIO; break;
      case 2: type_size=LED; break; // module LEDs (FM191)
      case 3: type_size=LED; break; // carrier LEDs (EMC2)
      case 4: type_size=LED_PHY; break;
    }

    for (port=0; port<type_size; port++) {
      data = 1;
      gpioAccess(port, read, type, data);
      data = 0;
      if (port>0) gpioAccess(port-1, read, type, data);
      usleep(500000);
    }
  } 

  printf("DIOs, GPIOs and LEDs  test done\n");

  return 0;

}

int test_adc(unsigned int port) 
{
  if (port>AI) printf("!!!Wrong port number, the port number should be between 0 - %hd\n", AI-1);

  char portname[16];
  sprintf(portname, "/dev/ttyUL%d", (port/4)+1); //ttyULx devices are numbered from 1		
  UART_ADC uart(portname, B115200, 0, 0); // set speed to 115,200 bps, 8n1 (no parity), no blocking  
  unsigned int mux = ((port%4) + 1) & 0x3;
  uart.setReg0Value(1, mux); //gain 1
  //printf("UART %d\n",port%4);																				
  uart.setReg1Value(2, 0); // Analog supply (AVDD / AVSS) used as reference, single shot mode

  uart.setReg3Value(1); // automatic read mode

  int err = 0;
  err = uart.writeReg(0); if (err<0) printf("\tWrite reg 0 failed (error %d)\n", err);
  err = uart.writeReg(1); if (err<0) printf("\tWrite reg 1 failed (error %d)\n", err);
  err = uart.writeReg(3); if (err<0) printf("\tWrite reg 3 failed (error %d)\n", err);

  /*char res =0;
  char reg = 0;
	  
  for (int j=0; j<5; j++) {
	  err = uart.readReg(j, &res);
	  if (err<0) printf("\tFailed to read register %d (error %d)\n", j, err);
	  else printf("\tRead reg %d: 0x%x\n", j, res);
	  if ((reg=uart.getRegValue(j)) != res) printf("\t!!!ERROR: expected 0x%x but register %d = 0x%x\n", reg, j, res);
  }*/
  int val = 0;
for (int j=0; j<30; j++) {
  uart.start();
  err = uart.readVal(val);
	if (err<0) {
		printf("Read value failed\n");
	} else {
		if (val>0x7FFFFF) {
			float f = (float)((float)((val-0x800000)*5)/0x7FFFFF);
			printf("AI%d:\t%0.3fV (raw value: 0x%x)\n", port, f-5.0, val);
		} else {
 			printf("AI%d:\t%0.3fV (raw value : 0x%x)\n", port, (float)((float)(val*5)/0x7FFFFF), val);
		}
	}
	sleep(1);
}
  return 0;
}

int test_dac(float value, unsigned int port) 
{	
  unsigned int gain = 1; // DAC default value
  unsigned int div = 1; // DAC default value
  unsigned int n = 12; // DAC resolution in bits
  float vref = 2.5; // DAC reference voltage in volts
  float code = (value*div*pow(2,n))/(vref*gain);
  unsigned int data = (unsigned int)code;
  if (value>=2.5) data = 0xFFF;
	printf("AO%d at %0.3fV (code 0x%x)\n", port, value, data);
  if (port < AO){
    // Access the SPI interface to write the DACs
    SPI_DAC spi("/dev/spidev1.0", SPI_CPOL, 8, 78000);
	spi.writeData(DAC_TRIGGER_REG, 0xA);
//	spi.writeData(DAC_TRIGGER_REG, 0x0);
	usleep(100000);
 	spi.writeData(port+0x8, data);
  } else {
    printf("!!!Wrong port number, the port number should be between 0 - %d\n", AO-1);
  }

  return 0;
}

/*

int main()
{
  unsigned int n = 99;

  for (;;) {
    // Menu
    printf("\n");
	printf("#########################################\r\n");
	printf("##############  FM191 tests  ############\r\n");
	printf("#########################################\r\n");

    printf("1- DIOs, GPIOs and LEDs write test\n");
    printf("2- DIOs and GPIOs read test\n");
    printf("3- DAC test\n");
    printf("4- ADC test\n");
    printf("99- Exit testing\n");
    printf("Enter your selection:\n");
    int scan = scanf("%d", &n);
	  if (scan!=1) { n=0;clean_stdin();}
    printf("\n");

    switch (n) {
      case 1: {
        printf("Starting the DIOs, GPIOs and LEDs write test\n");
        test_gpio_write();
      } break;

    case 2: {
        printf("Starting the DIOs and GPIOs read test\n");
        test_gpio_read();
      } break;

      case 3: {
        printf("Starting the DAC test\n");
        unsigned int port = 0;
        float value = 0.0;
        for (;;) {
          printf("Enter the port number (0-7) or 99 to exit the DAC test:\n"); 
		      unsigned int scan = scanf("%d", &port);
		      if (port==99) break;
		      if ((scan!=1) || (port>7)) {
			      printf("Wrong value!\n");
			      port = 0;
			      clean_stdin();
			      continue;
		      }
          printf("Enter the output voltage (0-2.5V):\n"); 
		      scan = scanf("%f", &value);
		      if ((scan!=1) || (value>2.5)) {
			      printf("Wrong value!\n"); 
			      value = 0;
			      clean_stdin(); 
			      continue;
		      }
          test_dac(value, port);
          printf("\n");
        }
      } break;

      case 4: {
        printf("Starting the ADC test\n");
        unsigned int port = 0;
        for (;;) {
          printf("Enter the port number (0-11) or 99 to exit the ADC test:\n");
		      unsigned int scan =  scanf("%d", &port);
          if (port==99) break;
		      if ((scan!=1) || (port>11)) {
			      printf("Wrong value!\n");
			      port = 0;
			      clean_stdin();
			      continue;
		      } 
          test_adc(port);
          printf("\n");
        }
        
      } break;      

      case 99: printf("Exit testing ...\n"); return 0;

	default: printf("!!!Wrong selection!!!\n"); break;
    }
  }
} */
