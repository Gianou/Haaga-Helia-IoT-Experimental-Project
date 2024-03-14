#ifndef Gyroscope_H
#define Gyroscope_H

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

class Gyroscope
{
public:
    Gyroscope();
    void begin();
    void update();
    float getAXValue();
    float getAYValue();
    float getAZValue();
    bool getIsConnected();

private:
    MPU6050 accelgyro;
    uint16_t xValue;
    uint16_t yValue;
    uint16_t zValue;
};

#endif
