#include "motor.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "SimpleTimer.h"

#define AIN1 16
#define AIN2 17

#define BIN1 5
#define BIN2 18

#define enA 4
#define enB 19

#define clp 35
#define near 34

#define L1_S 27 //S1
#define L2_S 26 // S2
#define R1_S 23 //S4
#define R2_S 32 // S5
#define C_S 25 // S3

//#define BLYNK_PRINT Serial

const int offsetA = 1;
const int offsetB = 1;

int count = 0;
int speed = 100;

//BlynkTimer timer;
SimpleTimer timer;

char auth[] = "2V_OEwpvftBfHdhCiHoQvc1nRV4nDuW6"; 
char ssid[] = "chotroihn.vn";  //Enter your WIFI Name
char pass[] = "chotroihn.vn@";  //Enter your WIFI Password

Motor motor1 = Motor(AIN1, AIN2, enA, offsetA);
Motor motor2 = Motor(BIN1, BIN2, enB, offsetB);


void processor()
{
    int s1 = digitalRead(L1_S);  //Left Most Sensor
    int s2 = digitalRead(L2_S);  //Left Sensor
    int s3 = digitalRead(C_S);  //Middle Sensor
    int s4 = digitalRead(R1_S);  //Right Sensor
    int s5 = digitalRead(R2_S);  //Right Most Sensor
//    Serial.println("S1 = ");
//    Serial.println(s1);
//    Serial.println("S2 = ");
//    Serial.println(s2);
//    Serial.println("S3 = ");
//    Serial.println(s3);
//    Serial.println("S4 = ");
//    Serial.println(s4);
//    Serial.println("S5 = ");
//    Serial.println(s5);
    Serial.println("--------------------------------");
    if((s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
    {
    Serial.println ("Moving Forward...");
    forward(motor1, motor2, speed);
    }
    else if ((s2 == 0) && (s4 == 1) && (s5 == 1))
    {
    Serial.println ("Turing Left...");
    left(motor1, motor2, speed);
    }
    else if ((s2 == 1) && ((s4 == 0) || (s5 == 0)))
    {
    Serial.println ("Turning right...");
    right(motor1, motor2, speed);
    }
    else if (( ((s2 == 0) || (s3 == 0)) && ((s4 == 0) || (s5 == 0)) )) 
    {
    Serial.println ("Stop...");
    count += 1;
    brake(motor1, motor2);  
    }   
}


BLYNK_WRITE(V1)
{
  speed = param.asInt(); 
  Serial.println(speed);
}


void setup()
{
	pinMode(L1_S, INPUT);
	pinMode(L2_S, INPUT);
	pinMode(C_S,  INPUT);
	pinMode(R1_S, INPUT);
	pinMode(R2_S, INPUT);
  pinMode(near,INPUT);
  pinMode(clp,INPUT);
	Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
	timer.setInterval(10L, processor);
}


void loop()
{
    Serial.println("Hello my friends!!!");
    if ( !Blynk.connected() )
    {
    Serial.println("wait wat?");
    }
    if(WiFi.status())
    {
      Serial.println("Oki");
    }
    Serial.println ("...");
    Blynk.run();
    timer.run();
}
