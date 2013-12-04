/*
 * sensor.c
 *
 *  Created on: Dec 3, 2013
 *      Author: C15Payden.McBee
 */
#include "sensor.h"

void enableADC10Subsystem()
{

}

void initLEDs()
{

}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}


