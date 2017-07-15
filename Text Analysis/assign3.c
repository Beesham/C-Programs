/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/19
	Description: This program analyses text. It determines how many times words are used,
    letter repetition, and word length repetition
    
    *Note: if inputting from a file, the first line must have the number of lines to be analysed + 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20

//prototypes
void letterAnalysis(const char **bufferPtr, int numOfLines);
int wordLengthAnalysis(const char **bufferPtr, int numOfLines, int length);
void wordAnalysis(const char **bufferPtr, int numOfLines);
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
void letterAnalysis(const char **bufferPtr, int numOfLines){
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
int wordLengthAnalysis(const char **bufferPtr, int numOfLines, int length){
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
void wordAnalysis(const char **bufferPtr, int numOfLines){
    char copy[MAX_LINES * MAX_LINE_LENGTH];
    strcpy(copy, bufferPtr[0]); //copies first string in the buffer for subsequent concatenation
   
    //concatenates all the strings together 
    for(unsigned int i = 1; i < numOfLines; i++){
        strcat(copy, bufferPtr[i]);
    }
    
    char *strTokenPtr;
    char *strPtr;
    int count = 0;
    
    
    strTokenPtr = strtok(copy, " "); 
    
    while(strTokenPtr != NULL){
        printf("%s ", strTokenPtr);
        
        strPtr = strstr(copy, strTokenPtr);
        printf("%s ", strPtr);

        
        while(strPtr != NULL){
            if(!strcmp(strTokenPtr, strPtr)){
                count++;
            }
            strPtr = strstr(strPtr + strlen(strPtr) + 1, strTokenPtr);
            //printf("%s ", strPtr);
        }
        
                printf("%d\n", count);

        strTokenPtr = strtok(NULL, " ");
    }
    
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
    //scanf("%s", input);
    fgets(input, 3, stdin);
    //input[2] = '\0';
        
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