#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

#include "DHT.h"

#define DHTPIN D4

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);



void setup() {

 Wire.begin(); 
 lcd.init();
 lcd.backlight();
 dht.begin();
 
Serial.begin(115200);
}

void loop() {
  
  float h = dht.readHumidity();

  float t = dht.readTemperature();

  Serial.print("Umiditate: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t); 
  Serial.println(" *C ");
  
  lcd.setCursor(0,0);
  lcd.print(t);
  lcd.setCursor(5,0);
  lcd.print(" C");
  lcd.setCursor(9,0);
  lcd.print(h);
  lcd.setCursor(14,0);
  lcd.print(" %\t");


}
