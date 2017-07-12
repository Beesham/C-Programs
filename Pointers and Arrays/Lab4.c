/*
    Author: Beesham Sarendranauth
    Date: 2017/07/17
    Description: performs tasks using pointer operations, such as finding 
    largest number, or swapping   
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

//prototypes
int* largest(int *array, int size);
void swap(int *x, int *y);
void populateRandomArray(int *A, int size);

int main (void){
    srand(time(NULL));  //seeds rand()
    
    int array[SIZE] = {0};
    int a = 3;
    int b = 6;

    //Tests swap function
    printf("%s %d %d\n", "Value of a, b respectively:", a, b);
    printf("%s", "Swapping...");
    getchar();    
    swap(&a, &b);   //performs swap
    printf("%s %d %d\n", "New value of a, b respectively:", a, b);

    puts("");
    
    //Tests largest function
    printf("%s", "Your array numbers are... ");
    getchar();
    populateRandomArray(array, SIZE);   //populates the arrays with random number
    printf("\n%s %d %s %p", "  and the largest number is", *largest(array, SIZE), "at address", (largest(array, SIZE)));
}

/*
    largest: determines the largest value in an array represented by a pointer
    input: an array to be searched, the size of the array
    output: the address of the largest value
*/
int* largest(int *array, int size){
    int *largestElementPtr = array + 1; //init to 2nd element of array so as to facilitate comparisons 

    //loop to compare elements to find largest element address
    for (unsigned int i = 0; i < size; i++, array++){
        if (*array > *largestElementPtr ){
            largestElementPtr = array;
        }
    }
    
    return largestElementPtr;
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

/*
    populateRandomArray: generates a random num from 1 - MxN and stores it in a 2D array
    input: the array to be used to store the numbers
*/
void populateRandomArray(int *A, int size){
    int max = 100;

    for (int j = 0; j < size; j++){
        //Generates a random number and checks if it already exists in the array
        *(A + j) = 1 + (rand() % (max + 1 - 1)); //assigns a random positive int from 1 - max to a position in the array 
                                                //(1 + (rand() % (max + 1 - 1)) is the formula used 
        
        printf(" %3d %p\n", *(A + j), A + j);
    }
}
