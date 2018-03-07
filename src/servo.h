/*
 * servo.h
 *
 *  Created on: 7 de mar de 2018
 *      Author: fabio
 */

#include <stdio.h>
#include <stdint.h>

typedef struct ServoHandler {
	uint8_t pin;
	uint16_t range;
	uint16_t position;
} StServoHandler;

void servoInit(StServoHandler servoHandler, uint8_t pin, uint16_t range,
		uint16_t position);
void servoUpdate(StServoHandler servoHandler, uint16_t newPosition);
void servoWrite(StServoHandler servoHandler);
