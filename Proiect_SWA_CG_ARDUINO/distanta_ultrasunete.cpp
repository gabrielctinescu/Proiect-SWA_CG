  #include "distanta_ultrasunete.h"

  int trig = 44;
  int echo = 45;

  void ultrasunete_setup(){
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(115200);
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
