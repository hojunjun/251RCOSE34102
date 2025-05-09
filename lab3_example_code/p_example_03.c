#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv){
    pid_t pid, pid2;
    int status;

    pid = fork();

    if(pid>0) {
        pid2 = fork();
        if(pid2>0) {
            printf("Parent waiting for first process %d...\n", pid);
            waitpid(pid, &status, 0);
            printf("parent exiting...\n");
            printf("my wait was 7 * 256 which is %d\n", status);
        }
        else if (pid2==0) {
            sleep(1);
            printf("I am process %d and exiting with 5\n", getpid());
            exit(5);
        }
        else {
            return -1;
        }
    }
    else if (pid==0) {
        sleep(3);
        printf("I am process %d and exiting with 7\n", getpid());
        exit(7);
    }
    else {
        return -1;
    }
    return 0;
}