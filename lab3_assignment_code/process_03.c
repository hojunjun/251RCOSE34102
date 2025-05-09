#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    printf("where am I?\n");


    execl("/bin/pwd", "pwd", NULL);

    return 0;
}




/*
Expected output:

Where am I?
**some directory where process_03.c is in**
(example: /home/dnclab/shared/process)
*/
