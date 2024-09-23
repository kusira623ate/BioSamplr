// Pin definitions for motor control
int in1 = 5;  // Motor input 1 (connected to IN1 on motor driver)
int in2 = 4;  // Motor input 2 (connected to IN2 on motor driver)
// int enA = 9;  // PWM pin to control motor speed

void setup() {
  // Set the motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // pinMode(enA, OUTPUT);
}

void loop() {
  // Turn on the peristaltic pump (forward direction)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // analogWrite(enA, 255);  // Full speed
  delay(5000);  // Pump runs for 5 seconds
  
  // Stop the pump
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // analogWrite(enA, 0);
  delay(1000);  // Wait for 1 second
  
  // // Reverse the pump direction (fluid out)
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);
  // analogWrite(enA, 255);  // Full speed
  // delay(5000);  // Pump runs in reverse for 5 seconds
  
  // // Stop the pump again
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, LOW);
  // analogWrite(enA, 0);
  // delay(1000);  // Wait before the next cycle
}

