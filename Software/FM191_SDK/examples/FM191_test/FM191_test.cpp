#include "FM191.hpp"

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

int test_gpio_read()
{
  bool data = 0;
  unsigned int port = 0;
  unsigned int type = 0;
  unsigned int type_size = 0;
  std::string s = "";

  printf("Reading all the DIOs and GPIOs\n");

  for (type=0; type<NB_TYPE_RD; type++)  {
    switch (type) {
      case 0: {type_size=DIO; s = "DIO"; }break;
      case 1: {type_size=GPIO; s = "GPIO"; }break;
    }

    for (port=0; port<type_size; port++) {
      digital_read(type, port, data);
      printf("%s%d:\t%d\n", s.c_str(), port, data);
    }    
  }

  printf("DIOs and GPIOs read test done\n");

  return 0;

}

int test_gpio_write()
{
  bool data = 0;
  unsigned int port = 0;
  unsigned int type = 0;
  unsigned int type_size = 0;

  printf("Set all the DIOs, GPIOs and LEDs to 0\n");

  for (type=0; type<NB_TYPE; type++)  {
    switch (type) {
      case 0: type_size=DIO; break;
      case 1: type_size=GPIO; break;
      case 2: type_size=LED; break; // module LEDs (FM191)
      case 3: type_size=LED; break; // carrier LEDs (EMC2)
      case 4: type_size=LED_PHY; break;
    }

    for (port=0; port<type_size; port++) {
      int err = digital_write(type, port, data);
      if (err<0) printf("ERROR %d %s\n", err, getErrMsg());
    }
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
      int err = digital_write(type, port, data);      
      if (err<0) printf("ERROR %d %s\n", err, getErrMsg());
      data = 0;
      if (port>0) {
        err = digital_write(type, port-1, data);
        if (err<0) printf("ERROR %d %s\n", err, getErrMsg());
      }
      usleep(500000);
    }
  } 

  printf("DIOs, GPIOs and LEDs  test done\n");

  return 0;

}

int test_adc(unsigned int port) 
{
  int data = 0;
  for (int j=0; j<30; j++) {
    int err = analog_read(port, data);
  	if (err<0) {
  		printf("ERROR %d %s\n", err, getErrMsg());
  	} else {
  		if (data>0x7FFFFF) {
  			float f = (float)((float)((data-0x800000)*5)/0x7FFFFF);
  			printf("AI%d:\t%0.3fV (raw value: 0x%x)\n", port, f-5.0, data);
  		} else {
   			printf("AI%d:\t%0.3fV (raw value : 0x%x)\n", port, (float)((float)(data*5)/0x7FFFFF), data);
  		}
  	}
  	sleep(1);
  }
  return 0;
}

int test_dac(float value, unsigned int port) 
{	
  int err = analog_write(port, value);
  printf("ERROR %d %s\n", err, getErrMsg());
  
  return 0;
}

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
}
