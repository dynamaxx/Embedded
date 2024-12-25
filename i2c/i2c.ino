#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();           // Initialize the LCD
  lcd.backlight();      // Turn on the backlight
  lcd.clear();          // Clear the screen

  // Display messages sequentially
  lcd.print("   JAIN");
  lcd.setCursor(0, 1);
  lcd.print("   COLLEGE");
  delay(3000);

  lcd.clear();
  lcd.print("EC DEPT");
  lcd.setCursor(0, 1);
  lcd.print(" BLAH");
  delay(3000);

  lcd.clear();
  lcd.print("BLAH BLAH");
  lcd.setCursor(0, 1);
  lcd.print("DHOOOOOM");
  delay(3000);

  
}

void loop() {
  lcd.clear();
  lcd.print("WHAT IS");
  lcd.setCursor(0, 1);
  lcd.print("THIS?");
  delay(3000);
}

