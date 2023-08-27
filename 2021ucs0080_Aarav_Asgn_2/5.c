#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void* fileCreation() {
    FILE *fptr;
    fptr = fopen("mythread.txt", "w");
    fclose(fptr);

    return NULL;
}

void* updateFile() {
    sleep(2);

    int fd = open("mythread.txt", O_WRONLY);
    char s[46] = "Hello, I am writing in the file created by you";

    write(fd, s, 46);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, fileCreation, NULL);
    pthread_create(&thread2, NULL, updateFile, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}