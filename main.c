#include <msp430g2553.h>
#include "sensor.h"

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  enableADC10Subsystem();

  initLEDs();

  for (;;)
  {

	  turnLeftSensorOn();

   if (ADC10MEM < 0x1FF)
      P1OUT &= ~0x01;                       // Clear P1.0 LED off
    else
      P1OUT |= 0x01;                        // Set P1.0 LED on
  }

}



