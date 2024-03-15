#include "Gyroscope.h"

Gyroscope::Gyroscope()
{
    // Constructor
}

void Gyroscope::begin()
{
    Wire.begin();           // initialize I2C
    accelgyro.initialize(); // Initialize MPU6050

    Serial.println("Testing device connections...");
    // verify connection
    if (accelgyro.testConnection())
    {
        Serial.println("MPU6050 connection successful");
    }
    else
    {
        Serial.println("MPU6050 connection failed");
        while (1)
            ;
    }
    // when you need to calibrate the gravity acceleration, you can set the offset here and eliminate the note
    // accelgyro.setXAccelOffset(-1200);
    // accelgyro.setYAccelOffset(-2500);
    // accelgyro.setZAccelOffset(1988);
    Serial.print("X.Y.Z offset :\t");
    Serial.print(accelgyro.getXAccelOffset());
    Serial.print("\t");
    Serial.print(accelgyro.getYAccelOffset());
    Serial.print("\t");
    Serial.print(accelgyro.getZAccelOffset());
    Serial.print("\n");
}

void Gyroscope::update()
{
    int16_t ax, ay, az;
    accelgyro.getAcceleration(&ax, &ay, &az); // Read raw acceleration data
    Serial.println(ax);
    xValue = ((float)ax / 16384);
    yValue = ((float)ay / 16384);
    zValue = ((float)az / 16384);
    Serial.print("X : ");
    Serial.print(xValue);
    Serial.print(", Y : ");
    Serial.print(yValue);
    Serial.print(", Z : ");
    Serial.println(zValue);
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
