#define NEO_PIXEL_LENGTH 24

// Define NeoPixel object
Adafruit_NeoPixel rgbRing(NEO_PIXEL_LENGTH, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// The colourIDs for the NeoPixel ring, as well as the frequency of each colour
static int ringRGB[NEO_PIXEL_LENGTH];
static int ringRGBFreq[NEO_PIXEL_LENGTH] = {0};

// The first LED of the fake group
static const int decoyGroupStart = rand() % NEO_PIXEL_LENGTH;

// The sequence to reveal the fake group
static int revealSequence[4];

// How many correct inputs in the sequence so far
static int correctInputs = 0;

// The current start colour for the victory animation
static int victoryStartColour = 0;

// Fills the NeoPixel ring with colours, and updates the frequency of each colour
void fillRingRGB() {
  for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
    const int colourToAdd = rand() % 6;
    ringRGB[i] = colourToAdd;
    ringRGBFreq[colourToAdd]++;
  }
}

// Calculates the sequence of button presses required to reveal the decoy group
void calcRevealSequence() {
  static int highestID = 0;
  static int highestValue = 0;
  static int lowestID = 0;
  static int lowestValue = NEO_PIXEL_LENGTH;
  for (int i = 0; i < 6; i++) {
    if (ringRGBFreq[i] > highestValue) {
      highestID = i;
      highestValue = ringRGBFreq[i];
    }
    if (ringRGBFreq[i] < lowestValue) {
      lowestID = i;
      lowestValue = ringRGBFreq[i];
    }
  }
  lowestID = 6 - lowestID;
  static int sequenceValue;
  switch (highestID) {
    case 0: sequenceValue = theValue & oledValues[correctPotentiometerPos];     break;
    case 1: sequenceValue = theValue | oledValues[correctPotentiometerPos];     break;
    case 2: sequenceValue = ~(theValue & oledValues[correctPotentiometerPos]);  break;
    case 3: sequenceValue = theValue ^ oledValues[correctPotentiometerPos];     break;
    case 4: sequenceValue = ~(theValue ^ oledValues[correctPotentiometerPos]);  break;
    case 5: sequenceValue = ~(theValue | oledValues[correctPotentiometerPos]);  break;
  }
  // Mask so we only have the lowest 10 bits
  sequenceValue = sequenceValue & 0b1111111111;
  // The reveal code consists of 4 presses
  for (int i = 0; i < 4; i++) {
    const int currentDigit = sequenceValue / ((int)pow(10, (3 - i))) % 10;
    switch (lowestID) {
      case 0: switch (currentDigit) {
          case 0: revealSequence[i] = LEFT; break;
          case 1: revealSequence[i] = RIGHT; break;
          case 2: revealSequence[i] = UP; break;
          case 3: revealSequence[i] = RIGHT; break;
          case 4: revealSequence[i] = UP; break;
          case 5: revealSequence[i] = LEFT; break;
          case 6: revealSequence[i] = DOWN; break;
          case 7: revealSequence[i] = UP; break;
          case 8: revealSequence[i] = LEFT; break;
          case 9: revealSequence[i] = RIGHT; break;
        } break;
      case 1: switch (currentDigit) {
          case 0: revealSequence[i] = UP; break;
          case 1: revealSequence[i] = UP; break;
          case 2: revealSequence[i] = RIGHT; break;
          case 3: revealSequence[i] = LEFT; break;
          case 4: revealSequence[i] = RIGHT; break;
          case 5: revealSequence[i] = DOWN; break;
          case 6: revealSequence[i] = LEFT; break;
          case 7: revealSequence[i] = UP; break;
          case 8: revealSequence[i] = LEFT; break;
          case 9: revealSequence[i] = LEFT; break;
        } break;
      case 2: switch (currentDigit) {
          case 0: revealSequence[i] = UP; break;
          case 1: revealSequence[i] = LEFT; break;
          case 2: revealSequence[i] = LEFT; break;
          case 3: revealSequence[i] = LEFT; break;
          case 4: revealSequence[i] = RIGHT; break;
          case 5: revealSequence[i] = DOWN; break;
          case 6: revealSequence[i] = LEFT; break;
          case 7: revealSequence[i] = DOWN; break;
          case 8: revealSequence[i] = RIGHT; break;
          case 9: revealSequence[i] = RIGHT; break;
        } break;
      case 3: switch (currentDigit) {
          case 0: revealSequence[i] = RIGHT; break;
          case 1: revealSequence[i] = RIGHT; break;
          case 2: revealSequence[i] = UP; break;
          case 3: revealSequence[i] = LEFT; break;
          case 4: revealSequence[i] = RIGHT; break;
          case 5: revealSequence[i] = LEFT; break;
          case 6: revealSequence[i] = LEFT; break;
          case 7: revealSequence[i] = RIGHT; break;
          case 8: revealSequence[i] = DOWN; break;
          case 9: revealSequence[i] = RIGHT; break;
        } break;
      case 4: switch (currentDigit) {
          case 0: revealSequence[i] = UP; break;
          case 1: revealSequence[i] = UP; break;
          case 2: revealSequence[i] = RIGHT; break;
          case 3: revealSequence[i] = DOWN; break;
          case 4: revealSequence[i] = RIGHT; break;
          case 5: revealSequence[i] = UP; break;
          case 6: revealSequence[i] = RIGHT; break;
          case 7: revealSequence[i] = UP; break;
          case 8: revealSequence[i] = LEFT; break;
          case 9: revealSequence[i] = UP; break;
        } break;
      case 5: switch (currentDigit) {
          case 0: revealSequence[i] = DOWN; break;
          case 1: revealSequence[i] = UP; break;
          case 2: revealSequence[i] = DOWN; break;
          case 3: revealSequence[i] = DOWN; break;
          case 4: revealSequence[i] = UP; break;
          case 5: revealSequence[i] = LEFT; break;
          case 6: revealSequence[i] = DOWN; break;
          case 7: revealSequence[i] = DOWN; break;
          case 8: revealSequence[i] = LEFT; break;
          case 9: revealSequence[i] = RIGHT; break;
        } break;
    }
  }
}

// Updates the colours of the LED ring
void updateRingColours() {
  for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
    rgbRing.setPixelColor(i, colours[ringRGB[i]][0], colours[ringRGB[i]][1], colours[ringRGB[i]][2]);
  }
  rgbRing.show();
}

// Turns all LEDs in the decoy group off
void revealDecoyGroup() {
  for (int i = 0; i < 3; i++) {
    rgbRing.setPixelColor(i + decoyGroupStart, 0, 0, 0);
  }
  rgbRing.show();
}

// Increases the current sequence input of correct, or resets otherwise
void updateSequenceInput() {
  const int prevCorrect = correctInputs;
  switch (revealSequence[correctInputs]) {
    case UP: if (buttonStatus.up == RISING) {
        correctInputs++;
      }
      break;
    case DOWN: if (buttonStatus.down == RISING) {
        correctInputs++;
      }
      break;
    case LEFT: if (buttonStatus.left == RISING) {
        correctInputs++;
      }
      break;
    case RIGHT: if (buttonStatus.right == RISING) {
        correctInputs++;
      }
      break;
  }
  if (correctInputs == prevCorrect) {
    correctInputs = 0;
  }
  if (correctInputs == 4) {
    revealDecoyGroup();
    mazeStatus.active = true;
  }
}

void updateRingSolved() {
  victoryStartColour++;
  for (int i = 0; i < NEO_PIXEL_LENGTH; i++) {
    long long int colour = rgbRing.gamma32(rgbRing.ColorHSV((victoryStartColour + i * 5) % 65536));
    rgbRing.setPixelColor(i, colour);
  }
  rgbRing.show();
}
