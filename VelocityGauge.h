#ifndef VELOCITY_GAUGE_H
#define VELOCITY_GAUGE_H

#include <msp430.h>

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

===============================*/

/*=======
Macros
========*/
#define P_ENCODER_OUT P1OUT
#define P_ENCODER_DIR P1DIR
#define P_ENCODER_IN P1IN
#define P_ENCODER_IE P1IE
#define P_ENCODER_IFG P1IFG
#define P_ENCODER_IV P1IV

#define ENCODER_BIT BIT2

/*=======
Globals
=======*/
long int encoderCounts;

/*=======
Function Prototypes
========*/

/*======
~~encoderISR~~

This function will be the one responsible for counting pulses
inputs: none
outputs: none
Globals affected: encoderCounts
=======*/
void encoderISR(void);

/*======
~~velocityGaugeInit~~

This function initializes all parameters necessary
inputs: none
outputs: none
Globals affected: Encoder pin (usually P1.2)
======*/
void velocityGaugeInit(void);

#endif