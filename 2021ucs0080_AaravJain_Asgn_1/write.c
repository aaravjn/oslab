#include <unistd.h>
int main() {

    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    write(1, &a, 4);
    
    /*
    Doesn't work with int data-type. Only with characters.
    */
    return 0;
}