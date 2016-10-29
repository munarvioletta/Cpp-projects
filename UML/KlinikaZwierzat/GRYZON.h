/**
 * Project Untitled
 */


#ifndef _GRYZON_H
#define _GRYZON_H

#include "Zwierzak.h"


class GRYZON final : public Zwierzak {
public:

    string rasa_gryzonia;

    void zaszczep_gryzonia();

   GRYZON();
   GRYZON(string ,int ,int);
};



#endif //_GRYZON_H
