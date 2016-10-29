//---------------------------------------------------------------------------

#ifndef PIDokienkoH
#define PIDokienkoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TEdit *Edit1;
        TLabel *Label1;
        TTrackBar *K1;
        TTrackBar *K2;
        TTrackBar *K3;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit4;
        TTrackBar *T;
        TLabel *Label5;
        TEdit *Edit5;
        TTrackBar *Tk;
        TTrackBar *DT;
        TEdit *Edit6;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Edit7;
        TTrackBar *U;
        TRadioGroup *RadioGroup1;
        TEdit *numer;
        void __fastcall K1Change(TObject *Sender);
        void __fastcall K2Change(TObject *Sender);
        void __fastcall K3Change(TObject *Sender);
        void __fastcall TChange(TObject *Sender);
        void __fastcall TkChange(TObject *Sender);
        void __fastcall DTChange(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall UChange(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall numerChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
