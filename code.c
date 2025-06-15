// Motor A
const int enA = 9;
const int in1 = 4;
const int in2 = 5;

// Motor B
const int enB = 10;
const int in3 = 6;
const int in4 = 7;

// Ultrasonic sensors
const int echo1 = 8;
const int trig1 = 2;
const int echo2 = 12;
const int trig2 = 13;
const int echo3 = 3;
const int trig3 = 11;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);

  analogWrite(enA, 255); 
  analogWrite(enB, 255);  

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.begin(9600);
  delay(150);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return microsecondsToCentimeters(duration);
}

void loop() {
  int cm1 = getDistance(trig1, echo1); // left
  int cm2 = getDistance(trig2, echo2); // right
  int cm3 = getDistance(trig3, echo3); // forward

  Serial.print("S1: ");
  Serial.print(cm1);
  Serial.print(" cm   S2: ");
  Serial.print(cm2);
  Serial.print(" cm   S3: ");
  Serial.println(cm3);

  if (cm3 < 20) {
    stop();
    delay(100);
    if (cm1 > cm2 && cm2 < 20) {
      left();
    } else if (cm2 > cm1 && cm1 < 20) {
      right();
    } else {
      back();
    }
  } else if (cm1 < 20) {
    stop();
    delay(100);
    right();
  } else if (cm2 < 20) {
    stop();
    delay(100);
    left();
  } else {
    forward();
  }

  delay(150); 
}

// Motor control functions
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void back() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
