#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5
pthread_t tid[NUM_THREADS];

void *hello_thread(void *arg){
    int i = 0;
    while(1) {
        if(i==5) {break;}
        i++;
        sleep(1);
    }
    printf("thread%ld termianted...\n", (intptr_t)arg);
    pthread_exit((void*)(intptr_t)i);
}

void main(){
    long int i, status;
    printf("pid: %d\n", getpid());
    for (i=0;i<NUM_THREADS;i++) {
        status = pthread_create(&tid[i], NULL, &hello_thread, (void *)(intptr_t)i);
        if (status!=0){
            fprintf(stderr, "create thread%ld, status: %ld\n", i, status);
            exit(1);
        }
        printf("thread:%ld is created...\n", i);
    }
    for (i=0;i<NUM_THREADS;i++){
        void *return_value;
        pthread_join(tid[i], &return_value);
        printf("thread%ld's return value is %ld\n", i,(intptr_t)return_value);
    }
}