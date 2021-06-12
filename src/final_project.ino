#include "motor.h"

#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

#define L1_S A1 
#define L2_S A0
#define R1_S A3 
#define R2_S A4
#define C_S A2

const int offsetA = 1;
const int offsetB = 1;
int dem = 0;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup()
{
pinMode(L1_S, INPUT);
pinMode(L2_S, INPUT);
pinMode(C_S,  INPUT);
pinMode(R1_S, INPUT);
pinMode(R2_S, INPUT);
}

int check(int a,int b)
{
   if(a==1||b==1)
      return 0;
   else
      return 1; 
}


void loop()
{

   if ( check(digitalRead(L1_S),digitalRead(L2_S)) && check(digitalRead(R1_S),digitalRead(R2_S)) && digitalRead(L2_S) == 1)
   {
   forward(motor1, motor2, 150);
   delay(1000);
   }

   //back(motor1, motor2, -150);
   //delay(1000);
   
   brake(motor1, motor2);
   delay(1000);
   
   if (!check(digitalRead(L1_S),digitalRead(L2_S)) && check(digitalRead(R1_S),digitalRead(R2_S)) && digitalRead(L2_S) == 1)
   {
   left(motor1, motor2, 100);
   delay(1000);
   }

   if (check(digitalRead(L1_S),digitalRead(L2_S)) && !check(digitalRead(R1_S),digitalRead(R2_S)) && digitalRead(L2_S) == 0)
   {
   right(motor1, motor2, 100);
   delay(1000);
   }

   if (!check(digitalRead(L1_S),digitalRead(L2_S)) && !check(digitalRead(R1_S),digitalRead(R2_S)) && digitalRead(L2_S) == 0)
   {
   dem += 1;
   delay(1000); 
   }

   
}