void setup() {
  // Calculate solutions
  fillRGBLoops();
  calcServoLoopStart();
  fillServoLoop();
  fillOLEDValues();
  fillOLEDPatterns();
  determineInitialValue();
  calcPotentiometerPos();
  fillRingRGB();
  calcRevealSequence();
  determineWaypoints();

  // pinModes
  pinMode(NEO_PIXEL_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(LEFT_RGB_LED_RED_PIN, OUTPUT);
  pinMode(LEFT_RGB_LED_GREEN_PIN, OUTPUT);
  pinMode(LEFT_RGB_LED_BLUE_PIN, OUTPUT);
  pinMode(RIGHT_RGB_LED_RED_PIN, OUTPUT);
  pinMode(RIGHT_RGB_LED_GREEN_PIN, OUTPUT);
  pinMode(RIGHT_RGB_LED_BLUE_PIN, OUTPUT);
  pinMode(BUTTON_UP_PIN, INPUT);
  pinMode(BUTTON_DOWN_PIN, INPUT);
  pinMode(BUTTON_LEFT_PIN, INPUT);
  pinMode(BUTTON_RIGHT_PIN, INPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);

  // Log
  Serial.begin(9600);

  // Other setup
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);
  oled.clear();

  servo.attach(SERVO_PIN, 500, 2500);
  // Updates twice to account for lastSpace
  updateInputs();
  updateInputs();
  rgbRing.begin();
  rgbRing.setBrightness(50);
  rgbRing.show();
  updateRingColours();
  updateOLED();
  resetMazeProgress();
}

void loop() {
  if (mazeStatus.solved) {
    analogWrite(LEFT_RGB_LED_RED_PIN, 0);
    analogWrite(LEFT_RGB_LED_GREEN_PIN, 0);
    analogWrite(LEFT_RGB_LED_BLUE_PIN, 0);
    analogWrite(RIGHT_RGB_LED_RED_PIN, 0);
    analogWrite(RIGHT_RGB_LED_GREEN_PIN, 0);
    analogWrite(RIGHT_RGB_LED_BLUE_PIN, 0);
    displayTime();
    while (true) {
      updateRingSolved();
    }
  }
  else {
    // Update tick-based modules
    updateRGBLEDs();
    updateServo();

    // Reset maze if buttons are held down
    updateInputs();
    if (buttonStatus.up == HIGH && buttonStatus.down == HIGH && buttonStatus.left == HIGH && buttonStatus.right == HIGH) {
      resetMazeProgress();
    }

    // Update react-based modules until a second has passed
    do {
      updateInputs();
      if (space != lastSpace) {
        updateOLED();
      }
      if (mazeStatus.active) {
        updateMazePos();
      } else {
        updateSequenceInput();
      }

      // Delay to avoid bouncing
      delay(BOUNCE_DELAY);
    } while (millis() % 1000 < 1000 - BOUNCE_DELAY);
    tick++;  // Advance internal clock
  }
}
