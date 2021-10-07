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
 
 DO NOT REMOVE THIS SECTION IF YOU USE THIS SCRIPT IN YOUR OWN PROJECT!
 
 ========== INFORMATION ==========
 Project: IoT Fishery for Level 8
 Details: -
 Website: https://aquashrimp.technonatura.id
 File ID: A05
 =================================
*/

string pinWL = "A0";
int valueWL = 0;
float waterHeight = 0;
float sensorVoltage = 0;

int maxValue = 1023;
int minWaterHeight  = ;
float sensorLength = 4.0;

void setup() {
  
}

void loop() {
  sensorValue = analogRead(pinWL); // membaca tengan dari sensor dalam bentuk integer
  waterHeight = valueWL*sensorLength/maxValue;
  sensorVoltage = valueWL*5.0/1023;

  // print data ke serial monitor
  if(sesnorValue < minWaterHeight){
    
  }
  delay(1000);
}
