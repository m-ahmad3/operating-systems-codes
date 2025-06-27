#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];          // Semaphore for each chopstick
sem_t max_chopsticks;        // Semaphore to ensure at most 4 chopsticks are in use at once

void *philos(void *);
void eat(int);

int main() {
    int i, n[5];
    pthread_t T[5];

    sem_init(&max_chopsticks, 0, 4); // Allow at most 4 chopsticks to be used simultaneously
    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1); // Initialize semaphores for chopsticks

    for (i = 0; i < 5; i++) {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]); // Create philosopher threads
    }

    for (i = 0; i < 5; i++)
        pthread_join(T[i], NULL); // Wait for all threads to complete

    return 0;
}

void *philos(void *n) {
    int ph = *(int *)n;

    printf("Philosopher %d wants to eat\n", ph);

    // Wait until at least 2 chopsticks are available
    sem_wait(&max_chopsticks);
    sem_wait(&max_chopsticks);

    printf("Philosopher %d tries to pick left chopstick\n", ph);
    sem_wait(&chopstick[ph]); // Pick left chopstick
    printf("Philosopher %d picks the left chopstick\n", ph);

    printf("Philosopher %d tries to pick right chopstick\n", ph);
    sem_wait(&chopstick[(ph + 1) % 5]); // Pick right chopstick
    printf("Philosopher %d picks the right chopstick\n", ph);

    eat(ph);
    sleep(2);

    printf("Philosopher %d has finished eating\n", ph);

    // Release both chopsticks
    sem_post(&chopstick[(ph + 1) % 5]); // Release right chopstick
    printf("Philosopher %d leaves the right chopstick\n", ph);

    sem_post(&chopstick[ph]); // Release left chopstick
    printf("Philosopher %d leaves the left chopstick\n", ph);

    // Signal the availability of 2 chopsticks
    sem_post(&max_chopsticks);
    sem_post(&max_chopsticks);
}

void eat(int ph) {
    printf("Philosopher %d begins to eat\n", ph);
}

