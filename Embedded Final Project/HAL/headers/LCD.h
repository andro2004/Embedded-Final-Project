#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/headers/Delay.h"



#define LCD_PORT GPIO_PORTB_DATA_R 
#define LCD_CTRL_PORT GPIO_PORTA_DATA_R
#define EN 6
#define RS 7

void Ports_init(void);
void LCD_print_char(char c);//sends a data (char) to the lcd to be displayed
void LCD_cmd(uint8_t command);//sends a command to the lcd
void LCD_init(void);//initiation of ports direction and initiation of lcd
void LCD_setCursor(uint8_t x,uint8_t y);//moves currsor to any position //x = col,y=row //// 0 ---> first row or first col
void LCD_clear(void);
void LCD_clearScnd(void);//clears the second line of the lcd only and set cursor to the beginning of the second line
void LCD_writeStr(char *a);//displays entire string on the lcd

#endif /* LCD_H_ */
