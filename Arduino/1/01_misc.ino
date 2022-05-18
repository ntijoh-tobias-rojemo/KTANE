// Counts the occurances of a given item in an array
int occurancesInArray(int inputArray[], int item, int arrayLength) {
  int output = 0;
  for (int i = 0; i < arrayLength; i++) {
    if (inputArray[i] == item) {
      output++;
    }
  }
  return output;
}

// Updates the data for the inputs
void updateInputs() {
  const bool upButton = digitalRead(BUTTON_UP_PIN);
  const bool downButton = digitalRead(BUTTON_DOWN_PIN);
  const bool leftButton = digitalRead(BUTTON_LEFT_PIN);
  const bool rightButton = digitalRead(BUTTON_RIGHT_PIN);
  potentiometerPos = analogRead(POTENTIOMETER_PIN);
  lastSpace = space;
  space = map(potentiometerPos, 0, 0x400, 0, 9);
  // Since structure members cannot be accessed dynamically in this version of C++, this cannot be written as a loop
  if (upButton) {
    switch (buttonStatus.up) {
      case HIGH:
      case RISING: buttonStatus.up = HIGH;
        break;
      case LOW:
      case FALLING: buttonStatus.up = RISING;
    }
  } else {
    switch (buttonStatus.up) {
      case LOW:
      case FALLING: buttonStatus.up = LOW;
        break;
      case HIGH:
      case RISING: buttonStatus.up = FALLING;
    }
  }
  if (downButton) {
    switch (buttonStatus.down) {
      case HIGH:
      case RISING: buttonStatus.down = HIGH;
        break;
      case LOW:
      case FALLING: buttonStatus.down = RISING;
    }
  } else {
    switch (buttonStatus.down) {
      case LOW:
      case FALLING: buttonStatus.down = LOW;
        break;
      case HIGH:
      case RISING: buttonStatus.down = FALLING;
    }
  }
  if (leftButton) {
    switch (buttonStatus.left) {
      case HIGH:
      case RISING: buttonStatus.left = HIGH;
        break;
      case LOW:
      case FALLING: buttonStatus.left = RISING;
    }
  } else {
    switch (buttonStatus.left) {
      case LOW:
      case FALLING: buttonStatus.left = LOW;
        break;
      case HIGH:
      case RISING: buttonStatus.left = FALLING;
    }
  }
  if (rightButton) {
    switch (buttonStatus.right) {
      case HIGH:
      case RISING: buttonStatus.right = HIGH;
        break;
      case LOW:
      case FALLING: buttonStatus.right = RISING;
    }
  } else {
    switch (buttonStatus.right) {
      case LOW:
      case FALLING: buttonStatus.right = LOW;
        break;
      case HIGH:
      case RISING: buttonStatus.right = FALLING;
    }
  }
}

/*
template <unsigned int SIZE> void printArr(const int (& arr)[SIZE]) {
  for(unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    Serial.println(arr[i]);
  }
}

template <unsigned int SIZE> void printArr(const long unsigned int (& arr)[SIZE]) {
  for(unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    Serial.println(arr[i]);
  }
}
*/