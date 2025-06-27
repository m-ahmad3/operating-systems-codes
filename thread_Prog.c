#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

void* func(void* arg);

int main()
{
    size_t stack;
    
    pthread_attr_t at;
    
    pthread_attr_init(&at);
    
    pthread_attr_getstacksize(&at, &stack);
    
    printf("Default stack size is %d\n",(int)stack);
    
    pthread_attr_setstacksize(&at, 1024*1024*16);
    
    pthread_t thread;
    
    int arr[] = {1, 2, 3, 4};
    
    int result; void* tmp;
    
    pthread_create(&thread, &at, func, (void*)arr);
    
    //pthread_cancel(thread);
    
    pthread_join(thread, &tmp);
    
    printf("----- Inside main() -----\n");
    
    pthread_attr_getstacksize(&at, &stack);
    
    printf("New stack size is %d\n",(int)stack);
    
    result = *((int*)tmp);
    
    printf("Result from thread is %d",result);

    return 0;
}

void* func(void* arg){
    
    /*pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);*/
    
    //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    
    printf("----- Inside thread -----\n");
    
    int* sum = (int *) arg;
    
    int* result = (int *)malloc(sizeof(int));
    
    *result = sum[0] + sum[1];
    
    printf("Addition result is %d\n",*result);
    
    //pthread_testcancel();
    pthread_exit((void *)result);
}