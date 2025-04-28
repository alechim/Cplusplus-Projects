#ifndef SWIMMING_POOL_H
#define SWIMMING_POOL_H

class swimmingPool
{        
    public:
        void determineTimeFill();
        void determineTimeDrain();
        double promptAmount();
        void displayWater();

        swimmingPool(double = 1.0, double = 1.0, double = 1.0, double = 1.0, double = 1.0);
    private:
        double length;          // length, width, and depth are in feet
        double width;
        double depth;
        double fillingPool;     // rates are gallons per minute
        double drainingPool;
        double currentWater;    // 0.0 - 1.0
};

#endif