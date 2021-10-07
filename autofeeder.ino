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
 File ID: A03
 =================================
*/

#include <iostream>
#include <DS3231.h>
using namespace std;
 
DS3231  rtc(SDA, SCL);
string feedTime[3] = {"07:00:00","12:00:00","20:00:00"};
int pinRelayAutofeeder = 7;
int relayDuration = 1000;
int relayEvents = 0;
int dangerIndicatorLight = 4;
 
void setup(){
  rtc.begin();
}
 
void loop(){
  
  var rtcTime = rtc.getTimeStr(); //prosedur pembacaan waktu
  
//   while(relayEvents < 3){
    
    
//     relayEvents++;
//   }
  
  if(rtcTime == feedTime[0]){
    digitalWrite(pinRelayAutofeeder, HIGH);
    delay(relayDuration);
    digitalWrite(pinRelayAutofeeder, LOW);
  }else if(rtcTime == feedTime[1]){
    digitalWrite(pinRelayAutofeeder, HIGH);
    delay(relayDuration);
    digitalWrite(pinRelayAutofeeder, LOW);
  }else if(rtcTime == feedTime[2]){
    digitalWrite(pinRelayAutofeeder, HIGH);
    delay(relayDuration);
    digitalWrite(pinRelayAutofeeder, LOW);
  }else{
    //Idle
  }
  
  delay (1000); //delay 1 sec befor reload void loop
}
 
