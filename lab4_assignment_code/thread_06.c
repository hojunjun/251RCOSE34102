#include <stdio.h>
#include <stdatomic.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

#define NUM_SUBS 3
#define NUM_TASKS 3
#define NUM_TOTAL_TASK (NUM_SUBS * NUM_TASKS)
#define SPREADING 2

static _Atomic int cnt_task = NUM_TOTAL_TASK;
pthread_mutex_t lock;

void spread_words(char* sub){\
    sleep(SPREADING);
    printf("[%s] spreading words...\n", sub);
    cnt_task--;
}

void* subordinate(void* arg)
{
    char sub[20];
    sprintf(sub, "%s %d", "subordinate", (int)arg);
    printf("[%s] as you wish\n", sub);

    for(int i = 0; i < 3; i++)
    {
        spread_words(sub);
    }
    printf("[%s] I am done!\n", sub);
    //hint: finish up the threads
    pthread_exit(NULL);
}

void* king(void* arg)
{
    pthread_t tid[NUM_SUBS];
    int status;
    printf("spread the words that I am king!\n");


    //hint: start your subordinates
    //hint: for??????
    for (int i=0;i<NUM_SUBS;i++){
        //start workers
        status = pthread_create(&tid[i], NULL, subordinate, (void*)i); //feel free to move this around
    }
    //hint: try using some locks and for
    for (int i=0;i<NUM_SUBS;i++){
        pthread_mutex_lock(&lock);
        pthread_join(tid[i], NULL); //feel free to move this around
    //BUT DO NOT move it outside the king function
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    int status;
    pthread_mutex_init(&lock, NULL);

    status = pthread_create(&tid, NULL, king, NULL);

    if (status != 0)
    {
        printf("error");
        return -1;
    }

    pthread_detach(tid);

    //added
    sleep(2);
    
    //hint: look at king function
    //do NOT use pthread_join
    //hint: locks
    pthread_mutex_lock(&lock);

    printf("The words have been spread...\n");\

    return 0;
}

/*
Expected output:

spread the words that I am king!
[subordinate x] as you wish
[subordinate y] as you wish
[subordinate z] as you wish
[subordinate x] spreading words...
[subordinate y] spreading words...
[subordinate z] spreading words...
[subordinate x] spreading words...
[subordinate y] spreading words...
[subordinate z] spreading words...
[subordinate x] spreading words...
[subordinate y] spreading words...
[subordinate z] spreading words...
The words have been spread...

*/