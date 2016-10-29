#include <iostream>

using namespace std;

// klasa Pies
class Pies
    {
 public: // skladowe publiczne klasy Pies
         // (skladowe zwykle powinny byc prywatne,
         // a dostep do nich powinien odbywac sie poprzez publiczne metody ustawiania i odczytu,
         // np 'void setWiek(int w)' albo 'int getStWkurzalnosci()' itd...
         // zapobiega to ustawieniu nieprawidlowych wartosci skladowych a takze przed nieuprawnionym odczytem
     string imie;
     string rasa;
     int wiek;
     int stWkurzalnosci;

    // konstruktor czteroargumentowy
    Pies(string i, string r, int w, int s)
     {
        imie = i;
        rasa = r;
        wiek = w;
        stWkurzalnosci=s;
     }

    // konstruktor domyslny - bezargumentowy
    Pies()
     {
         cout << "konstruktor bezasrgumetowy"<<"\n";
     }

    // metoda szczekaj() obiektu klasy Pies
    void szczekaj()
    {
        cout<<imie << ": hau hau\n";
    }

    // metoda postarzPsa() obiektu klasy Pies
    void postarzPsa()
    {
        cout<<imie<<" ma teraz " << ++wiek<<"lat"<<"\n";
    }

    // przeciazenie operatora + dla obiektow klasy Pies
    // gdy dodajemy pies1 + pies2, do pies1 odwolujemy sie przez this -> skladowa, drugi obiekt jest argumentem przeciazenia operatora
    // wynikiem dodawania Psow jest Pies (tworzony do returna za pomoca konstruktora)
    Pies operator+ (Pies x) {
        return Pies(this->imie + x.imie,
                    this->rasa + x.rasa,
                    this->wiek + x.wiek,
                    this->stWkurzalnosci + x.stWkurzalnosci);
    }
}; // koniec definicji klasy Pies

// przeciazenie operatora << dla obiektu klasy Pies
ostream& operator << (ostream &wyjscie, const Pies x) {
   return wyjscie << "\n" << "Imie: " << x.imie << "\n"
                    << "Rasa: " <<x.rasa<<"\n"
                    << "Wiek: " << x.wiek << "\n"
                    << "Stopien Wkurzalnosci: " << x.stWkurzalnosci<<"\n";
 } // koniec definicji przeciazenia operatora <<

// prototyp funkcji wywolanie()
void wywolanie(Pies);

// program glowny
int main()
{
    // statyczne tworzenie obiektu luna klasy Pies
    Pies luna;
    luna.imie = "Luna";
    luna.rasa = "labrador";
    luna.wiek = 3;
    luna.stWkurzalnosci = 3;

    // dynamiczne tworzenie obiektu bonifacy klasy Pies*
    Pies* bonifacy;
    bonifacy = new Pies;
    bonifacy -> imie = "Bonifacy";
    bonifacy -> rasa = "jamnik";
    bonifacy -> wiek = 10;
    bonifacy -> stWkurzalnosci = 9;

    // statyczne tworzenie obiektu reksio klasy Pies za pomoca konstruktora - znacznie szybsze
    Pies reksio("reksio", "kundel", 4, 5);

    // wyswietlanie statycznie alokowanej luny
    wywolanie(luna);

    // wyswietlanie dynamicznie alokowanego bonifacego
    wywolanie(*bonifacy);

    // wyswietlanie statycznie alokowanego reksia utworzonego za pomoca konstruktora
    wywolanie(reksio);

    // wywolanie metody szczekaj() obiektu reksio
    reksio.szczekaj();

    // wywolanie metody postarzPsa() obiektu bonifacy alokowanego dynamicznie
    bonifacy->postarzPsa();
    bonifacy->postarzPsa();

    // wyswietlanie luny za pomoca przeciazonego operatora <<
    cout << luna;

    // dodanie reksia i luny do siebie za pomoca przeciazonego operatora + i wyswietlenir za pomoca przeciazonego operatora <<
    cout << reksio + luna;

    // dodanie reksia i luny do siebie za pomoca przeciazonego operatora +
    // i wyswietlenie wyniku za pomoca przeciazonego operatora <<
    Pies lunofacy = luna + *bonifacy;
    cout << lunofacy;

    // usuwanie obiektu bonifacy (byl alokowany dynamicznie)
    delete bonifacy;

    // zwracanie kodu programu - brak bledu
    return 0;
} // koniec programu glownego


// funkcja wyswietlajaca Psa, zamiast ktorej mozna zastosowac przeciazony operator <<
void wywolanie (Pies x)
{
    cout << "\n" << "Imie: " << x.imie << "\n";
    cout << "Rasa: " <<x.rasa<<"\n";
    cout << "Wiek: " << x.wiek << "\n";
    cout << "Stopien Wkurzalnosci: " << x.stWkurzalnosci<<"\n";
}
