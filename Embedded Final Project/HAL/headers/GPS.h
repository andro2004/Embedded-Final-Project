#ifndef GPS
#define GPS

#define pi  3.14159265358979323846264338327950288419716939937510

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../../MCAL/headers/UART.h"
float GPS_FormatLat() ;
void GPS_READ();
float GPS_FormatLong() ;
float toRAD(float angle);
 float ToGetDistance( float currentlong ,float currentlat ,float destlong ,float destlat);
 void GPS_READ();
float ToDegree (float angle);


#endif
