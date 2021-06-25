#ifndef sensor_h
#define sensor_h

class sensor{
    private:
        int numOfSens;
        double* thresholds;
        int* sensorValues;
        int* pins;
    public:
        sensor(int, double*, double*, int*);
        void calib();
        void read();  
};
#endif