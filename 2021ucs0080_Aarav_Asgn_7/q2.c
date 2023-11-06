#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

static volatile int counter = 0;
sem_t s;

void* myThread(void* arg) {
    for(int i = 0;i < 1000000; i++) {
        sem_wait(&s);
        
        /* Critical section starts */
        counter++;
        /* Critical section ends */

        sem_post(&s);
    }
}


int main() {
    sem_init(&s, 0, 1);
    pthread_t p1, p2;
    pthread_create(&p1, NULL, myThread, NULL);
    pthread_create(&p2, NULL, myThread, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);


    printf("%d\n", counter);
    return 0;
}


/*
The above solves the critical section problem by allowing only one thread to access a shared resource
at a time. This is implemented by using a semaphore variable s. If s == 1, then the resource is available
thus, any thread can access it now. If any thread enters, s becomes 0, and the resource becomes
inaccessible by any thread. After the thread completes execution, the variable s becomes 1, and it 
can now be accessed by the other thread. The functions sem_wait and sem_post are atomic operations.
This means, they connot be interrupted in between their execution. 
*/