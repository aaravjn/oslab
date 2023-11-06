#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t mutex, wrt;
int readercnt = 0;
int resource = 0;

void* reader(void* arg) {
    for(int j = 0;j < 100000;j++) {

        /*
        This is done to update the reader count.
        If there is a writer executing the critical section, then the reader has to wait for it.
        Else, the reader will disable the wrt flag, blocking all the writers.
        */


        sem_wait(&mutex);
        readercnt++;
        if(readercnt == 1)
            sem_wait(&wrt); // Waits for any writer present to finish if it is the first reader.

        sem_post(&mutex);

        /* Read operation */
        printf("Reader reads the value of the variable as: %d\n", resource);

        sem_wait(&mutex);
        readercnt--;
        if(readercnt == 0)
            sem_post(&wrt); // If it is the last reader to leave, it will enable the wrt flag for writers.

        sem_post(&mutex);
    }
}

void* writer(void* arg) {
    for(int j = 0;j < 100000;j++) {

        /* There should be only one writer to execute the critical section */

        sem_wait(&wrt);

        /* Critical section starts*/
        resource++;
        /* Critical section ends */

        sem_post(&wrt);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);


    pthread_t p1, p2;
    pthread_create(&p2, NULL, reader, NULL);
    pthread_create(&p1, NULL, writer, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}