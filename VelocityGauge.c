/*===============================

	Velocity Gauge
	
	this C module is part of the MSP Motor Control.
	It gathers signals from and encoder, counts the pulses,
	and it estimates the velocity.
	
	Written by Daniel Walnut
	
	Requirements for use:
	
	P1.2 must be connected to a motor encoder channel
	This module will modify P1.2, so do not use any other modules that use it.
	
	Note:If you want to use another pins, modify the Macros. Make sure to use an
	interrupt enabled port like P1 or P2
	
	For function descriptions and usage, please visit VelocityGauge.h

===============================*/

#include <msp430.h>
#include <VelocityGauge.h>

void encoderISR(void) {

}

void velocityGaugeInit(void) {

}
