#include <Arduino.h>

/*Randomize configuration*/
static const int servoLoopLength = rand()%7+3;

/*Declare empty arrays*/
static int servoLoop[9] = {-1};

// Declare integers
static int servoLoopStart;

// Array of servo starts
static const int servoStarts[4][4] = {
  {0, 7, 4, 2},
  {5, 3, 3, 5},
  {4, 2, 9, 8},
  {0, 1, 8, 9}
};

// Returns the first value in the servo sequence
void calcServoLoopStart() {
  if (leftRGBLoopLength < rightRGBLoopLength) {
    servoLoopStart = servoStarts[leftRGBLoopLength][rightRGBLoopLength];
  }
  else {
    servoLoopStart = servoStarts[rightRGBLoopLength][leftRGBLoopLength];
  }
}

// Returns an array of unique integers, starting with servoLoopStart
void fillServoLoop() {
  servoLoop[0] = servoLoopStart;
  int output[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  random_shuffle(&output[0], &output[10]);
}