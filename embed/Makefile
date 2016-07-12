
CFLAGS=$(shell python-config --cflags)
LDFLAGS=$(shell python-config --ldflags)


all: basic

basic: basic.c
	gcc $(CFLAGS) $(LDFLAGS) -o basic basic.c

clean:
	rm host
