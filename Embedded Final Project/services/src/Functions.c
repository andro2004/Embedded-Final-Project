#include "../headers/Functions.h"
int f_int;
int ipart ;
float fpart ;
int temp ;
int len ;
int i ;
int k ;
int flen;
int start ;
char* float_to_string(float n, int afterpoint) {
    static char res[32];  // Static buffer to hold the result
    i = 0;

    // Handle negative numbers
    if (n < 0) {
        res[i++] = '-';
        n = -n;
    }

     ipart = (int)n;
    fpart = n - (float)ipart;

    // Convert integer part
    temp = ipart;
     len = 0;
    do {
        res[i + len++] = (temp % 10) + '0';
        temp /= 10;
    } while (temp);

    // Reverse the integer digits
		
    for ( k = 0; k < len / 2; k++) {
        char t = res[i + k];
        res[i + k] = res[i + len - 1 - k];
        res[i + len - 1 - k] = t;
    }

    i += len;

    // If precision is needed
    if (afterpoint > 0) {
        res[i++] = '.';

        fpart *= pow(10, afterpoint);
         f_int = (int)(fpart + 0.5f);  // rounding

        start = i;
   			flen = 0;
        do {
            res[i + flen++] = (f_int % 10) + '0';
            f_int /= 10;
        } while (f_int);

        // Add leading zeros if needed
        while (flen < afterpoint)
            res[i + flen++] = '0';

        // Reverse fractional part
        for ( k = 0; k < flen / 2; k++) {
            char t = res[i + k];
            res[i + k] = res[i + flen - 1 - k];
            res[i + flen - 1 - k] = t;
        }

        i += flen;
    }

    res[i] = '\0';  // Null terminator
    return 
res;
}
