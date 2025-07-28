#include <Stepper.h> // Import the Stepper Library, not inculded; must install with IDE

/////////////////////////////////////////////////
// Define Stepper Motor Constants
const int STEPS_PER_REV = 200;  // Number of steps per revolution for your motor (scalable)

const int IN[4] = {8,9,10,11}; // Pin Definitions


Stepper stepperMotor(STEPS_PER_REV, IN[0]), IN[1], IN[2], IN[3]; // Create Stepper motor object
/////////////////////////////////////////////////

// Setup Function
void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging

  // Set motor speed in RPM
  stepperMotor.setSpeed(60);  // Adjust this value as needed (Max depends on voltage)
}

// Loop Function
void loop() {
  // Rotate stepper motor forward
  Serial.println("Rotating forward...");
  stepperMotor.step(STEPS_PER_REV);  // Rotate one full revolution (forward)
  delay(1000);                       // Pause for 1 second

  // Rotate stepper motor backward
  Serial.println("Rotating backward...");
  stepperMotor.step(-STEPS_PER_REV); // Rotate one full revolution (backward)
  delay(1000);                       // Pause for 1 second

  // Half revolution forward
  Serial.println("Rotating half revolution forward...");
  stepperMotor.step(STEPS_PER_REV / 2); // Rotate half a revolution
  delay(1000);

  // Stop for 2 seconds
  Serial.println("Stopping...");
  delay(2000);
}