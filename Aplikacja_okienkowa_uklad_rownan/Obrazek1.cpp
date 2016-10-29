//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Obrazek1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
   BorderStyle=bsDialog;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormPaint(TObject *Sender)
{
   Graphics::TBitmap *obrazek = new Graphics::TBitmap;

   obrazek->LoadFromFile("pomoc.bmp");
   Canvas->Draw(0, 0, obrazek);
   delete obrazek;
}
//---------------------------------------------------------------------------

