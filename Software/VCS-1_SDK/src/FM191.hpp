/**
* ==================================================================
\file FM191.cpp						       
\author Pedro Machado <pedro.m@sundance.com>			               
\version 0.1								
\copyright 2018, Sundance Multiprocessor Technology Ltd. (c) GPLv3                 
\brief FM191 header file               
* ==================================================================
*/


// include files
#include<iostream>

// macros defenition
#ifndef FM191_HPP_
#define FM191_HPP_

using namespace std;
class FM191
{
	public:
		FM191(std::string ip, std::string port);
		~FM191();
		int getPorts(int type);
		int digitalWrite(int port, int type, int value, std::string* error_code); //0 - DIOs and 1 GPIOs
		int digitalRead(int port, int type, std::string* value, std::string* error_code);
		int analogWrite(int port, float value, std::string* error_code);
		int analogRead(int port, std::string* value, std::string* error_code);
		int setupDigitalPorts(int* dios, int* gpios, std::string* value, std::string* error_code);
                void getDigitalPortsStatus(int* dios, int* gpios);
                int setupPwm(int frequency, int scale, std::string* error_code);
                int pwm(int port, int type, int value, int duration, std::string* error_code);
	private:
		const int DIO=15;
		const int GPIO=28;
                const int LED=4;
		const int AI=12;
		const int AO=8;
		const int DIGITAL_WRITE=1;
		const int DIGITAL_READ=2;
		const int ANALOG_WRITE=3;
		const int ANALOG_READ=4;
		const int DIGPORTSETUP_SETUP=5;
		const int DIGITAL_RESULTS=6;
		const int ANALOG_RESULTS=7;
		const int DIGITAL_ERRORS=9;
		const int ANALOG_ERRORS=10;
		const int DIGPORTSETUP_ERRORS=11;
                const int PWMSETUP=12;
                const int PWMSETUP_ERRORS=13;
                const int PWM=13;
                const int PWM_ERRORS=14;
                bool digital_ports_setup=false;
                bool pwm_setup=false;
                int gpioLut [28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int dioLut [15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		const std::string TOPICS[5]={"/FM191/messages",
				"/FM191/digital/results",
				"/FM191/analog/results",
				"/FM191/digitalportssetup/results",
                                "/FM191/pwm/results"
                };
		std::string server;
		std::string client_id;
};




#endif /* FM191_HPP_ */
