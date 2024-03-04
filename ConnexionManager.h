#ifndef CONNEXION_MANAGER_H
#define CONNEXION_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

#include <Firebase_ESP_Client.h>
class ConnexionManager
{
public:
  ConnexionManager(const char *ssid, const char *password, const char *apiKey, const char *databaseUrl);
  void begin();
  bool isConnected();
  bool sendData(String pseudo, int count);
  String receiveData();

private:
  const char *_ssid;
  const char *_password;

  const char *_apiKey;
  const char *_databaseUrl;

  bool _signupOK;
  unsigned long _sendDataPrevMillis;
  FirebaseData _fbdo;
};

#endif
