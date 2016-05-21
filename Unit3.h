//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TWyniki : public TForm
{
__published:	// IDE-managed Components
        TLabel *Top10;
        TButton *Wyjscie;
        TLabel *nr01;
        TLabel *nr02;
        TLabel *nr03;
        TLabel *nr04;
        TLabel *nr05;
        TLabel *nr06;
        TLabel *nr07;
        TLabel *nr08;
        TLabel *nr09;
        TLabel *nr10;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TMemo *Memo1;
        TImage *Image1;
        void __fastcall WyjscieClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TWyniki(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWyniki *Wyniki;
//---------------------------------------------------------------------------
#endif
