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
 File ID: INDEX
 =================================

*/

int pinSolenoid = 8;

void setup(){
  pinMode(pinSolenoid, OUTPUT);
}

void loop(){
  digitalWrite(pinSolenoid, HIGH);
  delay(1000);
  digitalWrite(pinSolenoid, LOW);
}
