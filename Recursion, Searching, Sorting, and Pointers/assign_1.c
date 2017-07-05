/*
	Author: Beesham Sarendranauth, 104854956
	Date: July 12, 2017
	Description: This program demonstrated the sorting of a matrix of integers
*/
#include <stdio.h>
#define COL 20
#define ROW 20
#define DONE 1

//function prototypes
int sortMatrix (unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[rowsize][colsize]);

int main(void){
    int array[2][6]={{4,8,6,9,4}, {8,6,2,5,4,7}};
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
            printf("%2d", array[i][j]);
	} 
        puts("");
    }
    
    int sortedArr = sortMatrix(2, 6, array);
    puts("");
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
            printf("%2d", array[i][j]);
        } 
        puts("");
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
    
    
    return 0;
}

/*
    searchMatrix:
    input:
    output:
*/
int searchMatrix (int V, int *P, unsigned int rowsize, unsigned int colsize, int A[][colsize]){
    
    return 0;
}
