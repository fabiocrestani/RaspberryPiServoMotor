/*
 * servo.c
 *
 *  Created on: 7 de mar de 2018
 *      Author: fabio
 */

#include "servo.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

void servoInitAll(StServoHandler servoHandler) {
	if (wiringPiSetup() == -1) {
		printf("Erro ao inicializar WiringPi\n\r");
	} else {
		servoInit(servoHandler);
	}
}

void servoInit(StServoHandler servoHandler) {
	pinMode(servoHandler.pin, PWM_OUTPUT);
	digitalWrite(servoHandler.pin, LOW);
	softPwmCreate(servoHandler.pin, servoHandler.position, servoHandler.range);
	softPwmWrite(servoHandler.pin, 0);
}

void servoUpdate(StServoHandler servoHandler, uint16_t position) {
	servoHandler.position = position;
	softPwmWrite(servoHandler.pin, servoHandler.position);
}
