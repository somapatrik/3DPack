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
  moving_piece = -1;
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
    Optimization2DX1->RegisterOptimization2DX(fRegister->eName->Text.c_str(), fRegister->eSerialNumber->Text.c_str());
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

  Optimization2DX1->NumberOfRepositoryPieces = 1;
  Optimization2DX1->SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0); // DO NOT modify the size of the sheet. it has the same size as the picture

  Optimization2DX1->NumberOfDemandPieces = 7;

  Optimization2DX1->SetDemandPiece(0,  60,  40,  1, 0, 0);
  Optimization2DX1->SetDemandPiece(1,  60,  40,  1, 1, 0);
  Optimization2DX1->SetDemandPiece(2,  48,  40,  1, 2, 0);
  Optimization2DX1->SetDemandPiece(3,  60,  53,  1, 3, 0);
  Optimization2DX1->SetDemandPiece(4,  45,  45,  1, 4, 0);
  Optimization2DX1->SetDemandPiece(5,  50,  80,  1, 5, 0);
  Optimization2DX1->SetDemandPiece(6,  45,  75,  1, 6, 0);

  Optimization2DX1->BladeWidth = 0;
  Optimization2DX1->OptimizationLevel = 50;
  Optimization2DX1->RandomSeed = 0;
  Optimization2DX1->MaximalCutLength = 300;

  sbIteration->SimpleText = "";
  iteration = 0;

  Optimization2DX1->StartGuillotine();   // manual arrange works for guillotine only

  // PREPARE FOR MANUAL ARRANGE

  Optimization2DX1->ManualArrangeOptimizationType = 0;
  Optimization2DX1->ManualArrangeSetRepositoryPiece(300, 200, 0, 0, 0, 0, 0); // do not modify the size of the sheet. it has the same size as the picture. do scale if you need other sizes

  // set all other parameters here
  Optimization2DX1->BladeWidth = 0;
  // settings of all other parameters is required

  //send all cuts back to the component
  Optimization2DX1->ManualArrangeNumberOfCuts = sheet.NumCuts;
  for (int i = 0; i < sheet.NumCuts; i++)
	  Optimization2DX1->ManualArrangeSetCut(i, sheet.Cuts[i].TopX, sheet.Cuts[i].TopY, sheet.Cuts[i].BottomX, sheet.Cuts[i].BottomY, sheet.Cuts[i].Thickness);

  //send all piece positions back to the component
  Optimization2DX1->ManualArrangeNumberOfDemandPieces = sheet.NumPieces;
  for (int i = 0; i < sheet.NumPieces; i++)
	Optimization2DX1->ManualArrangeSetDemandPiece(i, sheet.Pieces[i].TopX, sheet.Pieces[i].TopY, sheet.Pieces[i].BottomX, sheet.Pieces[i].BottomY, sheet.Pieces[i].Rotated, sheet.Pieces[i].ExternalIndex);

  //send all waste positions back to the component
  Optimization2DX1->ManualArrangeNumberOfWastes = sheet.NumWastes;
  for (int i = 0; i < sheet.NumWastes; i++)
	Optimization2DX1->ManualArrangeSetWaste(i, sheet.Wastes[i].TopX, sheet.Wastes[i].TopY, sheet.Wastes[i].BottomX, sheet.Wastes[i].BottomY);

  // now you can move pieces with the mouse
  ShowMessage("Move an existing piece by drag and drop. You can drop a piece on waste large enough to accept that piece.");

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


  Optimization2DX1->NumberOfCuttings(SheetIndex, &sheet.NumCuts, &repository_Index, &repository_ID);
  sheet.Cuts = new Cut[sheet.NumCuts];

  for (int i = 0; i < sheet.NumCuts; i++){
    long top_x, top_y, bottom_x, bottom_y, thick;
    Optimization2DX1->GetCut(SheetIndex, i, &top_x, &top_y, &bottom_x, &bottom_y, &thick, &repository_Index, &repository_ID);
    Image1->Canvas->MoveTo(top_x, top_y);
	Image1->Canvas->LineTo(bottom_x, bottom_y);

	sheet.Cuts[i].TopX = top_x;
	sheet.Cuts[i].TopY = top_y;
	sheet.Cuts[i].BottomX = bottom_x;
	sheet.Cuts[i].BottomY = bottom_y;
	sheet.Cuts[i].Thickness = thick;
  }

  // utilized rectagles

  Optimization2DX1->NumberOfUtilizedDemandPieces(SheetIndex, &sheet.NumPieces, &repository_Index, &repository_ID);
  sheet.Pieces = new Piece[sheet.NumPieces];

  for (int i = 0; i < sheet.NumPieces; i++){
    long top_x, top_y, bottom_x, bottom_y, InputIndex, rotated;
    Optimization2DX1->GetUtilizedDemandPiece(SheetIndex, i, &top_x, &top_y, &bottom_x, &bottom_y, &rotated, &repository_Index, &demand_Index, &repository_ID, &demand_ID);
    int poz_x = (bottom_x+top_x)/2 - Image1->Canvas->TextWidth(FloatToStr(bottom_x-top_x)+"x"+FloatToStr(bottom_y-top_y))/2;
    int poz_y = (bottom_y+top_y)/2 - Image1->Canvas->TextHeight(FloatToStr(bottom_x-top_x)+"x"+FloatToStr(bottom_y-top_y))/2;;
	Image1->Canvas->TextOut(poz_x, poz_y, FloatToStr(fabs(bottom_x - top_x)) + "x" + FloatToStr(fabs(bottom_y - top_y)));

	sheet.Pieces[i].TopX = top_x;
	sheet.Pieces[i].TopY = top_y;
	sheet.Pieces[i].BottomX = bottom_x;
	sheet.Pieces[i].BottomY = bottom_y;
	sheet.Pieces[i].Rotated = rotated;
	sheet.Pieces[i].ExternalIndex = demand_ID;
  }

  // waste rectangles

  Optimization2DX1->NumberOfWastePieces(SheetIndex, &sheet.NumWastes, &repository_Index, &repository_ID);
  sheet.Wastes = new Waste[sheet.NumWastes];
  for (int i = 0; i < sheet.NumWastes; i++){
    long top_x, top_y, bottom_x, bottom_y;
    Optimization2DX1->GetWastePiece(SheetIndex, i, &top_x, &top_y, &bottom_x, &bottom_y, &repository_Index, &repository_ID);
    lbWaste->AddItem(FloatToStr(fabs(top_x - bottom_x)) + " x " + FloatToStr(fabs(bottom_y - top_y)), NULL);

    int poz_x = (bottom_x + top_x) / 2 - Image1->Canvas->TextWidth("w") / 2;
    int poz_y = (bottom_y + top_y) / 2 - Image1->Canvas->TextHeight("w") / 2;
	Image1->Canvas->TextOut(poz_x, poz_y, "w");

	sheet.Wastes[i].TopX = top_x;
	sheet.Wastes[i].TopY = top_y;
	sheet.Wastes[i].BottomX = bottom_x;
	sheet.Wastes[i].BottomY = bottom_y;
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

void __fastcall TForm1::Optimization2DX1AfterManualArrange(TObject *Sender)
{
  // if you want to obtain information about all sheets just iterate through all of them
  // sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
  // usually the first parameter of the methods is the sheet index

  long tx, ty, bx, by, thick, rotated;
  long poz_x, poz_y ;
  long rep_ID, rep_Index, dem_Index, dem_ID;
  double sf_cov;

  long SheetIndex = 0;

  sf_cov = Optimization2DX1->ManualArrangeSurfaceCovered;
  eUtilizedSurface->Text = FloatToStr(sf_cov);
  Image1->Canvas->Rectangle(0, 0, 300, 200);

  sheet.NumCuts = Optimization2DX1->ManualArrangeNumberOfCuts;
  if (sheet.Cuts)
	delete[] sheet.Cuts;
  sheet.Cuts = new Cut[sheet.NumCuts];

  for (int i = 0; i < sheet.NumCuts; i++)
  {
	Optimization2DX1->ManualArrangeGetCut(i, &tx, &ty, &bx, &by, &thick);
	Image1->Canvas->MoveTo(tx, ty);
	Image1->Canvas->LineTo(bx, by);
	// save the cuts again ... maybe some of them have been changed during manual arrange

	sheet.Cuts[i].TopX = tx;
	sheet.Cuts[i].TopY = ty;
	sheet.Cuts[i].BottomX = bx;
	sheet.Cuts[i].BottomY = by;
	sheet.Cuts[i].Thickness = thick;
  };

  // utilized rectagles
  sheet.NumPieces = Optimization2DX1->ManualArrangeNumberOfDemandPieces;
  if (sheet.Pieces)
	delete[] sheet.Pieces;
  sheet.Pieces = new Piece[sheet.NumPieces];
  for (int i = 0; i < sheet.NumPieces; i++)
  {
	Optimization2DX1->ManualArrangeGetDemandPiece(i, &tx, &ty, &bx, &by, &rotated, &dem_ID);
	poz_x = (bx+tx) / 2 - Image1->Canvas->TextWidth(FloatToStr(bx-tx)+"x"+FloatToStr(by-ty)) / 2;
	poz_y = (by+ty) / 2 - Image1->Canvas->TextHeight(FloatToStr(bx-tx)+"x"+FloatToStr(by-ty)) / 2;;
	Image1->Canvas->TextOut(poz_x, poz_y, FloatToStr(abs(bx - tx)) + "x" + FloatToStr(abs(by - ty)));
	//save the pieces again ... maybe some of them have been changed during manual arrange

	sheet.Pieces[i].TopX = tx;
	sheet.Pieces[i].TopY = ty;
	sheet.Pieces[i].BottomX = bx;
	sheet.Pieces[i].BottomY = by;
	sheet.Pieces[i].Rotated = rotated;
	sheet.Pieces[i].ExternalIndex = dem_ID;
  };

  // waste rectangles
  sheet.NumWastes = Optimization2DX1->ManualArrangeNumberOfWastes;
  if (sheet.Wastes)
    delete[] sheet.Wastes;
  sheet.Wastes = new Waste[sheet.NumWastes];

  for (int i = 0; i < sheet.NumWastes; i++)
  {
	Optimization2DX1->ManualArrangeGetWaste(i, &tx, &ty, &bx, &by);
	lbWaste->AddItem(FloatToStr(abs(tx - bx)) + " x " + FloatToStr(abs(by - ty)), NULL);

	poz_x = (bx + tx) / 2 - Image1->Canvas->TextWidth("w") / 2;
	poz_y = (by + ty) / 2 - Image1->Canvas->TextHeight("w") / 2;
	Image1->Canvas->TextOut(poz_x, poz_y, "w");
	// save the wastes again ... maybe some of them have been changed during manual arrange

	sheet.Wastes[i].TopX = tx;
	sheet.Wastes[i].TopY = ty;
	sheet.Wastes[i].BottomX = bx;
	sheet.Wastes[i].BottomY = by;
  };


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  int index = -1;
  // now I have to iterate through all pieces to see which one will be moved
  for (int i = 0; i < sheet.NumPieces; i++)
	  if ((sheet.Pieces[i].TopX < X) && (sheet.Pieces[i].TopY < Y) && (sheet.Pieces[i].BottomX > X) && (sheet.Pieces[i].BottomY > Y))
	  {
		  //i've found the piece to be moved
		  index = i;
		  break;
      }

  if (index != -1)
  {
	moving_piece = index; // index of the moving piece
	LastX = X; // where the mouse cursor was last time
	LastY = Y;
	MouseX = X; // where the mouse was down
	MouseY = Y;
    TRect rc;
	// draw the current moving rectangle with dots
	rc.Left = sheet.Pieces[moving_piece].TopX + LastX - MouseX;
	rc.Right = sheet.Pieces[moving_piece].BottomX - sheet.Pieces[moving_piece].TopX  + rc.Left;
	rc.Top = sheet.Pieces[moving_piece].TopY + LastY - MouseY;
	rc.Bottom = sheet.Pieces[moving_piece].BottomY - sheet.Pieces[moving_piece].TopY + rc.Top;

	Image1->Canvas->DrawFocusRect(rc);
  }
  else
	  moving_piece = -1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{

  if (moving_piece != -1)
  {// only if a piece is moving
    TRect rc;
	// delete the moving oject from the previous position
	rc.Left = sheet.Pieces[moving_piece].TopX + LastX - MouseX;
	rc.Right = sheet.Pieces[moving_piece].BottomX - sheet.Pieces[moving_piece].TopX  + rc.Left;
	rc.Top = sheet.Pieces[moving_piece].TopY + LastY - MouseY;
	rc.Bottom = sheet.Pieces[moving_piece].BottomY - sheet.Pieces[moving_piece].TopY + rc.Top;

	Image1->Canvas->DrawFocusRect(rc);


	// draw the moving rectangle in the new position
	rc.Left = sheet.Pieces[moving_piece].TopX + X - MouseX;
	rc.Right = sheet.Pieces[moving_piece].BottomX - sheet.Pieces[moving_piece].TopX  + rc.Left;
	rc.Top = sheet.Pieces[moving_piece].TopY + Y - MouseY;
	rc.Bottom = sheet.Pieces[moving_piece].BottomY - sheet.Pieces[moving_piece].TopY + rc.Top;

	Image1->Canvas->DrawFocusRect(rc);

	LastX = X;
	LastY = Y;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
  if (moving_piece != -1)
  {
    TRect rc;
	rc.Left = sheet.Pieces[moving_piece].TopX + LastX - MouseX;
	rc.Right = sheet.Pieces[moving_piece].BottomX - sheet.Pieces[moving_piece].TopX  + rc.Left;
	rc.Top = sheet.Pieces[moving_piece].TopY + LastY - MouseY;
	rc.Bottom = sheet.Pieces[moving_piece].BottomY - sheet.Pieces[moving_piece].TopY + rc.Top;

	Image1->Canvas->DrawFocusRect(rc);

	long Allowed;
	//now perform the actual manual arrange with the component
	//after this operation the OnManualArrange event is raised automatically
	Optimization2DX1->ManualArrangeGuillotineMovePiece(moving_piece,
													  X - MouseX + sheet.Pieces[moving_piece].TopX,
													  Y - MouseY + sheet.Pieces[moving_piece].TopY,
													  X - MouseX + sheet.Pieces[moving_piece].TopX + sheet.Pieces[moving_piece].BottomX - sheet.Pieces[moving_piece].TopX,
													  Y - MouseY + sheet.Pieces[moving_piece].TopY + sheet.Pieces[moving_piece].BottomY - sheet.Pieces[moving_piece].TopY,
													  sheet.Pieces[moving_piece].Rotated,
													  0,
													  &Allowed);
	if (Allowed = 1)
		;//            OK. MOVE ACCEPTED
	else
		// MOVE NOT ACCEPTED
	   ;
	moving_piece = -1; // the piece is not moving anymore
  };

}
//---------------------------------------------------------------------------

