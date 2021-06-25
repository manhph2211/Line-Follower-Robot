#ifndef sensor_h
#define sensor_h

class sensors{
    private:
        int numberOfSensors;
        double thresolds;
        double* readSensors;
        double minSensorLimit,maxSensorLimit;
        int* pins;
    public:
        void calib();  
};
#endif