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

#define L1 27 //S1
#define L2 26 // S2
#define R1 33 //S4
#define R2 32 // S5
#define C 25 // S3

char auth[] = "2V_OEwpvftBfHdhCiHoQvc1nRV4nDuW6"; 
char ssid[] = "Thanh Dat (5G)";  //Enter your WIFI Name
char pass[] = "hm22112000";  //Enter your WIFI Password

SimpleTimer timer;

Motor motor1 = Motor(AIN1, AIN2, enA);
Motor motor2 = Motor(BIN1, BIN2, enB);

byte state = 0;// 0 la dung , 1 la di thang, 2 la ben phai, 3 la ben trai
int count = 0;
int dutyCycle = 250;
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
    if(!digitalRead(C) & digitalRead(L2) & digitalRead(R2))
        state = 1;
      else  if(!digitalRead(L2) & digitalRead(R2)) 
                state = 2;
              else  if(!digitalRead(R2) & digitalRead(L2)) 
                        state = 3;
                          else
                            state = 0;
    Serial.println(state);
    switch(state){
      case 0:
         brake(motor1,motor2);
         count += 1;
         if (count == step_n)
             Serial.print("Da den vi tri can dung"); 
         break;
      case 1:
         forward(motor1,motor2,dutyCycle);
         break;
      case 2:
         right(motor1,motor2,dutyCycle);
         break;
      case 3:
         right(motor1,motor2,dutyCycle);
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
  timer.setInterval(100L,processor);
}

void loop() {
  //Blynk.run();
  timer.run();
}
