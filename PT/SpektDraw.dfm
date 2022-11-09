object FormSpectrTrend: TFormSpectrTrend
  Left = 343
  Top = 450
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'FormSpectrTrend'
  ClientHeight = 604
  ClientWidth = 984
  Color = clBtnFace
  Constraints.MaxWidth = 1000
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 984
    Height = 577
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 577
    Width = 984
    Height = 27
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Label5: TLabel
      Left = 396
      Top = 13
      Width = 5
      Height = 13
      Caption = 's'
    end
    object LabelToTime: TLabel
      Left = 374
      Top = 13
      Width = 18
      Height = 13
      Caption = '111'
    end
    object Label6: TLabel
      Left = 360
      Top = 13
      Width = 9
      Height = 13
      Caption = 'to'
    end
    object Label4: TLabel
      Left = 337
      Top = 13
      Width = 5
      Height = 13
      Caption = 's'
    end
    object LabelFromTime: TLabel
      Left = 312
      Top = 13
      Width = 18
      Height = 13
      Caption = '000'
    end
    object Label1: TLabel
      Left = 180
      Top = 13
      Width = 128
      Height = 13
      Caption = 'Trends for time period from:'
    end
    object EditTime: TEdit
      Left = 132
      Top = 6
      Width = 33
      Height = 21
      TabOrder = 4
      Text = 'xx.xx'
    end
    object ButtonFastFwd: TButton
      Left = 97
      Top = 6
      Width = 25
      Height = 20
      Caption = '>>'
      TabOrder = 2
      OnClick = ButtonFwdClick
    end
    object ButtonFwd: TButton
      Left = 66
      Top = 6
      Width = 25
      Height = 20
      Caption = '>'
      TabOrder = 0
      OnClick = ButtonFwdClick
    end
    object ButtonRew: TButton
      Left = 36
      Top = 6
      Width = 25
      Height = 20
      Caption = '<'
      TabOrder = 1
      OnClick = ButtonFwdClick
    end
    object ButtonFastRew: TButton
      Left = 4
      Top = 6
      Width = 25
      Height = 20
      Caption = '<<'
      TabOrder = 3
      OnClick = ButtonFwdClick
    end
  end
end
