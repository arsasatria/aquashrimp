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
 File ID: A03
 =================================
*/

#include <Wire.h>
#include <DS3231.h>
using namespace std;
struct t; 
 

String feedTimeAquashrimp[3] = {"07:00:00","12:00:00","20:00:00"};
int pinRelayAutofeeder = 7;
int relayDuration = 1000;
int relayEvents = 0;
int dangerIndicatorLight = 4;
String rtcTime = "";
 
void setup(){
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
}
 
void loop(){
  
  DS3231_get(&t);
  rtcTime = (t.hour) . ":" . (t.min) . "" . (t.sec);
 
  //relayEvents goes door be like-an, sshhh..
  
  if(rtcTime == feedTimeAquashrimp[0]){
    digitalWrite(pinRelayAutofeeder, HIGH);
    delay(relayDuration);
    digitalWrite(pinRelayAutofeeder, LOW);
  }else if(rtcTime == feedTimeAquashrimp[1]){
    digitalWrite(pinRelayAutofeeder, HIGH);
    delay(relayDuration);
    digitalWrite(pinRelayAutofeeder, LOW);
  }else if(rtcTime == feedTimeAquashrimp[2]){
    digitalWrite(pinRelayAutofeeder, HIGH);
    delay(relayDuration);
    digitalWrite(pinRelayAutofeeder, LOW);
  }else{
    //Idle
  }
  
  delay (1000); //delay 1 sec befor reload void loop
}
 
