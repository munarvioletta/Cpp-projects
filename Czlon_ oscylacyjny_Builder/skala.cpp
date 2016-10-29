//---------------------------------------------------------------------------
#include "skala.h"

//   Oto treœæ pliku skala.cpp - implementacji algorytmów obiektu TSkalowanie.
//----------------------------------------------------
//	Konstruktor.
//	(xe0, ye0) - lewy górny róg obszaru ekranowego,
//	eszer, ewys - szerokoœæ i wysokoœæ obszaru ekranowego
//	(xr0, yr0) - œrodek obszaru rzeczywistego,
//	rszer, rwys - szerokoœæ i wysokoœæ obszaru rzeczywistego
TSkalowanie::TSkalowanie( int xe0, int ye0, int eszer, int ewys, double xr0, double yr0, double rszer, double rwys)
{
 A = (double) eszer / rszer;	//z przestrzeni na ekran
 B = (double) xe0 - A * (xr0 - rszer / 2.);
 C = -(double)ewys  / rwys;
 D = (double) ye0 - C * (yr0 + rwys / 2.);

 E = rszer / (double)eszer;		//z ekranu do przestrzeni
 F = xr0 - rszer / 2. - E * (double)xe0;
 G = -rwys / (double)ewys;
 H = yr0 + rwys  / 2. - G * (double)ye0;
}
//----------------------------------------------------
//	Wyliczenie wspó³rzêdnej ekranowej xe punktu,
//	gdy znana jest jego wspó³rzêdna rzeczywista x.
int TSkalowanie::daj_ekr_x( double x)
{
 return (int)(A * x + B);
}
//----------------------------------------------------
//	Wyliczenie wspó³rzêdnej ekranowej ye punktu,
//	gdy znana jest jego wspó³rzêdna rzeczywista y.
int TSkalowanie::daj_ekr_y( double y)
{
 return (int)(C * y + D);
}
//----------------------------------------------------
//	Wyliczenie wspó³rzêdnej rzeczywistej x punktu,
//	gdy znana jest jego wspó³rzêdna ekranowa xe.
double TSkalowanie::daj_real_x( int xe)
{
 return E * xe + F;
}
//----------------------------------------------------
//	Wyliczenie wspó³rzêdnej rzeczywistej y punktu,
//	gdy znana jest jego wspó³rzêdna ekranowa ye.
double TSkalowanie::daj_real_y( int ye)
{
 return G * ye + H;
}
//---------------------------------------------------------------------------

