/**
 * Project Untitled
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include<list>

using namespace std;

#ifndef _KLINIKA_H
#define _KLINIKA_H

class Klinika {
public:
    list <Zwierzak> lista_zwierzat;
    string Nazwa = "Bari";
    string Ulica = " Komsmowskiego 2";
    int numer = 24;

    void dodaj(Zwierzak&);

    void usun();

    void wyszukaj();

    void wyswietl();
};

#endif //_KLINIKA_H
