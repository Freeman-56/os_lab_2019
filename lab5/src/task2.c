#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <sys/time.h>

#include <pthread.h>

struct FactArgs{
    int begin;
    int end;
    int mod;
};
int result = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int Factorial(const struct FactArgs *args)
{
    int fact = 1;
    int i;
    for(i = args->begin; i < args->end; i++){
        fact *= i;
        fact %= args->mod;
    }

    pthread_mutex_lock(&mutex);
    result *= fact;
    result %= args ->mod;
    pthread_mutex_unlock(&mutex);
    
    return fact;
}

void *ThreadFact(void *args) {
  struct FactArgs *fact_args = (struct FactArgs*)args;
  return (void *)(size_t)Factorial(fact_args);
}

int main(int argc, char **argv) {
    int threads_num = -1;
    int seed = -1;
    int array_size = -1;
    int current_optind = optind ? optind : 1;
    while(true){
        static struct option options[] = {{"pnum", required_argument, 0, 0},
                                        {"mod", required_argument, 0, 0},
                                        {0, 0, 0, 0}};
                                        
        int option_index = 0;
        int c = getopt_long(argc, argv, "", options, &option_index);
    if (c == -1) break;
        switch (c) {
        case 0:
            switch (option_index) {
            case 0:
                threads_num = atoi(optarg);
                break;
            case 1:
                seed = atoi(optarg);
                break;
            case 2:
                array_size = atoi(optarg);
                break;
            defalut:
                printf("Index %d is out of options\n", option_index);
            }
            break;
        case '?':
            break;
        default:
            printf("getopt returned character code 0%o?\n", c);
        }
    }   
    
}


