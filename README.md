# ESP32 Game Project

Welcome to the ESP32 Game Project! This project allows you to run a game on an ESP32 microcontroller. This README will guide you through the setup process for both the software and hardware components of the project.

## Software Setup

### Dependencies

This project requires the following librairies:
- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [Firebase_Arduino_Client_Library_for_ESP8266_and_ESP32](https://github.com/mobizt/Firebase-ESP-Client)
- [MPU6050 for ESP32](https://github.com/jrowberg/i2cdevlib/tree/master/ESP32_ESP-IDF/components/MPU6050)
- [I2Cdev for ESP32](https://github.com/jrowberg/i2cdevlib/tree/master/ESP32_ESP-IDF/components/I2Cdev)


### Configuration

To configure the project, follow these steps:

1. Navigate to the `/src/network/` directory of your project.

2. Create a new file named `config.cpp`.

3. Add the following code block to `config.cpp`, replacing placeholders with your actual credentials:

```cpp
#include "config.h"

const char *ssid = "your_wifi_ssid";
const char *password = "your_wifi_password";
const char *apiKey = "your_api_key";
const char *databaseUrl = "your_database_url";
```
Note: if you are reproducing this project from scratch you will have to create a Realtime Database in a new Firebase project

## Hardware Setup

### Components Used

- ESP32 microcontroller 
- TFT LCD display
- Buttons for input
- Joystick
- HC-SR04 
- GY-521 

### Wiring Instructions

This is gonna take a while

## Running the Project

Once you have completed the software and hardware setup, you can upload the project to your ESP32 board using the Arduino IDE or your preferred IDE. After uploading, the game should start running on your ESP32 device.

## License
To be discussed

