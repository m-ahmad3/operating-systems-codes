
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
// ps | sed 1d | wc -l

int f1[2];
int f2[2];

pipe(f1);

if(fork()==0){
dup2(f1[1],1);
close(f1[0]);
close(f1[1]);
execlp("ps","ps",NULL);
perror("execlp failed for ps");
}

pipe(f2);

if(fork()==0){
dup2(f1[0],0);
dup2(f2[1],1);
close(f1[1]);
close(f1[0]);
close(f2[0]);
close(f2[1]);
execlp("sed","sed","1d",NULL);
perror("execlp failed for sed");
}

close(f1[0]);
close(f1[1]);

if (fork() == 0) {
dup2(f2[0], 0); 
close(f2[0]);
close(f2[1]);
execlp("wc", "wc", "-l", NULL);
perror("Error executing wc");
}

close(f2[0]);
close(f2[1]);

wait(NULL);

return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/wait.h>

int main() {
    int fds1[2], fds2[2];

    // Create the first pipe
    if (pipe(fds1) == -1) {
        perror("Error creating pipe 1");
        return 1;
    }

    // Fork the process for ps command
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("Error forking process 1");
        return 1;
    }

    if (pid1 == 0) {
        // Child process 1: Executes ps
        dup2(fds1[1], 1); // Redirect stdout to pipe 1 write end
        close(fds1[0]);
        close(fds1[1]);

        execlp("ps", "ps", NULL);

        // If execlp fails
        perror("Error executing ps");
        exit(1);
    }

    // Parent process continues
    // Create the second pipe
    if (pipe(fds2) == -1) {
        perror("Error creating pipe 2");
        return 1;
    }

    // Fork the process for sed command
    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("Error forking process 2");
        return 1;
    }

    if (pid2 == 0) {
        // Child process 2: Executes sed
        dup2(fds1[0], 0); // Redirect stdin to pipe 1 read end
        dup2(fds2[1], 1); // Redirect stdout to pipe 2 write end
        close(fds1[0]);
        close(fds1[1]);
        close(fds2[0]);
        close(fds2[1]);

        execlp("sed", "sed", "1d", NULL);

        // If execlp fails
        perror("Error executing sed");
        exit(1);
    }

    // Parent process closes unused pipe ends
    close(fds1[0]);
    close(fds1[1]);

    // Fork the process for wc command
    pid_t pid3 = fork();
    if (pid3 == -1) {
        perror("Error forking process 3");
        return 1;
    }

    if (pid3 == 0) {
        // Child process 3: Executes wc
        dup2(fds2[0], 0); // Redirect stdin to pipe 2 read end
        close(fds2[0]);
        close(fds2[1]);

        execlp("wc", "wc", "-l", NULL);

        // If execlp fails
        perror("Error executing wc");
        exit(1);
    }

    // Parent process closes unused pipe ends
    close(fds2[0]);
    close(fds2[1]);

    // Wait for all child processes to complete
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
*/
