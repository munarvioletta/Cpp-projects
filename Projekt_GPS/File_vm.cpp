#include <conio.h>
#include <iostream.h>
#include <math.h>

using namespace std;

char RMCstr[85] = "$GPRMC,135618.00,A,5215.2979,N,02054.1103,E,123.0,000.0,180308,02.5,E,A*08";
char *p;

float przeliczWspolrzedne(string str) {


        return 1.0;
}

void main () {
        p = strtok (RMCstr,",");
        if (p) printf("pakiet= %s\n",p);

        p = strtok (NULL,",");
        if (p) printf("czas UTM= %s\n",p);

        p = strtok (NULL,",");
        if (p) printf("dane= %s\n",p);

        p = strtok (NULL,",");
        if (p) printf("szerokosc geograficzna= %s\n",p);
        /*p = strtok (NULL,",");
        if (p) printf("szerokosc geograficzna= %s\n",p);*/


        p = strtok (NULL,",");
        if (p) printf("polkula= %s\n",p);

        p = strtok (NULL,",");
        if (p) printf("dlugosc geograficzna= %s\n",p);
        /*p = strtok (NULL,",");
        if (p) printf("dlugosc geograficzna= %s\n",p);*/

        p = strtok (NULL,",");
        if (p) printf("polkula= %s\n",p);

        p = strtok (NULL,",");
        if (p) printf("predkosc [wezly]= %s\n\n",p);

        p = strtok (NULL,",");
        if (p) printf("%s\n",p);

        p = strtok (NULL,",");
        if (p) printf("%s\n",p);

        p = strtok (NULL,",");
        if (p) printf("%s\n",p);

        p = strtok (NULL,",");
        if (p) printf("%s\n",p);

        p = strtok (NULL,",");
        if (p) printf("suma kontrolna: %s\n",p);

        getch();
}
