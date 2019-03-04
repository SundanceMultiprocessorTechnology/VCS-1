//======================================================================================//
// Name        : emc2-vs1.cpp															//
// Author      : Emilie Wheatley															//
// Version     : 1																	//
// Copyright   : 2018, Sundance Multiprocessor Technology Ltd. (c) All rights reserved	//
// Description : EMC2 interface for VS-1												//
//======================================================================================//

#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>	// For sleep
#include <atomic>
#include <chrono>
#include <cstring>
#include "mqtt/async_client.h"
#include "FM191.hpp"

#define VERSION 0.2
#define VERSION_DATE "10/05/2018"
#define DIFF "initial version"
#define AUTHOR "Emilie Wheatley"
#define CONTACT "emilie.w@sundance.com"
#define DESCRIPTION "FM191 linux SDK"
#define COPYRIGHT "2018, Sundance Multiprocessor Technology Ltd. (c) GNU v.3.0"

#define PORT "1883"
#define IP "127.0.0.1" //local

void test(void){
	FM191 fm191 (IP,PORT);
	fm191.startListening();
	while (std::tolower(std::cin.get()) != 'q'){}
	fm191.stopListening();
	fm191.~FM191();

}

int main(int argc, char* argv[]){
	cout<<"*************************************************************************"<<endl;
	cout<<"Copyright: "<< COPYRIGHT <<endl<<"Support contact: "<<AUTHOR<<", "<<CONTACT<<endl;
	cout<<"Version: "<< VERSION << ", "<<VERSION_DATE<< ", "<< DIFF <<endl;
	cout<<"*************************************************************************"<<endl;
	test();
}





