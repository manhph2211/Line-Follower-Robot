#include "motor.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "SimpleTimer.h"

#define AIN1 5
#define BIN1 18

#define AIN2 21
#define BIN2 17

#define enA 23
#define enB 22

#define clp 32
#define near 35

#define L1_S 23
#define L2_S 25
#define R1_S 26
#define R2_S 27
#define C_S 14

const int offsetA = 1;
const int offsetB = 1;

int count = 0;
int speed = 254;

SimpleTimer timer;

char auth[] = ""; 
char ssid[] = "TANG 2";  //Enter your WIFI Name
char pass[] = "123456a@";  //Enter your WIFI Password

Motor motor1 = Motor(AIN1, AIN2, enA, offsetA);
Motor motor2 = Motor(BIN1, BIN2, enB, offsetB);


BLYNK_WRITE(V1)
{
	speed = param.asFloat(); 
}


void processor()
{
    int s1 = digitalRead(L1_S);  //Left Most Sensor
    int s2 = digitalRead(L2_S);  //Left Sensor
    int s3 = digitalRead(C_S);  //Middle Sensor
    int s4 = digitalRead(R1_S);  //Right Sensor
    int s5 = digitalRead(R2_S);  //Right Most Sensor
    Serial.println(s3);
    if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
    {
    Serial.println ("Moving Forward...");
    forward(motor1, motor2, speed);
    }
    if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0))
    {
    Serial.println ("Moving Forward...");
    forward(motor1, motor2, speed);
    }
    else if ((s1 == 1) || (s2 == 1) && (s4 == 0) && (s5 == 0))
    {
    Serial.println ("Turing Left...");
    left(motor1, motor2, speed);
    }
    else if ((s1 == 0) && (s2 == 0) && ((s4 == 1) || (s5 == 1)))
    {
    Serial.println ("Turning right...");
    right(motor1, motor2, speed);
    }
    else if (((s1 == 1) || (s2 == 1)) && (s3 == 1) && ((s4 == 1) || (s5 == 1)))
    {
    Serial.println ("Stop...");
    count += 1;
    brake(motor1, motor2);  
    }   
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
//	Blynk.begin(auth, /ssid, pass);
	timer.setInterval(1000L, processor);
}


void loop()
{
//    fo/rward(motor1, motor2, speed);
    delay(1000);
//  Blynk.run(); /
  	timer.run();
}
