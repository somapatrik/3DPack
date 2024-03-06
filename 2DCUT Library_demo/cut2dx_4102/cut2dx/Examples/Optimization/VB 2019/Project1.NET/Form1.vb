Option Strict Off
Option Explicit On
Friend Class Form1
	Inherits System.Windows.Forms.Form
    Dim WithEvents Optimization2DX1 As optimal2dx.Optimization2DX
	Dim iteration As Short
	Dim rez As Short
    Dim top_x As Integer
    Dim top_y As Integer
    Dim bottom_x As Integer
    Dim bottom_y As Integer
    Dim thick As Integer
    Dim demand_Index As Integer
    Dim rotated As Integer
    Dim demand_ID As Integer
    Dim repository_ID As Integer
    Dim repository_Index As Integer
    Dim NumCuts As Integer
    Dim NumWastes As Integer
    Dim NumPieces As Integer
    Dim myPen As Pen = Pens.Black
    Dim text_size As System.Drawing.SizeF
    Dim i As Integer
    Private Sub cbStart_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cbStart.Click

        cbStart.Enabled = False

        Optimization2DX1.NumberOfRepositoryPieces = 1
        Optimization2DX1.SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0)
        Optimization2DX1.NumberOfDemandPieces = 14
        Optimization2DX1.BladeWidth = 0
        Optimization2DX1.OptimizationLevel = 50
        Optimization2DX1.RandomSeed = 1

        Optimization2DX1.SetDemandPiece(0, 60, 40, 0, 0, 0)
        Optimization2DX1.SetDemandPiece(1, 60, 40, 0, 1, 0)
        Optimization2DX1.SetDemandPiece(2, 48, 40, 0, 2, 0)
        Optimization2DX1.SetDemandPiece(3, 60, 53, 0, 3, 0)
        Optimization2DX1.SetDemandPiece(4, 45, 45, 0, 4, 0)
        Optimization2DX1.SetDemandPiece(5, 50, 80, 0, 5, 0)
        Optimization2DX1.SetDemandPiece(6, 45, 75, 0, 6, 0)
        Optimization2DX1.SetDemandPiece(7, 100, 100, 0, 7, 0)
        Optimization2DX1.SetDemandPiece(8, 100, 100, 0, 8, 0)
        Optimization2DX1.SetDemandPiece(9, 90, 90, 0, 9, 0)
        Optimization2DX1.SetDemandPiece(10, 90, 90, 0, 10, 0)
        Optimization2DX1.SetDemandPiece(11, 90, 90, 0, 11, 0)
        Optimization2DX1.SetDemandPiece(12, 110, 110, 0, 12, 0)
        Optimization2DX1.SetDemandPiece(13, 110, 110, 0, 13, 0)

        iteration = 0

        lbWaste.Items.Clear()

        Optimization2DX1.StartGuillotine()

        cbStart.Enabled = True
    End Sub

    Private Sub RegisterToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RegisterToolStripMenuItem.Click
        If Register.ShowDialog() = Windows.Forms.DialogResult.OK Then
            Optimization2DX1.RegisterOptimization2DX(Register.tbName.Text, Register.tbSerialNumber.Text)
        End If
    End Sub
    Private Sub AboutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AboutToolStripMenuItem.Click
        AboutBox1.ShowDialog()
    End Sub
    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
        Close()
    End Sub
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Optimization2DX1 = New optimal2dx.Optimization2DX
        Register.tbComputerID.Text = CStr(Optimization2DX1.ComputerID)
    End Sub

    Private Sub Optimization2DX1_OnFinish() Handles Optimization2DX1.OnFinish
        ' if you want to obtain information about all sheets just iterate through all of them
        ' sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
        ' usually the first parameter of the methods is the sheet index

        Dim SheetIndex As Long
        SheetIndex = 0 ' this is the first sheet
        Dim bm As Bitmap = New Bitmap(Picture1.Width, Picture1.Height)
        Dim g As Graphics = Graphics.FromImage(bm)
        Dim surf_covered As Double
        Optimization2DX1.SurfaceCovered(SheetIndex, surf_covered, repository_Index, repository_ID)
        tbUtilizedSurface.Text = CStr(surf_covered)
        g.Clear(Color.White)

        g.DrawRectangle(myPen, 0, 0, 300, 200)
        Optimization2DX1.NumberOfCuttings(SheetIndex, NumCuts, repository_Index, repository_ID)
        For i = 0 To NumCuts - 1
            Optimization2DX1.GetCut(SheetIndex, i, top_x, top_y, bottom_x, bottom_y, thick, repository_Index, repository_ID)
            g.DrawLine(myPen, top_x, top_y, bottom_x, bottom_y)
        Next i

        Optimization2DX1.NumberOfUtilizedDemandPieces(SheetIndex, NumPieces, repository_Index, repository_ID)
        For i = 0 To NumPieces - 1
            Optimization2DX1.GetUtilizedDemandPiece(SheetIndex, i, top_x, top_y, bottom_x, bottom_y, rotated, repository_Index, demand_Index, repository_ID, demand_ID)
            text_size = g.MeasureString(CStr(System.Math.Abs(bottom_x - top_x)) & "x" & CStr(System.Math.Abs(bottom_y - top_y)), Font)
            g.DrawString(CStr(System.Math.Abs(bottom_x - top_x)) & "x" & CStr(System.Math.Abs(bottom_y - top_y)), Font, Brushes.Black, (bottom_x + top_x) / 2 - text_size.Width / 2, (bottom_y + top_y) / 2 - text_size.Height / 2)
        Next i

        Optimization2DX1.NumberOfWastePieces(SheetIndex, NumWastes, repository_Index, repository_ID)
        For i = 0 To NumWastes - 1
            Optimization2DX1.GetWastePiece(SheetIndex, i, top_x, top_y, bottom_x, bottom_y, repository_Index, repository_ID)
            lbWaste.Items.Add(CStr(System.Math.Abs(bottom_x - top_x)) & "x" & CStr(System.Math.Abs(bottom_y - top_y)))
            text_size = g.MeasureString("w", Font)
            g.DrawString("w", Font, Brushes.Black, (bottom_x + top_x) / 2 - text_size.Width / 2, (bottom_y + top_y) / 2 - text_size.Height / 2)
        Next i
        Picture1.Image = bm
    End Sub

    Private Sub Optimization2DX1_OnProgress() Handles Optimization2DX1.OnProgress
        iteration = iteration + 1
    End Sub
End Class