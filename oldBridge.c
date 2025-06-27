#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

pthread_mutex_t mutex;
sem_t semaphore;
int cars = 0;
int cdir = -1;  // -1 indicates no direction set yet

void ArriveBridge(int direction) {
    pthread_mutex_lock(&mutex);

    while ((cars == 3) || (cars > 0 && cdir != direction)) {
        pthread_mutex_unlock(&mutex);
        sem_wait(&semaphore);
        pthread_mutex_lock(&mutex);
    }

    cars++;
    cdir = direction;

    pthread_mutex_unlock(&mutex);
}

void ExitBridge() {
    pthread_mutex_lock(&mutex);

    cars--;

    sem_post(&semaphore);

    pthread_mutex_unlock(&mutex);
}

void* Car(void* arg) {
    int direction = *((int*)arg);
    
    ArriveBridge(direction);
    printf("Car going in direction %d is on the bridge.\n", direction);
    // Simulate some time on the bridge
    sleep(2);
    ExitBridge();
    printf("Car going in direction %d has exited the bridge.\n", direction);

    return NULL;
}

int main() {
    pthread_t threads[20];
    int dir;  // Example directions for cars

    pthread_mutex_init(&mutex, NULL);
    sem_init(&semaphore, 0, 3);

    for (int i = 0; i < 20; i++) {
        dir = rand()%2;
        pthread_create(&threads[i], NULL, Car, &dir);
    }

    for (int i = 0; i < 20; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
