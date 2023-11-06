#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#define n 10

int arr[n];
int i = 0;
sem_t mutex, empty, full;


void* producer(void* arg) {
    for(int j = 0;j < 1000;j++) {
        int a = rand() % 10;
        sem_wait(&empty); /* It firstly checks if the array is full, 
                             If yes, then it will wait for it to have alteast 1 empty space.      
                          */
        sem_wait(&mutex); // Only one produces will update the array.

        printf("Producer entered\n");
        /* Critical section starts */
        arr[i] = a;
        i++;
        /* Critical section ends */
        printf("Producer exited after generating the number %d\n", a);

        sem_post(&full);
        sem_post(&mutex);
    }
}

void* consumer(void* arg) {
    for(int j = 0;j < 1000;j++) {
        sem_wait(&full); // Consumer checks if the array is empty, if so, it will wait for the producer to fill it.
        sem_wait(&mutex);

        /* Critical section starts*/
        i--;
        printf("Consumed the number %d\n", arr[i]);
        /* Critical section ends */

        sem_post(&empty);
        sem_post(&mutex);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, n);
    sem_init(&full, 0, 0);


    pthread_t p1, p2;
    pthread_create(&p1, NULL, consumer, NULL);
    pthread_create(&p2, NULL, producer, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}