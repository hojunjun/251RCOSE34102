#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    pid_t pid;
    int status;

    printf("Counting to three.\n");

    printf("1!\n");

    pid = fork();

    if(pid>0){
        // HINT: The parent process should fall into this scope.
        wait(&status);
        printf("%d!\n", status>>8);
    } else if(pid==0){
        // HINT: The child process should fall into this scope.
        sleep(1);
        printf("2!\n");
        exit(3);
        printf("4!");
    } else {
        printf("4,321,222");
        return -1;
    }
    return 0;
}




/*
Expected output:

counting to three.
1!
2!
3!


*/
