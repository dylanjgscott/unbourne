CC=gcc
CFLAGS=-g -std=gnu90 -pedantic -Wall -Wextra

all: unbourne

unbourne: unbourne.o handle.o parse.o clear.o dir.o env.o quit.o init.o cd.o
	$(CC) -o $@ $^

unbourne.o: unbourne.c unbourne.h
	$(CC) $(CFLAGS) -c -o $@ $<

handle.o: handle.c handle.h
	$(CC) $(CFLAGS) -c -o $@ $<

parse.o: parse.c parse.h builtins.h
	$(CC) $(CFLAGS) -c -o $@ $<

clear.o: clear.c clear.h
	$(CC) $(CFLAGS) -c -o $@ $<

dir.o: dir.c dir.h
	$(CC) $(CFLAGS) -c -o $@ $<

env.o: env.c env.h
	$(CC) $(CFLAGS) -c -o $@ $<

quit.o: quit.c quit.h
	$(CC) $(CFLAGS) -c -o $@ $<

cd.o: cd.c cd.h
	$(CC) $(CFLAGS) -c -o $@ $<

init.o: init.c init.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm unbourne *.o
