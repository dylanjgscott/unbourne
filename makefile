#
# @author Dylan Scott dsco9564
#

CC=gcc
CFLAGS=-g -std=gnu90 -pedantic -Wall -Wextra

all: myshell

myshell: unbourne.o handle.o parse.o clear.o dir.o env.o quit.o init.o cd.o rest.o echo.o help.o redirect.o handle_signal.o
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

rest.o: rest.c rest.h
	$(CC) $(CFLAGS) -c -o $@ $<

help.o: help.c help.h
	$(CC) $(CFLAGS) -c -o $@ $<

echo.o: echo.c echo.h
	$(CC) $(CFLAGS) -c -o $@ $<

init.o: init.c init.h
	$(CC) $(CFLAGS) -c -o $@ $<

handle_signal.o: handle_signal.c handle_signal.h
	$(CC) $(CFLAGS) -c -o $@ $<

redirect.o: redirect.c redirect.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm myshell *.o
