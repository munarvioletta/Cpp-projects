
#include <iostream>
#include <assert.h>

// HEADERS
class Stos {
  unsigned int rozmiar = 0;
  float *wsk = NULL;
  
  public:
  Stos();
  ~Stos();
  float pop();
  void push(float);
  unsigned int size();
  float* top(); //zwraca adres wiercholka
  void print();
};

// CPP FILE
Stos::Stos(){}

Stos::~Stos(){
  
  delete[] wsk;
}

float Stos::pop(){
  
 float el_do_zwr = 0;
 if (rozmiar == 0) {
   throw 5;
 }
 
 float* nowatab = new float[rozmiar-1];
 for(int i=0; i<rozmiar-1; i++)
 {
   nowatab[i] = wsk[i+1];
 }
 
 el_do_zwr = wsk[0];
 
 delete[] wsk;
 wsk = nowatab;
 rozmiar--;
 
 
 return el_do_zwr;
}

void Stos::push(float x){

  // alokacja nowej tablicy
  float *nowatab = new float[rozmiar+1]; 
  
  // wpisywanie nowego elementu
  nowatab[0] = x;
  
  // przepisywanie starej tablicy do nowej
  for(int i=0; i<rozmiar; i++)
  {
    nowatab[i+1] = wsk[i];
  }
  
  // usuwanie pamieci po starej tablicy
  delete[] wsk;
  
  // pointer tablicy wskazuje na nowa tablice
  wsk = nowatab;
    
  // zwiekszenie rozmiaru o jeden
  rozmiar++;
}

unsigned int Stos::size(){
  
  return rozmiar;
}

float* Stos::top(){
  // zwaraca adres wierzcholka
  if (rozmiar == 0) {
    throw 7;
  }
  
  
  float* wynik = this->wsk;
  return wynik;
  

}

void Stos::print(){
  std::cout << "[ ";
  for(int i=0; i<size(); i++){
    std::cout<<wsk[i] << " ";
  }
  std::cout << "]\n";
    
}

// MAIN
int main() {
  // {
  //   float a = 4.0;
  //   float b = 5.0;
  //   float c = 6.0;
  //   float d = 7.0;
  //   float e = 8.0;
    
  //   Stos s;
  //   s.push(a);
    
  //   assert(*s.top() == a);
  //   assert(s.size() == 1);
    
  //   assert(s.pop() == a);
  //   assert(s.size() == 0);
    
  //   try {
  //     s.pop(); // problem: pusta tablica i usuwam
  //   } catch (int e){
      
  //   }
    
  //   assert(s.size() == 0);
    
  //   s.push(a);
  //   s.push(b);
  //   s.push(c);
  //   s.push(d);
  //   s.push(e);
    
  //   assert(s.size() == 5);
    
  //   s.print();
  
    
  // }
  
  Stos moj_stos;
  //unsigned int wielkosc = 0;
  unsigned int r = 0;
  int numer = 0;
  float* adres = NULL;
  //std::cout<<"Wpisz wielkosc stosu:"<<std::endl;
  //std::cin >> wielkosc;
  
  std::cout<< "MENU"<<std::endl;
  std::cout<<"Wybierz opcje"<<std::endl;
  std::cout<<"0 - wyswietl stos"<<std::endl;
  std::cout<<"1 - dodaj element"<<std::endl;
  std::cout<<"2 - usun element"<<std::endl;
  std::cout<<"3 - wyswietl rozmiar stosu "<<std::endl;
  std::cout<<"4 - wyswietl adres wierzcholka "<<std::endl;
  std::cout<<"5 - wyjdz"<<std::endl;
  std::cin>>numer;  
  
 while(numer != 5){
  
  switch (numer)
  {
    case 0:
      std::cout<<"Zawartosc stosu: ";
      moj_stos.print();
      break;
    case 1:
      
    //  for (int i=0; i<wielkosc;i++){
      float x;
      std::cout<<"Dodaj element: ";
      std::cin >> x;
      moj_stos.push(x);
   // }
      break;
    case 2:
    try{
      moj_stos.pop();
      std::cout<<"Usunales element"<<std::endl;
    } catch(int s){
      std::cout<<"Blad " << s << " - nie mozna usunac elementu, brak elementow na stosie"<<std::endl;
    }
    
      break;
    case 3:
      std::cout<<"Rozmiar stosu to: ";
      r = moj_stos.size();
      std::cout<<r<<std::endl;
      break;
    case 4:
      try {
        adres = moj_stos.top();
        std::cout<<"Adres wierzcholka to: ";
        std::cout<<adres<<std::endl;
      } catch (int e) {
        std::cout<<"Blad " << e << " - brak elementow na stosie"<<std::endl;
      }
      
      break;
  }
  std::cin>>numer;  
 }  
}





