/*===============================

	Velocity Gauge
	
	this C module is part of the MSP Motor Control.
	It gathers signals from and encoder, counts the pulses,
	and it estimates the velocity.
	
	Written by Daniel Walnut
	
	Requirements for use:
	
	P1.2 must be connected to a motor encoder channel
	This module will modify P1.2, so do not use any other modules that use it.
	
	Note:If you want to use another pins, modify the Macros as well as the ISR. Make sure to use an
	interrupt enabled port like P1 or P2
	
	For function descriptions and usage, please visit VelocityGauge.h

===============================*/

#include <msp430.h>
#include <VelocityGauge.h>

//To do: Create shared port ISR driver module
#pragma vector=PORT1_VECTOR
__interrupt void encoderISR(void) {
	switch(__even_in_range(P_ENCODER_IV,6)) {
		case 0x0:
			//Nothing. How did we end up here?
			break;
		case 0x02:
			//P1.0 - Not interested
			break;
		case 0x04:
			//P1.1 - Not interested
		case 0x06:
			//P1.2 - an encoder count!
			encoderCount++; //Increase count
			break;
		default:
			//Nothing here
			break;
	}
}

void velocityGaugeInit(void) {
	P_ENCODER_DIR &= ~ENCODER_BIT; //Encoder is an input
	P_ENCODER_IE |= ENCODER_BIT; //Enable interrupts for encoder
	P_ENCODER_REN |= ENCODER_BIT; //Enable Pull up/down resistor
	P_ENCODER_OUT &= ~ENCODER_BIT; // Pull down resistor
}
