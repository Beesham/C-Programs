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

//prototypes
void letterAnalysis(const char **bufferPtr, int numOfLines);
int wordLengthAnalysis(const char **bufferPtr, int numOfLines, int lenght);
void wordAnalysis(const char **bufferPtr, int numOfLines);
unsigned long getText(char **bufferPtr);

//TODO: write cleanup function to free malloc

int main(void){
    char *bufferPtr[MAX_LINES];// = {"This is line: 1", "This is line: 2"};
    unsigned int numOfLines = 2;
    numOfLines = getText(bufferPtr);
    
    //letterAnalysis(bufferPtr, numOfLines);
}

/*
    letterAnalysis: analyses the number of occurences of each letter in the text
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines)
*/
void letterAnalysis(const char **bufferPtr, int numOfLines){
    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    char *copy[MAX_LINE];
    
    for(unsigned int i = 0; i < numOfLines; i++){
        bufferPtr[i] = malloc(sizeof(char) *  MAX_LINE_LENGTH);  //allocates memory for each string in the array, ch12.2

        for(unsigned int j = 0; (bufferPtr[i])[j] != '\0'; j++){
            //printf("%c",  (bufferPtr[i])[j]);
            char aChar = (bufferPtr[i])[j];
            if(isalpha(aChar)){
                aChar = tolower(aChar);
            }
            
            int count = 0;
            
            
            
            printf("%c %d",  aChar, count);
        }
    }
    
    
    for(unsigned int i = 0; i < numOfLines; i++){
        for(unsigned int j = 0; (bufferPtr[i])[j] != '\0'; j++){
            //printf("%c",  (bufferPtr[i])[j]);
            char aChar = (bufferPtr[i])[j];
            if(isalpha(aChar)){
                aChar = tolower(aChar);
            }
            
            int count = 0;
            
            
            
            printf("%c %d",  aChar, count);
        }
    }
    
    
}

/*

*/
int wordLengthAnalysis(const char **bufferPtr, int numOfLines, int lenght){
    
    return 0;
}

/*

*/
void wordAnalysis(const char **bufferPtr, int numOfLines){
    
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
    scanf("%s", input);
    input[2] = '\0';
        
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