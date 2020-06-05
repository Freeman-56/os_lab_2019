CC=gcc
CFLAGS=-I.

debug: clean all

all : server client

server : server.o 
	$(CC) -o server -lpthread server.o -L. -lmult_modulo

client : client.o 
	$(CC) -o client client.o -L. -lmult_modulo

server.o :
	$(CC) -o server.o -c -std=c99 -L. -lmult_modulo server.c $(CFLAGS)

client.o : 
	$(CC) -o client.o -c -std=c99 -L. -lmult_modulo client.c $(CFLAGS)

clean : 
	rm client.o client server.o server 