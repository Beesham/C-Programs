/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/17
	Description: performs string manipulation operations such as tokenization and reversal
*/
#include <stdio.h>

int main(void){
    
    char buffer1[] = {'t', 'h', 'i', 's', ' ',
                      'i','s', ' ',
                      't', 'h', 'e', ' ',
                      'f', 'i', 'r', 's', 't', ' ',
                      'b', 'u', 'f', 'f', 'e', 'r',
                      '\0'};
    char buffer2[] = "this is the second buffer";
    char buffer3[80];
    
    printf("%s", "Please enter a string: ");
    //scanf("%s", buffer3);   //only reads in a single word. To read a whole line fgets should be used
    fgets(buffer3, 80, stdin);
    
    printf("%s %s\n%s %s\n%s %s\n", "buffer1:", buffer1, "buffer2:", buffer2, "buffer3:", buffer3);
    
    char *pBuffer = buffer3;
    
    puts(pBuffer);
    
    pBuffer++;
    pBuffer++;
    pBuffer++;

    puts(pBuffer);

    return 0;
}