#include "ConnexionManager.h"

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

FirebaseConfig config;
FirebaseAuth auth;

ConnexionManager::ConnexionManager()
{
  _ssid = ssid;
  _password = password;
  _apiKey = apiKey;
  _databaseUrl = databaseUrl;
  _signupOK = false;
  _sendDataPrevMillis = 0;
}

ConnexionManager &ConnexionManager::getInstance()
{
  static ConnexionManager instance; // This ensures that only one instance exists
  return instance;
}

void ConnexionManager::begin()
{
  delay(1000);

  WiFi.begin(_ssid, _password);
  Serial.println("\nConnecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  config.api_key = _apiKey;
  config.database_url = _databaseUrl;

  if (Firebase.signUp(&config, &auth, "", ""))
  {
    Serial.println("ok");
    _signupOK = true;
  }
  else
  {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
}

bool ConnexionManager::isConnected()
{
  return WiFi.status() == WL_CONNECTED;
}

bool ConnexionManager::sendData(String pseudo, int score)
{
  if (!isConnected())
    return false;

  if (Firebase.ready() && _signupOK && (millis() - _sendDataPrevMillis > 15000 || _sendDataPrevMillis == 0))
  {
   Firebase.RTDB.getInt(&_fbdo, "index");
   int num = _fbdo.intData();
    Serial.println(num);
    _sendDataPrevMillis = millis();
    
    String indexStr = String(num);
    String path = "score_board/";
    String pathIndex = path += indexStr;
    String pathPseudo = path += "/pseudo";
    String pathScore = pathIndex += "/score";
    if (Firebase.RTDB.setInt(&_fbdo, pathScore, score) && Firebase.RTDB.setString(&_fbdo, pathPseudo, pseudo))
    {
      Firebase.RTDB.setInt(&_fbdo, "index/", num + 1);
    }

    
    Firebase.RTDB.getInt(&_fbdo, "leader_board/min");
    int min = _fbdo.intData();
    
    //check if the score has to be added to leader_board
    if (score >= min) {
      int leader_board_score[10];
      String leader_board_pseudo[10];
      for (int i = 0; i < 10; i++) {
        leader_board_score[i] = receiveDataScore(String(i+1));
        leader_board_pseudo[i] = receiveDataUserName(String(i+1));
      }

      int rank = 0;
      //loop to find which rank the score will be
      for (int i = 8; i >= 0; i--) {
        if (score < leader_board_score[i]) {
          rank = i+1;
          break;
        }
      }

      //loop to change the ranks of the leader_board
      for (int i = 9; i > rank; i--) {
        leader_board_score[i] = leader_board_score[i-1];
        leader_board_pseudo[i] = leader_board_pseudo[i-1];
      }

      //add the new score and pseudo to the leader_board
      leader_board_score[rank] = score;
      leader_board_pseudo[rank] = pseudo;

      //loop to change the leader_board in the database
      for (int i = 0; i < 10; i++) {
        String path_leader = "leader_board/";
        String pathIndex_leader = path_leader += String(i+1);
        String pathScore_leader = pathIndex_leader += "/score";
        String pathPseudo_leader = path_leader += "/pseudo";
        Firebase.RTDB.setInt(&_fbdo, pathScore_leader, leader_board_score[i]);
        Firebase.RTDB.setString(&_fbdo, pathPseudo_leader, leader_board_pseudo[i]);
      }

      //change the min value
      Firebase.RTDB.setInt(&_fbdo, "leader_board/min", leader_board_score[9]);
      
    }
    return true;
  }
  return false;
}

String ConnexionManager::receiveDataUserName(String index)
{
  String path = "leader_board/";
  String userName = "";
  path += index += "/pseudo";
  bool success = Firebase.RTDB.getString(&_fbdo, path);
  if (success)
  {
    userName = _fbdo.stringData();
  }
  return userName;
}

int ConnexionManager::receiveDataScore(String index)
{
  String path = "leader_board/";
  path += index += "/score";
  int score = 0;
  bool success = Firebase.RTDB.getInt(&_fbdo, path);
  if (success)
  {
    score = _fbdo.intData();
  }
  return score;
}
