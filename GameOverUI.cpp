#include "GameOverUI.h"

GameOverUI::GameOverUI()
{
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        alphabets[c - 'A'] = c;
    }

    for (int i = 0; i < 3; ++i)
    {
        nameInput[i] = 'A';
        userChanged[i] = false;
        userSelection[i] = 'A';
    }

    currentCharXIndex = 0;
    currentCharYIndex = 0;
    moveXAxis = true;
    moveYAxis = true;
}

void GameOverUI::update()
{
    handleInput();
}

void GameOverUI::draw(TFT_eSprite &sprite)
{
    int score = 0;

    sprite.setTextColor(TFT_YELLOW);
    sprite.setTextSize(2);
    sprite.drawString("GAME OVER", 10, 10);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("Final score: " + String(score), 10, 30);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("Username: ", 10, 60);

    for (int i = 0; i < 3; ++i)
    {
        if (i == currentCharXIndex)
        {

            sprite.setTextColor(TFT_GREENYELLOW);
            sprite.setTextSize(1);
            sprite.drawString(String(userSelection[i]), 85 + i * 20, 60);
            sprite.setTextSize(1);
            sprite.setTextColor(TFT_WHITE);
        }
        else
        {
            sprite.drawString(String(nameInput[i]), 85 + i * 20, 60);
        }
    }

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("Move left/right/up/down", 10, 80);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("PRESS BLUE TO SAVE", 10, 100);
}

void GameOverUI::handleInput()
{
    InputManager &inputManager = InputManager::getInstance();
    if (moveXAxis)
    {
        if (inputManager.getJoystickXValue() > 2200)
        {
            currentCharXIndex > 0 ? currentCharXIndex-- : currentCharXIndex = 2;
            moveXAxis = false;
            currentCharYIndex = 0;
        }
        else if (inputManager.getJoystickXValue() < 1800)
        {
            currentCharXIndex < 2 ? currentCharXIndex++ : currentCharXIndex = 0;
            moveXAxis = false;

            currentCharYIndex = 0;
        }
    }
    else
    {
        if (inputManager.getJoystickXValue() >= 1800 && inputManager.getJoystickXValue() <= 2200)
        {
            moveXAxis = true;
        }
    }

    if (moveYAxis)
    {
        if (inputManager.getJoystickYValue() > 4000)
        {
            currentCharYIndex > 0 ? currentCharYIndex-- : currentCharYIndex = 25;
            moveYAxis = false;
        }
        else if (inputManager.getJoystickYValue() < 200)
        {
            currentCharYIndex < 25 ? currentCharYIndex++ : currentCharYIndex = 0;
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

    userSelection[currentCharXIndex] = alphabets[currentCharYIndex];

    if (nameInput[currentCharXIndex] != userSelection[currentCharXIndex])
    {
        nameInput[currentCharXIndex] = userSelection[currentCharXIndex];
    }
}