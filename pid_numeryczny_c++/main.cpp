#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>
                                      // okres probkowania
#define n 1000                                          // liczba probek
using namespace std;

unsigned skok (unsigned arg) {                    // funkcja do implementacji wymuszen

    unsigned wartosc;
    if ( arg == 0 )
    {                                                   // implementacja skoku jednostkowego
        wartosc = 0;
    }
    else
    {
        wartosc = 1;
    }
    return wartosc;
}

int impuls(int i)
{
    if(i == 1)
    {
        return 200;
    }
    else
    {
        return 0;
    }
}


int main()
{
    double y[n];
    double x[n];
    double Tp = 0.004;                // zadeklarowanie dwoch tablic na probki wejsciowe i wyjsciowe

//fstream plik;
ofstream plik;
plik.open("D:\\MEGA\\Semestr IX\\Pur\\Zadania egzaminacyjne\\Zad\\Zad1\\dane_skok_R1.txt",ios::out);

//plik.open( "dane.txt", ios::out | ios::trunc );
  for(int i = 0; i < n; i++)
    {
        x[i] = skok(i);
    }

    //regulator R1
    for(int i = 0; i <n; i++)
    {

        if(i == 0) {
            y[i] = 0;
        }
        else if(i <= 1)
        {
            y[i]=1.874*y[i-1]+0.0487*x[i-1];
        }
        else {
            y[i]=1.874*y[i-1]-0.8782*y[i-2]+0.0487*x[i-1]-0.04496*x[i-2];
        }
       // plik << 0.004*i << "," << y[i] << "\n";
    }

    //zapis do pliku .txt

    double t = 0;
    plik << "T" << "\t" << "X[nTp]" << "\t" << "Y[nTp]" << endl;
    for ( int i = 0; i < n; i++)
    {
        plik << i*Tp << "\t" << x[i] << "\t" << y[i] * (1.0/0.9)<< endl;
        //t += Tp;
    }
plik.close();

ofstream plik2;
plik2.open("D:\\MEGA\\Semestr IX\\Pur\\Zadania egzaminacyjne\\Zad\\Zad1\\dane_skok_R2.txt",ios::out);

    //regulator R2

    for(int i= 0; i < n; i++)
  {

        if(i == 0) {
            y[i] = 0;
        }
        else if(i <= 1)
        {
            y[i]=1.828*y[i-1]+0.09503*x[i-1];
        }
        else {
            y[i]=1.828*y[i-1]-0.8354*y[i-2]+0.09503*x[i-1]-0.08773*x[i-2];
        }
      // plik2<< 0.004*i << "," << y[i] << "\n";
       double t1 = 0;
       plik2 << i*Tp << "\t" << x[i] << "\t" << y[i] << endl;
       //t1 += Tp;
    }

//    double t1 = 0;
//    plik2 << "T" << "\t" << "X[nTp]" << "\t" << "Y[nTp]" << endl;
//    for ( int i = 0; i < n; i++)
//    {
//        plik2 << t1 << "\t" << x[i] << "\t" << y[i] << endl;
//        t1 += Tp;
//    }

plik2.close();



 //odpowiedz impulsowa
ofstream plik1_impuls;
plik1_impuls.open("D:\\MEGA\\Semestr IX\\Pur\\Zadania egzaminacyjne\\Zad\\Zad1\\dane_impuls_R1.txt",ios::out);
        for(int i = 0; i < n; i++)
    {
        x[i] = impuls(i);
    }
    for(int i = 0; i < n; i++)
    {
        //regulator R1
        if(i == 0) {
            y[i] = 0;
        }
        else if(i <= 1) {
            y[i]=1.874*y[i-1]+0.0487*x[i-1];
        }
        else {
            y[i]=1.874*y[i-1]-0.8782*y[i-2]+0.0487*x[i-1]-0.04496*x[i-2];
        }
        //plik1_impuls << 0.004*i << "," << y[i] << "\n";
    }

    double t2 = 0;
    plik1_impuls << "T" << "\t" << "X[nTp]" << "\t" << "Y[nTp]" << endl;
    for ( int i = 0; i < n; i++)
    {
        plik1_impuls<< t2 << "\t" << x[i] << "\t" << y[i] << endl;
        t2 += Tp;
    }

    plik1_impuls.close();

ofstream plik2_impuls;
plik2_impuls.open("D:\\MEGA\\Semestr IX\\Pur\\Zadania egzaminacyjne\\Zad\\Zad1\\dane_impuls_R2.txt",ios::out);

      //regulator R2
    for(int i = 0; i < n; i++)
    {
        if(i == 0) {
            y[i] = 0;
        }
        else if(i <= 1) {
           y[i]=1.828*y[i-1]+0.09503*x[i-1];
        }
        else {
            y[i]=1.828*y[i-1]-0.8354*y[i-2]+0.09503*x[i-1]-0.08773*x[i-2];
        }
      //  plik2_impuls << 0.004*i << "," << y[i] << "\n";
    }
    double t3 = 0;
    plik2_impuls << "T" << "\t" << "X[nTp]" << "\t" << "Y[nTp]" << endl;
    for ( int i = 0; i < n; i++)
    {
        plik2_impuls << t3 << "\t" << x[i] << "\t" << y[i] << endl;
        t3 += Tp;
    }

    plik2_impuls.close();


    cout << "\n Dane zostaly zapisane - spawdz"<<endl;
    return 0;
}

