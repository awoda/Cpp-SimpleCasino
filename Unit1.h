//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "Unit2.h"
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TSimpleCasino : public TForm
{
__published:	// IDE-managed Components
        TButton *Wyjscie;
        TButton *HighButton;
        TButton *LowButton;
        TButton *BlackJackButton;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Posiadasz;
        TEdit *Obstawiasz;
        TStaticText *Czat;
        TLabel *Label4;
        TLabel *Label5;
        TButton *HelpButton;
        TButton *ResetButton;
        TButton *ChickenButton;
        TTimer *Timer1;
        TImage *Image1;
        void __fastcall WyjscieClick(TObject *Sender);
        void __fastcall HighButtonClick(TObject *Sender);
        void __fastcall HelpButtonClick(TObject *Sender);
        void __fastcall LowButtonClick(TObject *Sender);
        void __fastcall BlackJackButtonClick(TObject *Sender);
        void __fastcall ResetButtonClick(TObject *Sender);
        void __fastcall ChickenButtonClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Wyjscie1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSimpleCasino(TComponent* Owner);

        int Licznik; //zmienna do przechowywania ilosci klikniec w helpbutton
        String backup; //zmienna do przechowywania outputu dla helpa
        //Pola do zapisu wyniku
        String Rezultat;
        String nickName;

};
//---------------------------------------------------------------------------
extern PACKAGE TSimpleCasino *SimpleCasino;
//---------------------------------------------------------------------------
#endif
