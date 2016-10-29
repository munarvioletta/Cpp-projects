#include <iostream>

using namespace std;

class Zwierzak
{
protected:
   string plec;
   string imie;
   int wzrost;
   string jedzenie;

public:
   Zwierzak() {}
   Zwierzak(string im, string p, int wzr, string jedz)
   {
       imie = im; plec=p; wzrost =wzr; jedzenie = jedz;
   }
   virtual void dajGlos()
    {
        cout<<"\n Daje glos: wol WOL WOL \n"<<endl;
    }

    void jedz()
    {
        cout<<"\n Jem : "<<jedzenie<<endl;
    }
};

class Kotek: public Zwierzak
{
    // zmienne sa dziedziczone z innej klasy
public:
    Kotek(string im, string p, int wzr, string jedz)
   {
       imie = im; plec=p; wzrost =wzr; jedzenie = jedz;
   }

    void dajGlos() //
    {
        cout<<"\n mial mial mial \n"<<endl;
    }
};

class Piesek: public Zwierzak
{
    // zmienne sa dziedziczone z innej klasy
public:
    Piesek(string im, string p, int wzr, string jedz)
   {
       imie = im; plec=p; wzrost =wzr; jedzenie = jedz;
   }

    void dajGlos() //
    {
        cout<<"\n hauhauhau \n"<<endl;
    }
};



int main()
{
    Zwierzak zwierz("janek", "menska", 125, "kupa");
    zwierz.dajGlos();
    zwierz.jedz();

    Kotek fanucy("fanucy", "¿eñska", 150, "karma dla kotow i ryby");
    fanucy.dajGlos();
    fanucy.jedz();

    Zwierzak* ala = new Kotek("zzz", "¿eñska", 150, "karma dla kotow i ryby");
    ala->dajGlos();
    ala->jedz();

    Piesek reksio("fanucy", "¿eñska", 150, "karma dla kotow i ryby");
    reksio.dajGlos();
    reksio.jedz();

    Zwierzak tablicaZwierzakow[3]; // tablica obiektow typu zwierzak lub pochodnych!
    tablicaZwierzakow[0] = zwierz; // do talicy zwierzakow wstawiam zwierzaka
    tablicaZwierzakow[1] = fanucy; // do tablicy zwierzakow wstawiam kotka
    tablicaZwierzakow[2] = reksio; // do tablicy zwierzakow wstawiam pieska



    return 0;
}
