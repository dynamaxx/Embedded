#include <NewPing.h>

#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 200
#define led 11
#define limitswitch A0
#define smoke A1
#define ldr A2

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int count=0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(limitswitch, INPUT_PULLUP);
  pinMode(ldr, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  delay(50);
  int limitswitchValue = analogRead(limitswitch);
  int ldrValue = analogRead(ldr);
  Serial.println(ldrValue);
  delay(200);
  int smokeValue = analogRead(smoke);
    Serial.println(smokeValue);
    delay(200);

  unsigned int distance = sonar.ping_cm();
  if(limitswitchValue<100 || smokeValue>1000){
  
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  if(distance<20){
     count++;  
      Serial.print("count: ");
      Serial.println(count); 
      digitalWrite(led, HIGH); 
      Serial.println("LED ON"); 
    } 
    else if(ldrValue>20){
      count--;
      Serial.print("count: ");
      Serial.println(count);
       digitalWrite(led, HIGH);  
      Serial.println("LED ON");
    }
    else {
      digitalWrite(led, LOW); 
      Serial.println("LED OFF");
    }
  }
  else{
    digitalWrite(led, LOW);  // Turn LED OFF
      Serial.println("LED OFF");
  }
}
