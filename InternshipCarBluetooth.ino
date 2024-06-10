#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
char command;

void setup()
{
  Serial.begin(9600);
}

void loop(){
if(Serial.available() > 0){
  command = Serial.read();
  Stop();
    switch(command){
    case 'F':
      forward();
    break;
    case 'B':
      back();
    break;
    case 'L':
      left();
    break;
    case 'R':
      right();
    break;
    }
  }
}

void forward(){
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void back(){
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void left(){
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}
void right(){
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void Stop(){
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}