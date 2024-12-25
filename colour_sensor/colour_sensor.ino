#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define OUT 6

int RED_freq = 0;
int GREEN_freq = 0;
int BLUE_freq = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  pinMode(OUT, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(115200);
}
void loop() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  RED_freq = pulseIn(OUT, LOW);
  Serial.print("R = ");
  Serial.print(RED_freq);
  delay(100);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  GREEN_freq = pulseIn(OUT, LOW);
  Serial.print(" G = ");
  Serial.print(GREEN_freq);
  delay(100);
 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  BLUE_freq = pulseIn(OUT, LOW);
  Serial.print(" B = ");
  Serial.println(BLUE_freq);
  delay(100);
}