# -*- encoding: utf-8 -*-

from distutils.core import setup, Extension, os

## Escolha entre compilar para PC ou Raspberry:
platform = "Raspberry"

# PC serve apenas para testes da geração da biblioteca para Python.
# O binário gerado não tem serventia no PC pois não roda nem no PC nem no Rasp.
if (platform == "PC"):
	os.environ["CC"] = "arm-linux-gnueabihf-gcc"
	os.environ["LDSHARED"] = "arm-linux-gnueabihf-gcc -shared"
	sysroot_args = ["--sysroot","-I /home/fabio/Raspberry/wiringPi/compiledForRaspberry", "-I /home/fabio/Eclipse C/cross-compile tools/tools/arm-bcm2708/arm-linux-gnueabihf/include", "/home/fabio/Eclipse C/cross-compile tools/tools/arm-bcm2708/arm-linux-gnueabihf/bin"]

	module1 = Extension('servo',
					sources = ['servomodule.c'],
					libraries = ['wiringPi', 'pthread'],
					include_dirs = ["/home/fabio/Raspberry/wiringPi/compiledForRaspberry"],					
					library_dirs = ["/home/fabio/Raspberry/wiringPi/compiledForRaspberry"],
					extra_compile_args = sysroot_args,
					extra_link_args = sysroot_args)

# Para compilar diretamente no Raspberry (Não é compilação cruzada!).
# Gera o binário válido da biblioteca para Python.
elif (platform == "Raspberry"):
	module1 = Extension('servo',
					sources = ['servomodule.c'],
					libraries = ['wiringPi', 'pthread'])
else:
	print "Erro! Plataforma desconhecida!"

setup (name = 'servo', 
	version = '1.0', 
	description = 'Controla um servo motor',
	author = 'Fabio Crestani',
	ext_modules = [module1])
