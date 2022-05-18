#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define I2C_ADDRESS 0x3C

// Pattern substrings are used to save space
static const char* const patternSubstrings[] = {
  "--------------------\n",
  "| | | | | | | | | | \n",
  "+-+-+-+-+-+-+-+-+-+-\n",
  "/ / / / / / / / / / \n",
  " / / / / / / / / / /\n",
  "X X X X X X X X X X \n",
  " X X X X X X X X X X\n",
  "                    \n",
  "     ____      ____ \n",
  "____|    |____|    |\n",
  "| ___________ |\n| | _______ | |\n| | | ___ | | |\n| | | |_| | | |\n| | |_____| | |\n| |_________| |"
};

// The OLED Object
SSD1306AsciiWire oled;

// The array for values in order
static unsigned long int oledValues[10];
static int oledPatterns[10];

// Fills the arrays for OLED values
void fillOLEDValues() {
  for (int i = 0; i < 10; i++) {
    oledValues[i] = rand() % 0xffffffff;
  }
}

void fillOLEDPatterns() {
  for (int i = 0; i < 10; i++) {
    oledPatterns[i] = /*rand() % 8*/ i;
  }
}

// The correct position for the potentiometer
static int correctPotentiometerPos = 10;

// Calculate correct potentiometer position
void calcPotentiometerPos() {


  correctPotentiometerPos %= 10;
}

// Updates the display based on the current potentiometer position
void updateOLED() {
  // Convert int to const char*
  char buf[11];
  snprintf(buf, 11, "%d", oledValues[space]);

  // Print to OLED
  oled.clear();
  oled.print(buf);
  oled.print("\n");
  drawPattern(space);
}

// Draws the pattern from ID
void drawPattern(int space) {
  switch(space) {
    case 0: 
      oled.print(patternSubstrings[0]);
      oled.print(patternSubstrings[0]);
      oled.print(patternSubstrings[0]);
      oled.print(patternSubstrings[0]);
      oled.print(patternSubstrings[0]);
      oled.print(patternSubstrings[0]);
    break;
    case 1:
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[1]);
    break;
    case 2:
      oled.print(patternSubstrings[2]);
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[2]);
      oled.print(patternSubstrings[1]);
      oled.print(patternSubstrings[2]);
      oled.print(patternSubstrings[1]);
    break;
    case 3:
      oled.print(patternSubstrings[3]);
      oled.print(patternSubstrings[4]);
      oled.print(patternSubstrings[3]);
      oled.print(patternSubstrings[4]);
      oled.print(patternSubstrings[3]);
      oled.print(patternSubstrings[4]);
    break;
    case 4:
      oled.print(patternSubstrings[5]);
      oled.print(patternSubstrings[6]);
      oled.print(patternSubstrings[5]);
      oled.print(patternSubstrings[6]);
      oled.print(patternSubstrings[5]);
      oled.print(patternSubstrings[6]);
    break;
    case 5:
      oled.print(patternSubstrings[7]);
      oled.print(patternSubstrings[7]);
      oled.print(patternSubstrings[8]);
      oled.print(patternSubstrings[9]);
      oled.print(patternSubstrings[7]);
      oled.print(patternSubstrings[7]);
    break;
    case 6:
      oled.print(patternSubstrings[10]);
    break;
    case 7:
      oled.print(patternSubstrings[10]);
    break;
  }
}

// Displays the time it took to disarm the bomb
void displayTime() {
  // Calc time
  int minutes = tick / 60;
  int seconds = tick % 60;

  // Convert time to const char*
  char minuteBuf[4];
  char secondBuf[3];
  snprintf(minuteBuf, 4, "%d", minutes);
  snprintf(secondBuf, 3, "%d", seconds);

  // Concat time buffers to output const char*
  char timeToDisplay[6];
  strcpy(timeToDisplay, minuteBuf);
  strcat(timeToDisplay, ":");
  strcat(timeToDisplay, secondBuf);

  // Print to OLED
  oled.clear();
  oled.print("Time:");
  oled.print(timeToDisplay);
}
