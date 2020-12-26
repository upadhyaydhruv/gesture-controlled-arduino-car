// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h> 

// DC motor on M1 and M2

class Car {
  public:
  void driveAhead();
  double leftSpeed;
  double rightSpeed;

  void setLeftSpeed(double leftSpeedIn){
    motor3.setSpeed(leftSpeedIn);
    motor4.setSpeed(leftSpeedIn);
  }

  void setRightSpeed(double rightSpeedIn) {
    motor1.setSpeed(rightSpeedIn);
    motor2.setSpeed(rightSpeedIn);
  }

  Car(){
    AF_DCMotor motor1(1, 0);
    AF_DCMotor motor2(2, 0);
    AF_DCMotor motor3(3, 0);
    AF_DCMotor motor4(4, 0);
  }
  void move(bool isForward, double speed){
    speed *= isForward;
    this->release();
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    motor3.setSpeed(speed);
    motor4.setSpeed(speed);
  }

  void turn(double location){
    motor1.set
  }

  void release(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    
  }

  

  private:
  AF_DCMotor motor1;
  AF_DCMotor motor2;
  AF_DCMotor motor3;
  AF_DCMotor motor4;
  
}


void setup() {   
  // turn on motor #2
  motor1.setSpeed(200);
  motor1.run(RELEASE);

  motor2.setSpeed(200);
  motor2.run(RELEASE);

  motor3.setSpeed(200);
  motor3.run(RELEASE);

  motor4.setSpeed(200);
  motor4.run(RELEASE);

  delay(10000);
}

void loop() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(3000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(3000);
}
