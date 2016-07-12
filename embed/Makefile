
CFLAGS=$(shell python-config --cflags)
LDFLAGS=$(shell python-config --ldflags)


all: host

host: host.c
	gcc $(CFLAGS) $(LDFLAGS) -o host host.c

clean:
	rm host
