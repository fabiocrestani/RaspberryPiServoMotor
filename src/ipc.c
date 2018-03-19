/*
 * ipc.c
 *
 *  Created on: 18 de mar de 2018
 *      Author: fabio
 */

#include <sys/msg.h>
#include <sys/ipc.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "ipc.h"

stMsg ipcMsg;
int mqHandler;

void ipcInit(void) {
	mqHandler = msgget(IPC_QUEUE_KEY, IPC_CREAT);
	assert(mqHandler != -1);
}

int ipcReceive(char message[]) {
	memset(ipcMsg.message, 0, IPC_QUEUE_MAX_SIZE);
	int ret = msgrcv(mqHandler, (stMsg *) &ipcMsg, IPC_QUEUE_MAX_SIZE,
			ipcMsg.type, 0);
	memcpy(message, ipcMsg.message, IPC_QUEUE_MAX_SIZE);
	return ret;
}

// Removes the message queue.
// Once removed it cannot be used again.
void ipcRemove() {
	int ret = msgctl(mqHandler, IPC_RMID, 0);
	assert(ret != -1);
}
