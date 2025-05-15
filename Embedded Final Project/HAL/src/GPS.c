#include "../headers/GPS.h"

const double Earth_Radius=6371000;

char GPS_output[80] ;
char GPS_Formated [12] [20];
char *token;

char GPS_logName[]= "SGPRMC,";
	
float ToDegree (float angle) {
int degree = (int) (angle / 100);
float minutes = angle - (float) degree* 100;
return (degree+ (minutes/ 60) ) ;
}

void GPS_READ() {
	char recievedchar;
	char i=0;
	char UART_char ;
	char fillGpsCounter=0;
	do 
	{ 
		while (UART_GetChar()!= GPS_logName[i]);
		i+=1;
	} while(i!=6);
	strcpy (GPS_output, "");
	do { 
		
		recievedchar = UART_GetChar();
		GPS_output [fillGpsCounter++] = recievedchar;
	}while(recievedchar != '*');
}  
 
float currentlat;
float currentlong;

float GPS_FormatLat() 
	{
				char j=0; 
		GPS_READ();
      // number of token strings
		token = strtok(GPS_output,",");
		do 
			{ 
					strcpy( GPS_Formated[j],token);
					token = strtok( NULL , ",");	 
					j++; 
	    }while (token!=NULL); 
			 
	 if (strcmp (GPS_Formated[1],"A")==0)
			{
          if  (strcmp (GPS_Formated[3],"N")==0)
			        currentlat = atof( GPS_Formated[2]);
					else 
					    currentlat =  -atof (GPS_Formated[3])	;		
					
					
				}
			return toRAD(currentlat);
	}
	
float GPS_FormatLong() 
	{
				char j=0;       // number of token strings

		GPS_READ();
		token = strtok(GPS_output,",");
		do 
		{ 
					strcpy( GPS_Formated[j],token);
					token = strtok( NULL , ",");	 
					j++; 
		}while (token!=NULL); 	
				
		
		if (strcmp (GPS_Formated[1],"A")==0)
			{		 
					if  (strcmp (GPS_Formated[5],"E"	)	==0)
			        currentlong = atof( GPS_Formated[4]);
					else 
					    currentlong =  -atof (GPS_Formated[4])	;		
			}	
			return toRAD(currentlong);
	}					
	

float toRAD(float angle) {
    int degree = (int)(angle / 100);
    float mins = angle - (degree * 100);
    float deg = degree + (mins / 60.0);
    return deg * pi / 180.0;
}


// to get distace
 float ToGetDistance( float currentlong ,float currentlat ,float destlong ,float destlat)
	 {
		 float difflat;
		 float difflong;
		 float a,c,distance;
		destlong=toRAD(destlong);
		destlat=toRAD(destlat);
    difflat = currentlat - destlat;
    difflong = currentlong - destlong;


		 
    a= sin(difflat/2)*sin(difflat/2)+ cos(destlat)*cos(currentlat)*sin(difflong/2)*sin(difflong/2); // Haversine formula: a = sin (?f/2) + cos f1   cos f2   sin (??/2)
    c = 2 * atan2(sqrt(a), sqrt(1 - a));

		distance = Earth_Radius * c;
    return distance;
 }