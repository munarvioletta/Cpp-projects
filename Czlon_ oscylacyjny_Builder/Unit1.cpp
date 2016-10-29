/*program sluzy do kreslenie charakterystyk szeregowego polaczenia czlonu oscylacyjnego
i calkujacego*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "skala.h"
#include "skala.cpp"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//============================================================================
double licz(double KSI, double K, double T, double tp, double tk, double dt, double wymuszenie)

    {

      double y1,y2, y3,dy1[2], dy2[2], dy3[2];

      y1=0.0;                       //zerowanie zmiennych
      y2=0.0;
      y3=0.0;
      dy3[0]=0;
      dy2[0]=0;
      dy1[0]=0;
      dy3[1]=0;
      dy2[1]=0;
      dy1[1]=0;




        while(tp<tk)                    //petla while wykonywana dopoki tp < tk
          {
              tp=tp+dt;         //inkrementacja kroku o wartosc dt
              dy1[1]=y2;
              dy2[1]=y3;
              dy3[1]=(-2*KSI/T)*y3-(1/(T*T))*y2+(K/(T*T))*wymuszenie;
              y1+=(dy1[0]+dy1[1])/2*dt;          // obliczenie pola pod krzyw¹ miedzy pochodn¹ y1 dla
                                                       // pocz¹tku przedzia³u i dla koñca

                  y2+=(dy2[0]+dy2[1])/2*dt;       // obliczenie pola pod krzyw¹ miedzy pochodn¹ y2 dla
                  y3+=(dy3[0]+dy3[1])/2*dt;
                                                         // pocz¹tku przedzia³u i dla koñca
                  dy1[0]=dy1[1];        //zmiana pocz¹tku obszaru dla którego
                  dy2[0]=dy2[1];          // nastêpna pêtla bêdzie liczyæ pole
                  dy3[0]=dy3[1];

          }
    return y1;
    }
    double licz2(double KSI, double K, double T, double tp, double tk, double dt, double wymuszenie)

    {

      double y1,y2, y3,dy1[2], dy2[2], dy3[2];

      y1=0.0;                       //zerowanie zmiennych
      y2=0.0;
      y3=0.0;
      dy3[0]=0;
      dy2[0]=0;
      dy1[0]=0;
      dy3[1]=0;
      dy2[1]=0;
      dy1[1]=0;




        while(tp<tk)                    //petla while wykonywana dopoki tp < tk
          {
              tp=tp+dt;         //inkrementacja kroku o wartosc dt
              dy1[1]=y2;
              dy2[1]=y3;
              dy3[1]=(-2*KSI/T)*y3-(1/(T*T))*y2+(K/(T*T))*wymuszenie;
              y1+=(dy1[0]+dy1[1])/2*dt;          // obliczenie pola pod krzyw¹ miedzy pochodn¹ y1 dla
                                                       // pocz¹tku przedzia³u i dla koñca

                  y2+=(dy2[0]+dy2[1])/2*dt;       // obliczenie pola pod krzyw¹ miedzy pochodn¹ y2 dla
                  y3+=(dy3[0]+dy3[1])/2*dt;
                                                         // pocz¹tku przedzia³u i dla koñca
                  dy1[0]=dy1[1];        //zmiana pocz¹tku obszaru dla którego
                  dy2[0]=dy2[1];          // nastêpna pêtla bêdzie liczyæ pole
                  dy3[0]=dy3[1];

          }
    return y2;
    }

//============================================================================

void __fastcall TForm1::TrackBar1Change(TObject *Sender)//Wspó³czynnik ksi
{
KSI = (double)TrackBar1->Position/10;
Edit1->Text=(double)TrackBar1->Position/10;
Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)//Wspó³czynnik T
{
T = (double)TrackBar2->Position/5;
Edit2->Text=(double)TrackBar2->Position/5;
Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar3Change(TObject *Sender)  //Wspó³czynnik K
{
K = (double)TrackBar3->Position/2;
Edit3->Text=(double)TrackBar3->Position/2;
Refresh();       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar4Change(TObject *Sender) //Wzmocnienie wymuszenia
{
 A = (double)TrackBar4->Position;
 Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
 TrackBar1Change( Sender);              //zainicjuj parametry fal
 TrackBar2Change( Sender);
 TrackBar3Change( Sender);
 TrackBar4Change( Sender);
 TrackBar5Change( Sender);
 TrackBar6Change( Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
 int xe_old, ye1_old, ye2_old;
 int xe, ye1, ye2;       //wspó³rzêdne ekranowe
 double x, y1, y2;          //wspó³rzêdne rzeczywiste
 bool pierwszy = true;
 double omega;
 omega = 2*3.14*C;
 int a = ClientHeight / 4;              //pomocnicze
 TSkalowanie s1( Panel1 -> Width, a, ClientWidth - Panel1 -> Width, a, 0, -8, 20, 10);
 TSkalowanie s2( Panel1 -> Width, 2.7*a, ClientWidth - Panel1 -> Width, a, 0, 8, 20, 500);

 Canvas -> Pen -> Width = 2;
  for( x = -10; x < 10; x += 0.1)
 {
    xe = s1.daj_ekr_x( x);

    if(R==0)y1 = A* sin(omega * x + F);        //pierwszy przebieg
    if(R==1)y1 = A*1;
    ye1 = s1.daj_ekr_y( y1);

    if(R==0)y2 = licz2(KSI, K*A, T, -10, x, 0.1, y1);         //do harmonicznej
    if(R==1)y2 = licz(KSI, K*A, T, -10, x, 0.1, y1);          //do skokowej
    ye2 = s2.daj_ekr_y( y2);

    if( pierwszy)                       //pocz¹tek kreœlenia?
    {
        xe_old = xe;
        ye1_old = ye1;
        ye2_old = ye2;

        pierwszy = false;
    }

    Canvas -> Pen -> Color = clGreen;
    Canvas -> MoveTo( xe_old, ye1_old);
    Canvas -> LineTo( xe, ye1);

    Canvas -> Pen -> Color = clBlue;
    Canvas -> MoveTo( xe_old, ye2_old);
    Canvas -> LineTo( xe, ye2);


    xe_old  = xe;                       //koñce odcinków staj¹ siê pocz¹tkami nastêpnych
    ye1_old = ye1;
    ye2_old = ye2;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar5Change(TObject *Sender)//Przesuniêcie fazowe wymuszenia
{
 F = (double)TrackBar5->Position;
 Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar6Change(TObject *Sender)//Czestotliwosc Wymuszenia
{
 C = (double)TrackBar6->Position * 100;
 Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
 R = RadioGroup1->ItemIndex;
 Refresh();
}
//---------------------------------------------------------------------------


