/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/19
	Description: This program analyses text. It determines how many times words are used,
    letter repetition, and word length repetition
    *Note: reading from a file, the file must begin with the number of lines to be read then follwed in a
    new line the text. Reading more than 10 lines causes undefined behaviour (Seg. faults)
    
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20
#define MAX_SIZE_OF_INPUT 3

//prototypes
void letterAnalysis(char **bufferPtr, int numOfLines);
int wordLengthAnalysis(char **bufferPtr, int numOfLines, int length);
void wordAnalysis(char **bufferPtr, int numOfLines);
unsigned long getText(char **bufferPtr);
char* make1DArrayFrom2D(char *destination, char **source, int numOfLines);
void testWordLengthAnalysis(char **bufferPtr, int numOfLines, int wordLength);


int main(void){
    
    char *bufferPtr[MAX_LINES];
    unsigned int numOfLines = 0;
    
    numOfLines = getText(bufferPtr);
    
    if(numOfLines > 0){
        letterAnalysis(bufferPtr, numOfLines);
        puts("");

        testWordLengthAnalysis(bufferPtr, numOfLines, 1);
        testWordLengthAnalysis(bufferPtr, numOfLines, 2);
        testWordLengthAnalysis(bufferPtr, numOfLines, 3);
        testWordLengthAnalysis(bufferPtr, numOfLines, 4);
        testWordLengthAnalysis(bufferPtr, numOfLines, 6);
        testWordLengthAnalysis(bufferPtr, numOfLines, 7);
        testWordLengthAnalysis(bufferPtr, numOfLines, 8);
        testWordLengthAnalysis(bufferPtr, numOfLines, 9);
        testWordLengthAnalysis(bufferPtr, numOfLines, 10);

        wordAnalysis(bufferPtr, numOfLines);
            
        void cleanUp(char **bufferPtr, int numOfLines);
        cleanUp(bufferPtr, numOfLines);
    }
}

/*
    testWordLengthAnalysis: performs tests on the word length analysis function and prints the results
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines), the length of a word to look for (length)
*/
void testWordLengthAnalysis(char **bufferPtr, int numOfLines, int wordLength){
    
    unsigned int numOfWords = 0;

    numOfWords = wordLengthAnalysis(bufferPtr, numOfLines, wordLength);
    const char *singleWord = "word";
    const char *pluralWord = "words";
    if(numOfWords <= 1){
        printf("%3d %-5s %s %d\n", numOfWords, singleWord, "of length", wordLength);
    }
    else{
        printf("%3d %-5s %s %d\n", numOfWords, pluralWord, "of length", wordLength);
    }
}

/*
    make1DArrayFrom2D: creates a 1D string array from a 2D string array using concatenation
    input: an array to store the results in (destination), an array of text (source), the number of lines to be analysed (numOfLines)
    output: the 1D string array containing the data
*/
char* make1DArrayFrom2D(char *destination, char **source, int numOfLines){
    
    strcpy(destination, source[0]); //copies first string in the buffer for subsequent concatenation
   
    //concatenates all the strings together 
    for(unsigned int i = 1; i < numOfLines; i++){
        strcat(destination, source[i]);
    }
    
    return destination;
}

/*
    letterAnalysis: analyses the number of occurences of each letter in the text and prints the results
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines)
*/
void letterAnalysis(char **bufferPtr, int numOfLines){
    puts("");
    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    //makes a copy of the original data to avoid data destruction
    char copy[MAX_LINES * MAX_LINE_LENGTH];   
    make1DArrayFrom2D(copy, bufferPtr, numOfLines);

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
    
    puts("");
}

/*
    wordLengthAnalysis: analyses the amount of words that are of a certain length
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines), the length of a word to look for (length)
    output: the amount of words (count) found having the specified length 
*/
int wordLengthAnalysis(char **bufferPtr, int numOfLines, int length){
    
    //makes a copy of the original data to avoid data destruction
    char copy[MAX_LINES * MAX_LINE_LENGTH];
    make1DArrayFrom2D(copy, bufferPtr, numOfLines);
    
    char *strTokenPtr;
    int count = 0;
    
    strTokenPtr = strtok(copy, " \r\n"); //to get curly single quote hold alt + 0146 (num lock must be on)
    while(strTokenPtr != NULL){
        if(strlen(strTokenPtr) == length){
            count++;
        }
        strTokenPtr = strtok(NULL, " \r\n");
    }
    
    return count;
}

/*
    wordAnalysis: analyses the repetition of words in a given text and prints the results
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines)
*/
void wordAnalysis(char **bufferPtr, int numOfLines){
    puts("");
    
    //used for printing results
    const char *singleWord = "time";
    const char *pluralWord = "times";

    //makes a copy of the original data to avoid data destruction
    char copy[MAX_LINES * MAX_LINE_LENGTH];
    make1DArrayFrom2D(copy, bufferPtr, numOfLines);
        
    //creates a second copy of the data because strtok modifies it
    char copy2[MAX_LINES * MAX_LINE_LENGTH];
    strcpy(copy2, copy); 
    
    char *strTokenPtr;
    int wordCount = 0;
    
    //tokenizes the 1D string to count the words
    strTokenPtr = strtok(copy2, " \r\n"); 
    while(strTokenPtr != NULL){
        wordCount++;
        strTokenPtr = strtok(NULL, " \r\n");
    }
    
    //re-copies the data to re-use variable and use unmodified data
    strcpy(copy2, copy); 
    
    char wordArray2D[wordCount][MAX_WORD_LENGTH];
    
    //tokenizes and stores each word in a 2D word array
    strTokenPtr = strtok(copy2, " \r\n"); 
    int count = 0;
    while(strTokenPtr != NULL){
        strcpy(wordArray2D[count++], strTokenPtr);
        strTokenPtr = strtok(NULL, " \r\n");
    }
    
    strcpy(copy2, copy); 
    
    //looks for and compares words for recurring occurrences in the 2D array
    int occurrences = 0;
    for(int i = 0; i < wordCount; i++){
        for(int j = 0; j < wordCount; j++){
            if(!strcmp(wordArray2D[i], wordArray2D[j])){
                occurrences++;
            }
        }
         
        //printf("\n%s: %d\n", wordArray2D[i], occurrences);
        if(occurrences <= 1){
            printf("\"%s\" %*s %d %s\n", wordArray2D[i], 20 - (int) strlen(wordArray2D[i]), "appeared", occurrences, singleWord);
        }
        else{
            printf("\"%s\" %*s %d %s\n",  wordArray2D[i], 20 - (int) strlen(wordArray2D[i]), "appeared", occurrences, pluralWord);
        }
        occurrences = 0;
    }    
}

/*
    getText: reads N amount of text input from the user
    input: the string array the text is to be stored in (bufferPtr)
    output: the number of lines to be analysed
*/
unsigned long getText(char **bufferPtr){
    char input[MAX_SIZE_OF_INPUT];
    unsigned long numOfLines = 0;
    
    printf("%s", "How many lines of text do you want to analyse: ");
    fgets(input, MAX_SIZE_OF_INPUT, stdin);
    
    numOfLines = strtol(input, NULL, 10);
      
    if (!numOfLines){
        puts("Invalid input! Exiting...");
    }
    else if (numOfLines > MAX_LINES){
        puts("\nReading more than 10 lines is prohibited! Exiting...");
        numOfLines = 0;
    }
    else{
        printf("\n%s %lu %s\n", "Analysing", numOfLines, "lines of text\nPlease begin entering text");
                
        for(unsigned int i = 0; i < numOfLines; i++){
            bufferPtr[i] = malloc(sizeof(char) *  MAX_LINE_LENGTH);  //allocates memory for each string in the array, ch12.2
            fgets(bufferPtr[i], MAX_LINE_LENGTH, stdin);
        }
    }
    
    return numOfLines;
}

/*
    cleanUp: free the memory allocated using malloc
    input: an array of text (bufferPtr), the number of lines to be analysed (numOfLines)
*/
void cleanUp(char **bufferPtr, int numOfLines){
    if(bufferPtr != NULL){
        for(unsigned int i = 0; i < numOfLines; i++){
                free(bufferPtr[i]); //frees the allocated memory for each string in the array, ch12.2
        }
    }
}