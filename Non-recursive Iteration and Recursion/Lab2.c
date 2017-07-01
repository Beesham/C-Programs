/*
  Author: Beesham Sarendranauth, 104854956
  Date: 2017/07/03
  Description: performs recursive operations such as factorials
   and fibonacci sequence.
   The operations are selected from a menu presented to
   the user.
*/
#include <stdio.h>
#include <stdlib.h>

//Function prototypes
int prompt();
unsigned long long int summation(unsigned int);
unsigned long long int factorial(unsigned int);
unsigned long long int fibonacci(unsigned int);
int gcd(unsigned int, unsigned int);
unsigned long long int power(unsigned int, unsigned int);


int main(void){
  
  int selection;
  int input; //variable that holds user input
  int input2; //variable that holds user input
    
  while(selection != EOF){ 
    
    //displays a menu
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

    //switch statement to select appropriate operation
    switch(selection){
      case 1:{ 
        input = prompt();
        
        if(input >= 1){
          printf("%s %d %s %llu", "Summation of ", input, " is: ", summation(input));
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
          printf("%s %d %s %llu", "Factorial of ", input, " is: ", factorial(input));
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
          printf("%s %d %s %llu", "Fibonacci of ", input, " is: ", fibonacci(input));
          getchar();  //waits for user to hit Enter to continue
        }
        else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
      break;
      
      case 4:{ 
        input = prompt();
        input2 = prompt();
        
        if(input >= 0 && input2 >= 0){
          printf("%s%d %d %s%d", "GCD of ", input, input2, "is: ", gcd(input, input2));
          getchar();  //waits for user to hit Enter to continue
        }
        else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
      break;
      
      case 5:{ 
        input = prompt();
        input2 = prompt();
        
        if(input > 0 && input2 >= 0){
          printf("%s%d %d %s%llu", "Power of ", input, input2, "is: ", power(input, input2));
          getchar();  //waits for user to hit Enter to continue
        }
        else{
          puts("Invalid input!");
          getchar();  //waits for user to hit Enter to continue
        }
      }
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
unsigned long long int summation(unsigned int n){
    unsigned long long int results = 0;
    //base case
    if(n == 1){
        results = 1;
    }
    else{
        results = summation(n - 1) + n; //recursive call
    }
    return results;
}

/*
  factorial: multiplies each number sequence of a given positive integer down to 1 e.g 4: 4 * 3 * 2 * 1 = 24
  Input: a positive integer (n)
  Output: results
*/
unsigned long long int factorial(unsigned int n){
  int results = 1;
  
  //base case
  if(n == 0) return 1;
  results = n * factorial(n - 1); //recursive call
  return results;
}

/*
  fibonacci: generates the fibonacci sequence for a positive integer e.g 4: fibonacci(10) = 55
             starting sequence number is chosen to be 1.
  Input: a positive integer (n) where n is the number of sequences
  Output: results
*/
unsigned long long int fibonacci(unsigned int n){
  int results = 1;  //we initialize results to 1 because our seq. starts at 1
    
  //tests base cases as the fib. seq. of 0 is 0 and 1 is 1
  if(n == 0 || n == 1){
      return n;
  } 
  else{
      results = fibonacci(n - 1) + fibonacci(n - 2);  //recursive call
  }
  return results;
}

/*
  gcd: calculates the greatest common divisor of 2 given positive integer
  Input: 2 positive integers: x, y
  Output: result (the gcd of the 2 integers)
*/
int gcd(unsigned int x, unsigned int y){
    int results = 1;  //results is init. to 1 because all numbers have 1 as a divisor except 0
    
    if(y == 0) return x;  //base case
    results = gcd(y, x % y);  //recursive call
   
    return results;
}

/*
  power: calculates the power of a given integer but a given integer
  Input: 2 integers; a,b where a is powered by b
  Output: results (the power of a by b)
*/
unsigned long long int power(unsigned int a, unsigned int b){
    int results = 1; //results init. to 1 because 1^n is still 1
    
    if(b == 0) return 1; //base case
    results = power(a, b - 1) * a; //recursive call
    
    return results;
}
