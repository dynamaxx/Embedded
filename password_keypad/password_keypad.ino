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
String correctPassword = "1234"; 
String secondpass = "5678";

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey(); 

  if (key) {
    enteredPassword += key; 
    Serial.print("Key Pressed: ");
    Serial.println(key);

if (enteredPassword.length() == correctPassword.length()) {
      if (enteredPassword == correctPassword) {
        Serial.println("enter second key");
        if(correctPassword==secondpass){
        Serial.println("welcome");
        }
      } else {
        Serial.println("wrong password");
      }
      enteredPassword = ""; 
    }
  }
}
