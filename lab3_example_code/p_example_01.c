#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

static int idata = 111;

int main(int argc, char *argv[]) {
    int istack = 222;
    pid_t childPid;

    switch(childPid = fork()) {
        case -1:
            return -1;
        case 0:
            idata *=3;
            istack *=3;
            break;
        default:
            sleep(3);
            break;
    }

    printf("PID = %d %s idata= %d istack=%d\n", getpid(), childPid == 0 ? "(child)" : "(parent)", idata, istack);
    return 0;
}