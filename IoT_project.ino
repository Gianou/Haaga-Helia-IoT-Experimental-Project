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
#include "EnemyManager.h"
#include "ConnexionManager.h"
#include "Sonar.h"
#include "Gyroscope.h"

// GYROSCOPE
Gyroscope gyroscope = Gyroscope();

// SONAR
#define sonarTrigPin 12  // define TrigPin
#define sonarEchoPin 14  // define EchoPin.
#define MAX_DISTANCE 200 // Maximum sensor distance is rated at 400-500cm.
Sonar sonar(sonarTrigPin, sonarEchoPin, MAX_DISTANCE);

// SCREEN
Screen screen = Screen();

// JOYSTICKS
#define VRX_PIN 34
#define VRY_PIN 35
Joystick joystick = Joystick(VRX_PIN, VRY_PIN);

// BUTTONS
#define BUTTON_PIN_YELLOW 19 // Yellow button
#define BUTTON_PIN_BLUE 17   // Blue button TODO change for gyro

Button yellowButton = Button(BUTTON_PIN_YELLOW);
Button blueButton = Button(BUTTON_PIN_BLUE);
Player player = Player(20, 50, 20, 20);
GameEngine gameEngine = GameEngine();
CollisionManager collisionManager = CollisionManager(player);
Debugger debugger = Debugger(4, 4, collisionManager);
Scene gameScene = Scene();
Scene startScene = Scene();
Scene gameOverScene = Scene();
Scene LeaderboardScene = Scene();
StartUI startUI = StartUI();
GameOverUI gameOverUI = GameOverUI();
LeaderboardUI leaderboardUI = LeaderboardUI();

void setup()
{
  Serial.begin(9600);

  screen.begin();
  yellowButton.begin();
  blueButton.begin();
  sonar.begin();
  gyroscope.begin();

  ConnexionManager &connexionManager = ConnexionManager::getInstance();
  connexionManager.begin(screen.getTFT());

  InputManager &inputManager = InputManager::getInstance();
  inputManager.init(yellowButton, blueButton, joystick, sonar, gyroscope);
  EnemyManager &enemyManager = EnemyManager::getInstance();

  SceneManager &sceneManager = SceneManager::getInstance();

  gameEngine.addGameObject(&inputManager);
  gameEngine.addGameObject(&debugger);

  startScene.addGameObject(&startUI);

  gameScene.addGameObject(&collisionManager);
  gameScene.addGameObject(&player);
  gameScene.addGameObject(&enemyManager);

  gameOverScene.addGameObject(&gameOverUI);

  LeaderboardScene.addGameObject(&leaderboardUI);

  sceneManager.addGameObject(&startScene);
  sceneManager.addGameObject(&gameScene);
  sceneManager.addGameObject(&gameOverScene);
  sceneManager.addGameObject(&LeaderboardScene);

  gameEngine.addGameObject(&sceneManager);
  gameEngine.addGameObject(&screen);

  sceneManager.setIndex(0);
  delay(2000);
}

void loop()
{
  gameEngine.update();
  gameEngine.draw(screen.getSprite());

  delay(33);
}
