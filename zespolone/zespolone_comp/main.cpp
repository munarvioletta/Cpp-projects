#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <complex>
#include <fstream>

//Klasa ZESPOLONE z wykorzystaniem bilioteki COMPLEX
using namespace std;

//void zapisDoPliku(ofstream&, vector<complex<double> > , int );
int main()
{
    // deklaracja zmiennych pomocniczych
int m, poz=0,poz_usun=0; // ilosc osob w tablicy (zmienia sie po dodaniu osoby)
ofstream MojPlik;
MojPlik.open("E:\\Programowanie\\C++\\stopien 2\\Programy_uczelnia\\zespolone\\plik.txt",ios::out);

complex<double> z1(1.5, 3.3);
complex<double> z2(2, 5.6);
vector <complex<double> > liczby;

cout<<"\n Wpisz ile liczb chcesz wpisaæ: \n\n";
cin>> m;

complex<double> a(0), b(0), c(1,0), d(1,0);

for(int i = 0; i<m; i++)
{
    cout<<"\n Wpis liczbe zespolona: \n" <<endl;
    complex<double> temp;
    cin >> temp;
    liczby.push_back(temp);
    a += temp;
    b -= temp;
    c *= temp;
    d /= temp;
}

cout <<"\n Suma liczb\n " <<endl<<"\t"<<a<<endl;
cout << "\n Roznica liczb\n " <<endl<<"\t"<< b<<endl;
cout<< "\n Iloczyn liczb\n" <<endl<<"\t"<< c<<endl;
cout<< " \n Iloraz liczb\n" <<endl<<"\t"<< d << endl;

    liczby.push_back(a);
    liczby.push_back(b);
    liczby.push_back(c);
    liczby.push_back(d);

//dopisywanie liczb
    int f;
    cout<<"\n\n Wpisz ile liczb chcesz dodac \n\n"<<endl;
    cin >> f;

for(int i=0; i<f;i++)
    {
        cout<<"\n Wpisz liczbe: \n"<<endl;
        complex<double> zesp;
        cin>>zesp;
        cout<<"\n Wpisz pozycje jej wpisania\n\n";
        cin>>poz ;

            if(poz>liczby.size()-1)
                poz = liczby.size();

            vector<complex<double> >::iterator c = liczby.begin() + poz; // wpisanie dodatkowo osob do tablicy
            liczby.insert(c, zesp);
            //staraMiej = miej;
    }

    // ---------usuniecie liczby-------

    cout<<"\n Wpisz nr miejsca liczby ktora chcesz usunac: \n"<<endl;
    cin>>poz_usun;

   if ( (0>poz_usun) || (poz_usun>liczby.size()-1))
    {
        cout<< "\n Nie ma takiej pozycji do usuniecia\n"<<endl;
    }
    else
    {
        vector<complex<double> >::iterator k = liczby.begin() + poz_usun;
        liczby.erase(k);
    }
// -------wyswietlanie tablicy

cout<< "\n Zawartosc tablicy: \n"<<endl;
for (int i=0; i<liczby.size();i++)
{
    cout << "Pozycja[" << i << "] = " << liczby.at(i)<< endl;
    cout << endl;

    //zapisDoPliku(MojPlik, liczby, i);
    MojPlik << liczby.at(i)<<"\n";

}

    MojPlik.close();
    return 0;
}

/*void zapisDoPliku(ofstream& plik, vector<complex<double> > v, int j)
{
    plik << v.at(j);
}*/






