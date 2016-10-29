/**
 * Project Untitled
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#ifndef _ZWIERZAK_H
#define _ZWIERZAK_H

class Zwierzak {
public:
    string imie;
    int nr_ID;
    int wiek;
    int waga;
    bool szczepienie;

    Zwierzak(){};
    Zwierzak (string im_pacjenta, int nr_pac, int w, int wag, bool sz);

};

#endif //_ZWIERZAK_H
