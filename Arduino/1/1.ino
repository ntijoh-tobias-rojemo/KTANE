/* KTANE DESIGN DOC

RGBLEDs
  Consists of 2 sequences of random length between 4 and 7
  Each sequence contains colours picked from the available colours

Servo
  Consists of a sequence of length 10
  Each value from 0 to 9 occurs exactly once in the sequence

OLED
  Has values and patterns
  You can scroll through the values and patterns using the potentiometer

Value
  Is a value between 0 (inclusive) and 999 (inclusive)
  In inital value, each digit is determined separately based on the RGBLEDs and servo
  This value is then modified by the patterns in the OLED

NeoPixel Ring
  Contains 8 groups of 3 LEDs each
  1 group is a decoy group and is revealed after button inputs
  The remaining 7 groups are waypoint co-ordinates in the maze
  
Maze
  Navigated using the button D-pad
  Cross all 7 waypoints to disarm the bomb

*/
