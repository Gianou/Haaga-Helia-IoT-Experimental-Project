#include "LeaderboardUI.h"


LeaderboardUI::LeaderboardUI()
{
    
}

void LeaderboardUI::update()
{
    ConnexionManager &connexionManager = ConnexionManager::getInstance();
    _isConnected = connexionManager.isConnected();
    for (int i = 0; i < 10; i++)
    {   
        String line = "";
        String pseudo = connexionManager.receiveDataUserName(String(i+1));
        int score = connexionManager.receiveDataScore(String(i+1));
        line += i+1;
        line += ": ";
        line += pseudo;
        line += "  ";
        line += score;
        Serial.print(": ");
        Serial.print(pseudo);
        Serial.print("  ");
        Serial.println(score);
        _lines[i] = line;
    }
}

void LeaderboardUI::draw(TFT_eSprite &sprite)
{
    sprite.setTextColor(TFT_YELLOW);
    sprite.setTextSize(1);
    sprite.drawString("LeadeBoard", 22, 5);
    if (!_isConnected)
    {
        sprite.setTextColor(TFT_RED);
        sprite.setTextSize(1);
        sprite.drawString("No Internet connection", 22, 20);
        return;
    } else {
        for (int i = 0; i < 10; i++)
        {
            sprite.setTextColor(TFT_WHITE);
            sprite.setTextSize(1);
            sprite.drawString(_lines[i], 22, 20 + i * 10);
        }
    }
    
    

}