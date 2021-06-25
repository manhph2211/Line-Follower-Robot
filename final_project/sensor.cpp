#include "Arduino.h"
#include<sensor.h>

sensor::sensor(int numbOfSens, double* thresholds, int* pins){
    this->numOfSens = numOfSens;
    this->thresholds = thresholds;
    this->sensorValues = new int [numOfSens];
    this->pins = pins;
}
void sensor::read(){
    for(i=0;i<=this->numOfSens,i++){
        double val = analogRead(this->pins[i]);
        if (val > this->thresholds[i]){
            this->sensorValues[i] = 1;
        }
        else this->sensorValues[i] = 0;
    }
}
