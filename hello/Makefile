
CFLAGS=$(shell python-config --cflags)
LDFLAGS=$(shell python-config --ldflags)
FFLAGS=-static-libgcc


all: helloc hellof hellopy hellocy

helloc: hello.c
	gcc -o helloc hello.c

hellof: hello.f
	gfortran $(FFLAGS) -o hellof hello.f

hellopy: hello.py
	chmod +x hello.py

hellocy.c: hello.pyx
	cython -2 --embed -o hellocy.c hello.pyx

hellocy: hellocy.c
	gcc $(CFLAGS) $(LDFLAGS) -o hellocy hellocy.c

clean:
	rm helloc hellof hellocy hellocy.c
