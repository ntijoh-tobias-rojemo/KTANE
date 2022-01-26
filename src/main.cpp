#include "global.h"
#include "setup.h"
#include "tick.h"

static int value;

void setup() {
  KTANE::fillRGBLoops();
  KTANE::calcServoLoopStart();
  KTANE::fillServoLoop();
  value = KTANE::determineInitialValue();
  pinMode(NeoPixelPin, OUTPUT);
  pinMode(OLEDClockPin, OUTPUT);
  pinMode(OLEDDataPin, OUTPUT);
  pinMode(ServoPin, OUTPUT);
  pinMode(LeftRGBLEDRedPin, OUTPUT);
  pinMode(LeftRGBLEDGreenPin, OUTPUT);
  pinMode(LeftRGBLEDBluePin, OUTPUT);
  pinMode(RightRGBLEDRedPin, OUTPUT);
  pinMode(RightRGBLEDGreenPin, OUTPUT);
  pinMode(RightRGBLEDBluePin, OUTPUT);
  pinMode(ButtonUpPin, INPUT);
  pinMode(ButtonDownPin, INPUT);
  pinMode(ButtonLeftPin, INPUT);
  pinMode(ButtonRightPin, INPUT);
  pinMode(Timer1Pin, OUTPUT);
  pinMode(Timer2Pin, OUTPUT);
  pinMode(Timer3Pin, OUTPUT);
  pinMode(PotentiometerPin, INPUT);
}

void loop() {
  if (KTANE::hasWon) {
  }
  else {
    /* Update tick-based modules */
    KTANE::updateRGBLEDs();

    /* Update react-based modules until a second has passed */
    /* while (millis() % 1000 - 10 < 20) {

    } */
    KTANE::tick++;  // Advance internal clock, 1 tick = 1 second
  }
}