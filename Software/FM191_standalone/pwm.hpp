/**
* ==================================================================
\file pwm.hpp						       
\author Pedro Machado <pedro.m@sundance.com>			               
\version 0.1								
\copyright 2018, Sundance Multiprocessor Technology Ltd. (c) GPLv3                 
\brief FM191 source file               
* ==================================================================
*/



#include<iostream>

#ifndef pwm_HPP_
#define pwm_HPP_

using namespace std;
class pwm
{
	public:
		pwm(int frequency, int scale); // constructor
		~pwm(); // destructor
		void generate_pwm(int port, int type, int value, int duration); // value in the range of [0,scale] duration in clock cycles
		
	private:
                int frequency;
                int scale;
};




#endif /* PWM_HPP_ */
