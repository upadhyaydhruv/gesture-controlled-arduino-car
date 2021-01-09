#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);

Servo turret;

int trigPin = (10); // Add the Trig pin on pin 10.
int echoPin = (9); // Add the ECHO pin on pin 9.

int rightDistance = 0;
int leftDistance = 0;

void taskRotateTurret(void *pvParameters);
void taskDrive(void *pvParameters);
int findDistance();

void releaseMotors(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4);
void driveForward(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4);
void driveBackward(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4);
void turnRight(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4);
void turnLeft(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4);

void setup() {
  // put your setup code here, to run once:

  turret.attach(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(10000);

  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);

  releaseMotors(m1, m2, m3, m4);
}

void loop() {
  // put your main code here, to run repeatedly:  
  
  turret.write(40);
  delay(200);
  rightDistance = findDistance();
  turret.write(140);
  delay(200);
  leftDistance = findDistance(); 

  if (rightDistance <= 70 && leftDistance <= 70) {
    driveForward(m1,m2, m3, m4);
  }

  else if (rightDistance >= 20 && leftDistance >= 20) {
    driveBackward(m1, m2, m3, m4);
  }

  if (rightDistance - 3 > leftDistance) {
    turnLeft(m1, m2, m3, m4);
  }

  if (rightDistance + 3 < leftDistance) {
    turnRight(m1, m2, m3, m4);
  }

  
}

int findDistance() {
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  float duration=pulseIn(echoPin,HIGH);
  float currDistance = (duration/2)/29.1;
  return (int)currDistance; 
}

void releaseMotors(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4) {
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void driveForward(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4) {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void driveBackward(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4) {
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void turnRight(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4) {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void turnLeft(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4) {
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}
