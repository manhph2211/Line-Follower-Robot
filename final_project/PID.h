#ifndef PID_h
#define PID_h

class PID
{
    private:
        void Initialize();

        double kp;       //(P)roportional part
        double ki;       //(I)ntegral part
        double kd;       //(D)erivative part

        double *myInput; // input of pid
        double *myOutput;// out put of pid
        double *setPoint;// desired PWM output

        unsigned long lastRecordedTime;  // the last sampling time               
        double lastInput;                // the last sampled input

        unsigned long sampleTime;        // sampling time
        double minLimit, maxLimit;       // limit of PWM at the output

    public:
        /* Constructor and configuring function*/
        PID(double*, double*, double*, double, double, double);
        bool calculate();

        void setOutputLimits(double, double);
        void setTunings(double, double, double);
        void setSampleTime(unsigned long);
};
#endif