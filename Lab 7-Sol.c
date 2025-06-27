#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/sysinfo.h>
#include<sched.h>

/*-----
int main(int argc,char* argv[]){

cpu_set_t set;

CPU_ZERO(&set);

int procs=get_nprocs();

printf("Available CPUs are from 0 to %d\n",procs);

int new;
printf("Select CPU from Available Range: ");
scanf("%d",&new);

if(new<0&&new>procs){
printf("This CPU is Not Available!...");
return 0;
}

CPU_SET(new,&set);

sched_setaffinity(0,sizeof(cpu_set_t),&set);

printf("\nNew Affinity is %d\n\n",sched_getcpu());

execlp(argv[1],argv[1],NULL);

return 0;
}
*/


// Task 2
/*----------------------------------------------*/
int main(int argc,char* argv[]){

int ptoc1[2];
int ptoc2[2];
int ptoc3[2];

pipe(ptoc1);
pipe(ptoc2);
pipe(ptoc3);

int n=argc-1;

// First Child
if(fork()==0){
close(ptoc1[1]);

cpu_set_t set;

CPU_ZERO(&set);

int procs=get_nprocs();
CPU_SET(1,&set);

sched_setaffinity(0,sizeof(cpu_set_t),&set);

int avg=0;
for(int a=0;a<n;a++){
int temp;
read(ptoc1[0],&temp,sizeof(int));
avg+=temp;
}

avg/=n;

printf("\nThe Average Value is %d\n",avg);

return 0;
}
else{

// Second Child
if(fork()==0){

close(ptoc2[1]);

cpu_set_t set;

CPU_ZERO(&set);

int procs=get_nprocs();

CPU_SET(2,&set);

sched_setaffinity(0,sizeof(cpu_set_t),&set);

int min,max;
read(ptoc2[0],&min,sizeof(int));
max=min;
for(int a=1;a<n;a++){
int temp;
read(ptoc2[0],&temp,sizeof(int));
if(min>temp){
min=temp;
}
if(max<temp){
max=temp;
}
}

printf("The minimum and maximum values are %d and %d\n",min,max);

return 0;
}
else{

// Third Child
if(fork()==0){

close(ptoc3[1]);

cpu_set_t set;

CPU_ZERO(&set);

int procs=get_nprocs();

CPU_SET(3,&set);

sched_setaffinity(0,sizeof(cpu_set_t),&set);

int arr[n];
for(int a=0;a<n;a++){
read(ptoc3[0],&arr[a],sizeof(int));
}

for(int a=0;a<n;a++){
int s=a;
for(int b=a+1;b<n;b++){
if(arr[b]<arr[s]){
s=b;
}
}
if(s!=a){
int temp=arr[s];
arr[s]=arr[a];
arr[a]=temp;
}
}

printf("Sorted List: ");
for(int a=0;a<n;a++){
printf("%d ",arr[a]);
}
 printf("\n");
return 0;
}else{

close(ptoc1[0]);
close(ptoc2[0]);
close(ptoc3[0]);

for(int a=0;a<n;a++){
int t=atoi(argv[a+1]);
write(ptoc1[1],&t,sizeof(int));
write(ptoc2[1],&t,sizeof(int));
write(ptoc3[1],&t,sizeof(int));
}

wait(NULL);
}
}
}
return 0;
}
