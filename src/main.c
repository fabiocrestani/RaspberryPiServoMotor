/**
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "servo.h"

int main(void) {
	printf("Iniciando aplicação de controle de servomotor\n\r");

	const int PWM_PIN = 15; 	// WiringPi pin convention
	const int PWM_RANGE = 400;

	if (wiringPiSetup() == -1) {
		printf("Erro ao inicializar WiringPi\n\r");
		exit(1);
	}

	StServoHandler servo;
	servoInit(servo, PWM_PIN, PWM_RANGE, 0);
	servoWrite(servo);
	delay(1000);

	int dutyCycle = 0;
	for (dutyCycle = 0; dutyCycle < 27; dutyCycle++) {
		printf("Servo: %d\n\r", dutyCycle);
		servoUpdate(servo, dutyCycle);
		delay(200);
	}

	return EXIT_SUCCESS;
}
