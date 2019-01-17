//Coded By:                ***** *****
//***#:                    **********
//Date:                    2018-10-29
//Description:             This program takes in an integer which specifies a
//                         length of a sequence. It then takes in a sequence of
//                         doubles of that length. Once stored, the array is
//                         sorted and the average and median of the sequence
//                         are returned to the user.

#include<stdio.h>

//Functions to be used in sorting
void mergesort(double array[], int lower, int upper);
void merge(double array[], int lower, int middle, int upper);


//main method to take in numbers and find the average and median
int main() {
  
  //the count is the number of numbers in a sequence
  int count;
  //the input is a given number input into a sequence
  double input;
  
  //boolean value to keep the program looping
  int looping = 1;

  //main program loop
  while (looping == 1) {

    //get size of this sequence
    scanf("%d", &count); 
  
    //checks to see if an exit number was entered for count
    if (count < 1) {

      looping = 0;
      break;

    }

    //create the array that will hold the sequence
    double line[count];

    //take input and put it into the array
    for (int i = 0; i < count; i++) {
 
      scanf("%lf", &input);
    
      line[i] = input;

    }
    
    //sort the array
    mergesort(line, 0, count -1);
    
    //a variable to help calculate average
    double sum = 0;
    
    //take the sum
    for (int i = 0; i < count; i++) {

      sum = sum + line[i];

    }
    
    //calculate the average
    double average = sum / count;
    
    //variable to store the median
    double median = 0;

    //if there is an even number of numbers in the sequence
    if (count % 2 == 0) {
      
      //formula for calculating median with even number
      median = (line[(count - 1)/2] + line[count/2]) / 2;

      //if there are an odd number of numbers in the seqence
    } else {

      //formula for calculating median with odd number
      median = (line[count/2]);

    }
    
    //print the average and median to 3 decimal places
    printf("Avg: %.3lf Med: %.3lf\n", average, median);

  }

  return 0;

}

//merge sort method. 
//recursively runs itself and also runs merge
void mergesort(double array[], int lower, int upper) {

  //merge sort is called recursively so this check is run to make sure no
  //invalid conditions are entered that would cause an error.
  if (lower < upper) {

    //this variable will be initialized to half way between lower and upper
    //when mergesort is started with a starting value of
    //mergesort(array[], 0, max);
    int middle = (lower + upper) / 2;
    //This is a recursive call of mergesort on the lower half of the array
    //the middle variable has been entered as the upper limit
    mergesort(array, lower, middle);
    //This is a recursive call of mergesort on the upper half of the array
    //the 1 above the middle variable has been entered as the lower limit
    mergesort(array, middle+1, upper);
    //run the merge method 
    merge(array, lower, middle, upper);

  }

}

//
void merge(double array[], int lower, int middle, int upper) {

  //length of the lower half of the array
  int length_left = middle - lower + 1;
  //length of the upper half of the array
  int length_right = upper - middle;
  //create sub arrays for the left and right sides
  double left[length_left], right[length_right];
  //a few integers of index counters
  int i, j, k;
  
  //this for loop populates the left array
  for (i = 0, j = lower; i < length_left; i++, j++) {

    left[i] = array[j];

  }

  //this for loop populates the right array
  for (i = 0, j = middle + 1; i < length_right; i++, j++) {

    right[i] = array[j];

  }

  //reset i and j
  i = j = 0; 
  //set k to lower
  k = lower;

  //sorts the left are right arrays into one array
  while (i < length_left && j < length_right) {
    
    //if the number in the left array is smaller, put it in the new array
    if (left[i] <= right[j]) {

      array[k++] = left[i++];

      //otherwise put the number from the right array in the new array
    } else {

      array[k++] = right[j++];

    }

  }

  //add the rest of the left array if there is any
  while (i < length_left) {

    array[k++] = left[i++];

  }
  
  //add the rest of the right array if there is any
  while (j < length_right) {

    array[k++] = right[j++];

  }

}
