#ifndef InputManager_H
#define InputManager_H

#include "Button.h"
#include "Joystick.h"
#include "GameObject.h"

class InputManager : public GameObject
{
public:
    static InputManager &getInstance();

    void init(Button &yellow, Button &blue, Joystick &joystick);
    void update() override;
    void draw(TFT_eSprite &sprite) override;
    int getBlueButtonValue();
    int getYellowButtonValue();
    int getJoystickXValue();
    int getJoystickYValue();

private:
    Button *blue;
    Button *yellow;
    Joystick *joystick;

    InputManager();                                // Private constructor to enforce Singleton pattern
    InputManager(const InputManager &) = delete;   // Disallow copy constructor
    void operator=(const InputManager &) = delete; // Disallow assignment operator
};

#endif
