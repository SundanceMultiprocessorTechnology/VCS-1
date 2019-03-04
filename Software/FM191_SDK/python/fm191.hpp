#ifndef FM191_HPP_
#define FM191_HPP_

#define DIO         15
#define GPIO        28
#define LED         4
#define LED_PHY     2
#define NB_TYPE     5  // DIO 0 - GPIO 1 - LEDS 2
#define NB_TYPE_RD  2
#define AI          12
#define AO          8

int clean_stdin();
int test_gpio_read();
int test_gpio_write();
int test_gpio_write();
int test_dac(float value, unsigned int port);


#endif //FM191_HPP_
