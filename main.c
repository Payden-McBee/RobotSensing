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
	  isLeftSensorCloseToWall();

	  //gets reading from right sensor and checks against a threshhold value, if the reading is greater
	  // then LED2 is turned on
	  isRightSensorCloseToWall();

  }

}



