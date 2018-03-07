/*
 * servo.h
 *
 *  Created on: 7 de mar de 2018
 *      Author: fabio
 */

#include <stdint.h>

typedef struct ServoHandler {
	uint8_t pin;
	uint16_t range;
	uint16_t position;
} StServoHandler;

void servoInit(StServoHandler servoHandler);
void servoUpdate(StServoHandler servoHandler, uint16_t position);
