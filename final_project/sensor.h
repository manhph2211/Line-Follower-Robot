#ifndef sensor_h
#define sensor_h

class sensor{
    private:
        int numOfSens;
        double* thresholds;
        int* sensorValues;
        int* outputs;
        int* pins;
    public:
        sensor(int, double*, int*);
        void calib();
        void read();  
        void encode();
};
#endif