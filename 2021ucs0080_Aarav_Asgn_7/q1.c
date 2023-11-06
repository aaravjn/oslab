#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static volatile int counter = 0;

void* myThread(void* arg) {
    int i;
    
    for(int i = 0;i < 10; i++) {
        sleep(1);
        counter++;
    }
}


int main() {
    pthread_t p1, p2;
    pthread_create(&p1, NULL, myThread, NULL);
    pthread_create(&p2, NULL, myThread, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);


    printf("%d\n", counter);
    return 0;
}


/*
    The problem is that both the threads are trying to update the counter value concurrently, thus
    leading to a critical section problem where both the thread try to change a shared resource.
    Thus, when one thread reads the counter and increments it, but before writing back the changes
    the thread gets interrupted. Therefore, the next thread still uses the old value of counter to update
    its value. This is an example where we lost a count value which explains why the output value would
    always be <= 200,000,000.
*/