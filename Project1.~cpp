//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", SimpleCasino);
USEFORM("Unit2.cpp", SaveState);
USEFORM("Unit3.cpp", Wyniki);
USEFORM("Unit4.cpp", NickEdit);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Simple Casino";
                 Application->CreateForm(__classid(TSimpleCasino), &SimpleCasino);
                 Application->CreateForm(__classid(TSaveState), &SaveState);
                 Application->CreateForm(__classid(TWyniki), &Wyniki);
                 Application->CreateForm(__classid(TNickEdit), &NickEdit);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
