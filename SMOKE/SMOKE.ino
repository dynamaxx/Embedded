#define led 11
#define SMOKE A0

void setup() 
{
pinMode(led, OUTPUT);
pinMode(SMOKE, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
A();
}
void A()
{
  int SMOKEValue = analogRead(SMOKE);
    Serial.println(SMOKEValue);
    delay(200);
    
  if(SMOKEValue<1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}