#include <Arduino.h>

#define LEDCount 24

/*Randomize configuration*/
static const int fakeGroupStart = rand() % LEDCount;

/*Declare empty arrays*/
static int ringRGB[LEDCount], ringRGBColours[LEDCount][3];

/*Fills 2 arrays with the colours of the RGB ring in order
ringRGB contains the colours as single integers
ringRGBColours contains the colours as RGB values*/
void fillRingRGB() {
  for (int i = 0; i < LEDCount; i++) {
    ringRGB[i] = rand() % 6;
  }
  for (int i = 0; i < leftRGBLoopLength; i++) {
    ringRGBColours[i][0] = colours[ringRGB[i]][0];
    ringRGBColours[i][1] = colours[ringRGB[i]][1];
    ringRGBColours[i][2] = colours[ringRGB[i]][2];
  }
}