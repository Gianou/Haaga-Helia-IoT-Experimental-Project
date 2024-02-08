#include <SPI.h>
#include <TFT_eSPI.h>
#include "Screen.h"
#include "Button.h"
#include "Joystick.h"
#include "InputManager.h"
#include "Player.h"
#include "RenderEngine.h"
#include "Debugger.h"

// SCREEN
Screen screen = Screen();

// JOYSTICKS
#define VRX_PIN 34
#define VRY_PIN 35
Joystick joystick = Joystick(VRX_PIN, VRY_PIN);

// BUTTONS
#define BUTTON_PIN_YELLOW 19 // Yellow button
#define BUTTON_PIN_BLUE 21   // Blue button

Button yellowButton = Button(BUTTON_PIN_YELLOW);
Button blueButton = Button(BUTTON_PIN_BLUE);
Player player = Player(50, 50, 20, 20);
Debugger debugger = Debugger(4, 4);
RenderEngine renderEngine = RenderEngine();

void setup()
{
  Serial.begin(9600);

  screen.begin();
  yellowButton.begin();
  blueButton.begin();

  InputManager &inputManager = InputManager::getInstance();
  inputManager.init(yellowButton, blueButton, joystick);

  renderEngine.addRenderable(&screen);
  renderEngine.addRenderable(&debugger);
  renderEngine.addRenderable(&player);

  delay(2000);
}

void loop()
{
  // Get reference to the inputManager Singleton and get all inputs
  InputManager &inputManager = InputManager::getInstance();
  inputManager.update();
  renderEngine.draw(screen.getTFT());

  player.update();
  delay(64);
}
