#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <time.h>

#include "../gpio.hpp"

int main()
{
  unsigned int pin = 8;
  bool read = 1;
  unsigned int gpio = 0;
  bool data = 0;
  int type = 0;
  int value = 0;

  for (int i=1; i<15; i++) {
    gpioAccess(i, read, 0, data);
  }

  for (int i=0; i<28; i++) {
    gpioAccess(i, read, 1, data);
  }

  for (int i=0; i<4; i++) {
    gpioAccess(i, read, type, data);
  }
  read = 0;
  gpioAccess(0,read,0,data);

  for (;;) {
    printf("\n\nSelect type:\n");
    printf("0- DIO\n");
    printf("1- GPIO\n"); 
    printf("2- LEDS\n");
    scanf("%d",&type);
  
    printf("Enter pin number:\n");
    scanf("%d",&pin);

    printf("Enter value:");
    scanf("%d", &value);
    data = (bool)value;

    printf("Writing %d to pin%d on type %d\n", data, pin, type);
    read = 0;
    gpioAccess(pin, read, type, data);
    usleep(100000);
    read = 1;
    gpioAccess(pin+1, read, type, data);
    printf("Reading %d from pin %d on type %d\n", data, pin+1, type);
  }
/*for (;;) {
	for (pin=0; pin<15; pin++) {
		gpioAccess(pin, read, 0, data);
	}
	if (data) data = 0;
	else data = 1;
	sleep(4);
}*/

/*
  printf("Select the test to run:\n");
  printf("0- DIOs\n");
  printf("1- GPIOs\n");
  printf("2- LEDs\n");
  int n = 0;
  scanf("%d",&n);

  switch(n) {
   case 0: {
    printf("DIO TEST\n");
    gpio = 0;
    read = 1;
    for (int i=0; i<15; i++) {
	gpioAccess(i, read, gpio, data);
	printf("Read DIO%d: %d\n",i, data);
    }

    for (int i=0; i<15; i++) {
	data = 1; read = 0;
	gpioAccess(i, read, gpio, data);
	read = 1;
	gpioAccess(i, read, gpio, data);
	if (!data) printf("!!!ERROR ");
	printf("Write 1-Read DIO%d: %d\n", i, data);
	data = 0; read = 0;
	gpioAccess(i, read, gpio, data);
	read = 1;
	gpioAccess(i, read, gpio, data);
	if (data) printf("!!!ERROR ");
        printf("Write 0-Read DIO%d: %d\n", i, data);
    }
   } break;

   case 1: {
    printf("GPIO TEST");
    gpio = 1;
    read = 1;
    for (int i=0; i<28; i++) {
	gpioAccess(i, read, gpio, data);
	printf("Read GPIO%d: %d\n",i, data);
    }

    for (int i=0; i<28; i++) {
	data = 1; read = 0;
	gpioAccess(i, read, gpio, data);
	read = 1;
	gpioAccess(i, read, gpio, data);
	if (!data) printf("!!!ERROR ");
        printf("Write 1-Read GPIO%d: %d\n", i, data);
	data = 0; read = 0;
	gpioAccess(i, read, gpio, data);
	read = 1;
	gpioAccess(i, read, gpio, data);
	if (data) printf("!!!ERROR ");
        printf("Write 0-Read GPIO%d: %d\n", i, data);
    }

   } break;

   case 2: {
    printf("LED TEST\n");
    gpio = 2;
    for (;;) {
	for (int i=0; i<4; i++) {
		gpioAccess(i, read, gpio, data);
		sleep(1);
	}
	data = (data) ? 0 : 1;
    }
   } break;
  
   default: printf("Wrong selection\n");
  }

*/
  return 0;
} 
