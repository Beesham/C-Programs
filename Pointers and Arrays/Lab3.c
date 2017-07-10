/*
    Author: Beesham Sarendranauth
    Date: 2017/07/18
    Description: Performs 2 dimensional array manipulations such as creating,
    filling, searching, and left shifting
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 6
#define N 5

//prototypes
void printArray2D(int array[][N]);
void populateRandom2D(int array[][N]);
void linearSearch2D(int array[][N], int num);
void leftShift2D(int array[][N]);

int main(void){
    srand(time(NULL));


}

/*
    printArray2D: prints the 2D array in a table format
    input: the array to be printed (A)
*/
void printArray2D(int A[][N]){
    puts("");

    //traverses and displays matrix
    for (int i = 0; i < M; i++){
        
        //prints column header
        if (i == 0){
            printf(" %3s  ", " ");
            for (int j = 0; j < N; j++){
                printf(" %3d ", j);
            }
            
            puts("");
            
            printf(" %3s  ", " ");
            for (int j = 0; j < N; j++){
                printf(" %3s ", "V");
            } 
        }
        
        //prints the value of the matrix at the index
        for (int j = 0; j < N; j++){
            if (j % N == 0){
                puts("");
                printf(" %3d %s", i, ">");  //prints row header
            }
            printf(" %3d ", A[i][j]);
        } 
    }
    
    puts("");
}

/*
    populateRandom2D: generates a random num from 1 - MxN and stores it in a 2D array
    input: the array to be used to store the numbers

*/
void populateRandom2D(int A[][N]){
    int max = M * N;

    //TODO: implement check for num uniqueness

    //gens a random num for each element in the array
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = rand() % 1 + (rand() % (max)); //assigns a random positive int from 1 - max to a position in the array 
                                    //(1 + (rand() % (max + 1 - 1)) is the formula used 
        }
    }
}

/*

*/
void linearSearch2D(int A[][N], int num){

}

/*

*/
void leftShift2D(int A[][N]){

}
