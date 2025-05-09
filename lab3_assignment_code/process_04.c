#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    char name[] = "Jeffrey";
    pid_t pid;

    switch (pid=fork())
    {
        default:
            // HINT: The parent process should fall into this scope.
            printf("My name is %s and I am a parent.\n", name);
            sleep(3);
            break;

        case 0:
            sleep(1);
            // HINT: The child process should fall into this scope
            char child_name[] = "Michael";
            pid_t pid2 = fork();
            switch(pid2) {
                default:
                    printf("My name is %s and my father is %s. My pid is %d\n", child_name, name, getpid());
                    break;
                
                case 0:
                sleep(1);
                    char grandchild_name[] = "Steven";
                    printf("My name is %s! My father's name is %s and my grandpa is called %s. My pid is %d\n", grandchild_name, child_name, name, getpid());
                    break;

                case -1:
                    printf("something went awfully wrong");
                    return -1;
            }
            break;

        case -1:
            printf("and it failed once again");
            return -1;
            break;
    }
}


/*
Expected output:
My name is Jeffrey and I am a parent.
My name is Michael and my father is Jeffrey. My pid is yyyy
My name is Steven! My father's name is Michael and my grandpa is called Jeffrey. My pid is zzzz
*/
