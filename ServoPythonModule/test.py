# -*- coding: utf-8 -*-

import servo
import time

# Classe simples para guardar dados de pino, alcance e posição do servo
class Servo:
	def __init__(self, pin, range, position):
		self.pin = pin
		self.range = range
		self.position = position
	
	def __str__(self):
		return "Pino: " + str(self.pin) + " Range: " + str(self.range) \
									  + " Position: " + str(self.position) 

# Principal
servoHandler = Servo(15, 300, 0)

print "[Py] Inicializando wiringPi com servo configurado: " + str(servoHandler)
ret = servo.init(servoHandler.pin, servoHandler.range, servoHandler.position)
print "ret = " + str(ret);

servoHandler.position = 10;
print "[Py] Atualizando posição do servo para: " + str(servoHandler.position)
ret = servo.update2(servoHandler.pin, servoHandler.range, servoHandler.position)
print "ret = " + str(ret);

time.sleep(3);



servoHandler.position = 30;
print "[Py] Atualizando posição do servo para: " + str(servoHandler.position)
ret = servo.update2(servoHandler.pin, servoHandler.range, servoHandler.position)
print "ret = " + str(ret);

#servoHandler.position = 30;
#print "[Py] Atualizando posição do servo para: " + str(servoHandler.position)
#ret = servo.update2(servoHandler.position)
#print "ret = " + str(ret);
