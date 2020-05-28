#include "directie_motoare.h"
#include <Servo.h>
#include "distanta_ultrasunete.h"


Servo motor_servo;

int unghi_dreapta = 30;
int unghi_stanga = 140;
int unghi_drept = 90;

int senzor_stanga   = 52;     
int senzor_dreapta  = 53;
int senzor_mijloc   = 35;
int pin_servo = 7;
float distanta_stanga, distanta_dreapta, distanta_fata;



void ocolitor_setup()
{
  motor_servo.attach(pin_servo);
  motoare_setup();
  ultrasunete_setup();

  pinMode(senzor_stanga, INPUT);
  pinMode(senzor_dreapta, INPUT);
  pinMode(senzor_mijloc, INPUT);

  Serial.begin(115200);
}

void ocolitor_obstacole()
{
  motor_servo.write(unghi_drept);
  distanta_fata = distanta();


  int senzor_stanga   = digitalRead(52);     
  int senzor_dreapta  = digitalRead(53);
  int senzor_mijloc   = digitalRead(35);

  if (distanta_fata > 12){
    
      if ((senzor_stanga == HIGH)&&(senzor_dreapta == HIGH)&&(senzor_mijloc == LOW))
        {
          directie_motoare(1);    
        }
      if (senzor_stanga == LOW)
        {
          directie_motoare(4);    
        }
      if (senzor_dreapta == LOW)
        {
          directie_motoare(6);    
        }
      if (((senzor_stanga == LOW)&&(senzor_dreapta == LOW)&&(senzor_mijloc == HIGH))||((senzor_stanga == HIGH)&&(senzor_dreapta == HIGH)&&(senzor_mijloc == HIGH)))
        {
          directie_motoare(2);  // spate
          delay(300);
          directie_motoare(3);  // stop

          motor_servo.write(unghi_stanga);
          delay(500);
          distanta_stanga = distanta();
    
          motor_servo.write(unghi_dreapta);
          delay(500);
          distanta_dreapta = distanta();

          motor_servo.write(unghi_drept);


          if((distanta_dreapta > distanta_stanga) && (distanta_dreapta > 20))
            {
              directie_motoare(7);
              delay(500);
              directie_motoare(1);
      
            }else if((distanta_stanga > distanta_dreapta)&& (distanta_stanga > 20))
              {
                directie_motoare(5);
                delay(500);
                directie_motoare(1);
              }else{
                directie_motoare(2);
                delay(1000);
                directie_motoare(7);
                delay(500);
                directie_motoare(1);
              }
        }
    }else if ((distanta_fata < 12)|| (senzor_mijloc == HIGH)){
        directie_motoare(2);
        delay(1000);
        directie_motoare(7);
        delay(500);
        directie_motoare(1);
    }
  
  
}
