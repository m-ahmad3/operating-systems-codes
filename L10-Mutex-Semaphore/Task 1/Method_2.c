#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

#define NUM_PHILOSOPHERS 5

sem_t chopstick[NUM_PHILOSOPHERS];
sem_t table_sem;
pthread_mutex_t mutex;

void* philosopher(void* num) {
int a = *(int*)num;
sem_wait(&table_sem);
printf("Philosopher %d is thinking\n", a);

pthread_mutex_lock(&mutex);

sem_wait(&chopstick[a]);
sem_wait(&chopstick[(a+1)%NUM_PHILOSOPHERS]);

printf("Philosopher %d is eating\n", a);

sem_post(&chopstick[a]);

sem_post(&chopstick[(a+1)%NUM_PHILOSOPHERS]);
pthread_mutex_unlock(&mutex);
printf("Philosopher %d is thinking again\n", a);
sem_post(&table_sem);

return NULL;
}

int main() {
pthread_t threads[NUM_PHILOSOPHERS];

int philosopher_numbers[NUM_PHILOSOPHERS];

for (int a = 0; a < NUM_PHILOSOPHERS; a++) {
sem_init(&chopstick[a], 0, 1);
}
sem_init(&table_sem, 0, 4);
pthread_mutex_init(&mutex, NULL);

for (int a = 0; a < NUM_PHILOSOPHERS; a++) {
philosopher_numbers[a] = a;
pthread_create(&threads[a], NULL, philosopher, &philosopher_numbers[a]);
}

for (int a = 0; a < NUM_PHILOSOPHERS; a++) {
pthread_join(threads[a], NULL);
}

return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];    // Semaphores for each chopstick
pthread_mutex_t mutex; // Mutex to guard the critical section

void *philos(void *);
void eat(int);

int main() {
    int i, n[5];
    pthread_t T[5];

    pthread_mutex_init(&mutex, NULL); // Initialize the mutex
    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < 5; i++) {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]);
    }

    for (i = 0; i < 5; i++)
        pthread_join(T[i], NULL);

    pthread_mutex_destroy(&mutex); // Destroy the mutex
    return 0;
}

void *philos(void *n) {
    int ph = *(int *)n;

    printf("Philosopher %d wants to eat\n", ph);

    // Enter the critical section to pick up both chopsticks
    pthread_mutex_lock(&mutex);

    printf("Philosopher %d tries to pick left chopstick\n", ph);
    sem_wait(&chopstick[ph]);
    printf("Philosopher %d picks the left chopstick\n", ph);

    printf("Philosopher %d tries to pick the right chopstick\n", ph);
    sem_wait(&chopstick[(ph + 1) % 5]);
    printf("Philosopher %d picks the right chopstick\n", ph);

    pthread_mutex_unlock(&mutex);

    // Eat after successfully picking both chopsticks
    eat(ph);
    sleep(2);

    printf("Philosopher %d has finished eating\n", ph);

    // Release both chopsticks
    sem_post(&chopstick[(ph + 1) % 5]);
    printf("Philosopher %d leaves the right chopstick\n", ph);
    sem_post(&chopstick[ph]);
    printf("Philosopher %d leaves the left chopstick\n", ph);
}

void eat(int ph) {
    printf("Philosopher %d begins to eat\n", ph);
}

*/
