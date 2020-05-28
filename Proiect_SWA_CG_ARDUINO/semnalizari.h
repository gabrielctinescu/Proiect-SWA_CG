#ifndef semnalizari_h
#define semnalizari_h

#include "MaxMatrix.h"
#include "avr/pgmspace.h"
#include <Arduino.h>

void semnalizari_setup();
void printStringWithShiftS(char* s, int shift_speed);
void printStringWithShiftD(char* s, int shift_speed);
void printCharWithShiftS(char c, int shift_speed);
void printCharWithShiftD(char c, int shift_speed);
void semnalizare_dreapta();
void semnalizare_stanga();

#endif
