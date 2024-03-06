//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Register.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfRegister *fRegister;
//---------------------------------------------------------------------------
__fastcall TfRegister::TfRegister(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
