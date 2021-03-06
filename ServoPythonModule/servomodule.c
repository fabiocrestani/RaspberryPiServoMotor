#include <Python.h>
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdint.h>

#define WIRINGPI_CODES 1 // mostrar códigos de retorno do wiringPiSetup()

typedef struct ServoHandler {
	uint8_t pin;
	uint16_t range;
	uint16_t position;
} StServoHandler;

StServoHandler servoHandler;

static PyObject *ServoError;
static PyObject *servo_init(PyObject *self, PyObject *args);
static PyObject *servo_update(PyObject *self, PyObject *args);
static PyObject *servo_update2(PyObject *self, PyObject *args);

// Lista dos métodos presentes neste módulo
static PyMethodDef ServoMethods[] = {
	{"init", servo_init, METH_VARARGS, "Inicializa o servo motor"},
	{"update", servo_update, METH_VARARGS, "Atualiza a posição do servo motor"},	
	{"update2", servo_update2, METH_VARARGS, "Atualiza a posição do servo motor"},	
	{NULL, NULL, 0, NULL}
};

// Inicializa o módulo Python
PyMODINIT_FUNC initservo(void) {
	PyObject *m;

	m = Py_InitModule("servo", ServoMethods);
	if (m == NULL) {
		return; 
	}

	ServoError = PyErr_NewException("servo.error", NULL, NULL);
	Py_INCREF(ServoError);
	PyModule_AddObject(m, "error", ServoError);
}

// Inicializa o servo motor 
static PyObject *servo_init(PyObject *self, PyObject *args) {
	int ret;
	if (!PyArg_ParseTuple(args, "iii", &servoHandler.pin, &servoHandler.range, 
									   &servoHandler.position)) {
		return NULL;
	}

	printf("[C] Inicializando servo com os parâmetros: Pino: %d, Range: %d \
Position: %d\n\r", servoHandler.pin, servoHandler.range, servoHandler.position);
	
	ret = wiringPiSetup();

	if (ret < 0) {
		PyErr_SetString(ServoError, "Init command failed");
		return Py_BuildValue("i", ret);
	}

	pinMode(servoHandler.pin, PWM_OUTPUT);
	digitalWrite(servoHandler.pin, LOW);
	softPwmCreate(servoHandler.pin, servoHandler.position, servoHandler.range);
	//softPwmWrite(servoHandler.pin, 0);

	return Py_BuildValue("i", ret);
}

// Atualiza posição do servo motor 
static PyObject *servo_update(PyObject *self, PyObject *args) {
	if (!PyArg_ParseTuple(args, "i", &servoHandler.position)) {
		return Py_BuildValue("i", 0);
	}

	printf("[C] Atualizando posição do servo para: %d\n\r", 
		   servoHandler.position);
	
	softPwmWrite(servoHandler.pin, servoHandler.position);
	return Py_BuildValue("i", 1);
}

// Atualiza posição do servo motor
static PyObject *servo_update2(PyObject *self, PyObject *args) {
	if (!PyArg_ParseTuple(args, "iii", &servoHandler.pin, &servoHandler.range, 
									   &servoHandler.position)) {
		return Py_BuildValue("i", 0);
	}

	printf("[C] 2 Atualizando posição do servo para: %d\n\r", 
		   servoHandler.position);
	
	softPwmWrite(servoHandler.pin, servoHandler.position);
	return Py_BuildValue("i", 1);
}
