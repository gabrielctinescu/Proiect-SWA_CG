#include "directie_motoare.h"

int s1 =  23;     //senzor 1
int s2 =  25;     //senzor 2
int s3 =  27;     //senzor 3
int s4 =  29;     //senzor 4
int s5 =  31;     //senzor 5
int buton = 33;     //CLP
int near  = 35;
 
 
 
 void urmaritor_linie_setup()
 {
 pinMode(23, INPUT);
 pinMode(25, INPUT);
 pinMode(27, INPUT);
 pinMode(29, INPUT);
 pinMode(31, INPUT);
 pinMode(33, INPUT);
 pinMode(35, INPUT);
 motoare_setup();
  
 }

 void urmaritor_linie(){
  
  int s1 =    digitalRead(23);     //senzor 1
  int s2 =    digitalRead(25);     //senzor 2
  int s3 =    digitalRead(27);     //senzor 3
  int s4 =    digitalRead(29);     //senzor 4
  int s5 =    digitalRead(31);     //senzor 5
  int buton = digitalRead(33);     //CLP
  int near  = digitalRead(35);     //Near

 if ((s1==HIGH)&&(s2==HIGH)&&(s3==LOW)&&(s4==HIGH)&&(s5==HIGH)){
  
    directie_motoare(1);
    
  } else if ((s1==HIGH)&&(s2==LOW)&&(s3==LOW)&&(s4==LOW)&&(s5==HIGH)){
    
    directie_motoare(1);
    
  }else if ((s1==LOW)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
    
    directie_motoare(5);
    
  }else if ((s1==HIGH)&&(s2==LOW)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
    
    directie_motoare(4);
    
  }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==LOW)){
    
    directie_motoare(7);
    
  }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==LOW)&&(s5==HIGH)){
    
    directie_motoare(6);
    
  }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
    
    directie_motoare(3);
    
  }else if ((s1==LOW)&&(s2==LOW)&&(s3==LOW)&&(s4==LOW)&&(s5==LOW)){
    
    directie_motoare(3);
    
  }else if ((s1==LOW)&&(s2==LOW)&&(s3==HIGH)&&(s4==HIGH)&&(s5==HIGH)){
    
    directie_motoare(5);
   
  }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==HIGH)&&(s4==LOW)&&(s5==LOW)){
    
    directie_motoare(7);
    
  }else if ((s1==HIGH)&&(s2==LOW)&&(s3==LOW)&&(s4==HIGH)&&(s5==HIGH)){
    
    directie_motoare(1);
    
  }else if ((s1==HIGH)&&(s2==HIGH)&&(s3==LOW)&&(s4==LOW)&&(s5==HIGH)){
    
    directie_motoare(1);
    
  }
}
