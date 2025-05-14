#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

static int global;

void print_addr(void* g, void* m, void* t, void* ts){
    printf("%p\t%p\t%p\t%p\n", g, m, t, ts);
}

void* worker(void* arg){
    int thread;
    static int thread_static;

    print_addr(&global, arg, &thread, &thread_static);

    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    static int main_static;

    pthread_t tids[NUM_THREADS];
    int status;

    printf("global\t\tmain\t\tthread\t\tthread-static\n");
    print_addr(&global, &main, 0, 0);


    for(int i = 0; i < NUM_THREADS; i++){
        status = pthread_create(&tids[i], NULL, worker, &main_static);

        if(status != 0){
            printf("WTF?");
            return -1;
        }
    }
    for(int i =0; i<NUM_THREADS; i++){
        pthread_join(tids[i], NULL);
    }

    return 0;
}

/*
Expected output:

global		main		thread		thread-static
AxAAAAAA	BxBBBBBB	(nil)	    (nil)
AxAAAAAA	CxCCCCCC	DxDD....	ExEEEEEE
AxAAAAAA	CxCCCCCC	DxDD....	ExEEEEEE
AxAAAAAA	CxCCCCCC	DxDD....	ExEEEEEE
*/
