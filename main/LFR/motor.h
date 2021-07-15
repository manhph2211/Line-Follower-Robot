#include <Arduino.h>

#ifndef L298
#define L298
#define DEFAULTSPEED 255  


class Motor
{
  public:

    Motor(int, int, int);      
    void drive(int speed);  
    void brake(); 
	
  private:
	int In1, In2, PWM;
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
