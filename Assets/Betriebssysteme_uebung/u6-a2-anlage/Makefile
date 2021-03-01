CFLAGS = -g

all: daemon

clean:
	rm -f helpers.o daemon.o daemon

helpers.o: helpers.c helpers.h

daemon.o: daemon.c helpers.h

daemon: daemon.o helpers.o
	$(CC) -o daemon daemon.o helpers.o
