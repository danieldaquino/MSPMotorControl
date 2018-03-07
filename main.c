#include <msp430.h> 
#include <stdio.h>

#include "VelocityGauge.h"
#include "UARTIO.h"

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	velocityGaugeInit(); //Initialize Gauge
	UARTIOInit(); // Initialize communication with Computer Console
	
	__enable_interrupt(); // Enable global interrupts. Everything must be configured before this.
	while(1) {
		//Nothing yet
		char LeString[30];
		sprintf(LeString, "Current Speed: %d\n\r", countsIn100ms);
		UARTIOSend(LeString);
		__delay_cycles(1000000);
	}
	return 0;
}
