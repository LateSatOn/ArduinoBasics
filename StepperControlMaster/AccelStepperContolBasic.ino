#include <AccelStepper.h> // Import the AccelStepper Library, not inculded; must install with IDE

/////////////////////////////////////////////////
// Define Stepper Motor Constants
const int STEPS_PER_REV = 200;  // Number of steps per revolution for your motor (adjustable based on motor specs)

// Pin Definitions for Stepper Motor Driver
const int IN[4] = {8, 9, 10, 11}; // Define the 4 control pins for the motor driver
                                  // Number of pins depends opn what hardware is used to control stepper

// Create an AccelStepper object
AccelStepper stepperMotor(AccelStepper::FULL4WIRE, IN[0], IN[2], IN[1], IN[3]);
/////////////////////////////////////////////////

// Setup Function
void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging

  // Set the maximum speed and acceleration for the stepper motor
  stepperMotor.setMaxSpeed(1000); // Maximum speed in steps per second
  stepperMotor.setAcceleration(500); // Acceleration in steps per second squared
  Serial.println("Stepper Motor Initialized with AccelStepper");
}

/////////////////////////////////////////////////
// Loop Function
void loop() {
  // Example 1: Rotate forward for one revolution
  Serial.println("Rotating forward one revolution...");
  stepperMotor.moveTo(STEPS_PER_REV); // Set target position (1 full revolution forward)
  while (stepperMotor.distanceToGo() != 0) {
    stepperMotor.run(); // Moves the motor step-by-step towards the target
  }
  delay(1000); // Pause for 1 second

  // Example 2: Rotate backward for one revolution
  Serial.println("Rotating backward one revolution...");
  stepperMotor.moveTo(-STEPS_PER_REV); // Set target position (1 full revolution backward)
  while (stepperMotor.distanceToGo() != 0) {
    stepperMotor.run(); // Moves the motor step-by-step towards the target
  }
  delay(1000); // Pause for 1 second

  // Example 3: Rotate forward by half a revolution
  Serial.println("Rotating half revolution forward...");
  stepperMotor.moveTo(STEPS_PER_REV / 2); // Set target position (half revolution forward)
  while (stepperMotor.distanceToGo() != 0) {
    stepperMotor.run(); // Moves the motor step-by-step towards the target
  }
  delay(1000); // Pause for 1 second

  // Example 4: Stop for 2 seconds
  Serial.println("Stopping...");
  delay(2000);
}
