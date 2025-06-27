#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Semaphores and mutex
pthread_mutex_t lock;
sem_t waitingH, waitingO;

// Counters
int wH = 0; // Waiting Hydrogen atoms
int wO = 0; // Waiting Oxygen atoms
int aH = 0; // Assigned Hydrogen atoms
int aO = 0; // Assigned Oxygen atoms
int waterMolecules = 0;

void* Hydrogen(void* arg) {
    pthread_mutex_lock(&lock);

    wH++; // Increment waiting Hydrogen count
    printf("Hydrogen atom added. Waiting Hydrogen atoms: %d\n", wH);

    // While this Hydrogen is not assigned
    while (aH == 0) {
        // Try to form a water molecule
        if (wH >= 2 && wO >= 1) {
            wH -= 2; aH += 2;
            wO -= 1; aO += 1;
            printf("Water molecule formed! Total water molecules: %d\n", ++waterMolecules);

            // Signal other atoms to proceed
            sem_post(&waitingH);
            sem_post(&waitingH);
            sem_post(&waitingO);
        } else {
            // Wait until another thread signals
            pthread_mutex_unlock(&lock);
            sem_wait(&waitingH);
            pthread_mutex_lock(&lock);
        }
    }

    aH--; // This Hydrogen atom is now assigned and can leave
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

void* Oxygen(void* arg) {
    pthread_mutex_lock(&lock);

    wO++; // Increment waiting Oxygen count
    printf("Oxygen atom added. Waiting Oxygen atoms: %d\n", wO);

    // While this Oxygen is not assigned
    while (aO == 0) {
        // Try to form a water molecule
        if (wH >= 2 && wO >= 1) {
            wH -= 2; aH += 2;
            wO -= 1; aO += 1;
            printf("Water molecule formed! Total water molecules: %d\n", ++waterMolecules);

            // Signal other atoms to proceed
            sem_post(&waitingH);
            sem_post(&waitingH);
        } else {
            // Wait until another thread signals
            pthread_mutex_unlock(&lock);
            sem_wait(&waitingO);
            pthread_mutex_lock(&lock);
        }
    }

    aO--; // This Oxygen atom is now assigned and can leave
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    
    int n = atoi(argv[1]);
    
    // Initialize semaphores and mutex
    sem_init(&waitingH, 0, 0);
    sem_init(&waitingO, 0, 0);
    pthread_mutex_init(&lock, NULL);

    pthread_t threads[n];

    // Create Hydrogen & Oxygen threads
    for (int i = 0; i < n; i++){
        pthread_create(&threads[i], NULL, Hydrogen, NULL);
        pthread_create(&threads[i], NULL, Oxygen, NULL);
        sleep(1);
    }

    // Join all threads
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
