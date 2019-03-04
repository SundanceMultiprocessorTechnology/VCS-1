//======================================================================================//
// Name        : FM191.cpp                                                              //
// Author      : Emilie Wheatley                                                        //
// Version     : 0.1                                                                    //
// Copyright   : 2018, Sundance Multiprocessor Technology Ltd. (c) GNU v.3.0            //
// Description : FM191 Windows SDK                                                      //
//======================================================================================//

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
#include <termios.h>
#include <math.h>
#include <unistd.h>

const int  QOS = 1;
const auto TIMEOUT = std::chrono::seconds(10);
const int  N_RETRY_ATTEMPTS = 5;

std::atomic_flag listening(ATOMIC_FLAG_INIT);

using namespace std;
using namespace std::chrono;

int publish_message(mqtt::async_client &client, std::string message, std::string topic);

/////////////////////////////////////////////////////////////////////////////

// Callbacks for the success or failures of requested actions.
// This could be used to initiate further action, but here we just log the
// results to the console.

class action_listener : public virtual mqtt::iaction_listener
{
	std::string name_;

	void on_failure(const mqtt::token& tok) override {
		std::cout << name_ << " failure";
		if (tok.get_message_id() != 0)
			std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
		std::cout << std::endl;
	}

	void on_success(const mqtt::token& tok) override {
		std::cout << name_ << " success";
		if (tok.get_message_id() != 0)
			std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
		auto top = tok.get_topics();
		if (top && !top->empty())
			std::cout << "\ttoken topic: '" << (*top)[0] << "', ..." << std::endl;
		std::cout << std::endl;
	}

public:
	action_listener(const std::string& name) : name_(name) {}
};

/////////////////////////////////////////////////////////////////////////////

/**
 * Local callback & listener class for use with the client connection.
 * This is primarily intended to receive messages, but it will also monitor
 * the connection to the broker. If the connection is lost, it will attempt
 * to restore the connection and re-subscribe to the topic.
 */
class callback: public virtual mqtt::callback,
					public virtual mqtt::iaction_listener

{
	// Counter for the number of connection retries
	int nretry_;
	// The MQTT client
	mqtt::async_client& client_;
	// Options to use if we need to reconnect
	mqtt::connect_options& connOpts_;
	// An action listener to display the result of actions.
	action_listener subListener_;

	std::string topic_;
	FM191* fm191_;
	
	

	// This deomonstrates manually reconnecting to the broker by calling
	// connect() again. This is a possibility for an application that keeps
	// a copy of it's original connect_options, or if the app wants to
	// reconnect with different options.
	// Another way this can be done manually, if using the same options, is
	// to just call the async_client::reconnect() method.
	void reconnect() {
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		try {
			client_.connect(connOpts_, nullptr, *this);
		}
		catch (const mqtt::exception& exc) {
			std::cerr << "Error: " << exc.what() << std::endl;
			exit(1);
		}
	}

	// Re-connection failure
	void on_failure(const mqtt::token& tok) override {
		std::cout << "Connection failed" << std::endl;
		if (++nretry_ > N_RETRY_ATTEMPTS)
			exit(1);
		reconnect();
	}

	// Re-connection success
	void on_success(const mqtt::token& tok) override {
		std::cout << "\nConnection success" << std::endl;
		std::cout << "\nSubscribing to topic '" << topic_ << "'\n"
			<< " using QoS" << QOS << "\n" << std::endl;

		client_.subscribe(topic_, QOS, nullptr, subListener_);////////////////////////////////// TO SORT

	}

	// Callback for when the connection is lost.
	// This will initiate the attempt to manually reconnect.
	void connection_lost(const std::string& cause) override {
		std::cout << "\nConnection lost" << std::endl;
		if (!cause.empty())
			std::cout << "\tcause: " << cause << std::endl;

		std::cout << "Reconnecting..." << std::endl;
		nretry_ = 0;
		reconnect();
	}

	// Callback for when a message arrives.
	void message_arrived(mqtt::const_message_ptr msg) override {
		std::cout << "\nMessage arrived" << std::endl;
		std::cout << "\ttopic: '" << msg->get_topic() << "'" << std::endl;
		std::cout << "\tpayload: '" << msg->to_string() << "'\n" << std::endl;
		std::string topic, result = "ACQ", error = "0";	
		if (!fm191_->processCommand(msg->to_string(), &result, &error, &topic)) {
			if (result!="") publish_message(client_, result, topic);
			publish_message(client_, error, topic);
		}
	}

	void delivery_complete(mqtt::delivery_token_ptr tok) override {
		cout << "\tDelivery complete for token: "
			<< (tok ? tok->get_message_id() : -1) << endl;
	}

public:
	callback(mqtt::async_client& client, mqtt::connect_options& connOpts, std::string topic, FM191 *fm191)
				: nretry_(0), client_(client), connOpts_(connOpts), subListener_("Subscription"), topic_(topic), fm191_(fm191) {}
};


/////////////////////////////////////////////////////////////////////////////

int publish_message(mqtt::async_client &client, std::string message, std::string topic){
	try {
		cout << "\nSending message..." << endl;
		cout << "\ttopic: '" << topic << "'" << endl;
		cout << "\tpayload: '" << message <<  endl;
		mqtt::message_ptr pubmsg = mqtt::make_message(topic,message);
		pubmsg->set_qos(QOS);
		client.publish(pubmsg)->wait_for(TIMEOUT);
		cout << "  ...OK" << endl;
	}
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		return -1;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

int subscribe_message(std::string server_address, std::string client_id, std::string topic, FM191 *fm191)
{
	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_clean_session(true);
	
	mqtt::async_client client(server_address, client_id);

	callback cb(client, connOpts, topic, fm191);
	client.set_callback(cb);

	try {
		cout << "Connecting to the MQTT server..." << flush;
		client.connect(connOpts, 0, cb);
		while(listening.test_and_set(std::memory_order_acquire)){}
	}
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		return -1;
	}

	return 0;
}

FM191::FM191(std::string ip, std::string port):pwm_frequency(0), pwm_scale(0)
{
	FM191::server= "tcp://"+ip+":"+port;
	FM191::client_id="MQTT client FM191 Linux SDK";
	std::cout<<"FM191 module initialised with SUCCESS."<<std::endl<<"MQTT broker configuration: "<<ip<<":"<<port<<std::endl;
	
	unsigned int i = 0;
	bool data = 0;	
	bool read = 0;
	int err = 0;

	for (int i=0; i<4; i++) {
		read = 0; data = 0;
		int err = gpioAccess(i, read, 2, data); // set all the on-board LEDs to 0
		if (!err) LED_state[i] = 0;
	}
	data = 1;
	gpioAccess(0, 0, 2, data); //LED0 on when SDK running
	
	for (i=0; i<DIO; i++) {
		read = 0; data = 0;
		if (i==11) read = 1; // DIO11 is the only input all the other DIOs and GPIOs are set as output
		err = gpioAccess(i, read, 0, data);
	}
	for (i=0; i<GPIO; i++) {
		read = 0; data = 0;
		err = gpioAccess(i, read, 1, data);
	}
}

FM191::~FM191(){
	std::cout<<"FM191 module deleted with SUCCESS!" <<std::endl;
	bool data = 0;
	gpioAccess(0, 0, 2, data); //LED0 off when SDK stops	
}


void FM191::startListening()
{
	std::cout<<"Starting the subscriber!"<<std::endl;
	listening.test_and_set(std::memory_order_acquire);
	std::thread subscribe_thread(subscribe_message,FM191::server,FM191::client_id,FM191::TOPICS[0], this);
	subscribe_thread.detach();
}

void FM191::stopListening()
{
	std::cout<<"Stopping the subscriber!"<<std::endl;
	listening.clear(std::memory_order_release);
}

int FM191::analogRead(unsigned int port, std::string *result, std::string* error)
{
	time_t now = time(0);
	std::string sNow = std::to_string(now);
	std::string sport = std::to_string(port);
	std::string sresult = "";
	std::string cmd = "";
	int err = 0;
	
	if (port < FM191::AI){
		
		// Access the UART interface to read the ADCs
		char portname[16];
		sprintf(portname, "/dev/ttyUL%d", (port/4)+1); //ttyULx devices are numbered from 1		
		UART_ADC uart(portname, B115200, 0, 0); // set speed to 115,200 bps, 8n1 (no parity), no blocking  
		unsigned int mux = ((port%4) + 1) & 0x3;
		uart.setReg0Value(1, mux); //gain 1
		printf("UART %d\n",port%4);																				
		uart.setReg1Value(2, 0); // Analog supply (AVDD / AVSS) used as reference, single shot mode

		uart.setReg3Value(1); // automatic read mode

		err = uart.writeReg(0);
		err = uart.writeReg(1);
		err = uart.writeReg(3);

		int val = 0;
		uart.start();
		err = uart.readVal(val);
		sresult = std::to_string(val);		
	}
	else{
		std::cout<<"Invalid Analog port: "<<port<<std::endl;
		err = -5;
	}

	*result = std::to_string(FM191::ANALOG_RESULTS) + "," + sNow + "," + sport + "," + sresult;		
	*error = std::to_string(FM191::ANALOG_ERRORS) + "," + sNow + "," + sport + "," + std::to_string(err);

	return 0;
}

int FM191::analogWrite(unsigned int port, float &value, std::string *result, std::string* error){
	time_t now = time(0);
	std::string sNow =std::to_string(now);
	std::string sport= std::to_string(port);
	int err = 0;		
	unsigned int gain = 1; // DAC default value
	unsigned int div = 1; // DAC default value
	unsigned int n = 12; // DAC resolution in bits
	float vref = 2.5; // DAC reference voltage in volts
	float code = (value*div*pow(2,n))/(vref*gain);
	unsigned int data = (unsigned int)code;
	if (value==2.5) data = 0xFFF;
		
	if (port < FM191::AI){
		// Access the SPI interface to write the DACs
		SPI_DAC spi("/dev/spidev1.0", SPI_CPOL, 8, 78000); 
		spi.writeData(DAC_TRIGGER_REG, 0xA);
//	spi.writeData(DAC_TRIGGER_REG, 0x0);
		usleep(100000);
		err = spi.writeData(port+0x8, data);
	}
	else{
		std::cout<<"Invalid Analog port: "<<port<<std::endl;
		err = -5;
	}
	*result = "";		
	*error = std::to_string(FM191::ANALOG_ERRORS) + "," + sNow + "," + sport + "," + std::to_string(err);
	
	return 0;
}

int FM191::digitalRead(unsigned int port, int type, std::string* value, std::string *result, std::string* error){
	time_t now = time(0);
	std::string sNow =std::to_string(now);
	std::string sport= std::to_string(port);
	std::string sresult = "";
	int err = 0;

	if (((type==0) && (port < FM191::DIO)) || ((type==1) && (port < FM191::GPIO))){
		
		bool data = 0;
		err = gpioAccess(port, 1, type, data);
		sresult = std::to_string(data);
	} else if ((type==2) && (port < FM191::LED)) {
		sresult = std::to_string(LED_state[port]); 
	} else{
		std::cout<<"Invalid Digital port: "<<port<<std::endl;
		err = -5;
	}
	*result = std::to_string(FM191::DIGITAL_RESULTS) + "," + sNow + "," + sport + "," + sresult;		
	*error = std::to_string(FM191::DIGITAL_ERRORS) + "," + sNow + "," + sport + "," + std::to_string(err);
	
	return 0;
}

int FM191::digitalWrite(unsigned int port, int type, bool &value, std::string *result, std::string* error){
	time_t now = time(0);
	std::string sNow = std::to_string(now);
	std::string sport = std::to_string(port);
	int err = 0; 

	if (((type==0) && (port < FM191::DIO)) || ((type==1) && (port < FM191::GPIO))|| ((type==2) && (port < FM191::LED))){
		
		err = gpioAccess(port, 0, type, value);
		if ((!err) && (type==2)) LED_state[port] = value; // keep a log of the LED state as we can't read it back	
	}
	else{
		std::cout<<"Invalid Digital port: "<<port<<std::endl;
		err = -5;
	}
	
	*result = "";
	*error = std::to_string(FM191::DIGITAL_ERRORS) + "," + sNow + "," + sport + "," + std::to_string(err);
	
	return 0;
}

int FM191::digitalPortsSetup(bool DIO_state[DIO], bool GPIO_state[GPIO], std::string* result, std::string* error){
	time_t now = time(0);
	std::string sNow = std::to_string(now);
	int err = 0; 

	bool read = 0;
	unsigned int i = 0;
	for (i=0; i<DIO; i++) {
		err = gpioAccess(i, read, 0, DIO_state[i]);
	}
	for (i=0; i<GPIO; i++) {
		err = gpioAccess(i, read, 1, GPIO_state[i]);
	}
	
	*result = "";		
	*error = std::to_string(FM191::DIGITAL_PORT_SETUP_ERRORS) + "," + sNow + ",0," + std::to_string(err);
	
	return 0;
}

int FM191::pwmSetup(int frequency, int scale, std::string* result, std::string* error){
	time_t now = time(0);
	std::string sNow = std::to_string(now);
	int err = 0; 
	*result = "";
	pwm_frequency = frequency;
	pwm_scale = scale;
	*error = std::to_string(FM191::PWMSETUP_ERRORS) + "," + sNow + ",0," + std::to_string(err);
	
	return 0;
}

int FM191::pwm_(int port, int type, int value, int duration, std::string* result, std::string* error){
	time_t now = time(0);
	std::string sNow = std::to_string(now);
	int err = 0; 
	*result = "";	
	pwm p(pwm_frequency, pwm_scale);	
	p.generate_pwm(port, type, value, duration);
	*error = std::to_string(FM191::PWM_ERRORS) + "," + sNow + ",0," + std::to_string(err);
	
	return 0;
}

int FM191::processCommand(std::string msg_cmd, std::string* msg_res, std::string* msg_err, std::string* topic)
{
	std::string sCmd,tmstp,value, type, port;
	int ct=0;
	uint16_t i = 0;
	
	for (i=0;i<msg_cmd.length();++i){
		if (msg_cmd[i]==',') ct=ct+1;
		else{
			if (ct==0) sCmd+=msg_cmd[i];
			else if (ct==1) tmstp+=msg_cmd[i];
			else break;
		}
	}
	ct=0;

	unsigned int cmd = std::atoi(sCmd.c_str());						
	if (cmd == DIGITAL_WRITE) {
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				if (ct==0) type+=msg_cmd[j];
				else if (ct==1) port+=msg_cmd[j];
				else value+=msg_cmd[j];
			}
		}
		bool val = std::atoi(value.c_str());
		digitalWrite(std::atoi(port.c_str()), std::atoi(type.c_str()), val, msg_res, msg_err); 
		*topic = TOPICS[1];

	} else if (cmd == DIGITAL_READ) {
		std::string port, type;
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				if (ct==0) type+=msg_cmd[j];
				else if (ct==1) port+=msg_cmd[j];
				else break;
			}
		}
		digitalRead(std::atoi(port.c_str()), std::atoi(type.c_str()), &value, msg_res, msg_err); 
		*topic = TOPICS[1];

	} else if (cmd == ANALOG_WRITE) {		
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				if (ct==0) port+=msg_cmd[j];
				else value+=msg_cmd[j];
			}
		}
		float val = std::atof(value.c_str());
		analogWrite(std::atoi(port.c_str()), val, msg_res, msg_err); 
		*topic = TOPICS[2];
	
	} else if (cmd == ANALOG_READ) {
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				if (ct==0) port+=msg_cmd[j];
				else break;
			}
		}
		analogRead(std::atoi(port.c_str()), msg_res, msg_err); 
		*topic = TOPICS[2];
	
	} else if (cmd== DIGITAL_PORT_SETUP) {
		bool DIO_state[DIO];
		bool GPIO_state[GPIO];
		unsigned int pin = 0;
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				value = msg_cmd[j];
				if (pin<DIO) {
					DIO_state[pin] = std::atof(value.c_str());
				} else if ((pin>=DIO) && (pin<(DIO+GPIO))) {
					GPIO_state[pin-DIO] = std::atof(value.c_str());
				} else {
					break;
				}
				pin++;	
			}
		}
		digitalPortsSetup(DIO_state, GPIO_state,  msg_res, msg_err);
		*topic = TOPICS[3];
	
	} else if (cmd== PWMSETUP) {
		std::string frequency = "";
		std::string scale = "";
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				if (ct==0) frequency+=msg_cmd[j];
				else scale+=msg_cmd[j];
			}
		}
		pwmSetup(std::atof(frequency.c_str()), std::atof(scale.c_str()), msg_res, msg_err);
		*topic = TOPICS[4];
			
	} else if (cmd== PWM) {
		std::string port = "";
		std::string type = "";
		std::string value = "";
		std::string duration = "";
		for (std::uint16_t j=i;j<msg_cmd.length();++j){
			if (msg_cmd[j]==',') ct=ct+1;
			else{
				if (ct==0) port+=msg_cmd[j];
				else if (ct==1) port+=msg_cmd[j];
				else if (ct==2) type+=msg_cmd[j];
				else if (ct==3) value+=msg_cmd[j];
				else duration+=msg_cmd[j];
			}
		}
		pwm_(std::atof(port.c_str()), std::atof(type.c_str()), std::atof(value.c_str()), std::atof(duration.c_str()), msg_res, msg_err);
		*topic = TOPICS[4];	
		
	} else  {
		cout << "Command not recognized -> "<< msg_cmd << endl; 
		return -1;
	}	

	return 0;
}


