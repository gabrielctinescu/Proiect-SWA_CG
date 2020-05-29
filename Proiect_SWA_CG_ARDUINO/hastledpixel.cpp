#include "fastledpixel.h"
#include  <FastLED.h>

#define LED_PIN 24
#define NUM_LEDS 8

CRGB leds[NUM_LEDS];

unsigned long actTime = 0;
unsigned long remTime = 0;


void setup_fastled() {
  
FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
Serial.begin(115200);

}

void fastled_stanga()
{
  FastLED.clear();
    for(int i = 4; i < 8;i++)
    {
      
      leds[i] = CRGB(255, 69, 0);
      FastLED.show();
//    leds[7 - i] = CRGB(255, 255, 0);
//    FastLED.show();
      unsigned long time_now = millis();
      while(millis() < time_now + 200){
      } 
    } 
  FastLED.clear();
 } 

  void fastled_dreapta()
{
  FastLED.clear();
    for(int i = 4; i < 8;i++)
    {
           
//      leds[i] = CRGB(255, 69, 0);
//      FastLED.show();
    leds[7 - i] = CRGB(255, 255, 0);
    FastLED.show();
      unsigned long time_now = millis();
      while(millis() < time_now + 200){
      } 
    } 
  FastLED.clear();
 } 


 void fastled_fata()
{
    for(int i = 0; i < 8;i++)
    {
      
      leds[i] = CRGB(255, 255, 255);
      FastLED.show();

    } 

 } 
