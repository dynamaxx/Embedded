#define x A0
#define y A1
#define z A2

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(x, INPUT);
pinMode(y, INPUT);
pinMode(z, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int xvalue = analogRead(x);
Serial.println("x value: ");
Serial.println(xvalue);
delay(1000);
int yvalue = analogRead(y);
Serial.println("y value: ");
delay(1000);
Serial.println(yvalue);
int zvalue = analogRead(z);
Serial.println("z value: ");
Serial.println(zvalue);
delay(1000);
}
