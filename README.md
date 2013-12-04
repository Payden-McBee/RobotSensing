#RobotSensing
============

Library for sensors on robot

Documentation: I looked at C2C Good's code for help on setting up another sensor and learned that I needed
to reset the ENC bit before changing samples from different sensors. 

## Robot Sensing
Example code: This code checks for a really close wall and turns on LED1 for the left sensor being close to the wall 
and LED2 will be turned on if the right sensor is close to the wall. The input signal is an analog and this code 
converts it to a digital number in order to check it against a value to determine if the sensor is close to the wall.
```c
#include <msp430g2553.h>
#include "sensor.h"
/*
 * example.c
 */
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
```

## Notes

- To use this in Lab8, I will turn the robot when a wall is detected instead of turning on an LED.