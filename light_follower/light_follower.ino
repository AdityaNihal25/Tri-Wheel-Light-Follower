int LDR_left = A0;
int LDR_right = A1;

// Left Motor pins
int ENA = 9;
int IN1 = 6;
int IN2 = 7;

// Right Motor pins
int ENB = 10;
int IN3 = 8;
int IN4 = 11;

void setup() {
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftValue = analogRead(LDR_left);
  int rightValue = analogRead(LDR_right);

  Serial.print("Left: "); Serial.print(leftValue);
  Serial.print(" Right: "); Serial.println(rightValue);

  if (abs(leftValue - rightValue) < 50) {
    moveForward(150, 150);
  }
  else if (leftValue > rightValue) {
    // More light on left, slow left motor
    moveForward(100, 150);
  }
  else {
    // More light on right, slow right motor
    moveForward(150, 100);
  }
}

void moveForward(int leftSpeed, int rightSpeed) {
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, leftSpeed);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, rightSpeed);
}
