#define led 11
#define moisture A0

void setup() 
{
pinMode(led, OUTPUT);
//pinMode(moisture, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
A();
}
void A()
{
  int moistureValue = analogRead(moisture);
    Serial.println(moistureValue);
    delay(200);
    
  if(moistureValue>500)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}