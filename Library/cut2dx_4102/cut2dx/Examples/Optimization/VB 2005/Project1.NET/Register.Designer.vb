<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Register
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing AndAlso components IsNot Nothing Then
            components.Dispose()
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.bRegister = New System.Windows.Forms.Button
        Me.tbSerialNumber = New System.Windows.Forms.TextBox
        Me.tbComputerID = New System.Windows.Forms.TextBox
        Me.tbName = New System.Windows.Forms.TextBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.bCancel = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'bRegister
        '
        Me.bRegister.BackColor = System.Drawing.SystemColors.Control
        Me.bRegister.Cursor = System.Windows.Forms.Cursors.Default
        Me.bRegister.DialogResult = System.Windows.Forms.DialogResult.OK
        Me.bRegister.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.bRegister.ForeColor = System.Drawing.SystemColors.ControlText
        Me.bRegister.Location = New System.Drawing.Point(46, 183)
        Me.bRegister.Name = "bRegister"
        Me.bRegister.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.bRegister.Size = New System.Drawing.Size(81, 25)
        Me.bRegister.TabIndex = 17
        Me.bRegister.Text = "Register"
        Me.bRegister.UseVisualStyleBackColor = False
        '
        'tbSerialNumber
        '
        Me.tbSerialNumber.AcceptsReturn = True
        Me.tbSerialNumber.BackColor = System.Drawing.SystemColors.Window
        Me.tbSerialNumber.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.tbSerialNumber.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbSerialNumber.ForeColor = System.Drawing.SystemColors.WindowText
        Me.tbSerialNumber.Location = New System.Drawing.Point(12, 141)
        Me.tbSerialNumber.MaxLength = 0
        Me.tbSerialNumber.Name = "tbSerialNumber"
        Me.tbSerialNumber.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.tbSerialNumber.Size = New System.Drawing.Size(310, 20)
        Me.tbSerialNumber.TabIndex = 13
        '
        'tbComputerID
        '
        Me.tbComputerID.AcceptsReturn = True
        Me.tbComputerID.BackColor = System.Drawing.SystemColors.Window
        Me.tbComputerID.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.tbComputerID.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbComputerID.ForeColor = System.Drawing.SystemColors.WindowText
        Me.tbComputerID.Location = New System.Drawing.Point(12, 85)
        Me.tbComputerID.MaxLength = 0
        Me.tbComputerID.Name = "tbComputerID"
        Me.tbComputerID.ReadOnly = True
        Me.tbComputerID.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.tbComputerID.Size = New System.Drawing.Size(310, 20)
        Me.tbComputerID.TabIndex = 12
        '
        'tbName
        '
        Me.tbName.AcceptsReturn = True
        Me.tbName.BackColor = System.Drawing.SystemColors.Window
        Me.tbName.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.tbName.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbName.ForeColor = System.Drawing.SystemColors.WindowText
        Me.tbName.Location = New System.Drawing.Point(12, 29)
        Me.tbName.MaxLength = 0
        Me.tbName.Name = "tbName"
        Me.tbName.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.tbName.Size = New System.Drawing.Size(310, 20)
        Me.tbName.TabIndex = 11
        Me.tbName.Text = "Your company name here ..."
        '
        'Label4
        '
        Me.Label4.BackColor = System.Drawing.SystemColors.Control
        Me.Label4.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label4.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label4.Location = New System.Drawing.Point(12, 125)
        Me.Label4.Name = "Label4"
        Me.Label4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label4.Size = New System.Drawing.Size(81, 17)
        Me.Label4.TabIndex = 16
        Me.Label4.Text = "Serial Number"
        '
        'Label3
        '
        Me.Label3.BackColor = System.Drawing.SystemColors.Control
        Me.Label3.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label3.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label3.Location = New System.Drawing.Point(12, 69)
        Me.Label3.Name = "Label3"
        Me.Label3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label3.Size = New System.Drawing.Size(65, 17)
        Me.Label3.TabIndex = 15
        Me.Label3.Text = "ComputerID"
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.SystemColors.Control
        Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label2.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label2.Location = New System.Drawing.Point(12, 13)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label2.Size = New System.Drawing.Size(57, 17)
        Me.Label2.TabIndex = 14
        Me.Label2.Text = "Name"
        '
        'bCancel
        '
        Me.bCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.bCancel.Location = New System.Drawing.Point(193, 183)
        Me.bCancel.Name = "bCancel"
        Me.bCancel.Size = New System.Drawing.Size(75, 23)
        Me.bCancel.TabIndex = 18
        Me.bCancel.Text = "Cancel"
        Me.bCancel.UseVisualStyleBackColor = True
        '
        'Register
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(334, 218)
        Me.Controls.Add(Me.bCancel)
        Me.Controls.Add(Me.bRegister)
        Me.Controls.Add(Me.tbSerialNumber)
        Me.Controls.Add(Me.tbComputerID)
        Me.Controls.Add(Me.tbName)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Name = "Register"
        Me.Text = "Register"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Public WithEvents bRegister As System.Windows.Forms.Button
    Public WithEvents tbSerialNumber As System.Windows.Forms.TextBox
    Public WithEvents tbComputerID As System.Windows.Forms.TextBox
    Public WithEvents tbName As System.Windows.Forms.TextBox
    Public WithEvents Label4 As System.Windows.Forms.Label
    Public WithEvents Label3 As System.Windows.Forms.Label
    Public WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents bCancel As System.Windows.Forms.Button
End Class
