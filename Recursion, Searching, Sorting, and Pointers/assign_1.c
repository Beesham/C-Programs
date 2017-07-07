/*
	Author: Beesham Sarendranauth, 104854956
	Date: July 12, 2017
	Description: This program demonstrated the sorting of a matrix of integers
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 3
#define ROW 3
#define SIZE COL * ROW
#define DONE 1

//function prototypes
int sortMatrix (unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);

int main(void){
    
    srand(time(NULL));
    
    int array[ROW][COL] = {{2,3,4},{5,6,7},{8,9, 10}};    //init array to 0
    int searchedNumPosition[2] = {0, SIZE - 1};
    
    //gens a random num for each element in the array
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            //array[i][j] = rand() % 101; //assigns a random positive int from 0 - 100 to a position in the array 
                                        //(0 + (rand() % (100 + 1 - 0)) is the formula used to get 101
        }
    }
    
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (j % 10 == 0) puts("");
            printf(" %3d ", array[i][j]);
        } 
    }
    
    //int sortedArr = sortMatrix(ROW, COL, array);
    puts("");
    
    int isFound = searchMatrix(9, searchedNumPosition, ROW, COL, array);
    printf("\nisFOund: %d\n", isFound);

    
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (j % 10 == 0) puts("");
            printf(" %3d ", array[i][j]);
        } 
    }
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
    
    for(unsigned int pass = 0; pass < sizeOfArray - pass - 1 && !swap; pass++){
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
    searchMatrix: searches a sorted matrix for a given value using recursive binary search.
                  it also computes the position of the value in the matrix
    input: the value to be searched (V)
           the size of the matrix (rowsize, colsize)
           the array (A[][])
           a pointer to the potential position of the value
    output: 1 if the value is found, otherwise -1
*/
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[][colsize]){
    int foundNum = -1;
    int minOffset = *P;
    int maxOffset = *(P + 1);
    int middleOffset = (maxOffset + minOffset) / 2;
    
    int *ptr = &A[0][0];
    
    printf("\nminOff: %d maxOff: %d midOff: %d\n", minOffset, maxOffset, middleOffset);
        
    int minValue = *(ptr + minOffset);
    int maxValue = *(ptr + maxOffset);
    int middleValue = *(ptr + middleOffset);

    printf("\nA min: %d, max: %d, mid: %d\n", minValue, maxValue, middleValue);

    //base case
    if (V == middleValue) return 1;
    if (V > middleValue){
        *P = middleOffset;
        searchMatrix(V, P, rowsize, colsize, A);
    }
    else if (V < middleValue){
        *P = minOffset;
        *(P + 1) = middleOffset;
        searchMatrix(V, P, rowsize, colsize, A);
    }
    /*
    else if (V > A[rowsize/2][colsize/2]){
        searchMatrix(V, P, rowsize/2, colsize/2, A);
    }
    */
        
    
    return foundNum;
}































