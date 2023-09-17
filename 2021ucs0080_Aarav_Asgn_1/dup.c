#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main() {
    int old_fd = open("file.txt", O_RDONLY);

    int new_fd = dup(old_fd);
    
    printf("%d\n", old_fd);
    printf("%d\n", new_fd);
}