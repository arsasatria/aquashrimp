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

#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>
#include <Keypad.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 7
#define waterlevelPower 12
#define waterlevelPin A0
#define echoPin 3 //HC-SR04
#define trigPin 4 //HC-SR04

int pos = 00;
int waterlevelValue;
int vncvi = 0;
int maximumRange = 200;
int minimumRange = 00;
long duration, distance;
float suhuSekarang;
const byte ROWS = 4; 
const byte COLS = 4;
char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
}; 

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensorSuhu(&oneWire);
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
RTC_DS3231 rtc;
DateTime now;
DateTime jamsusun;

void setup(){
  pinMode(waterlevelPower, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(waterlevelPower, LOW);

  rtc.begin();
  sensorSuhu.begin();
  Serial.begin(9600);
  Wire.begin();
  
  myservo.attach(13);
  

  Wire.beginTransmission(0x3F);
  if (Wire.endTransmission())
  {
    lcd = LiquidCrystal_I2C(0x27, 16, 2);
  }
       lcd.init();
   
  lcd.backlight();
   
  lcd.print("CNF1 Autofeeder");
  lcd.setCursor(0, 1);
  lcd.print("  -AQUASHRIMP-");
  delay(1000);
  lcd.clear();

  lcd.print("Updating Module");
  lcd.setCursor(0, 1);
  lcd.print("-");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("--");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("---");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("----");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("-----");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("-------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("--------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("---------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("----------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("-----------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("------------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("-------------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("--------------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("---------------");
  delay(100);
//  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("----------------");
  delay(100);
//  lcd.clear();


//  rtc.adjust(DateTime(2021, 11, 9, 18, 59, 00));

    pos = 50;
    myservo.write(pos);
    delay(100);
    pos = 0;
    myservo.write(pos);
    delay(500);

}
 
void loop(){

    waterlevelValue = analogRead(waterlevelPin);


     
    now = rtc.now();

//    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//    Serial.print(',');
//
//    Serial.print(now.day(), DEC);
//    Serial.print('/');
//    Serial.print(now.month(), DEC);
//    Serial.print('/');
//    Serial.print(now.year(), DEC);
//    Serial.print('\t');
//
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();
    
    Serial.println();

    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print(now.hour());

    lcd.setCursor(2,0);
    lcd.print(":");
    
    lcd.setCursor(3,0);
    lcd.print(now.minute());

    lcd.setCursor(5,0);
    lcd.print(":");
    
    lcd.setCursor(6,0);
    lcd.print(now.second());

//    sensors.requestTemperatures();
    suhuSekarang = ambilSuhu();
lcd.setCursor(0,1);
lcd.print("Suhu Air:");
lcd.setCursor(9,1);
lcd.print(suhuSekarang);

//    if(vncvi == 5){
    pos = 50;
    myservo.write(pos);
    delay(100);
    pos = 0;
    myservo.write(pos);
//    }

    digitalWrite(trigPin, LOW);delayMicroseconds(2);
digitalWrite(trigPin, HIGH);delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
 
//perhitungan untuk dijadikan jarak
distance = duration/58.2;
 
/* Kirim angka negatif ke komputer dan Turn LED ON 
untuk menunjukkan "di luar jangkauan" */
 
if (distance >= maximumRange || distance <= minimumRange)
{
Serial.println("-1");digitalWrite(LEDPin, HIGH);
}
else {
 
/*Kirim jarak ke komputer menggunakan Serial protokol, dan
menghidupkan LED OFF untuk menunjukkan membaca sukses. */
Serial.println(distance);
digitalWrite(LEDPin, LOW);
 
//waktu tunda 50mS
delay(50);
}
    
int waterlevelValue = analogRead(waterlevelPin);

    
    delay(1000);
}

float ambilSuhu(){
   sensorSuhu.requestTemperatures();
   float suhu = sensorSuhu.getTempCByIndex(0);
   return suhu;   
}
