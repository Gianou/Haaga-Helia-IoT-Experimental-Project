#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "Screen.h"
#include "Button.h"
#include "Joystick.h"

// SCREEN
Screen screen = Screen();

// JOYSTICKS
#define VRX_PIN 34 // ESP32 pin GPIO36 (ADC0) connected to VRX pin
#define VRY_PIN 35 // ESP32 pin GPIO39 (ADC0) connected to VRY pin
Joystick joystick = Joystick(VRX_PIN, VRY_PIN);

// BUTTONS

#define BUTTON_PIN_YELLOW 19 // Yellow button
#define BUTTON_PIN_BLUE 21   // Blue button

Button yellowButton = Button(BUTTON_PIN_YELLOW);
Button blueButton = Button(BUTTON_PIN_BLUE);

void setup()
{
  // SERIAL MONITOR
  Serial.begin(9600);
  screen.begin();
  yellowButton.begin();
  blueButton.begin();

  delay(5000);
}

void loop()
{
  // tft.fillScreen(TFT_BLACK); // To delete previous frame
  screen.draw();
  yellowButton.update();
  blueButton.update();
  joystick.update();

  Serial.println("Yellow : " + String(yellowButton.getValue()));
  Serial.println("Blue : " + String(blueButton.getValue()));
  Serial.println("X : " + String(joystick.getXValue()));
  Serial.println("Y : " + String(joystick.getYValue()));

  /*
    Instantiating the buttons as a class works but now we need the draw method
    from the screen to draw each element.
    Interface to define some data for the elements + composition pattern?
  */

  delay(500);
}
