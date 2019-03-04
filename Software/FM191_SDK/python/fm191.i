/* fm191.i */
%module fm191
 %{
 /* Put header files here or function declarations like below */
#include "fm191.hpp"
extern int clean_stdin();
extern int test_gpio_read();
extern int test_gpio_write();
extern int test_gpio_write();
extern int test_dac(float value, unsigned int port);
%}

%include "fm191.hpp"
extern int clean_stdin();
extern int test_gpio_read();
extern int test_gpio_write();
extern int test_gpio_write();
extern int test_dac(float value, unsigned int port);
