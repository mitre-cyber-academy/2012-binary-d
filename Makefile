CC=gcc
CFLAGS=-Wall -pedantic -O3 -finline-functions

all: binaryAux.bin

binaryAux.bin: chuckTesta.c
	$(CC) $(CFLAGS) -o binaryAux.bin chuckTesta.c

clean:
	rm binaryAux.bin

