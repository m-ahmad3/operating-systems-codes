#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<limits.h>
#include<math.h>

/*int n=0;
int result[100];
int tnum=0;

void * fact(void * arg){

  int id=*((int *) arg);
  int product=1;
  int chunk=n/tnum;
  int st=chunk* id+1;
  int ed=(id==tnum-1)?n:st+chunk-1;
  for(int i=st;i<=ed;i++){
    product=product*i;
  }
  result[id]=product;
  pthread_exit(NULL);
}

int main(int argc,char * argv[]){

 n=atoi(argv[1]);
 tnum=atoi(argv[2]);
 
 pthread_t threads[tnum+1];
 int tid[tnum+1];
 
 for(int i=0;i<tnum;i++){
  tid[i]=i;
  pthread_create(&threads[i],NULL,fact,(void *)&tid[i]);
 }
 
 for(int i=0;i<tnum;i++){
  pthread_join(threads[i],NULL);
 }
 
 int s=1;
 for(int i=0;i<tnum;i++){
  s=s*result[i];
 }
printf("factorial is %d\n",s);

 return 0;
}*/

/*int result[50];
int n=0;
int tnum=0;
int arr[50];
int chunk=0;

void * SUM(void * ptr){

  int id=*(int *)ptr;
  
  int st=chunk* id;
  int ed=(id==tnum-1)?n:st+chunk;
  int s=0;
  for(int i=st;i<ed;i++){
   s=s+arr[i];
  }
  result[id]=s;
  pthread_exit(NULL);
}

int main(int argc,char * argv[]){
  
  n=argc-2;
  
  for(int i=0;i<n;i++){
    arr[i]=atoi(argv[i+2]);
  }
  
  tnum=atoi(argv[1]);
  chunk=n/tnum;
  
  pthread_t threads[tnum];
  int id[tnum];
  
  for(int i=0;i<tnum;i++){
  id[i]=i;
  pthread_create(&threads[i],NULL,SUM,(void *)&id[i]);
  }
  for(int i=0;i<tnum;i++){
  pthread_join(threads[i],NULL);
  }
  
  int re=0;
    for(int i=0;i<tnum;i++){
    re=re+result[i];
  }

printf("sum is %d\n",re);

return 0;
}
*/

/*int n=0;
int arr[30];

void * average(void * id){

  int s=0;
  for(int i=0;i<n;i++){
    s+=arr[i];
  }
  int * avg=malloc(sizeof(int));
  *avg=s/n;
  pthread_exit((void *)avg);

}

void * max1(void * id){

  int *max=malloc(sizeof(int));
  *max=INT_MIN;
  for(int i=0;i<n;i++){
    if(*max<arr[i]){
      *max=arr[i];
    }
  }
  pthread_exit((void *)max);

}

void * min1(void * id){

  int *min=malloc(sizeof(int));
  *min=INT_MAX;
  for(int i=0;i<n;i++){
    if(*min>arr[i]){
      *min=arr[i];
    }
  }
  pthread_exit((void *)min);

}

int main(int argc,char * argv[]){
  
  n=argc-1;
  for(int i=0;i<n;i++){
    arr[i]=atoi(argv[i+1]);
  }
  
  pthread_t threads[3];
  void * result=0;
  pthread_create(&threads[0],NULL,average,NULL);
  pthread_join(threads[0],&result);
  printf("Average is %d\n",*(int *)result);
  
  pthread_create(&threads[1],NULL,min1,NULL);
  pthread_join(threads[1],&result);
  printf("MIN is %d\n",*(int *)result);
  
  pthread_create(&threads[2],NULL,max1,NULL);
  pthread_join(threads[2],&result);
  printf("Max is %d\n",*(int *)result);
  
  return 0;
}*/

/*int n=0;
int arr[30];
int max[30];
int tnum=0;
int chunk=0;

  void * MAX1(void * ptr){
   
    int  id=*(int *)ptr;
    int st=chunk*id;
    int ed=(id==tnum-1)?n:st+chunk;
    int m=INT_MIN;
    
    for(int i=st;i<ed;i++){
      if(m<arr[i]){
       m=arr[i];
      }
    }
    
    max[id]=m;
    pthread_exit(NULL);
}
int main(int argc,char * argv[]){

tnum=atoi(argv[1]);
n=argc-2;
chunk=n/tnum;

for(int i=0;i<n;i++){
arr[i]=atoi(argv[i+2]);
}

pthread_t thread[tnum];
int tid[tnum];

for(int i=0;i<tnum;i++){
  tid[i]=i;
  pthread_create(&thread[i],NULL,MAX1,(void *)&tid[i]);
}

for(int i=0;i<tnum;i++){
  pthread_join(thread[i],NULL);
}
int result=INT_MIN;
for(int i=0;i<tnum;i++){
  if(result<max[i]){
    result=max[i];
  }
}

printf("MAX IS %d\n",result);
return 0;
}*/

/*double result1=0.0;
int  n=0;
int tnum=0;
int chunk=0;


void * calpie(void * arg){

  int id=*((int *)arg);
  double t=0.0;
  for(int i=id;i<=n;i+=tnum){
   double temp;
   if(i%2==0){
    temp=1.0/(2*i+1);
   }
   else{
    temp=-1.0/(2*i+1);
   }
   t+=temp;
}

result1 +=t;
pthread_exit(NULL);
}

int main(int argc,char * argv[]){

n=atoi(argv[2]);
tnum=atoi(argv[1]);
chunk=n/tnum;
  if(n<100000 || n%tnum !=0){
    printf("wrong input\n");
    return 1;
  }
pthread_t thread[tnum];
int id[tnum];
  for(int i=0;i<tnum;i++){
    id[i]=i;
    pthread_create(&thread[i],NULL,calpie,&id[i]);
  }
  for(int i=0;i<tnum;i++){
    pthread_join(thread[i],NULL);
  }
  double pie=4*result1;
  printf("Value is %.15f\n",pie);
  return 0;
}*/

// 3+6+9+12+16....... Arithmetic Series

/*int n=0;
int tnum=0;
int result[30];
int chunk=0;

void * arith(void * arg){

  int id=*(int *)arg;
  int sum=0;
  for(int i=id;i<=n;i+=tnum){
  int t;
  t=(i*3);
  sum+=t;
}
  result[id-1]=sum;
  pthread_exit(NULL);
  
}

int main(int argc,char * argv[]){

  n=atoi(argv[1]);
  tnum=atoi(argv[2]);
  pthread_t threads[tnum];
  int tid[tnum];
  chunk=n/tnum;
  
  for(int i=0;i<tnum;i++){
    tid[i]=i+1;
    pthread_create(&threads[i],NULL,arith,&tid[i]);
  }
  for(int i=0;i<tnum;i++){
    pthread_join(threads[i],NULL);
  }
  int r=0;
  for(int i=0;i<tnum;i++){
    r=r+result[i];
  }
  printf("Sum is %d\n",r);
  return 0;
}*/

// Harmonic Series 1+1/2+1/3+1/4

/*int n=0;
int tnum=0;
double result[30];
int chunk=0;

void * har(void * arg){

  int id=*(int *)arg;
  double sum=0.0;
  for(int i=id;i<=n;i+=tnum){
  double t;
  t=(1.0/i);
  sum+=t;
}
  result[id-1]=sum;
  pthread_exit(NULL);
  
}

int main(int argc,char * argv[]){

  n=atoi(argv[1]);
  tnum=atoi(argv[2]);
  pthread_t threads[tnum];
  int tid[tnum];
  chunk=n/tnum;
  
  for(int i=0;i<tnum;i++){
    tid[i]=i+1;
    pthread_create(&threads[i],NULL,har,&tid[i]);
  }
  for(int i=0;i<tnum;i++){
    pthread_join(threads[i],NULL);
  }
  double r=0.0;
  for(int i=0;i<tnum;i++){
    r=r+result[i];
  }
  printf("Sum is %f\n",r);
  return 0;
}*/

int n=0;
int tnum=0;
int result[300];
int chunk=0;

void * gseries(void * arg){

  int id=*(int *)arg;
  for(int i=id;i<n;i+=tnum){
  result[i]=(int)pow(3,i);
}
  pthread_exit(NULL);
  
}

int main(int argc,char * argv[]){

  n=atoi(argv[1]);
  tnum=atoi(argv[2]);
  pthread_t threads[tnum];
  int tid[tnum];
  chunk=n/tnum;
  
  for(int i=0;i<tnum;i++){
    tid[i]=i;
    pthread_create(&threads[i],NULL,gseries,&tid[i]);
  }
  for(int i=0;i<tnum;i++){
    pthread_join(threads[i],NULL);
  }
  int r=0.0;
  for(int i=0;i<n;i++){
    r=r+result[i];
  }
  printf("Sum is %d\n",r);
  return 0;
}
