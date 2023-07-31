const int numLEDs = 8; // Number of LEDs connected
int ledPins[] = {4, 5, 6, 7, 8, 9,10,11}; // Array to store the LED pin numbers

const int rightSensorPin = A0; // Pin number for the right photomicrosensor
const int leftSensorPin = A1;  // Pin number for the left photomicrosensor

boolean ledsOn = false; // Flag to control the state of LEDs

void setup() {
  // Initializing all LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Initializing photomicrosensor pins as INPUT with internal pull-up resistors
  pinMode(rightSensorPin, INPUT_PULLUP);
  pinMode(leftSensorPin, INPUT_PULLUP);
}

void loop() {
  // Checking if the right sensor is interrupted
  if (digitalRead(rightSensorPin) == LOW) {
    // Turning all LEDs on and off
    ledsOn = !ledsOn;
    if (ledsOn) {
      turnOnLEDs();
      delay(500);
      turnOffLEDs();
      delay(500);
    }
  }

  // Checking if the left sensor is interrupted
  if (digitalRead(leftSensorPin) == LOW) {
    // Blink LEDs one after another
    blinkLEDs();
  }
}

// Function to turn on all LEDs
void turnOnLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

// Function to turn off all LEDs
void turnOffLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

// Function to blink LEDs one after another
void blinkLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
  }
}
