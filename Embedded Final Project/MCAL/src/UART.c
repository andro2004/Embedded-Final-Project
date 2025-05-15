#include "../headers/UART.h"

void UART_Init(void) {
    SYSCTL_RCGCUART_R |= (1 << 3);    // Enable UART3
    SYSCTL_RCGCGPIO_R |= (1 << 2);    // Enable Port C (UART3 on PC6, PC7)
    while ((SYSCTL_PRGPIO_R & (1 << 2)) == 0); // Wait until Port C is ready

    UART3_CTL_R &= ~(1 << 0);         // Disable UART3

    UART3_IBRD_R = 104;               // Integer part of BRD
    UART3_FBRD_R = 11;                // Fractional part of BRD

    UART3_LCRH_R = (0x3 << 5) | (1 << 4); // 8-bit, enable FIFO
    UART3_CTL_R |= (1 << 0) | (1 << 8) | (1 << 9); // Enable UART3, TX, RX

    GPIO_PORTC_AFSEL_R |= (1 << 6) | (1 << 7);   // Enable alt functions on PC6, PC7
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & ~0xFF000000) | 0x11000000;
    GPIO_PORTC_DEN_R |= (1 << 6) | (1 << 7);     // Digital enable
    GPIO_PORTC_AMSEL_R &= ~((1 << 6) | (1 << 7));// Disable analog
}

void UART_SendChar(char c) {
    while (UART3_FR_R & (1 << 5));    // Wait while TX FIFO is full
    UART3_DR_R = c;
}

void UART_SendString(const char *str) {
    while (*str) {
        UART_SendChar(*str++);
    }
}

char UART_GetChar(void) {
    while (UART3_FR_R & (1 << 4));    // Wait while RX FIFO is empty
    return (char)(UART3_DR_R & 0xFF);
}