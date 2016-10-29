#include <iostream>

using namespace std;
int x=22, y=6;
void zapelnianie(int**);
void wyswietlanie(int**);
int main()
{
    cout << "Program realizujacy dynamiczne alokowanie tablicy -> funkcja -> wskazniki" << endl;
    int** Owoce;
    Owoce = new int*[x];
    for(int i=0;i<x;i++)
        {
            Owoce[i] = new int[y];
        }
    zapelnianie(Owoce);
    cout << "Elementy tablicy to: \n";
    wyswietlanie(Owoce);

     for(int i=0;i<x;i++)
        {
            delete[] Owoce[i];
        }
    delete[] Owoce;
    return 0;
}

void zapelnianie(int** Owoce)
{
    for(int i=0; i<x; i++)
    {
        for(int j=0;j<y;j++)

            Owoce[i][j]=i*j;
    }
}

void wyswietlanie(int** Owoce)
{
     for(int i=0; i<x; i++)
    {
        for(int j=0;j<y;j++)
        {
            cout << Owoce[i][j] << "\t";

        }


            cout << "\n";

    }
}
