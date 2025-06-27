// Task 1: Calculate area of Rectangle
#include <stdio.h>

int main() {

   int len,wid;
   printf("\t---Rectangle Area Calculator---\n");
   printf("What is the length of rectangle? ");
   scanf("%d",&len);

   printf("What is the width of rectangle? ");
   scanf("%d",&wid);
   
   printf("\nThe area of rectangle is %d.\n",len*wid);

    return 0;
}

// Task 2: Evaluate Triangle

#include<stdio.h>

int main(){

int p,h,b;

printf("Enter Length of Perpendicular: ");
scanf("%d",&p);

printf("Enter Length of Hypotenuse: ");
scanf("%d",&h);

printf("Enter Length of Base: ");
scanf("%d",&b);

if(p+h>b&&p+b>h&&h+b>p){
  if(p!=h&&h!=b&&b!=p){
    printf("The Triangle is Scalene\n");
  }
  else if(p==h&&h==b){
    printf("The Triangle is Equilateral\n");
  }
  else{
    printf("The Triangle is Isosceles\n");
  }
}
else{
printf("It is Not a Triangle!...\n");
}

return 0;
}


// Task 3: Get and Sort the Array

#include<stdio.h>

int main(){

const int s=20;
int count=0;
int arr[s];

printf("Input Sequence: ");
for(int a=0;a<s;a++){
int t;
scanf("%d",&t);
  if(t==-99){
    break;
   }
 count++;
 arr[a]=t;
}

printf("\nThe Entered Sequence is: ");
for(int a=0;a<count;a++){
printf("%d ",arr[a]);
}

for(int a=0;a<count;a++){
  for(int b=0;b<count-a-1;b++){
  	if(arr[b]>arr[b+1]){
	int t=arr[b+1];
	arr[b+1]=arr[b];
	arr[b]=t;  	
  	}
  }
 }

printf("\nUpdated Sequence is: ");
for(int a=0;a<count;a++){
printf("%d ",arr[a]);
}

return 0;
}


// Task 4: Check Prime Number
#include<stdio.h>

void checkPrimeNumber(int n){
  if(n<2){
    printf("%d is not a Prime Number!...\n",n);
    return;	
  }
  for(int a=2;a<n;a++){
    if(n%a==0){
      printf("%d is not a Prime Number!...\n",n);
      return;
    }
  }
  
  printf("%d is a Prime Number!...\n",n);
}

int main(){

 int in;
 
 printf("Enter Number to Check Prime No.: ");
 scanf("%d",&in);
 
 checkPrimeNumber(in);


return 0;
}

// Task 5: Multiply from Command Line
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  printf("Answer of Multiplication: %d\n", atoi(argv[1])*atoi(argv[2]));
return 0;
}

// Task 6: Run Time Memory
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  
  int* arr=malloc(sizeof(int)*(argc-1));
  
  int i=1;
  for(int a=0;a<argc-1;a++){
    arr[a]=atoi(argv[i++]);
  }
  
  int min=arr[0];
  int secMin;
  for(int a=0;a<argc-1;a++){
    if(arr[a]<min){
    	secMin=min;
    	min=arr[a];
    }
  }
    printf("Second Minimum No. is: %d\n", secMin);
  
return 0;
}

// Task 7: Struct
#include<stdio.h>

struct info{
  int id;
  char name[50];
  int age;
  float pay;
};

int main(){
  
  struct info i={123,"Ahmad",20,154.98};
  printf("Details of Employee: \n");
  printf("Id: %d\nName: %s\nAge: %d\nPay: %f\n", i.id,i.name,i.age,i.pay);
  
return 0;
}
#include<stdio.h>

struct employee{
  char name[50];
  char gender;
  char position[50];
  int exp;
  int pay;
};

void printStd(employee tmp){
  printf("\nId: %d Name: %s Gender: %c Position: %s Experience: %d Pay: %d, tmp.id,tmp.name,tmp.gender,tmp.position,tmp.exp,tmp.pay);
}
void readData(employee rec[], int &count){
  FILE *f;
  f=fopen("task1.txt","r");
}
void addRecord(employee rec[], int*count)
void searchByID(char reg[], employee rec[],int count)
void showAllRecord(employee rec[], int count)
void showBelowBasicpay(employee [], int count, int basicpay)

int main(){
  

  
return 0;
}
