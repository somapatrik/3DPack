object Form1: TForm1
  Left = 192
  Top = 107
  Caption = 'Cut 2D X example'
  ClientHeight = 382
  ClientWidth = 549
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 177
    Top = 286
    Width = 91
    Height = 16
    Caption = 'Utilized surface'
  end
  object Image1: TImage
    Left = 20
    Top = 20
    Width = 369
    Height = 246
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Label7: TLabel
    Left = 414
    Top = 20
    Width = 82
    Height = 16
    Caption = 'Waste (L x W)'
  end
  object eUtilizedSurface: TEdit
    Left = 177
    Top = 305
    Width = 120
    Height = 24
    ReadOnly = True
    TabOrder = 1
  end
  object lbWaste: TListBox
    Left = 414
    Top = 39
    Width = 118
    Height = 199
    TabOrder = 2
  end
  object sbIteration: TStatusBar
    Left = 0
    Top = 363
    Width = 549
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object bStart: TButton
    Left = 30
    Top = 295
    Width = 92
    Height = 31
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
    OnAfterManualArrange = Optimization2DX1AfterManualArrange
    Left = 320
    Top = 240
  end
end
