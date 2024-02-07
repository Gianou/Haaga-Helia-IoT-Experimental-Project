#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "Screen.h"
#include "Button.h"

////
// SCREEN
////
Screen screen = Screen();

////
// JOYSTICKS
////
#define VRX_PIN 34 // ESP32 pin GPIO36 (ADC0) connected to VRX pin
#define VRY_PIN 35 // ESP32 pin GPIO39 (ADC0) connected to VRY pin

int currentValueX = 0; // to store the X-axis value
int currentValueY = 0; // to store the Y-axis value
int lastValueX = 0;    // to store the X-axis value
int lastValueY = 0;    // to store the Y-axis value

////
// BUTTONS
////
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

  Serial.println("Yellow : " + String(yellowButton.getValue()));
  Serial.println("Blue : " + String(blueButton.getValue()));

  /*
    Instantiating the buttons as a class works but now we need the draw method
    from the screen to draw each element.
    Interface to define some data for the elements + composition pattern?
  */

  // read X
  currentValueX = analogRead(VRX_PIN);
  if (abs(lastValueX - currentValueX) > 200)
  {
    // print data to Serial Monitor on Arduino IDE
    Serial.print("x = ");
    Serial.println(currentValueX);
    lastValueX = currentValueX;
  }

  // read Y
  currentValueY = analogRead(VRY_PIN);
  if (abs(lastValueY - currentValueY) > 200)
  {
    Serial.print("y = ");
    Serial.println(currentValueY);
    lastValueY = currentValueY;
  }

  delay(64);
}
