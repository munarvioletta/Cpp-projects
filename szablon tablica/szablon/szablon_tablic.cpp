#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

 //------ deklaracje zapowiadajace -----------
 template <typename T> class Zesp;
 template <typename T>
 ostream & operator<<(ostream & wyj, Zesp<T> & x);
 template <typename T>
 istream & operator>>(istream & wej, Zesp<T> & x);

template <typename T>
class Zesp
  {

     T real;
     T imag;
    public:
     Zesp(){real=0.;imag=0.;};  //konstrktor bezargumentowy
     Zesp(T re, T im)      //konstruktor dwuargumentowy
       {
        real=re; imag=im;
       }
     void wstaw(T re, T im) // metoda do wstawiania
      {
        real=re; imag=im;
      }
       Zesp<T> operator+(Zesp<T> &zz); // przci¹¿ony operator dodawania zespol
       Zesp<T> operator-(Zesp<T> &zz); // przci¹¿ony operator odejmowania zespol
       Zesp<T> operator*(Zesp<T> &zz); // przci¹¿ony operator odejmowania zespol
      friend   ostream & operator<<<T>(ostream & wyj, Zesp<T> & x);
      friend  istream & operator>><T>(istream & wej, Zesp<T> & x);
  };
//--------------------Implementacja operatora +  -----------------------
 template<typename T>
 Zesp<T> Zesp<T>::operator+(Zesp<T> &zz)
  {
    Zesp<T> zd;
    zd.real=zz.real+this->real;
    zd.imag=zz.imag+this->imag;
    return zd;
  }
 //---------------Implementacja operatora odejmowania---------------------
  template<typename T>
 Zesp<T> Zesp<T>::operator*(Zesp<T> &zz)
  {

    Zesp<T> zd;
    zd.real=real*zz.real-imag*zz.imag;
    zd.imag=real*zz.imag+imag*zz.real;
    return zd;
  }
 //------------------------------------------------------------------
 template<typename T>
 Zesp<T> Zesp<T>::operator-(Zesp<T> &zz)
  {
    Zesp zd;
    zd.real=this->real-zz.real;
    zd.imag=this->imag-zz.imag;
    return zd;
  }
 //------Implementacja przci¹zonego operatora wypisywania---------
 template<typename T>
  ostream & operator<<(ostream & wyj, Zesp<T> & x)
  {
    wyj<<"("<<x.real<<","<<x.imag<<")";
    return wyj;
  }

 //----------------------------------------------------------------------
  template<typename T>
 istream & operator>>(istream & wej, Zesp<T> & x)
  {
    wej>>x.real>>x.imag;
    return wej;
  }
 //=======================================================================

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


template <typename TYP> class Wektor
{
public:

    int n; // ilosc osob w tablicy (zmienia sie po dodaniu osoby)
    TYP* osoby;
    TYP* c;

    Wektor() {
        n=0;
    }

    int iloscElementow() {
        return n;
    }
    void wpiszOsobe(TYP os, int miejsce) // wpisuje osobe w istniejace miejsce
    {
        osoby[miejsce] = os;
    }


    void dodajOsobe(TYP os, int miejsce)
    {

        if (n==0)
        {
            //cout<< "zapisz na zerowym miejsce" << endl;
            //cout<< "n: " << n << " miejsce: " << miejsce << endl;
            osoby = new TYP[1];
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
                TYP* nowaTablica;
                nowaTablica = new TYP[n+1];
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
                    TYP* nowaTablica;
                    nowaTablica = new TYP[n+1];

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
                    TYP* nowaTablica;
                    nowaTablica = new TYP[n+1];
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
                TYP* nowaTablica;
                nowaTablica = new TYP[n+1];
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

    TYP* zwrocElementy() {
        return osoby;
    }
};


int main()
{
    // deklaracja zmiennych pomocniczych

    string imie, nazwisko;
    int wiek;


    Wektor <Osoba> ludzie;
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

Wektor <Zesp<double> > wektorZespolonych;


   //-----------wypelnianie tablicy liczbami zespolonymi
    for(int i=0;i<4;i++)
    {
        cout<<"\n Wpis liczbe: \n"<<endl;
        Zesp<double> l_zespolona;
        cin>>l_zespolona;
        wektorZespolonych.dodajOsobe(l_zespolona, i);
   }

   for(int i=0;i<wektorZespolonych.iloscElementow();i++)
    {
        cout << *(wektorZespolonych.zwrocElementy() + i) << endl ; // zwraca wskaznik i za jego pomoca dobieram sie do odpowiedniego elementu tablicy, po czym wyswietlam go
    }


    return 0;
}
