#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
long duration, distance;

void setup() {
AFMS.begin();
pinMode(7, OUTPUT);
pinMode(8, INPUT);
Serial.begin(9600);

}

void loop() {
distanceTest();
if(distance < 30 ){
  reverse();
  delay(300);
  right();
  delay(500);
  left();
  delay(500);
} else{
  forwards();
}
}

void forwards(){
rightMotor->setSpeed(150);
leftMotor->setSpeed(150);

rightMotor->run(FORWARD);
leftMotor->run(FORWARD);
}

void right(){
rightMotor->setSpeed(100);
leftMotor->setSpeed(100);

rightMotor->run(BACKWARD);
leftMotor->run(FORWARD);
}
void left(){
rightMotor->setSpeed(90);
leftMotor->setSpeed(90);

rightMotor->run(FORWARD);
leftMotor->run(BACKWARD);
}
void reverse(){
rightMotor->setSpeed(100);
leftMotor->setSpeed(100);

rightMotor->run(BACKWARD);
leftMotor->run(BACKWARD);
}
long distanceTest(){
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  duration = pulseIn(8, HIGH);
  distance = (duration /2 ) / 29.1;
  Serial.print(distance);
  return distance;
}

