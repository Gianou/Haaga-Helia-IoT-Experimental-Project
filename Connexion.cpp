#include "Connexion.h"

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"



    
FirebaseConfig config;
FirebaseAuth auth;

Connexion::Connexion(const char* ssid, const char* password, const char* apiKey, const char* databaseUrl) {
  _ssid = ssid;
  _password = password;
  _apiKey = apiKey;
  _databaseUrl = databaseUrl;
  _signupOK = false;
  _sendDataPrevMillis = 0;
}

void Connexion::begin() {
  delay(1000);

  WiFi.begin(_ssid, _password);
  Serial.println("\nConnecting");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }


  config.api_key = _apiKey;
  config.database_url = _databaseUrl;

  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    _signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
  
}

bool Connexion::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}


bool Connexion::sendData(String pseudo, int count) {
  if (!isConnected()) return false;
  Serial.println("sendData");
  Serial.println(Firebase.ready());
  Serial.println(_signupOK);
  Serial.println(millis() - _sendDataPrevMillis > 15000);
  Serial.println(_sendDataPrevMillis == 0);
 
  if (Firebase.ready() && _signupOK && (millis() - _sendDataPrevMillis > 15000 || _sendDataPrevMillis == 0)) {
    _sendDataPrevMillis = millis();
    FirebaseJson json;
    json.set("pseudo", pseudo);
    json.set("score", count);
    Serial.println("sendData2");

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



