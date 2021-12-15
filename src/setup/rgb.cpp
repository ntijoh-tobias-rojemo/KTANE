#include <Arduino.h>

/*Randomize configuration*/
static const int leftRGBLoopLength = rand()%4+4;
static const int rightRGBLoopLength = rand()%4+4;

/*Declare empty arrays*/
static int leftRGBLoop[7] = {-1}, leftRGBLoopColours[7][3];
static int rightRGBLoop[7] = {-1}, rightRGBLoopColours[7][3];

/*Fills 4 arrays with the colours of the RGB sequence in order, 2 for each sequence
RGBLoop contains the colours as single integers
RGBLoopColours contains the colours as RGB values*/
void fillRGBLoops() {
  //// Left
  for (int i = 0; i < leftRGBLoopLength; i++) {
    leftRGBLoop[i] = rand() % 6;
  }
  // Exceptions to avoid a 4-length being indistinguishable to a 6-length
  if (leftRGBLoopLength == 4 && leftRGBLoop[0] == leftRGBLoop[2] && leftRGBLoop[1] == leftRGBLoop[3]) {
    leftRGBLoop[2] = leftRGBLoop[1];
    leftRGBLoop[3] = leftRGBLoop[0];
  }
  else if (leftRGBLoopLength == 6 && leftRGBLoop[0] == leftRGBLoop[3] && leftRGBLoop[1] == leftRGBLoop[4] && leftRGBLoop[2] == leftRGBLoop[5]) {
    leftRGBLoop[3] = leftRGBLoop[2];
    leftRGBLoop[5] = leftRGBLoop[0];
  }
  for (int i = 0; i < leftRGBLoopLength; i++) {
    leftRGBLoopColours[i][0] = colours[leftRGBLoop[i]][0];
    leftRGBLoopColours[i][1] = colours[leftRGBLoop[i]][1];
    leftRGBLoopColours[i][2] = colours[leftRGBLoop[i]][2];
  }
  // Add RGB values
  for (int i = 0; i < rightRGBLoopLength; i++) {
    rightRGBLoop[i] = rand() % 6;
  }
  //// Right
  // Exceptions to avoid a 4-length being indistinguishable to a 6-length
  if (rightRGBLoopLength == 4 && rightRGBLoop[0] == rightRGBLoop[2] && rightRGBLoop[1] == rightRGBLoop[3]) {
    rightRGBLoop[2] = rightRGBLoop[1];
    rightRGBLoop[3] = rightRGBLoop[0];
  }
  else if (rightRGBLoopLength == 6 && rightRGBLoop[0] == rightRGBLoop[3] && rightRGBLoop[1] == rightRGBLoop[4] && rightRGBLoop[2] == rightRGBLoop[5]) {
    rightRGBLoop[3] = rightRGBLoop[2];
    rightRGBLoop[5] = rightRGBLoop[0];
  }
  // Add RGB values
  for (int i = 0; i < rightRGBLoopLength; i++) {
    rightRGBLoopColours[i][0] = colours[rightRGBLoop[i]][0];
    rightRGBLoopColours[i][1] = colours[rightRGBLoop[i]][1];
    rightRGBLoopColours[i][2] = colours[rightRGBLoop[i]][2];
  }
}