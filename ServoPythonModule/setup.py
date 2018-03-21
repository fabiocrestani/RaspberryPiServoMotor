from distutils.core import setup, Extension, os

os.environ["CC"] = "arm-linux-gnueabihf-gcc"
os.environ["LDSHARED"] = "arm-linux-gnueabihf-gcc -shared"
sysroot_args = ["--sysroot","-I /home/fabio/Raspberry/wiringPi/compiledForRaspberry", "-I /home/fabio/Eclipse C/cross-compile tools/tools/arm-bcm2708/arm-linux-gnueabihf/include", "/home/fabio/Eclipse C/cross-compile tools/tools/arm-bcm2708/arm-linux-gnueabihf/bin"]

module1 = Extension('servo',
					sources = ['servomodule.c'],
					#include_dirs = ['/home/fabio/Raspberry/wiringPi/wiringPi/wiringPi'],
					libraries = ['wiringPi', 'pthread'],
					#library_dirs = ['/home/fabio/Raspberry/wiringPi/wiringPi/wiringPi'],
					include_dirs = ["/home/fabio/Raspberry/wiringPi/compiledForRaspberry"],					
					library_dirs = ["/home/fabio/Raspberry/wiringPi/compiledForRaspberry"],
					extra_compile_args = sysroot_args,
					extra_link_args = sysroot_args)

setup (name = 'servo', 
	version = '1.0', 
	description = 'Controla um servo motor',
	author = 'Fabio Crestani',
	ext_modules = [module1])
