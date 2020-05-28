const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x08;

//====initializare i2c====

#include <Wire.h> 

//initializare motoare====
#include "directie_motoare.h"

//initializare senzori linie
#include "urmaritor_linie.h"

// initializare ultrasunete
#include "distanta_ultrasunete.h"

//initializare ocolitor obstacole

#include "ocolitor_obstacole.h"

//===initializare led 8x8 ====
#include "semnalizari.h"


//===initializare infrared=====

#include <IRremote.h>

int pinIR = 28;

IRrecv irrecv(pinIR);
decode_results results;

int wemos_data;

unsigned long int ir_stanga = 16753245;
unsigned long int ir_dreapta = 16769565;
unsigned long int ir_fata = 16712445;
unsigned long int ir_spate =  16754775;
unsigned long int ir_stopp = 16750695;
unsigned long int ir_drept = 16736925;

//=============================

void setup() {
  Wire.begin(I2C_SLAVE);

  Wire.onReceive(receiveEvent);
  
  irrecv.enableIRIn();
  
  motoare_setup();
  
  urmaritor_linie_setup();
  
  ultrasunete_setup();
  
  ocolitor_setup();
  
  semnalizari_setup();
  
 Serial.begin(115200);
}

void loop() {

//  control wemos

  if (wemos_data == 8){
    
    ocolitor_obstacole();
  }
    
  if (wemos_data == 7){
    
    urmaritor_linie();
  }
  if (wemos_data == 6){
    
    directie_motoare(7);
  }
  if (wemos_data == 5){
    
    directie_motoare(6);
    semnalizare_dreapta();
  }
  if (wemos_data == 4){
    
    directie_motoare(4);
    semnalizare_stanga();
  }
  if (wemos_data == 3){
    
    directie_motoare(2);
  }
  if (wemos_data == 2){
    
    directie_motoare(1);
  }
  if (wemos_data == 1){
    
    directie_motoare(3);
  }

//==control infrarosu

  if (irrecv.decode(&results)) 
    { // daca senzorul primeste
      
      unsigned long int codIR = results.value;
      
    if (codIR == ir_stanga)
      {
        
        directie_motoare(4);
        semnalizare_stanga();
      }
    else if (codIR == ir_dreapta)
      {
        directie_motoare(6);
        semnalizare_dreapta();
      }
    else if (codIR == ir_spate)
      {
        directie_motoare(2);
      }
    else if (codIR == ir_stopp)
      {
        directie_motoare(3);
      }
    else if(codIR == ir_fata)
    {
      directie_motoare(1);
    }
    irrecv.resume();
  }
 }

void receiveEvent(size_t howMany) {

  (void) howMany;
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print("c=");  
    Serial.println(c);// print the character
  }
  int x = Wire.read();
   Serial.print("x="); // receive byte as an integer
  Serial.println(x); 

  if (x == 1){
      wemos_data=1;
  }else if(x == 2){
      wemos_data=2;
  }else if(x == 3){
      wemos_data=3;
  }else if(x == 4){      
      wemos_data=4;
//      semnalizare_stanga();
  }else if(x == 5){
      wemos_data=5;
//      semnalizare_stanga();
  }else if(x == 6){
      wemos_data=6;
  }else if (x == 7){
      wemos_data=7;
  }else if (x == 8)
  {
      wemos_data=8;
  }
}
