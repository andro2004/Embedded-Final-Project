#ifndef UART
#define UART

#include "tm4c123gh6pm.h"
#include "stdint.h"
#include <stdio.h>

// Function Prototypes
void UART_Init(void);
char UART_IsCharAvail(void);
char UART_GetChar(void);
void UART_SendChar(char);
#endif
