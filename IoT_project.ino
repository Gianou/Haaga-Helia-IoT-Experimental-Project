#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "Screen.h"
#include "Button.h"
#include "Joystick.h"
#include "InputManager.h"

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
  Serial.begin(9600);

  screen.begin();
  yellowButton.begin();
  blueButton.begin();

  InputManager &inputManager = InputManager::getInstance();
  inputManager.init(yellowButton, blueButton, joystick);

  delay(2000);
}

void loop()
{
  screen.draw();

  // Get reference to the inputManager Singleton and get all inputs
  InputManager &inputManager = InputManager::getInstance();
  inputManager.update();

  delay(64);
}
