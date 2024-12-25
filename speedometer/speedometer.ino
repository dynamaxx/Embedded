#define LED_PIN 11     // Pin connected to an LED for visual feedback
#define SPEED_PIN A0   // Pin connected to the sensor's analog output

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the speed sensor
  int speedValue = analogRead(SPEED_PIN);
  
  // Print the analog sensor value to the Serial Monitor
  Serial.println(speedValue);
  
  // Control the LED based on the sensor value (example threshold)
  if (speedValue > 500) {   // Adjust the threshold based on your testing
    digitalWrite(LED_PIN, HIGH);  // Turn on LED if object detected
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn off LED if no object
  }
  
  delay(200); // Delay for stability and readability in Serial Monitor
}
