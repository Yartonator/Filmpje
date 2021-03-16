#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
//#include <WiFi.h>
//#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Stepper.h>

#define DHTPIN 32
#define DHTTYPE DHT11
#define minpot 34
#define maxpot 35
#define led 26
#define steps 2038

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(21, 19, 36, 39, 23, 22);
Stepper stepper(steps, 13, 12, 14, 27);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  dht.begin();
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(minpot, INPUT);
  pinMode(maxpot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float mintemp = map(analogRead(minpot), 0, 4096, 0, 30);
  float maxtemp = map(analogRead(maxpot), 0, 4096, 0, 30);
  float temp = dht.readTemperature();
  Serial.println(mintemp);
  Serial.println(maxtemp);
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  if ((mintemp+0.5) > temp)
  {
    
  }
}
