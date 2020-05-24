

//====initializare i2c====

#include <Wire.h> 

//====initializare servo-motoare ====

#include <Servo.h>

Servo servo_senzor;


//===initializare infrared=====

#include <IRremote.h>

int pinIR = 50;

IRrecv irrecv(pinIR);
decode_results results;

unsigned long int ir_stanga = 16753245;
unsigned long int ir_dreapta = 16769565;
unsigned long int ir_fata = 16712445;
unsigned long int ir_spate =  16754775;
unsigned long int ir_stopp = 16750695;
unsigned long int ir_drept = 16736925;

//===definire pini motorase====

// Motor A

int enA = 4;
int in1 = 42; //Motor A1   F
int in2 = 40; //Motor A2   R

//Motor B
int enB = 5;
int in3 = 38; //Motor B1   F
int in4 = 36; //Motor B2   R

//===initializare senzor ultrasunete====

int trig = 44;
int echo = 45;

//===============================

void setup() {
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);



 servo_senzor.attach(7);

 irrecv.enableIRIn();
 
 pinMode(23, INPUT);
 pinMode(25, INPUT);
 pinMode(27, INPUT);
 pinMode(29, INPUT);
 pinMode(31, INPUT);
 pinMode(33, INPUT);
 pinMode(35, INPUT);

 pinMode(41, INPUT);
 pinMode(43, INPUT);
 
 pinMode(in1, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);

 
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 
 Serial.begin(115200);
}

void loop() {




//===initializare senzori urmritor-linie====

int s1 =    digitalRead(23);     //senzor 1
int s2 =    digitalRead(25);     //senzor 2
int s3 =    digitalRead(27);     //senzor 3
int s4 =    digitalRead(29);     //senzor 4
int s5 =    digitalRead(31);     //senzor 5
int buton = digitalRead(33);     //CLP
int near  = digitalRead(35);     //Near


//===========================================
//===initializare senzori laterali====
//===========================================
//int senzor_stanga   = digitalRead(41);     
//int senzor_dreapta  = digitalRead(43);    
//
//if (senzor_stanga==LOW){
//  motor_directie.write(120);
//}else if(senzor_dreapta==LOW){
//  motor_directie.write(60);
//}else{
//  motor_directie.write(90);
//}
//=========================================== 
//============urmaritor-linie=============================
//===========================================


  if (distanta() > 5){

    
      if ((s1==HIGH)&&(s2==HIGH)&&(s3==LOW)&&(s4==HIGH)&&(s5==HIGH)){
        
        do{
          
          directie_motoare(1,60);
          
        }while((s4==LOW) || (s2=LOW));

      } else if ((s1==HIGH)&&(s2==LOW)&&(s3==LOW)&&(s4==LOW)&&(s5==HIGH)){

         do{
          
          directie_motoare(1,70);
          
        }while((s1==LOW) || (s5=LOW));

      }else if ((s1==LOW)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
        do{
          
          directie_motoare(5,150);
          
        }while(s2==LOW);
          
              
      }else if ((s1==HIGH)&&(s2==LOW)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
          do{
            
           directie_motoare(4,150);   
              
          }while(s3==LOW);
            

      }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==LOW)){
          do{
            
            directie_motoare(7,150);
            
          }while(s4==LOW);
           
    
      }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==LOW)&&(s5==HIGH)){
          do{
            
            directie_motoare(6,90); 
            
          }while(s3==LOW);
   
     }else if ((s1==LOW)&&(s2==LOW)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
          do{
            
            directie_motoare(4,90);
            
          }while(s3==LOW);
            

      }else if((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==LOW)&&(s5==LOW)){
          do{
          
            directie_motoare(6,90);
            
          }while(s3==LOW);
      }
        
  }else{
    directie_motoare(3,80);
  }



  //===================control telecomanda - IR==================

//  if (irrecv.decode(&results)) { // daca senzorul primeste
//    unsigned long int codIR = results.value;
//    if (codIR == ir_stanga){
//
//        motor_directie.write(65);
//
//
//    }else if (codIR == ir_dreapta){
//  
//        motor_directie.write(113);
// 
//
//    }else if (codIR == ir_spate){
//
//        directie_motoare(2,90);
// 
//    }else if (codIR == ir_stopp){
//  
//        motor_directie.write(90);
//        directie_motoare(3,1);
//     
//        
//    }else if(codIR == ir_fata){
//
//        directie_motoare(1,90);
//
//    }else if (codIR == ir_drept){
//      motor_directie.write(90);
//    }
////    else {
////      motor_directie.write(90);
////    }
//    irrecv.resume();
//  }

  }


float distanta()
{
  long durata;
  float distantam;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);


  durata = pulseIn(echo,HIGH);

  distantam = (durata * 0.0340)/2.0;

  return distantam;
}

void directie_motoare(int d, int viteza){
  switch(d){
    case 1:
//    fata 
        analogWrite(enB,viteza);
        analogWrite(enA,viteza);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);

    break;
    case 2:
//    spate
        analogWrite(enB,viteza);
        analogWrite(enA,viteza);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
    break;
        case 3:
//    stop
        analogWrite(enB,viteza);
        analogWrite(enA,viteza);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,HIGH);
    break;
       case 4:
//    stanga
        analogWrite(enB,0);
        analogWrite(enA,viteza);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,HIGH);
    break;
      case 5:
    //    stanga brusc
        analogWrite(enB,0);
        analogWrite(enA,viteza+50);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,HIGH);
    break;
           case 6:
//    dreapta
        analogWrite(enB,viteza);
        analogWrite(enA,0);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
    break;
      case 7:
    //    dreapta brusc
        analogWrite(enB,viteza+50);
        analogWrite(enA,0);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
    break;
  }
}
