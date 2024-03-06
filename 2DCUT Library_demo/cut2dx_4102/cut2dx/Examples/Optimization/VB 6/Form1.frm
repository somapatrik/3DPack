VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Cut 2D X example"
   ClientHeight    =   6840
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7515
   LinkTopic       =   "Form1"
   ScaleHeight     =   6840
   ScaleWidth      =   7515
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox lbWaste 
      Height          =   2010
      Left            =   5400
      TabIndex        =   11
      Top             =   2160
      Width           =   1455
   End
   Begin VB.CommandButton cbRegister 
      Caption         =   "Register"
      Height          =   375
      Left            =   1080
      TabIndex        =   10
      Top             =   3600
      Width           =   1215
   End
   Begin VB.TextBox tbSerialNumber 
      Height          =   285
      Left            =   240
      TabIndex        =   6
      Top             =   6000
      Width           =   4575
   End
   Begin VB.TextBox tbComputerID 
      Height          =   285
      Left            =   240
      TabIndex        =   5
      Top             =   5160
      Width           =   4575
   End
   Begin VB.TextBox tbName 
      Height          =   285
      Left            =   240
      TabIndex        =   4
      Text            =   "Your company name here ..."
      Top             =   4320
      Width           =   4575
   End
   Begin VB.PictureBox Picture1 
      AutoRedraw      =   -1  'True
      Height          =   3135
      Left            =   120
      ScaleHeight     =   205
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   309
      TabIndex        =   3
      Top             =   120
      Width           =   4695
   End
   Begin VB.TextBox tbUtilizedSurface 
      Height          =   285
      Left            =   5400
      TabIndex        =   1
      Top             =   1200
      Width           =   1455
   End
   Begin VB.CommandButton cbStart 
      Caption         =   "Start"
      Height          =   375
      Left            =   5400
      TabIndex        =   0
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label Label7 
      Caption         =   "Waste (L x W)"
      Height          =   255
      Left            =   5400
      TabIndex        =   12
      Top             =   1920
      Width           =   1335
   End
   Begin VB.Label Label4 
      Caption         =   "Serial Number"
      Height          =   255
      Left            =   240
      TabIndex        =   9
      Top             =   5760
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "ComputerID"
      Height          =   255
      Left            =   240
      TabIndex        =   8
      Top             =   4920
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "Name"
      Height          =   255
      Left            =   240
      TabIndex        =   7
      Top             =   4080
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "Utilized Surface"
      Height          =   255
      Left            =   5400
      TabIndex        =   2
      Top             =   960
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim WithEvents OptDX2 As Optimization2DX
Attribute OptDX2.VB_VarHelpID = -1
Dim iteration As Integer
Dim stationary As Integer
Dim rez As Integer
Dim top_x As Long
Dim top_y As Long
Dim bottom_x As Long
Dim bottom_y As Long
Dim L As Long
Dim W As Long
Dim u As Long
Dim thick As Long
Dim rotated As Long
Dim demand_index As Long
Dim demand_ID As Long
Dim num_cuts As Long
Dim repository_Index As Long
Dim repository_ID As Long
Dim num_wastes As Long
Dim num_pieces As Long
Dim surf_covered As Double

Private Sub cbRegister_Click()
  OptDX21.RegisterOptimization2DX tbName.Text, tbSerialNumber.Text
End Sub
Private Sub cbStart_Click()

  cbStart.Enabled = False
  OptDX2.NumberOfRepositoryPieces = 1
  OptDX2.SetRepositoryPiece 0, 300, 200, 0, 0, 0, 0, 0, 0, 0
  
  OptDX2.NumberOfDemandPieces = 14
  OptDX2.BladeWidth = 0
  OptDX2.OptimizationLevel = 50
  OptDX2.RandomSeed = 1
  
  
  OptDX2.SetDemandPiece 0, 60, 40, 1, 0, 0
  OptDX2.SetDemandPiece 1, 60, 40, 1, 1, 0
  OptDX2.SetDemandPiece 2, 48, 40, 1, 2, 0
  OptDX2.SetDemandPiece 3, 60, 53, 1, 3, 0
  OptDX2.SetDemandPiece 4, 45, 45, 1, 4, 0
  OptDX2.SetDemandPiece 5, 50, 80, 1, 5, 0
  OptDX2.SetDemandPiece 6, 45, 75, 1, 6, 0
  OptDX2.SetDemandPiece 7, 100, 100, 1, 7, 0
  OptDX2.SetDemandPiece 8, 100, 100, 1, 8, 0
  OptDX2.SetDemandPiece 9, 90, 90, 1, 9, 0
  OptDX2.SetDemandPiece 10, 90, 90, 1, 10, 0
  OptDX2.SetDemandPiece 11, 90, 90, 1, 11, 0
  OptDX2.SetDemandPiece 12, 110, 110, 1, 12, 0
  OptDX2.SetDemandPiece 13, 110, 110, 1, 13, 0
  
  iteration = 0
  stationary = 0
  
  lbWaste.Clear

  OptDX2.StartGuillotine
End Sub
Private Sub OptDX2_OnFinish()
  ' if you want to obtain information about all sheets just iterate through all of them
  ' sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
  ' usually the first parameter of the methods is the sheet index

  Dim SheetIndex As Long
  SheetIndex = 0 ' this is the first sheet

  OptDX2.SurfaceCovered SheetIndex, surf_covered, repository_Index, repository_ID ' surface covered in percent
  tbUtilizedSurface.Text = surf_covered
  Picture1.Cls
  
  Picture1.Line (0, 0)-(300, 200), , B
  ' number of cuttings for the first sheet
  OptDX2.NumberOfCuttings SheetIndex, num_cuts, repository_Index, repository_ID
  For i = 0 To num_cuts - 1
    OptDX2.GetCut SheetIndex, i, top_x, top_y, bottom_x, bottom_y, thick, repository_Index, repository_ID
    Picture1.Line (top_x, top_y)-(bottom_x, bottom_y)
  Next i
  
  ' number of utilized demand piece for the first sheet
  OptDX2.NumberOfUtilizedDemandPieces SheetIndex, num_pieces, repository_Index, repository_ID
  For i = 0 To num_pieces - 1
    OptDX2.GetUtilizedDemandPiece SheetIndex, i, top_x, top_y, bottom_x, bottom_y, rotated, repository_Index, demand_index, repository_ID, demand_ID
    Picture1.CurrentX = (bottom_x + top_x) / 2 - Picture1.TextWidth(CStr(Abs(bottom_x - tx)) + "x" + CStr(Abs(bottom_y - top_y))) / 2
    Picture1.CurrentY = (bottom_y + top_y) / 2 - Picture1.TextHeight(CStr(Abs(bottom_x - tx)) + "x" + CStr(Abs(bottom_y - top_y))) / 2
    Picture1.Print CStr(Abs(bottom_x - top_x)) + "x" + CStr(Abs(bottom_y - ty))
  Next i
  
  ' number of waste piece for the first sheet
  OptDX2.NumberOfWastePieces SheetIndex, num_wastes, repository_Index, repository_ID
  For i = 0 To num_wastes - 1
    OptDX2.GetWastePiece SheetIndex, i, top_x, top_y, bottom_x, bottom_y, repository_Index, repository_ID
    lbWaste.AddItem CStr(Abs(bottom_x - top_x)) + "x" + CStr(Abs(bottom_y - top_y))
    Picture1.CurrentX = (bottom_x + top_x) / 2 - Picture1.TextWidth("w") / 2
    Picture1.CurrentY = (bottom_y + top_y) / 2 - Picture1.TextHeight("w") / 2
    Picture1.Print "w";
  Next i

  cbStart.Enabled = True
End Sub
Private Sub Form_Activate()
  Set OptDX2 = New Optimization2DX
  v = OptDX2.ComputerID
  tbComputerID.Text = CStr(v)
End Sub
