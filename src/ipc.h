/*
 * ipc.h
 *
 *  Created on: 18 de mar de 2018
 *      Author: fabio
 */

#ifndef IPC_H_
#define IPC_H_

#define IPC_QUEUE_MAX_SIZE 1024
#define IPC_QUEUE_KEY 9001

typedef struct vmsgbuf {
	long int type;
	char message[IPC_QUEUE_MAX_SIZE];
} stMsg;

extern stMsg ipcMsg;

void ipcInit(void);
int ipcReceive(char message[]);
void ipcRemove();

#endif /* IPC_H_ */
