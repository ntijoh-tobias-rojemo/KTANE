#include "global.h"

int determineInitialValue() {
  static int initialValue = 0;

  /* Servo sequence */
  static int numberOfEven = 0;
  static int numberOfOdd = 0;
  static int numberOfPrimes = 0;
  static bool noneBelow5 = true;
  for (int i = 0; i < servoLoopLength; i++) {
    if (KTANE::servoLoop[i]%2 == 0) {
      numberOfEven++;
    }
    else {
      numberOfOdd++;
    }
    if (KTANE::servoLoop[i] == 2 || KTANE::servoLoop[i] == 3 || KTANE::servoLoop[i] == 5 || KTANE::servoLoop[i] == 7) {
      numberOfPrimes++;
    }
    if (KTANE::servoLoop[i] < 5) {
      noneBelow5 = false;
    }
  }
  
  /* left RGB */


  /* Right RGB */

  // Green is present twice in both LED sequences
  if (false) {
    // 0
  }
  // The servo sequence contains exclusively even numbers
  else if (false) {
    initialValue += 100;
  }
  // The last number in the servo sequence is either a 4, 6, or 9
  else if (KTANE::servoLoop[KTANE::servoLoopLength-1] == 4 || KTANE::servoLoop[KTANE::servoLoopLength-1] == 6 || KTANE::servoLoop[KTANE::servoLoopLength-1] == 9) {
    initialValue += 200;
  }
  // Both orange and pink are present in the same RGB sequence
  else if (false) {
    initialValue += 300;
  }
  // The servo sequence contains exactly 1 prime number
  else if (numberOfPrimes == 1) {
    initialValue += 400;
  }
  // Both RGB sequences are identical
  else if (false) {
    initialValue += 500;
  }
  // The servo sequence contains at least 2 prime numbers
  else if (numberOfPrimes >= 2) {
    initialValue += 600;
  }
  // The second number in the servo sequence is either a 1 or a 6
  else if (KTANE::servoLoop[1] == 1 || KTANE::servoLoop[1] == 6) {
    initialValue += 700;
  }
  // The length of the servo sequence is an odd number
  else if (false) {
    initialValue += 800;
  }
  // None of the above
  else {
    initialValue += 900;
  }

  // Both LED sequences are the same length
  if (false) {
    // 0
  }
  // The servo sequence is at least 7 digits long
  else if (false) {
    initialValue += 10;
  }
  // The servo sequence contains no numbers smaller than 5
  else if (false) {
    initialValue += 20;
  }
  // The servo sequence is the same length as either of the RGB sequences
  else if (false) {
    initialValue += 30;
  }
  // The length of the servo sequence is a prime number
  else if (false) {
    initialValue += 40;
  }
  // The servo sequence contains only one even number
  else if (false) {
    initialValue += 50;
  }
  // Blue is present in either of the RGB sequences
  else if (false) {
    initialValue += 60;
  }
  // No colour in the RGB sequence is repeated
  else if (false) {
    initialValue += 70;
  }
  // The RGB sequence contains all six colours
  else if (false) {
    initialValue += 80;
  }
  // None of the above
  else {
    initialValue += 90;
  }

  // The third number in the servo sequence is either a 5 or a 7
  if (false) {
    // 0
  }
  // Blue and purple are both present in the same RGB sequence after one another
  else if (false) {
    initialValue += 1;
  }
  // In the servo sequence, there is a sequence of 3 numbers where each number is 1 smaller than the previous number
  else if (false) {
    initialValue += 2;
  }
  // The servo sequence contains no prime numbers
  else if (false) {
    initialValue += 3;
  }
  // Purple is present in both RGB sequences
  else if (false) {
    initialValue += 4;
  }
  // The RGB sequences share exactly 2 colours
  else if (false) {
    initialValue += 5;
  }
  // The length of the servo sequence is an even number
  else if (false) {
    initialValue += 6;
  }
  // The fifth number in the servo sequence is either a 3, 6, 7, or a 8
  else if (false) {
    initialValue += 7;
  }
  // Red is present in either of the RGB sequences
  else if (false) {
    initialValue += 8;
  }
  // None of the above
  else {
    initialValue += 9;
  }
  return initialValue;
}