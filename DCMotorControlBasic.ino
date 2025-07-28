
/////////////////////////////////////////////////
// Pin Definitions
const int IN1 = 9;  // Motor driver input pin 1
const int IN2 = 10; // Motor driver input pin 2
const int ENA = 11; // Enable pin for motor speed control (PWM)
/////////////////////////////////////////////////

// Setup Function
void setup() {
  // Start serial communication for debugging (optional)
  Serial.begin(9600);
  Serial.println("DC Motor Control Initialized");
  
  // Initialize motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

/////////////////////////////////////////////////
// Loop Function
void loop() {
  // Example: Rotate the motor forward
  Serial.println("Motor rotating forward...");
  digitalWrite(IN1, HIGH);  // Set IN1 HIGH
  digitalWrite(IN2, LOW);   // Set IN2 LOW
  analogWrite(ENA, 128);    // Set speed (PWM: 0-255, 128 = ~50% speed)
  delay(2000);              // Run for 2 seconds

  // Example: Rotate the motor backward
  Serial.println("Motor rotating backward...");
  digitalWrite(IN1, LOW);   // Set IN1 LOW
  digitalWrite(IN2, HIGH);  // Set IN2 HIGH
  analogWrite(ENA, 200);    // Set speed (PWM: 200 for faster speed)
  delay(2000);              // Run for 2 seconds

  // Stop the motor
  Serial.println("Stopping motor...");
  digitalWrite(IN1, LOW);   // Stop motor by setting both IN1 and IN2 LOW
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);      // Set speed to 0, not technically needed
  delay(2000);              // Wait for 2 seconds before repeating
}