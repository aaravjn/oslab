#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int p1 = fork();

    if(p1 == 0) {
        printf("I am child 1 and I have completed %d\n", getpid());
    }
    else {
        int p2 = fork();
        
        if(p2 == 0) {
            printf("I am Child 2 and I have completed %d\n", getpid());
        }
        else {
            int cpid1 = wait(NULL);
            int cpid2 = wait(NULL);
            printf("I am parent process and My Children finished the task %d %d\n", cpid1, cpid2);
        }
    }
}