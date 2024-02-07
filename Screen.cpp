#include "Screen.h"

Screen::Screen() : tft(TFT_eSPI()) {}

void Screen::begin()
{
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

    // Set "cursor" at top left corner of display (0,0) and select font 4
    tft.setCursor(0, 4, 4);
    // Set the font colour to be white with a black background
    tft.setTextColor(TFT_WHITE);
    tft.println("Hello World!");
}

void Screen::draw()
{
    tft.fillScreen(TFT_BLACK); // To delete previous frame

    tft.setCursor(0, 4, 4);
    // Set the font colour to be white with a black background
    tft.setTextColor(TFT_WHITE);
    tft.println("The game is running");
}
