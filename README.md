# trash_project_gps_ArduinoIoTCloud

- [Libraries](#Libraries)
- [Hardware](#Hardware)
- [diagram](#diagram)
- [connections](#connections)

## diagram

![diagram](https://cdn.discordapp.com/attachments/810756128295354419/1103136999294107658/image.png)

## Libraries

- `ArduinoIoTCloud`
- `TinyGPS`
- `SoftwareSerial`

## Hardware

- In this project I'll use **DOIT ESP32 DEVKIT V1 Board**. You can use any Arduino boards or esp that are compatible with the Arduino IoT Cloud:
  - DOIT ESP32 DEVKIT V1 Board
  - NEO-6M GPS
  - Ultrasonic Distance Sensor - HC-SR04


## connections 

- [`ultrasonic`](#pin-on-ultrasonic)
- [`GPS neo 6m`](#Pin-on-GPS-neo-6m)

### Pin on ultrasonic

| ultrasonic | esp32   | NODEMCU |
| ---------- | ------- | ------- |
| ECHO       | GPIO 13 | D13     |
| TRIG       | GPIO 12 | D12     |
| VCC        | 3V      | 3V      |
| GND        | GND     | GND     |

### Pin on GPS neo 6m

| GPS neo 6m | esp32   | NODEMCU |
| ---------- | ------- | ------- |
| RX         | GPIO 25 | D25     |
| TX         | GPIO 26 | D26     |
| VCC        | 3V      | 3V      |
| GND        | GND     | GND     |
