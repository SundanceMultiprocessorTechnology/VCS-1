/**
* ==================================================================
\file emc2-vs2.cpp						       
\author Pedro Machado <pedro.m@sundance.com>			               
\version 0.1								
\copyright 2018, Sundance Multiprocessor Technology Ltd. (c) GPLv3                 
\brief Interface between any external device and the EMC2-Zxxx-FM191               
* ==================================================================
*/

// include section
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>	
#include <atomic>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstring>
#include "mqtt/async_client.h"
#include "FM191.hpp"

// Define section
#define VERSION 0.1
#define VERSION_DATE "01/04/2018"
#define DIFF "initial version"
#define AUTHOR "Pedro Machado"
#define CONTACT "pedro.m@sundance.com"
#define DESCRIPTION "FM191 Microsoft Windows SDK"
#define COPYRIGHT "2018, Sundance Multiprocessor Technology Ltd. (c) GNU v.3.0"
#define PORT "1883"
//#define IP "emc2"
//#define IP "192.168.0.5" //home
#define IP "192.128.64.190" //Sundance
//#define IP "127.0.0.1" // localhost

using namespace std;

void menu(void){
	cout<<"*******************\nOptions menu v1.0\n*******************"<< endl;
	cout<<"Please enter one of the following options:"<<endl;
	cout<<"1: Run test AT-ATDS1. Setup Digital ports!"<<endl;
	cout<<"2: Run test AT-AR1. Get 12 readings from the 12 Analogue ports!"<<endl;
	cout<<"3: Run test AT-DR1. Get 24 readings from 24 different Digital ports!"<<endl;
	cout<<"4: Run test AT-AW1. Write 8 analogue values to the 8 Analogue output ports!"<<endl;
	cout<<"5: Run test AT-DW1. Write 20 Boolean values to 20 different Digital ports!"<<endl;
        cout<<"6: Run test blink. Runs blink 20 times with an interval of 1s!"<<endl;
        cout<<"7: Run test AT-ATDGS1. Get the Digital Ports States!"<<endl;
        cout<<"8: Run pwm setup!"<<endl;
        cout<<"9: Send a pwm value!"<<endl;
	cout<<"q or Q: Quit the test program!"<<endl;
	cout<<"your option: "<<endl;
}
// test function
/**
 * Test function for testing all the FM191 methods.
@return void
@param void 
*/
void test(void){
	int result=0, menuFlag=true;
	char choice;
	FM191 fm191 (IP,PORT);
	std::string value,error_code;
	std::chrono::high_resolution_clock::time_point now,start;

	while (menuFlag==true){
		menu();
		cin>>choice;
		switch (choice)	{
			case '1':
			{
                            cout << "AT-ATDS1 - Setup Digital ports started.\n"<<endl;
                            int res1=0, res2=0, pt=0, val=0;
                            int gpios[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                            int dios[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                            cout<<"How many DIOs [0..14] would you like to define?"<<endl;
                            cin>>res1;
                            cout<<endl<<"How many GPIOS [0..27] would you like to define?"<<endl;
                            cin>>res2;
                            cout<<endl;
                            for(int i=0;i<res1;++i){
                                    cout<<endl<<"What is the DIO port number [0..14]!"<<endl;
                                    cin>>pt;
                                    cout<<endl<<"What is the DIO"<<pt<<" value [0 or 1]?"<<endl;
                                    cin>>val;
                                    dios[pt]=val;
                            }
                            for(int i=0;i<res2;++i){
                                    cout<<endl<<"What is the GPIO port number[0..27]!"<<endl;
                                    cin>>pt;
                                    cout<<endl<<"What is the GPIO"<<pt<<" value [0 or 1] ?"<<endl;
                                    cin>>val;
                                    gpios[pt]=val;
                            }
                            result=fm191.setupDigitalPorts(dios,gpios,&value,&error_code);
                            start = std::chrono::high_resolution_clock::now();
                            if (result<0){
                                    cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                            }
                            else{
                                    if (!error_code.compare("0"))
                                            cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
                                    else
                                            cout<<"Test FAILED! Error code:" << error_code << endl;
                            }
                            now = std::chrono::high_resolution_clock::now();
                            std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms = now - start;
                            if (elapsed_ms.count()<1000.) cout<<"SUCCESS. The test was completed on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                            else cout<<"Time FAILED. Failed to run the test on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                            break;
				}
			case '2':
				{
					cout << "AT-AR1 - Analogue read test started.\n";
					start = std::chrono::high_resolution_clock::now();
					for(int i=0;i<12;++i){
						cout<<"Reading analogue value from port ";
						cout<<"AI "<<i<<"!"<<endl;
						result=fm191.analogRead(i,&value,&error_code);
						if (result<0){
							cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
						}
						else{
							if (!error_code.compare("0"))
								cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
							else
								cout<<"Test FAILED! Error code:" << error_code << endl;
						}

					}
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					now = std::chrono::high_resolution_clock::now();
					std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms = now - start;
					if (elapsed_ms.count()<1000) cout<<"SUCCESS. The test was completed on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
					else cout<<"Time FAILED. Failed to run the test on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
					break;
				}
			case '3':
				{
                                    cout << "AT-DR1 - Digital read test started.\n";
                                    int gpios[28]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
                                    int dios[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
                                    cout<<"Configuring all the DIOs and GPIOs as input ports!"<<endl;
                                    result=fm191.setupDigitalPorts(dios,gpios,&value,&error_code);
                                    start = std::chrono::high_resolution_clock::now();
                                    if (result<0){
                                            cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                    }
                                    else{
                                            if (!error_code.compare("0"))
                                                    cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
                                            else
                                                    cout<<"Test FAILED! Error code:" << error_code << endl;
                                    }
                                    start = std::chrono::high_resolution_clock::now();
                                    for(int i=0;i<24;++i){
                                            cout<<"Reading Digital value from port ";
                                            if (i<16){
                                                    cout<<"DIO "<<i<<"!"<<endl;
                                                    result=fm191.digitalRead(i,0,&value,&error_code);
                                            }
                                            else if ((i>=16) && (i<20)) {
                                                    cout<<"GPIO "<<i-16<<"!"<<endl;
                                                    result=fm191.digitalRead(i-16,1,&value,&error_code);
                                            } else {
                                                    cout<<"LED "<<i-20<<"!"<<endl;
                                                    result=fm191.digitalRead(i-20,2,&value,&error_code);
                                            }
                                            if (result<0){
                                                    cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                            }
                                            else{
                                                    if (!error_code.compare("0"))
                                                            cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
                                                    else
                                                            cout<<"Test FAILED! Error code:" << error_code << endl;
                                            }

                                    }
                                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                    now = std::chrono::high_resolution_clock::now();
                                    std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms = now - start;
                                    if (elapsed_ms.count()<1000) cout<<"SUCCESS. The test was completed on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                                    else cout<<"Time FAILED. Failed to run the test on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                                    break;
				}
			case '4':
				{
                                    cout << "AT-AW1 - Analogue write test started.\n";
                                    start = std::chrono::high_resolution_clock::now();
                                    float value=0.75;
                                    for(int i=0;i<8;++i){
                                            cout<<"Writing analogue value: "<<value<<" to port ";
                                            cout<<"AO "<<i<<"!"<<endl;
                                            result=fm191.analogWrite(i,value,&error_code);
                                            value+=0.25;
                                            if (result<0){
                                                    cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                            }
                                            else{
                                                    if (!error_code.compare("0"))
                                                            cout<<"Test PASSED!"<<endl;
                                                    else
                                                            cout<<"Test FAILED! Error code:" << error_code << endl;
                                            }

                                    }
                                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                    now = std::chrono::high_resolution_clock::now();
                                    std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms = now - start;
                                    if (elapsed_ms.count()<1000) cout<<"SUCCESS. The test was completed on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                                    else cout<<"Time FAILED. Failed to run the test on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                                    break;
				}
			case '5':
				{
                                    
                                    cout << "AT-DW1 - Digital write test started.\n";
                                    int gpios[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    int dios[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    cout<<"Configuring all the DIOs and GPIOs as output ports!"<<endl;
                                    result=fm191.setupDigitalPorts(dios,gpios,&value,&error_code);
                                    start = std::chrono::high_resolution_clock::now();
                                    if (result<0){
                                            cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                    }
                                    else{
                                            if (!error_code.compare("0"))
                                                    cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
                                            else
                                                    cout<<"Test FAILED! Error code:" << error_code << endl;
                                    }
                                    start = std::chrono::high_resolution_clock::now();
                                    for(int i=0;i<24;++i){
                                            cout<<"Writing to port ";
                                            if (i<16){
                                                    cout<<"DIO "<<i<<", value: 1!"<<endl;
                                                    result=fm191.digitalWrite(i,0,1,&error_code);
                                            }
                                            else if ((i>=16) && (i<20)) {
                                                    cout<<"GPIO "<<i-16<<", value 0!"<<endl;
                                                    result=fm191.digitalWrite(i-16,1,1,&error_code);
                                            } else {
                                                    cout<<"LED "<<i-20<<", value 0!"<<endl;
                                                    result=fm191.digitalWrite(i-20,2,1,&error_code);
                                            }
                                            if (result<0){
                                                    cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                            }
                                            else{
                                                    if (!error_code.compare("0"))
                                                            cout<<"Test PASSED!"<<endl;
                                                    else
                                                            cout<<"Test FAILED! Error code:" << error_code << endl;
                                            }

                                    }
                                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                    now = std::chrono::high_resolution_clock::now();
                                    std::chrono::duration<long double,std::ratio<1,1000>> elapsed_ms = now - start;
                                    if (elapsed_ms.count()<1000) cout<<"SUCCESS. The test was completed on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                                    else cout<<"Time FAILED. Failed to run the test on time! Elapsed time: "<< elapsed_ms.count() <<" milliseconds."<<endl;
                                    result=fm191.digitalWrite(1,1,true,&error_code);
                                    break;
				}
			case '6':
				{
                                    cout << "Blink - Blink test started."<<endl;
                                    int gpios[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    int dios[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    cout<<"Configuring all the DIOs and GPIOs as output ports!"<<endl;
                                    result=fm191.setupDigitalPorts(dios,gpios,&value,&error_code);
                                    start = std::chrono::high_resolution_clock::now();
                                    if (result<0){
                                            cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                    }
                                    else{
                                            if (!error_code.compare("0"))
                                                    cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
                                            else
                                                    cout<<"Test FAILED! Error code:" << error_code << endl;
                                    }
				    std::string tp, pt;
                                    cout<<"Please enter the Digital type [0 - dio, 1 - gpio, 2 - led].";
                                    cin >> tp;
                                    cout << endl<<"Please enter the port number [";
                                    if (std::stoi(tp)==0) cout<<"Dio 0..14]";
                                    else if (std::stoi(tp)==1) cout<<"Gpio 0..27]";
                                    else cout<<"Led 0..3]";
                                    cin >> pt;
                                    cout << endl;
                                    start = std::chrono::high_resolution_clock::now();
                                    for(int I=0;I<20;++I)
                                            {
                                                cout<<"Test "<<I<<" - ";
                                                if (std::stoi(tp)==0) cout<<"DIO";
                                                else if (std::stoi(tp)==1) cout<<"GPIO";
                                                else if (std::stoi(tp)==2) cout<<"LED";
                                                else cout<<"DIO";
                                                cout << pt<<" value: 1!"<<endl;
                                                result=fm191.digitalWrite(std::stoi(pt),std::stoi(tp),1,&error_code);
                                                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                                cout<<"Result: "<< result<<endl;
                                                cout << " value: 0!"<<endl;
                                                result=fm191.digitalWrite(std::stoi(pt),std::stoi(tp),0,&error_code);
                                                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                                cout<<"Result: "<< result<<endl; 
                                            }
                                    break;
				}
                        case '7':
                                {
                                    cout << "AT-ATDGS1 - Get digital ports states started.\n"<<endl;
                                    int gpios [28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    int dios [15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    fm191.getDigitalPortsStatus(dios, gpios);
                                    cout<<"DIOs={";
                                    for(int i=0;i<15;++i){
                                        cout<<dios[i]<<",";
                                    }
                                    cout<<"}"<<endl<<"GPIOs={";
                                    for(int i=0;i<28;++i){
                                        cout<<gpios[i]<<",";
                                    }
                                    cout<<"}"<<endl;
                                    break;
                                }
                        case '8':
                                {
                                    cout << "Configure PWM.\n"<<endl;
                                    cout << "Configure PWM with a clock of 500Hz and scale of 0-255."<<endl;
                                    result=fm191.setupPwm(500, 255,&error_code);
                                    if (result<0){
                                            cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                    }
                                    else{
                                            if (!error_code.compare("0"))
                                                    cout<<"Test PASSED!"<<endl;
                                            else
                                                    cout<<"Test FAILED! Error code:" << error_code << endl;
                                    }
                                    break;
                                }
                        case '9':
                                {
                                    int gpios[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    int dios[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                                    cout<<"Configuring all the DIOs and GPIOs as output ports!"<<endl;
                                    result=fm191.setupDigitalPorts(dios,gpios,&value,&error_code);
                                    start = std::chrono::high_resolution_clock::now();
                                    if (result<0){
                                            cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                    }
                                    else{
                                            if (!error_code.compare("0"))
                                                    cout<<"Test PASSED!"<<endl<<" Returned value: "<< value<<endl;
                                            else
                                                    cout<<"Test FAILED! Error code:" << error_code << endl;
                                    }
                                    
                                    cout << "Send PWM to DIO0 with a 50% dutty cycle (value 124) and repetition of 1 clock cycle .\n"<<endl;
                                    result=fm191.pwm(0, 0, 124, 1, &error_code);
                                    if (result<0){
                                            cout<<"Test FAILED! Connection error with error code "<< result<< " !"<<endl;
                                    }
                                    else{
                                            if (!error_code.compare("0"))
                                                    cout<<"Test PASSED!"<<endl;
                                            else
                                                    cout<<"Test FAILED! Error code:" << error_code << endl;
                                    }
                                    break;
                                }
                                            
			case 'q':
				cout << "Quitting...\n";
				menuFlag=false;
				//fm191.~FM191(); // deleting object
				break;
			case 'Q':
				cout << "Quitting...\n";
				menuFlag=false;
				//fm191.~FM191(); // deleting object
				break;
			default:
				cout << "Please enter a valid option!\n";
				break;
		   }
	}


}

//main function
int main(int argc, char* argv[]){
	cout<<"*************************************************************************"<<endl;
	cout<<"Copyright: "<< COPYRIGHT <<endl<<"Support contact: "<<AUTHOR<<", "<<CONTACT<<endl;
	cout<<"Version: "<< VERSION << ", "<<VERSION_DATE<< ", "<< DIFF <<endl;
	cout<<"*************************************************************************"<<endl;
	test();
}





