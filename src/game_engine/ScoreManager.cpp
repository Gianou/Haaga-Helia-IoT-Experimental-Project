#include "ScoreManager.h"

ScoreManager::ScoreManager() {}

ScoreManager &ScoreManager::getInstance()
{
    static ScoreManager instance;
    return instance;
}

String ScoreManager::getUsername()
{
    return username;
}

void ScoreManager::setUsername(String &newUsername)
{
    username = newUsername;
}

int ScoreManager::getScore()
{
    return score;
}

void ScoreManager::setScore(int newScore)
{
    score = newScore;
}