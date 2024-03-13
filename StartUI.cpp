#include "StartUI.h"

StartUI::StartUI()
{
    currentCharYIndex = 0;
    moveYAxis = false;

    stringArray[0] = "Play game";
    stringArray[1] = "Leaderboard";
}

void StartUI::update()
{
    handleInput();
    InputManager &inputManager = InputManager::getInstance();
    SceneManager &sceneManager = SceneManager::getInstance();

    if (!inputManager.getBlueButtonValue())
    {
        sceneManager.setIndex(1);
    }
}

void StartUI::draw(TFT_eSprite &sprite)
{
    sprite.setTextColor(TFT_YELLOW);
    sprite.setTextSize(2);
    sprite.drawString("Welcome", 10, 10);
    sprite.drawString("captain!", 10, 15);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString(currentCharYIndex == 0 ? "> " + stringArray[0] : stringArray[0], 20, 30);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString(currentCharYIndex == 1 ? "> " + stringArray[1] : stringArray[1], 20, 60);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("Press blue to select", 10, 80);
}

void StartUI::handleInput()
{
    InputManager &inputManager = InputManager::getInstance();

    if (moveYAxis)
    {
        if (inputManager.getJoystickYValue() > 4000)
        {
            currentCharYIndex > 0 ? currentCharYIndex-- : currentCharYIndex = 0;
            moveYAxis = false;
        }
        else if (inputManager.getJoystickYValue() < 200)
        {
            currentCharYIndex < 1 ? currentCharYIndex++ : currentCharYIndex = 0;
            moveYAxis = false;
        }
    }
    else
    {
        if (inputManager.getJoystickYValue() >= 200 && inputManager.getJoystickYValue() <= 4000)
        {
            moveYAxis = true;
        }
    }
}