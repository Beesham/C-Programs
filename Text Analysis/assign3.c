/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/19
	Description: This program analyses text. It determines how many times words are used,
    letter repetition, and word length repetition
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20

//prototypes
void letterAnalysis(char **bufferPtr, int numOfLines);
int wordLengthAnalysis(char **bufferPtr, int numOfLines, int length);
void wordAnalysis(char **bufferPtr, int numOfLines);
unsigned long getText(char **bufferPtr);

//TODO: write cleanup function to free malloc

int main(void){
    char *bufferPtr[MAX_LINES];// = {"This is line: 1", "This is line: 2"};
    unsigned int numOfLines = 2;
    unsigned int numOfWords = 0;
    numOfLines = getText(bufferPtr);
    
    letterAnalysis(bufferPtr, numOfLines);
    wordAnalysis(bufferPtr, numOfLines);
    
    numOfWords = wordLengthAnalysis(bufferPtr, numOfLines, 2);
    const char *singleWord = "word";
    const char *pluralWord = "words";
    if(numOfWords <= 1){
        printf("%3d %s %s %d", numOfWords, singleWord, "of length", 2);
    }
    else{
        printf("%3d %s %s %d", numOfWords, pluralWord, "of length", 2);
    }
}

/*
    letterAnalysis: analyses the number of occurences of each letter in the text
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines)
*/
void letterAnalysis(char **bufferPtr, int numOfLines){
    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    char copy[MAX_LINES * MAX_LINE_LENGTH];
    
    strcpy(copy, bufferPtr[0]); //copies first string in the buffer for subsequent concatenation
   
               printf("%s", copy);

    //concatenates all the strings together 
    for(unsigned int i = 1; i < numOfLines; i++){
        strcat(copy, bufferPtr[i]);
    }
    
    //converts all convertable characters to lowercase
    for(unsigned int j = 0; (copy[j]) != '\0'; j++){
        if(isalpha((copy[j]))){
            (copy[j]) = tolower((copy[j]));
        }
    }

    //searches for occurances of letters
    for(unsigned int j = 0; alphabet[j] != '\0'; j++){ 
        int count = 0;
        char *str = strchr(copy, alphabet[j]);;
        while(str != NULL){
            count++;
            str = strchr(str+1, alphabet[j]);
        }
        
        if(j % 5 == 0) puts("");
        printf("%c : %3d   ", alphabet[j], count);
    }
}

/*
    wordLengthAnalysis: analyses the amount of words that are of a certain length
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines), the lenght of a word to look for (length)
    output: the amount of words (count) found having the specified length 
*/
int wordLengthAnalysis(char **bufferPtr, int numOfLines, int length){
    char copy[MAX_LINES * MAX_LINE_LENGTH];
    
    strcpy(copy, bufferPtr[0]); //copies first string in the buffer for subsequent concatenation
   
    //concatenates all the strings together 
    for(unsigned int i = 1; i < numOfLines; i++){
        strcat(copy, bufferPtr[i]);
    }
    
    char *strTokenPtr;
    int count = 0;
    
    strTokenPtr = strtok(copy, " :',?.!()’"); //to get curly single quote hold alt + 0146 (num lock must be on)
    while(strTokenPtr != NULL){
        if(strlen(strTokenPtr) == length){
            count++;
        }
        strTokenPtr = strtok(NULL, " :',?.!()’");
    }
    
    return count;
}

/*
    wordAnalysis: 
*/
void wordAnalysis(char **bufferPtr, int numOfLines){
    char copy[MAX_LINES * MAX_LINE_LENGTH];
    strcpy(copy, bufferPtr[0]); //copies first string in the buffer for subsequent concatenation
   
    //concatenates all the strings together 
    for(unsigned int i = 1; i < numOfLines; i++){
        strcat(copy, bufferPtr[i]);
    }
    
    printf("\n%s\n\n", copy);

    char copy2[MAX_LINES * MAX_LINE_LENGTH];
    strcpy(copy2, copy); 
    
    int count = 0;
    char *strTokenPtr;
    strTokenPtr = strtok(copy2, " \r"); 
    while(strTokenPtr != NULL){
        count++;
        strTokenPtr = strtok(NULL, " \r");
    }
    
    strcpy(copy2, copy); 
    char wordArray2D[count][MAX_WORD_LENGTH];
    
    strTokenPtr = strtok(copy2, " \r"); 
    count = 0;
    while(strTokenPtr != NULL){
        strcpy(wordArray2D[count++], strTokenPtr);
        //printf("\n%s\n", wordArray2D[count-1]);
        strTokenPtr = strtok(NULL, " \r");
    }
    
    strcpy(copy2, copy); 

    char *copy2Ptr = copy;
    
    int newCount = 0;
    for(int i = 0; i < count; i++){
        //printf("\n%s\n", wordArray2D[i]);
        for(int j = 0; j < count; j++){
            if(!strcmp(wordArray2D[i], wordArray2D[j])){
                newCount++;
            }
        }
         
        printf("\n%s: %d\n", wordArray2D[i], newCount);
        newCount = 0;
    }
    
    
    /*
    char *strTokenPtr;
    char *copy2Ptr = copy2;
    char *copyPtr = copy;
    int count = 0;
    
    
    strTokenPtr = strtok(copy2, " "); 
    //printf("strTokenPtr: %s %p\n", strTokenPtr, strTokenPtr);
    //printf("copy: %s %p\n", copy, copy);

    char *strFoundPtr;

    
    while(strTokenPtr != NULL){
        printf("%s\n", strTokenPtr);
        printf("looking for %s in %s\n", strTokenPtr, copyPtr);
        strFoundPtr = strstr(copyPtr, strTokenPtr);
        if(strFoundPtr != NULL) printf("outer while strPtr: %s %p\n", strFoundPtr, strFoundPtr);

        
        while(strFoundPtr != NULL){
            if(!strcmp(strTokenPtr, strFoundPtr)){
                count++;
            }
            
            
            //printf("1. strPtr inner while: %s %p\n", strPtr, strPtr);
            //printf("before temp copy2 inner while: %s %p\n", copy2Ptr, copy2Ptr);

            char *temp = copyPtr + (strlen(strFoundPtr) + 1);
            copyPtr = temp;
            //printf("after temp copy2 inner while: %s %p\n", copy2Ptr, copy2Ptr);
            strFoundPtr = strstr(temp, strTokenPtr);
            //printf("2. copy inner while: %s %p\n", temp, temp);
            //printf("3. strPtr inner while: %s %p\n", strPtr, strPtr);
            //if(strFoundPtr == NULL) printf("strPtr is NULL, meaning there is no more occurrences");
            
        }
        
        printf("%d\n", count);
        //copyPtr = &copy[0];
        count = 0;
        strTokenPtr = strtok(NULL, " ");
    }
    */
    
}

/*
    getText: reads N amount of text input from the user
    input: the string array the text is to be stored in (bufferPtr)
    output: the number of lines to be analysed
*/
unsigned long getText(char **bufferPtr){
    char input[3];
    unsigned long numOfLines = 0;
    
    printf("%s", "How many lines of text do you want to analyse: ");
    fgets(input, 3, stdin);
        
    numOfLines = strtol(input, NULL, 10);
    getchar();
    
    if (!numOfLines){
        puts("Invalid input! Exiting...");
        getchar();
    }
    else{
        for(unsigned int i = 0; i < numOfLines; i++){
            bufferPtr[i] = malloc(sizeof(char) *  MAX_LINE_LENGTH);  //allocates memory for each string in the array, ch12.2
            fgets(bufferPtr[i], MAX_LINE_LENGTH, stdin);
        }
    }
    
    return numOfLines;
}