#include "Connexion.h"


Connexion::Connexion(const char* ssid, const char* password) {
  _ssid = ssid;
  _password = password;
}

void Connexion::begin() {
  delay(1000);

  WiFi.begin(_ssid, _password);
  Serial.println("\nConnecting");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }

    /*
  FirebaseConfig config;
  config.api_key = _apiKey;
  config.database_url = _databaseUrl;

  if (Firebase.signUp(&config, nullptr, "", "")){
    Serial.println("ok");
    _signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  Firebase.begin(&config, nullptr);
  Firebase.reconnectWiFi(true);

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
  */
}

bool Connexion::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}

/*
bool Connexion::sendData(String pseudo, int count) {
  if (!isConnected()) return false;

  if (Firebase.ready() && _signupOK && (millis() - _sendDataPrevMillis > 15000 || _sendDataPrevMillis == 0)) {
    _sendDataPrevMillis = millis();
    FirebaseJson json;
    json.set("pseudo", pseudo);
    json.set("score", count);

    return Firebase.RTDB.pushJSON(&_fbdo, "score_board/", &json);
  }
  return false;
}

String Connexion::receiveData() {
  if (!isConnected()) return "";

  bool success = Firebase.RTDB.getJSON(&_fbdo, "score_board/");
  if (success) {
    FirebaseJson json = _fbdo.jsonObject();
    String jsonString;
    json.toString(jsonString);
    return jsonString;
  }
  return "";
}

void Connexion::tokenStatusCallback(bool status) {
  // Handle token status change here if needed
}

*/