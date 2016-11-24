/**
 * Project Untitled
 */


#ifndef _KLIENT_H
#define _KLIENT_H

class klient {
public:
    klient();
    klient(char* imie_n,  char* nazwisko_n,  char* adres_n);
    /**
     * @param char* imie
     * @param char* nazwisko
     * @param char* adres
     */
    void zmien_dane( char* imie_n,  char* nazwisko_n,  char* adres_n);
    void pokaz_dane();
private:
    char* imie;
    char* nazwisko;
    char* adres;
};

#endif //_KLIENT_H
