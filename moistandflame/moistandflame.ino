#define led 11
#define moisture A0
#define flame A1
void setup() 
{
pinMode(led, OUTPUT);

Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
A();
B();
}
void A()
{
  int moistureValue = analogRead(moisture);
    Serial.println(moistureValue);
    delay(200);
    
  if(moistureValue<1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}
void B(){
  int flameValue = analogRead(flame);
    Serial.println(flameValue);
    delay(200);
    
  if(flameValue<1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
}
}
