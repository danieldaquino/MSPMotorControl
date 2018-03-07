#include <msp430.h> 
#include <VelocityGauge.h>

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	velocityGaugeInit(); //Initialize Gauge
	
	__enable_interrupt(); // Enable global interrupts. Everything must be configured before this.
	while(1) {
		//Nothing yet
	}
	return 0;
}
