/*
  Author: Beesham Sarendranauth, 104854956
  Date: 2017/07/03
  Description: performs non-recursive operations such as factorials
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
    puts("Please select the number index of your operation e.g 1 \nEnter -1 to quit (ERROR prints upon exit)");
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
unsigned long long int factorial(unsigned int n){
  int results = 1;
  
  if(n == 0) return 1;
  
  for(unsigned int i = n; i > 1; i--){
    results *= i;
  }
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
  gcd: calculates the greatest common divisor of 2 given positive integer
  Input: 2 positive integers: x, y
  Output: result (the gcd of the 2 integers)
*/
int gcd(unsigned int x, unsigned int y){
    int results = 1;  //results is init. to 1 because all numbers have 1 as a divisor except 0
    int max;  //the max num of the 2 integers
    
    if(y == 0) return x;  //base case
    
    max = x > y ? x : y;  //calculates the max of the 2 integers
    
    //determines the GCD of the 2 integers by looping through the count of the max 
    for(unsigned int i = 1; i <= max; i++){
        //if the x or y MOD i == 0, then the GCD is the count. ie. i
        if((x % i == 0) && (y % i == 0)){
            results = i;
        }
    }
   
    return results;
}

/*
  power: calcualtes the power of a given integer but a given integer
  Input: 2 integers; a,b where a is powered by b
  Output: results (the power of a by b)
*/
unsigned long long int power(unsigned int a, unsigned int b){
    unsigned long long int results = 1; //results init. to 1 because 1^n is still 1
    
    //determines the results of a^b by iteration
    for(unsigned int i = 0; i < b; i++){
        results *= a;
    }
    
    return results;
}
