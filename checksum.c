//Coded by:                     ***** *****
//***#:                         *********
//Date:                         2018-11-01

//Description:                  This program tests numbers against the Luhn 
//                              checksum. First enter the number of sequences
//                              you want to check between 1 and 100, then
//                              enter your sequences with new lines separating
//                              them.

#include <stdio.h>
#include <string.h>

//I'm defining it like this just because I haven't done it like this before
#define string_length 51

int main()
{

  //size of the test sample
  int T;

  //get the size of the test sample between 1 and 100
  scanf("%d", &T);

  //loop through the test sample
  for (int i = 0; i < T; i++) {

    //get the current input string
    char string[string_length];
    scanf("%s", string);
    
    //length to track the number of individual integers
    int length = 0;

    //loop counter
    int s = 0;

    //this loop counts the length of the current string
    //I tried doing without this loop but I just love knowing
    //the length of arrays and strings...
    while (( string[s] <= '9' ) && ( string[s] >= '0' )) {

      length++;
      s++;

    }

    //array that holds the processed numbers
    int numbers[length];

    //holds the sum when doing calculations
    int sum = 0;
    
    //a boolean for tracking if the index is an even number or not
    int even = 0;

    //for processing numbers. holds the digits of the number that was doubled
    //and became two digits. In a bit we are going to need to separate then
    //add those digits so this array will be handy.
    int transfer[3];

    //going from the right hand side of the string to the left hand side.
    //two different if statements inside for odd and even numbers
    for (int a = length - 1; a >= 0; a--) {

      //not an even number
      if (even == 0) {

	even = 1;
	numbers[a] = (string[a] - '0');

	//an even number
      } else {

	even = 0;
	numbers[a] = (string[a] - '0') *2;

	//if the number became 10 or larger after being multiplied by 2
	if (numbers[a] > 9) {

	  //get the number in question in a nice safe integer we can work with
	  int digits = numbers[a];

	  //this loop will grab each digit of digits using %10
	  //we know that two single digits added together can only make 18 at
	  //the biggest so we only have to loop twice.
	  for (int d = 0; d < 2; d++) {

	    //get one digit
	    int digit = digits % 10;
	    //put the digit in the transfer array
	    transfer[d] = digit;
	    //remove one digit
	    digits /= 10;

	  }

	  //add the sum of those two digits to the numbers array
	  numbers[a] = (transfer[0] + transfer[1]);

	}

      }

    }

    //sum the integer array.
    for (int c = 0; c < length; c++) {

      sum = sum + numbers[c];

    }

    //if the number is divisible by 10, we passed the test
    if (sum % 10 == 0) {

      printf("PASS\n");

      //otherwise we failed the test
    } else {

      printf("FAIL\n");

    }

  }

  return 0;

}
