/**
 * Project Untitled
 */


#include "produkt.h"
using namespace std;
/**
 * produkt implementation
 */

/**
 * @brief produkt::produkt
 * @param produkt
 */
produkt::produkt(char * produkt,double cena_n)
{
    nazwa = produkt;
    cena = cena_n;

}

/**
 * @brief produkt::zmniejsz_stan
 */
void produkt::zmniejsz_stan() {
ilosc--;
}

/**
 * @return int
 */
int produkt::podaj_ilosc() {
    return ilosc;
}

/**
 * @return double
 */
double produkt::podaj_cene() {
    return cena;
}
/**
 * @brief produkt::zwroc
 */
void produkt::zwroc() {
    ilosc++;
}
void produkt::wypisz()
{
    cout << nazwa << "\t" << cena << endl;
}
