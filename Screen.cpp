#include "Screen.h"

Screen::Screen() : tft(TFT_eSPI()), sprite(&tft)
{
}

void Screen::begin()
{
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

    // Splash Screen
    tft.setTextSize(2);
    tft.setCursor(36, 10);
    tft.setTextColor(TFT_YELLOW);
    tft.println("Welcome");
    tft.setCursor(36, 30);
    tft.println("Captain ");
    // WIFI info
    tft.setTextSize(1);
    tft.setCursor(10, 60);
    tft.setTextColor(TFT_WHITE);
    tft.println("Connecting to Wifi");
    tft.setCursor(10, 70);
    tft.println("ssid : " + String(ssid));

    /*
    When refactoring from drawing each element on screen to drawing each element to a Sprite that is then rendered when it is ready,
    It appeared that the Sprite would get corrupt with a with of 160px but works as expected with a width of 158px
    */
    sprite.createSprite(158, 128);
}

void Screen::draw(TFT_eSprite &wedontneedthereferencehere)
{
    // TODO : remove from here and do in RenderEngine instead, maybe?
    sprite.pushSprite(0, 0);
}

void Screen::update() {}

TFT_eSPI &Screen::getTFT()
{
    return tft;
}
TFT_eSprite &Screen::getSprite()
{
    return sprite;
}