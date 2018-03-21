# Esse script compila para arquitetura PC x86_64
# Portanto, a wiringPi não vai funcionar, uma vez que não é um Raspberry.

from distutils.core import setup, Extension, os

module1 = Extension('servo',
					sources = ['servomodule.c'],
					include_dirs = ['/home/fabio/Raspberry/wiringPi/wiringPi/wiringPi'],
					libraries = ['wiringPi', 'pthread'],
					library_dirs = ['/home/fabio/Raspberry/wiringPi/wiringPi/wiringPi'])

setup (name = 'servo', 
	version = '1.0', 
	description = 'Controla um servo motor',
	author = 'Fabio Crestani',
	ext_modules = [module1])
