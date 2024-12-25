#define led 11
#define RD A0
#define moisture A1
#define flame A2

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
C();
}
void A()
{
  int RDValue = analogRead(RD);
    Serial.println(RDValue);
    delay(200);
    
  if(RDValue<1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}
void B()
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
void C()
{
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
