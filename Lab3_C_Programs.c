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

// task1.txt
/*
Emp01 Asad M internee 1 14000
Emp02 Ahmad M developer 2 50000
Emp03 Ayesha F sqaanalyst 5 35000
Emp04 Amjad M dataanalyst 3 30000
Emp05 Bushra F personalassistant 4 25000
Emp06 Bisma F developer 2 40000
Emp09 ahama m asd 3 234
*/

// Task 8: Filing
#include<stdio.h>
#include<string.h>

const int max=100;

struct employee{
  char id[50];
  char name[50];
  char gender;
  char position[50];
  int exp;
  int pay;
};

void printStd(struct employee tmp){
  printf("\nId: %s, Name: %s, Gender: %c, Position: %s, Experience: %d Years, Pay: Rs. %d\n", 
  tmp.id, tmp.name, tmp.gender, tmp.position, tmp.exp, tmp.pay);
}

void readData(struct employee rec[], int *count){
  FILE *f;
  f=fopen("task1.txt","r");
  if(f==NULL){
    printf("File is Not Found!...\n");
    return;
  }
  while(fscanf(f,"%s %s %c %s %d %d", rec[*count].id, rec[*count].name, &rec[*count].gender, rec[*count].position, &rec[*count].exp, &rec[*count].pay)!=EOF){
  (*count)++;
  }
  fclose(f);
}

void addRecord(struct employee rec[], int *count){
  if(*count>=max){
    printf("Maximum employee limit reached\n");
    return;
  }
  printf("\nEnter ID: ");
  scanf("%s", rec[*count].id);
  printf("Enter Name: ");
  scanf("%s", rec[*count].name);
  printf("Enter Gender (m/f): ");
  scanf(" %c", &rec[*count].gender);
  printf("Enter Position: ");
  scanf("%s", rec[*count].position);
  printf("Enter Experience (in years): ");
  scanf("%d", &rec[*count].exp);
  printf("Enter Pay: ");
  scanf("%d", &rec[*count].pay);
  
  FILE *f=fopen("task1.txt","a");
  fprintf(f, "%s %s %c %s %d %d", rec[*count].id, rec[*count].name, rec[*count].gender, rec[*count].position, rec[*count].exp, rec[*count].pay);
  fclose(f);
  *count++;
}


void searchByID(char reg[],struct employee rec[],int count){
  for(int a=0;a<count;a++){
    if(strcmp(rec[a].id,reg)==1){
      printStd(rec[a]);
      return;
    }
  }
  printf("ID %s not found in Record\n", reg);
}
void showAllRecord(struct employee rec[], int count){
  for(int a=0;a<count;a++){
    printStd(rec[a]);
  }
}
void showBelowBasicpay(struct employee rec[], int count, int basicpay){
  printf("\nEmployees with Salary Lower then %d:\n",basicpay);
  for(int a=0;a<count;a++){
    if(rec[a].pay<basicpay){
      printStd(rec[a]);
    }
  }
}

int main(){
  struct employee rec[max];
  int count=0;
  readData(rec,&count);
  
  
  int r=-1;
  
  while(r!=0){
  printf("\n\t---Menu---\n");
  printf("1. Add a Record\n");
  printf("2. Search a Record by ID\n");
  printf("3. Show all Records\n");
  printf("4. Show employees having pay less then basic pay\n");
  printf("5. Save and exit\n");
  
  printf("Enter the Option: ");
  scanf("%d", &r);
  
  if(r==1){
    addRecord(rec,&count);
  }
  else if(r==2){
    char id[50];
    printf("\nEnter the ID: ");
    scanf("%s",id);
    searchByID(id,rec,count);
  }
  else if(r==3){
    showAllRecord(rec,count);
  }
  else if(r==4){
    showBelowBasicpay(rec,count,20000);
  }
  else if(r==5){
    r=0;
  }
  else{
  printf("Invalid Option!...\n");
  }
 }

  
return 0;
}
