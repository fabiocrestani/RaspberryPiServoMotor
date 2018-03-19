/**
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "servo.h"
#include "ipc.h"

int main(void) {
	// Inicializa fila de mensagens
	printf("Iniciando IPC...\n\r");
	ipcInit();

	// Inicializa controle do servo
	printf("Iniciando PWM...\n\r");
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

	printf("Tudo pronto. Iniciando aplicação.");

	while (1) {
		int c = 0;
		scanf("%i", &c);
		servoUpdate(servo, c);

		char message[IPC_QUEUE_MAX_SIZE];
		int ret = ipcReceive(message);
		if (ret > 0) {
			printf("Mensagem lida da fila: %s\n\r", message);
		} else {
			printf("Nenhuma mensagem na fila.\n\r");
		}

		delay(1000);
	}

	return EXIT_SUCCESS;
}
