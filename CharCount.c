//Coded by:               ***** *****
//***#:                   **********
//Date:                   2018-10-29
//Description:            This program takes text input and returns each line
//                        of text with a count of the number of characters in
//                        the line.            

#include <stdio.h>
int main()
{

  //number of letters in a line of input
  int count;
  //the current character being accessed by the getchar() method
  int character;

  //First: this assigns the character variable its first value.
  //Second: it checks after each line to make sure we have not reached the end
  // of the file.
  while ((character = getchar()) != EOF) {
    
    //reset count to 0 in every new line
    count = 0;
    
    //this loop runs once per line.
    //it's condition is, while the character being examined is not a new line
    //character or an end of line
    //This loop is responsible for counting the number of characters in a line
    //and printing most of our output
    //It also increments the current character
    while ((character != '\n') && (character != EOF)) {
      //we increase the count by 1
      count++;
      //we use putchar for out output at this stage
      putchar(character);
      //we increment the character variable to the next index
      character = getchar();
    }

    //finally we print the colon and the count followed by a new line
    printf(":%d\n", count);
  
  }

  return 0;

}
