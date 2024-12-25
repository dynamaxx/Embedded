#include <pushButton.h>


#include <Arduino.h>

#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif


#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2SNoDAC.h"

// VIOLA sample taken from https://ccrma.stanford.edu/~jos/pasp/Sound_Examples.html
#include "viola.h"

AudioGeneratorWAV *wav;
AudioFileSourcePROGMEM *file;
AudioOutputI2SNoDAC *out;

int speaker = 3;     // LED pin
int button = 16; // push button is connected
int temp = 0; 	 // temporary variable for reading the button pin status


void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);   // declare LED as output
  pinMode(button, INPUT); // declare push button as input

  Serial.begin(9600);

  delay(1000);
  Serial.printf("WAV start\n");

  audioLogger = &Serial;
  file = new AudioFileSourcePROGMEM( viola, sizeof(viola) );
  out = new AudioOutputI2SNoDAC();
  wav = new AudioGeneratorWAV();
  wav->begin(file, out);
}

void loop() {
  // put your main code here, to run repeatedly:
   temp = digitalRead(button);
     
     if (temp == HIGH) {
      digitalWrite(speaker, HIGH);
        if (wav->isRunning()) {
        if (!wav->loop()) wav->stop();
        } else {
        Serial.printf("WAV done\n");
        delay(1000);
  }


      delay(5000);
        
    }
     else {    
        digitalWrite(speaker, LOW);
        Serial.println("Speaker Turned OFF");
        delay(1000);
       }

}