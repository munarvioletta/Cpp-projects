
#include "stdio.h"
#include <iostream>
#include <string>
using namespace std;


int A = 0;
int B = 0;
string x;
string result;
string stringA;
string stringB;
int sizeA;
int sizeB;

int wynik;

string solution(int A, int B)
{

if (A<B){

if (sizeA > 1) {

for (int i = 0; i < sizeB; i++)
	{

		if (stringA[0] == stringB[i]) {

			for (int j = 1; j < sizeA; j++) {

				if (stringA[j] == stringB[j + i]) {

					wynik = i;


				}

			}

			x += to_string(wynik) + ",";
		}

	}
}

 else if (sizeA == 1)
 {

	for (int i = 0; i < sizeB; i++)
	{

		if (stringA[0] == stringB[i]) {

					wynik = i;
          x += to_string(wynik) + ",";
		}

 	}

 }
	//return x ;
}

else { x = " Liczba A jest wieksza od B, wpisz poprawną liczbe";}

return x ;
}



int main()
{
  cout<<"Program wyszukuje liczbe A we wpisanej liczbie B i zwraca miejsce polozenia liczby A. UWAGA, liczba A musi być mniejsza od liczby B. Jeżeli liczba A znajduje sie wielokrotnie w liczbie B, zostaną podane wszystkie miejsca polozenia"<<endl<<endl;

	cout << "wpisz A:";
	cin >> A;

	cout << "wpisz B:";
	cin >> B;



	stringA = to_string(A);
	sizeA = stringA.length();
  //cout<< "sizeA "<< sizeA<<endl;

	stringB = to_string(B);
	sizeB = stringB.length();
  // cout<< "sizeB "<< sizeB<<endl;

	string zmienna = solution( A, B);

  //cout<< "zmienna dlu "<< zmienna.length()<<endl;
	if (zmienna.length() == 0) {

		result = "-1"; // brak liczby A w liczbie B
	}
	else result = zmienna;


  	cout << "wynik:" << result;


 // system("\n PAUSE");
	return 0;
}

