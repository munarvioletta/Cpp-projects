/**
 * Project Untitled
 */
#include "Faktura.h"
using namespace std;
/**
 * Faktura implementation
 */


/**
 * @param produkt
 */
Faktura::Faktura()
{
    kwota = 0;
    liczba_pozycji = 0;
}
/**
 * @param produkt
 */
void Faktura::dodaj_pozycje(produkt nowy_produkt) {
    lista_produktow.push_back(nowy_produkt);
    liczba_pozycji++;
    kwota += nowy_produkt.podaj_cene();
    nowy_produkt.zmniejsz_stan();
}

/**
 * @param klient
 * @return bool
 */
void Faktura::ustaw_odbiorce(klient nowy_klient) {
    odbiorca = nowy_klient;
}

/**
 * @param platnosc
 */
void Faktura::rodzaj_platnosci(platnosc rodzaj) {
    fakt_platnosc = rodzaj;
}
void Faktura::drukuj()
{
    cout << "ODBIORCA: " << endl;
    odbiorca.pokaz_dane();
    cout << "LISTA PRODUKTOW: " << endl;
    for(unsigned int i = 0; i < lista_produktow.size(); i++)
    {
        lista_produktow[i].wypisz();
    }
    cout << "RAZEM:          " << kwota << endl;
    fakt_platnosc.wypisz_rodz();
}
