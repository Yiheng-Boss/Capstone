// Define pins for Motor Right
const int pwmPinR = 11;     // PWM pin for motor A
const int dirPinR = 10;     // Direction pin for motor A

// Define pins for Motor Left
const int pwmPinL = 6;    // PWM pin for motor B
const int dirPinL = 9;     // Direction pin for motor B

void setup() {
    // Set motor pins as outputs
    pinMode(pwmPinR, OUTPUT);
    pinMode(dirPinR, OUTPUT);
    
    pinMode(pwmPinL, OUTPUT);
    pinMode(dirPinL, OUTPUT);
}

// Function to control a motor1
void controlMotor(int pwmPin, int dirPin, int speed, bool direction) {
    digitalWrite(dirPin, direction);  // Set direction
    analogWrite(pwmPin, speed);       // Set speed (0-255)
}

void loop() {
    // Example: Move forward
    controlMotor(pwmPinR, dirPinR, 100, true);  // Motor A forward
    controlMotor(pwmPinL, dirPinL, 100, true);  // Motor B forward
    delay(2000);  // Move for 2 seconds

    /*// Example: Move backward
    controlMotor(pwmPinR, dirPinR, 200, false); // Motor A backward
    controlMotor(pwmPinL, dirPinL, 200, false); // Motor B backward
    delay(2000);  // Move for 2 seconds
    

    // Example: Stop
    controlMotor(pwmPinR, dirPinR, 0, true);    // Stop motor A
    controlMotor(pwmPinL, dirPinL, 0, true);    // Stop motor B
    delay(1000);  // Wait for 1 second
    */
}
