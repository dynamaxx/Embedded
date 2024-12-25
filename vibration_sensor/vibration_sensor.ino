#define vibrate 7
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
  int vibrateValue = digitalRead(vibrate);
  Serial.println(vibrateValue);
  delay(200);
}