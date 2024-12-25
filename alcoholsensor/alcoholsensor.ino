#define led 11
#define alcohol A0

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
  int alcoholValue = analogRead(alcohol);
    Serial.println(alcoholValue);
    delay(200);
    
  if(alcoholValue<50)
  {
    digitalWrite(led, HIGH);
    Serial.print("LED ON");

  }
  else{
    digitalWrite(led, LOW);
    Serial.print("LED OFF");
  }
}