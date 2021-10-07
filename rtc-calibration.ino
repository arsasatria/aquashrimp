#include <iostream>
#include <chrono>
#include <ctime>
#include <DS3231.h>

DS3231  rtc(SDA, SCL);
using namespace std;

void setup(){
  time_t now = time(0);   
  char* dt = ctime(&now);
  
  rtc.setDate((ltm->tm_mday << endl), (1 + ltm->tm_mon<< endl), (1900 + ltm->tm_year<<endl));
  rtc.setTime((1 + ltm->tm_hour), (1 + ltm->tm_min), (1 + ltm->tm_sec));
//   rtc.setDOW(6);
}
void loop(){
  
}
