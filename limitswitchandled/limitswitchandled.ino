#define led 11
#define limitswitch A0

void setup() 
{
pinMode(led, OUTPUT);
pinMode(limitswitch, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
A();

}
void A()
{
  int limitswitchValue = analogRead(limitswitch);
    Serial.println(limitswitchValue);
    delay(200);
    
  if(limitswitchValue<1000)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}