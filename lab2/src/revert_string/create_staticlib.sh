#!/bin/bash
gcc -c revert_string.c
ar rc libstatic.a revert_string.o
gcc -c main.c
gcc main.o -L. -lstatic -o resultstat.out