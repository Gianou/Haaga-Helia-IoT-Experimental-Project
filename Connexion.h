#ifndef CONNEXION_H
#define CONNEXION_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class Connexion {
  public:
    Connexion(const char* ssid, const char* password);
    void begin();
    bool isConnected();
  
  private:
    const char* _ssid;
    const char* _password;
    /*
    const char* _apiKey;
    const char* _databaseUrl;
    bool _signupOK;
    unsigned long _sendDataPrevMillis;
    FirebaseData _fbdo;

    static void tokenStatusCallback(bool status);
    */
};

#endif
