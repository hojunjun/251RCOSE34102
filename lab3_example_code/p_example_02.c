#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv){
    pid_t pid;
    int status;

    pid = fork();

    if(pid>0) {
        printf("Parent waiting...\n");
        wait(&status);
        printf("3 * 256 is %d\n", status);
    }
    else if (pid == 0) {
        sleep(1);
        printf("child exits with 3\n");
        exit(3);
    }
    else {
        return -1;
    }

}