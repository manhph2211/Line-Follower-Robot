#include "Arduino.h"
#include<sensor.h>

sensor::sensor(int numbOfSens, double* thresholds, int* pins){
    this->numOfSens = numOfSens;
    this->thresholds = thresholds;
    this->sensorValues = new int [numOfSens];
    this->outputs = new int[numbOfSens];
    this->pins = pins;
}
void sensor::read(){
    for(i=0;i<=this->numOfSens,i++){
        double val = analogRead(this->pins[i]);
    }
}
void sensor::encode(){
    for (i=0;i<this->numOfSens,i++){
        if(this->sensorValues[i]>this->thresholds[i]){
            this->outputs[i] = 1;
        }
        else this->outputs[i] = 0;
    }
}