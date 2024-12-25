#define led 11
#define ir A0

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
  int irValue = analogRead(ir);
    Serial.println(irValue);
    delay(200);
    
  if(irValue>10)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}