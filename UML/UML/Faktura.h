/**
 * Project Untitled
 */


#ifndef _FAKTURA_H
#define _FAKTURA_H
#include <vector>
#include <iostream>
#include "klient.h"
#include "platnosc.h"
#include "produkt.h"


class Faktura {
public:
    Faktura();
    /**
     * @param produkt
     */
    void dodaj_pozycje(produkt nowy_produkt);

    /**
     * @param klient
     */
    void ustaw_odbiorce(klient nowy_klient);

    /**
     * @param platnosc
     */
    void rodzaj_platnosci(platnosc rodzaj);
    void drukuj();
private:
    double kwota;
    int liczba_pozycji;
    std::vector<produkt> lista_produktow;
    platnosc fakt_platnosc;
    klient odbiorca;
};

#endif //_FAKTURA_H
