/*
  Author: Beesham Sarendranauth, 104854956
  Date: 2017/07/03
  Description: performs non-recursive operations such as factorials
   and fibonnacci sequence.
   The operations are selected from a menu presented to
   the user.
*/
#include <stdio.h>
#include <stdlib.h>

//Function prototypes
void summation();
void factorial();
void fibonacci();
void gcd();
void power();


int main(void){
  
  int selection;
    
  while(selection != EOF){ 
    
    puts("*************");
    puts("*   Menu    *");
    puts("*************");
    puts("1. Summation");
    puts("2. Factorial");
    puts("3. Fibonacci");
    puts("4. GCD");
    puts("5. Power");

    puts("");
    puts("Please select the number index of your operation e.g 1. \nEnter -1 to quit");
    printf("%s","Input:");
    scanf("%d", &selection);

  
    switch(selection){
      case 1:
      break;
      
      case 2:
      break;
      
      case 3:
      break;
      
      case 4:
      break;
      
      case 5:
      break;
                
      default:
          puts("ERROR: selection must be from the menu shown");
    }
        
    getchar();  //Clears the input buffer
  }
  
}

/*
  Objective:
  Input:
  Output:
*/
void summation(){

}

/*
  Objective:
  Input:
  Output:
*/
void factorial(){
  
}

/*
  Objective:
  Input:
  Output:
*/
void fibonacci(){
  
}

/*
  Objective:
  Input:
  Output:
*/
void gcd(){
  
}

/*
  Objective:
  Input:
  Output:
*/
void power(){

}
