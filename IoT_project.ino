#include <SPI.h>
#include <TFT_eSPI.h>
#include "Screen.h"
#include "Button.h"
#include "Joystick.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameEngine.h"
#include "Debugger.h"
#include "CollisionManager.h"

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
Enemy enemy1 = Enemy(100, 50, 12, 12, 10);
GameEngine gameEngine = GameEngine();
CollisionManager collisionManager = CollisionManager(player, enemy1);
Debugger debugger = Debugger(4, 4, collisionManager);

void setup()
{
  Serial.begin(9600);

  screen.begin();
  yellowButton.begin();
  blueButton.begin();

  InputManager &inputManager = InputManager::getInstance();
  inputManager.init(yellowButton, blueButton, joystick);

  gameEngine.addGameObject(&inputManager);
  gameEngine.addGameObject(&debugger);
  gameEngine.addGameObject(&collisionManager);
  gameEngine.addGameObject(&player);
  gameEngine.addGameObject(&enemy1);
  gameEngine.addGameObject(&screen);

  delay(2000);
}

void loop()
{
  gameEngine.update();
  gameEngine.draw(screen.getSprite());

  delay(33);
}
