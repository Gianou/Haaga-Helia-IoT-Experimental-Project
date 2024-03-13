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
    /*
    Check for inputs and set index in SceneManager
    */
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
    sprite.drawString("Welcome captain!", 10, 10);

    for (int i = 0; i < 2; ++i)
    {
        if (i == currentCharYIndex)
        {
            sprite.setTextColor(TFT_GREENYELLOW);
            sprite.setTextSize(1);
            sprite.drawString(stringArray[i], 20, 30 + i * 30);
            sprite.setTextSize(1);
            sprite.setTextColor(TFT_WHITE);
            // Draw pointer (>)
            sprite.drawString(">", 10, 30 + i * 30);
        }
        else
        {
            sprite.setTextColor(TFT_WHITE);
            sprite.setTextSize(1);
            sprite.drawString(stringArray[i], 20, 30 + i * 30);
        }
    }

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString(stringArray[0], 20, 30);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString(stringArray[1], 20, 60);

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