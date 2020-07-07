
#include "AntaresESP8266HTTP.h" 
#define ACCESSKEY"d8134ce7938a1983:c68c33d3e16b5d0e" 
#define WIFISSID "atelputra" 
#define PASSWORD "12345678" 
#define projectName "SMART_BEDROOM" 
#define deviceName "Modulrelay" 

 
AntaresESP8266HTTP antares(ACCESSKEY);

void setup() {  

  Serial.begin(9600);
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID,PASSWORD);
  pinMode(D6,OUTPUT); 
   digitalWrite(D6,HIGH);
  pinMode(D7,OUTPUT); 
   digitalWrite(D7,HIGH);
  pinMode(D8,OUTPUT); 
   digitalWrite(D8,HIGH);
}  

void loop() { 
  antares.get(projectName, deviceName); // Store latest value in buffer 
  if(antares.getSuccess()) { 
  int status = antares.getInt("status");
  
  if (status==1){
    digitalWrite(D6,HIGH); // LAMPU MATI
  
  }  
  else if (status==0){  
    digitalWrite(D6,LOW); // LAMPU HIDUP
    
  }
  else if (status==3){
    digitalWrite(D7,HIGH);// KIPAS MATI

  }   
  else if (status==2){
    digitalWrite(D7,LOW);// KIPAS HIDUP
   
  }  
  else if (status==5){
    digitalWrite(D8,HIGH);// SPEAKER MATI

  }      
  else if (status==4){
    digitalWrite(D8,LOW);// SPEAKER HIDUP
    
  }     
  else if (status==6){
    digitalWrite(D8,LOW);// SPEAKER HIDUP dan LAMPU LED HIDUP 
    digitalWrite(D7,LOW);
    digitalWrite(D6,HIGH);
  }   
  else if (status==7){
    digitalWrite(D6,HIGH);// SPEAKER HIDUP dan LAMPU LED HIDUP 
    digitalWrite(D7,HIGH);
    digitalWrite(D8,HIGH);
  }       
  delay(100); 
 } 
}
