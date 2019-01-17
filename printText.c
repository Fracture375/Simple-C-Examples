//Coded By:              ***** *****
//***#:                  **********
//Date:                  2018-11-01
//Description            Reads a text file and prints each word on its own line

#include <stdio.h>

int main() {

  //keeps the program looping
  int state = 0;

  //hold the character being scanned
  char character = getchar();
  
  //while we have not reached the end of the file
  while (character != EOF) {
    
    //if the character being read if a letter
    if ((character >= 'a' && character <= 'z') || 
        (character >= 'A' && character <= 'Z')) {

      state = 1;
      
      //otherwise set the state to 0
    } else {
      
      //if the state was not previously 0, set a new line
      if (state != 0) {

	printf("\n");

      }

      state = 0;

    }
    
    //if the state is 0, do nothing
    if (state == 0) {


      //otherwise put down the character
    } else {

      putchar(character);

    }

    //get the next character for the next loop
    character = getchar();
  
  }

  return 0;
}
