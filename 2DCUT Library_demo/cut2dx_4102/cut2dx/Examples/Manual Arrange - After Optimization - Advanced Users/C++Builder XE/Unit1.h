//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleServer.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include "optimal2dx_OCX.h"

#include "utils.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *eUtilizedSurface;
        TLabel *Label1;
        TImage *Image1;
        TListBox *lbWaste;
        TLabel *Label7;
        TStatusBar *sbIteration;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Exit1;
        TMenuItem *Register1;
        TButton *bStart;
        TOptimization2DX *Optimization2DX1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Register1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall bStartClick(TObject *Sender);
        void __fastcall Optimization2DX1Finish(TObject *Sender);
        void __fastcall Optimization2DX1Progress(TObject *Sender);
	void __fastcall Optimization2DX1AfterManualArrange(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private:	// User declarations

  int iteration;
  int moving_piece; // -1 if no piece is moving; index of the moving piece otherwise
  int LastX, LastY;
  int MouseX, MouseY;
  SheetInfo sheet;

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
