# RFID-Open-and-Close-Servo
Opening and Closing a servo motor using RFID scan 

Using 3 components:
- NodeMCU 8266
- RFID-RC522
- Servo 180

Connecting the RFID to the Microcontroller:
- 3.3v -> 3.3v
- GND -> GND
- RST -> D0
- SDA -> D1
- SCK -> D5
- Miso -> D6
- Mosi -> D7

Connecting the Servo to the Microcontroller:
- 3.3v -> 3.3v
- GND -> GND
- Data -> D3

by scanning the card to retrieve the card UID and validating the card to give instructions to the servo by turning 0 degree or 180 degree based on the given value of the RFID chip. the validation step uses
