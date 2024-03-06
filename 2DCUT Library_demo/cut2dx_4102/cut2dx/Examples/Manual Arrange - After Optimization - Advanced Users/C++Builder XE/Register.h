//---------------------------------------------------------------------------

#ifndef RegisterH
#define RegisterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfRegister : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TBitBtn *bbRegister;
        TBitBtn *bbCancel;
        TPanel *Panel2;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *eName;
        TEdit *eComputerID;
        TEdit *eSerialNumber;
private:	// User declarations
public:		// User declarations
        __fastcall TfRegister(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfRegister *fRegister;
//---------------------------------------------------------------------------
#endif
