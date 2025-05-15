#include "../headers/Delay.h"
void delay_us(uint32_t time) {
	int i = 0;
    NVIC_ST_CTRL_R = 0;            // Disable SysTick during setup
    NVIC_ST_RELOAD_R = 16 - 1;     // 16 counts for 1 microsecond (assuming 16 MHz clock)
    NVIC_ST_CURRENT_R = 0;         // Clear current value
    NVIC_ST_CTRL_R = 0x05;         // Enable SysTick with core clock
    
    for (i = 0; i < time; i++) {
        while ((NVIC_ST_CTRL_R & 0x10000) == 0) {
            // Wait until COUNT flag is set
        }
    }
}

void delay_ms(uint32_t time)
{
	int i;
		for(i=0;i<time;i++)
	{
			delay_us(1000);
	}
}

