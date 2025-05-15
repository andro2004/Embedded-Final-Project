#include "HAL/headers/LCD.h"
#include "HAL/headers/GPS.h"
#include "HAL/headers/Buzzer.h"
#include "services/headers/Functions.h"

int main(void)
{
	float longLoc1 = 3116.8167;
	float longLoc2 = 3116.7667;
	float longLoc3 = 3116.7;
	float longLoc4 = 3116.667;
	float longLoc5 = 3116.8;
	
	float latLoc1 = 3003.81667;
	float latLoc2 = 3003.8;
	float latLoc3 = 3003.8;
	float latLoc4 = 3003.85;
	float latLoc5 = 3003.9;
	float dist[5];

	char loc1[]="Hall C";
	char loc2[]="Lupan";	
	char loc3[]="ICHEP";
	char loc4[]="Civil";
	char loc5[]="Library";
	float mindist;
	int i;
	int minI=0;
	UART_Init();
	LCD_init();
	delay_ms(50);
	
	while(1){
		
		float currentlat = GPS_FormatLat();
		float currentlong = GPS_FormatLong();
		
		
		dist[0]=0;
		dist[1]=0;
		dist[2]=0;
		dist[3]=0;
		dist[4]=0;
		
		dist[0]=ToGetDistance(currentlong, currentlat, longLoc1, latLoc1);
		dist[1]=ToGetDistance(currentlong, currentlat, longLoc2, latLoc2);
		dist[2]=ToGetDistance(currentlong, currentlat, longLoc3, latLoc3);
		dist[3]=ToGetDistance(currentlong, currentlat, longLoc4, latLoc4);
		dist[4]=ToGetDistance(currentlong, currentlat, longLoc5, latLoc5);
		
		
		mindist=dist[0];
		for(i=1; i<5; i++)
		{
				if(mindist>dist[i]){
					mindist=dist[i];
					minI=i;
				}
		}

		switch(minI)
		{
			case 0:
				LCD_clear();
				LCD_writeStr(loc1);
				morsee(minI);
			  delay_ms(1000);
				break;
			case 1:
				LCD_clear();
				LCD_writeStr(loc2);
			  morsee(minI);
			  delay_ms(1000);
				break;
			case 2:
				LCD_clear();
				LCD_writeStr(loc3);
		    morsee(minI);
			delay_ms(1000);
				break;
			case 3:
				LCD_clear();
				LCD_writeStr(loc4);
			  morsee(minI);
			delay_ms(1000);
				break;
			case 4:
				LCD_clear();
				LCD_writeStr(loc5);
	    	morsee(minI);
		   	delay_ms(1000);
				break;
		}
	}
}
