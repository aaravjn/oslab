#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int p1 = fork();

    if(p1 == 0) {
        int p2 = fork();

        if(p2 == 0) {
            printf("I am child 1 and I have completed \n");
        }
        else {
            printf("I am child 2 and I have completed \n");
        }
    }
    else {
        int cpid = wait(NULL);
        printf("I am parent process and My Children finished the task \n");
    }
}