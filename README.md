# trash_project_gps_ArduinoIoTCloud

- [ultrasonic](#Pin-on-ultrasonic)
- [GPS neo 6m](#Pin-on-GPS-neo-6m)

![daigram](https://cdn.discordapp.com/attachments/810756128295354419/1103136999294107658/image.png)




Libraries
---------
* `ArduinoIoTCloud`  
* `TinyGPS`
* `SoftwareSerial`


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
