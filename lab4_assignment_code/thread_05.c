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

void spread_words(char* sub){\
    sleep(SPREADING);
    printf("[%s] spreading words...\n", sub);
    cnt_task--;
}

void* subordinate(void* arg)
{
    char sub[20];
    sprintf(sub, "%s %d", "subordinate", (int)arg);
    sleep(2);
    printf("[%s] as you wish\n", sub);

    for(int i = 0; i < 3; i++)
    {
        spread_words(sub);
    }
    sleep(1);
    //hint: finish up the threads
    pthread_exit(NULL);
}

void* king(void* arg)
{
    pthread_t tid;
    int status;
    printf("spread the words ");

    //hint: you should start your subordinates here
    //hint: for???
    for(int i=0; i<NUM_SUBS;i++){
        status = pthread_create(&tid, NULL, subordinate, i);
        usleep(10000);
        pthread_detach(tid); //feel free to move this around
    //BUT DON'T move it outside the king function
    }
    
    printf("that I am king!\n");
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    int status;

    status = pthread_create(&tid, NULL, king, NULL);

    if (status != 0)
    {
        printf("error");
        return -1;
    }

    pthread_join(tid, NULL);

    //hint: make the main thread wait for the subordinates to finish
    //do NOT use pthread_join
    //hint: possible in 1 line
    while (cnt_task > 0) usleep(10000);

    printf("The words have been spread...\n");
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