#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* add(void* arr) {
    int sum = 0;
    for(int i = 0;i < 10;i++) {
        int* ptr = (int*)arr;
        sum += *(ptr + i);
    }
    int* res = malloc(sizeof(int*));
    *res = sum;

    return (void*)res;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    pthread_t thread1;
    void* output_sum;
    pthread_create(&thread1, NULL, add, arr);
    pthread_join(thread1, &output_sum);

    printf("%d\n", *(int*)output_sum);
}