#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int p1;
    p1 = fork();

    if(p1 == 0) {
        printf("Child 1 -> process id : %d parent pid %d \n", getpid(), getppid());
    }
    else {
        int p2 = fork();
        if(p2 == 0) {
            printf("Child 2 -> process id : %d parent pid %d \n", getpid(), getppid());
        }
        else {
            int p3 = fork();
            if(p3 == 0) {
                printf("Child 3 -> process id : %d parent pid %d \n", getpid(), getppid());
            }
            else {
                sleep(3);
                printf("Parent -> process id : %d \n", getpid());
            }
        }
    }
}