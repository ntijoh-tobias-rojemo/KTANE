#ifndef KTANE_RING_SETUP
#define KTANE_RING_SETUP

#include "global.h"

/*Randomize configuration*/
static const int fakeGroupStart = rand() % LEDCount;

/*Fills 2 arrays with the colours of the RGB ring in order
ringRGB contains the colours as single integers
ringRGBColours contains the colours as RGB values*/
void KTANE::fillRingRGB() {
  for (int i = 0; i < LEDCount; i++) {
    KTANE::ringRGB[i] = rand() % 6;
  }
  for (int i = 0; i < LEDCount; i++) {
    KTANE::ringRGBColours[i][0] = KTANE::colours[KTANE::ringRGB[i]][0];
    KTANE::ringRGBColours[i][1] = KTANE::colours[KTANE::ringRGB[i]][1];
    KTANE::ringRGBColours[i][2] = KTANE::colours[KTANE::ringRGB[i]][2];
  }
}

#endif