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

#include <stdio.h>

int main() {

   int b,p,h;
   printf("Enter Length of Perpendicular: ");
   scanf("%d",&p);
   printf("Enter Length of Hypotenuse: ");
   scanf("%d",&h);
   printf("Enter Length of Base: ");
   scanf("%d",&b);
   
   if (p + b > h && p + h > b && b + h > p){
    //Scalene: No sides of the triangle are 
    //equal to each other. 
    if(h!=p&&h!=b&&p!=b){
        printf("\nThis is Scalene Triangle");
    }
    else if(h==p&&p==b){
        printf("\nThis is Equilateral Triangle");
    }
    else{
        printf("\nThis is Isosceles Triangle");
    }
    //Isosceles: Two sides of the triangle are equal. 
    //Equilateral: All three sides are equal. 
   }
   else{
       printf("\nThis is Not a Triangle!");
   }

    return 0;
}

#include <stdio.h>

int main() {

   const int size=20;
   int arr[size];
   
   printf("Input Sequence: ");
   int s=0;
   for(int a=0;a<size;a++){
       int t;
      
       scanf("%d",&t);
       if(t==-99){
           break;
       }
        s++;
       arr[a]=t;
   }
   printf("The entered sequence is: ");
   for(int a=0;a<s;a++){
       printf("%d ",arr[a]);
   }
   
   
   for(int a=0;a<s;a++){
       for(int b=0;b<s-a-1;b++){
           if(arr[b]>arr[b+1]){
               int t=arr[b];
               arr[b]=arr[b+1];
               arr[b+1]=t;
           }
       }
   }

   printf("Updated sequence is: ");
   for(int a=0;a<s;a++){
       printf("%d ",arr[a]);
   }
   
    
    return 0;
}

#include <stdio.h>

void checkPrimeNumber(int n){
    if(n<2){
         printf("\n%d is not a Prime Number!...", n);
            return;
    }
    for(int a=2;a<n;a++){
        if(n%a==0){
            printf("\n%d is not a Prime Number!...", n);
            return;
        }
    }
      printf("\n%d is a Prime Number!...",n);  
}

int main() {

   int in;
   printf("Enter a Number: ");
   scanf("%d",&in);
   
   checkPrimeNumber(in);
    
    return 0;
}