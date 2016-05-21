//---------------------------------------------------------------------------
//to-do:
//timer zamiast sleepa - done
//kolorek na EditBox Posiadasz - done
//naprawa wynikow
//Bevel zamiast shape
//funkcja SetFocus() - done
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSimpleCasino *SimpleCasino;
//---------------------------------------------------------------------------
__fastcall TSimpleCasino::TSimpleCasino(TComponent* Owner)
        : TForm(Owner)
{
//Podstawowa inicjalizacja pol zadeklarowanych
        Licznik = 0;
        backup = "";
        nickName = "";
        Rezultat= "";
        Czat->Caption = "Witaj w SimpleCasino!\nZaczynasz z kwota 50zl, wykorzystaj ja madrze!";
}
//---------------------------------------------------------------------------

void __fastcall TSimpleCasino::WyjscieClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TSimpleCasino::HighButtonClick(TObject *Sender)
{
   try{
         double posiadasz = StrToFloat(Posiadasz->Text);
         double obstawiasz = StrToFloat(Obstawiasz->Text);

         if(obstawiasz > posiadasz){
                Czat->Caption = "Przykro mi, nie masz wystarczajacych srodkow na koncie :-(";
         }
         else if(obstawiasz<5){
                Czat->Caption = "Musisz obstawic minimum 5zl!";
         }
         else{
                randomize();
                double kasa = StrToFloat(Posiadasz->Text);

                int losowa = random(6)+1;

                Sleep(500);
                Czat->Caption  = "Wylosowano: " + FloatToStr(losowa);

                if(losowa>3){
                        double wygrana = StrToFloat(Obstawiasz->Text) * 0.8;
                        kasa = kasa + wygrana;
                        Posiadasz->Text = FloatToStr(kasa);
                        Sleep(500);
                        Czat->Caption = Czat->Caption + "\n" + "Gratulacje, wygrales:" + wygrana + "zl!";
                        Posiadasz->Color = clLime;
                        Timer1->Enabled = true;
                }
                else{
                        double przegrana = StrToFloat(Obstawiasz->Text);
                        double kasaNew = kasa - przegrana;
                        Posiadasz->Text = FloatToStr(kasaNew);
                        Sleep(500);
                        Czat->Caption = Czat->Caption + "\n" + "Przykro mi, przegrales...";
                        Posiadasz->Color = clRed;
                        Timer1->Enabled = true;
                }
         }

         if(StrToFloat(Posiadasz->Text) <5){
                Sleep(1500);
                Czat->Caption = "BRAK SRODKOW, KONIEC GRY!";
                Obstawiasz->Text = "";
         }
   }
   catch(...){
        Czat->Caption = "NIEODPOWIEDNIA LICZBA, PA£O!";
   }
         Obstawiasz->SetFocus();
}

//---------------------------------------------------------------------------
void __fastcall TSimpleCasino::LowButtonClick(TObject *Sender)
{
   try{
         double posiadasz = StrToFloat(Posiadasz->Text);
         double obstawiasz = StrToFloat(Obstawiasz->Text);

         if(obstawiasz > posiadasz){
                Czat->Caption = "Przykro mi, nie masz wystarczajacych srodkow na koncie :-(";
         }
         else if(obstawiasz<5){
                Czat->Caption = "Musisz obstawic minimum 5zl!";
         }
         else{
                randomize();
                double kasa = StrToFloat(Posiadasz->Text);

                int losowa = random(6)+1;

                Sleep(500);
                Czat->Caption  = "Wylosowano: " + FloatToStr(losowa);

                if(losowa<=3){
                        double wygrana = StrToFloat(Obstawiasz->Text) * 0.8;
                        kasa = kasa + wygrana;
                        Posiadasz->Text = FloatToStr(kasa);
                        Sleep(500);
                        Czat->Caption = Czat->Caption + "\n" + "Gratulacje, wygrales:" + wygrana + "zl!";
                        Posiadasz->Color = clLime;
                        Timer1->Enabled = true;
                }
                else{
                        double przegrana = StrToFloat(Obstawiasz->Text);
                        double kasaNew = kasa - przegrana;
                        Posiadasz->Text = FloatToStr(kasaNew);
                        Sleep(500);
                        Czat->Caption = Czat->Caption + "\n" + "Przykro mi, przegrales...";
                        Posiadasz->Color = clRed;
                        Timer1->Enabled = true;
                }
         }
         if(StrToFloat(Posiadasz->Text) <5){
                Sleep(1500);
                Czat->Caption = "BRAK SRODKOW, KONIEC GRY!";
                Obstawiasz->Text = "";
         }
   }
   catch(...){
        Czat->Caption = "NIEODPOWIEDNIA LICZBA, PA£O!";
   }
   Obstawiasz->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSimpleCasino::BlackJackButtonClick(TObject *Sender)
{
   try{
         double posiadasz = StrToFloat(Posiadasz->Text);
         double obstawiasz = StrToFloat(Obstawiasz->Text);

         if(obstawiasz > posiadasz){
                Czat->Caption = "Przykro mi, nie masz wystarczajacych srodkow na koncie :-(";
         }
         else if(obstawiasz<5){
                Czat->Caption = "Musisz obstawic minimum 5zl!";
         }
         else{
                randomize();
                double kasa = StrToFloat(Posiadasz->Text);

                int losowa1[6];
                int losowa2[6];

                int suma1 = 0;
                int suma2 = 0;

                for(int i=0;i<6;i++){
                        losowa1[i] = random(6)+1;
                        losowa2[i] = random(6)+1;
                }

                Czat->Caption  = "TWOJE CYFRY:\n";

                for(int i=0;i<6;i++){
                        Czat->Caption  = Czat->Caption + "Wylosowano: " + FloatToStr(losowa1[i]) + "\n";
                        suma1 = suma1 + losowa1[i];
                        Sleep(300);
                }

                Czat->Caption  = Czat->Caption + "\nMOJE CYFRY:\n";

                for(int i=0;i<6;i++){
                        Czat->Caption  = Czat->Caption + "Wylosowano: " + FloatToStr(losowa2[i]) + "\n";
                        suma2 = suma2 + losowa2[i];
                        Sleep(300);
                }


//---------------------------Porownanie wynikow------------------------
                if(suma1>21){
                        if(suma2>21){
                                Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                                Sleep(500);
                                Czat->Caption = Czat->Caption + "\nWyglada na to, ze oboje wyrzucilismy za duzo...\n";
                                Czat->Caption = Czat->Caption + "Remis, oddajê Ci pieniadze";
                                Posiadasz->Color = clBlue;
                                Timer1->Enabled = true;
                        }
                        else{
                                Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                                Sleep(500);
                                double przegrana = StrToFloat(Obstawiasz->Text);
                                double kasaNew = kasa - przegrana;
                                Czat->Caption = Czat->Caption + "Wyrzuciles zdecydowanie za duzo oczek, przegrales ;(";
                                Posiadasz->Text = FloatToStr(kasaNew);
                                Posiadasz->Color = clRed;
                                Timer1->Enabled = true;

                        }
                }
                else if(suma2>21){
                        if(suma1>21){
                                Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                                Sleep(500);
                                Czat->Caption = Czat->Caption + "\nWyglada na to, ze oboje wyrzucilismy za duzo...\n";
                                Czat->Caption = Czat->Caption + "Remis, oddajê Ci pieniadze";
                                Posiadasz->Color = clBlue;
                                Timer1->Enabled = true;
                        }
                        else{
                                Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                                Sleep(500);
                                double wygrana = StrToFloat(Obstawiasz->Text) * 0.8;
                                kasa = kasa + wygrana;
                                Posiadasz->Text = FloatToStr(kasa);
                                Czat->Caption = Czat->Caption + "Wyrzucilem zdecydowanie za duzo oczek, wygrales " + wygrana + "zl! ;)";
                                Posiadasz->Color = clLime;
                                Timer1->Enabled = true;
                        }
                }



               else if(suma1>suma2){
                        double wygrana = StrToFloat(Obstawiasz->Text) * 0.8;
                        kasa = kasa + wygrana;
                        Posiadasz->Text = FloatToStr(kasa);
                        Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                        Sleep(500);
                        Czat->Caption = Czat->Caption + "\n" + "Gratulacje, wygrales:" + wygrana + "zl!";
                        Posiadasz->Color = clLime;
                        Timer1->Enabled = true;
                }
                else if(suma1<suma2){
                        double przegrana = StrToFloat(Obstawiasz->Text);
                        double kasaNew = kasa - przegrana;
                        Posiadasz->Text = FloatToStr(kasaNew);
                        Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                        Sleep(500);
                        Czat->Caption = Czat->Caption + "\n" + "Przykro mi, przegrales...";
                        Posiadasz->Color = clRed;
                        Timer1->Enabled = true;
                }
                else{
                       Czat->Caption = Czat->Caption + suma1 + " vs " + suma2 + "\n";
                       Sleep(500);
                       Czat->Caption = Czat->Caption + "Remis, oddajê Ci pieniadze";
                       Posiadasz->Color = clBlue;
                       Timer1->Enabled = true;
                }

         }

         if(StrToFloat(Posiadasz->Text) <5){
                Sleep(1500);
                Czat->Caption = "BRAK SRODKOW, KONIEC GRY!";
                Obstawiasz->Text = "";
         }
   }
   catch(...){
        Czat->Caption = "NIEODPOWIEDNIA LICZBA, PA£O!";
   }
          Obstawiasz->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSimpleCasino::HelpButtonClick(TObject *Sender)
{
        Licznik++;

        if(Licznik%2==1){
                backup = Czat->Caption;
                Czat->Caption = "Witaj w SimpleCasino!\nZaczynasz z kwota 50zl, wykorzystaj ja madrze!\n\nMozesz zagrac High/Low lub uproszczonego BlackJacka.";
                Czat->Caption = Czat->Caption + "\n\nZASADY OGOLNE\n";
                Czat->Caption = Czat->Caption + "- Mozesz obstawiac minimum 5zl\n- Payrate wynosi 80% zainwestowanej kwoty w obu grach!";
                Czat->Caption = Czat->Caption + "\n\nBLACKJACK\n";
                Czat->Caption = Czat->Caption + "- Rzucam koscia 6 razy dla kazdego z nas, kto zbierze wiecej oczek wygrywa\n- Jesli suma oczek przekroczy 21 - przegrywasz";
                Czat->Caption = Czat->Caption + "\n\nHigh/Low\n";
                Czat->Caption = Czat->Caption + "- Obstawiasz czy wyrzucona wartosc na kostce bedzie >3 lub =<3. \n\nSIMPLE.\n\nWszystkie prawa zastrzezone. by Voodek";
        }
        else{
                Czat->Caption = backup;
        }
        Obstawiasz->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSimpleCasino::ResetButtonClick(TObject *Sender)
{
     Czat->Caption = "Sprobuj swojego szczescia juz dzis!\n";
     Posiadasz->Text = "50";
     Obstawiasz->Text = "";
     Posiadasz->Color = clYellow;
     Obstawiasz->Color = clYellow;
     Timer1->Enabled = true;
     Obstawiasz->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TSimpleCasino::ChickenButtonClick(TObject *Sender)
{
        SaveState->Show();
}
//---------------------------------------------------------------------------


void __fastcall TSimpleCasino::Timer1Timer(TObject *Sender)
{
Posiadasz->Color = clMenu;
Obstawiasz->Color = clWindow;
Timer1->Enabled = false;
/*
if(zielony == true){

        if(flag==true)
        {
                Posiadasz->Color = clMenu;
                Timer1->Enabled = false;
                flag = false;
                //flag = !flag;
        }
        else
        {
                Posiadasz->Color = clLime;
                flag = !flag;
        }
}
else{

        if(flag==true)
        {
                Posiadasz->Color = clMenu;
                Timer1->Enabled = false;
                //flag = !flag;
                flag = false;
        }
        else
        {
                Posiadasz->Color = clRed;
                flag = !flag;
        }

}
*/
}
//---------------------------------------------------------------------------


void __fastcall TSimpleCasino::Wyjscie1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

