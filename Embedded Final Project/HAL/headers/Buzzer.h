#ifndef BUZZER
#define BUZZER
#include "../../MCAL/headers/Delay.h"
#include "../../services/headers/GPIO.h"

void buzzer_inti(void);
void dot(void);
void dash(void);
void morsee(int location);

#endif