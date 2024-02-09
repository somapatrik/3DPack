object fRegister: TfRegister
  Left = 318
  Top = 236
  Width = 440
  Height = 268
  Caption = 'Registration'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 200
    Width = 432
    Height = 41
    Align = alBottom
    TabOrder = 0
    object bbRegister: TBitBtn
      Left = 72
      Top = 8
      Width = 75
      Height = 25
      TabOrder = 0
      Kind = bkOK
    end
    object bbCancel: TBitBtn
      Left = 280
      Top = 8
      Width = 75
      Height = 25
      TabOrder = 1
      Kind = bkCancel
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 432
    Height = 200
    Align = alClient
    TabOrder = 1
    object Label2: TLabel
      Left = 24
      Top = 72
      Width = 59
      Height = 13
      Caption = 'Computer ID'
    end
    object Label3: TLabel
      Left = 24
      Top = 133
      Width = 66
      Height = 13
      Caption = 'Serial Number'
    end
    object Label4: TLabel
      Left = 24
      Top = 16
      Width = 81
      Height = 13
      Caption = 'Name (Company)'
    end
    object eName: TEdit
      Left = 24
      Top = 32
      Width = 385
      Height = 21
      TabOrder = 0
      Text = 'Your company name here ...'
    end
    object eComputerID: TEdit
      Left = 24
      Top = 88
      Width = 385
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object eSerialNumber: TEdit
      Left = 24
      Top = 149
      Width = 385
      Height = 21
      TabOrder = 2
    end
  end
end
