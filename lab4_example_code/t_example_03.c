#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *cancel_thread(void *arg) {
    printf("Cancel [%s] My thread id is %ld and I will count up to 15!\n", arg, pthread_self());
    for (int i=1; i<16;i++) {
        sleep(1);
        printf("[%s] %d\n", arg, i);
    }
    return 0;
}

void *detach_thread(void *arg) {
    printf("Detach [%s]My thread id is %ld and I will count up to 15!\n", arg, pthread_self());
    pthread_detach(pthread_self());
    for (int i=1; i<16;i++) {
        sleep(1);
        printf("[%s] %d\n", arg, i);
    }
    return 0;

}

int main(int argc, char *argv[]) {
    pthread_t tid[3];
    int status;


    status = pthread_create(&tid[0], NULL, cancel_thread, "cancel_thread");
    if (status!=0) {
        printf("error creating thread\n");
        return 0;
    }

    for (int i=1; i<3;i++) {
        status = pthread_create(&tid[i], NULL, detach_thread, "detach_thread");
        if (status!=0) {
            printf("error creating thread\n");
        }
    }
    //pthread_detach(tid[1]);
    sleep(5);
 
    status = pthread_cancel(tid[0]);
    if (status!=0) {
        printf("Failed to cancel thread %ld\n", tid[0]);
    }  
    else {
        printf("canceled thread %ld\n", tid[0]);
    }

    status = pthread_join(tid[1], NULL);
     if (status!=0) {
        printf("Failed to join thread %ld\n", tid[1]);
    }  
    else {
        printf("join thread %ld\n", tid[1]);
    }

    status = pthread_cancel(tid[2]);
     if (status!=0) {
        printf("Failed to cancel thread %ld\n", tid[2]);
    }  
    else {
        printf("canceled thread %ld\n", tid[2]);
    }   



    printf("main process finished\n");
    return 0;

}