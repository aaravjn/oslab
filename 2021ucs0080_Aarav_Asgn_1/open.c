#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {

    int fd = open("file.txt", O_RDONLY);
    char buff[10];

    read(fd, buff, 10);
    write(1, buff, 10);

    return 0;
}