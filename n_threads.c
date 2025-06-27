#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 10 // Size of the array
#define M 3  // Number of threads

int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int partial_sums[M]; // Array to store partial sums

void *add(void *ptr) {
    int thread_id = *((int *)ptr);
    int sum = 0;

    // Calculate the range for this thread
    int chunk_size = N / M;
    int start = thread_id * chunk_size;
    int end = (thread_id + 1) * chunk_size;

    // Calculate the partial sum for the assigned range
    for (int i = start; i < end; i++) {
        sum += arr[i];
    }

    partial_sums[thread_id] = sum;

    return NULL;
}

int main() {
    pthread_t threads[M];
    int thread_ids[M];

    // Create threads
    for (int i = 0; i < M; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, add, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < M; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the final sum by adding partial sums
    int final_sum = 0;
    for (int i = 0; i < M; i++) {
        final_sum += partial_sums[i];
    }

    printf("Final sum = %d\n", final_sum);

    return 0;
}
