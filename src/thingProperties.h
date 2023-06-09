// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>


const char DEVICE_LOGIN_NAME[]  = "96e02359-df29-4767-b361-aDDDD2ceecce673";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password


void onStauteultraChange();
void onPinultrasonicChange();
void onBoardGPSChange();
void onSwitchultraChange();

String stauteultra;
int pinultrasonic;
CloudLocation boardGPS;
bool switchultra;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(stauteultra, READWRITE, ON_CHANGE, onStauteultraChange);
  ArduinoCloud.addProperty(pinultrasonic, READWRITE, ON_CHANGE, onPinultrasonicChange);
  ArduinoCloud.addProperty(boardGPS, READWRITE, ON_CHANGE, onBoardGPSChange);
  ArduinoCloud.addProperty(switchultra, READWRITE, ON_CHANGE, onSwitchultraChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
