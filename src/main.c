/**
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main(void) {
	printf("Iniciando aplicação de controle de servomotor\n\r");

	const int PWM_PIN = 15; // WiringPi pin convention

	int dutyCycle = 0;

	if (wiringPiSetup() == -1) {
		printf("Erro ao inicializar WiringPi\n\r");
		exit(1);
	}

	pinMode(PWM_PIN, PWM_OUTPUT);
	digitalWrite(PWM_PIN, LOW);
	softPwmCreate(PWM_PIN, 0, 400);
	softPwmWrite(PWM_PIN, 0);
	delay(1000);

	for (dutyCycle = 0; dutyCycle < 27; dutyCycle++) {
		softPwmWrite(PWM_PIN, dutyCycle);
		delay(200);
	}

	return EXIT_SUCCESS;

}
