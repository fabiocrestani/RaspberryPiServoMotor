/**
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "servo.h"

int main(void) {
	printf("Iniciando aplicação de controle de servomotor\n\r");

	if (wiringPiSetup() == -1) {
		printf("Erro ao inicializar WiringPi\n\r");
		exit(1);
	}

	const int PWM_PIN = 15; 	// WiringPi pin convention
	const int PWM_RANGE = 400;
	int position = 0;
	StServoHandler servo = { PWM_PIN, PWM_RANGE, position };

	servoInit(servo);
	delay(1000);

	for (position = 0; position < 27; position++) {
		servoUpdate(servo, position);
		delay(200);
	}

	return EXIT_SUCCESS;
}
