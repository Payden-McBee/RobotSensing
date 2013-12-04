#include <msp430g2553.h>
#include "sensor.h"

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  enableADC10Subsystem();

  initLEDs();    //initialize LEDs as outputs

  for (;;)
  {

	  //gets reading from left sensor and checks against a threshhold value, if the reading is greater
	  	  // then LED1 is turned on

	  	 if (isLeftSensorCloseToWall())
	  	         P1OUT &= ~BIT0;                       // Clear P1.0 LED off
	  	 else
	  	         P1OUT |= BIT0;                        // Set P1.0 LED on

	  //gets reading from right sensor and checks against a threshhold value, if the reading is greater
	  	  // then LED2 is turned on

	  	if (isRightSensorCloseToWall())
	  	         P1OUT &= ~BIT6;                       // Clear P1.6 LED off
	  	else
	  	         P1OUT |= BIT6;                        // Set P1.6 LED on

  }

}



