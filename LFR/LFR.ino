#include "motor.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "SimpleTimer.h"

#define AIN1 18
#define AIN2 5

#define BIN1 16
#define BIN2 17

#define enA 19
#define enB 4

#define clp 35
#define near 34

#define L2 27 //S1
#define L1 26 // S2
#define R1 33 //S4
#define R2 32 // S5
#define C 25 // S3

char auth[] = "KOLz6MhYtf3-HApAMiDnevnkRJyGgNLy"; 
char ssid[] = "Thanh Dat(5G)";  //Enter your WIFI Name
char pass[] = "hm22112000";  //Enter your WIFI Password

SimpleTimer timer;

Motor motor1 = Motor(AIN1, AIN2, enA);
Motor motor2 = Motor(BIN1, BIN2, enB);

byte state = 1;// 0 : Stop , 1 : Forward, 2 : Right, 3 : Left
int count = 0;
int dutyCycle = 150;
int step_n = 3 ;
/*
BLYNK_WRITE(V1)
{
  dutyCycle = param.asInt(); 
  Serial.println(dutyCycle);
}

BLYNK_WRITE(V2)
{
  step_n = param.asInt(); 
  Serial.println(step_n);
}
*/
void processor(){
    if(!digitalRead(C))
        state = 1;
      else  if(!digitalRead(R2) | !digitalRead(R1)) 
                state = 2;
              else  if(!digitalRead(L2) | !digitalRead(L1)) 
                        state = 3;
                          else if(!digitalRead(C) & !digitalRead(L2) & !digitalRead(L1) & !digitalRead(R1) & !digitalRead(R2))
                                     {
                                       count += 1;
                                       if (count == step_n)
                                         {    
                                             state = 0; 
                                             Serial.print("Finished");
                                         }
                                       else
                                         state = 1;
                                     }
    switch(state){
      case 0:
         brake(motor1,motor2);
         Serial.println("Stop");
         break;
      case 1:
         forward(motor1,motor2,dutyCycle);
         Serial.println("Moving Forward");
         break;
      case 2:
         right(motor2,motor1,dutyCycle);
         Serial.println("Turning Right");
         break;
      case 3:
         left(motor2,motor1,dutyCycle);
         Serial.println("Turning Left");
         break; 
      default: break;     
    }
    
}

void setup() {
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(C,  INPUT);
  pinMode(R1, INPUT);
  pinMode(R2, INPUT);
  pinMode(near,INPUT);
  pinMode(clp,INPUT);
  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass); 
  timer.setInterval(80L,processor);
}

void loop() {
  Serial.println("Hello my friends!!!");
  if ( !Blynk.connected() )
  {
  Serial.println("wait wat?");
  }
  //Blynk.run();
  timer.run();
}
