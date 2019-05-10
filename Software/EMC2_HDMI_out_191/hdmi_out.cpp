//======================================================================================//
// Name        : hdmi_out.cpp                             															//
// Author      : Emilie Wheatley													                           		//
// Version     : 1											                                    						//
// Copyright   : 2018, Sundance Multiprocessor Technology Ltd. (c) All rights reserved	//
// Description : EMC2 HDMI out configuration									                          //
//======================================================================================//

#include <iostream>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <errno.h>
#define I2C_ADDR 0x39

unsigned int i2c_ioctl_read (int fd, uint8_t addr)
{
  int ret;
  char buffer[1];
  char buffer_out[1];

  buffer[0] = 0;
  buffer_out[0] = addr;

  struct i2c_msg messages[2];
  messages[0].addr = I2C_ADDR;
  messages[0].buf = (__u8*)buffer_out;
  messages[0].len = 1;
  messages[0].flags=0;

  messages[1].addr = I2C_ADDR;
  messages[1].buf = (__u8*)buffer;
  messages[1].len = 1;
  messages[1].flags=I2C_M_RD;

  struct i2c_rdwr_ioctl_data payload;
  payload.msgs = messages;
  payload.nmsgs = 2;

  ret = ioctl(fd, I2C_RDWR, &payload);
  if (ret < 0) {
    ret = -errno;
    printf("READ Error payload %d\n", errno);
  }

  return (unsigned int)(buffer[0]);
}

int i2c_ioctl_write (int fd, uint8_t addr, uint8_t data)
{
  int ret;
  char buffer[2];
  unsigned long funcs;

  buffer[0] = addr;
  buffer[1] = data;

  if (ioctl(fd, I2C_FUNCS, &funcs) < 0) {
   printf("Error I2C_FUNCS\n");
  }

  struct i2c_msg messages[1];
  messages[0].addr = I2C_ADDR;
  messages[0].buf = (__u8*)buffer;
  messages[0].len = 2;
  messages[0].flags = 0;

  struct i2c_rdwr_ioctl_data payload[1];
  payload[0].msgs = messages;
  payload[0].nmsgs = 1;

  ret = ioctl(fd, I2C_RDWR, &payload);
  if (ret < 0) {
    ret = -errno;
    printf("Error payload %d\n", errno);
  }

    return ret;
}
       
int main (void) 
{
 int fd;

  // ADV7511 (HDMI out)  
  fd = open("/dev/i2c-2", O_RDWR);

  if (fd < 0) {
      printf("Error opening file: %s\n", strerror(errno));
      return 1;
  }

  if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
      printf("ioctl error: %s\n", strerror(errno));
      return 1;
  }

  // Initialise ADV7511
  int HotPlugDetect = (i2c_ioctl_read(fd,  0x42) >> 6) & 0x1;

  for (;;) {
    // wait until a monitor is connected
    while(!HotPlugDetect) {
    	HotPlugDetect = (i2c_ioctl_read(fd,  0x42) >> 6) & 0x1;
    }

	  // Power up AD7511
	  i2c_ioctl_write(fd,  0x41, 0x10);

    // Waiting for the ADV7511 to power up and initialise properly  
    unsigned int monitor_detected, pll_locked, vsync_detected, status;

    while (status!=0xe41202) {
	    monitor_detected = i2c_ioctl_read(fd,  0xc8);
	    pll_locked = i2c_ioctl_read(fd,  0x9e);
	    vsync_detected = i2c_ioctl_read(fd,  0x96);
	    status = (vsync_detected<<16)|(pll_locked<<8)|(monitor_detected);//printf("0x%x\n", data); 
    }
    sleep(3);
	  
	  unsigned int vic  = i2c_ioctl_read(fd,  0x3e);
	  if (vic == 0) printf("VIC unavailable\n");


    // Configure ADV7511	

	  i2c_ioctl_write(fd,  0x98, 0x03); // FIXED 0x03
	  i2c_ioctl_write(fd,  0x9A, 0xE0); // FIXED 0xE0
	  i2c_ioctl_write(fd,  0x9C, 0x30); // FIXED 0x30 PLL
	  i2c_ioctl_write(fd,  0x9D, 0x61); // xxxx_xx01 CLK Div
	  i2c_ioctl_write(fd,  0xA2, 0xA4); // FIXED
	  i2c_ioctl_write(fd,  0xA3, 0xA4); // FIXED
	  i2c_ioctl_write(fd,  0xE0, 0xD0); // FIXED
	  i2c_ioctl_write(fd,  0xF9, 0x00);
	  i2c_ioctl_write(fd,  0xFF, 0xFF);

	  i2c_ioctl_write(fd,  0x15, 0x05); // ID 5
	                                    // xxxx_xx1x first on rising
	                                    // xxxx_01xx style 01 => 2, 10 => 1, 11 => 3
	                                    // xx11_xxxx color depth 8
	  i2c_ioctl_write(fd,  0x16, 0x38); // 8, style 1, falling
	  i2c_ioctl_write(fd,  0x48, 0x08); // align right, right justified, DDR low bits, normal bus order
	  i2c_ioctl_write(fd,  0x55, 0x12); // AVI AVI valid, RGB, PC
	  i2c_ioctl_write(fd,  0x56, 0x28); //
	  i2c_ioctl_write(fd,  0x17, 0x00); // DE gen disabled, aspec 4:3
	  i2c_ioctl_write(fd,  0xBA, 0x60); // - 0.8ns
	  i2c_ioctl_write(fd,  0xD0, 0x8C); // inv clk ?
	  i2c_ioctl_write(fd,  0xAF, 0x04); // no HDCP

	  // Conversion matrix IN=OUT
	  i2c_ioctl_write(fd,  0x18, 0xA8);
	  i2c_ioctl_write(fd,  0x19, 0x00);
	  i2c_ioctl_write(fd,  0x1A, 0x00);
	  i2c_ioctl_write(fd,  0x1B, 0x00);
	  i2c_ioctl_write(fd,  0x1C, 0x00);
	  i2c_ioctl_write(fd,  0x1D, 0x00);
	  i2c_ioctl_write(fd,  0x1E, 0x00);
	  i2c_ioctl_write(fd,  0x1F, 0x00);
	  i2c_ioctl_write(fd,  0x20, 0x00);
	  i2c_ioctl_write(fd,  0x21, 0x00);
	  i2c_ioctl_write(fd,  0x22, 0x08);
	  i2c_ioctl_write(fd,  0x23, 0x00);
	  i2c_ioctl_write(fd,  0x24, 0x00);
	  i2c_ioctl_write(fd,  0x25, 0x00);
	  i2c_ioctl_write(fd,  0x26, 0x00);
	  i2c_ioctl_write(fd,  0x27, 0x00);
	  i2c_ioctl_write(fd,  0x28, 0x00);
	  i2c_ioctl_write(fd,  0x29, 0x00);
	  i2c_ioctl_write(fd,  0x2A, 0x00);
	  i2c_ioctl_write(fd,  0x2B, 0x00);
	  i2c_ioctl_write(fd,  0x2C, 0x08);
	  i2c_ioctl_write(fd,  0x2D, 0x00);
	  i2c_ioctl_write(fd,  0x2E, 0x00);
	  i2c_ioctl_write(fd,  0x2F, 0x00);
    // ------------------------

  // wait until the monitor is disconnected
    while(HotPlugDetect) {
    	HotPlugDetect = (i2c_ioctl_read(fd,  0x42) >> 6) & 0x1;
    }
  }
  
  close(fd);
	printf("HDMI configuration Done\r\n");

	return 0;
}

