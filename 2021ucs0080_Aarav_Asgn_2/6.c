#include <stdio.h>
#include <pthread.h>

int res;

void* add() {
    int sum = 0;
    for(int i = 0;i < 10;i++) {
        sum += i;
    }
    res = sum;
    return NULL;
}

int main() {
    pthread_t thread1;

    pthread_create(&thread1, NULL, add, NULL);
    pthread_join(thread1, NULL);

    printf("%d\n", res);
}