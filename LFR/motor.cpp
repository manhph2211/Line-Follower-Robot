#include "motor.h"
#include <Arduino.h>
const int freq = 1500;
const int ledChannel = 0;
const int resolution = 8;

Motor::Motor(int In1pin, int In2pin, int PWMpin)
{
  In1 = In1pin;
  In2 = In2pin;
  PWM = PWMpin;
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(PWM, OUTPUT);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(PWM, ledChannel);
}

void Motor::drive(int speed)
{
  if (speed>=0) fwd(speed);
  else rev(-speed);
}

void Motor::fwd(int speed)
{
   ledcWrite(ledChannel, speed);
   digitalWrite(In1,HIGH);
   digitalWrite(In2,LOW);
}

void Motor::rev(int speed)
{
   ledcWrite(ledChannel, speed);
   digitalWrite(In1, LOW);
   digitalWrite(In2, HIGH);   
}

void Motor::brake()
{
   //ledcWrite(ledChannel, speed);
   digitalWrite(In1,LOW);
   digitalWrite(In2,LOW);
}
 
void forward(Motor motor1, Motor motor2, int speed)
{
	motor1.drive(speed);
	motor2.drive(speed);
}

void forward(Motor motor1, Motor motor2)
{
	motor1.drive(DEFAULTSPEED);
	motor2.drive(DEFAULTSPEED);
}

void back(Motor motor1, Motor motor2, int speed)
{
	int temp = abs(speed);
	motor1.drive(-temp);
	motor2.drive(-temp);
}

void back(Motor motor1, Motor motor2)
{
	motor1.drive(-DEFAULTSPEED);
	motor2.drive(-DEFAULTSPEED);
}

void left(Motor left, Motor right, int speed)
{
	int temp = abs(speed/2);
	left.drive(-temp);
	right.drive(temp);
	
}

void right(Motor left, Motor right, int speed)
{
	int temp = abs(speed/2);
	left.drive(temp);
	right.drive(-temp);
}

void brake(Motor motor1, Motor motor2)
{
	motor1.brake();
	motor2.brake();
}
