// Define the pins connected to L298N
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Step sequence for 4-phase stepper motor
int stepSequence[8][4] = {
  {1, 0, 1, 0},  // Step 1
  {0, 1, 1, 0},  // Step 2
  {0, 1, 0, 1},  // Step 3
  {1, 0, 0, 1},  // Step 4
  {1, 0, 1, 0},  // Step 5
  {0, 1, 1, 0},  // Step 6
  {0, 1, 0, 1},  // Step 7
  {1, 0, 0, 1}   // Step 8
};

void setup() {
  // Set motor control pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("NEMA17 working");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    // input command for vial 1
    if (command == "first") {
      // Rotate the stepper motor clockwise
      for (int i = 0; i < 200; i++) {
        stepMotor(1);
        delay(10); // Adjust delay to control speed
        }

      Serial.println("first vial filled");
      delay(2000); // Wait for 1 second

      // Rotate the stepper motor counterclockwise
      for (int i = 0; i < 200; i++) {
        stepMotor(-1);
        delay(10); // Adjust delay to control speed
        }
      delay(1000); // Wait for 1 second

      Serial.println("needle washed");
    }

    // input command for vial 2
    else if (command == "second") {
      // Rotate the stepper motor clockwise
      for (int i = 0; i < 400; i++) {
        stepMotor(1);
        delay(10); // Adjust delay to control speed
        }

      Serial.println("second vial filled");
      delay(2000); // Wait for 1 second

      // Rotate the stepper motor counterclockwise
      for (int i = 0; i < 400; i++) {
        stepMotor(-1);
        delay(10); // Adjust delay to control speed
        }
      delay(1000); // Wait for 1 second

      Serial.println("needle washed");
    }

    // input command for vial 3
    else if (command == "third") {
      // Rotate the stepper motor clockwise
      for (int i = 0; i < 600; i++) {
        stepMotor(1);
        delay(10); // Adjust delay to control speed
        }

      Serial.println("third vial filled");
      delay(2000); // Wait for 1 second

      // Rotate the stepper motor counterclockwise
      for (int i = 0; i < 600; i++) {
        stepMotor(-1);
        delay(10); // Adjust delay to control speed
        }
      delay(1000); // Wait for 1 second

      Serial.println("needle washed");
    }

    // input command for vial 4
    else if (command == "fourth") {
      // Rotate the stepper motor clockwise
      for (int i = 0; i < 800; i++) {
        stepMotor(1);
        delay(10); // Adjust delay to control speed
        }

      Serial.println("fourth vial filled");
      delay(2000); // Wait for 1 second

      // Rotate the stepper motor counterclockwise
      for (int i = 0; i < 800; i++) {
        stepMotor(-1);
        delay(10); // Adjust delay to control speed
        }
      delay(1000); // Wait for 1 second

      Serial.println("needle washed");
    }

    // input command for vial 5
    else if (command == "fifth") {
      // Rotate the stepper motor clockwise
      for (int i = 0; i < 1000; i++) {
        stepMotor(1);
        delay(10); // Adjust delay to control speed
        }

      Serial.println("fifth vial filled");
      delay(2000); // Wait for 1 second

      // Rotate the stepper motor counterclockwise
      for (int i = 0; i < 1000; i++) {
        stepMotor(-1);
        delay(10); // Adjust delay to control speed
        }
      delay(1000); // Wait for 1 second

      Serial.println("needle washed");
    }

    else {
      Serial.println("Invalid command. No more vials");
    }
  }
}

void stepMotor(int direction) {
  static int stepIndex = 0;

  // Update stepIndex based on direction
  if (direction > 0) {
    stepIndex++;
    if (stepIndex >= 8) stepIndex = 0;
  } else if (direction < 0) {
    stepIndex--;
    if (stepIndex < 0) stepIndex = 7;
  }

  // Set the motor pins according to the step sequence
  digitalWrite(IN1, stepSequence[stepIndex][0]);
  digitalWrite(IN2, stepSequence[stepIndex][1]);
  digitalWrite(IN3, stepSequence[stepIndex][2]);
  digitalWrite(IN4, stepSequence[stepIndex][3]);
}


