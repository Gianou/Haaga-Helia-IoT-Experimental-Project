#ifndef CONNEXION_MANAGER_H
#define CONNEXION_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

#include <Firebase_ESP_Client.h>
#include <TFT_eSPI.h>
#include "config.h"
class ConnexionManager
{
public:
  static ConnexionManager &getInstance();
  void begin(TFT_eSPI tft);
  bool isConnected();
  bool sendData(String pseudo, int count);
  String receiveDataUserName(String index);
  int receiveDataScore(String index);

private:
  ConnexionManager();

  const char *_ssid;
  const char *_password;

  const char *_apiKey;
  const char *_databaseUrl;

  bool _signupOK;
  unsigned long _sendDataPrevMillis;
  FirebaseData _fbdo;
};

#endif
