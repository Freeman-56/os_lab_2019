gcc -fPIC -c revert_string.c
gcc -shared -o libdynamic.so revert_string.o
gcc -c main.c
gcc main.o -L. -ldynamic -o resultdyn.out
LD_LIBRARY_PATH=/projects/Freeman-56-os_lab_2019/lab2/src/revert_string/
export LD_LIBRARY_PATH