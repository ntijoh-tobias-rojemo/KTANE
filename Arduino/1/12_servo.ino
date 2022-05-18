// Define servo object
Servo servo;

// The length of the servo sequence
static const int servoLoopLength = rand() % 7 + 3;

// The positions for the servo sequence
static int servoLoop[9] = { -1};

// The starting position for the servo sequence
static int servoLoopStart;

// The current position for the servo
static int currentServoPos = rand() % servoLoopLength;

// Array of servo starts
static const int servoStarts[4][4] = {
  {0, 7, 4, 2},
  {5, 3, 3, 5},
  {4, 2, 9, 8},
  {0, 1, 8, 9}
};

// Determines the first value in the servo sequence
void calcServoLoopStart() {
  if (leftRGBLoopLength < rightRGBLoopLength) {
    servoLoopStart = servoStarts[leftRGBLoopLength - 4][rightRGBLoopLength - 4];
  } else {
    servoLoopStart = servoStarts[rightRGBLoopLength - 4][leftRGBLoopLength - 4];
  }
}

// Fills an array of unique integers, starting with servoLoopStart
void fillServoLoop() {
  int validInts[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  servoLoop[0] = servoLoopStart;
  validInts[servoLoopStart] = -1;
  for (int i = 1; i < servoLoopLength; i++) {
    bool hasFoundValidInt = false;
    int intToAdd;
    while (!hasFoundValidInt) {
      intToAdd = rand() % 10;
      if (validInts[intToAdd] != -1) {
        hasFoundValidInt = true;
      }
    }
    validInts[intToAdd] = -1;
    servoLoop[i] = intToAdd;
  }
}

void updateServo() {
  // Set the servo to the current position
  servo.write(map(currentServoPos, 0, 9, 0, 180));

  // Increment the position counter
  currentServoPos++;

  // Set the position counter to 0 if the value exceeds the sequence length
  if (currentServoPos > servoLoopLength) {
    currentServoPos = 0;
  }

  Serial.println(currentServoPos);
}
