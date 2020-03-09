#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


long SommeInit =0;
pthread_mutex_t mutexsum;


void * printHEllo(void *threadId){
    long tid;
    tid = (long)threadId;
    long localSomme ;
    for (long i = 0; i < 1000000; i++)
    {
        /* code */
        localSomme += tid;
    }
    
    pthread_mutex_lock (&mutexsum);
    SommeInit +=localSomme ;
    pthread_mutex_unlock (&mutexsum);
    
    printf("thread #%ld termine avec succes \n" , tid);
    pthread_exit(NULL);
}



int main(int argc, char const *argv[])
{

    void * status;
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

        for ( t = 0; t < nbThreads; t++)
        {
            /* code */
            pthread_join(myThreads[t],&status);
        }  
    
    }

    printf("\nle resultat est %ld \n", SommeInit);  
   
}

