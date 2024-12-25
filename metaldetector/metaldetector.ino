int sensorPin = A0; // Connect the output signal to A0
int sensorValue = 0;
#define buzzer

void setup() {
  Serial.begin(9600); // Start the Serial Monitor
  pinMode(sensorPin, INPUT); // Set the pin as input
}

void loop() {
  sensorValue = analogRead(sensorPin); // Read the sensor value
  Serial.println(sensorValue); // Print the value to Serial Monitor
  if(sensorValue>500){
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }
  delay(500); // Add a small delay
}
