#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv) {
    pid_t child;
    int status;
    child = fork();
    if(child > 0){
        sleep(100);
    }
    else 
        exit(0);


}