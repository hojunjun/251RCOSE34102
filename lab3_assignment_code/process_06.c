#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv){
    pid_t pid, pid2;
    int status;

    printf("counting to 5!\n");
    pid = fork();

    if(pid>0) {
        pid2 = fork();

        if(pid2>0) {
            printf("1!\n");
            waitpid(pid, &status, 0);
            printf("3!\n");
            waitpid(pid2, &status, 0);
            printf("5!\n");
        }
        else if (pid2==0) {
            sleep(3);
            printf("4!\n");
            exit(3);
        }
        else {
            return -1;
        }
    }
    else if (pid==0) {
        sleep(1);
        printf("2!\n");
        exit(2);
    }
    else {
        return -1;
    }
    return 0;
}

/*
expected output

counting to 5!
1!
2!
3!
4!
5!

*/