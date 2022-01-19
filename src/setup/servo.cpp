#include "global.h"

// Array of servo starts
static const int servoStarts[4][4] = {
  {0, 7, 4, 2},
  {5, 3, 3, 5},
  {4, 2, 9, 8},
  {0, 1, 8, 9}
};

// Returns the first value in the servo sequence
void calcServoLoopStart() {
  if (KTANE::leftRGBLoopLength < KTANE::rightRGBLoopLength) {
    KTANE::servoLoopStart = servoStarts[KTANE::leftRGBLoopLength][KTANE::rightRGBLoopLength];
  }
  else {
    KTANE::servoLoopStart = servoStarts[KTANE::rightRGBLoopLength][KTANE::leftRGBLoopLength];
  }
}

// Returns an array of unique integers, starting with servoLoopStart
void fillServoLoop() {
  KTANE::servoLoop[0] = KTANE::servoLoopStart;
  int output[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  random_shuffle(&output[0], &output[10]);
}