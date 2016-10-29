//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PIDokienko.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include<math.h>
#include"SKALA.h"

using namespace std;

//---------------------------skala---------------------

TForm1 *Form1;
int wybor=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

/*------------------ wymuszenie---------------*/

double u(double t, int wybor)
  {
   switch (wybor)
   {
   case 0: return sin(t); break;
   case 1: return t;  break;
   case 2: return 1; break;
   }
  }

 //-------------------Pochodna 1-----------------------------

double pochodna1(double t, double dt,int wybor)
  {
   double x[3],y1;
   x[0]=u(t-dt,wybor);
   x[1]=u(t,wybor);
   x[2]=u(t+dt,wybor);
   y1=(x[2]-x[0])/(2*dt);
   return y1;
  }
 //-------------------Pochodna 2-----------------------------

 double pochodna2(double t, double dt, int wybor)
  {
   double x[3],y2;
   x[0]=pochodna1(t-dt,dt,wybor);
   x[1]=pochodna1(t,dt,wybor);
   x[2]=pochodna1(t+dt,dt,wybor);
   y2=(x[2]-x[0])/(2*dt);
   return y2;
   }
//---------------------------------------------------------------------------

void __fastcall TForm1::K1Change(TObject *Sender) //wzmocnienie K1
{
        Edit1->Text = K1->Position;
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::K2Change(TObject *Sender)  //wzmocnienie K2
{
        Edit2->Text=K2->Position;
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::K3Change(TObject *Sender)   //wzmocnienie K3
{
       Edit3->Text=K3->Position;
       Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TChange(TObject *Sender)  // czas poczatkowy t
{
        Edit4->Text=T->Position;
       Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TkChange(TObject *Sender) // czas koncowy tk
{
        Edit5->Text=Tk->Position;
       Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DTChange(TObject *Sender) // czas probkowania dt
{
  Edit6->Text=1.0/(DT->Position);
  Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{

  SKALA cl;
  double t,tk,dt,calka,dy1,dy2,k1,k2,k3,wymuszenie,A=U->Position;

  double tp=T->Position;
  tk=Tk->Position;
  dt=1.0/(DT->Position);

  Canvas->MoveTo(0,ClientHeight/2);
  Canvas->Pen->Color=clRed;

  for(t=tp;t<tk;t+=dt)   //wymuszenie u(t)
   {
    wymuszenie=A*u(t,wybor);
    Canvas->LineTo(cl.X(t-tp,ClientWidth,Panel1->Width,tp,tk),cl.Y(-wymuszenie,ClientHeight,ClientHeight/6));

    //PID<< t << "   " << u(t)<< "   " << pochodna1(t,dt) << "   " << pochodna2(t,dt) << "   " << calka <<  endl;

    }
   k1=K1->Position;
   k2=K2->Position;
   k3=K3->Position;


 // ofstream PID;
 // PID.open("D:\\Inne\\wynikiPID2.txt");

 Canvas->MoveTo(0,ClientHeight/2);
 Canvas->Pen->Color=clGreen;

   calka=0;

  for(t=tp;t<tk;t+=dt)   // PID
   {
    dy1=k1*A*pochodna1(t,dt,wybor)+k2*A*pochodna2(t,dt,wybor)+A*u(t,wybor)*k3;
    dy2=k1*A*pochodna1(t+dt,dt,wybor)+k2*A*pochodna2(t+dt,dt,wybor)+A*u(t+dt,wybor)*k3;
    calka+=((dy1+dy2)/2)*dt;
    Canvas->LineTo(cl.X(t-tp,ClientWidth,Panel1->Width,tp,tk),cl.Y(-calka,ClientHeight,-ClientHeight/6));
    //Canvas->MoveTo(10*(t-(T->Position))+160,10*-calka+ClientHeight/2);
    //PID<< t << "   " << u(t)<< "   " << pochodna1(t,dt) << "   " << pochodna2(t,dt) << "   " << calka <<  endl;
     }


 // PID.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
        Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UChange(TObject *Sender)
{
  Edit7->Text=U->Position;
  Refresh();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
 wybor= RadioGroup1->ItemIndex;
 numer->Text = RadioGroup1->ItemIndex;
 Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
 K1Change( Sender);
 K2Change( Sender);
 K3Change( Sender);
 TChange( Sender);
 TkChange( Sender);
 DTChange( Sender);
 UChange( Sender);
 RadioGroup1Click( Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::numerChange(TObject *Sender)
{
        Refresh();
}
//---------------------------------------------------------------------------




