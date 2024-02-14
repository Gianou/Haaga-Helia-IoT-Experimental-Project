#include "LeaderboardUI.h"

LeaderboardUI::LeaderboardUI()
{
}

void LeaderboardUI::update()
{
}

void LeaderboardUI::draw(TFT_eSprite &sprite)
{
    sprite.setTextColor(TFT_YELLOW);
    sprite.setTextSize(2);
    sprite.drawString("Game Over =(", 10, 40);

    sprite.setTextColor(TFT_WHITE);
    sprite.setTextSize(1);
    sprite.drawString("press blue to start", 22, 90);
}