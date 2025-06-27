#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main (int argc, char* argv[])
{

printf("Name: Muhammad Ahmad\n");
printf("Reg# L1F22BSCS0634\n");

// To check if argument is passed or not
if(argc<2){
printf("No Command Line Argument Given!...\n");
return 0;
}

int n=atoi(argv[1]);

// Print the given number
printf("Parent: Value from command-line arguments is %d\n\n", n);

// Declaring FD's for pipes
int ptoc1[2],ptoc2[2],c1top[2],c2top[2];

// Creating pipes
pipe(ptoc1);
pipe(ptoc2);
pipe(c1top);
pipe(c2top);


// Child 1
if(fork()==0){
close(ptoc1[1]);
close(c1top[0]);

int r;
read(ptoc1[0],&r,sizeof(int));
printf("Child1: Read Value is %d\n",r);
r*=r; // Taking square

// Write the output in pipe c1top
write(c1top[1],&r,sizeof(int));

exit(0); // Terminates the child process
}

// Child 2
if(fork()==0){
close(ptoc2[1]);
close(c2top[0]);

int r;
read(ptoc2[0],&r,sizeof(int));
printf("Child2: Read Value is %d\n",r);
r=r*r*r; // Taking Cube

write(c2top[1],&r,sizeof(int));

exit(0);
}

close(ptoc1[0]);
close(ptoc2[0]);

write(ptoc1[1],&n,sizeof(int));
write(ptoc2[1],&n,sizeof(int));

wait(NULL);  // Wait for all Child process to terminate

close(c1top[1]);
close(c2top[1]);

int temp;
printf("\nParent read:\n");
read(c1top[0],&temp,sizeof(int));
printf("Square = %d\n",temp);
read(c2top[0],&temp,sizeof(int));
printf("Cube + Number = %d\n",temp+n);

return 0;
}
