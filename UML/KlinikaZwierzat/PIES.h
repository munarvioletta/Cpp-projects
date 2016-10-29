/**
 * Project Untitled
 */


#ifndef _PIES_H
#define _PIES_H

#include "Zwierzak.h"


class PIES final : public Zwierzak {
public:
    string rasa_psa;

    PIES();
    PIES(string, int, int);

    void zaszczep_psa();
};

#endif //_PIES_H
