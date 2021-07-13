#include "motor.h"
#include <Arduino.h>
//#define analogWrite ledcWrite


Motor::Motor(int In1, int In2, int PWM, int offset)
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(PWM, OUTPUT);
}


void Motor::drive(int speed)
{
  speed = speed * Offset;
  if (speed>=0) fwd(speed);
  else rev(-speed);
}


void Motor::fwd(int speed)
{
   digitalWrite(In1, HIGH);
   digitalWrite(In2, LOW);
   digitalWrite(PWM,HIGH);
   analogWrite(PWM, speed);
}


void Motor::rev(int speed)
{
   digitalWrite(In1, LOW);
   digitalWrite(In2, HIGH);
   digitalWrite(PWM,HIGH);
   analogWrite(PWM, speed);
}


void Motor::brake()
{
   digitalWrite(In1, HIGH);
   digitalWrite(In2, HIGH);
   //analogWrite(PWM,0);
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
	int temp = abs(speed)/2;
	left.drive(-temp);
	right.drive(temp);
	
}


void right(Motor left, Motor right, int speed)
{
	int temp = abs(speed)/2;
	left.drive(temp);
	right.drive(-temp);
}


void brake(Motor motor1, Motor motor2)
{
	motor1.brake();
	motor2.brake();
}
