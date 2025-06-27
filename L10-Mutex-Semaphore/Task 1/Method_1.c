#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

#define NUM_PHILOSOPHERS 5

sem_t chopstick[NUM_PHILOSOPHERS];
sem_t table_sem;

void* philosopher(void* num) {
int a = *(int*)num;

sem_wait(&table_sem);

printf("Philosopher %d is thinking\n", a);
sem_wait(&chopstick[a]);
sem_wait(&chopstick[(a+1)%NUM_PHILOSOPHERS]);

printf("Philosopher %d is eating\n", a);

sem_post(&chopstick[a]);
sem_post(&chopstick[(a+1)%NUM_PHILOSOPHERS]);

printf("Philosopher %d is thinking again\n", a);
sem_post(&table_sem);

return NULL;
}

int main() {

pthread_t threads[NUM_PHILOSOPHERS];
int philosopher_numbers[NUM_PHILOSOPHERS];

for(int a = 0; a < NUM_PHILOSOPHERS; a++) {
sem_init(&chopstick[a], 0, 1);
}

sem_init(&table_sem, 0, 4);

for(int a = 0; a < NUM_PHILOSOPHERS; a++) {
philosopher_numbers[a] = a;
pthread_create(&threads[a], NULL, philosopher, &philosopher_numbers[a]);
}

for(int a = 0; a < NUM_PHILOSOPHERS; a++) {
pthread_join(threads[a], NULL);
}

return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];
sem_t table; // Semaphore to allow at most 4 philosophers at the table.

void *philos(void *);
void eat(int);

int main() {
    int i, n[5];
    pthread_t T[5];

    sem_init(&table, 0, 4); // Initialize table semaphore to 4.
    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < 5; i++) {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]);
    }

    for (i = 0; i < 5; i++)
        pthread_join(T[i], NULL);

    return 0;
}

void *philos(void *n) {
    int ph = *(int *)n;

    sem_wait(&table); // Wait for permission to sit at the table.
    printf("Philosopher %d sits at the table.\n", ph);

    printf("Philosopher %d wants to eat\n", ph);
    printf("Philosopher %d tries to pick left chopstick\n", ph);
    sem_wait(&chopstick[ph]);
    printf("Philosopher %d picks the left chopstick\n", ph);
    printf("Philosopher %d tries to pick the right chopstick\n", ph);
    sem_wait(&chopstick[(ph + 1) % 5]);
    printf("Philosopher %d picks the right chopstick\n", ph);

    eat(ph);
    sleep(2);

    printf("Philosopher %d has finished eating\n", ph);
    sem_post(&chopstick[(ph + 1) % 5]);
    printf("Philosopher %d leaves the right chopstick\n", ph);
    sem_post(&chopstick[ph]);
    printf("Philosopher %d leaves the left chopstick\n", ph);

    sem_post(&table); // Leave the table, allowing another philosopher to sit.
    printf("Philosopher %d leaves the table.\n", ph);
}

void eat(int ph) {
    printf("Philosopher %d begins to eat\n", ph);
}

*/

