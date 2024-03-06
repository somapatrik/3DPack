object Form1: TForm1
  Left = 192
  Top = 107
  Width = 459
  Height = 362
  Caption = 'Cut 2D X example'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 144
    Top = 232
    Width = 72
    Height = 13
    Caption = 'Utilized surface'
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 300
    Height = 200
  end
  object Label7: TLabel
    Left = 336
    Top = 16
    Width = 68
    Height = 13
    Caption = 'Waste (L x W)'
  end
  object eUtilizedSurface: TEdit
    Left = 144
    Top = 248
    Width = 97
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object lbWaste: TListBox
    Left = 336
    Top = 32
    Width = 96
    Height = 161
    ItemHeight = 13
    TabOrder = 2
  end
  object sbIteration: TStatusBar
    Left = 0
    Top = 297
    Width = 451
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object bStart: TButton
    Left = 24
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 0
    OnClick = bStartClick
  end
  object MainMenu1: TMainMenu
    Left = 280
    Top = 240
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object Register1: TMenuItem
        Caption = 'Register ...'
        OnClick = Register1Click
      end
      object About1: TMenuItem
        Caption = 'About ...'
        OnClick = About1Click
      end
    end
  end
  object Optimization2DX1: TOptimization2DX
    AutoConnect = False
    ConnectKind = ckRunningOrNew
    OnFinish = Optimization2DX1Finish
    OnProgress = Optimization2DX1Progress
    Left = 320
    Top = 240
  end
end
