#include <iostream>
#include<assert.h>
using namespace std;
//Headers
class Priority_queue{
  unsigned int rozmiar = 0;
  float* tab_glowna = new float[rozmiar];
  
  
  public:
  void push(float);
  
  float pop();
  unsigned int size();
  bool empty();
  float top();
  void print();
  
};

// cpp file

  void Priority_queue::push(float liczba){
    
    float* tab_pomoc = new float[rozmiar+1];
    tab_pomoc[rozmiar] = liczba;
    for (int i = 0; i<rozmiar; i++){
      tab_pomoc[i] = tab_glowna[i];
    }

    delete [] tab_glowna;
    tab_glowna = tab_pomoc;
    //sortowanie babelkowe
    for (int j = 0; j<rozmiar; j++){    
     for (int i = 0; i<rozmiar; i++){
      if (tab_glowna[i+1]>tab_glowna[i]){
        float a = 0; //zmienna pomocniczna
        a = tab_glowna[i+1];
        tab_glowna[i+1] = tab_glowna[i];
        tab_glowna[i] = a;
      }
     }
    } 
    rozmiar++;
  }
  
  float  Priority_queue::pop(){
    float* tab_pomoc = new float[rozmiar-1];
    if (rozmiar == 0) {
    throw std::runtime_error("Proba uzyskania pop() przy pustej kolejce.");
    }
    float liczb_do_zwr = tab_glowna[0];
    
    for (int i = 0; i<rozmiar; i++){
      tab_pomoc[i] = tab_glowna[i+1];
    }
    
    delete [] tab_glowna;
    tab_glowna = tab_pomoc;
    rozmiar--;
    return liczb_do_zwr;
  }
  unsigned int  Priority_queue::size(){
    return this-> rozmiar;
  }
  bool  Priority_queue::empty(){
    return (0 == this->rozmiar);
  }
  float  Priority_queue::top(){
    if(0 == rozmiar){
      throw std::runtime_error("Proba uzyskania top() przy pustej kolejce.");
    }
    return tab_glowna[0];
  }
  
  // void Priority_queue:: print(){
  //   cout<<"[ ";
  //   for (int i = 0; i<rozmiar; i++){
  //     cout<<tab_glowna[i]<<" ";
  //   }
  //   cout<<"] ";
  // }
  
int main()
{
  {
    float a = 6;
    float b = 9;
    float c = 10;
    float d = 5;
    float e = 15;
    Priority_queue k;
    assert(k.empty() == 1);
    k.push(a);
    k.push(b);
    k.push(c);
    k.push(d);
    k.push(e);
    assert(k.size() == 5);
    float m = k.pop();
    cout<<" liczba usunieta to: "<< m;
    
    float kpop = k.pop();
    std::cout << "\nTeraz bedzie assert(" << kpop << " == " << c << ")\n";
    assert(kpop == c);// - nie dziala nie mam pojecia czemu
    assert(k.size() == 3);
   
   // k.print();
    // float l = k.top();
    // cout<<"\n Wartość pierwszego elementu w kolejce priorytetowej: " << l<<endl;
    k.empty();
    
  }
  
  {
    Priority_queue pq;
    assert(0 == pq.size());
    
    pq.push(2);
    assert(1 == pq.size());
    assert(!pq.empty());
    assert(2 == pq.pop());
    assert(0 == pq.size());
    assert(pq.empty());
    
    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(2);
    
    assert(4 == pq.size());
    assert(5 == pq.pop());
    assert(3 == pq.size());
    assert(4 == pq.pop());
    assert(2 == pq.size());
    assert(3 == pq.pop());
    assert(1 == pq.size());
    assert(2 == pq.pop());
    assert(0 == pq.size());
    
    // return 0;
  }
  
  
  
  
  
    cout << "                 MENU "<<endl;
   // cout << "0 - Wyswietl Kolejke"<<endl;
    cout << "1 - PUSH - dodaj element na koniec kolejki"<<endl;
    cout << "2 - POP -  usuwa element z poczatku kolejki"<<endl;
    cout << "3 - SIZE - ilosc elementow w kolejce"<<endl;
    cout << "4 - EMPTY - czy kolejka jest pusta"<<endl;
    cout << "5 - TOP - zwraca wartość pierwszego elementu w kolejce priorytetowej"<<endl;
    cout << "6 - EXIT - Koniec programu\n\n"<<endl;
    
    Priority_queue kolejka;
    int n = 0;
    float x; //zmienna przyjmujaca elementy do kolejki
    while (n!= 6){
     
    cout<<"Wybor: ";
    cin>>n;
     
      switch(n){
        case 0:
          // kolejka.print();
          cout<<endl;
          break;
          
        case 1:
          cout<<"Dodaj element do kolejki: ";
          cin>>x;
          kolejka.push(x);
          break;
        case 2:
          try{
            kolejka.pop();
            cout<<"Usunales element z poczatku kolejki"<<endl;
          } catch(const std::runtime_error& b) {
            
            cout<< "Blad - 5 - brak elementow w kolejce do ususniecia"<<endl;
          }
          break;
        case 3:
          cout<<"Ilosc elementow w kolejce: "<<kolejka.size()<<endl;
          
          break;
        case 4:
          if (kolejka.empty() == 1){cout<<"Kolejka pusta? -  PRAWDA"<<endl;}
          else{cout<<"Kolejka pusta? - FALSZ"<<endl;}
          break;
        case 5:
          try{
            cout<<"Wartość pierwszego elementu w kolejce priorytetowej: "<<kolejka.top()<<endl;
          } catch(const std::runtime_error& b) {
            
            cout<< "Blad - 5 - brak elementow w kolejce"<<endl; 
          }
          break;
        
      }
    }
    
  
  cout<<"Wyszedles z programu"<<endl;  
  return 0;
}
