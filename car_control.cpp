#include <AFMotor.h>

void releaseMotors(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4);
void updateSpeed(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4, double leftPower, double RightPower);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  if (Serial.available()){
    // update the speed based on the data received from the master transmitter  
  }
}

void updateSpeed(AF_DCMotor &m1, AF_DCMotor &m2, AF_DCMotor &m3, AF_DCMotor &m4, double leftPower, double RightPower) {
  releaseMotors(m1, m2, m3, m4);
  double leftPowerMapped = map(leftPower, -127, 128, 0, 255);
  double rightPowerMapped = map(rightPower, -127, 128, 0, 255);
  if (leftPower<0){
    m1.run(BACKWARD);
    m2.run(BACKWARD);
  }
  else {
    m1.run(FORWARD);
    m2.run(FORWARD);
  }
  if (rightPower < 0) {
    m3.run(BACKWARD);
    m4.run(BACKWARD);
  }
  else {
    m3.run(FORWARD);
    m4.run(FORWARD);
  }

  m1.setSpeed(leftPowerMapped);
  m2.setSpeed(leftPowerMapped);
  m3.setSpeed(rightPowerMapped);
  m4.setSpeed(rightPowerMapped);
}
