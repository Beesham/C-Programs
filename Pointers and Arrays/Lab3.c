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
#define FOUND 1
#define NOTFOUND 0

//prototypes
int prompt();
void zeroArray(int array[][N]);
void printArray2D(int array[][N]);
void populateRandom2D(int array[][N]);
int linearSearch2D(const int array[][N], int num);
void leftShift2D(int array[][N]);

int main(void){
    srand(time(NULL));  //seeds the rand() 
    int array[M][N] = {0}; //init the array to 0's
    int selection;

    while(selection != EOF){ 
        
        //displays a menu
        puts("");
        puts("*************");
        puts("*   Menu    *");
        puts("*************");
        puts("1. Populate Array");
        puts("2. Print Array");
        puts("3. Search Array");
        puts("4. Left Shift Array");

        puts("");
        puts("Please select the number index of your operation e.g 1 \nEnter -1 to quit (ERROR prints upon exit)");
        printf("%s","Input: ");
        scanf("%d", &selection);

        //switch statement to select appropriate operation
        switch(selection){
          case 1:{ 
                populateRandom2D(array);
          }
          break;
          
          case 2:{ 
                printArray2D(array);       
          }
          break;
          
          case 3:{ 
                int input;
                input = prompt();
                if(linearSearch2D(array, input)) puts("Your number was found");
                else puts("Your number is not found!");
          }
          break;
          
          case 4:{ 
                leftShift2D(array);
          }
          break;
                          
          default:
              puts("ERROR: selection must be from the menu shown");
        }
            
        getchar();  //waits for user to hit Enter to continue
    }

}

/*
  prompt: displays a message to the user asking for input
  Input:
  Output: the users input
*/
int prompt(){
    int input;
    printf("%s", "Please enter a positive integer: ");
    scanf("%d", &input);
    return input;
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
    seroArray: fills the array with zero, so as to re-initialize it
    input: the array to be zeroed (A)
*/
void zeroArray(int A[][N]){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = 0;
        }
    }
}

/*
    populateRandom2D: generates a random num from 1 - MxN and stores it in a 2D array
    input: the array to be used to store the numbers

*/
void populateRandom2D(int A[][N]){
    int max = M * N;

    zeroArray(A);   //zeros the array first, in case of subsequent calls to populate the array

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){

            int randNum;
            //Generates a random number and checks if it already exists in the array
            do{		 
                
                randNum = 1 + (rand() % (max + 1 - 1)); //assigns a random positive int from 1 - max to a position in the array 
                                                        //(1 + (rand() % (max + 1 - 1)) is the formula used 
            }while(linearSearch2D(A, randNum));
            A[i][j] = randNum;
        }
    }
}

/*
    linearSearch2D: searches a 2 dimensional array for a specific value
    input: the value to search for (num)
    output: 1 if found, else 0 if not found
*/
int linearSearch2D(const int A[][N], int num){
    int isFound = NOTFOUND;
    
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if(A[i][j] == num){ 
                isFound = FOUND;
                return isFound;
            }
        }
    }

    return isFound;
}

/*
    leftShift2D: left shifts the entire array by 1, replacing the last element with the first
    input: the array to be leftshifted (A)
*/
void leftShift2D(int A[][N]){
    int holdPos1 = A[0][0]; //holds the value of the first element of the array
    
    //Loops through the array and swaps each element with its preceding one
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            int hold = A[i][j];
            A[i][j] = A[i][j+1];
            A[i][j+1] = hold;
        }
    }
    
    A[M-1][N-1] = holdPos1; //places the first element in the last position in the array
}
