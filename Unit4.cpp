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
TNickEdit *NickEdit;
//---------------------------------------------------------------------------
__fastcall TNickEdit::TNickEdit(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TNickEdit::ZatwierdzButtonClick(TObject *Sender)
{
        SimpleCasino->nickName = Nick->Text; //zapisanie nicka
        SimpleCasino->Rezultat = SimpleCasino->Posiadasz->Text; //zapisanie wyniku

        //wyzerowanie wartosci dla nastepnej gry
        SimpleCasino->Posiadasz->Text = "50";
        SimpleCasino->Obstawiasz->Text ="0";
        SimpleCasino->Czat->Caption = "Zagraj jeszcze raz!\n";

        //------SPRAWDZENIE OTWARCIA PLIKU-------

        fstream plik;
        String pusty = "";
        plik.open("Save.dat", ios::in | ios::out );

        if( plik.good() == true )
        {
            plik.close();
            //Wczytanie pliku z danymi do ukrytego pola MEMO
            Wyniki->Memo1->Lines->LoadFromFile("Save.dat");

         //Dodanie nowego wyniku do Top10


        float zmienna = 0;
        for(int j = 1 ; j < 20 ; j=j+2){
         if(Wyniki->Memo1->Lines->Strings[j] == "")
         {
                zmienna = 0;
         }
         else
         {
                zmienna = StrToFloat(Wyniki->Memo1->Lines->Strings[j]);
         }


         if(StrToFloat(SimpleCasino->Rezultat) >= zmienna)
         {
                for(int k = 19 ; k >= j ; k=k-2){
                        Wyniki->Memo1->Lines->Strings[k-1] = Wyniki->Memo1->Lines->Strings[(k-1)-2];  //nick
                        Wyniki->Memo1->Lines->Strings[k] = Wyniki->Memo1->Lines->Strings[k-2];            //rezultat
                }
                Wyniki->Memo1->Lines->Strings[j-1]= SimpleCasino->nickName;
                Wyniki->Memo1->Lines->Strings[j]= SimpleCasino->Rezultat;

                //clean dla pewnosci
                //Wyniki->Memo1->Lines->Strings[18] = "";
                //Wyniki->Memo1->Lines->Strings[19] = "chuj";

                Wyniki->Memo1->Lines->SaveToFile("Save.dat");
                break;

         }
        }

        }
        else{  //Jesli plik nie istnieje to go stworz i dodaj gracza jako najlepszy wynik
            plik.close();

            Wyniki->Memo1->Lines->Strings[0] = SimpleCasino->nickName;
            Wyniki->Memo1->Lines->Strings[1] = SimpleCasino->Rezultat;
            for(int h = 2 ; h < 30 ; h++){
                 Wyniki->Memo1->Lines->Add("");
            }
            Wyniki->Memo1->Lines->SaveToFile("Save.dat");
            Wyniki->Memo1->Lines->LoadFromFile("Save.dat");

        }


    //Konwersja danych z pliku do tablicy ktora jest uzyta do wyswietlenia tabeli wynikow
    String linia[10];
    int licznik1 = 0;
    int licznik2 = 1;
    for(int i = 0 ; i < 10 ; i++){
        linia[i]= Wyniki->Memo1->Lines->Strings[licznik1] + " - " + Wyniki->Memo1->Lines->Strings[licznik2] + "PLN";

        licznik1 = licznik1 + 2;
        licznik2 = licznik2 + 2;
    }


    Wyniki->Label1->Caption = linia[0];
    Wyniki->Label2->Caption = linia[1];
    Wyniki->Label3->Caption = linia[2];
    Wyniki->Label4->Caption = linia[3];
    Wyniki->Label5->Caption = linia[4];
    Wyniki->Label6->Caption = linia[5];
    Wyniki->Label7->Caption = linia[6];
    Wyniki->Label8->Caption = linia[7];
    Wyniki->Label9->Caption = linia[8];
    Wyniki->Label10->Caption = linia[9];

        Wyniki->Show();
        SimpleCasino->Enabled = false;
        Close();
}
