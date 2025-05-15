
#include "../headers/LCD.h"
void Ports_init(void)
{
	//init port B(command and data port)
		SYSCTL_RCGCGPIO_R |= 0x00000002;
		while((SYSCTL_PRGPIO_R & 0x00000002)==0){};
		GPIO_PORTB_DIR_R = 0x000000ff;
		GPIO_PORTB_DEN_R = 0x000000ff;
	//init port A pin 6 (en) and pin 7 (rs)
		SYSCTL_RCGCGPIO_R|=0x00000001;
		while((SYSCTL_PRGPIO_R & 0x00000001)==0){};
		GPIO_PORTA_DIR_R |= 0x000000c0;
		GPIO_PORTA_DEN_R |= 0x000000c0;
}
//sends a data (char) to the lcd to be displayed
void LCD_print_char(char c)
{
    LCD_CTRL_PORT |= (1 << RS);  // RS = 1 for data
    LCD_PORT = c;
    LCD_CTRL_PORT |= (1 << EN);  // Enable the LCD to latch the data
    delay_ms(1);
    LCD_CTRL_PORT &= ~(1 << EN);  // Disable EN
    delay_ms(1);
}
//sends a command to the lcd
void LCD_cmd(uint8_t command)
{
    LCD_CTRL_PORT &= ~(1 << RS);  // RS = 0 for command
    LCD_PORT = command;
    LCD_CTRL_PORT |= (1 << EN);  // Enable the LCD to latch the command
    delay_ms(1);
    LCD_CTRL_PORT &= ~(1 << EN);  // Disable EN
    delay_ms(1);
}
//initiation of ports direction and initiation of lcd
void LCD_init(void)
{
	
	delay_ms(50);
	Ports_init();
	delay_ms(40);
	LCD_cmd(0x38);
	delay_ms(1);
	LCD_cmd(0x0C);
	delay_ms(1);
	LCD_clear();
	delay_ms(1);
	LCD_cmd(0x06);
	delay_ms(1);
	LCD_cmd(0x80);
	delay_ms(1);
}
//moves currsor to any position //x = col,y=row //// 0 ---> first row or first col
void LCD_setCursor(uint8_t x,uint8_t y)
{
	
}
//clears the entire lcd
void LCD_clear(void)
{
	LCD_cmd(0x01);
}
//clears the second line of the lcd only and set cursor to the beginning of the second line
void LCD_clearScnd(void)
{
	LCD_clear();
	delay_ms(1);
	LCD_cmd(0x80);
	delay_ms(1);
	LCD_writeStr("You are near to:"); 	
	delay_ms(1);
	LCD_cmd(0xC0);
	delay_ms(1);
}
//displays entire string on the lcd
void LCD_writeStr(char *a)
{
	int i =0;
	while(a[i]!=0)
	{
		LCD_print_char(a[i]);
		i++;
	}
}
