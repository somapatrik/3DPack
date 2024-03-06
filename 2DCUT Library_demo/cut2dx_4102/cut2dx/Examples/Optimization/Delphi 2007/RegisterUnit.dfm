object RegisterForm: TRegisterForm
  Left = 192
  Top = 107
  Width = 356
  Height = 259
  Caption = 'Register'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 24
    Top = 16
    Width = 28
    Height = 13
    Caption = 'Name'
  end
  object Label3: TLabel
    Left = 24
    Top = 72
    Width = 56
    Height = 13
    Caption = 'ComputerID'
  end
  object Label4: TLabel
    Left = 24
    Top = 128
    Width = 66
    Height = 13
    Caption = 'Serial Number'
  end
  object eName: TEdit
    Left = 24
    Top = 32
    Width = 313
    Height = 21
    TabOrder = 0
    Text = 'Your Company Name here ...'
  end
  object eComputerID: TEdit
    Left = 24
    Top = 88
    Width = 313
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object eSerialNumber: TEdit
    Left = 24
    Top = 144
    Width = 313
    Height = 21
    TabOrder = 2
  end
  object bRegister: TButton
    Left = 48
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Register'
    ModalResult = 1
    TabOrder = 3
  end
  object Button1: TButton
    Left = 232
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 4
  end
end
