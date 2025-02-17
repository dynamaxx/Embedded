#include <SoftwareSerial.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  
#include <Wire.h> 
#include<DHT.h>

SoftwareSerial mySerial(4, 5); 

int _timeout;
int a=0;
unsigned long stime = 0;
unsigned long currentMillis;
const unsigned long period = 5000;


String apiKey = "DP63B1558QZZ9L6X";    
String Host_Name = "SATURDAY";        
String Password = "SATURDAY";         

SoftwareSerial ser(2,3);

int i = 1;
String cmd;

 
#define ANALOG_IN_PIN A0  // Voltage sensor
#define DHTPIN 2          // DHT11 data pin
#define DHTTYPE DHT11     // DHT11 type
#define buzzer 5
#define RELAY_PIN 7   //relay

DHT dht(DHTPIN, DHTTYPE);

float adc_voltage = 0.0;
float in_voltage = 0.0;
float R1 = 30000.0;  // Resistor R1 value (in ohms)
float R2 = 7500.0;   // Resistor R2 value (in ohms)
float ref_voltage = 5.0; // Reference voltage
int adc_value = 0;


int offset =00;


int relay = 9;

void setup()
{
  mySerial.begin(9600); 
  Serial.begin(9600); 
  Serial.begin(115200);                 
  ser.begin(115200);
  ser.println("AT+RST");              

    Serial.begin(115200);
  
  char inv = '"';
  String cmd = "AT+CWJAP";

  cmd += "=";
  cmd += inv;
  cmd += Host_Name;
  cmd += inv;
  cmd += ",";
  cmd += inv;
  cmd += Password;
  cmd += inv;
  ser.println(cmd);

    dht.begin();
  lcd.init();           // Initialize the LCD
  lcd.backlight();      // Turn on the backlight
  lcd.clear();
  pinMode(buzzer, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
}
void loop()
{
  A();


EstablishTCPconnection();
UpdatetoTS();
}

void A(){
  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage * (R1 + R2) / R2;

  // Print voltage to Serial Monitor
  lcd.clear();
  lcd.print(in_voltage, 2);
  

  delay(300);

  // Read DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print DHT11 readings to Serial Monitor
  lcd.print("   TEMP");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  delay(300);

  lcd.clear();
  lcd.print("HUMIDITY");
  lcd.setCursor(0, 1);
  lcd.print( humidity);
  delay(300);
  }

  // Delay for readability
  delay(2000);
  
//temp
  if(temperature>40){
    digitalWrite(buzzer, HIGH);
    digitalWrite(RELAY_PIN, LOW); 
    SendMessagetemp();

  }
  else{
    digitalWrite(buzzer, LOW);  
    digitalWrite(RELAY_PIN, HIGH); // Turn relay ON (activates NO)
  }

//voltage

  if(in_voltage==0){
    digitalWrite(buzzer, HIGH);
    digitalWrite(RELAY_PIN, LOW); 
    SendMessagevolt();
// Turn relay OFF
  }
  else{
    digitalWrite(buzzer, LOW);  
    digitalWrite(RELAY_PIN, HIGH); // Turn relay ON (activates NO)
  }
  
}



void EstablishTCPconnection()
{
  String cmd = "AT+CIPSTART=\"TCP\",\"";          
  cmd += "184.106.153.149";                     
  cmd += "\",80";                                 

  ser.println(cmd);
  Serial.println(cmd);
  if (ser.find("Error")) 
  {
    Serial.println("AT+CIPSTART error");
    return;
  }
}

void UpdatetoTS()
{
            float volt1 = analogRead(A0);
            double voltage1 = map(volt1,0,1023, 0, 2500) + offset;
            voltage1 /=100;
            float v1 = voltage1;

            
            
            float temp = dht.readTemperature();
            

  String state1 = String(v1);
  String state2 = String(temp);

    String getStr = "GET /update?api_key=";         
  getStr += apiKey;
  getStr += "&field1=";
  getStr += String(state1);
  getStr += "&field2=";
  getStr += String(state2);
   getStr += "\r\n\r\n";
  
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());            

  ser.println(cmd);
  Serial.println(cmd);

  if (ser.find(">")) 
  {
    ser.print(getStr);
    Serial.print(getStr);
      lcd.setCursor(0, 1);
  lcd.print("data sent");
  delay(1000);
  lcd.clear();
      ser.print(getStr);
    Serial.print(getStr);
  }
  else 
  {
    ser.println("AT+CIPCLOSE");                
    // alert user
    Serial.println("AT+CIPCLOSE");
   lcd.setCursor(1, 0);
  lcd.print("Check Internet");
  delay(1000);
  lcd.clear();
  }                                
  
}


  void SendMessagetemp()
              {
                  mySerial.println("AT+CMGF=1");    
                  delay(1000);  
                  mySerial.println("AT+CMGS=\"+919019983536\"\r");
                  delay(1000);
                  mySerial.println("TEMPERATURE is HIGH");
                  delay(100);
                   mySerial.println((char)26);
                  delay(1000); 
                                      lcd.setCursor(0, 1);
                    lcd.print("GSM SMS SEND");                
                    delay(2000);
                     lcd.clear();
                    SendMessagetemp1();
                } 

 void SendMessagetemp1()
              {
                  mySerial.println("AT+CMGF=1");    
                  delay(1000);  
                  mySerial.println("AT+CMGS=\"+919945188995\"\r");
                  delay(1000);
                  mySerial.println("TEMPERATURE is HIGH");
                  delay(100);
                   mySerial.println((char)26);
                  delay(1000);
                                      lcd.setCursor(0, 1);
                    lcd.print("GSM SMS SEND");                
                    delay(2000);
                     lcd.clear();
                      EstablishTCPconnection();
                      UpdatetoTS();
           
                } 


void SendMessagevolt()
              {
                  mySerial.println("AT+CMGF=1");    
                  delay(1000);  
                  mySerial.println("AT+CMGS=\"+919019983536\"\r"); 
                  delay(1000);
                  mySerial.println("no voltage");
                  delay(100);
                   mySerial.println((char)26);
                  delay(1000);
                                      lcd.setCursor(0, 1);
                    lcd.print("GSM SMS SEND");                
                    delay(2000);
                     lcd.clear();
                    SendMessagevolt1();
                }

  void SendMessagevolt1()
              {
                  mySerial.println("AT+CMGF=1");    
                  delay(1000);  
                  mySerial.println("AT+CMGS=\"+919945188995\"\r");
                  delay(1000);
                  mySerial.println("no voltage");
                  delay(100);
                   mySerial.println((char)26);
                  delay(1000);
                                      lcd.setCursor(0, 1);
                    lcd.print("GSM SMS SEND");                
                    delay(2000);
                     lcd.clear();
                     EstablishTCPconnection();
                      UpdatetoTS();
              }
