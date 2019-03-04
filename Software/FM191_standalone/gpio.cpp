#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include "gpio.hpp"

#define GPIO_ADDR 0x41210000

#define GPIO_DATA    0x0 // 0x0000    // Channel 1 AXI GPIO Data Register.
#define GPIO_TRI     0x1 // 0x0004    // Channel 1 AXI GPIO 3-state Control Register.
#define GPIO2_DATA   0x2 // 0x0008    // Channel 2 AXI GPIO Data Register.
#define GPIO2_TRI    0x3 // 0x000C    // Channel 2 AXI GPIO 3-state Control.
#define GIER         0x011C    // Global Interrupt Enable Register.
#define IP_IER       0x0128    // IP Interrupt Enable Register (IP IER).
#define IP_ISR       0x0120    // IP Interrupt Status Register.


//////////////////////////////////////////////////////////////////////////////////
// gpioAccess: read or write data to the GPIO pins
//
// parameters:
// pin: GPIO pin number
// read: 0 -> write data (output), 1 -> read data (input)
// gpio: 0 -> dio selected, 1-> gpio selected, 2 -> leds selected
// data: data read or data to write depending on the value of the parameter read
//////////////////////////////////////////////////////////////////////////////////
 
int gpioAccess(unsigned int pin, bool read, unsigned int gpio, bool &data)
{
 unsigned int value;
 unsigned int gpioTri = GPIO_TRI; 
 unsigned int gpioData = GPIO_DATA;
 const char *devName = "/dev/uio0";
  
 switch (gpio) {
	case 0: {devName = "/dev/uio1"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA;} break;
	case 1: {devName = "/dev/uio1"; gpioTri = GPIO2_TRI; gpioData = GPIO2_DATA;} break;
	case 2: {devName = "/dev/uio2"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA;} break;
	case 3: {devName = "/dev/uio0"; gpioTri = GPIO_TRI; gpioData = GPIO_DATA;} break;
	case 4: {devName = "/dev/uio0"; gpioTri = GPIO2_TRI; gpioData = GPIO2_DATA;} break;
 }

 /* Open the UIO device file */
 int fd = open(devName, O_RDWR);
 if (fd < 1) {
  printf("Invalid UIO device file: %s\n", devName);
  return -1;
 }


 /* mmap the UIO devices */
 int pgsize = getpagesize();
 void *ptr_axi_gpio = mmap(NULL, pgsize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
 if (ptr_axi_gpio==MAP_FAILED) {
        printf("Can't map GPIO (error %d)\n", errno);
        return -2;
 }

 uint32_t *ptr = (uint32_t *)(ptr_axi_gpio);
 
 /* AXI GPIO configuration */
 if (read) {
  ptr[gpioTri] |= 1UL<<pin;
  value = ptr[gpioData];	
  data = (value>>pin)&0x1;
 } else {
  ptr[gpioTri] &= ~(1UL<<pin);
  if (data) { //set bit
   ptr[gpioData] |= 1UL << pin;
  } else { //clear bit
   ptr[gpioData] &= ~(1UL << pin);
  }
 }

/* AXI GPIO configuration */
/* if (read) {
  *((volatile unsigned long*)(ptr_axi_gpio + gpioTri)) |= 1UL<<pin;
  value = *((volatile unsigned long *)(ptr_axi_gpio + gpioData));	
  data = (value>>pin)&0x1;
 } else {
  *((volatile unsigned long*)(ptr_axi_gpio + gpioTri)) &= ~(1UL<<pin);
  if (data) { //set bit
   *((volatile unsigned long*)(ptr_axi_gpio + gpioData)) |= 1UL << pin;
  } else { //clear bit
   *((volatile unsigned long *)(ptr_axi_gpio + gpioData)) &= ~(1UL << pin);
  }
 }
*/

  munmap(ptr_axi_gpio, pgsize);
  close(fd);
 
  return 0;
}

