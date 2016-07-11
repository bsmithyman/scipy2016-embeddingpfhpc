
CFLAGS=$(shell python-config --cflags)
LDFLAGS=$(shell python-config --ldflags)
FFLAGS=-static-libgcc


all: hellocy.so

hellof.o: hellof.f
	gfortran hellof.f -c -o hellof.o -fPIC

hellocy.so: hellocy.pyx helloc.c hellof.o
	python setup.py build_ext --inplace

clean:
	rm hellocy.c hellocy.so hellof.o
