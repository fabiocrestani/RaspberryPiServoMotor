/*
 * servo.c
 *
 *  Created on: 7 de mar de 2018
 *      Author: fabio
 */

#include "servo.h"
#include <wiringPi.h>
#include <softPwm.h>

void servoInit(StServoHandler servoHandler, uint8_t pin, uint16_t range,
		uint16_t position) {
	servoHandler.pin = pin;
	servoHandler.range = range;
	servoHandler.position = position;
	pinMode(servoHandler.pin, PWM_OUTPUT);
	digitalWrite(servoHandler.pin, LOW);
	softPwmCreate(servoHandler.pin, servoHandler.position, servoHandler.range);
}

void servoUpdate(StServoHandler servoHandler, uint16_t newPosition) {
	servoHandler.position = newPosition;
	servoWrite(servoHandler);
}

void servoWrite(StServoHandler servoHandler) {
	softPwmWrite(servoHandler.pin, servoHandler.position);
}

