#include <iostream>
#include <stdio.h>
#include <string>
#include "KOT.cpp"
#include "PIES.cpp"
#include "GRYZON.cpp"
#include "Klinika.cpp"


using namespace std;

void dodajPacjenta(Klinika& kl)
{
    string imie;
    int wiek;
    int waga;
    int typ;
    Zwierzak* pacjent;


    cout<<"Wybierz typ pacjenta do dodania: "<<endl<<endl;
    cout<< "1: KOT"<<endl;
    cout<< "2: PIES"<<endl;
    cout<< "3: GRYZOÑ"<<endl;

    cin>>typ;
    switch (typ)
    {
    case 1:
        cout<<"\n Wpisz dane kota \n"<<endl;
        cin>>imie>>wiek>>waga;
        //KOT pacjent(imie, wiek, waga);
        //pacjent = (Zwierzak*) new KOT(imie, wiek, waga);
        kl.dodaj(* new KOT(imie, wiek, waga));
    break;

    case 2:
        cout<<"\n Wpisz dane psa \n"<<endl;
        cin>>imie>>wiek>>waga;
        //PIES pacjent(imie, wiek, waga);
        pacjent = new PIES(imie, wiek, waga);
        kl.dodaj(*pacjent);
    break;

    case 3:
        cout<<"\n Wpisz dane psa \n"<<endl;
        cin>>imie>>wiek>>waga;
        //PIES pacjent(imie, wiek, waga);
        //pacjent = (Zwierzak*) new GRYZON(imie, wiek, waga);
        kl.dodaj( * new GRYZON(imie, wiek, waga) );
    break;
    }
}

int main()
{
    Klinika k;
    int n;
    string imie;
    int wiek;
    int waga;

    int opcja = 0;

    cout<<" Klinika "<< k.Nazwa <<endl<<endl;
    cout<< " Ulica " << k.Ulica<<" \n\n"<<" NR Kliniki "<<k.numer<<endl<<endl;

    cout << "MENU GLOWNE" << endl;
    cout<<"Wybierz opcje"<<endl<<endl;
    cout<<endl;
    cout << "-----------------" << endl;
    cout << "1. Dodaj pacjenta" << endl;
    cout << "2. Wyswietl liste pacjentow" << endl;
    cout << "3. Usun Pacjenta" << endl;
    cout << "9. Wyjdz z menu" << endl;
    cout<<endl;

while (opcja != 9){


    cin >> opcja;

    switch (opcja)
    {
        case 1: dodajPacjenta(k);

        break;
        case 2:   k.wyswietl();

        break;
        default: break;

    }
}




//   for (int i=0; i<n; i++)
//    {
//        cout<<"\n Wpisz dane kota \n"<<endl;
//        cin>>imie>>wiek>>waga;
//        KOT pacjent(imie, wiek, waga);
//        k.dodaj(pacjent);
//        //czlowiek.wpiszDaneOsoby(imie, nazwisko, il_etsc);
//    }


    //pacjent.waga = 22;

    return 0;

}
