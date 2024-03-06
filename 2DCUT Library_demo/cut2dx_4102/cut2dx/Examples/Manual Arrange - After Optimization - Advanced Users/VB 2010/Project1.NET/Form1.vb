Option Strict Off
Option Explicit On
Friend Class Form1
	Inherits System.Windows.Forms.Form
    Dim WithEvents Optimization2DX1 As optimal2dx.Optimization2DX
	Dim iteration As Short
	Dim rez As Short
	Dim tx As Integer
	Dim ty As Integer
	Dim bx As Integer
	Dim by As Integer
    Dim thick As Integer
    Dim dem_Index As Integer
    Dim rotated As Integer
    Dim dem_ID As Integer
    Dim rep_ID As Integer
    Dim rep_Index As Integer

    Dim myPen As Pen = Pens.Black
    Dim text_size As System.Drawing.SizeF
    Dim i As Integer
    Dim sheet As SheetInfo ' store all info about a particular sheet
    Dim moving_piece As Integer ' -1 if no piece is moving; index of the moving piece otherwise
    Dim LastX As Integer
    Dim LastY As Integer
    Dim MouseX As Integer
    Dim MouseY As Integer
    Dim startPoint As Point ' this will contain the client coordinates (0,0) given in screen coordinates; useful for drawing the moving piece

    Private Sub cbStart_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cbStart.Click

        cbStart.Enabled = False

        Optimization2DX1.NumberOfRepositoryPieces = 1

        Optimization2DX1.SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0) ' DO NOT modify the size of the sheet. it has the same size as the picture

        Optimization2DX1.NumberOfDemandPieces = 7
        Optimization2DX1.BladeWidth = 0
        Optimization2DX1.OptimizationLevel = 50
        Optimization2DX1.RandomSeed = 1

        Optimization2DX1.SetDemandPiece(0, 60, 40, 1, 0, 0)
        Optimization2DX1.SetDemandPiece(1, 60, 40, 1, 1, 0)
        Optimization2DX1.SetDemandPiece(2, 48, 40, 1, 2, 0)
        Optimization2DX1.SetDemandPiece(3, 60, 53, 1, 3, 0)
        Optimization2DX1.SetDemandPiece(4, 45, 45, 1, 4, 0)
        Optimization2DX1.SetDemandPiece(5, 50, 80, 1, 5, 0)
        Optimization2DX1.SetDemandPiece(6, 45, 75, 1, 6, 0)
        
        iteration = 0

        lbWaste.Items.Clear()

        Optimization2DX1.StartGuillotine() ' manual arrange works for guillotine only

        ' PREPARE FOR MANUAL ARRANGE

        Optimization2DX1.ManualArrangeOptimizationType = 0

        Optimization2DX1.ManualArrangeSetRepositoryPiece(300, 200, 0, 0, 0, 0, 0) ' do not modify the size of the sheet. it has the same size as the picture. do scale if you need other sizes

        ' set all other parameters here
        Optimization2DX1.BladeWidth = 0
        'set all other parameters is required

        'send all cuts back to the component
        Optimization2DX1.ManualArrangeNumberOfCuts = sheet.NumCuts
        For i = 0 To sheet.NumCuts - 1
            Optimization2DX1.ManualArrangeSetCut(i, sheet.Cuts(i).TopX, sheet.Cuts(i).TopY, sheet.Cuts(i).BottomX, sheet.Cuts(i).BottomY, sheet.Cuts(i).Thickness)
        Next i
        'send all piece positions back to the component
        Optimization2DX1.ManualArrangeNumberOfDemandPieces = sheet.NumPieces
        For i = 0 To sheet.NumPieces - 1
            Optimization2DX1.ManualArrangeSetDemandPiece(i, sheet.Pieces(i).TopX, sheet.Pieces(i).TopY, sheet.Pieces(i).BottomX, sheet.Pieces(i).BottomY, sheet.Pieces(i).Rotated, sheet.Pieces(i).ExternalIndex)

        Next i
        'send all waste positions back to the component
        Optimization2DX1.ManualArrangeNumberOfWastes = sheet.NumWastes
        For i = 0 To sheet.NumWastes - 1
            Optimization2DX1.ManualArrangeSetWaste(i, sheet.Wastes(i).TopX, sheet.Wastes(i).TopY, sheet.Wastes(i).BottomX, sheet.Wastes(i).BottomY)
        Next i

        ' now you can move pieces with the mouse
        MsgBox("Move an existing piece by drag and drop. You can drop a piece on waste large enough to accept that piece.", MsgBoxStyle.OkOnly)

        cbStart.Enabled = True
    End Sub

    Private Sub RegisterToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RegisterToolStripMenuItem.Click
        If Register.ShowDialog() = Windows.Forms.DialogResult.OK Then
            Optimization2DX1.RegisterCut2DX(Register.tbName.Text, Register.tbSerialNumber.Text)
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
        moving_piece = -1 ' no moving piece
    End Sub

    Private Sub Optimization2DX1_OnAfterManualArrange() Handles Optimization2DX1.OnAfterManualArrange
        ' this is raised after a manual arrange operation
        ' use this event to draw the new layout and to store information about the new layout (cuts, pieces, wastes)
        ' very similar with OnFinish

        Dim bm As Bitmap = New Bitmap(Picture1.Width, Picture1.Height)
        Dim g As Graphics = Graphics.FromImage(bm)
        Dim surf_covered As Double

        lbWaste.Items.Clear()

        surf_covered = Optimization2DX1.ManualArrangeSurfaceCovered
        tbUtilizedSurface.Text = CStr(surf_covered)
        sheet.CoveredSurface = surf_covered

        Dim trim As Integer

        Dim NumHoles As Integer

        Optimization2DX1.ManualArrangeGetRepositoryPiece(sheet.length, sheet.width, trim, trim, trim, trim, NumHoles)

        g.Clear(Color.White)

        g.DrawRectangle(myPen, 0, 0, 300, 200)
        sheet.NumCuts = Optimization2DX1.ManualArrangeNumberOfCuts
        Array.Resize(sheet.Cuts, sheet.NumCuts)

        For i = 0 To sheet.NumCuts - 1
            Optimization2DX1.ManualArrangeGetCut(i, tx, ty, bx, by, thick)
            g.DrawLine(myPen, tx, ty, bx, by)
            'save the cuts again ... maybe some of them have been changed during manual arrange
            sheet.Cuts(i) = New Cut
            sheet.Cuts(i).TopX = tx
            sheet.Cuts(i).TopY = ty
            sheet.Cuts(i).BottomX = bx
            sheet.Cuts(i).BottomY = by
            sheet.Cuts(i).Thickness = thick
        Next i

        sheet.NumPieces = Optimization2DX1.NumberOfDemandPieces
        Array.Resize(sheet.Pieces, sheet.NumPieces)

        For i = 0 To sheet.NumPieces - 1
            Optimization2DX1.ManualArrangeGetDemandPiece(i, tx, ty, bx, by, rotated, dem_ID)
            text_size = g.MeasureString(CStr(System.Math.Abs(bx - tx)) & "x" & CStr(System.Math.Abs(by - ty)), Font)
            g.DrawString(CStr(System.Math.Abs(bx - tx)) & "x" & CStr(System.Math.Abs(by - ty)), Font, Brushes.Black, (bx + tx) / 2 - text_size.Width / 2, (by + ty) / 2 - text_size.Height / 2)
            'save the piece position again ... maybe some of them have been changed during manual arrange
            sheet.Pieces(i) = New Piece
            sheet.Pieces(i).TopX = tx
            sheet.Pieces(i).TopY = ty
            sheet.Pieces(i).BottomX = bx
            sheet.Pieces(i).BottomY = by
            sheet.Pieces(i).Rotated = rotated
            sheet.Pieces(i).ExternalIndex = dem_ID

        Next i

        sheet.NumWastes = Optimization2DX1.ManualArrangeNumberOfWastes
        Array.Resize(sheet.Wastes, sheet.NumWastes)
        For i = 0 To sheet.NumWastes - 1
            Optimization2DX1.ManualArrangeGetWaste(i, tx, ty, bx, by)
            lbWaste.Items.Add(CStr(System.Math.Abs(bx - tx)) & "x" & CStr(System.Math.Abs(by - ty)))
            text_size = g.MeasureString("w", Font)
            g.DrawString("w", Font, Brushes.Black, (bx + tx) / 2 - text_size.Width / 2, (by + ty) / 2 - text_size.Height / 2)
            'save the wastes again ... maybe some of them have been changed during manual arrange
            sheet.Wastes(i) = New Waste
            sheet.Wastes(i).TopX = tx
            sheet.Wastes(i).TopY = ty
            sheet.Wastes(i).BottomX = bx
            sheet.Wastes(i).BottomY = by
        Next i
        Picture1.Image = bm

    End Sub

    Private Sub Optimization2DX1_OnFinish() Handles Optimization2DX1.OnFinish
        ' if you want to obtain information about all sheets just iterate through all of them
        ' sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
        ' usually the first parameter of the methods is the sheet index
        lbWaste.Items.Clear()

        sheet = New SheetInfo

        Dim SheetIndex As Long
        SheetIndex = 0 ' this is the first sheet
        Dim bm As Bitmap = New Bitmap(Picture1.Width, Picture1.Height)
        Dim g As Graphics = Graphics.FromImage(bm)
        Dim surf_covered As Double


        Optimization2DX1.SurfaceCovered(SheetIndex, surf_covered, rep_Index, rep_ID)
        tbUtilizedSurface.Text = CStr(surf_covered)
        'sheet.setCoveredSurface(surf_covered)
        sheet.CoveredSurface = surf_covered

        Dim trim As Integer
        Dim priority As Integer
        Dim NoHoles As Integer

        Optimization2DX1.GetRepositoryPiece(0, sheet.length, sheet.width, Trim, Trim, Trim, Trim, rep_ID, priority, NoHoles)

        g.Clear(Color.White)

        g.DrawRectangle(myPen, 0, 0, 300, 200)
        Optimization2DX1.NumberOfCuttings(SheetIndex, sheet.NumCuts, rep_Index, rep_ID)
        Array.Resize(sheet.Cuts, sheet.NumCuts)

        For i = 0 To sheet.NumCuts - 1
            Optimization2DX1.GetCut(SheetIndex, i, tx, ty, bx, by, thick, rep_Index, rep_ID)
            g.DrawLine(myPen, tx, ty, bx, by)

            ' store the cuts
            sheet.Cuts(i) = New Cut
            sheet.Cuts(i).TopX = tx
            sheet.Cuts(i).TopY = ty
            sheet.Cuts(i).BottomX = bx
            sheet.Cuts(i).BottomY = by
            sheet.Cuts(i).Thickness = thick
        Next i

        Optimization2DX1.NumberOfUtilizedDemandPieces(SheetIndex, sheet.NumPieces, rep_Index, rep_ID)
        Array.Resize(sheet.Pieces, sheet.NumPieces)

        For i = 0 To sheet.NumPieces - 1
            Optimization2DX1.GetUtilizedDemandPiece(SheetIndex, i, tx, ty, bx, by, rotated, rep_Index, dem_Index, rep_ID, dem_ID)
            text_size = g.MeasureString(CStr(System.Math.Abs(bx - tx)) & "x" & CStr(System.Math.Abs(by - ty)), Font)
            g.DrawString(CStr(System.Math.Abs(bx - tx)) & "x" & CStr(System.Math.Abs(by - ty)), Font, Brushes.Black, (bx + tx) / 2 - text_size.Width / 2, (by + ty) / 2 - text_size.Height / 2)
            'store the piece position
            sheet.Pieces(i) = New Piece
            sheet.Pieces(i).TopX = tx
            sheet.Pieces(i).TopY = ty
            sheet.Pieces(i).BottomX = bx
            sheet.Pieces(i).BottomY = by
            sheet.Pieces(i).Rotated = rotated
            sheet.Pieces(i).ExternalIndex = dem_ID

        Next i

        Optimization2DX1.NumberOfWastePieces(SheetIndex, sheet.NumWastes, rep_Index, rep_ID)

        Array.Resize(sheet.Wastes, sheet.NumWastes)
        For i = 0 To sheet.NumWastes - 1
            Optimization2DX1.GetWastePiece(SheetIndex, i, tx, ty, bx, by, rep_Index, rep_ID)
            lbWaste.Items.Add(CStr(System.Math.Abs(bx - tx)) & "x" & CStr(System.Math.Abs(by - ty)))
            text_size = g.MeasureString("w", Font)
            g.DrawString("w", Font, Brushes.Black, (bx + tx) / 2 - text_size.Width / 2, (by + ty) / 2 - text_size.Height / 2)
            ' store the wastes
            sheet.Wastes(i) = New Waste
            sheet.Wastes(i).TopX = tx
            sheet.Wastes(i).TopY = ty
            sheet.Wastes(i).BottomX = bx
            sheet.Wastes(i).BottomY = by

        Next i
        Picture1.Image = bm
    End Sub

    Private Sub Optimization2DX1_OnProgress() Handles Optimization2DX1.OnProgress
        iteration = iteration + 1
    End Sub

    Private Sub Picture1_MouseDown(ByVal sender As System.Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles Picture1.MouseDown

        Dim control As Control = CType(sender, Control)
        startPoint = Control.PointToScreen(New Point(0, 0))

        ' now I have to iterate through all pieces to see which one will be moved
        Dim index As Integer
        For i = 0 To sheet.NumPieces - 1
            If (sheet.Pieces(i).TopX < e.X) And (sheet.Pieces(i).TopY < e.Y) And (sheet.Pieces(i).BottomX > e.X) And (sheet.Pieces(i).BottomY > e.Y) Then
                'i've found the piece to be moved
                index = i
                Exit For
            End If
        Next i
        If (index <> -1) Then
            moving_piece = index ' index of the moving piece
            LastX = e.X ' where the mouse cursor was last time
            LastY = e.Y
            MouseX = e.X ' where the mouse was down
            MouseY = e.Y

            Dim rc As Rectangle
            ' draw the current moving rectangle with dots
            rc.X = sheet.Pieces(moving_piece).TopX + e.X - LastX + startPoint.X
            rc.Width = sheet.Pieces(moving_piece).BottomX - sheet.Pieces(moving_piece).TopX
            rc.Y = sheet.Pieces(moving_piece).TopY + e.Y - LastY + startPoint.Y
            rc.Height = sheet.Pieces(moving_piece).BottomY - sheet.Pieces(moving_piece).TopY

            ControlPaint.DrawReversibleFrame(rc, Color.White, FrameStyle.Dashed) ' draw the moving rectangle
        Else
            moving_piece = -1
        End If
    End Sub

    Private Sub Picture1_MouseMove(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles Picture1.MouseMove
        If (moving_piece <> -1) Then ' only if a piece is moving
            If (e.Y - MouseY + sheet.Pieces(moving_piece).BottomY < Picture1.Bottom) And (e.X - MouseX + sheet.Pieces(moving_piece).BottomX < Picture1.Right) And (e.X - MouseX + sheet.Pieces(moving_piece).TopX > 0) And (e.Y - MouseY + sheet.Pieces(moving_piece).TopY > 0) Then ' do the redraw only if the piece is inside the picture
                Dim rc As Rectangle

                ' delete the moving oject from the previous position
                rc.X = sheet.Pieces(moving_piece).TopX + LastX - MouseX + startPoint.X
                rc.Width = sheet.Pieces(moving_piece).BottomX - sheet.Pieces(moving_piece).TopX
                rc.Y = sheet.Pieces(moving_piece).TopY + LastY - MouseY + startPoint.Y
                rc.Height = sheet.Pieces(moving_piece).BottomY - sheet.Pieces(moving_piece).TopY

                ControlPaint.DrawReversibleFrame(rc, Color.White, FrameStyle.Dashed)

                ' draw the moving rectangle in the new position
                rc.X = sheet.Pieces(moving_piece).TopX + e.X - MouseX + startPoint.X
                rc.Width = sheet.Pieces(moving_piece).BottomX - sheet.Pieces(moving_piece).TopX
                rc.Y = sheet.Pieces(moving_piece).TopY + e.Y - MouseY + startPoint.Y
                rc.Height = sheet.Pieces(moving_piece).BottomY - sheet.Pieces(moving_piece).TopY

                ControlPaint.DrawReversibleFrame(rc, Color.White, FrameStyle.Dashed)

                LastX = e.X
                LastY = e.Y
            End If
        End If
    End Sub

    Private Sub Picture1_MouseUp(ByVal sender As System.Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles Picture1.MouseUp

        If (moving_piece <> -1) Then
            Dim rc As Rectangle
            ' delete the moving oject from the previous position
            rc.X = sheet.Pieces(moving_piece).TopX + LastX - MouseX + startPoint.X
            rc.Width = sheet.Pieces(moving_piece).BottomX - sheet.Pieces(moving_piece).TopX
            rc.Y = sheet.Pieces(moving_piece).TopY + LastY - MouseY + startPoint.Y
            rc.Height = sheet.Pieces(moving_piece).BottomY - sheet.Pieces(moving_piece).TopY

            ControlPaint.DrawReversibleFrame(rc, Color.White, FrameStyle.Dashed)


            Dim Allowed As Long
            'now perform the actual manual arrange with the component
            'after this operation the OnManualArrange event is raised automatically
            Optimization2DX1.ManualArrangeGuillotineMovePiece(moving_piece, e.X - MouseX + sheet.Pieces(moving_piece).TopX, e.Y - MouseY + sheet.Pieces(moving_piece).TopY, e.X - MouseX + sheet.Pieces(moving_piece).TopX + sheet.Pieces(moving_piece).BottomX - sheet.Pieces(moving_piece).TopX, e.Y - MouseY + sheet.Pieces(moving_piece).TopY + sheet.Pieces(moving_piece).BottomY - sheet.Pieces(moving_piece).TopY, sheet.Pieces(moving_piece).Rotated, 0, Allowed)
            If (Allowed) Then
                '            OK. MOVE ACCEPTED

            Else
                ' MOVE NOT ACCEPTED

            End If
            moving_piece = -1 ' the piece is not moving anymore
        End If
    End Sub

    Private Sub Form1_Shown(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Shown
        MsgBox("Pres start to perform the optimization", MsgBoxStyle.OkOnly)
    End Sub
End Class
Public Class Cut
    Public TopX As Integer ' top-left corner point
    Public TopY As Integer
    Public BottomX As Integer 'bottom-right corner point
    Public BottomY As Integer
    Public Thickness As Integer

End Class
Public Class Waste
    Public TopX As Integer ' top-left corner point
    Public TopY As Integer
    Public BottomX As Integer 'bottom-right corner point
    Public BottomY As Integer

End Class
Public Class Piece
    Public TopX As Integer ' top-left corner point
    Public TopY As Integer
    Public BottomX As Integer 'bottom-right corner point
    Public BottomY As Integer
    Public DemandIndex As Integer
    Public ExternalIndex As Integer
    Public Rotated As Long

End Class
Public Class SheetInfo
    Public SheetIndex As Long
    Public length As Integer
    Public width As Integer
    Public CoveredSurface As Double
    Public NumCuts As Integer
    Public Cuts() As Cut
    Public NumPieces As Integer
    Public Pieces() As Piece
    Public NumWastes As Integer
    Public Wastes() As Waste

    Function getCoveredSurface() As Double
        Return CoveredSurface
    End Function

    Sub setCoveredSurface(ByVal Value As Double)
        CoveredSurface = Value
    End Sub
End Class