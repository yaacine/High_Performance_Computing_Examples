#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


 
void * printHEllo(void *threadId){
    long tid;
    tid = (long)threadId;
    printf("thread #%ld\n" , tid);
    pthread_exit(NULL);
}



int main(int argc, char const *argv[])
{
    /* code */
    if (argc<1)
    {
        /* code */
        printf("precisez le nombre de threads \n");
        exit(-1);
    }
    else{
        int nbThreads = atoi(argv[1]) ;
        pthread_t myThreads[nbThreads];
        int rc ;
        long t;
        for ( t = 0; t < nbThreads; t++)
        {
            /* code */
            printf("in main : creating thread %ld \n" , t);
            rc= pthread_create(&myThreads[t], NULL, printHEllo, (void *)t);
            if(rc){
                // erreur de creation
                printf("ERROR; return code from pthread_create() is %d\n", rc);
                exit(-1);
            }

        }
        pthread_exit(NULL);
    
    }
    
   
}

