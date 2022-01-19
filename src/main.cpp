#include "global.h"

#include "misc.cpp"
#include "./setup.cpp"
#include "./tick.cpp"

void setup() {
  fillRGBLoops();
  calcServoLoopStart();
  fillServoLoop();
  // determineInitialValue();
      /*
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
  pinMode(Button1Pin, INPUT);
  pinMode(Button2Pin, INPUT);
  pinMode(Button3Pin, INPUT);
  pinMode(TiltSwitchAHPin, INPUT);
  pinMode(TiltSwitchBGPin, INPUT);
  pinMode(TiltSwitchCFPin, INPUT);
  pinMode(TiltSwitchDEPin, INPUT);
  pinMode(Timer1Pin, OUTPUT);
  pinMode(Timer2Pin, OUTPUT);
  pinMode(Timer3Pin, OUTPUT);
  pinMode(PotentiometerPin, INPUT);
      */
}

void loop() {
  if (KTANE::hasWon) {
  }
  else {
    /* Update tick-based modules */
    updateRGBLEDs();

    /* Update react-based modules until a second has passed */
    /* while (millis() % 1000 - 10 < 20) {

    } */
    KTANE::tick++;  // Advance internal clock, 1 tick = 1 second
  }
}