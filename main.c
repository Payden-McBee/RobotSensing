#include <msp430g2553.h>
#include "sensor.h"

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  enableADC10Subsystem();

  initLEDs();    //initialize LEDs as outputs

  for (;;)
  {

	  isLeftSensorCloseToWall();
	  isRightSensorCloseToWall();

  }


}



