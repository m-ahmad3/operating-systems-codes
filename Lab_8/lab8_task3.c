#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>  // For using bool

#define MAX_LINE_LENGTH 1024

// Global flag to indicate whether the string is found
bool found = false;

// File descriptor (make them globally)
int fd;
char *search_string;

// Thread function
void *search_in_file(void *arg) {
    int thread_id = *(int *)arg;
    free(arg);

    char buffer[MAX_LINE_LENGTH];
    int bytes_read;
    int line_number = 1;
    int column_number;

    // Move to the beginning of the file for each thread
    lseek(fd, 0, SEEK_SET);

    // Each thread processes lines from the file independently
    while (!found && (bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        char *line = buffer;

        // Process the line and search for the string
        while (line) {
            char *pos = strstr(line, search_string);
            if (pos) {
                found = true;
                column_number = (int)(pos - line) + 1;  // Column where string is found
                write(STDOUT_FILENO, "Thread ", 7);
                char msg[256];
                int len = snprintf(msg, sizeof(msg), "Thread %d: Found '%s' at line %d, column %d\n", thread_id, search_string, line_number, column_number);
                write(STDOUT_FILENO, msg, len);
                return NULL;
            }
            line = strchr(line, '\n');
            if (line) {
                line++; // Move to the next line
                line_number++;
            }
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        write(STDERR_FILENO, "Usage: <filename> <N> <string>\n", 30);
        exit(-1);
    }

    char *filename = argv[1];
    int num_threads = atoi(argv[2]);
    search_string = argv[3];

    if (num_threads <= 0) {
        write(STDERR_FILENO, "Number of threads must be greater than 0.\n", 41);
        exit(-1);
    }

    // Open the file using low-level open()
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(-1);
    }

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i + 1;

        if (pthread_create(&threads[i], NULL, search_in_file, thread_id) != 0) {
            perror("Error creating thread");
            close(fd);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    if (!found) {
        write(STDOUT_FILENO, "String not found in the file.\n", 30);
    }

    close(fd);
    return 0;
}
