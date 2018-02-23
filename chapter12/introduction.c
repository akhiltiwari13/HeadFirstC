#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void error_and_exit(char *msg)
{
    fprintf(stderr, "%s: %s", msg ,strerror(errno));
    exit(1); //exit the process with the error
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s", msg ,strerror(errno));
}

// defining function to be run on thread 1.
void *funct_thrd1()
{
    for(int i=0; i<5; i++)
    {
        puts("function for thread 1");
        sleep(1);
    }
    return NULL;
}

// definig function to be run on thread 2
void *funct_thrd2()
{
    for(int i=0; i<5; i++)
    {
        puts("function for thread 2");
        sleep(1);
    }
    return NULL;
}

// main.

int main()
{
    /*These two pthread_t data structures will hold the information of the two threads*/
    pthread_t *thr0= (pthread_t *)malloc(sizeof(pthread_t));
    pthread_t *thr1= (pthread_t *)malloc(sizeof(pthread_t));
    
    /*---modified the multiple thread call using function pointer----*/
    void *(*fuct_pointer_1)()=funct_thrd1;
    void *(*funct_pointer_2)()=funct_thrd2;
    
    /*creating threads*/
    if(pthread_create(thr0, NULL, fuct_pointer_1, NULL)==-1)
    {
        error_and_exit("can't create thread1");
    }
     if(pthread_create(thr1, NULL, funct_pointer_2, NULL)==-1)
    {
        error_and_exit("can't create thread2");
    }
    
    /*Once the threads have been created and started we need to wait and get their exit statuses*/
    void *result;
    if(pthread_join(*thr0, &result)== -1)
    {
        error("can't wait for the thread1");
    }
    if(pthread_join(*thr1, &result)== -1)
    {
        error("can't wait for the thread2");
    }
    
    
    return 0;
} 