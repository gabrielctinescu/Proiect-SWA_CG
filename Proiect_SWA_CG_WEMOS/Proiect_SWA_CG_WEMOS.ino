
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"

#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

#include "DHT.h"

#define DHTPIN D4

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Internetc1";
const char* password = "Magazin89";

const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x08;

ESP8266WebServer server(80);


int secunde1 = 0;
int secunde2 = 0;

int minute1 = 0;
int minute2 = 0;

int ora1 = 0;
int ora2 = 0;

unsigned long previousMillis = 0;
unsigned long previousMilliss = 0;
long interval;



void setup() {
  
  Serial.begin(115200);
  
  lcd.init();
  lcd.backlight();
  
  dht.begin();
  WiFi.begin(ssid,password); 
  Wire.begin(I2C_MASTER); 
  
  while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.println(".");
   }
  if (WiFi.status() == WL_CONNECTED)
    {
    
      Serial.println("");
      Serial.println("Wireless conectat! ");

      Serial.print("Adresa IP: ");
      Serial.println(WiFi.localIP());

      server.on("/", handle_index);
      server.on("/forward", handle_forward);
      server.on("/reverse", handle_reverse);
      server.on("/left", handle_left);
      server.on("/right", handle_right);
      server.on("/cercle", handle_cercle);
      server.on("/stop", handle_stop);
      server.on("/ocolitor", handle_ocolitor);
      server.on("/urmaritor", handle_urmaritor);
      
      server.on("/ora", handle_ora);
      server.on("/minute", handle_minute);


   
      server.begin();

      Serial.println("Serverul a pornit");
      lcd.setCursor(1,1);
      lcd.print("ON");
    }else{
      Serial.println("Eroare ");
      lcd.setCursor(1,1);
      lcd.print("OFF");
    }
    

  
}

void loop() {
 //=====senzor h/t afisare display========== 
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
//======================================

//====ceas afisare display======
  unsigned long currentMillis = millis();
  unsigned long currentMilliss = millis();
  
  if ( currentMilliss  - previousMilliss >= 1000)
    {
      secunde1++;
      previousMilliss = currentMilliss;
      
      if(secunde1 == 10)
        {
          secunde1 = 0;
          secunde2++;
        }
        if (secunde2 == 6)
        {
          secunde2 = 0;
          minute1++;
        }
        
        if(minute1 == 10)
        {
          minute1 = 0;
          minute2++;
        }
        if (minute2 == 6)
        {
          minute2 = 0;
          ora1++;
        }
        if (ora1 == 10)
        {
          ora1 = 0;
          ora2++;
        }
        if (ora1 == 5 && ora2 == 2)
        {
            ora1 = 0;
            ora2 = 0;
        }
  }
     
//if (buton2==0 && buton1==1 && buton3==1){
//      interval = 600;
//    if ( (currentMillis - previousMillis) >= interval){
//        previousMillis = currentMillis;
//        if (buton2 == 0){
//          minute1++;
//        }
        if(minute1 == 10)
        {
          minute1 = 0;
          minute2++;
        }
        if (minute2 == 6)
        {
          minute2 = 0;
        }
//    }
//}
//if (buton1==0 && buton2==1 && buton3==1){
//      interval = 600;
//    if ( (currentMillis - previousMillis) >= interval){
//        previousMillis = currentMillis;
//        if (buton1 == 0){
//          ora1++;
//        }
        if (ora1 == 10)
        {
          ora1 = 0;
          ora2++;
        }
        if (ora1 == 4 && ora2 == 2){
            ora1 = 0;
            ora2 = 0;
        }
//
//
//    }


  lcd.setCursor(11,1);
  lcd.print(secunde1);
  
  lcd.setCursor(10,1);
  lcd.print(secunde2);
  
  lcd.setCursor(9,1);
  lcd.print(":");
  
  lcd.setCursor(8,1);
  lcd.print(minute1);
  
  lcd.setCursor(7,1);
  lcd.print(minute2);
  
  lcd.setCursor(6,1);
  lcd.print(":");
  
  lcd.setCursor(5,1);
  lcd.print(ora1);
  
  lcd.setCursor(4,1);
  lcd.print(ora2);

  

  server.handleClient();
}


void handle_stop() {
 server.send(200, "text/html", PAGINA_INDEX);
     trimite(1);
}
void handle_forward() {
 server.send(200, "text/html", PAGINA_INDEX);
     trimite(2);
}
void handle_reverse() {
  server.send(200, "text/html", PAGINA_INDEX);
      trimite(3);
}
void handle_left() {
  server.send(200, "text/html", PAGINA_INDEX);
      trimite(4);
}
void handle_right() {
  server.send(200, "text/html", PAGINA_INDEX);
      trimite(5);
}
void handle_cercle() {
  server.send(200, "text/html", PAGINA_INDEX);
      trimite(6);
}
void handle_ocolitor() {
  server.send(200, "text/html", PAGINA_INDEX);
      trimite(7);
}
void handle_urmaritor() {
  server.send(200, "text/html", PAGINA_INDEX);
      trimite(8);
}
void handle_minute() {
  server.send(200, "text/html", PAGINA_INDEX);
      minute1++;
}
void handle_ora() {
  server.send(200, "text/html", PAGINA_INDEX);
      ora1++;
}
void handle_index(){
  String pagina = PAGINA_INDEX;
  server.send(200,"text/html",pagina);
}

void trimite(int y)
{
   Wire.beginTransmission(I2C_SLAVE); // transmit to device #8
   Wire.write(y);              // sends one byte
   Wire.endTransmission();    // stop transmitting
}
