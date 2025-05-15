#ifndef DELAY
#define DELAY

#include "tm4c123gh6pm.h"
#include "../../services/headers/GPIO.h"
#include <stdint.h>

void delay_us(uint32_t time);
void delay_ms(uint32_t time);
#endif
