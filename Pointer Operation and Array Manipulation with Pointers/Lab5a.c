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
    
    printf("%p", &a);       //prints the address of var 'a'
    printf("%p", aPtr);     //prints the address of var 'a' through a pointer
    printf("%p", &aPtr);    //prints the address of 'aPtr' itself
    printf("%d", a);        //prints the value of var 'a'
    printf("%d", *aPtr);    //prints the value of var 'a' through pointer dereferencing
    printf("%p", *&aPtr);   //prints the address of 'aPtr' itself because * and & are compliments of each other
    printf("%p", &*aPtr);   //prints the address of 'aPtr' itself because * and & are compliments of each other
    printf("%d", *&a);      //prints the value of var 'a' through address dereferencing 
    //printf("%d", &*a);      //error, var 'a' is not a pointer. &*a is interpreted as ampersand multiplied by var 'a'
    
    return 0;
}