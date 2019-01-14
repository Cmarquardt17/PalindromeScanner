#include <stdio.h>
#include <string.h>

#define size 20

/* Christian Marquardt
 * CSCI 112 Lab6
 * 10/26/2018
 * Description: We are getting the users input of a potential palindrome
 * We will continually ask until the user types in either "Stop" "stop" "STOP"
*/

//This will check to see if it is a palindrome or not
int check(char word[], int length, int size1, int iterator){

//Our index we will want for base case
int middle = (size1/2)-1;

  //Base case to check for middle letters
  if(word[iterator] == word[middle]){

    printf("This is a palindrome\n");
    return(1);
  }

  //See if each letter on opposing sides works
  if(word[iterator] == word[length-1]){

    //Function call calling the same function
    check(&word[iterator], length-1, size1, iterator+1);
  }

  else{

    //If its not a recursive call
    printf("This is not a palindrome\n");
  }

    //Returns regardless
    return(0);
  }

int main(){

  char palindrome[size];

  int rc1, rc2, rc3;

  //To check if we are done or not
  int concreteSize = 0;
  int done = 0;
  int editSize = 0;
  int iterator = 0;

  //char arrays that will test against the user input to see whether to kill the program
  char* string1 = "Stop";
  char* string2 = "STOP";
  char* string3 = "stop";

  //Will continue to read word then compare against the stops and if so will become one
  while(done != 1){

    printf("Please enter in a word to check if it's a palindrome: ");
    scanf("%s", palindrome);
    editSize = strlen(palindrome);

    //comparing all forms of stop
    rc1 = strncmp(string1, palindrome, 4);
    rc2 = strncmp(string2, palindrome, 4);
    rc3 = strncmp(string3, palindrome, 4);

    //After being compared we check to see if they are euqal to eachother
    if(rc1 == 0 || rc2 == 0 || rc3 == 0){

      //If so we will change done to 1 so we will be done
      done = 1;
      printf("Goodbye!\n");
      break;
    }
    //If not we will want to convert the word to a plural
    //Struggling to get the actual String in
    else{

      //We want our concrete size and a size we will edit
      concreteSize = editSize;

      //Function to find the palindrome using recursion
      check(palindrome, editSize, concreteSize, iterator);

    }
  }

  //To safely execute the function
  return(0);
}
