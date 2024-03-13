#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager &InputManager::getInstance()
{
    static InputManager instance; // This ensures that only one instance exists
    return instance;
}

void InputManager::init(Button &yellow, Button &blue, Joystick &joystick, Sonar &sonar)
{
    this->yellow = &yellow;
    this->blue = &blue;
    this->joystick = &joystick;
    this->sonar = &sonar;
}

void InputManager::update()
{
    blue->update();
    yellow->update();
    joystick->update();
    sonar->update();
}
void InputManager::draw(TFT_eSprite &sprite)
{
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

float InputManager::getSonarDistance()
{
    return sonar->getDistance();
}
