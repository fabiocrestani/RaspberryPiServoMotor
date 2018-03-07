# Controle de servo motor

Este é um controle simples de servo motor no Raspberry Pi utilizando a biblioteca wiringPi.

A grande sacada é que suporta compilação cruzada no Eclipse rodando em um PC com Ubuntu e debugando direto no Raspberry via ssh.



## Como preparar o ambiente

* Configurar o Eclipse de acordo com: https://github.com/awesomebytes/xenorasp/wiki/Crosscompile-a-program-from-your-computer-to-your-Raspberry-Pi
* Instalar o wiringPi no Raspberry: http://wiringpi.com/download-and-install/
* Copiar o **wiringPi.h** e o binário da biblioteca (**libWiringPi.a** ou **libWiringPi.so**) para o PC
* Apontar o *libraries search path* do Eclipse para os arquivos copiados do wiringPi
* Incluir a flag **-lwiringPi** no compilador
* Como esta aplicação utilizada o PWM gerador por software, é necessário incluir também **-lpthread**