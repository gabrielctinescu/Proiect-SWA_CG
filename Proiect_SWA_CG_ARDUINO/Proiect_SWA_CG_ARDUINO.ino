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
      directie_motoare(3);
  }else if(x == 2){
      directie_motoare(1);
  }else if(x == 3){
      directie_motoare(2);
  }else if(x == 4){      
      directie_motoare(4);
      semnalizare_stanga();
  }else if(x == 5){
      directie_motoare(6);
      semnalizare_stanga();
  }else if(x == 6){
      directie_motoare(7);
  }else if (x = 7){
      ocolitor_obstacole();
  }else if (x = 8)
  {
      urmaritor_linie();
  }
}
