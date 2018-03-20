from distutils.core import setup, Extension

module1 = Extension('servo',
					sources = ['servomodule.c'],
					include_dirs = ['/home/fabio/Raspberry/wiringPi/wiringPi/wiringPi'],
					libraries = ['wiringPi'],
					library_dirs = ['/home/fabio/Raspberry/wiringPi/wiringPi/wiringPi'])

setup (name = 'servo', 
	version = '1.0', 
	description = 'Controla um servo motor',
	author = 'Fabio Crestani',
	ext_modules = [module1])
