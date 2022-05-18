// The length of the RGB loops
static const int leftRGBLoopLength = rand() % 4 + 4;
static const int rightRGBLoopLength = rand() % 4 + 4;

// The colourIDs for the RGB loops
static int leftRGBLoop[7] = { -1};
static int rightRGBLoop[7] = { -1};

// The frequence of each colour in the RGB loops
static int leftRGBFreq[6] = {0};
static int rightRGBFreq[6] = {0};

// The current position in the sequences
int currentLeftRGBLEDPos = rand() % leftRGBLoopLength;
int currentRightRGBLEDPos = rand() % rightRGBLoopLength;

// Fills <side>RGBLoop with the colours of the RGB sequences in order, and updates the colour frequency
void fillRGBLoops() {
  //// Left
  for (int i = 0; i < leftRGBLoopLength; i++) {
    const int colourToAdd = rand() % 6;
    leftRGBLoop[i] = colourToAdd;
    leftRGBFreq[colourToAdd]++;
  }
  // Exceptions to avoid a 4-length being indistinguishable to a 6-length
  if (leftRGBLoopLength == 4 && leftRGBLoop[0] == leftRGBLoop[2] && leftRGBLoop[1] == leftRGBLoop[3]) {
    leftRGBLoop[2] = leftRGBLoop[1];
    leftRGBLoop[3] = leftRGBLoop[0];
  } else if (leftRGBLoopLength == 6 && leftRGBLoop[0] == leftRGBLoop[2] && leftRGBLoop[1] == leftRGBLoop[3] && leftRGBLoop[2] == leftRGBLoop[4] && leftRGBLoop[3] == leftRGBLoop[5]) {
    leftRGBLoop[4] = leftRGBLoop[1];
    leftRGBLoop[5] = leftRGBLoop[0];
  }
  //// Right
  for (int i = 0; i < rightRGBLoopLength; i++) {
    const int colourToAdd = rand() % 6;
    rightRGBLoop[i] = colourToAdd;
    rightRGBFreq[colourToAdd]++;
  }
  // Exceptions to avoid a 4-length being indistinguishable to a 6-length
  if (rightRGBLoopLength == 4 && rightRGBLoop[0] == rightRGBLoop[2] && rightRGBLoop[1] == rightRGBLoop[3]) {
    rightRGBLoop[2] = rightRGBLoop[1];
    rightRGBLoop[3] = rightRGBLoop[0];
  } else if (rightRGBLoopLength == 6 && rightRGBLoop[0] == rightRGBLoop[3] && rightRGBLoop[1] == rightRGBLoop[4] && rightRGBLoop[2] == rightRGBLoop[5]) {
    rightRGBLoop[3] = rightRGBLoop[2];
    rightRGBLoop[5] = rightRGBLoop[0];
  }
}

void updateRGBLEDs() {
  // Set the pins to the values corresponding to the current positions
  Serial.print(LEFT_RGB_LED_RED_PIN, colours[leftRGBLoop[currentLeftRGBLEDPos]][0]);
  Serial.print(LEFT_RGB_LED_GREEN_PIN, colours[leftRGBLoop[currentLeftRGBLEDPos]][1]);
  Serial.print(LEFT_RGB_LED_BLUE_PIN, colours[leftRGBLoop[currentLeftRGBLEDPos]][2]);
  Serial.print(RIGHT_RGB_LED_RED_PIN, colours[rightRGBLoop[currentRightRGBLEDPos]][0]);
  Serial.print(RIGHT_RGB_LED_GREEN_PIN, colours[rightRGBLoop[currentRightRGBLEDPos]][1]);
  Serial.print(RIGHT_RGB_LED_BLUE_PIN, colours[rightRGBLoop[currentRightRGBLEDPos]][2]);
  Serial.println();

  analogWrite(LEFT_RGB_LED_RED_PIN, colours[leftRGBLoop[currentLeftRGBLEDPos]][0]);
  analogWrite(LEFT_RGB_LED_GREEN_PIN, colours[leftRGBLoop[currentLeftRGBLEDPos]][1]);
  analogWrite(LEFT_RGB_LED_BLUE_PIN, colours[leftRGBLoop[currentLeftRGBLEDPos]][2]);
  analogWrite(RIGHT_RGB_LED_RED_PIN, colours[rightRGBLoop[currentRightRGBLEDPos]][0]);
  analogWrite(RIGHT_RGB_LED_GREEN_PIN, colours[rightRGBLoop[currentRightRGBLEDPos]][1]);
  analogWrite(RIGHT_RGB_LED_BLUE_PIN, colours[rightRGBLoop[currentRightRGBLEDPos]][2]);

  // Increment the position counters
  currentLeftRGBLEDPos++;
  currentRightRGBLEDPos++;

  // Set the position counters to 0 if the value exceeds the sequence length
  if (currentLeftRGBLEDPos > leftRGBLoopLength) {
    currentLeftRGBLEDPos = 0;
  }
  if (currentRightRGBLEDPos > rightRGBLoopLength) {
    currentRightRGBLEDPos = 0;
  }

  Serial.print(currentLeftRGBLEDPos);
  Serial.print(", ");
  Serial.println(currentRightRGBLEDPos);
}
