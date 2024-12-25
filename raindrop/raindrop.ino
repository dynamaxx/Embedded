#define led 11
#define rain A0

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
  int rainValue = analogRead(rain);
    Serial.println(rainValue);
    delay(200);
    
  if(rainValue<500)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}