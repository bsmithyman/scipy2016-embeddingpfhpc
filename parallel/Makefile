
CFLAGS=$(shell python-config --cflags)
LDFLAGS=$(shell python-config --ldflags)
FFLAGS=-static-libgcc


all: hellompif hellompic hellomppy hellompipy

hellompif: hellompi.f
	/usr/local/bin/mpif90 $(FFLAGS) -o hellompif hellompi.f

hellompic: hellompi.c
	mpicc -o hellompic hellompi.c

hellomppy: hellomp.py
	chmod +x hellomp.py

hellompipy: hellompi.py
	chmod +x hellompi.py

clean:
	rm hellompic hellompif
