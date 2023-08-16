#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    int fd = open("file.txt", O_WRONLY);
    lseek(fd, 5, SEEK_CUR);

    char text[5] = {'1', '2', '3', '4', '5'};
    write(fd, text, 5);

    char buff[10];
    int n = open("file.txt", O_RDONLY);
    read(n, buff, 10);
    write(1, buff, 10);
    return 0;
}