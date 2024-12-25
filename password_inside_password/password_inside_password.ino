#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3};    

// Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String enteredPassword = "";     
String passwords[4] = {"1234", "5678", "abcd", "wxyz"}; // Array of passwords

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey(); 

  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);

    // Loop through the keys 1-4
    for (int i = 0; i < 4; i++) {
      if (key == (i + '1')) { // Check if key matches 1-4
        enteredPassword = ""; // Reset password input
        Serial.print("Enter password for ");
        Serial.print(key);
        Serial.println(":");

        // Loop to get the password
        while (true) {
          char subkey = keypad.getKey();
          if (subkey) {
            enteredPassword += subkey;
            Serial.print("Key Pressed: ");
            Serial.println(subkey);
          }

          // Check if password length matches
          if (enteredPassword.length() == passwords[i].length()) {
            if (enteredPassword == passwords[i]) {
              Serial.print("Correct password for ");
              Serial.print(key);
              Serial.println("!");
            } else {
              Serial.print("Wrong password for ");
              Serial.print(key);
              Serial.println(".");
            }
            break; // Exit loop after checking password
          }
        }
      }
    }
  }
}
