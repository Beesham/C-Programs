/*
	Author: Beesham Sarendranauth, 104854956
	Date: July 12, 2017
	Description: This program demonstrated the sorting of a matrix of integers
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 10
#define ROW 10
#define SIZE COL * ROW
#define DONE 1
#define FOUND 1
#define NOTFOUND -1

//function prototypes
int sortMatrix (unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);

int main(void){
    
    srand(time(NULL));
    
    int array[ROW][COL] = {0};    //init array to 0
    int searchedNumPosition[2] = {SIZE - 1, 0}; //the position of the number searched will be stored here
    
    int input;
    printf("%s","Please enter a positive number:");
    scanf("%d", &input);
    
    //gens a random num for each element in the array
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            array[i][j] = rand() % 101; //assigns a random positive int from 0 - 100 to a position in the array 
                                        //(0 + (rand() % (100 + 1 - 0)) is the formula used to get 101
        }
    }
    
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (j % COL == 0) puts("");
            printf(" %3d ", array[i][j]);
        } 
    }
    
    int sortedArr = sortMatrix(ROW, COL, array);
    puts("");
       
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (j % COL == 0) puts("");
            printf(" %3d ", array[i][j]);
        } 
    }
    
    int isFound = searchMatrix(input, searchedNumPosition, ROW, COL, array);
    printf("\nisFOund: %d at P{%d, %d}\n", isFound, searchedNumPosition[0], searchedNumPosition[1]);
}

/*
    sortMatrix: sorts a matrix of size NxM in descending order i.e. A[0][0] would have the largest value
    and A[N][M] would have the smallest value
    input: 2 dimensional array A[][], the row (rowsize) and column (colsize) size
    output: returns 1 (DONE) when sort finishes
*/
int sortMatrix (unsigned int rowsize, unsigned int colsize, int A[][colsize]){
    int swap = 0;
    int sizeOfArray = rowsize * colsize;
        
    //control loop for passes
    for(unsigned int pass = 0; pass < sizeOfArray - 1 && !swap; ++pass){
        //control loop for amount of comparisons per pass
        //traverses the matrix of integers
        for(unsigned int i = 0; i < rowsize; i++){
            for(unsigned int j = 0; j < colsize; j++){
                int hold = A[i][j];

                //checks if current num is less than next, if so then swap
                if(A[i][j] < A[i][j+1]){
                    hold = A[i][j];
                    A[i][j] = A[i][j+1];
                    A[i][j+1] = hold;
                    swap = 0;
                }
            }
        }            
    }    
    
    return DONE;
}

/*
    searchMatrix: searches a sorted matrix for a given value using recursive binary search
                  it also computes the position of the value in the matrix
    input: the value to be searched (V)
           the size of the matrix (rowsize, colsize)
           the array (A[][])
           a pointer to the potential position of the value
    output: 1 if the value is found, otherwise -1
*/
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[][colsize]){
    
    int isFound = NOTFOUND;
    int minOffset = *P; //offset for the location of min num in A, the 0th element of arr P
    int maxOffset = *(P + 1);   //offset for the location of max num in A, the 1st element of array P
    int middleOffset = (maxOffset + minOffset) / 2; //offset for the location of middle num in A
    
    int *ptr = &A[0][0];    //points to the beginning of the matrix (A)
            
    //computes the actual value for the min, max, and middle
    int minValue = *(ptr + minOffset);
    int maxValue = *(ptr + maxOffset);
    int middleValue = *(ptr + middleOffset);
    
    //base case
    if (V == middleValue){
        P[0] = middleOffset / colsize;    //row of searched num
        P[1] = middleOffset % colsize;    //col of searched num
        return FOUND;
    }
        
    //if num is not found
    if (((middleValue == minValue) && (middleValue == maxValue) && V != middleValue)){
        P[0] = -1;
        P[1] = -1;
        return NOTFOUND;
    }
        
    if (V > middleValue){   //if num is greater than the middle val of the array, search the upper half
        *P = middleOffset - 1;
        //no need to re-assign the 1st element of arr P as it still is the max
        isFound = searchMatrix(V, P, rowsize, colsize, A);
    }
    else if (V < middleValue){      //if num is lesser than the middle val of the array, search the lower half
        *P = minOffset;
        *(P + 1) = middleOffset + 1;
        isFound = searchMatrix(V, P, rowsize, colsize, A);
    }     
    
    return isFound;
}































