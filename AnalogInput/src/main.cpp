#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
  
} 
 
void loop() { 
  
 
  // read digitized value from the D1 Mini's A/D convertor 
  int iVal = analogRead(A0); 

  
float voltage= iVal * 3.3 / 1024.0;
  //iVal = map(iVal, 0, 1023, 0, 50);

 
  float celsius =  (voltage - 0.33) * 10;
  
  

 
  // print value to the USB port 
  Serial.println("Digitized Value = " + String(voltage) + " V"); 
if(35 < celsius ){
      Serial.println("Output of " + String(iVal) + " is equal to a temperature input of " + celsius + " C , thats WAY TOO HOT !!"); 
  }
    else if(30 <= celsius){
      Serial.println("Output of " + String(iVal) + " is equal to a temperature input of " + celsius + " C , thats hot!!"); 
  }
  else if(25 <= celsius ){
      Serial.println("Output of " + String(iVal) + " is equal to a temperature input of " + celsius + " C , thats warm!!"); 
  }
else if(15 <= celsius){
      Serial.println("Output of " + String(iVal) + " is equal to a temperature input of " + celsius + " C , thats Perfect!!"); 
  }
   else if(10 <= celsius ){
      Serial.println("Output of " + String(iVal) + " is equal to a temperature input of " + celsius + " C , thats cool!!"); 
  }
  else{
      Serial.println("Output of " + String(iVal) + "is equal to a temperature input of " + celsius + " C , thats cold!!"); 
  }
 
  // wait 0.5 seconds (500 ms) 
  delay(500); 
} 