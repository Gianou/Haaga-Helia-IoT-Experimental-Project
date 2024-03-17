#ifndef SONAR_H
#define SONAR_H

class Sonar
{
public:
    Sonar(int trigPin, int echoPin, int maxDistance);
    void begin();
    void update();
    float getDistance();

private:
    int trigPin;
    int echoPin;
    int maxDistance;
    float timeOut;
    int soundVelocity;
    float distance;
};

#endif
