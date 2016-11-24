/**
 * Project Untitled
 */


#include "klient.h"
#include <iostream>
using namespace std;
/**
 * klient implementation
 */


/**
 * @param char* imie
 * @param char* nazwisko
 * @param char* adres
 */
 klient::klient()
{
    imie = 0;
    nazwisko = 0;
    adres = 0;
}
klient::klient(char * imie_n, char* nazwisko_n, char* adres_n)
{
    imie = imie_n;
    nazwisko = nazwisko_n;
    adres = adres_n;
}

void klient::zmien_dane( char* imie_n,  char* nazwisko_n,  char* adres_n) {
    imie = imie_n;
    nazwisko = nazwisko_n;
    adres = adres_n;
}
void klient::pokaz_dane()
{
    cout << imie << " " << nazwisko << "\n" << adres << endl;
}
