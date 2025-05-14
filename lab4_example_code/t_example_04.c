#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TOTAL_THREAD 50
#define EXPECTED 10

pthread_mutex_t lock;
int count = EXPECTED;
int countdown = 3;

void *add_thread(void *arg) {
    while (countdown !=0);
    for (int i = 0; i< 10; i++) {
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}
void *sub_thread(void *arg) {
    while (countdown !=0);
    for (int i = 0; i<10; i++) {
        pthread_mutex_lock(&lock);
        count--;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    pthread_t tid[TOTAL_THREAD];
    int status;
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i<TOTAL_THREAD; i++) {
        if (i % 2 == 0) {
            pthread_create(&tid[i], NULL, add_thread, NULL);
        }
        else {
            pthread_create(&tid[i], NULL, sub_thread, NULL);
        }
    }

    for (int i = 0; i<4; i++) {
        sleep(1);
        printf("starting in %d\n", countdown--);
    }

    for (int i = 0; i<TOTAL_THREAD; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("expected : %d\n", EXPECTED);
    printf("result: %d\n", count);

    return 0;
}

