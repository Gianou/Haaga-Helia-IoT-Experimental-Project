#include "LeaderboardUI.h"

#define RGB16(color) rgb32_to_rgb16(color)
#define rgb32_to_rgb16(color) rgbc32_to_rgb16((color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, (color & 0x0000FF))
#define rgbc32_to_rgb16(red, green, blue) ((red & 0b11111000) << 8) | ((green & 0b11111100) << 3) | (blue >> 3)


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
        line += ":";
        line += pseudo;
        line += " ";
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
     uint16_t colorValues[] = {
                                TFT_RED,        // Red
                                RGB16(0xFF6800),         // Orange
                                0xFFE0,         // Yellow
                                TFT_GREEN,      // Green
                                TFT_DARKGREEN,
                                RGB16(0x158080), //A bit turquoise
                                RGB16(0x0355AB), //blue
                                RGB16(0x5800AA), //blue-purple
                                RGB16(0x820080), //purple
                                RGB16(0xFF00D4), //pink                
                                };
    sprite.setTextColor(TFT_YELLOW);
    sprite.setTextSize(2);
    sprite.drawString("LeaderBoard", 15, 5);
    if (!_isConnected)
    {
        sprite.setTextColor(TFT_RED);
        sprite.setTextSize(1);
        sprite.drawString("No Internet connection", 22, 30);
        return;
    } else {
        for (int i = 0; i < 5; i++)
        {
            sprite.setTextColor(colorValues[i]);
            sprite.setTextSize(1);
            sprite.drawString(_lines[i], 5, 30 + i * 10);
        }
        for (int i = 5; i < 10; i++)
        {
            sprite.setTextColor(colorValues[i]);
            sprite.setTextSize(1);
            if (i == 9) {
                sprite.drawString(_lines[i], 82, 30 + (i-5) * 10);
            } else {
                sprite.drawString(_lines[i], 88, 30 + (i-5) * 10);
            }
        }
    }

    sprite.setTextSize(1);
    sprite.drawLine(75, 30, 75, 76, TFT_WHITE);
    
    

}