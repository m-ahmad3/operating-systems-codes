#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t lock;
sem_t hydrogen_sem;
sem_t oxygen_sem;

int wH = 0, wO = 0, aH = 0, aO = 0;
int total_water_molecules = 0;

void* hydrogen(void* arg) {
pthread_mutex_lock(&lock);
wH++;
printf("Hydrogen atom added. Waiting Hydrogen atoms: %d\n", wH);
if (wH>=2 && wO>=1) {
wH -= 2; aH += 2;
wO -= 1; aO += 1;
sem_post(&hydrogen_sem);
sem_post(&hydrogen_sem);
sem_post(&oxygen_sem);
} 
else {
pthread_mutex_unlock(&lock);
sem_wait(&hydrogen_sem);
pthread_mutex_lock(&lock);
}
aH--;
if (aH==0 && aO==0) {
total_water_molecules++;
printf("Water molecule formed! Total water molecules: %d\n",total_water_molecules);
}
pthread_mutex_unlock(&lock);

return NULL;
}

void* oxygen(void* arg) {

pthread_mutex_lock(&lock);
wO++;
printf("Oxygen atom added. Waiting Oxygen atoms: %d\n", wO);
if (wH>=2 && wO>=1) {
wH -= 2; aH += 2;
wO -= 1; aO += 1;
sem_post(&hydrogen_sem);
sem_post(&hydrogen_sem);
sem_post(&oxygen_sem);
} 
else {
pthread_mutex_unlock(&lock);
sem_wait(&oxygen_sem);
pthread_mutex_lock(&lock);
}
aO--;
if (aH==0 && aO==0) {
total_water_molecules++;
printf("Water molecule formed! Total water molecules: %d\n", total_water_molecules);
}
pthread_mutex_unlock(&lock);

return NULL;
}

int main() {

pthread_mutex_init(&lock, NULL);
sem_init(&hydrogen_sem, 0, 0);
sem_init(&oxygen_sem, 0, 0);

pthread_t toxy[3];
pthread_t thyd[6];
int ind = 0;
for (int a = 0; a < 3; a++) {
pthread_create(&thyd[ind], NULL, hydrogen, NULL);
pthread_create(&toxy[a], NULL, oxygen, NULL);
pthread_create(&thyd[ind + 1], NULL, hydrogen, NULL);
ind += 2;
}
ind = 0;
for (int a = 0; a < 3; a++) {
pthread_join(thyd[ind], NULL);
pthread_join(thyd[ind + 1], NULL);
pthread_join(toxy[a], NULL);
ind += 2;
}

return 0;
}




