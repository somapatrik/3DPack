object Form1: TForm1
  Left = 192
  Top = 107
  Width = 485
  Height = 480
  Caption = 'Cut 2D X example'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 336
    Top = 128
    Width = 80
    Height = 13
    Caption = 'Surface Covered'
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 300
    Height = 200
  end
  object Label6: TLabel
    Left = 144
    Top = 232
    Width = 108
    Height = 13
    Caption = 'Unused pieces (L x W)'
  end
  object Label5: TLabel
    Left = 8
    Top = 232
    Width = 97
    Height = 13
    Caption = 'Used Pieces (L x W)'
  end
  object Label7: TLabel
    Left = 280
    Top = 232
    Width = 68
    Height = 13
    Caption = 'Waste (L x W)'
  end
  object bStart: TButton
    Left = 336
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 0
    OnClick = bStartClick
  end
  object eSurfaceCovered: TEdit
    Left = 336
    Top = 144
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object lbUsedPieces: TListBox
    Left = 8
    Top = 248
    Width = 105
    Height = 155
    ItemHeight = 13
    TabOrder = 2
  end
  object lbUnusedPieces: TListBox
    Left = 144
    Top = 248
    Width = 105
    Height = 155
    ItemHeight = 13
    TabOrder = 3
  end
  object lbWaste: TListBox
    Left = 280
    Top = 248
    Width = 97
    Height = 153
    ItemHeight = 13
    TabOrder = 4
  end
  object sbIteration: TStatusBar
    Left = 0
    Top = 415
    Width = 477
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object MainMenu1: TMainMenu
    Left = 344
    Top = 184
    object File1: TMenuItem
      Caption = 'File'
      object Exiy1: TMenuItem
        Caption = 'Exit'
        OnClick = Exiy1Click
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
    Left = 376
    Top = 80
  end
end
