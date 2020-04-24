CC=gcc
OPT=-std=c99
CFLAGS=-I.
THRD=-pthread

all : task1 task3 task5

task5 : utils.o 
	$(CC) $(OPT) $(THRD) -o task5 utils.o parallel_sum.c $(CFLAGS)

task3 : 
	$(CC) process_memory.c -o task3

task1 : utils.o find_min_max.o ./src_l3/utils.h ./src_l3/find_min_max.h
	$(CC) $(OPT) -o task1 utils.o find_min_max.o ./src_l3/parallel_min_max.c $(CFLAGS)

utils.o : ./src_l3/utils.h
	$(CC) -o utils.o -c ./src_l3/utils.c $(CFLAGS)

find_min_max.o : ./src_l3/utils.h ./src_l3/find_min_max.h
	$(CC) -o find_min_max.o -c ./src_l3/find_min_max.c $(CFLAGS)

clean :
	rm utils.o find_min_max.o task1 task3 task5