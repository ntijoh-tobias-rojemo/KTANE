// The value
static int theValue = 0;

void determineInitialValue() {
  /* Servo */
  static int numberOfEven = 0;
  static int numberOfOdd = 0;
  static int numberOfPrimes = 0;
  static bool noneBelow5 = true;
  static bool noneAbove6 = true;
  for (int i = 0; i < servoLoopLength; i++) {
    if (servoLoop[i] % 2 == 0) {
      numberOfEven++;
    } else {
      numberOfOdd++;
    }
    if (servoLoop[i] == 2 || servoLoop[i] == 3 || servoLoop[i] == 5 || servoLoop[i] == 7) {
      numberOfPrimes++;
    }
    if (servoLoop[i] < 5) {
      noneBelow5 = false;
    } else if (servoLoop[i] > 6) {
      noneAbove6 = false;
    }
  }

  /* RGBs */
  static bool identical = true;
  static bool noRepeats = true;
  static bool colourIsPresentInLeft[6] = {false};
  static bool colourIsPresentInRight[6] = {false};
  static bool colourIsPresent[6] = {false};
  static bool blueAndPurple = false;
  static int sharedColours = 0;
  for (int i = 0; i < 7; i++) {
    if (leftRGBLoop[i] != rightRGBLoop[i]) {
      identical = false;
    }
    if (leftRGBLoop[i] != -1) {
      colourIsPresentInLeft[leftRGBLoop[i]] = true;
      if (leftRGBLoop[i] == 2) {
        if (leftRGBLoop[(i - 1 + leftRGBLoopLength) % leftRGBLoopLength] == 4 || leftRGBLoop[(i + 1) % leftRGBLoopLength] == 4) {
          blueAndPurple = true;
        }
      } else if (leftRGBLoop[i] == 4) {
        if (leftRGBLoop[(i - 1 + leftRGBLoopLength) % leftRGBLoopLength] == 2 || leftRGBLoop[(i + 1) % leftRGBLoopLength] == 2) {
          blueAndPurple = true;
        }
      }
    }
    if (rightRGBLoop[i] != -1) {
      colourIsPresentInRight[rightRGBLoop[i]] = true;
      if (rightRGBLoop[i] == 2) {
        if (rightRGBLoop[(i - 1 + rightRGBLoopLength) % rightRGBLoopLength] == 4 || rightRGBLoop[(i + 1) % rightRGBLoopLength] == 4) {
          blueAndPurple = true;
        }
      } else if (rightRGBLoop[i] == 4) {
        if (rightRGBLoop[(i - 1 + rightRGBLoopLength) % rightRGBLoopLength] == 2 || rightRGBLoop[(i + 1) % rightRGBLoopLength] == 2) {
          blueAndPurple = true;
        }
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    if (occurancesInArray(leftRGBLoop, i, leftRGBLoopLength) > 1) {
      noRepeats = false;
    }
    if (occurancesInArray(rightRGBLoop, i, rightRGBLoopLength) > 1) {
      noRepeats = false;
    }
    if (colourIsPresentInLeft[i] || colourIsPresentInRight[i]) {
      colourIsPresent[i] = true;
    }
    if (colourIsPresentInLeft[i] && colourIsPresentInRight[i]) {
      sharedColours++;
    }
  }

  if (leftRGBFreq[1] >= 2 && rightRGBFreq[1] >= 2) {
    // Green is present twice in both LED sequences
    // 0
  } else if (numberOfOdd == 0) {
    // The servo sequence contains exclusively even numbers
    theValue += 100;
  } else if (servoLoop[servoLoopLength - 1] == 4 || servoLoop[servoLoopLength - 1] == 6 || servoLoop[servoLoopLength - 1] == 9) {
    // The last number in the servo sequence is either a 4, 6, or 9
    theValue += 200;
  } else if ((leftRGBFreq[3] > 0 && leftRGBFreq[5] > 0) || (rightRGBFreq[3] > 0 && rightRGBFreq[5] > 0)) {
    // Both cyan and white are present in the same RGB sequence
    theValue += 300;
  } else if (numberOfPrimes == 1) {
    // The servo sequence contains exactly 1 prime number
    theValue += 400;
  } else if (identical) {
    // Both RGB sequences are identical
    theValue += 500;
  } else if (numberOfPrimes >= 2) {
    // The servo sequence contains at least 2 prime numbers
    theValue += 600;
  } else if (servoLoop[1] == 1 || servoLoop[1] == 6) {
    // The second number in the servo sequence is either a 1 or a 6
    theValue += 700;
  } else if (servoLoopLength % 2 == 1) {
    // The length of the servo sequence is an odd number
    theValue += 800;
  } else {
    // None of the above
    theValue += 900;
  }

  if (leftRGBLoopLength == rightRGBLoopLength) {
    // Both LED sequences are the same length
    // 0
  } else if (servoLoopLength >= 7) {
    // The servo sequence is at least 7 digits long
    theValue += 10;
  } else if (noneBelow5) {
    // The servo sequence contains no numbers smaller than 5
    theValue += 20;
  } else if (servoLoopLength == leftRGBLoopLength || servoLoopLength == rightRGBLoopLength) {
    // The servo sequence is the same length as either of the RGB sequences
    theValue += 30;
  } else if (servoLoopLength == 3 || servoLoopLength == 5 || servoLoopLength == 7) {
    // The length of the servo sequence is a prime number (length is between 3 and 10 so no need to check if it's 2)
    theValue += 40;
  } else if (numberOfEven == 1) {
    // The servo sequence contains only one even number
    theValue += 50;
  } else if (leftRGBFreq[2] > 0 || rightRGBFreq[2] > 0) {
    // Blue is present in either of the RGB sequences
    theValue += 60;
  } else if (noRepeats) {
    // No colour in an RGB sequence is repeated in that sequence
    theValue += 70;
  } else if (colourIsPresent[0] && colourIsPresent[1] && colourIsPresent[2] && colourIsPresent[3] && colourIsPresent[4] && colourIsPresent[5]) {
    // The RGB sequences together contain all six colours
    theValue += 80;
  } else {
    // None of the above
    theValue += 90;
  }

  if (servoLoop[2] == 5 || servoLoop[2] == 7) {
    // The third number in the servo sequence is either a 5 or a 7
    // 0
  } else if (blueAndPurple) {
    // Blue and purple are both present in the same RGB sequence after one another
    theValue += 1;
  } else if (numberOfPrimes == 0) {
    // The servo sequence contains no prime numbers
    theValue += 2;
  } else if (noneAbove6) {
    // The servo sequence contains no numbers greater than 6
    theValue += 3;
  } else if (leftRGBFreq[4] > 0 && rightRGBFreq[4] > 0) {
    // Purple is present in both RGB sequences
    theValue += 4;
  } else if (sharedColours == 2) {
    // The RGB sequences share exactly 2 colours
    theValue += 5;
  } else if (servoLoopLength % 2 == 0) {
    // The length of the servo sequence is an even number
    theValue += 6;
  } else if (servoLoop[4] == 3 || servoLoop[4] == 6 || servoLoop[4] == 7 || servoLoop[4] == 8) {
    // The fifth number in the servo sequence is either a 3, 6, 7, or an 8
    theValue += 7;
  } else if (leftRGBFreq[0] > 0 || rightRGBFreq[0] > 0) {
    // Red is present in either of the RGB sequences
    theValue += 8;
  } else {
    // None of the above
    theValue += 9;
  }
}
