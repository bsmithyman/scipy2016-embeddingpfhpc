
CFLAGS=$(shell python-config --cflags)
LDFLAGS=$(shell python-config --ldflags)
FFLAGS=-static-libgcc


all: stackcy.so

stackf.o: stackf.f
	gfortran stackf.f -c -o stackf.o -fPIC

stackcy.so: stackcy.pyx helloc.c stackf.o
	python setup.py build_ext --inplace

clean:
	rm stackcy.c stackcy.so stackf.o
