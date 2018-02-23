#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long beer_bottles = 2000000;
/* since the mutex has to be shared between multiple threads it needs to be declared globally*/
pthread_mutex_t mutx_lock = PTHREAD_MUTEX_INITIALIZER; 


void error_and_exit(char* msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    exit(1); // exit the process with the error
}

void error(char* msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
}

// defining function for breaking the beer bottles to be run in 20 threads.
void* break_bottles()
{
    for(int i = 0; i < 100000; i++) {
        /*identifying critical section and protecting it with a mutex*/
        pthread_mutex_lock(&mutx_lock);
        beer_bottles--;
        pthread_mutex_unlock(&mutx_lock);
        /* end of critical section */
    }
    return NULL;
}

int main()
{
    pthread_t break_bottle_thread[20];
    printf("%d bottles of beer on the wall\n", beer_bottles);

    for(int thr_num = 0; thr_num < 20; thr_num++) {
        if(pthread_create(&break_bottle_thread[thr_num], NULL, break_bottles, NULL) == -1)
            error_and_exit("can't spawn a thread");
    }

    void* result;

    for(int thr_num = 0; thr_num < 20; thr_num++) {
        if(pthread_join(break_bottle_thread[thr_num], &result) == -1)
            error_and_exit("can't wait for thread");
        printf("beer bottles left after thread %d are %d\n", thr_num, beer_bottles);
    }

    printf("There are %d bottles of beer\n", beer_bottles);

    return 0;
}