#ifndef skalaH
#define skalaH

class SKALA
 {

	public:
	
 double X(double t,int szer,int szer_panelu,double tp,double tk)
  {
    return (t*(szer-szer_panelu)/(tk-tp))+szer_panelu;
  }

double Y(double funkcja, int wys_okna, int przesuniecie=0)
   {
    return (funkcja*(wys_okna/2)*0.08)+wys_okna/2+przesuniecie;
   }
 };
 # endif 