#include "Gyroscope.h"

Gyroscope::Gyroscope()
{
    // Constructor
}

void Gyroscope::begin()
{
    Wire.begin();           // initialize I2C
    accelgyro.initialize(); // Initialize MPU6050
}

void Gyroscope::update()
{
    int16_t ax, ay, az;
    accelgyro.getAcceleration(&ax, &ay, &az); // Read raw acceleration data

    xValue = (float)ax / 16384;
    yValue = (float)ay / 16384;
    zValue = (float)az / 16384;
}

float Gyroscope::getAXValue()
{
    return xValue;
}

float Gyroscope::getAYValue()
{
    return yValue;
}

float Gyroscope::getAZValue()
{
    return zValue;
}

bool Gyroscope::getIsConnected()
{
    return accelgyro.testConnection();
}
