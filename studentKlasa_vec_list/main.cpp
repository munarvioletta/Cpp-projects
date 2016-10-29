#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
using namespace std;

class Student
{
 public:
    string Imie;
    string Nazwisko;
    int Ilosc_etcs;

    Student() {} // konstruktor bezargumentowy

    Student(string im_osoby, string nazw_osoby, int ilosc) // konstruktor trzargumentowy
    {
        Imie=im_osoby;
        Nazwisko=nazw_osoby;
        Ilosc_etcs=ilosc;
    }

    void wpiszDaneOsoby(string im_osoby, string nazw_osoby, int ilosc) {
        Imie=im_osoby;
        Nazwisko=nazw_osoby;
        Ilosc_etcs=ilosc;

    }

    void wyswietlDaneOsoby()
    {
        cout<<Imie<<" "<<Nazwisko<<" "<<Ilosc_etcs<<endl<<endl;
    }

    string zwrocStringOsoby()
    {
        char buffer[10];
        snprintf(buffer, 10, "%d", Ilosc_etcs);

        string retVal;
        retVal = Imie;
        retVal += " ";
        retVal += Nazwisko;
        retVal += " ";
        retVal += buffer; // skonwertowac int na string

        return retVal;
    }

};

//prototypy funkcji
void wyswietlListe(list<Student>& );
void funkcjaSortujaca(list<Student>&, int);
void kopiujDoWektora(list<Student>&, vector<Student>& );
void zawartoscWektora(vector<Student>& );
//string znajdzNaLiscie(list<Student>& , string);

//void wypiszImie(list<Student>& );
enum nazwy {imie = 0, nazwisko, il_etsc}; //imie=0, nazwisko =1, ils-etsc=2

int main()
{//wpisywanie danych do listy
    int n;
    cout<<"\n Wpisz ilosc studentow n = "<<endl<<endl;
    cin>>n;
    Student czlowiek;
    vector <Student> osoby(n , czlowiek);
    list <Student> Lista;

    string imie, nazwisko;
    int il_etsc;



    for (int i=0; i<n; i++)
    {
        cout<<"\n Wpisz studenta(imie, nazwisko Ilosc_ETCS): \n"<<endl;
        cin>>imie>>nazwisko>>il_etsc;
        czlowiek.wpiszDaneOsoby(imie, nazwisko, il_etsc);
        Lista.push_back(czlowiek);
    }
   // cout << "Znaleziono aniowskie: " << znajdzNaLiscie(Lista, "aniowska") << endl;

        cout<<"\n\n Lista nieposortowana: \n"<<endl;
        wyswietlListe(Lista);

        //metoda sortujaca liste - funkcja lambdA - funkcja bez nazwy
        funkcjaSortujaca(Lista, nazwy::nazwisko);
        //funkcjaSortujaca(Lista, nazwisko)
        cout<<"\n\n Lista posortowana: \n"<<endl;

        // znajdzNaLiscie(Lista, 'ania');
        wyswietlListe(Lista);

        copy(Lista.begin(), Lista.end(), osoby.begin());

        cout<<"\n Po skopiowaniu do wektora zawartosc wektora to: \n" <<endl;

        for ( int i = 0; i < osoby.size(); i++)
        {
        cout<<endl;
        cout << "Student [" << i << "] = " << osoby.at(i).zwrocStringOsoby()<< endl;
        cout << endl;

        }

    return 0;
}

void funkcjaSortujaca(list<Student>& Lista, int x)
{
    switch (x) {
        case 0 :
            Lista.sort([](const Student& a, const Student& b) { return tolower(a.Imie[0]) < tolower(b.Imie[0]); });
            break;
        case 1 :
            Lista.sort([](const Student& a, const Student& b) { return tolower(a.Nazwisko[0]) < tolower(b.Nazwisko[0]); });
            break;
        case 2 :
            Lista.sort([](const Student& a, const Student& b) { return a.Ilosc_etcs < b.Ilosc_etcs; });
            break;
        default :
            Lista.sort([](const Student& a, const Student& b) { return tolower(a.Nazwisko[0]) < tolower(b.Nazwisko[0]); });
            break;

    }
}

void wyswietlListe(list<Student>& Lista)
 {
     list<Student>::iterator it;

    for (it = Lista.begin(); it != Lista.end(); ++it)
    {
        it -> wyswietlDaneOsoby();
    }
 }

/*string znajdzNaLiscie(list<Student>& v, string K) // lista co wyszukuje osoby po nazwisku i wyswietla imie znalezionych osob
{
    list<Student>::iterator it;
    it = find_if(v.begin(), v.end(), [&K](const Student& a){ return a.Nazwisko == K; }  );
    return it -> Imie;
}*/

/*void wypiszImie(list<Student>& x)
{

        list<Student>::iterator t;
        for (t = x.begin(); t != x.end(); ++t)
        {
            if ( t -> Imie[0] == 'B' )
            {
                cout<<t->Imie<<endl;
            }
        }

}*/
