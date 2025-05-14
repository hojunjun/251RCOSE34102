#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *hello_thread(void *arg) {
    printf("thread: hello\n");
    return arg;
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    int status;

    status = pthread_create(&tid, NULL, hello_thread, NULL);
    if (status!=0) {
        perror("create thread\n");
        pthread_exit(NULL);
    }
    sleep(2);
    return 0;
}   