#define BLYNK_PRINT Serial

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "b76d1967b13243fda77e6963c8278b11";
char ssid[] = "MSI 7544";
char pass[] = "5T347$d4";

//Set LED on board
int led2 = D1;

BlynkTimer timer;

WidgetLED led1(V1);

void sendSensor()
{
  int sensorValue = analogRead(A0);
  
  Serial.println(sensorValue);
  Blynk.virtualWrite(V5, sensorValue);

  if (sensorValue < 800) {
    led1.on();
    digitalWrite(led2, HIGH);
  } else {
    led1.off();
    digitalWrite(led2, LOW);
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(led2, OUTPUT);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  
}
