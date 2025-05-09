#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define SLEEP_TIME 2

int main(int argc, char* argv[]){
    pid_t pid;
    int status;
    int parent_pid, child_pid, favorite_number;
    char favorite_fruit[] = "apple";


    printf("Final Question!\n");

    pid = fork();

    //you are allowed to write your own printf
    switch(pid) {
        default:
            parent_pid = getpid();
            //hint: parent_pid =
            printf("[%d] I am a parent\n", parent_pid);
            //hint: how would this process get the result of another???
            wait(&status);
            printf("[%d] ....and my child's favorite number is %d\n", parent_pid, status >> 8);
            break;
        case 0:
            favorite_number = 5;
            child_pid = getpid();
            //hint: child_pid =
            printf("[%d] and I am a child!\n", child_pid);
            printf("[%d] my parent's favorite fruit is %s but he doesn't know that my favorite number is %d\n", child_pid, favorite_fruit, favorite_number);
            exit(favorite_number);
            break;
        case -1:
            printf("and I am ???");
            break;
    }


    return 0;
}

/*
Expected output:

Final Question!
[xxxx] I am a parent
[yyyy] and I am a child!
[yyyy] my parent's favorite fruit is Apple but he doesn't know that my favorite number is 5
[xxxx] ....and my child's favorite number is 5

***xxxx and yyyy are process IDs***
*/
