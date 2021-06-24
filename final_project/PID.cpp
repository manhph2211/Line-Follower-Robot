#include "Arduino.h"
#include <PID.h>

PID::PID(double* Input, double* Output, double* Setpoint, double Kp, double Ki, double Kd){
    myInput = Input;
    myOutput = Output;
    setPoint = Setpoint;

    PID::setTunings(Kp, Ki, Kd);

}
bool PID::Compute(){
    unsigned long currentTime = millis();
    unsigned long timeGap = currentTime - lastRecordedTime;
    if (timeGap > sampleTime){
        double input = *myInput;
        double error = *setPoint - input;
        double dInput = input - lastInput;
        outputSum += ki * error;
    }
}
void PID::setOutputLimits(double min, double Max){
    if (min >= Max){
        return;
    };
    minLimit = min;
    maxLimit = Max;
}
void PID::setTunings(double Kp, double Ki, double Kd){
    if (Kp<0 || Ki<0 || Kd<0) return;
    double sampleTimeInSecond = (double)sampleTime/1000;
    kp = Kp;
    ki = Ki * sampleTimeInSecond;
    kd = Kd / sampleTimeInSecond;
}
void PID::setSampleTime(unsigned long newSampleTime){
    double ratio = (double)newSampleTime / (double)sampleTime;
    ki *= ratio;
    kd /= ratio;
    sampleTime = (unsigned long)newSampleTime;
}