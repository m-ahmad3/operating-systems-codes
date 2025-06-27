#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TERMS 1000000

double result = 0.0;
int n;
int pthread_num_threads;

void *calculatePi(void *arg) {
    int threadID = *((int *)arg);
    double res = 0.0;

    for (int i = threadID; i <= n; i += pthread_num_threads) {
        double term;
        if (i % 2 == 0) {
            term = 1.0 / (2 * i + 1);
        } else {
            term = -1.0 / (2 * i + 1);
        }
        res += term;
    }

    result += res;

    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number of threads> <n>\n", argv[0]);
        return 1;
    }

    pthread_num_threads = atoi(argv[1]);
    n = atoi(argv[2]);

    if (n <= 100000 || n > MAX_TERMS || n % pthread_num_threads != 0) {
        printf("Invalid value for n. It should be greater than 100,000 and evenly divisible by the number of threads.\n");
        return 1;
    }

    pthread_t threads[pthread_num_threads];
    int threadIDs[pthread_num_threads];

    for (int i = 0; i < pthread_num_threads; ++i) {
        threadIDs[i] = i;
        pthread_create(&threads[i], NULL, calculatePi, &threadIDs[i]);
        pthread_join(threads[i], NULL);
    }

    double pi = 4 * result;

    printf("Estimated value of Pi using %d terms: %.15f\n", n, pi);

    return 0;
}
