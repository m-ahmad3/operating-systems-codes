#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //file controls
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int sort_pipe[2];
    pid_t pid;
    int status;

    // Create pipe
    pipe(sort_pipe);

    // Fork a child process
    pid = fork();

    if (pid == 0) { // Child process
        
        close(sort_pipe[0]); // Close the read end of sort pipe
        
        
        // Open input file
        int input_fd = open(argv[2], O_RDONLY);
        

        // Redirect stdin to read from the input file
        dup2(input_fd, 0);
        
        close(input_fd);

        // Redirect stdout to write to the sort pipe
        dup2(sort_pipe[1], 1);
        
        close(sort_pipe[1]);

        // Execute sort command
        execlp(argv[1], argv[1], NULL);
    
    } 
    else 
    { // Parent process
            
        wait(NULL);
            
        close(sort_pipe[1]); // Close the write end of sort pipe

        // Redirect stdin to read from the sort pipe
        dup2(sort_pipe[0], 0);

        // Redirect stdout to write to the output file
        int output_fd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        dup2(output_fd, 1);

        // Execute grep command
        execlp(argv[3], argv[3], argv[4], NULL);

    }

    return 0;
}

