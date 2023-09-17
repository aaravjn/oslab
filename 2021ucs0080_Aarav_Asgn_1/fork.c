#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t p;
    p = fork();

    if(p == 0) {
        printf("I am the if condition\n");
    }
    else {
        printf("I am the else condition\n");
    }

    printf("This is the value of p I got: %d \n", p);
}