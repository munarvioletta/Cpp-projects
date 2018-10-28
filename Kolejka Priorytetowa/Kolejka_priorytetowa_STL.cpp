#include <queue>
#include <iostream>
using namespace std;

int main()
{
    std::priority_queue < int > kolejkaLiczb;
    int liczba;
      kolejkaLiczb.push( 123 );
      kolejkaLiczb.push( 12 );
      kolejkaLiczb.push( 55 );
      kolejkaLiczb.push( 200 );
      kolejkaLiczb.push( 5 );
    int n = 0;
    while (n!= 5){
     
     cout<<"Wybor: ";
     cin>>n;
     
     switch(n){
       case 0:
        std::cout << "Podaj liczbe: ";
        std::cin >> liczba;
        kolejkaLiczb.push( liczba );
        break;
        
      case 1:
        kolejkaLiczb.pop();
        std::cout << "Usunales element z kolejki "<<endl;
        break;
      case 2:
        std::cout << "Pierwsza liczba w kolejce priorytetowej to: " << kolejkaLiczb.top() << std::endl;
        break;
      case 3:
        std::cout << "ilosc elementow w kolejce: " << kolejkaLiczb.size()<< std::endl;
        break;
      case 4:
       if( kolejkaLiczb.empty() )
        {
        std::cout << "Kolejka jest pusta." << std::endl;
        } else
        {
        std::cout << "W kolejce znajduje sie przynajmniej jeden element." << std::endl;
        }
        break;
    
     }
    }
  //
    return 0;
}
