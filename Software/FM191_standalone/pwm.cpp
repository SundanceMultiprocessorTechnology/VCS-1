/**
* ==================================================================
\file pwm.cpp						       
\author Pedro Machado <pedro.m@sundance.com>			               
\version 0.1								
\copyright 2018, Sundance Multiprocessor Technology Ltd. (c) GPLv3                 
\brief FM191 source file               
* ==================================================================
*/

#include"pwm.hpp"
#include <chrono>
#include <iostream>

/**
 * Class constructor
 */
pwm::pwm(int frequency, int scale){
	pwm::frequency= frequency;
        pwm::scale = scale;
	std::cout<<"PWM module initialised with SUCCESS."<<std::endl;
}


/**
 * Generate a PWM as per described in https://www.arduino.cc/en/Tutorial/PWM
 */
void pwm::generate_pwm(int port, int type, int value, int duration){
 // duration in clock cycles
    float time_period=1./pwm::frequency;
    float time_on=float(value)/float(scale)*1000.; //in ms
    float time_off=(1.-float(value)/float(scale))*1000.; //in ms
    std::chrono::high_resolution_clock::time_point now,start;
    for(int i=0;i<duration;++i){
        std::cout<<"Port "<< port<<" set to TRUE!"<<std::endl;
        start = std::chrono::high_resolution_clock::now();
        now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms = now - start;
        while(elapsed_ms.count()<time_on){
            //set port <pot> of type <type> to "1"
        }
        std::cout<<"Port "<< port<<" set to FALSE!"<<std::endl;
        start = std::chrono::high_resolution_clock::now();
        now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms2 = now - start;
        while(elapsed_ms2.count()<time_off){
            //set port <pot> of type <type> to "0"
        }
    }
}

/**
 * Class destructor
 */
pwm::~pwm(){
	std::cout<<"PWM module deleted with SUCCESS!"<<std::endl;
}
