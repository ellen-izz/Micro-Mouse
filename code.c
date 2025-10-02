#include <Servo.h>
Servo ser;

const int enA = 3;
const int in1 = 12;
const int enB = 11;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;
const int echoPin = 8;
const int trigPin = 2;
const int servoPin = A0;
const int obsdis = 30;  
const int btn = 4;

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(btn, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  ser.attach(servoPin);
  ser.write(140);  // face forward

  analogWrite(enA, 140);
  analogWrite(enB, 200);
}

void loop() {
  int state = digitalRead(btn);

  if (!state) {  
    int frontDist = getDistance();
    if (frontDist > obsdis) {
      ser.write(140);  
      moveForward();
    } else {
      avoid();
    }
  } else {
    stopMotors(); 
  }
}
void avoid() {
  stopMotors();
  delay(200);

  // Back up
  moveBackward();
  delay(500);
  stopMotors();
  delay(200);

  // Look left first
  ser.write(50);  // turn servo left
  delay(300);
  int leftDist = getDistance();

  // If left is clear go left
  if (leftDist > obsdis) {
    moveForward();
    delay(600);     // commit left
    stopMotors();
    ser.write(140);   // reset straight
    return;
  }

  // Else check right
  ser.write(230);   // turn servo right
  delay(300);
  int rightDist = getDistance();

  if (rightDist > obsdis) {
    moveForward();
    delay(600);   // commit right
    stopMotors();
    ser.write(140);   // reset straight
    return;
  }

  // Both sides blocked back up again
  moveBackward();
  delay(700);
  stopMotors();
  ser.write(140);   // reset straight
}



void moveForward() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
}

void moveBackward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW);  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, LOW);
}

void turnLeft() {
  ser.write(50);       
  moveForward();      
  delay(500);          
  stopMotors();
}

void turnRight() {
  ser.write(230);      
  moveForward();       
  delay(500);         
  stopMotors();
}


int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);  // timeout 30ms
  if (duration == 0) {
    return 1000;  // no reading → assume far away
  }
  return duration / 29 / 2; // convert to cm
}
