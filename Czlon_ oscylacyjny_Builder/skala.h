//---------------------------------------------------------------------------
#ifndef skalaH
#define skalaH
//---------------------------------------------------------------------------
// Oto treœæ pliku skala.h - nag³ówka modu³u o nazwie skala, mieszcz¹cego obiekt TSkalowanie.
//	Skalowanie obszaru ekranowego w matematyczny i odwrotnie
//	UWAGA: OBSZARY S¥ RÓZNIE ZDEFINIOWANE!
//	(xe0, ye0) - lewy górny róg obszaru ekranowego,
//	eszer, ewys - szerokoœæ i wysokoœæ obszaru ekranowego
//
//	(xr0, yr0) - œrodek obszaru rzeczywistego,
//	rszer, rwys - szerokoœæ i wysokoœæ obszaru rzeczywistego
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
 