#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

class Osoba
{
    string Imie;
    string Nazwisko;
    int Wiek;


public:

    Osoba() {} // konstruktor bezargumentowy

    Osoba (string im_osoby, string nazw_osoby, int wiek_osoby) // konstruktor trzargumentowy
    {
        Imie=im_osoby;
        Nazwisko=nazw_osoby;
        Wiek=wiek_osoby;
    }

    void wpiszDaneOsoby(string im_osoby, string nazw_osoby, int wiek_osoby) {
        Imie=im_osoby;
        Nazwisko=nazw_osoby;
        Wiek=wiek_osoby;

    }

    void wyswietlDaneOsoby()
    {
        cout<<Imie<<" "<<Nazwisko<<" "<<Wiek<<endl<<endl;
    }

    string zwrocStringOsoby()
    {
        char buffer[10];
        snprintf(buffer, 10, "%d", Wiek);

        string retVal;
        retVal = Imie;
        retVal += " ";
        retVal += Nazwisko;
        retVal += " ";
        retVal += buffer; // skonwertowac int na string

        return retVal;
    }
};

int main()
{
    // deklaracja zmiennych pomocniczych
    int n,t; // ilosc osob w tablicy (zmienia sie po dodaniu osoby)
    string imie, nazwisko;
    int wiek,miej=0,msc=0;
    Osoba czlowiek;
    n = 3; t = 3;
    ofstream MojPlik;
    MojPlik.open("E:\\Programowanie\\C++\\stopien 2\\Programy_uczelnia\\tablica_stl\\daneOsob.txt",ios::out);

    vector<Osoba> osoby; // konstruktor dwuargumetowy(ilisc elementow, wartosc)

    // ---------wprowadzenie  danych osoby-------
    cout<<"\n Podaj ilosc osob do wpisania\n\n";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout <<"\n Wpis osobe: \n\n";
        cin>>imie>>nazwisko>>wiek;
        czlowiek.wpiszDaneOsoby(imie, nazwisko, wiek);
        osoby.push_back(czlowiek);
        cout<<endl;
    }


    cout<<"\n Wpisz ile osob chcesz dodac  \n\n"<<endl;
    cin >> t;
    int staraMiej = -1;
    for(int i=0; i<t;i++)
    {
    cout<<"\n Wpisz osobe: \n\n";
    cin>>imie>>nazwisko>>wiek;
    czlowiek.wpiszDaneOsoby(imie, nazwisko, wiek);
        cout<<"\n Wpisz pozycje jej wpisania\n\n";
        cin>>miej ;

        if(miej>osoby.size()-1)
            miej = osoby.size();

        vector<Osoba>::iterator c = osoby.begin() + miej; // wpisanie dodatkowo osob do tablicy
        osoby.insert(c, czlowiek);

        staraMiej = miej;
    }
    // ---------usuniecie osoby-------
    cout<<"\n Wpisz nr miejsca osoby ktora chcesz usunac: \n"<<endl;
    cin>>msc;

   if ( (0>msc) || (msc>n-1))
    {
        cout<< "\n Nie ma takiej pozycji do usuniecia\n"<<endl;
    }
    else
    {

        vector<Osoba>::iterator k = osoby.begin() + msc;
        osoby.erase(k);
    }

    // wyswietlenie wpisanych osob
    for ( int i = 0; i < osoby.size(); i++)
    {
        cout<<endl;
        cout << "Osoba [" << i << "] = " << osoby.at(i).zwrocStringOsoby()<< endl;
        cout << endl;
        MojPlik<<"\n"<<osoby.at(i).zwrocStringOsoby()<<"\n";
    }
    MojPlik.close();
    return 0;
}
