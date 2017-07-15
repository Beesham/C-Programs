/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/07/17
    Description: printing pointers
*/
#include <stdio.h>

int main(void){
    int a = 7;
    int *aPtr;
    aPtr = &a;
    
    printf("%p", &a);
    printf("%p", aPtr);
    printf("%p", &aPtr);
    printf("%d", a);
    printf("%d", *aPtr);
    printf("%p", *&aPtr);
    printf("%p", &*aPtr);
    printf("%d", *&a);
    printf("%d", &*a);
    
    return 0;
}