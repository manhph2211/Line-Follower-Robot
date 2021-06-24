#ifndef PID_h
#define PID_h

class PID
{
    private:
        void Initialize();

        double kp;
        double ki;
        double kd;

        double *myInput;
        double *myOutput;
        double *setPoint;

        unsigned long lastRecordedTime;
        double outputSum;
        double lastInput;

        unsigned long sampleTime;
        double minLimit, maxLimit;

    public:
        /* Constructor and configuring function*/
        PID(double*, double*, double*, double, double, double);
        bool Compute();

        void setOutputLimits(double, double);
        void setTunings(double, double, double);
        void setSampleTime(unsigned long);
};
#endif