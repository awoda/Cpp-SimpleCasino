//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWyniki *Wyniki;
//---------------------------------------------------------------------------
__fastcall TWyniki::TWyniki(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWyniki::WyjscieClick(TObject *Sender)
{
        SimpleCasino->Enabled = true;
        Close();
}



