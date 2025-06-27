#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int counter = 0;
pthread_mutex_t counter_mutex;


void* increment_counter(void* arg) {

        
        if (pthread_mutex_trylock(&counter_mutex) == 0) {
            
            printf("Thread %ld incrementing counter. Current value: %d\n", (long)arg, counter);
            counter++;
            pthread_mutex_unlock(&counter_mutex);
        } else {
            
            printf("Thread %ld could not acquire lock\n", (long)arg);
        }


    pthread_exit(NULL);
}

int main() {
    
    pthread_mutex_init(&counter_mutex, NULL);
    
    pthread_t threads[5];

    
    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, increment_counter, (void*)i);
    }

    
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the counter
    printf("Final counter value: %d\n", counter);

    return 0;
}
