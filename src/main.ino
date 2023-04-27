#include "arduino_secrets.h"
#include "thingProperties.h"
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

const int trigPin = 12;
const int echoPin = 13;

// define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
int distance; // variable for the distance measurement
long duration;

// gps

TinyGPSPlus gps;
static const int RXPin = 25, TXPin = 26;
int GPSBaud = 9600;
SoftwareSerial gpsSerial(RXPin, TXPin);

// gps

void setup()
{
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // Initialize gps Serial:
  gpsSerial.begin(GPSBaud);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  delay(1500);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop()
{
  ArduinoCloud.update();
  // Your code here
  int ultrasonicl = ultrasonic();
  // Serial.print("ultrasonicl : ");
  // Serial.println(ultrasonicl);

  pinultrasonic = ultrasonicl;

  if (ultrasonicl > 30)
  {
    stauteultra = "full";
    loaded = true;
  }
  else
  {
    stauteultra = "not full";
    loaded = false;
  }

  // if gpsSerial is available and bigar then 0
  while (gpsSerial.available() > 0)
  {
    // will check and encode from gpsSerial and read
    if (gps.encode(gpsSerial.read()))
    {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      boardGPS = Location(gps.location.lat(), gps.location.lng());

      // watch the gps location length
      // Serial.print("Latitude: ");
      // Serial.println(gps.location.lat(), 6);
      // Serial.print("Longitude: ");
      // Serial.println(gps.location.lng(), 6);
      // Serial.print("Altitude: ");
      // Serial.println(gps.altitude.meters());
    }
  }

  delay(100);
}

int ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Serial.println(distance);
  delay(100);

  return distance;
}

/*
  Since Ultrasonic is READ_WRITE variable, onUltrasonicChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onUltrasonicChange()
{
  // Add your code here to act upon Ultrasonic change
}
/*
  Since Switchultra is READ_WRITE variable, onSwitchultraChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSwitchultraChange()
{
  // Add your code here to act upon Switchultra change
}

/*
  Since Stauteultra is READ_WRITE variable, onStauteultraChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onStauteultraChange()
{
  // Add your code here to act upon Stauteultra change
}
/*
  Since Pinultrasonic is READ_WRITE variable, onPinultrasonicChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPinultrasonicChange()
{
  // Add your code here to act upon Pinultrasonic change
}

/*
  Since BoardGPS is READ_WRITE variable, onBoardGPSChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBoardGPSChange()
{
  // Add your code here to act upon BoardGPS change
}

/*
  Since Loaded is READ_WRITE variable, onLoadedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLoadedChange()
{
  // Add your code here to act upon Loaded change
}
