#define led 11
#define alcohol A0
#define smoke A1
#define sound A2

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
  int alcoholValue = analogRead(alcohol);
    Serial.println(alcoholValue);
    delay(2000);
    
  if(alcoholValue<1000)
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
  int smokeValue = analogRead(smoke);
    Serial.println(smokeValue);
    delay(2000);
    
  if(smokeValue<1000)
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
  int soundValue = analogRead(sound);
    Serial.println(soundValue);
    delay(200);
    
  if(soundValue<1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
}
}

