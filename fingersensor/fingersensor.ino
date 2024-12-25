#define fing A0

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
A();
}
void A(){
int fingValue = analogRead(fing);
Serial.println(fingValue);
delay(200);
}