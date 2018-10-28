
#include <iostream> 
#include <assert.h>
using namespace std;

// HEADERS
template <class T>
class Kolejka {

  unsigned int rozmiar = 0;
  T* tab1 = new T[rozmiar];

  public:
  Kolejka();
  ~Kolejka();
  void push(T);
  T pop();
  unsigned int size();
  bool empty();
  void print();

};

// CPP FILE

template <class T>
Kolejka<T>::Kolejka() {}


template <class T>
Kolejka<T>::~Kolejka() {
  delete[] tab1;
}


template <class T>
void Kolejka<T>::push(T liczba) { //dziala ale nie wiem jak

  T * tab2 = new T[rozmiar + 1];
  tab2[rozmiar] = liczba; //dodawanie elementu 

 
  for (int i = 0; i < rozmiar; i++) {
    tab2[i] = tab1[i];

  }

  delete[] tab1;
  tab1 = tab2;
  rozmiar++;

}


template <class T>
T Kolejka<T>::pop() { // dziala nie do konca poprawnie zla wartosc zwracana

  T* tab2 = new T[rozmiar - 1]; // tu zmienilem rozmiar na rozmiar-1
  if (rozmiar == 0) {
    throw 5;
  }

  T zwr_liczba = tab1[0]; // tu zmienilem rozmiar na 0
  for (int i = 0; i < rozmiar; i++) {
    tab2[i] = tab1[i + 1];
  }

  delete[] tab1;
  tab1 = tab2;
  rozmiar--;
  return zwr_liczba;
}
template <class T>
unsigned int Kolejka<T>::size() {
  return this -> rozmiar;
}
template <class T>
bool Kolejka<T>::empty() { //dziala
  return (0 == this -> rozmiar);
}
template <class T>
void Kolejka<T>::print() { //dziala

  cout << " [ ";
  for (int i = 0; i < rozmiar; i++) {

    cout << tab1[i] << " ";
  }
  cout << "]" << endl;
}

int main() {
Kolejka<float> s;  
float element = 0;
int numer = 0;
cout << "                 MENU "<<endl;
cout << "0 - Wyswietl Kolejke"<<endl;
cout << "1 - PUSH - dodaj element na koniec kolejki"<<endl;
cout << "2 - POP -  usuwa element z poczatku kolejki"<<endl;
cout << "3 - SIZE - ilosc elementow w kolejce"<<endl;
cout << "4 - EMPTY - czy kolejka jest pusta"<<endl;
cout << "5 - EXIT - Koniec programu\n\n"<<endl;

while (numer!= 5){
  cout<<"Wybor: ";
  cin>>numer;
  switch (numer){
    case 0:
      std::cout<<"Zawartosc kolejki: ";
      s.print();
      break;
    case 1:
      cout<<"Dodaj element: ";
      cin>>element;
      s.push(element); 
      break;
    case 2:
      try{
        s.pop();
        cout<<"Usunales element z kolejki"<<endl;
      } catch(int e){
        cout<<"Blad - 5 - kolejka jest pusta - nie mozna usunac elementu "<<endl;
      }
      break;
    case 3:
      cout<<" Ilosc elementow w kolejce: ";
      cout<<s.size()<<endl;
      break;
    case 4:
      if (s.empty() == true){
       cout<<"PRAWDA"<<endl;
      }else{
       cout<<"FALSZ"<<endl;
      }
     break;
  }
 }
}
