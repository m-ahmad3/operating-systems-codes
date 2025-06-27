#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>

void* avg(void* arg){

int* list=(int*)arg;

int* ret=(int*)malloc(sizeof(int));
*ret=0;
int size=sizeof(list)-1;
for(int a=0;a<size;a++){
*ret+=list[a];
}

*ret/=size;

return ret;
}

void* max(void* arg){

int* list=(int*)arg;

int* ret=(int*)malloc(sizeof(int));

*ret=list[0];

int size=sizeof(list)-1;

for(int a=1;a<size;a++){
if(*ret<list[a]){
*ret=list[a];
}
}

return ret;
}

void* min(void* arg){

int* list=(int*)arg;

int* ret=(int*)malloc(sizeof(int));

*ret=list[0];

int size=sizeof(list)-1;

for(int a=1;a<size;a++){
if(*ret>list[a]){
*ret=list[a];
}
}

return ret;
}

int main(int argc, char* argv[])
{

int arr[argc-1];

for(int a=0;a<argc-1;a++){
arr[a]=atoi(argv[a+1]);
}

pthread_t threads[3];

pthread_create(&threads[0],NULL,&avg,(void*)arr);
pthread_create(&threads[1],NULL,&max,(void*)arr);
pthread_create(&threads[2],NULL,&min,(void*)arr);

void* ret;

pthread_join(threads[0],&ret);
int av=*((int*)ret);

pthread_join(threads[1],&ret);
int mx=*((int*)ret);

pthread_join(threads[2],&ret);
int mn=*((int*)ret);

printf("Average Value is %d\n",av);
printf("Minimum Value is %d\n",mn);
printf("Maximum Value is %d\n",mx);


return 0;
}
