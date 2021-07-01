#ifndef SPARKFUN_TB6612_h
#define SPARKFUN_TB6612_h
#include <Arduino.h>
#define analogWrite ledcWrite
//used in some functions so you don't have to send a speed
#define DEFAULTSPEED 255  


class Motor
{
  public:

    Motor(int In1pin, int In2pin, int PWMpin, int offset);      
    void drive(int speed);  
    void brake(); 
	
  private:
	int In1, In2, PWM, Offset;
	void fwd(int speed);
	void rev(int speed);
};

void forward(Motor motor1, Motor motor2, int speed);
void forward(Motor motor1, Motor motor2);
void back(Motor motor1, Motor motor2, int speed);
void back(Motor motor1, Motor motor2);
void left(Motor left, Motor right, int speed);
void right(Motor left, Motor right, int speed);
void brake(Motor motor1, Motor motor2);

#endif
