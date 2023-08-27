#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int p = fork();

    if(p == 0) {
        sleep(1);
        printf("(C) Process ID of Child (P1) %d \n", getpid());
        printf("(D) Parent ID of Child P1: %d \n", getppid());
    }
    else {
        printf("(A) Process ID of Child (P1): %d \n", getpid());
        int cpid = wait(NULL);
        printf("(B) ID of P's Child (P1): %d \n", cpid);
    }
}