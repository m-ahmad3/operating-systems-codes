#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int max=100;

struct employee{
char id[8];
char name[50];
char gender;
char job[50];
int yoe;
int pay;
};

void printStd(struct employee tmp){
printf("\n%s %s %c %s %d %d",tmp.id,tmp.name,tmp.gender,tmp.job,tmp.yoe,tmp.pay);
}

void readData(struct employee rec[], int* count){
FILE* f=fopen("task1.txt","r");
if(f==NULL){
printf("File Doesn't Exist!...\n");
return;
}

while((fscanf(f,"%s %s %c %s %d %d", rec[*count].id,rec[*count].name,&rec[*count].gender,
rec[*count].job,&rec[*count].yoe,&rec[*count].pay))!=EOF){
    if((*count) > max){
    printf("Max Limit Reached!...\n");
    break;
    }
(*count)++;
}
}
void addRecord(struct employee rec[], int* count){
    if(*count > max){
    printf("Max Limit Reached!...\n");
    return;
    }

    printf("Enter ID: ");
    scanf("%s",rec[*count].id);
    
    printf("Enter Name: ");
    scanf("%s",rec[*count].name);
    
    printf("Enter Gender: ");
    scanf(" %c", &rec[*count].gender);
    
    printf("Enter Job Position: ");
    scanf("%s",rec[*count].job);
    
    printf("Enter Years of Experience: ");
    scanf("%d",&rec[*count].yoe);
    
    printf("Enter Salary: ");
    scanf("%d",&rec[*count].pay);
    
    (*count)++;
    
}

void searchByID(char reg[], struct employee rec[],int count){
     for(int a=0;a<count;a++){
     	if(strcmp(rec[a].id,reg)==0){
     	   printStd(rec[a]);
     	   return;
     	}
     }
}

void showAllRecord(struct employee rec[], int count){
for(int a=0;a<count;a++){
   printStd(rec[a]);
}
printf("\n");
}
void showBelowBasicpay(struct employee rec[], int count, int basicpay){
    for(int a=0;a<count;a++){
     	if(rec[a].pay<basicpay){
     	   printStd(rec[a]);
     	}
     }
}

int main(){

struct employee rec[max];
int count=0;
FILE* f=fopen("task1.txt","r");
readData(rec, &count);
int r=-1;

printf("\n\t---Menu---");

while(r!=0){
printf("\n1. Add a record\n");
printf("2. Search a record by ID\n");
printf("3. Show all records\n");
printf("4. Show employees having pay less then basic pay (20000)\n");
printf("5. Save and exit\n");

printf("Enter Your Choice: ");
scanf("%d",&r);

switch(r){
case 5:
r=0;
break;

case 1:
addRecord(rec, &count);
break;

case 2:
char id[8];
printf("Enter ID to Search: ");
scanf("%s", id);
searchByID(id,rec,count);
break;

case 3:
showAllRecord(rec,count);
break;

case 4:
showBelowBasicpay(rec,count,20000);
break;

default:
printf("Wrong Input!....\n");
break;
}
}

return 0;
}









































