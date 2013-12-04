/*
 * sensor.h
 *
 *  Created on: Dec 3, 2013
 *      Author: C15Payden.McBee
 */

#ifndef SENSOR_H_
#define SENSOR_H_

void enableADC10Subsystem();
void initLEDs();
unsigned int getLeftSensorReading();
unsigned int getRightSensorReading();
void isLeftSensorCloseToWall();
void isRightSensorCloseToWall();

#endif /* SENSOR_H_ */
