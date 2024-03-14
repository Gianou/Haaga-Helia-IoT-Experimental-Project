#ifndef InputManager_H
#define InputManager_H

#include "Button.h"
#include "Joystick.h"
#include "Sonar.h"
#include "Gyroscope.h"
#include "GameObject.h"

class InputManager : public GameObject
{
public:
    static InputManager &getInstance();

    void init(Button &yellow, Button &blue, Joystick &joystick, Sonar &sonar, Gyroscope &gyroscope);
    void update() override;
    void draw(TFT_eSprite &sprite) override;
    int getBlueButtonValue();
    int getYellowButtonValue();
    int getJoystickXValue();
    int getJoystickYValue();
    float getSonarDistance();
    float getGyroscopeAXValue();
    float getGyroscopeAYValue();
    float getGyroscopeAZValue();

private:
    Button *blue;
    Button *yellow;
    Joystick *joystick;
    Sonar *sonar;
    Gyroscope *gyroscope;

    InputManager();                                // Private constructor to enforce Singleton pattern
    InputManager(const InputManager &) = delete;   // Disallow copy constructor
    void operator=(const InputManager &) = delete; // Disallow assignment operator
};

#endif
