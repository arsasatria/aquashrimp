/*
 * 

 █████   ██████  ██    ██  █████  ███████ ██   ██ ██████  ██ ███    ███ ██████  
██   ██ ██    ██ ██    ██ ██   ██ ██      ██   ██ ██   ██ ██ ████  ████ ██   ██ 
███████ ██    ██ ██    ██ ███████ ███████ ███████ ██████  ██ ██ ████ ██ ██████  
██   ██ ██ ▄▄ ██ ██    ██ ██   ██      ██ ██   ██ ██   ██ ██ ██  ██  ██ ██      
██   ██  ██████   ██████  ██   ██ ███████ ██   ██ ██   ██ ██ ██      ██ ██      
            ▀▀                                                                  
                                                                                
                                                               
 AQUASHRIMP Technology | MTs TechnoNatura
 ⓒ 2021 - Aquashrimp & TechnoNatura
 All Rights Reserved

 ========== INFORMATION ==========
 Project: IoT Fishery for Level 8
 Details: -
 Website: https://aquashrimp.technonatura.id
 File ID: A02
 =================================

*/

#include <OneWire.h>
#include <DallasTemperature.h>

int pinTemp = 5;

OneWire oneWire(pinTemp);

DallasTemperature sensors(&oneWire);

float Celcius=0;
float Fahrenheit=0;

void setup(void){
  Serial.begin(9600);
  sensors.begin();
}

void loop(){ 
  sensors.requestTemperatures(); 
  
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  
  Serial.println("Water Temperature is ");
  Serial.print(Celcius);
  Serial.print(" °C ");
//   Serial.println(" F  ");
//   Serial.println(Fahrenheit);
  
  delay(1000);
}
