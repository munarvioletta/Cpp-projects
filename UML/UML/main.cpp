#include <iostream>
#include <conio.h>
#include "Faktura.h"
#include "klient.h"
#include "produkt.h"
#include "platnosc.h"

using namespace std;

int main()
{
    Faktura nowa_faktura;
    produkt pierwszy_produkt("Plyta CD",2.50);
    produkt drugi_produkt("Plyta DVD",2.78);
    klient nowy_klient("Damian","Wojtyra","Wegrow");
    platnosc nowa_platnosc;
    nowa_platnosc.zmien_rodzaj('K');
    nowa_faktura.rodzaj_platnosci(nowa_platnosc);
    nowa_faktura.ustaw_odbiorce(nowy_klient);
    nowa_faktura.dodaj_pozycje(pierwszy_produkt);
    nowa_faktura.dodaj_pozycje(drugi_produkt);
    nowa_faktura.drukuj();
    getch();
    return 0;
}
