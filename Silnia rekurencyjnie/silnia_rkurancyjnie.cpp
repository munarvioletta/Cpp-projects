
#include <iostream>
using namespace std;
int wynik;

 long long int silnia(int n)
  {
    if (n<2)
      wynik = 1;
    else{
   // int wynik;
      wynik=n*silnia(n-1);
    }
    return wynik;
  }

int main()
{
  int n;
  cout<<"Wpisz liczbe:";
  cin>>n;
  silnia(n);
  cout<<"Wynik"<<" "<<wynik;
  return 0;
}
