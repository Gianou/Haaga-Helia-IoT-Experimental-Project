#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager &InputManager::getInstance()
{
    static InputManager instance; // This ensures that only one instance exists
    return instance;
}

void InputManager::init(Button &yellow, Button &blue, Joystick &joystick)
{
    this->yellow = &yellow;
    this->blue = &blue;
    this->joystick = &joystick;
}

void InputManager::update()
{
    blue->update();
    yellow->update();
    joystick->update();
}

int InputManager::getBlueButtonValue()
{
    return blue->getValue();
}

int InputManager::getYellowButtonValue()
{
    return yellow->getValue();
}

int InputManager::getJoystickXValue()
{
    return joystick->getXValue();
}

int InputManager::getJoystickYValue()
{
    return joystick->getYValue();
}
