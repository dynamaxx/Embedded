#define smoke A0
#define alcohol A1
#define limitswitch A2
#define ldr A3
#define led 11


void setup() {
  pinMode(limitswitch, INPUT_PULLUP);
  pinMode(ldr, INPUT_PULLUP);
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  A();  // Call the functio n A
}

void A() {
  int limitswitchValue = analogRead(limitswitch);
  int ldrValue = analogRead(ldr);
  Serial.println(ldrValue);
  
  if (limitswitchValue < 100 || ldrValue >= 0) {
    

    int alcoholValue = analogRead(alcohol);
    Serial.println(alcoholValue);
    delay(200);

    int smokeValue = analogRead(smoke);
    Serial.println(smokeValue);
    delay(200);

    if (alcoholValue < 1000 && smokeValue > 1000) {
      digitalWrite(led, HIGH);  // Turn LED ON
      Serial.println("LED ON");
    } else {
      digitalWrite(led, LOW);  // Turn LED OFF
      Serial.println("LED OFF");
    }
  }
  else{
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
    delay(200);
  }

}