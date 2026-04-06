# 🌡️ Universal Temperature & Humidity Monitor

A professional-grade environment monitoring system using **Arduino**, **OLED Display**, and **DHT Series sensors**. This project features modular code that allows you to swap sensors with a single line change.

## 🚀 Features
* **Multi-Sensor Support:** Compatible with DHT11, DHT22, and DHT21.
* **Modular Code:** High-level functions for OLED updates and error handling.
* **Real-time Alerts:** On-board LED triggers when temperature exceeds safe thresholds.
* **Precision Display:** Shows data with 1-decimal point accuracy and degree symbols.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno / Nano / Mega
* **Sensor:** DHT11 or DHT22 (Configurable in code)
* **Display:** 128x64 I2C OLED (SSD1306)
* **Alert:** 1x LED (Built-in Pin 13)

## 🔌 Connection Table
| Sensor Pin | Arduino Pin |
| :--- | :--- |
| **DHT VCC** | 5V |
| **DHT Data** | Pin 2 |
| **DHT GND** | GND |
| **OLED SDA** | A4 |
| **OLED SCL** | A5 |



## ⚙️ How to Customize
1. Open `code.ino`.
2. To use a **DHT22** instead of DHT11, change line 14:
   `#define SENSOR_TYPE DHT22`
3. To change the high-temp alert, update line 18:
   `const float TEMP_HIGH_THRESHOLD = 35.0;`

---
*Created by [Janil Mistry](https://github.com/janilmistry) - GPA Ahmedabad Engineering Student.*
