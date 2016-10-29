/**
 * Project Untitled
 */


#include "Klinika.h"
#include "Zwierzak.h"
#include<list>
/**
 * Klinika implementation
 */



void Klinika::dodaj(Zwierzak& pacjent) {
    lista_zwierzat.push_back(pacjent);
}

void Klinika::usun() {

}

void Klinika::wyszukaj() {

}

void Klinika::wyswietl() {
    list<Zwierzak>::iterator it;

    for (it = lista_zwierzat.begin(); it != lista_zwierzat.end(); ++it)
    {
        cout <<"\n"<< it -> imie << "\t : " <<" wiek"<< it -> wiek << " waga "<< it ->waga<<endl;
    }

}
