#include <Servo.h>
Servo ser;
const int enA= 4;
const int in1 = 12;
const int enB= 11;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;
const int echoPin = 8;
const int trigPin = 2;
const int servoPin = A0;
const int obsdis=30;

void setup(){
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  ser.attach(servoPin);
  ser.write(90);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}

void loop(){
  int frontDistance = getDistance();
  if (frontDistance > obsdis) {
    ser.write(90);
    moveForward();
  }
  else{
    avoid();
  }
}

void avoid(){
  stopMotors();
  delay(200);
  ser.write(0);
  delay(500);
  int leftDist = getDistance();
  if (leftDist > obsdis) {
    turnLeft();
    return; 
  }
  ser.write(180);
  delay(500);
  int rightDist = getDistance();
  if (rightDist > obsdis) {
    turnRight();
    return;
  }
  moveBackward();
  delay(600);
  stopMotors();
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
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH); 
  delay(500);
  stopMotors();
}
void turnRight() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);  
  delay(500);
  stopMotors();
}
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) {
    return 1000;
  }
  return duration / 29 / 2; 
}
