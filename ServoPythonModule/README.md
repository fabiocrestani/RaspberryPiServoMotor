# Servo Python Module

Módulo Python escrito em C para controle de servo motor.

---

Como chamar funções C no Python.
Referência: https://docs.python.org/2/extending/extending.html

---

### servomodule.c

É o módulo em si. Fornece as funções `servo.init(int pin, int range, int position)` e `servo.update(int position)` que podem ser usadas no Python.

### test.py

Mostra como usar o módulo

### setup.py

Compila e cria em /build o módulo como uma library do C. Usar `python setup.py build` e depois `python setup.py install`.

### compileAndRun.sh

Script que recompila o módulo e executa test.py para facilitar o desenvolvimento. 