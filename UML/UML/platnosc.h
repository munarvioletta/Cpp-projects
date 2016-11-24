/**
 * Project Untitled
 */


#ifndef _PLATNOSC_H
#define _PLATNOSC_H

class platnosc {
public:
    platnosc();
    bool zrealizuj();
    void zmien_rodzaj(char rodz);
    void wypisz_rodz();
private:
    bool zrealizowana;
    char rodzaj_platnosci;
};

#endif //_PLATNOSC_H
