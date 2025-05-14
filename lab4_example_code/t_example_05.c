#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

pthread_mutex_t lock1, lock2;
int a = 10;
int b = 20;

void *first_thread(void *arg) {
    int id = (int)arg;
    printf("[thread %d] trying to access object A...\n", id);
    sleep(2);
    pthread_mutex_lock(&lock1);
    printf("[thread %d] Accessed object A! Current A = %d\n",id, a);
    printf("[thread %d] trying to access object B...\n", id);
    sleep(2);
    pthread_mutex_lock(&lock2);
    printf("[thread %d] Accessed object B! Current B = %d\n",id, b);
    a = 20;
    b = 10;
    printf("[thread %d] changed A to 20 and B to 10\n", id);
    pthread_exit(NULL);

}

void *second_thread(void *arg) {
    int id = (int)arg;
    printf("[thread %d] trying to access object B...\n", id);
    sleep(2);
    pthread_mutex_lock(&lock2);
    printf("[thread %d] Accessed object B! Current B = %d\n",id, b);
    printf("[thread %d] trying to access object A...\n", id);
    sleep(2);
    pthread_mutex_lock(&lock1);
    printf("[thread %d] Accessed object A! Current A = %d\n",id, a);
    a = 2;
    b = 1;
    printf("[thread %d] changed A to 2 and B to 1\n", id);
    pthread_exit(NULL);

}

int main(int argc, char *argv[]) {
    pthread_t tid[2];
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    int status;

    status = pthread_create(&tid[0], NULL, first_thread, (void *) 1);
    if (status != 0) {
        printf("error creating thread 1\n");
        return -1;
    }
    status = pthread_create(&tid[1], NULL, second_thread, (void *) 2);
    if (status != 0) {
        printf("error creating thread 2\n");
        return -1;
    }

    for (int i = 0; i<2; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}