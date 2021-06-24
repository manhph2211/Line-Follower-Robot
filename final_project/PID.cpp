#include "Arduino.h"
#include <PID.h>
/* constuctor */
PID::PID(double* Input, double* Output, double* Setpoint, double Kp, double Ki, double Kd){
    myInput = Input;
    myOutput = Output;
    setPoint = Setpoint;


    PID::setTunings(Kp, Ki, Kd);
    PID::setOutputLimits(0,1023);
    sampleTime = 100; // set default sampling rate = 10 times per second
    lastRecordedTime = millis() - sampleTime;
}
/* compute the output of PID control */
bool PID::calculate(){
    unsigned long currentTime = millis();
    unsigned long timeGap = currentTime - lastRecordedTime;
    if (timeGap > sampleTime){
        double input = *myInput;
        double error = *setPoint - input;
        double dif = input - lastInput;
        
        
        double output;
        output = kp*error + ki*error - kd*dif;

        if (output>maxLimit) output = maxLimit;
        elseif (output<minLimit) output = minLimit;

        *myOutput = output;

        lastInput = input;
        lastRecordedTime = currentTime;
        return true;
    }
    else return false;
}
/* Set output limit of PWM - default of esp32: 0-1023 <--> 10 bits resolution  */
void PID::setOutputLimits(double min, double Max){
    if (min >= Max){
        return;
    };
    minLimit = min;
    maxLimit = Max;
}
/* modify the PID controller configuration */
void PID::setTunings(double Kp, double Ki, double Kd){
    if (Kp<0 || Ki<0 || Kd<0) return;
    double sampleTimeInSecond = (double)sampleTime/1000;
    kp = Kp;
    ki = Ki * sampleTimeInSecond;
    kd = Kd / sampleTimeInSecond;
}
/* set sampling time in miliseconds */
void PID::setSampleTime(unsigned long newSampleTime){
    double ratio = (double)newSampleTime / (double)sampleTime;
    ki *= ratio;
    kd /= ratio;
    sampleTime = (unsigned long)newSampleTime;
}