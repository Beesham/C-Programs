/*
	Author: Beesham Sarendranauth, 104854956
	Date: July 12, 2017
	Description: This program demonstrated the sorting of a matrix of integers
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 20
#define ROW 20
#define DONE 1

//function prototypes
int sortMatrix (unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);

int main(void){
    
    srand(time(NULL));
    
    int array[ROW][COL] = {0};    //init array to 0
    
    //gens a random num for each element in the array
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            array[i][j] = rand() % 101; //assigns a random positive int from 0 - 100 to a position in the array
        }
    }
    
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if (j % 10 == 0) puts("");
            printf(" %3d ", array[i][j]);
        } 
    }
    
    int sortedArr = sortMatrix(ROW, COL, array);
    puts("");
    
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if (j % 10 == 0) puts("");
            printf(" %3d ", array[i][j]);
        } 
    }
}

/*
    sortMatrix: sorts a matrix of size NxM in descending order i.e. A[0][0] would have the largest value
    and A[N][M] would have the smallest value.
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
    searchMatrix:
    input:
    output:
*/
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[][colsize]){
    
    return 0;
}
