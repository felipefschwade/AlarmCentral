/*
	AlarmCentral.cpp
	written by Felipe Faé Schwade
	2016, August 8.
	MIT license

*/

#include "Arduino.h"
#include "AlarmCentral.h"

/**
*	Class Consctructor
*	Receive the RCSwitch Object as a Parameter	
*/
AlarmCentral::AlarmCentral(RCSwitch mySwitch) {
	_mySwitch = mySwitch;
	//Enable Receive on interrupt 0, by default it is on Pin2
	_mySwitch.enableReceive(0);
}

/**
	Set the pins that will be used as PIR sensors Receiver
	you might put all the sensors in a serie and use it in only
	one Arduino PIN. But if you want a better feedback from the central
	you can set one pin for each sensor.
*/
void AlarmCentral::setPIRSensors(int *sensors) {
	_PIRSensors = sensors;
}

/**
	Set the 2 pins for the Output leds;
*/
void AlarmCentral::setLedPins(int greenLed, int redLed) {
	_greenLed = greenLed;
	_redLed = redLed;
}

/**
	Set the Siren Pin output
*/
void AlarmCentral::setSirenPin(int sirenPin) {
	_sirenPin = sirenPin;
}

/**
	<----------------------------------- Private Functions ------------------------------------->
*/
void AlarmCentral::ledBlink(int led, int speed_milis);
void AlarmCentral::turnOn(int pin);
void AlarmCentral::turnOff(int pin);
void AlarmCentral::sirenBeep(int times);