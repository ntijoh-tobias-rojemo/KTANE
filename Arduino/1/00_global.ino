#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <Wire.h>
#include <SSD1306AsciiWire.h>

static const int Seed = 324776345;

// The current cycle
static int tick = 0;

// The current status of the buttons
static struct {
  unsigned int up : 2;
  unsigned int down : 2;
  unsigned int left : 2;
  unsigned int right : 2;
} buttonStatus = {};

// The current position of the potentiometer and which space it is in
static int potentiometerPos;
static int space = 0;
static int lastSpace = 0;

// Array of colours used
static const int colours[6][3] = {
  {255, 0, 0},     // Red
  {0, 255, 0},     // Green
  {0, 0, 255},     // Blue
  {0, 255, 255},   // Cyan
  {166, 0, 255},   // Purple
  {225, 255, 255}  // White
};

// A structure used to store a maze position in 1 byte instead of 2
struct MazePos {
  unsigned int x : 4;
  unsigned int y : 4;
};

// The initial status of the maze, stored in a more optimized structure
static struct {
  bool active : 1;
  unsigned int wp0 : 2;
  unsigned int wp1 : 2;
  unsigned int wp2 : 2;
  unsigned int wp3 : 2;
  unsigned int wp4 : 2;
  unsigned int wp5 : 2;
  unsigned int wp6 : 2;
  bool solved : 1;
} mazeStatus = {};

// Locations of in/out pins
#define NEO_PIXEL_PIN 6
#define SERVO_PIN 10
#define LEFT_RGB_LED_RED_PIN 11
#define LEFT_RGB_LED_GREEN_PIN 12
#define LEFT_RGB_LED_BLUE_PIN 13
#define RIGHT_RGB_LED_RED_PIN 9
#define RIGHT_RGB_LED_GREEN_PIN 8
#define RIGHT_RGB_LED_BLUE_PIN 7
#define BUTTON_UP_PIN 4
#define BUTTON_DOWN_PIN 3
#define BUTTON_LEFT_PIN 5
#define BUTTON_RIGHT_PIN 2
#define POTENTIOMETER_PIN A0

// Directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Delay to avoid bouncing of button inputs
#define BOUNCE_DELAY 10
