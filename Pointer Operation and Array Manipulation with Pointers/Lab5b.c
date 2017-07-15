/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/17
	Description: performs array operations using pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

//prototypes
void swap(int *x, int *y);
void populateRandomArray(int *A, int size);
void printArray(int *A, int size);
void bubbleSortArray (int *A, size_t size);

int main(void){
    srand(time(NULL));  //seeds rand()
    
    int array[SIZE] = {0};
    
    populateRandomArray(array, SIZE);   //populates the arrays with random number
    
    puts("\nUn-sorted randomly generated array of values:");
    printArray(array, SIZE);
    
    bubbleSortArray(array, SIZE);   //sorts array in descending order
    
    puts("\n\nSorted previously generated matrix of values:");
    printArray(array, SIZE);

}

/*
    bubbleSortMatrix: sorts a array in descending order 
    input: 1 dimensional array A[], the size (size)
    output: returns 1 (DONE) when sort finishes
*/
void bubbleSortArray (int *A, size_t size){
    int isSwap = 0;
    int sizeOfArray = size;
        
    //control loop for passes
    for(unsigned int pass = 0; pass < sizeOfArray - 1 && !isSwap; ++pass){
        //control loop for amount of comparisons per pass
        //traverses the array of integers
        for(unsigned int i = 0; i < sizeOfArray; i++){                
                //checks if current num is less than next, if so then swap
                if(*(A + i) <  *(A + i + 1)){
                    swap(A + i, A + i + 1);
                    isSwap = 0;
                }
        }            
    }    
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
    populateRandomArray: generates a random num from 0 - 100 and stores it in a 1D array
    input: the array to be used to store the numbers
*/
void populateRandomArray(int *A, int size){
    int max = 100;

    for (int j = 0; j < size; j++){
        //Generates a random number and checks if it already exists in the array
        *(A + j) = (rand() % (max + 1)); //assigns a random positive int from 1 - max to a position in the array 
                                         //(min + (rand() % (max + 1 - min)) is the formula used         
    }
}

/*
    printArray: displays the values of an array
    input: the array to be displayed (A[])
*/
void printArray(int *A, int size){
    for (int j = 0; j < size; j++){
        if(!(j % 5)) puts("");
        printf(" %3d", *(A + j));
    }
}

