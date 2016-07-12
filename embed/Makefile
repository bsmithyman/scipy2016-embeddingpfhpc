
CFLAGS=$(shell python-config --includes) -I$(shell python -c 'import numpy; print(numpy.get_include())') -fPIC
LDFLAGS=$(shell python-config --ldflags) -L$(shell python-config --prefix)/lib


all: basic embed

basic: basic.c
	gcc $(CFLAGS) $(LDFLAGS) -o basic basic.c

mymod.c: mymod.pyx
	cython -v $< -o $@

mymod.o: mymod.c
	gcc $(CFLAGS) $(LDFLAGS) mymod.c -c -o mymod.o

support.o: support.c
	gcc $(CFLAGS) $(LDFLAGS) support.c -c -o support.o -D DEBUG=1

embed.o: embed.f
	gfortran -fPIC embed.f -c -o embed.o

embed: embed.o support.o mymod.o
	gcc $(CFLAGS) $(LDFLAGS) -fPIC -lgfortran -lm -o embed embed.o support.o mymod.o

clean:
	rm -rf basic embed mymod.c *.o *.dSYM
