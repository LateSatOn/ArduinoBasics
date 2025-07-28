#include <MultiStepper.h> // Import the MultiStepper Library, not included by default; must be installed through the Arduino IDE Library Manager.

/////////////////////////////////////////////////
// Define Stepper Motor Constants
const int STEPS_PER_REV = 200;  // Number of steps per revolution for your motor (adjustable based on motor specs)

// Pin Definitions for Stepper Motor Driver (Driver type with STEP and DIR pins)
const int STEP_PIN[2] = {8,9};
const int DIR_PIN[2] = {10,11};

// Create AccelStepper objects for driver-controlled motors (2 pins: STEP and DIR)
AccelStepper stepper[2];
AccelStepper stepper[0](AccelStepper::DRIVER, STEP_PIN[0], DIR_PIN[0]);
AccelStepper stepper[1](AccelStepper::DRIVER, STEP_PIN[1], DIR_PIN[1]);

// Create a MultiStepper object to control multiple steppers simultaneously
MultiStepper multiStepper;
/////////////////////////////////////////////////

// Setup Function
void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging

  // Set the maximum speed and acceleration for each stepper motor
  stepper[0].setMaxSpeed(1000);  // Max speed for motor 1 in steps per second
  stepper[0].setAcceleration(500);  // Acceleration for motor 1 in steps per second squared
  
  stepper[1].setMaxSpeed(1000);  // Max speed for motor 2 in steps per second
  stepper[1].setAcceleration(500);  // Acceleration for motor 2 in steps per second squared

  // Add stepper motors to the MultiStepper object for synchronized control
  multiStepper.addStepper(stepper[0]);
  multiStepper.addStepper(stepper[1]);

  Serial.println("MultiStepper Motors Initialized with DRIVER type");
}

/////////////////////////////////////////////////
// Loop Function
void loop() {
  // Create an array of target positions for each motor
  long targetPositions[2];

  // Example 1: Move both motors forward
  targetPositions[0] = STEPS_PER_REV;  // Move motor 1 one full revolution
  targetPositions[1] = STEPS_PER_REV;  // Move motor 2 one full revolution
  Serial.println("Moving both motors forward...");
  multiStepper.moveTo(targetPositions);  // Move both motors to their target positions
  multiStepper.run(); // Execute the movement
  delay(1000); // Pause for 1 second

  // Example 2: Move both motors backward
  targetPositions[0] = -STEPS_PER_REV; // Move motor 1 one full revolution backward
  targetPositions[1] = -STEPS_PER_REV; // Move motor 2 one full revolution backward
  Serial.println("Moving both motors backward...");
  multiStepper.moveTo(targetPositions);  // Move both motors to their target positions
  multiStepper.run(); // Execute the movement
  delay(1000); // Pause for 1 second

  // Example 3: Move motor 1 forward and motor 2 backward
  targetPositions[0] = STEPS_PER_REV;  // Move motor 1 forward
  targetPositions[1] = -STEPS_PER_REV; // Move motor 2 backward
  Serial.println("Moving motor 1 forward and motor 2 backward...");
  multiStepper.moveTo(targetPositions);  // Move both motors to their target positions
  multiStepper.run(); // Execute the movement
  delay(1000); // Pause for 1 second

  // Stop for 2 seconds
  Serial.println("Stopping...");
  delay(2000);
}