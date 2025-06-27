#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

int n=argc-1;
int arr[n];

int ptoc[2];
int ctop[2];

pipe(ptoc);
pipe(ctop);

wait(NULL);

if(fork()==0){
close(ptoc[1]);
close(ctop[0]);

for(int a=0;a<n;a++){
read(ptoc[0],&arr[a],sizeof(int));
}

for(int a=0;a<n;a++){
for(int b=0;b<n-a-1;b++){
if(arr[b]>arr[b+1]){
int t=arr[b];
arr[b]=arr[b+1];
arr[b+1]=t;
}
}
}

for(int a=0;a<n;a++){
write(ctop[1],&arr[a],sizeof(int));
}

exit(0);
}

close(ptoc[0]);
close(ctop[1]);

for(int a=1;a<=n;a++){
int temp=atoi(argv[a]);
write(ptoc[1],&temp,sizeof(int));
}

printf("Sorted Array is: ");
for(int a=0;a<n;a++){
int temp;
read(ctop[0],&temp,sizeof(int));
printf("%d ",temp);
}
printf("\n");

return 0;
}
