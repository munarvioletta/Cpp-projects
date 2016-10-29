#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

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
};

// -------klasa wektor------------

class Wektor
{
public:

    int n; // ilosc osob w tablicy (zmienia sie po dodaniu osoby)
    Osoba* osoby;
    Osoba* c;

    Wektor() {
        n=0;
    }

    int iloscElementow() {
        return n;
    }
    void wpiszOsobe(Osoba os, int miejsce) // wpisuje osobe w istniejace miejsce
    {
        osoby[miejsce] = os;
    }


    void dodajOsobe(Osoba os, int miejsce)
    {

        if (n==0)
        {
            //cout<< "zapisz na zerowym miejsce" << endl;
            //cout<< "n: " << n << " miejsce: " << miejsce << endl;
            osoby = new Osoba[1];
            osoby[0]=os; //wpiszOsobe(os, 0);
            n=n+1;
        }
        else
        {
            if ( (0<miejsce) && (miejsce<=n))
            {
                //cout << "zapisz gdzies w srodku "<< endl;
                //cout<< "n: " << n << " miejsce: " << miejsce << endl;
                // tworzenie nowej tablicy[n+1]
                Osoba* nowaTablica;
                nowaTablica = new Osoba[n+1];
                // przepisanie elementow ze starej tablicy do nowej
                for(int i=0; i<miejsce;i++)// przepisz()
                {
                   nowaTablica[i]=osoby[i];
                }
                // wpisanie nowego elementu na i-te miejsce //wpiszOsobe

                nowaTablica[miejsce] = os;
                // przesuniecie tablicy od i-tego elementu w prawo
                for(int i=miejsce+1;i<n+1;i++) //przesunPrawo()
                {
                   nowaTablica[i]=osoby[i-1];
                }

                //osoby = nowaTablica;
                //Osoba* c;
                c=nowaTablica;
                nowaTablica = osoby;
                osoby = c;
                c=nowaTablica;

                //delete c;
                delete[] nowaTablica;
                n++;
            }
            else
            {
                if(miejsce <=0)
                {
                    //cout<<"zapisz na zwrowe miejsce"<<endl;
                    //cout<< "n: " << n << " miejsce: " << miejsce << endl;
                    // tworzenie nowej tablicy[n+1]
                    Osoba* nowaTablica;
                    nowaTablica = new Osoba[n+1];

                    // wpisanie nowego elementu na i-te miejsce

                    nowaTablica[0] = os;
                    // przesuniecie tablicy od i-tego elementu w prawo
                    for(int i=1;i<n+1;i++)
                    {
                       nowaTablica[i]=osoby[i-1];
                    }

                    //osoby = nowaTablica;
                    //Osoba* c;
                    c=nowaTablica;
                    nowaTablica = osoby;
                    osoby = c;
                    c=nowaTablica;

                   // delete c;
                    delete[] nowaTablica;
                    n++;
                }
                else
                {
                    //cout<<"zapisz na n-tym miejscu"<<endl;
                    //cout<< "n: " << n << " miejsce: " << miejsce << endl;
                        // tworzenie nowej tablicy[n+1]
                    Osoba* nowaTablica;
                    nowaTablica = new Osoba[n+1];
                    // przepisanie elementow ze starej tablicy do nowej
                    for(int i=0; i<n;i++)
                    {
                       nowaTablica[i]=osoby[i];
                    }
                    // wpisanie nowego elementu na i-te miejsce
                    nowaTablica[n]=os;
                     //osoby = nowaTablica;
                    //Osoba* c;
                    c=nowaTablica;
                    nowaTablica = osoby;
                    osoby = c;
                    c=nowaTablica;

                    //delete c;
                    delete[] nowaTablica;
                    n++;
                }
            }

        }
    }
    void usunOsobe(int miejsce)
    {
         if (n==0)
        {
            cout<< "nie ma pozycji do usuniecia" << endl;
            cout<< "n: " << n << " miejsce: " << miejsce << endl;

        }
        else
        {
            if ( (0<=miejsce) && (miejsce<n))
            {
                //cout << "zapisz gdzies w srodku "<< endl;
                //cout<< "n: " << n << " miejsce: " << miejsce << endl;
                // tworzenie nowej tablicy[n+1]
                Osoba* nowaTablica;
                nowaTablica = new Osoba[n+1];
                // przepisanie elementow ze starej tablicy do nowej
                for(int i=0; i<miejsce;i++)// przepisz()
                {
                   nowaTablica[i]=osoby[i];
                }


                // przesuniecie tablicy od i-tego elementu w prawo
                for(int i=miejsce;i<n-1;i++) //przesunPrawo()
                {
                   nowaTablica[i]=osoby[i+1];
                }

                //osoby = nowaTablica;
                //Osoba* c;
                c=nowaTablica;
                nowaTablica = osoby;
                osoby = c;
                c=nowaTablica;

                //delete c;
                delete[] nowaTablica;
                n--;
            }
            else
            {
                if(miejsce <=0)
                {
                    cout<<"nie ma pozycji do usuniecia"<<endl;
                    //cout<< "n: " << n << " miejsce: " << miejsce << endl;
                    // tworzenie nowej tablicy[n+1]

                }
                else
                {

                     cout<<"nie ma takiej pozycji do usuniecia"<<endl;
                }
            }

        }
    }


    void wyswietlOsobe(int i) {
        osoby[i].wyswietlDaneOsoby();
    }
};


int main()
{
    // deklaracja zmiennych pomocniczych

    string imie, nazwisko;
    int wiek;


    Wektor ludzie;
    int msc;

// ---------wprowadzenie  danych osoby-------
int nn = 1;
    for(int i=0;i<nn;i++)
    {
        cout<<"\n Wpis osobe: \n"<<endl;
        cin>>imie>>nazwisko>>wiek>>msc;
        Osoba czlowiek;
        czlowiek.wpiszDaneOsoby(imie, nazwisko, wiek);
        ludzie.dodajOsobe(czlowiek, msc);
   }

cout << "\n koniec wypelniania poczatkowego"<<endl;

    cout<<"\n Wpis osobe: \n"<<endl;
    cin>>imie>>nazwisko>>wiek>>msc;
    Osoba czlowiek; czlowiek.wpiszDaneOsoby(imie, nazwisko, wiek);
    ludzie.dodajOsobe(czlowiek, msc);

    cout<<"\n Wpis osobe: \n"<<endl;
    cin>>imie>>nazwisko>>wiek>>msc;
    //Osoba czlowiek;
    czlowiek.wpiszDaneOsoby(imie, nazwisko, wiek);
    ludzie.dodajOsobe(czlowiek, msc);

    cout<<"Wpisz nr miejsca osoby ktora chcesz usunac: "<<endl;
    cin>>msc;

    ludzie.usunOsobe(msc);
    //------wyswietlanie----------

     for(int i=0;i<ludzie.iloscElementow();i++)
    {
        ludzie.wyswietlOsobe(i);
    }


    return 0;
}
