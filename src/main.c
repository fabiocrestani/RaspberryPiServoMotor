/**
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "servo.h"

int main(void) {
	// Inicializa controle do servo
	printf("Iniciando PWM...\n\r");
	const int PWM_PIN = 15; 	// WiringPi pin convention
	const int PWM_RANGE = 400;
	int position = 0;
	StServoHandler servo = { PWM_PIN, PWM_RANGE, position };
	servoInitAll(servo);
	delay(1000);

	for (position = 0; position < 27; position++) {
		servoUpdate(servo, position);
		delay(200);
	}

	printf("Tudo pronto. Iniciando aplicação.");

	while (1) {
		int c = 0;
		scanf("%i", &c);
		servoUpdate(servo, c);
		delay(1000);
	}

	return EXIT_SUCCESS;
}
