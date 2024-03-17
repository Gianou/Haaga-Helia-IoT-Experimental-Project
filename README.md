# ESP32 Game Project

Welcome to the ESP32 Game Project! This project allows you to run a game on an ESP32 microcontroller. This README will guide you through the setup process for both the software and hardware components of the project.

## Software Setup

### Dependencies

This project requires the following dependencies:
- [Firebase_Arduino_Client_Library_for_ESP8266_and_ESP32] (https://github.com/mobizt/Firebase-ESP-Client)
- ESP32 board support package installed in your IDE
- Firebase ESP32 library (install via Arduino Library Manager)
- TFT_eSPI library (install via Arduino Library Manager)

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
- Other necessary components (e.g., resistors, wires)

### Wiring Instructions

1. Connect the TFT LCD display to the ESP32 following the pinout specified in your display's datasheet.

2. Connect the buttons to the ESP32 for user input. Ensure proper connections for each button (e.g., one pin to ground and the other to a GPIO pin).

3. If using additional components, wire them according to their datasheets and project requirements.

4. Double-check all connections to ensure they are secure and correct.

## Running the Project

Once you have completed the software and hardware setup, you can upload the project to your ESP32 board using the Arduino IDE or your preferred IDE. After uploading, the game should start running on your ESP32 device.

## License
To be discussed

