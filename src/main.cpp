#include <Arduino.h>

srand(32497746);

// Declare integers
static int tick = 0;
static bool hasWon = false;

// Array of colours used
static const int colours[7][3] = {
  {255, 0, 0},     // Red
  {0, 255, 0},     // Green
  {0, 0, 255},     // Blue
  {100, 0, 255},   // Purple
  {255, 0, 225},   // Pink
  {255, 166, 0},   // Orange
  {0, 0, 0}        // Off
};

// Define locations of in/out pins
#define NeoPixelPin 1
#define OLEDClockPin 2
#define OLEDDataPin 3
#define ServoPin 4
#define LeftRGBLEDRedPin 5
#define LeftRGBLEDGreenPin 6
#define LeftRGBLEDBluePin 7
#define RightRGBLEDRedPin 8
#define RightRGBLEDGreenPin 9
#define RightRGBLEDBluePin 10
#define Button1Pin 11
#define Button2Pin 12
#define Button3Pin 13
#define TiltSwitchAHPin 14
#define TiltSwitchBGPin 15
#define TiltSwitchCFPin 16
#define TiltSwitchDEPin 17
#define Timer1Pin 18
#define Timer2Pin 19
#define Timer3Pin 20
#define PotentiometerPin 21

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
  if (hasWon) {
  }
  else {
    /* Update tick-based modules */
    updateRGBLEDs();

    /* Update react-based modules until a second has passed */
    /* while (millis() % 1000 - 10 < 20) {

    } */
    tick++;  // Advance internal clock, 1 tick = 1 second
  }
}