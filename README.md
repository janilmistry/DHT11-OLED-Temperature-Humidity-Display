DHT11-OLED-Temperature-Humidity-Display
Overview
This project uses a DHT11 temperature and humidity sensor to measure environmental conditions and display the results on an OLED display. It also calculates and displays the heat index (both in Celsius and Fahrenheit). The readings are updated every 2 seconds on the OLED screen, and sensor data is also output to the Serial Monitor for debugging purposes.

Features
Measures temperature and humidity using the DHT11 sensor.
Displays temperature (°C & °F), humidity (%), and heat index (°C & °F) on a 128x64 OLED display.
Outputs data to the Serial Monitor for debugging.
Error handling for sensor failure, displaying "Sensor Error!" on the OLED if the sensor reads invalid values.
Hardware Required
Arduino (any compatible board), such as Arduino Uno, Arduino Nano, etc.
DHT11 Sensor (or compatible temperature and humidity sensor).
OLED Display (128x64, SSD1306 or similar).
Jumper wires for connections.
Circuit Diagram
DHT11 Sensor:

VCC to 5V (or 3.3V depending on your board)
GND to GND
Data Pin to Digital Pin 2 on Arduino (or any other pin you choose).
OLED Display:

VCC to 5V (or 3.3V depending on your board)
GND to GND
SCL to A5 (on Arduino Uno)
SDA to A4 (on Arduino Uno)
Software Required
Arduino IDE (latest version recommended).
Adafruit_SSD1306 and Adafruit_GFX libraries for the OLED display.
DHT sensor library for DHT11.
Installation
Open the Arduino IDE.
Install the necessary libraries:
Adafruit SSD1306: In Arduino IDE, go to Sketch > Include Library > Manage Libraries. Search for "Adafruit SSD1306" and install it.
Adafruit GFX: Similarly, search for and install "Adafruit GFX".
DHT Sensor Library: Search for and install "DHT sensor library".
Connect the hardware components according to the circuit diagram.
Upload the code to your Arduino board.
Open the Serial Monitor to view the data output (set the baud rate to 9600).
The OLED display should show the temperature, humidity, and heat index.
Code Explanation
DHT Sensor: The code initializes the DHT11 sensor, reads humidity and temperature values, and computes the heat index.
OLED Display: The data is displayed on a 128x64 OLED screen. The screen shows:
Humidity percentage
Temperature in Celsius and Fahrenheit
Heat index in Celsius and Fahrenheit
Error Handling: If the sensor fails to return valid data (due to a connection issue or malfunction), the display shows a "Sensor Error!" message.
