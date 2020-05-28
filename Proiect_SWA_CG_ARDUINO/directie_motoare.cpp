#include "directie_motoare.h"

// Motor A

int enA = 4; 	//pwm
int in1 = 42; //Motor A1   F
int in2 = 40; //Motor A2   R

//Motor B
int enB = 5;   //pwm
int in3 = 38; //Motor B1   F
int in4 = 36; //Motor B2   R

int viteza = 70;

void motoare_setup(){
	
	pinMode(in1, OUTPUT);
	pinMode(in4, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
}


void directie_motoare(int d){
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
        analogWrite(enA,240);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,HIGH);
    break;
      case 5:
    //    stanga brusc
        analogWrite(enB,150);
        analogWrite(enA,150);
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,HIGH);
    break;
           case 6:
//    dreapta

        analogWrite(enB,240);
        analogWrite(enA,0);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
    break;
      case 7:
    //    dreapta brusc

        
        analogWrite(enB,150);
        analogWrite(enA,150);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
    break;

          case 8:
    //    test

        
        analogWrite(enB,150);
        analogWrite(enA,150);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
    break;
  }
}
