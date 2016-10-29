//---------------------------------------------------------------------------
#include "skala.h"

//   Oto tre�� pliku skala.cpp - implementacji algorytm�w obiektu TSkalowanie.
//----------------------------------------------------
//	Konstruktor.
//	(xe0, ye0) - lewy g�rny r�g obszaru ekranowego,
//	eszer, ewys - szeroko�� i wysoko�� obszaru ekranowego
//	(xr0, yr0) - �rodek obszaru rzeczywistego,
//	rszer, rwys - szeroko�� i wysoko�� obszaru rzeczywistego
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
//	Wyliczenie wsp�rz�dnej ekranowej xe punktu,
//	gdy znana jest jego wsp�rz�dna rzeczywista x.
int TSkalowanie::daj_ekr_x( double x)
{
 return (int)(A * x + B);
}
//----------------------------------------------------
//	Wyliczenie wsp�rz�dnej ekranowej ye punktu,
//	gdy znana jest jego wsp�rz�dna rzeczywista y.
int TSkalowanie::daj_ekr_y( double y)
{
 return (int)(C * y + D);
}
//----------------------------------------------------
//	Wyliczenie wsp�rz�dnej rzeczywistej x punktu,
//	gdy znana jest jego wsp�rz�dna ekranowa xe.
double TSkalowanie::daj_real_x( int xe)
{
 return E * xe + F;
}
//----------------------------------------------------
//	Wyliczenie wsp�rz�dnej rzeczywistej y punktu,
//	gdy znana jest jego wsp�rz�dna ekranowa ye.
double TSkalowanie::daj_real_y( int ye)
{
 return G * ye + H;
}
//---------------------------------------------------------------------------

