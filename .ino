#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// --- CONFIGURATION SECTION (Change things here easily) ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define I2C_ADDRESS   0x3C

// SENSOR SETTINGS
#define SENSOR_PIN    2      // Digital pin connected to the DHT sensor
#define SENSOR_TYPE   DHT11  // Change to DHT22 or DHT21 if needed
#define UPDATE_DELAY  2000   // Time between readings (ms)

// ALERT THRESHOLDS
const float TEMP_HIGH_THRESHOLD = 35.0; // Celsius
const int ledPin = 13; 

// Objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(SENSOR_PIN, SENSOR_TYPE);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(20, 20);
  display.println("System Initializing...");
  display.display();
  delay(1000);
}

void loop() {
  // 1. Read Data
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed
  if (isnan(h) || isnan(t)) {
    showError();
    return;
  }

  // 2. Alert Logic (LED turns on if too hot)
  if(t > TEMP_HIGH_THRESHOLD) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // 3. Update Display
  updateOLED(t, h);
  
  // 4. Serial Debugging
  Serial.print("Humidity: "); Serial.print(h);
  Serial.print("%  Temperature: "); Serial.print(t); Serial.println("C");

  delay(UPDATE_DELAY);
}

// --- MODULAR FUNCTIONS ---

void updateOLED(float temp, float hum) {
  display.clearDisplay();
  
  // Header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ENV MONITOR v1.0");
  display.drawFastHLine(0, 10, 128, WHITE);

  // Temperature
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("T: "); 
  display.print(temp, 1);
  display.print((char)247); // Degree symbol
  display.print("C");

  // Humidity
  display.setCursor(0, 45);
  display.print("H: ");
  display.print(hum, 1);
  display.print("%");

  display.display();
}

void showError() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.println("Sensor Error!");
  display.println("Check Wiring...");
  display.display();
}
