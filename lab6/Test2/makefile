CC=gcc
CFLAGS=-I.

debug: clean all

all : server client

server : server.o mult_modulo.h mult_modulo.o
	$(CC) -o server -lpthread server.o mult_modulo.o

client : client.o mult_modulo.h mult_modulo.o
	$(CC) -o client client.o mult_modulo.o

server.o : mult_modulo.h
	$(CC) -o server.o -c -std=c99 server.c $(CFLAGS)

client.o : mult_modulo.h
	$(CC) -o client.o -c -std=c99 client.c $(CFLAGS)

mult_modulo.o : mult_modulo.h
	$(CC) -o mult_modulo.o -c -std=c99 mult_modulo.c $(CFLAGS)

clean : 
	rm client.o client server.o server mult_modulo.o