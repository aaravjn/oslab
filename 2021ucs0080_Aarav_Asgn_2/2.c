#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int p1 = fork();

    if(p1 == 0) {
        int p2 = fork();
        
        if(p2 == 0) {
            sleep(1);
            printf("I am P2 with process ID %d with parent pid %d \n", getpid(), getppid());
        }
        else {
            sleep(2);
            printf("I am P1 with process ID : %d with parent pid %d \n", getpid(), getppid());
        }
    }
    else {
        sleep(3);
        printf("I am P with process ID : %d \n", getpid());
    }
}