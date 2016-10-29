//---------------------------------------------------------------------------
#ifndef skalaH
#define skalaH
//---------------------------------------------------------------------------
// Oto tre�� pliku skala.h - nag��wka modu�u o nazwie skala, mieszcz�cego obiekt TSkalowanie.
//	Skalowanie obszaru ekranowego w matematyczny i odwrotnie
//	UWAGA: OBSZARY S� R�ZNIE ZDEFINIOWANE!
//	(xe0, ye0) - lewy g�rny r�g obszaru ekranowego,
//	eszer, ewys - szeroko�� i wysoko�� obszaru ekranowego
//
//	(xr0, yr0) - �rodek obszaru rzeczywistego,
//	rszer, rwys - szeroko�� i wysoko�� obszaru rzeczywistego
class TSkalowanie
{
 private:
   double A, B, C, D;			//skaling z real na ekr
   double E, F, G, H;			//skaling odwrotny

 public:
   TSkalowanie( int xe0, int ye0, int eszer, int ewys, double xr0, double yr0, double rszer, double rwys);
   double daj_real_x( int xe);
   double daj_real_y( int ye);
   int daj_ekr_x( double xr);
   int daj_ekr_y( double yr);
};

#endif
 