#include "../headers/Buzzer.h"
		int dot_ms=200;
		int dash_ms=600;
		int silent_ms=200;
void buzzer_inti(void)
{
		//init port A pin 6 (en) and pin 7 (rs)
		SYSCTL_RCGCGPIO_R|=0x00000001;
		while((SYSCTL_PRGPIO_R & 0x00000001)==0){};
		SET_BIT(GPIO_PORTA_DIR_R ,2);
		SET_BIT(GPIO_PORTA_DEN_R ,2);

}
void dot(void)
{
	SET_BIT(GPIO_PORTA_DATA_R,2);
	delay_ms(dot_ms);
  CLEAR_BIT(GPIO_PORTA_DATA_R,2);;
	delay_ms(silent_ms);
}
void dash(void)
{
	SET_BIT(GPIO_PORTA_DATA_R,2);
	delay_ms(dash_ms);
  CLEAR_BIT(GPIO_PORTA_DATA_R,2);;
	delay_ms(silent_ms);
}
void morsee(int location)
{
	switch (location)
	{
		case 0:
			//C (hall C)
			dash();
			dot();
			dash();
			dot();
			break;
		case 1:
			//W (lupan workshop)
		dot();
		dash();
		dash();
		break;
		case 2:
			//I (ICHEP)
		dot();
		dot();
		break;
		case 3:
			//V (Civil)
			dot();
		dot();
		dot();
		dash();
		break;
		case 4:
		//L (Library)
			dot();
			dash();
			dot();
			dot();
		break;
		default:;
	}
}
