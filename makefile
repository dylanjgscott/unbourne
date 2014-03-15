CC=gcc
CFLAGS=-g -ansi -pedantic -Wall -Wextra

all: unbourne

unbourne: unbourne.o handle.o parse.o
	$(CC) $(CFLAGS) -o $@ $^

unbourne.o: unbourne.c unbourne.h
	$(CC) $(CFLAGS) -c -o $@ $<

handle.o: handle.c handle.h
	$(CC) $(CFLAGS) -c -o $@ $<

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm unbourne
	rm unbourne.o
	rm handle.o
	rm parse.o
