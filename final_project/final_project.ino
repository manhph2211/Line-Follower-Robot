#include "motor.h"

#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 10
#define PWMB 11
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

int convert(int x){
    if (x>512) 
        x = 1;
    else x = 0;
    return x;
}

int check(int a,int b)
{   
    a = convert(a);
    b = convert(b);
   if(a==1||b==1)
      return 0;
   else
      return 1; 
}


void loop()
{

//   if ( check(analogRead(L1_S),analogRead(L2_S)) && check(analogRead(R1_S),analogRead(R2_S)) && convert(analogRead(C_S)) == 1)
//   {
   digitalWrite(A0,0);
   digitalWrite(A1,0);
   digitalWrite(A2,1);
   digitalWrite(A3,0);
   digitalWrite(A4,0);
   forward(motor1, motor2, 150);
   delay(1000);
//   }

   //back(motor1, motor2, -150);
   //delay(1000);
   
//   brake(motor1, motor2);
//   delay(1000);
//   
//   if (!check(analogRead(L1_S),analogRead(L2_S)) && check(analogRead(R1_S),analogRead(R2_S)) && convert(analogRead(C_S)) == 1)
//   {
//   left(motor1, motor2, 100);
//   delay(1000);
//   }
//
//   if (check(analogRead(L1_S),analogRead(L2_S)) && !check(analogRead(R1_S),analogRead(R2_S)) && convert(analogRead(C_S)) == 0)
//   {
//   right(motor1, motor2, 100);
//   delay(1000);
//   }
//
//   if (!check(analogRead(L1_S),analogRead(L2_S)) && !check(analogRead(R1_S),analogRead(R2_S)) && convert(analogRead(C_S)) == 0)
//   {
//   dem += 1;
//   delay(1000); 
//   }

   
}
