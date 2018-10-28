#include<iostream>
using namespace std;


int silnia(int n){
int wynik=0;
int sil=1;
  if (n<1)    wynik=1;
  else {
    for (int i=1; i<=n; i++)
    {
    sil=sil*i;
    }
    wynik = sil;
  }
  return wynik;
}

int main()
{
  int n=0;
  int odp = 0;
  cout<<"wpisz liczbe:";
  cin>>n;
  odp = silnia(n);
  cout<<"wynik silni z liczby "<< n<<"! = "<< odp;
  return 0;
}
