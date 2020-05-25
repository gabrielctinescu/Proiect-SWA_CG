

//====initializare i2c====

#include <Wire.h> 

//====initializare servo-motoare ====

#include <Servo.h>

Servo servo_senzor;


//===initializare infrared=====

#include <IRremote.h>

int pinIR = 22;

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

////===========initializare lcd====================
//
//#include <LiquidCrystal_I2C.h>
//
//LiquidCrystal_I2C lcd(0x3F,16,2);
//
////===========initializare senzor temp================
//
//#include "DHT.h"
//
//#define DHTPIN 3
//
//#define DHTTYPE DHT11
//
//DHT dht(DHTPIN, DHTTYPE);
//
////================================

//===initializare led 8x8 ====


#include "MaxMatrix.h"
#include "avr/pgmspace.h"


PROGMEM const unsigned char CH[] = {
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};

int data_dreapta = 10;    // DIN pin of MAX7219 module
int load_dreapta = 9;    // CS pin of MAX7219 module
int clock_dreapta = 8;  // CLK pin of MAX7219 module

int data_stanga = 51;    // DIN pin of MAX7219 module
int load_stanga = 49;    // CS pin of MAX7219 module
int clock_stanga = 47;

int maxInUse = 1;  //how many MAX7219 are connected

MaxMatrix m_dreapta(data_dreapta, load_dreapta, clock_dreapta, maxInUse); // define Library
MaxMatrix m_stanga(data_stanga, load_stanga, clock_stanga, maxInUse); // define Library

byte buffer[10];

char string_stanga[] = ">>>>";  // Scrolling Text
char string_dreapta[] = "<<<<";
//================================

void setup() {
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);

// lcd.init();
// lcd.backlight();
// dht.begin();

  m_dreapta.init(); // module MAX7219
  m_dreapta.setIntensity(15); // LED Intensity 0-15


  m_stanga.init(); // module MAX7219
  m_stanga.setIntensity(15); // LED Intensity 0-15

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
 
 Serial.begin(9600);
}

void loop() {



//===initializare senzori urmritor-linie====

//int s1 =    digitalRead(23);     //senzor 1
//int s2 =    digitalRead(25);     //senzor 2
//int s3 =    digitalRead(27);     //senzor 3
//int s4 =    digitalRead(29);     //senzor 4
//int s5 =    digitalRead(31);     //senzor 5
//int buton = digitalRead(33);     //CLP
//int near  = digitalRead(35);     //Near

//==========================================

//  float h = dht.readHumidity();
//
//  float t = dht.readTemperature();
//
//  
//  lcd.setCursor(0,0);
//  lcd.print(t);
//  lcd.setCursor(5,0);
//  lcd.print(" C");
//  lcd.setCursor(9,0);
//  lcd.print(h);
//  lcd.setCursor(14,0);
//  lcd.print(" %\t");
//
//  
//  Serial.print("Umiditate: ");
//  Serial.print(h);
//  Serial.println(" %\t");
//  Serial.print("Temperatura: ");
//  Serial.print(t); 
//  Serial.println(" *C ");
  
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


//  if (distanta() > 5){
//
//    
//      if ((s1==HIGH)&&(s2==HIGH)&&(s3==LOW)&&(s4==HIGH)&&(s5==HIGH)){
//        
//        do{
//          
//          directie_motoare(1,60);
//          
//        }while((s4==LOW) || (s2=LOW));
//
//      } else if ((s1==HIGH)&&(s2==LOW)&&(s3==LOW)&&(s4==LOW)&&(s5==HIGH)){
//
//         do{
//          
//          directie_motoare(1,70);
//          
//        }while((s1==LOW) || (s5=LOW));
//
//      }else if ((s1==LOW)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
//        do{
//          
//          directie_motoare(5,150);
//          
//        }while(s2==LOW);
//          
//              
//      }else if ((s1==HIGH)&&(s2==LOW)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
//          do{
//            
//           directie_motoare(4,150);   
//              
//          }while(s3==LOW);
//            
//
//      }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==LOW)){
//          do{
//            
//            directie_motoare(7,150);
//            
//          }while(s4==LOW);
//           
//    
//      }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==LOW)&&(s5==HIGH)){
//          do{
//            
//            directie_motoare(6,90); 
//            
//          }while(s3==LOW);
//   
//     }else if ((s1==LOW)&&(s2==LOW)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
//          do{
//            
//            directie_motoare(4,90);
//            
//          }while(s3==LOW);
//            
//
//      }else if((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==LOW)&&(s5==LOW)){
//          do{
//          
//            directie_motoare(6,90);
//            
//          }while(s3==LOW);
//      }
//        
//  }else{
//    directie_motoare(3,80);
//  }



  //===================control telecomanda - IR==================

  if (irrecv.decode(&results)) { // daca senzorul primeste
    unsigned long int codIR = results.value;
    if (codIR == ir_stanga){

          directie_motoare(4,90);
          printStringWithShiftS(string_dreapta, 100);
          m_stanga.clear();

    }else if (codIR == ir_dreapta){
  
        directie_motoare(6,90);
        printStringWithShiftD(string_dreapta, 100);  // Send scrolling Text
        m_dreapta.clear();
 
    }else if (codIR == ir_spate){

        directie_motoare(2,65);
 
    }else if (codIR == ir_stopp){
  
        directie_motoare(3,1);
   
    }else if(codIR == ir_fata){

        directie_motoare(1,65);
    }
    irrecv.resume();
  }

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

// Put extracted character on Display
void printCharWithShiftD(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m_dreapta.writeSprite(maxInUse*8, 0, buffer);
  m_dreapta.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i = 0; i < buffer[0]+1; i++) 
  {
    unsigned long time_now = millis();

    while(millis() < time_now + shift_speed){
    
    }  
    m_dreapta.shiftLeft(false, false);
  }
}

void printCharWithShiftS(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m_stanga.writeSprite(maxInUse*8, 0, buffer);
  m_stanga.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i = 0; i < buffer[0]+1; i++) 
  {
    unsigned long time_now = millis();

    while(millis() < time_now + shift_speed){
    
    }  

    m_stanga.shiftLeft(false, false);
  }
}

// Extract characters from Scrolling text
void printStringWithShiftS(char* s, int shift_speed){
  while (*s != 0){
    printCharWithShiftS(*s, shift_speed);
    s++;
  }
}

void printStringWithShiftD(char* s, int shift_speed){
  while (*s != 0){
    printCharWithShiftD(*s, shift_speed);
    s++;
  }
}
