/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/19
	Description: This program analyses text. It determines how many times words are used,
    letter repetition, and word length repetition
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 80

//prototypes
void letterAnalysis(const char **bufferPtr, int numOfLines);
int wordLengthAnalysis(const char **bufferPtr, int numOfLines, int lenght);
void wordAnalysis(const char **bufferPtr, int numOfLines);
int getText(char **bufferPtr);

int main(void){
    char *bufferPtr[MAX_LINES];
    unsigned int numOfLines;
    numOfLines = getText(bufferPtr);
    puts(bufferPtr[1]);
}

/*

*/
void letterAnalysis(const char **bufferPtr, int numOfLines){
    
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
int getText(char **bufferPtr){
    char s[MAX_LINE_LENGTH];
    int numOfLines;
    
    printf("%s", "How many lines of text do you want to analyse: ");
    scanf("%2d", &numOfLines);
        
    getchar();
    
    //TODO: validate input
    
    for(int i = 0; i < numOfLines; i++){
        bufferPtr[i] = fgets(s, MAX_LINE_LENGTH, stdin);
        //puts(bufferPtr[i]);
    }
    
    return numOfLines;
}