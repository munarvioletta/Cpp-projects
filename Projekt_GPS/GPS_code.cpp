/**
 * Dekodowanie danych protokołu NMEA
 * 
 * https://en.wikipedia.org/wiki/NMEA_0183
 * http://aprs.gids.nl/nmea/
 */

//#include <conio.h> // getch, tylko dla borland
#include <iostream> // string
#include <string.h> // strtok, strcmp
#include <stdio.h>  // printf
#include <stdlib.h> // strtof
 
using namespace std;
 
/** 
* Klasa Wspolrzedna pozwala na proste wyświetlanie 
* dwoch postaci wspolrzednych geograficznych: 
* stopnie, minuty, sekundy oraz stopnie dziesiętne ze znakiem.
* 
* Posiada składowe reprezentacji znaku wspolrzednej 
* w dwóch formach: +/- oraz N/S, W/E.
* 
* Obliczanie składowych odbywa się w dwóch krokach: poprzez konstruktor, 
* który przyjmuje jako argument wartość wspolrzednej 
* w formacie SSMM.MMMM (S – stopnie, M – minuty kątowe) 
* a następnie podanie odpowiedniej półkuli 
* jako argument metody dodajZnak(). 
* 
* Argumentem konstruktora jest tablica znaków char[], 
* argumentem metody jest pojedynczy znak char.
*/
class Wspolrzedne {
public:
  string znakPlusMinus; string znakTekstowy; // w printf() należy dopisać .c_str() – zamiana na char[]
  float wspolrzednaStopnieDziesietne;
  int stopnie; int minuty; int sekundy;
  
  Wspolrzedne(char asdf[]) {
    float wspolrzedna = strtof(asdf, NULL);
    stopnie = ((int) wspolrzedna) / 100;
    minuty  = ((int) wspolrzedna) % 100;
    sekundy = (int)((wspolrzedna - (int)wspolrzedna)*60);
    wspolrzednaStopnieDziesietne = ((sekundy/60.0) + minuty)/60.0 + stopnie;
  }
  
  void dodajZnak(char znak_) {
    char znakiMinusujace[] = "SE";
    if ( (znak_ == znakiMinusujace[0]) || (znak_ == znakiMinusujace[1]) )
      znakPlusMinus = "-";
    else 
      znakPlusMinus = "+";
    znakTekstowy = znak_;
  }
};
 
char RMCstr[85] = "$GPRMC,135618.00,A,5215.2979,N,02054.1103,E,123.0,000.0,180308,02.5,E,A*08"; // badana ramka
char *p; // pomocniczy wskaznik
char oczekiwanyRodzajPakietu[] = "$GPRMC"; // typ ramki, ktory chcemy badac
 
int main () {
    

    printf("ramka danych = %s\n\n", RMCstr);
    
    p = strtok (RMCstr,","); if (p) printf("pakiet= %s\n",p); // wyswietlanie typu ramki
 
    if (strcmp(p, oczekiwanyRodzajPakietu) == 0) {                 // test, czy badamy wlasciwa ramke
      p = strtok (NULL,","); if (p) printf("czas UTM = %s\n",p); // wyswietlanie czasu wyslania ramki
      p = strtok (NULL,","); if (p) printf("dane = %s\n\n",p);   // wyswietlanie typu danych

      p = strtok (NULL,","); 
      if (p) printf("szerokosc geograficzna = %s\n", p); // wyświetlanie surowej szerokości geograficznej
      Wspolrzedne szerokosc(p);                          // tworzenie nowego obiektu typu Wspolrzedna za pomocą konstruktora
      p = strtok (NULL,","); 
      if (p) printf("polkula = %s\n",p);                 // wyswietlanie polkuli
      szerokosc.dodajZnak(*p);                           // definiowanie znaku wspolrzednej w obiekcie szerokosc
      printf("%ist. %i\' %i\" %s\n",  
              szerokosc.stopnie, 
              szerokosc.minuty, 
              szerokosc.sekundy, 
              szerokosc.znakTekstowy.c_str());           // wyświetlanie sformatowanej szerokości geograficznej
      printf("%s%.5fst. \n\n", 
              szerokosc.znakPlusMinus.c_str(), 
              szerokosc.wspolrzednaStopnieDziesietne);   // wyświetlanie sformatowanej szerokości geograficznej

      p = strtok (NULL,","); 
      if (p) printf("dlugosc geograficzna = %s\n", p);   // wyświetlanie surowej dlugosci geograficznej

      Wspolrzedne dlugosc(p);                            // tworzenie nowego obiektu typu Wspolrzedna za pomocą konstruktora
      p = strtok (NULL,","); 
      if (p) printf("polkula = %s\n",p);                 // wyswietlanie polkuli
      dlugosc.dodajZnak(*p);                             // definiowanie znaku wspolrzednej w obiekcie dlugosc
      printf("%ist. %i\' %i\" %s\n",  
              dlugosc.stopnie, 
              dlugosc.minuty, 
              dlugosc.sekundy, 
              dlugosc.znakTekstowy.c_str());             // wyświetlanie sformatowanej dlugosci geograficznej

      printf("%s%.5fst. \n\n", 
              dlugosc.znakPlusMinus.c_str(), 
              dlugosc.wspolrzednaStopnieDziesietne);     // wyświetlanie sformatowanej dlugosci geograficznej

      p = strtok (NULL,","); 
      if (p) 
        printf("predkosc [wezly] = %s, [m/s] = %.1f, [km/h] = %.1f\n\n", 
                p, 
                1.852*strtof(p, NULL),
                0.514444*strtof(p, NULL));               // wyswietlanie predkosci w trzech roznych jednostkach

      p = strtok (NULL,","); if (p) printf("%s\n",p);    // kat przemieszczenia
      p = strtok (NULL,","); if (p) printf("%s\n",p);    // data
      p = strtok (NULL,","); if (p) printf("%s\n",p);    // zmiany magnetyczne
      p = strtok (NULL,","); if (p) printf("%s\n\n",p);  // kierunek zmian magnetycznych

      p = strtok (NULL,","); if (p) printf("suma kontrolna: %s\n",p);        // wyswietlanie sumy kontrolnej
    } else {
      printf("\nOczekiwany pakiet nie zostal odebrany lub nie istnieje.\n"); // komunikat bledu
    }
    //getch(); // oczekiwanie na dowolny klawisz
}