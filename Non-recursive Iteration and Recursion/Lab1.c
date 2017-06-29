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
int summation(int);
int factorial(int);
void fibonacci();
void gcd();
void power();


int main(void){
  
  int selection;
  int input; //variable that holds user input
  int results; // variable that holds the result of the operation
    
  while(selection != EOF){ 
    
    puts("");
    puts("*************");
    puts("*   Menu    *");
    puts("*************");
    puts("1. Summation");
    puts("2. Factorial");
    puts("3. Fibonacci");
    puts("4. GCD");
    puts("5. Power");

    puts("");
    puts("Please select the number index of your operation e.g 1 \nEnter -1 to quit");
    printf("%s","Input: ");
    scanf("%d", &selection);

  
    switch(selection){
      case 1:{ 
        printf("%s", "Please enter a positive integer: ");
        scanf("%d", &input);
              
        if(input >= 1){
          int results = summation(input);
          printf("%s %d %s %d", "Summation of ", input, " is: ", results);
          getchar();  //waits for user to hit Enter to continue
        }else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
      break;
      
      case 2:{ 
        printf("%s", "Please enter a positive integer: ");
        scanf("%d", &input);
              
        if(input >= 0){
          int results = factorial(input);
          printf("%s %d %s %d", "Factorial of ", input, " is: ", results);
          getchar();  //waits for user to hit Enter to continue
        }else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
      break;
      
      case 3:
        fibonacci();
      break;
      
      case 4:
        gcd();
      break;
      
      case 5:
        power();
      break;
                
      default:
          puts("ERROR: selection must be from the menu shown");
    }
        
    getchar();  //waits for user to hit Enter to continue
  }
  
}

/*
  summation: adds each number sequence of a given positive integer up to itself e.g 4: 1 + 2 + 3 + 4 = 10
            and prints the result
  Input: a positive integer (n)
  Output: results
*/
int summation(int n){
  int results = 0;
  for(int i = 1; i <= n; ++i){
    results += i;
  }
  return results;
}

/*
  factorial: multiplies each number sequence of a given positive integer down to 1 e.g 4: 4 * 3 * 2 * 1 = 24
  Input: a positive integer (n)
  Output: results
*/
int factorial(int n){
  int results = 1;
  
  if(n == 0) return 0;
  
  for(int i = n; i > 1; i--){
    results *= i;
  }
  return results;
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
