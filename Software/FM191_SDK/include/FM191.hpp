#ifndef FM191_HPP_
#define FM191_HPP_

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
#define NB_TYPE     5  
#define NB_TYPE_RD  2	 
#define AI          12
#define AO          8

#define ERR_OK                (0)
#define ERR_WRONG_TYPE 	      (-1)
#define ERR_WRONG_PORT 	      (-2)
#define ERR_DIGITAL_RD_FAIL 	(-3)
#define ERR_DIGITAL_WR_FAIL 	(-4)
#define ERR_ANALOG_RD_FAIL 	  (-5)
#define ERR_ANALOG_WR_FAIL 	  (-6)


int digital_read(unsigned int type, unsigned int port, bool &data);
int digital_write(unsigned int type, unsigned int port, bool data);
int analog_read(unsigned int port, int &data);
int analog_write(unsigned int port, float data);
char* getErrMsg();


#endif //FM191_HPP_

