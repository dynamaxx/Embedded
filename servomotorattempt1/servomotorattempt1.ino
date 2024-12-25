#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo;
int currentAngle1 = 90;  
int angleStep1 = 5;  



SoftwareSerial Ser(2, 3); // RX, TX

void setup() 
{
  servo.attach(8); 
   
  
  Ser.begin(9600);
  Serial.begin(9600);
  Serial.println("Servo control ready");
}

void loop() 
{
   if (Serial.available() > 0) 
  {
    char data = Serial.read();


    if (data == 'F') 
    {
      Left();
      Serial.println("F");
    } 
    else if (data == 'B') 
    {
      Right();
      Serial.println("B");
    } 
   
  }
}

void Left() 
{
  currentAngle1 = 180;
currentAngle1 += angleStep1;  
          if (currentAngle1 > 180) 
          {  
          servo.write(currentAngle1);
          Serial.print("Servo moved to: ff");
          Serial.println(currentAngle1);
          }
  
}

void Right() 
{
  currentAngle1 = 0; 
currentAngle1 -= angleStep1; 
              if (currentAngle1 < 0) 
              { 
              servo.write(currentAngle1);  
              Serial.print("Servo moved to: bbb");
              Serial.println(currentAngle1); 
              }
}
