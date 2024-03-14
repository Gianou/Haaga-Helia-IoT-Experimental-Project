#include "StartUI.h"

StartUI::StartUI()
{
    moveYAxis = true;
    currentCharYIndex = 0;
}

void StartUI::update()
{
    handleInput();
    /*
    Check for inputs and set index in SceneManager
    */
    InputManager &inputManager = InputManager::getInstance();
    SceneManager &sceneManager = SceneManager::getInstance();

    if (!inputManager.getBlueButtonValue()&& currentCharYIndex == 0)
    {
        sceneManager.setIndex(1);
    }
    else if (!inputManager.getBlueButtonValue() && currentCharYIndex == 1)
    {
        sceneManager.setIndex(3);
    }

}

void StartUI::draw(TFT_eSprite &sprite)
{
    sprite.setTextSize(2);
    sprite.setCursor(36, 10);
    sprite.setTextColor(TFT_YELLOW);
    sprite.println("Welcome");
    sprite.setCursor(36, 30);
    sprite.println("Captain ");

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    if (currentCharYIndex == 0)
    {
        sprite.drawString("-> Start Game", 35, 60);
        sprite.drawString("Leaderboard", 53, 80);
    } else {
        sprite.drawString("Start Game", 53, 60);
        sprite.drawString("-> Leaderboard", 35, 80);
    }

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("press blue to start", 22, 110);
}

void StartUI::handleInput()
{
    InputManager &inputManager = InputManager::getInstance();
    if (moveYAxis)
    {
        if (inputManager.getJoystickYValue() > 4000)
        {
            currentCharYIndex == 0 ? currentCharYIndex = 1 : currentCharYIndex = 0;
            moveYAxis = false;
        }
        else if (inputManager.getJoystickYValue() < 200)
        {
            currentCharYIndex == 1 ? currentCharYIndex = 0 : currentCharYIndex = 1;
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