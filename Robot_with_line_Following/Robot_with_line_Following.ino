// Define pins for Motor Right
const int pwmPinR = 11;     // PWM pin for motor A
const int dirPinR = 10;     // Direction pin for motor A

// Define pins for Motor Left
const int pwmPinL = 6;    // PWM pin for motor B
const int dirPinL = 9;     // Direction pin for motor B

// Line Sensor Pins
const int sensorPins[] = {A1, A2, A3, A4, A5};  // LSS05 pins: OUT1 to OUT5
int sensorValues[5];                        // Array to store sensor readings

void setup() {
    // Set motor pins as outputs
    pinMode(pwmPinR, OUTPUT);
    pinMode(dirPinR, OUTPUT);
    
    pinMode(pwmPinL, OUTPUT);
    pinMode(dirPinL, OUTPUT);

    // Set up line sensor pins
    for (int i = 0; i < 5; i++) {
        pinMode(sensorPins[i], INPUT);
    }
}

// Function to control a motor1
void controlMotor(int pwmPin, int dirPin, int speed, bool direction) {
    if (direction) {
        digitalWrite(dirPin, LOW);  // LOW might mean "forward" for your motor driver
    } else {
        digitalWrite(dirPin, HIGH); // HIGH might mean "backward"
    }
    analogWrite(pwmPin, speed);       // Set speed (0-255)
}

void loop() {
    // Read sensor values
    for (int i = 0; i < 5; i++) {
        sensorValues[i] = digitalRead(sensorPins[i]);
    }
    // Line-following logic
    if (sensorValues[2] == LOW) {  // Center sensor active (aligned with line)
        controlMotor(pwmPinL, dirPinL, 200, true);  // Move forward
        controlMotor(pwmPinR, dirPinR, 200, true);
    } 
    else if (sensorValues[0] == LOW || sensorValues[1] == LOW) {  // Left sensors active
        controlMotor(pwmPinL, dirPinL, 150, false); // Slow/Reverse left motor
        controlMotor(pwmPinR, dirPinR, 200, true);  // Normal forward right motor
    } 
    else if (sensorValues[3] == LOW || sensorValues[4] == LOW) {  // Right sensors active
        controlMotor(pwmPinL, dirPinL, 200, true);  // Normal forward left motor
        controlMotor(pwmPinR, dirPinR, 150, false); // Slow/Reverse right motor
    } 
    else {  // No sensors detect the line
        controlMotor(pwmPinL, dirPinL, 0, true);  // Stop motors
        controlMotor(pwmPinR, dirPinR, 0, true);
    }

    delay(50);  // Small delay for stability
}