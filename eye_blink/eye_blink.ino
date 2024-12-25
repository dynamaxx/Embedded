#define eye A1
void setup() {
  // put your setup code here, to run once:
//pinMode(eye, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
A();
}

void A(){
  int eyeValue = analogRead(eye);
  Serial.println(eyeValue);
  delay(200);
}