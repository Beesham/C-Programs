/*
    Author: Beesham Sarendranauth
    Date: 2017/07/18
    Description: performs tasks using pointer operations, such as finding 
    largest number, or swaping   
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

//prototypes
int* largest(int *array, int size);
void swap(int *x, int *y);

int main (void){
    int array[SIZE] = {2,0,6,7,3,9,5,12,16,27};
    int a = 3;
    int b = 6;

    swap(&a, &b);
    printf("%d %d", a, b);
    printf("%d", *(largest(array, SIZE)));
}

/*
    largest: determines the largest value in an array represented by a pointer
    input: an array to be searched, the size of the array
    output: the address of the largest value
*/
int* largest(int *array, int size){
    int *holdPtr = NULL;
    int *arrayPtr = array;
    
    for(unsigned int i = 0; i < size; i++){
        if(*arrayPtr > *(arrayPtr + i)){
            holdPtr = arrayPtr;
        }
        else{
            holdPtr = (arrayPtr + 1);
        }
    }
    
    return holdPtr;
}

/*
    swap: swaps the 2 pointers' values
    input: 2 pointers, (x, y)
*/
void swap(int *x, int *y){
    int hold = *y;
    *y = *x;
    *x = hold;
}