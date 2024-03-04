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
#include "Scene.h"
#include "SceneManager.h"
#include "StartUI.h"
#include "GameOverUI.h"
#include "LeaderboardUI.h"
#include "Connexion.h"

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
Scene gameScene = Scene();
Scene startScene = Scene();
Scene gameOverScene = Scene();
Scene LeaderboardScene = Scene();
StartUI startUI = StartUI();
GameOverUI gameOverUI = GameOverUI();
LeaderboardUI leaderboardUI = LeaderboardUI();
Connexion connexion = Connexion ("XperiaX_b4dd", "d08fa948637d", "AIzaSyDthqQ1rZ20Qo3407_EO4a8_RSrIAXiyuo", "https://esp32-f271c-default-rtdb.europe-west1.firebasedatabase.app/"
);
int i = 0;

void setup()
{
  Serial.begin(9600);

  connexion.begin();
  screen.begin();
  yellowButton.begin();
  blueButton.begin();
  bool sendData = connexion.sendData("Pseudo", 0);

  InputManager &inputManager = InputManager::getInstance();
  inputManager.init(yellowButton, blueButton, joystick);

  SceneManager &sceneManager = SceneManager::getInstance();

  gameEngine.addGameObject(&inputManager);
  gameEngine.addGameObject(&debugger);

  startScene.addGameObject(&startUI);

  gameScene.addGameObject(&collisionManager);
  gameScene.addGameObject(&player);
  gameScene.addGameObject(&enemy1);

  gameOverScene.addGameObject(&gameOverUI);

  LeaderboardScene.addGameObject(&leaderboardUI);

  sceneManager.addGameObject(&startScene);
  sceneManager.addGameObject(&gameScene);
  sceneManager.addGameObject(&gameOverScene);
  sceneManager.addGameObject(&LeaderboardScene);

  gameEngine.addGameObject(&sceneManager);
  gameEngine.addGameObject(&screen);

  sceneManager.setIndex(2);
  delay(2000);
}

void loop()
{
  gameEngine.update();
  gameEngine.draw(screen.getSprite());

  delay(33);
}
