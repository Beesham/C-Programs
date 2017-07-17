/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/17
	Description: performs string manipulation operations such as tokenization and reversal
*/
#include <stdio.h>
#include <string.h>

//prototypes
void reverse(char *A);
void parseSentence(char *S);

int main(void){
    
    char buffer1[] = {'t', 'h', 'i', 's', ' ',
                      'i','s', ' ',
                      't', 'h', 'e', ' ',
                      'f', 'i', 'r', 's', 't', ' ',
                      'b', 'u', 'f', 'f', 'e', 'r',
                      '\0'};
    char buffer2[] = "this is the second buffer";
    char buffer3[80];
    
    printf("\n%s", "Please enter a sentence: ");
    //scanf("%s", buffer3);   //only reads in a single word. To read a whole line fgets should be used
    fgets(buffer3, 80, stdin);
    
    printf("\n%s %s\n%s %s\n%s %s\n", "buffer1:", buffer1, "buffer2:", buffer2, "buffer3:", buffer3);
    
    char *pBuffer = buffer3;
    
    printf("%s %s", "pBuffer before being incremented:", pBuffer);
    
    pBuffer++;
    pBuffer++;
    pBuffer++;

    printf("%s %s\n", "pBuffer after being incremented by 3 chars:", pBuffer);
    
    printf("%s %s\n", "buffer2 before being reversed:", buffer2);
    reverse(buffer2);
    printf("%s %s\n", "buffer2 after being reversed:", buffer2);

    printf("\n%s\n", "Your sentence tokenized: ");
    parseSentence(buffer3);

    return 0;
}

/*
    reverse: reverses the elements of an array
    input: the array to be reversed (A)
*/
void reverse(char *A){
    
    int sizeOfArray = strlen(A);
    char bufferHold[sizeOfArray];

    //copies the original array into a new array, backwards
    for(int i = 0, j = sizeOfArray - 1; i < sizeOfArray; i++, j--){
        bufferHold[i] = A[j];
    }
    
    //copies the now backwards array back into the original
    for(int i = 0; i < sizeOfArray; i++){
        A[i] = bufferHold[i];
    }
}

/*
    parseSentense: tokenizes a sentence and prints each word individually
    input: a null terminating string (S)
*/
void parseSentence(char *S){
    
    char *strTokenPtr;
    char strCopy[strlen(S)];
    
    strcpy(strCopy, S); //creates a copy of data to avoid data destruction
    
    //loops until NULL terminating char is found. Tokenize each word until then
    strTokenPtr = strtok(strCopy, " ,;.");
    while(strTokenPtr != NULL){
        printf("%s\n", strTokenPtr);
        strTokenPtr = strtok(NULL, " ,;.");
    }
}
