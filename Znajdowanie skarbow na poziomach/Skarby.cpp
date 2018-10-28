
#include <iostream>
#include <algorithm>
#include "stdio.h"

template <typename T>
void print_vector(T* v, int n) {
	for (int i = 0; i<n; i++) 
		std::cout << v[i] << "\t";
	std::cout << std::endl;
}

int main() {
  
    std:: cout<<"\n Zadanie - Poszukiwanie Skarbow - OPIS"<<std::endl<<std::endl;
    std:: cout<<" Nawisas '(' oznacza zejscie o 1 poziom niżej"<<std::endl;
    std:: cout<<" Nawisas ')' oznacza wejscie o 1 poziom wyzej"<<std::endl;
    std:: cout<<" Znak '*' oznacza skarb"<<std::endl<<std::endl;
    std:: cout<<" START na poziomie -1"<<std::endl<<std::endl;
    
    
    std::string tekst = "(((*))(((((*)))*))))(";

    std::cout<<"Aktualna sciezka: "<< tekst<<std::endl<<std::endl;
    
    int poziomy[tekst.size()];
    int skarbow_na_poz[tekst.size()+1];
    
    int aktualny_poziom = -1; // START na poziomie -1
    
    for (int i = 0; i < tekst.size(); i++) {
    	poziomy[i] = 0;
    	skarbow_na_poz[i] = 0;
    }
    skarbow_na_poz[tekst.size()] = 0;      
    for (int i = 0; i < tekst.size(); i++) {
    	if (tekst[i] == '(') {
    		aktualny_poziom--;
    	}
    	if (tekst[i] == ')') {
    		aktualny_poziom++;
    	}
    	if (tekst[i] == '*') {
    		skarbow_na_poz[-aktualny_poziom]++;
    	}
    	poziomy[i] = aktualny_poziom;
    }

          
    print_vector(&tekst[0], tekst.size());
    std::cout<<"\n\n";
    print_vector(poziomy, tekst.size());
    std::cout<<"\n\n";
    print_vector(skarbow_na_poz, tekst.size()+1);
    
    

    auto max_skarb_ptr = std::max_element(&skarbow_na_poz[0], &skarbow_na_poz[tekst.size()]);

    std::cout<<"\n\n";

    int  max_skarb_ptr_w_vek    = max_skarb_ptr - &skarbow_na_poz[0];
    
    int poziom_z_max_il_skarbow = -max_skarb_ptr_w_vek;

    std::cout << "Max ilosc skarbow " << *max_skarb_ptr << " na poziomie " << poziom_z_max_il_skarbow << std::endl;
    
    auto min_level_ptr       = std::min_element(&poziomy[0], &poziomy[tekst.size()]);
    int  min_poziom = *min_level_ptr;

    std::cout << "Minimalny poziom " << min_poziom << std::endl;

    if (skarbow_na_poz[-poziom_z_max_il_skarbow] > 0){

	    if (poziom_z_max_il_skarbow == min_poziom || skarbow_na_poz[-min_poziom] == skarbow_na_poz[-poziom_z_max_il_skarbow]) {

		    std::cout << "Na najnizszym poziomie: " << min_poziom << " jest najwiecej skarbow: " << skarbow_na_poz[-min_poziom]  << std::endl;

	    } else {

	    	std::cout << "Na najnizszym poziomie: " << min_poziom << " nie jest najwiecej skarbow: " << skarbow_na_poz[-min_poziom]  << std::endl;

	    	std::cout << "Na poziomie: " << poziom_z_max_il_skarbow << " jest " << skarbow_na_poz[-poziom_z_max_il_skarbow]  << " skarbow."  << std::endl;
	    }
    }

    else {
    	std::cout << "Nie ma skarbow!"  << std::endl;
    }
    
  return 0;  
}
