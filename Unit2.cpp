//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"

//moje do pliku
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSaveState *SaveState;
//---------------------------------------------------------------------------
__fastcall TSaveState::TSaveState(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSaveState::Button2Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TSaveState::Button1Click(TObject *Sender)
{
    Close();
    NickEdit->Show();
    PlaySound("TomJerry", HInstance, SND_ASYNC | SND_RESOURCE);

}
