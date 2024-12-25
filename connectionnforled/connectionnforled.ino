#include <SoftwareSerial.h>


int LmotorA= 13;


SoftwareSerial Ser(2,3);              

void setup() 
{
  pinMode(LmotorA,OUTPUT);
  
  
  Ser.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  if(Ser.available())
  {
    char data=Ser.read();
    Serial.print(data);
    if(data=='F')
    {
      Forward();
    }
    else if(data=='B')
    {
      Backward();
    }
    
    else
    {
      Stop();
    }
  }
}

void Forward()
{
  digitalWrite(LmotorA,HIGH);
  
  Serial.println("F");
}
void Backward()
{
  digitalWrite(LmotorA,LOW);
 
  Serial.println("B");
}

void Stop()
{
  digitalWrite(LmotorA,LOW);
  
  Serial.println("S");
}