// Arduino Basics Example: Understanding pinMode, digitalWrite, analogRead, potentiometers, LEDs, and buttons

// Pin Definitions
const int ledPin = 13;      // Pin 13 is the built-in LED on most Arduino boards
const int buttonPin = 2;    // Pin 2 will be used for the button input
const int potPin = A0;      // Analog Pin A0 for reading the potentiometer

// Variables
int buttonState = 0;        // Variable to hold the state of the button (HIGH or LOW)
int potValue = 0;           // Variable to store the value from the potentiometer (0 to 1023)
int mappedValue = 0;        // Variable to store the mapped potentiometer value for LED brightness (0 to 255)

void setup() {
  // Start serial communication for debugging and monitoring values
  Serial.begin(9600);  

  // Set up the LED pin as an output (we will control the LED)
  pinMode(ledPin, OUTPUT);  

  // Set up the button pin as an input (we will read the button)
  pinMode(buttonPin, INPUT);  

  // Print a welcome message to the Serial Monitor
  Serial.println("Arduino Basics - LED and Button Example");
}

void loop() {
  // Read the state of the button (HIGH if pressed, LOW if not)
  buttonState = digitalRead(buttonPin);  

  // Print the button state to the Serial Monitor
  Serial.print("Button State: ");
  Serial.println(buttonState); 

  // If the button is pressed (buttonState is HIGH), turn on the LED
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn the LED ON
    Serial.println("LED ON");
  } else {
    digitalWrite(ledPin, LOW);   // Turn the LED OFF
    Serial.println("LED OFF");
  }

  // Alterntive method of doing the same
  digitalWrite(ledPin, digitalRead(buttonPin));

  // Read the potentiometer value (analog value from 0 to 1023)
  potValue = analogRead(potPin);  

  // Map the potentiometer value to a range for LED brightness (0 to 255)
  mappedValue = map(potValue, 0, 1023, 0, 255);  

  // Use the mapped value to set the LED brightness using PWM (Pulse Width Modulation)
  analogWrite(ledPin, mappedValue);  // Controls brightness of the LED

  // Print the potentiometer value and mapped LED brightness to the Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue); 
  Serial.print("Mapped LED Brightness: ");
  Serial.println(mappedValue);

  // Wait a short time before repeating the loop
  delay(100);  // Delay to slow down the loop for better readability in the Serial Monitor
}