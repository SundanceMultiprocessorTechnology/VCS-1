/**
* ==================================================================
\file FM191.cpp						       
\author Pedro Machado <pedro.m@sundance.com>			               
\version 0.1								
\copyright 2018, Sundance Multiprocessor Technology Ltd. (c) GPLv3                 
\brief FM191 source file               
* ==================================================================
*/
#include"FM191.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <atomic>
#include <chrono>
#include <cstring>
#include "mqtt/client.h"
#include <ctime>


const int  QOS = 1;
const auto TIMEOUT = std::chrono::seconds(10);

using namespace std;
using namespace std::chrono;


/**
 * A callback class for use with the main MQTT client.
 */
class callback : public virtual mqtt::callback
{
public:
	void connection_lost(const string& cause) override {
		cout << "\nConnection lost" << endl;
		if (!cause.empty())
			cout << "\tcause: " << cause << endl;
	}

	void delivery_complete(mqtt::delivery_token_ptr tok) override {
		cout << "\tDelivery complete for token: "
			<< (tok ? tok->get_message_id() : -1) << endl;
	}
};


/**
 * A base action listener.
 */
class action_listener : public virtual mqtt::iaction_listener
{
protected:
	void on_failure(const mqtt::token& tok) override {
		cout << "\tListener failure for token: "
			<< tok.get_message_id() << endl;
	}

	void on_success(const mqtt::token& tok) override {
		cout << "\tListener success for token: "
			<< tok.get_message_id() << endl;
	}
};


/**
 * A derived action listener for publish events.
 */
class delivery_action_listener : public action_listener
{
	atomic<bool> done_;

	void on_failure(const mqtt::token& tok) override {
		action_listener::on_failure(tok);
		done_ = true;
	}

	void on_success(const mqtt::token& tok) override {
		action_listener::on_success(tok);
		done_ = true;
	}

public:
	delivery_action_listener() : done_(false) {}
	bool is_done() const { return done_; }
};


/** 
 * Simple function to manually reconect a client.
 * */

bool try_reconnect(mqtt::client& cli)
{
	constexpr int N_ATTEMPT = 30;

	for (int i=0; i<N_ATTEMPT && !cli.is_connected(); ++i) {
		try {
			cli.reconnect();
			return true;
		}
		catch (const mqtt::exception&) {
			this_thread::sleep_for(seconds(1));
		}
	}
	return false;
}


/**
 * Function to publish a message in a specific topic
 */
int publish_message(std::string server_address, std::string client_id, std::string message, std::string topic){
	mqtt::async_client client(server_address, client_id);
	callback cb;
	client.set_callback(cb);
	mqtt::connect_options conopts;
	try {
			//cout << "\nConnecting..." << endl;
			mqtt::token_ptr conntok = client.connect(conopts);
			//cout << "Waiting for the connection..." << endl;
			conntok->wait();
			//cout << "  ...OK" << endl;

			cout << "\nSending message..." << endl;
			mqtt::message_ptr pubmsg = mqtt::make_message(topic,message);
			pubmsg->set_qos(QOS);
			client.publish(pubmsg)->wait_for(TIMEOUT);
			//cout << "  ...OK" << endl;
			// Disconnect
			cout << "\nDisconnecting..." << endl;
			conntok = client.disconnect();
			conntok->wait();
			//cout << "  ...OK" << endl;
	}
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		return -1;
	}
	return 0;
}




/**
 * Function to subscribe messages from a specific topic
 */
int subscribe_message(std::string server_address, std::string client_id, std::string topic,
		std::string error,std::string* rxmessage, std::string* rxerror){
	mqtt::connect_options connOpts;
		connOpts.set_keep_alive_interval(20);
		connOpts.set_clean_session(true);

		mqtt::client cli(server_address, client_id);


		try {
			cout << "Connecting to the MQTT server..." << flush;
			cli.connect(connOpts);
			cli.subscribe(topic, QOS);
			cout << "OK\n" << endl;
			cout << "subscribing topic: "<< topic<<endl;

			// Consume messages
			//TODO check here
			while (true) {
				auto msg = cli.consume_message();
				if (!msg) break;
				std::string tmp,cmd,tmstp,port,value;
				int ct=0;
				tmp=msg->to_string();
				for (std::uint16_t i=0;i<tmp.length();++i){
					if (tmp[i]==',') ct=ct+1;
					else{
						if (ct==0) cmd+=tmp[i];
						else if (ct==1) tmstp+=tmp[i];
						else if (ct==2) port+=tmp[i];
						else value+=tmp[i];
					}
				}
				// TODO add tmstp protection
				if (cmd==error){
					*rxerror=value;
					break;
				}
				cout << msg->get_topic() << ": " << msg->to_string() << endl;
				*rxmessage=value;
			}

			// Disconnect

			cout << "\nDisconnecting from the MQTT server..." << flush;
			cli.disconnect();
			cout << "OK" << endl;
		}
		catch (const mqtt::exception& exc) {
			cerr << exc.what() << endl;
			return -1;
		}

	return 0;
}


/**
 * Class constructor
 */
FM191::FM191(std::string ip, std::string port){
	FM191::server= "tcp://"+ip+":"+port;
	FM191::client_id="Publisher FM191 Windows SDK";
	std::cout<<"FM191 module initialised with SUCCESS."<<std::endl<<"MQTT broker configuration: "<<ip<<":"<<port<<std::endl;
}

/**
 * Class destructor
 */
FM191::~FM191(){
	std::cout<<"FM191 module deleted with SUCCESS!"<<std::endl;
}

/**
 * Method to read data from an analogue port
 */
int FM191::analogRead(int port, std::string* value, std::string* error_code){
	if ((-1<port) && (port < FM191::AI)){
		time_t now = time(0);
		std::string sNow =std::to_string(now);
		std::string sport= std::to_string(port);
		std::string message {std::to_string(FM191::ANALOG_READ)+","+sNow+","+sport};
		if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
			int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[2],std::to_string(FM191::ANALOG_ERRORS),value,error_code);
			return res;
		}
		else{
			return -3;
		}
	}
	else{
		std::cout<<"Invalid Analog port: "<<port<<std::endl;
		return -2;
	}
}

/**
 * Method to write data in an analogue port
 */
int FM191::analogWrite(int port, float value, std::string* error_code){
	if ((-1<port) && (port < FM191::AI)){
		time_t now = time(0);
		std::string sNow =std::to_string(now);
		std::string svalue= std::to_string(value);
		std::string sport= std::to_string(port);
		std::string message {std::to_string(FM191::ANALOG_WRITE)+","+sNow+","+sport+","+svalue};
		if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
			std::string val; // not used
			int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[2],std::to_string(FM191::ANALOG_ERRORS),&val,error_code);
			return res;
		}
		else{
			return -3;
		}
	}
	else{
		std::cout<<"Invalid Analog port: "<<port<<std::endl;
		return -2;
	}
}

/**
 * Method to read data from a digital port
 */
int FM191::digitalRead(int port, int type, std::string* value, std::string* error_code){
	if ((type==0 and port < FM191::DIO) or (type==1 and port < FM191::GPIO) or (type==2 and port < FM191::LED)){
            if (FM191::digital_ports_setup) {
		time_t now = time(0);
		std::string sNow =std::to_string(now);
		std::string sport= std::to_string(port);
		std::string stype= std::to_string(type);
		std::string message {std::to_string(FM191::DIGITAL_READ)+","+sNow+","+stype+","+sport};
		if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
			if(type==0){
                            std::cout<<"Requesting Digital status to port: "<<port<< " of type DIO. Published in topic: "<<FM191::TOPICS[0]<<std::endl;
			}
			else if (type==1){
                            std::cout<<"Requesting Digital status to port: "<<port<<" of type GPIO. Published in topic: "<<FM191::TOPICS[0]<<std::endl;
			}
			else if(type==2){
                            std::cout<<"Requesting Digital status to LED"<<port<<". Published in topic: "<<FM191::TOPICS[0]<<std::endl;
                            
                        }
                        else{
                            std::cout<<"Wrong Digital type!"<<std::endl;
                            return -3;
                        }
			int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[1],std::to_string(FM191::DIGITAL_ERRORS),value,error_code);
			return res;
		}
		else{
			return -3;
		}
		
            }
            else return -4;
	}
	else{
		std::cout<<"Invalid Digital port: "<<port<<std::endl;
		return -1;
	}
}

/**
 * Method to write data in a digital port
 */
int FM191::digitalWrite(int port, int type, int value, std::string* error_code){
	if ((type==0 and port < FM191::DIO) or (type==1 and port < FM191::GPIO) or (type==2 and port < FM191::LED)){
            if (FM191::digital_ports_setup) {
                time_t now = time(0);
		std::string sNow =std::to_string(now);
		std::string svalue= std::to_string(value);
		std::string sport= std::to_string(port);
		std::string stype= std::to_string(type);
		std::string message {std::to_string(FM191::DIGITAL_WRITE)+","+sNow+","+stype+","+sport+","+svalue};
		if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
			if(type==0){
                            std::cout<<"Sending Digital value: "<< value <<" to port: "<<port<< " of type DIO. Published in topic: "<<FM191::TOPICS[0]<<std::endl;
			}
			else if (type==1){
                            std::cout<<"Sending Digital value: "<< value <<" to port: "<<port<<" of type GPIO. Published in topic: "<<FM191::TOPICS[0]<<std::endl;
			}
			else if(type==2){
                            std::cout<<"Sending Digital value: "<< value <<" to LED"<<port<<". Published in topic: "<<FM191::TOPICS[0]<<std::endl;
                            
                        }
                        else{
                            std::cout<<"Wrong Digital type!"<<std::endl;
                            return -3;
                        }
			std::string val; // not used
			int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[1],std::to_string(FM191::DIGITAL_ERRORS),&val,error_code);
			return res;
		}
		else{
			return -2;
		}
            }
            else return -3;
	}
	else{
		std::cout<<"Invalid Digital port: "<<port<<std::endl;
		return -1;
	}
}

/**
 * Method for setting up the digital I/Os as outputs or inputs
 */
int FM191::setupDigitalPorts(int* dios, int* gpios, std::string* value, std::string* error_code){
	time_t now = time(0);
	std::string sNow =std::to_string(now);
	std::string message {std::to_string(FM191::DIGPORTSETUP_SETUP)+","+sNow+','};
        for(int i=0; i<FM191::DIO; ++i) {
            FM191::dioLut[i]=*dios;
            message+={std::to_string(FM191::dioLut[i])+","};
            dios++;
        }
        cout<<endl;
        for(int i=0; i<FM191::GPIO; ++i){
            FM191::gpioLut[i]=*gpios;
            message+={std::to_string(FM191::gpioLut[i])+","};
            gpios++;
        }
        //cout<<message<<endl;
    
	if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
            int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[3],std::to_string(FM191::DIGPORTSETUP_ERRORS),value,error_code);
            if (res==0){
                FM191::digital_ports_setup=true;
            }
            return res;
	}
	else{
            return -2;
	}
        
}

/**
 * Method for getting the configuration of the Digital ports
 */
void FM191::getDigitalPortsStatus(int* dios, int* gpios){
        for(int i=0; i<FM191::DIO; ++i) {
            *dios=FM191::dioLut[i];
            cout << *dios;
            dios++;
        }
        
         for(int i=0; i<FM191::GPIO; ++i){
            *gpios=FM191::gpioLut[i];
            cout << *gpios;
            gpios++;
        }
        cout << endl;
}


/**
 * Method for setting up PWM configurations
 */
int FM191::setupPwm(int frequency, int scale, std::string* error_code){
    time_t now = time(0);
    std::string sNow =std::to_string(now);
    std::string message {std::to_string(FM191::PWMSETUP)+","+sNow+','+std::to_string(frequency)+','+std::to_string(scale)};
    if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
        std::string val; // not used
        int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[4],std::to_string(FM191::PWMSETUP_ERRORS),&val,error_code);
        if (res==0){
            FM191::pwm_setup=true;
        }
        return res;
    }
    else{
        return -2;
    }
    
}


/**
 * Method for sending a PWM to a Digital port
 */
int FM191::pwm(int port, int type, int value, int duration, std::string* error_code){
    if ((type==0 and port < FM191::DIO) or (type==1 and port < FM191::GPIO)){
        if (FM191::digital_ports_setup && FM191::pwm_setup) {
            time_t now = time(0);
            std::string sNow =std::to_string(now);
            std::string message {std::to_string(FM191::PWM)+","+sNow+','+std::to_string(port)+','+std::to_string(type)+','+std::to_string(value)+','+std::to_string(duration)};
            if (publish_message(FM191::server,FM191::client_id,message,FM191::TOPICS[0])==0){
                std::string val; // not used
                int res=subscribe_message(FM191::server,FM191::client_id,FM191::TOPICS[4],std::to_string(FM191::PWM_ERRORS),&val,error_code);
                return res;
            }
            else{
                    return -2;
            }
        }
        else return -4;
    }
    else return -3;
    
}