#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>       
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

char auth[] = "blynk token'i";
char ssid[] = "wifi adı";
char pass[] = "wifi şifre";

#define DHTPIN D1  
#define DHTTYPE DHT11


DHT dht(D1, DHT11);
SimpleTimer timer;


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Blynk.virtualWrite(V1, t); 
  Blynk.virtualWrite(V2, h);  

}

void setup()
{
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass);

  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run(); 
  timer.run(); 
}
