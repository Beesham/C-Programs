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
int prompt();
int summation(int);
int factorial(int);
int fibonacci(int);
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
        input = prompt();
              
        if(input >= 1){
          int results = summation(input);
          printf("%s %d %s %d", "Summation of ", input, " is: ", results);
          getchar();  //waits for user to hit Enter to continue
        }
        else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
      break;
      
      case 2:{ 
        input = prompt();
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
      
      case 3:{ 
        input = prompt();
        if(input >= 0){
          int results = fibonacci(input);
          printf("%s %d %s %d", "Fibonacci of ", input, " is: ", results);
          getchar();  //waits for user to hit Enter to continue
        }
        else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
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
  summation: adds each number sequence of a given positive integer up to itself e.g 4: 1 + 2 + 3 + 4 = 10
            and prints the result
  Input: a positive integer (n)
  Output: results
*/
int summation(int n){
  int results = 0;
  for(unsigned int i = 1; i <= n; ++i){
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
  
  for(unsigned int i = n; i > 1; i--){
    results *= i;
  }
  return results;
}

/*
  fibonacci: generates the fibonacci sequence for a positive integer ege 4: fibonacci(10) = 55
             starting sequence number is chosen to be 1.
  Input: a positive integer (n) where n is the number of sequences
  Output: results
*/
int fibonacci(int n){
  int results = 1;  //we initialize results to 1 because our seq. starts at 1
  
  int prev = 1, pprev = 1;  //var prev is the previous num in the sequence and is seeded with 1
                            //var pprev is the 2nd previous num in the sequence and is seeded with 1
  
  if(n == 0 || n == 1) return n;  //tests base cases as the fib. seq. of 0 is 0 and 1 is 1
  
  //Iteratively calculates the fib. seq. of the input number
  for (int i = 1; i <= n; i++){
    //we already know the first 2 position results of the seq. is 1 and 1, so we just need to calc. from the 3rd position
    if(i >= 3){
        results = (prev) + (pprev);
        pprev = prev;
        prev = results;
    }
  }
  return results;
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
