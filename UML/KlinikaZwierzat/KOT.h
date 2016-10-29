/**
 * Project Untitled
 */


#ifndef _KOT_H
#define _KOT_H

#include "Zwierzak.h"


class KOT: public Zwierzak  {
public:

    string rasa_kota;

    void zaszczep_kota();


KOT();

KOT(string imie, int wiek,int waga);

    /**
     * @param imie
     * @param wiek
     */

};

#endif //_KOT_H
