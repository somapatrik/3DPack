unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, OleServer, ComCtrls,
  Menus, RegisterUnit, About, optimal2dx_TLB;

type
  TForm1 = class(TForm)
    bStart: TButton;
    eSurfaceCovered: TEdit;
    Label1: TLabel;
    Image1: TImage;
    lbUsedPieces: TListBox;
    lbUnusedPieces: TListBox;
    Label6: TLabel;
    Label5: TLabel;
    lbWaste: TListBox;
    Label7: TLabel;
    sbIteration: TStatusBar;
    MainMenu1: TMainMenu;
    File1: TMenuItem;
    Exiy1: TMenuItem;
    Help1: TMenuItem;
    Register1: TMenuItem;
    About1: TMenuItem;
    Optimization2DX1: TOptimization2DX;
    procedure bStartClick(Sender: TObject);
    procedure Exiy1Click(Sender: TObject);
    procedure Register1Click(Sender: TObject);
    procedure About1Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure Optimization2DX1Finish(Sender: TObject);
    procedure Optimization2DX1Progress(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

var
  iteration : integer;

procedure TForm1.bStartClick(Sender: TObject);
begin
  bStart.Enabled := false;

  Optimization2DX1.NumberOfRepositoryPieces := 3;
  Optimization2DX1.SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0);
  Optimization2DX1.SetRepositoryPiece(1, 300, 200, 0, 0, 0, 0, 1, 0, 0);
  Optimization2DX1.SetRepositoryPiece(2, 300, 200, 0, 0, 0, 0, 2, 0, 0);

  Optimization2DX1.NumberOfDemandPieces := 14;
  Optimization2DX1.BladeWidth := 0;
  Optimization2DX1.OptimizationLevel := 50;
  Optimization2DX1.RandomSeed := 0;
  Optimization2DX1.MaximalCutLength := 300;

  Optimization2DX1.SetDemandPiece(0,  60,  40,  1, 0, 0);
  Optimization2DX1.SetDemandPiece(1,  60,  40,  1, 1, 0);
  Optimization2DX1.SetDemandPiece(2,  48,  40,  1, 2, 0);
  Optimization2DX1.SetDemandPiece(3,  60,  53,  1, 3, 0);
  Optimization2DX1.SetDemandPiece(4,  45,  45,  1, 4, 0);
  Optimization2DX1.SetDemandPiece(5,  50,  80,  1, 5, 0);
  Optimization2DX1.SetDemandPiece(6,  45,  75,  1, 6, 0);
  Optimization2DX1.SetDemandPiece(7,  100, 100, 1, 7, 0);
  Optimization2DX1.SetDemandPiece(8,  100, 100, 1, 8, 0);
  Optimization2DX1.SetDemandPiece(9,  90,  90,  1, 9, 0);
  Optimization2DX1.SetDemandPiece(10, 90,  90,  1, 10, 0);
  Optimization2DX1.SetDemandPiece(11, 90,  90,  1, 11, 0);
  Optimization2DX1.SetDemandPiece(12, 110, 110, 1, 12, 0);
  Optimization2DX1.SetDemandPiece(13, 110, 110, 1, 13, 0);

  sbIteration.SimpleText := '';

  iteration := 0;

  Optimization2DX1.StartGuillotine();

  bStart.Enabled := true;

end;

procedure TForm1.Exiy1Click(Sender: TObject);
begin
  Application.Terminate;
end;

procedure TForm1.Register1Click(Sender: TObject);
begin
  if RegisterForm.ShowModal = mrOk
  then begin
    Optimization2DX1.RegisterOptimization2DX(RegisterForm.eName.Text, RegisterForm.eSerialNumber.Text);
  end;
end;

procedure TForm1.About1Click(Sender: TObject);
begin
  AboutBox.lodx2ver.Caption := Optimization2DX1.Version;
  AboutBox.ShowModal;
end;

procedure TForm1.FormShow(Sender: TObject);
begin
  RegisterForm.eComputerID.Text := Optimization2DX1.ComputerID;
end;

procedure TForm1.Optimization2DX1Finish(Sender: TObject);
  var
    NumWastes, NumCuttings, NumPieces, i : integer;
    tx, ty, bx, by, thick, rotated : longint;
    poz_x, poz_y : integer;
    repository_eID, repository_index, demand_index, demand_eID: longint;
    surf_covered : double;
    SheetIndex : longint;

begin

  // if you want to obtain information about all sheets just iterate through all of them
  // sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
  // usualy the first parameter of the methods is the sheet index

  SheetIndex := 0;

  Optimization2DX1.SurfaceCovered(SheetIndex, surf_covered, repository_index, repository_eID);
  eSurfaceCovered.Text := FloatToStr(surf_covered);
  Image1.Canvas.Rectangle(0, 0, 300, 200);

  Optimization2DX1.NumberOfCuttings(SheetIndex, NumCuttings, repository_index, repository_eID);

  for i := 0 to NumCuttings - 1 do
  begin
    Optimization2DX1.GetCut(SheetIndex, i, tx, ty, bx, by, thick, repository_index, repository_eID);
    Image1.Canvas.MoveTo(tx, ty);
    Image1.Canvas.LineTo(bx, by);
  end;

  // utilized rectagles
  Optimization2DX1.NumberOfUtilizedDemandPieces(SheetIndex, NumPieces, repository_index, repository_eID);
  for i := 0 to NumPieces - 1 do
  begin
    Optimization2DX1.GetUtilizedDemandPiece(SheetIndex, i, tx, ty, bx, by, rotated, repository_index, demand_index, repository_eID, demand_eID);
    poz_x := (bx+tx) div 2 - Image1.Canvas.TextWidth(FloatToStr(bx-tx)+'x'+FloatToStr(by-ty)) div 2;
    poz_y := (by+ty) div 2 - Image1.Canvas.TextHeight(FloatToStr(bx-tx)+'x'+FloatToStr(by-ty)) div 2;;
    Image1.Canvas.TextOut(poz_x, poz_y, FloatToStr(abs(bx - tx)) + 'x' + FloatToStr(abs(by - ty)));
  end;

  // waste rectangles
  Optimization2DX1.NumberOfWastePieces(SheetIndex, NumWastes, repository_index, repository_eID);
  for i := 0 to NumWastes - 1 do
  begin
    Optimization2DX1.GetWastePiece(SheetIndex, i, tx, ty, bx, by, repository_index, repository_eID);
    lbWaste.AddItem(FloatToStr(abs(tx - bx)) + ' x ' + FloatToStr(abs(by - ty)), nil);

    poz_x := (bx + tx) div 2 - Image1.Canvas.TextWidth('w') div 2;
    poz_y := (by + ty) div 2 - Image1.Canvas.TextHeight('w') div 2;
    Image1.Canvas.TextOut(poz_x, poz_y, 'w');
  end;

end;

procedure TForm1.Optimization2DX1Progress(Sender: TObject);
begin
  inc(iteration);
  sbIteration.SimpleText := IntToStr(iteration);
  Application.ProcessMessages;
end;

end.
