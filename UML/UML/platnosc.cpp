/**
 * Project Untitled
 */


#include "platnosc.h"
#include <iostream>
using namespace std;
/**
 * platnosc implementation
 */

platnosc::platnosc()
{
    zrealizowana = false;
    rodzaj_platnosci = 'G';
}
/**
 * @brief platnosc::zrealizuj
 * @return
 */
bool platnosc::zrealizuj() {
    zrealizowana = true;
    return true;
}
/**
 * @brief platnosc::zmien_rodzaj
 * @param rodz
 */
void platnosc::zmien_rodzaj(char rodz) {
    rodzaj_platnosci = rodz;
}
void platnosc::wypisz_rodz()
{
    if(rodzaj_platnosci == 'G')
    {
        cout << "Rodzaj platnosci: Gotowka" << endl;
    }
    else
    {
        cout << "Rodzaj platnosci: Karta" << endl;
    }
}
