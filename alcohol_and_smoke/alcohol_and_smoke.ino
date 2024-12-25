#define led 11
#define alcohol A0
#define smoke A1


void setup() 
{
pinMode(led, OUTPUT);

Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
A();


}
void A()
{
  int alcoholValue = analogRead(alcohol);
    Serial.println(alcoholValue);
    delay(200);
    int smokeValue = analogRead(smoke);
    Serial.println(smokeValue);
    delay(200);
    
  if(alcoholValue<1000 && smokeValue>1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}


