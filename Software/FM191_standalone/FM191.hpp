//======================================================================================//
// Name        : FM191.hpp																//
// Author      : Pedro Machado															//
// Version     : 0.1																	//
// Copyright   : 2018, Sundance Multiprocessor Technology Ltd. (c) All rights reserved	//
// Description : FM191 module															//
//======================================================================================//




#ifndef FM191_HPP_
#define FM191_HPP_

#define TRACE 0

#include<iostream>
#include "uart.hpp"
#include "gpio.hpp"
#include "spi.hpp"
#include "pwm.hpp"

#define dbg(format, arg...) if (TRACE) printf("DGB: " format "\n" , ## arg)

using namespace std;
class FM191
{
	public:
		FM191(std::string ip, std::string port);
		~FM191();
		void startListening();
		void stopListening();
		int processCommand(std::string msg_cmd, std::string* msg_res, std::string* msg_err, std::string* topic);
		
			
		int getPorts(int type);
		
		
	private:
		const static unsigned int DIO=15;
		const static unsigned int GPIO=28;
		const static unsigned int LED=4;
		const static unsigned int AI=12;
		const static unsigned int AO=8;
		const static unsigned int DIGITAL_WRITE=1;
		const static unsigned int DIGITAL_READ=2;
		const static unsigned int ANALOG_WRITE=3;
		const static unsigned int ANALOG_READ=4;
		const static unsigned int DIGITAL_PORT_SETUP=5;
		const static unsigned int DIGITAL_RESULTS=6;
		const static unsigned int ANALOG_RESULTS=7;
		const static unsigned int DIGITAL_ERRORS=9;
		const static unsigned int ANALOG_ERRORS=10;
		const static unsigned int DIGITAL_PORT_SETUP_ERRORS=11;
		const static unsigned int PWMSETUP=12;
    const static unsigned int PWMSETUP_ERRORS=13;
    const static unsigned int PWM=13;
    const static unsigned int PWM_ERRORS=14;
		const std::string TOPICS[5]={"/FM191/messages",
				"/FM191/digital/results",
				"/FM191/analog/results",
				"/FM191/digitalportssetup/results",
        "/FM191/pwm/results"};
				
		std::string server;
		std::string client_id;			
			
		bool LED_state[4];
		int pwm_frequency;
		int pwm_scale;
		
		int digitalWrite(unsigned int port, int type, bool &value, std::string* result, std::string* error); //0 - DIOs and 1 GPIOs
		int digitalRead(unsigned int port, int type, std::string* value, std::string* result, std::string* error);
		int analogWrite(unsigned int port, float &value, std::string* result, std::string* error);
		int analogRead(unsigned int port, std::string* result, std::string* error);
		int digitalPortsSetup(bool DIO_state[DIO], bool GPIO_state[GPIO], std::string* result, std::string* error);
		int pwmSetup(int frequency, int scale, std::string* result, std::string* error);		
		int pwm_(int port, int type, int value, int duration, std::string* result, std::string* error);
};




#endif /* FM191_HPP_ */
