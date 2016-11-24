/**
 * Project Untitled
 */


#ifndef _PRODUKT_H
#define _PRODUKT_H
#include <iostream>

class produkt {
public:
    produkt(char * produkt,double cena_n);
    void zmniejsz_stan();

    int podaj_ilosc();

    double podaj_cene();

    void zwroc();
    void wypisz();
private:
    double cena;
    int ilosc;
    char* nazwa;
};

#endif //_PRODUKT_H
