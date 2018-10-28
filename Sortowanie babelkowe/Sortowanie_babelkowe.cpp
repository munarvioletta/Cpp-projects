#include <iostream>
using namespace std;
# include <math.h>
#include <iomanip>
#include <assert.h>     /* assert */

const int nn = 5;
float t[nn]; 

void wczytaj(float *tab, int n){
  std:: cout<<"SORTOWANIE BABELKOWE \n\n";
  std:: cout<<" Wpisz 5 liczb zmiennoprzecinkowych odzielajac czesc calkowita od dziesietnej kropka \n";
  for (int i=0; i<n; i++) {
   std:: cin>>tab[i];
  }  
 
}

float srednia(float *tab , int n ){    
  
   float srednia = 0;
   float suma = 0;
   
  for (int i=0; i<n; i++) {
   suma = suma + tab[i];
  }  
   srednia = suma/n;
   
   std::cout << "\nSrednia wynosi: " << srednia <<endl<<endl;
   
  return  srednia;
}

void licz_roznice(float *tab, float *tab2, float srednia, int n){
  
  std:: cout<< "Tablica roznic: \n";

  for(int i=0; i<n;i++){
    
     tab2[i] = (srednia - tab[i]);
     std:: cout<< "\t"<<tab2 [i];
     
  }

}

float minelemsort(float *roznica, int n){
  
  
  std:: cout<< "\nPosortowana tablica roznic: \n";
  for (int i=0; i<n;i++){ 
    for(int j=1; j<n; j++){
      if (fabs(roznica[j]) < fabs(roznica[j-1])){
        float bufor = roznica[j-1];
        roznica[j-1] = roznica[j];
        roznica[j]=bufor;
      }
      }
  }
  
  
  // wyswietlanie
  for(int i=0; i<n; i++){
  std::cout << "\t"<< roznica[i];
  //std::cout << std::setprecision(3)<< "\t"<< roznica[i];
  }
  
  return roznica[0];
  
// }
}

float znajdz_min(float *tab, int n){
  
  float min_el = tab[0];
  
  for (int i=1; i<n;i++){
    if (fabs(tab[i]) < fabs(min_el))
      min_el = tab[i];
  }
  
  return min_el;
}

float najblizsza_liczba(float min_el, float sr, int n){
  
  //float n_liczba = sr - roznica[0];
  float n_liczba = sr - min_el;
  
  return n_liczba;
}


int main() {

   wczytaj(t, nn);
   float s = srednia(t,nn);
   float r[nn];
   licz_roznice(t, r, s, nn); // modyfikacja r - wpisywanie do niej roznic z t
   //float sor_r = sortuj(r);
   //float elem_min = najblizsza_liczba(r, s, n);
   float elem_min = znajdz_min(r, nn);
   float elem_min_sort = minelemsort(r, nn); 
   assert(elem_min == elem_min_sort); // zabezpieczenie: wyrzuci blad jak nie beda rowne
   
   std::cout << "\n\nMinimalny element w tablicy to:  " << elem_min << " \n";
   float najb_liczba = najblizsza_liczba (elem_min, s, nn);
   std:: cout<< "\nNajblizsza liczba do sredniej to: "<<najb_liczba<<endl;
   
}
