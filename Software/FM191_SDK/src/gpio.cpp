#include "gpio.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>


SUN_GPIO::SUN_GPIO(const char *devname, unsigned int gpioTri, unsigned int gpioData, unsigned int nbPort):
  err_code(ERR_GPIO_OK), gpioTri(gpioTri), gpioData(gpioData), devName(devname), nbPort(nbPort)
{  
  sprintf(err_msg, "no error\n");
}

SUN_GPIO::~SUN_GPIO() 
{
}

//////////////////////////////////////////////////////////////////////////////////
// gpioAccess: read or write data to the GPIO pins
//
// parameters:
// pin: GPIO pin number
// read: 0 -> write data (output), 1 -> read data (input)
// gpio: 0 -> dio selected, 1-> gpio selected, 2 -> leds selected
// data: data read or data to write depending on the value of the parameter read
//////////////////////////////////////////////////////////////////////////////////
 
int SUN_GPIO::transfer(bool read, unsigned int pin, bool &data)
{
  if (pin>=nbPort) {
    err_code = ERR_GPIO_WRONG_PORT;
    sprintf(err_msg, "Wrong port, there are %d DIOs\n", nbPort);
    return err_code;
  }
	
  /* Open the UIO device file */
  int fd = open(devName, O_RDWR);
  if (fd < 1) {
    err_code = ERR_GPIO_NO_DEV_FILE;
    sprintf(err_msg, "Invalid UIO device file: %s\n", devName);
    return err_code;
  }
 
 /* mmap the UIO devices */
  int pgsize = getpagesize();
  void *ptr_axi_gpio = mmap(NULL, pgsize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  if (ptr_axi_gpio==MAP_FAILED) {
    err_code = ERR_GPIO_MMAP;
    sprintf(err_msg, "Can't map GPIO (error %d)\n", errno);
    close(fd);
    return err_code;
  }

  uint32_t *ptr = (uint32_t *)(ptr_axi_gpio);
  unsigned int value;
  
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
  
  return ERR_GPIO_OK;
}

char* SUN_GPIO::getError()
{
  return err_msg;
}
