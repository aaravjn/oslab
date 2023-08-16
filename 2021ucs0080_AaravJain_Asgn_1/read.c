#include <unistd.h>

int main() {
    char c;
    char* pointer_to_c = &c;
    read(0, pointer_to_c, 1);

    write(1, pointer_to_c, 1);

    return 0;
}