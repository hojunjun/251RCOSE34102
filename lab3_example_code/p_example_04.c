#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    printf("executing ls -l\n");
    execl("/bin/ls", "ls", "-l", NULL);
    printf("this will get overwritten\n");
    return 0;
}