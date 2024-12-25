// Include DHT library
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
#define ANALOG_IN_PIN A0  // Voltage sensor pin
#define DHTPIN 2          // DHT11 data pin
#define DHTTYPE DHT11     // DHT11 sensor type

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Variables for voltage sensor
float adc_voltage = 0.0;
float in_voltage = 0.0;
float R1 = 30000.0;  // Resistor R1 value (in ohms)
float R2 = 7500.0;   // Resistor R2 value (in ohms)
float ref_voltage = 5.0; // Reference voltage
int adc_value = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize DHT sensor
  dht.begin();
  lcd.init();           // Initialize the LCD
  lcd.backlight();      // Turn on the backlight
  lcd.clear();
}

void loop() {
  // Read voltage sensor
  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage * (R1 + R2) / R2;

  // Print voltage to Serial Monitor
  lcd.clear();
  lcd.print(in_voltage, 2);
  

  // Read DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print DHT11 readings to Serial Monitor
  lcd.print("   TEMP");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  delay(3000);

  lcd.clear();
  lcd.print("HUMIDITY");
  lcd.setCursor(0, 1);
  lcd.print( humidity);
  delay(3000);
  }

  // Delay for readability
  delay(2000);
}


///////////

// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// // Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup() {
//   lcd.init();           // Initialize the LCD
//   lcd.backlight();      // Turn on the backlight
//   lcd.clear();          // Clear the screen

//   // Display messages sequentially
//   lcd.print("   TEMP");
//   lcd.setCursor(0, 1);
//   lcd.print(temperature);
//   delay(3000);

//   lcd.clear();
//   lcd.print("HUMIDITY");
//   lcd.setCursor(0, 1);
//   lcd.print( humidity);
//   delay(3000);

//   lcd.clear();
//   lcd.print("BLAH BLAH");
//   lcd.setCursor(0, 1);
//   lcd.print("DHOOOOOM");
//   delay(3000);

  
// }

// void loop() {
//   lcd.clear();
//   lcd.print("WHAT IS");
//   lcd.setCursor(0, 1);
//   lcd.print("THIS?");
//   delay(3000);
// }
