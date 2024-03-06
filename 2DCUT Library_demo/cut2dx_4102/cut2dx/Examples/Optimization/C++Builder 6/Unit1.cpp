//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "About.h"
#include "Register.h"

#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "optimal2dx_OCX"
#pragma resource "*.dfm"

TForm1 *Form1;
int iteration;  // number of iterations
int stationary; // number of stationary iterations - without improvement
bool _stop = true; //if the algorithm is stop or not
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
  fRegister->eComputerID->Text = Optimization2DX1->get_ComputerID();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::About1Click(TObject *Sender)
{
  AboutBox->lodx2d->Caption = Optimization2DX1->Version;
  if (AboutBox->ShowModal() == mrOk){
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Register1Click(TObject *Sender)
{
  if (fRegister->ShowModal() == mrOk){
    Optimization2DX1->RegisterOptimization2DX(WideString(fRegister->eName->Text), WideString(fRegister->eSerialNumber->Text));
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::bStartClick(TObject *Sender)
{
  bStart->Enabled = false;

  Optimization2DX1->set_NumberOfRepositoryPieces(1);
  Optimization2DX1->SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0);

  Optimization2DX1->set_NumberOfDemandPieces(14);
  Optimization2DX1->set_BladeWidth(0);
  Optimization2DX1->set_OptimizationLevel(50);
  Optimization2DX1->set_RandomSeed(0);
  Optimization2DX1->set_MaximalCutLength(300);

  Optimization2DX1->SetDemandPiece(0,  60,  40,  1, 0, 0);
  Optimization2DX1->SetDemandPiece(1,  60,  40,  1, 1, 0);
  Optimization2DX1->SetDemandPiece(2,  48,  40,  1, 2, 0);
  Optimization2DX1->SetDemandPiece(3,  60,  53,  1, 3, 0);
  Optimization2DX1->SetDemandPiece(4,  45,  45,  1, 4, 0);
  Optimization2DX1->SetDemandPiece(5,  50,  80,  1, 5, 0);
  Optimization2DX1->SetDemandPiece(6,  45,  75,  1, 6, 0);
  Optimization2DX1->SetDemandPiece(7,  100, 100, 1, 7, 0);
  Optimization2DX1->SetDemandPiece(8,  100, 100, 1, 8, 0);
  Optimization2DX1->SetDemandPiece(9,  90,  90,  1, 9, 0);
  Optimization2DX1->SetDemandPiece(10, 90,  90,  1, 10, 0);
  Optimization2DX1->SetDemandPiece(11, 90,  90,  1, 11, 0);
  Optimization2DX1->SetDemandPiece(12, 110, 110, 1, 12, 0);
  Optimization2DX1->SetDemandPiece(13, 110, 110, 1, 13, 0);

  lbWaste->Clear();
  sbIteration->SimpleText = "";

  iteration = 0;

  Optimization2DX1->StartGuillotine();

  bStart->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Optimization2DX1Finish(TObject *Sender)
{

  // if you want to obtain information about all sheets just iterate through all of them
  // sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
  // usually the first parameter of the methods is the sheet index

  long SheetIndex = 0; // this is the first sheet;

  long repository_Index;  // index of Repository piece
  long repository_ID;     // external ID of repository piece

  long demand_Index;  // index of Demand piece
  long demand_ID;     // external ID of demand piece

  double surf_covered; // surface covered

  Optimization2DX1->SurfaceCovered(SheetIndex, &surf_covered, &repository_Index, &repository_ID);
  eUtilizedSurface->Text = FloatToStr(surf_covered);
  Image1->Canvas->Rectangle(0, 0, 300, 200);

  long NumCuts;
  Optimization2DX1->NumberOfCuttings(SheetIndex, &NumCuts, &repository_Index, &repository_ID);

  for (int i = 0; i < NumCuts; i++){
    long top_x, top_y, bottom_x, bottom_y, thick;
    Optimization2DX1->GetCut(SheetIndex, i, &top_x, &top_y, &bottom_x, &bottom_y, &thick, &repository_Index, &repository_ID);
    Image1->Canvas->MoveTo(top_x, top_y);
    Image1->Canvas->LineTo(bottom_x, bottom_y);
  }

  // utilized rectagles
  long NumPieces;
  Optimization2DX1->NumberOfUtilizedDemandPieces(SheetIndex, &NumPieces, &repository_Index, &repository_ID);
  for (int i = 0; i < NumPieces; i++){
    long top_x, top_y, bottom_x, bottom_y, InputIndex, rotated;
    Optimization2DX1->GetUtilizedDemandPiece(SheetIndex, i, &top_x, &top_y, &bottom_x, &bottom_y, &rotated, &repository_Index, &demand_Index, &repository_ID, &demand_ID);
    int poz_x = (bottom_x+top_x)/2 - Image1->Canvas->TextWidth(FloatToStr(bottom_x-top_x)+"x"+FloatToStr(bottom_y-top_y))/2;
    int poz_y = (bottom_y+top_y)/2 - Image1->Canvas->TextHeight(FloatToStr(bottom_x-top_x)+"x"+FloatToStr(bottom_y-top_y))/2;;
    Image1->Canvas->TextOut(poz_x, poz_y, FloatToStr(fabs(bottom_x - top_x)) + "x" + FloatToStr(fabs(bottom_y - top_y)));
  }

  // waste rectangles
  long NumWastes;
  Optimization2DX1->NumberOfWastePieces(SheetIndex, &NumWastes, &repository_Index, &repository_ID);
  for (int i = 0; i < NumWastes; i++){
    long top_x, top_y, bottom_x, bottom_y;
    Optimization2DX1->GetWastePiece(SheetIndex, i, &top_x, &top_y, &bottom_x, &bottom_y, &repository_Index, &repository_ID);
    lbWaste->AddItem(FloatToStr(fabs(top_x - bottom_x)) + " x " + FloatToStr(fabs(bottom_y - top_y)), NULL);

    int poz_x = (bottom_x + top_x) / 2 - Image1->Canvas->TextWidth("w") / 2;
    int poz_y = (bottom_y + top_y) / 2 - Image1->Canvas->TextHeight("w") / 2;
    Image1->Canvas->TextOut(poz_x, poz_y, "w");
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Optimization2DX1Progress(TObject *Sender)
{
  iteration++;
  sbIteration->SimpleText = IntToStr(iteration);
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------

