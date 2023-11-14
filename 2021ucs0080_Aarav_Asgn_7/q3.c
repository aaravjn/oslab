#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define n 10


int queue[n];
int front = 0;
int back = 0;
int size = 0;
sem_t mutex;

void insertElement(int x) {
    queue[back] = x;
    if(back == n-1) {
        back = 0;
    }
    else {
        back++;
    }
}
int removeFront() {
    int x = queue[front];
    if(front == n-1) {
        front = 0;
    }
    else {
        front++;
    }
    return x;
}


void sleepThread() {
    int rand_sleep_time = (rand() % 4) + 3; // Rand int from 3 to 6
    usleep(rand_sleep_time * 100);
}

void* producer(void* arg) {
    for(int j = 0;j < 100;j++) {
        int a = rand() % 10;
        sem_wait(&mutex); // Only one produces will update the array.
        if(size < n) { // Producer will check if there is any empty space in the array.
            printf("Producer entered\n");

            /* Critical section starts */
            insertElement(a);
            size++;
            /* Critical section ends */
            
            printf("Producer exited after generating the number %d\n", a);
            sem_post(&mutex);
        }
        else { // Otherwise it will release the lock and wait for some time.
            printf("Producer waits for the array to get empty. \n");
            sem_post(&mutex);
            sleepThread();
        }
    }
}

void* consumer(void* arg) {
    for(int j = 0;j < 100;j++) {
        sem_wait(&mutex);
        
        if(size >= 2) {
            
            /* Critical section starts*/
            int a = removeFront();
            printf("Consumer consumes the front element: %d \n", a);
            a = removeFront();
            printf("Consumer consumes the front element: %d \n", a);

            size -= 2;
            /* Critical section ends */
            sem_post(&mutex);
        }
        else {
            printf("Consumer waits for produces to produce. Size of array: %d\n", size);
            sem_post(&mutex);
            sleepThread();
        }
    }
}

int main() {
    sem_init(&mutex, 0, 1);

    pthread_t p1, p2;
    pthread_create(&p1, NULL, consumer, NULL);
    pthread_create(&p2, NULL, producer, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}