#include "DHT.h" 
#include "AntaresESP8266HTTP.h" 
#define DHTPIN D7 
#define DHTTYPE DHT11 
 
#define ACCESSKEY "069eb3f27064b862:911d9289cb3810c5" 
#define WIFISSID "atelputra" 
#define PASSWORD "12345678" 
 
#define projectName "SMART_BEDROOM" 
#define deviceName "SensorSuhu" 
 
AntaresESP8266HTTP antares(ACCESSKEY);
DHT dht(DHTPIN, DHTTYPE); 
 
void setup() { 

Serial.begin(115200); 
  Serial.println("DHTxx test!");  
  dht.begin(); 
  antares.setDebug(true);  
  antares.wifiConnection(WIFISSID,PASSWORD); 
  pinMode(D5,OUTPUT);
  digitalWrite(D5,HIGH);
} 
void loop() { 
  float h = dht.readHumidity(); 
  float t = dht.readTemperature();  
  float f = dht.readTemperature(true); 
   if (isnan(h) || isnan(t) || isnan(f)) { 
    Serial.println("Failed to read from DHT sensor!"); 
   return; 
  }  
  antares.add("Temperature", t);
  antares.add("Humidity", h);  
  antares.send(projectName, deviceName);  
  delay(1000); 

 if (t>=31){
  digitalWrite(D5,LOW);
  delay(100);
 }
 else {
  digitalWrite(D5,HIGH);
  delay(100);
 }
} 
