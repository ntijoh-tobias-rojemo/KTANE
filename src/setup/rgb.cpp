#ifndef KTANE_RGB_SETUP
#define KTANE_RGB_SETUP

#include "global.h"

/*Fills 4 arrays with the colours of the RGB sequence in order, 2 for each sequence
RGBLoop contains the colours as single integers
RGBLoopColours contains the colours as RGB values*/
void KTANE::fillRGBLoops() {
  //// Left
  for (int i = 0; i < KTANE::leftRGBLoopLength; i++) {
    KTANE::leftRGBLoop[i] = rand() % 6;
  }
  // Exceptions to avoid a 4-length being indistinguishable to a 6-length
  if (KTANE::leftRGBLoopLength == 4 && KTANE::leftRGBLoop[0] == KTANE::leftRGBLoop[2] && KTANE::leftRGBLoop[1] == KTANE::leftRGBLoop[3]) {
    KTANE::leftRGBLoop[2] = KTANE::leftRGBLoop[1];
    KTANE::leftRGBLoop[3] = KTANE::leftRGBLoop[0];
  }
  else if (KTANE::leftRGBLoopLength == 6 && KTANE::leftRGBLoop[0] == KTANE::leftRGBLoop[3] && KTANE::leftRGBLoop[1] == KTANE::leftRGBLoop[4] && KTANE::leftRGBLoop[2] == KTANE::leftRGBLoop[5]) {
    KTANE::leftRGBLoop[3] = KTANE::leftRGBLoop[2];
    KTANE::leftRGBLoop[5] = KTANE::leftRGBLoop[0];
  }
  for (int i = 0; i < KTANE::leftRGBLoopLength; i++) {
    KTANE::leftRGBLoopColours[i][0] = KTANE::colours[KTANE::leftRGBLoop[i]][0];
    KTANE::leftRGBLoopColours[i][1] = KTANE::colours[KTANE::leftRGBLoop[i]][1];
    KTANE::leftRGBLoopColours[i][2] = KTANE::colours[KTANE::leftRGBLoop[i]][2];
  }
  // Add RGB values
  for (int i = 0; i < KTANE::rightRGBLoopLength; i++) {
    KTANE::rightRGBLoop[i] = rand() % 6;
  }
  //// Right
  // Exceptions to avoid a 4-length being indistinguishable to a 6-length
  if (KTANE::rightRGBLoopLength == 4 && KTANE::rightRGBLoop[0] == KTANE::rightRGBLoop[2] && KTANE::rightRGBLoop[1] == KTANE::rightRGBLoop[3]) {
    KTANE::rightRGBLoop[2] = KTANE::rightRGBLoop[1];
    KTANE::rightRGBLoop[3] = KTANE::rightRGBLoop[0];
  }
  else if (KTANE::rightRGBLoopLength == 6 && KTANE::rightRGBLoop[0] == KTANE::rightRGBLoop[3] && KTANE::rightRGBLoop[1] == KTANE::rightRGBLoop[4] && KTANE::rightRGBLoop[2] == KTANE::rightRGBLoop[5]) {
    KTANE::rightRGBLoop[3] = KTANE::rightRGBLoop[2];
    KTANE::rightRGBLoop[5] = KTANE::rightRGBLoop[0];
  }
  // Add RGB values
  for (int i = 0; i < KTANE::rightRGBLoopLength; i++) {
    KTANE::rightRGBLoopColours[i][0] = KTANE::colours[KTANE::rightRGBLoop[i]][0];
    KTANE::rightRGBLoopColours[i][1] = KTANE::colours[KTANE::rightRGBLoop[i]][1];
    KTANE::rightRGBLoopColours[i][2] = KTANE::colours[KTANE::rightRGBLoop[i]][2];
  }
}

#endif