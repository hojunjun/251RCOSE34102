#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    pid_t pid;
    int val = 10;

    printf("The original value is %d\n", val);
    printf("The parent will now add 1 and the child will subtract 3\n");
    
    pid = fork();

    if(pid>0){
        // HINT: The parent process should fall into this scope.
        val++;
        sleep(1);
    } else if(pid==0) {
        // HINT: The child process should fall into this scope.
        sleep(2);
        val = val -3;
    } else {
        printf("something went wrong");
        return -1;
    }
    
    printf("The value of %s is %d.\n", pid == 0 ? "child" : "parent", val);

    return 0;
}




/*
Expected output:

The original value is 10
The parent will now add 1 and the child will subtract 3
The value of parent is 11
The value of child is 7
*/
