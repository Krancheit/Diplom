object FormParamSin: TFormParamSin
  Left = 0
  Top = 0
  Caption = 'FormParamSin'
  ClientHeight = 534
  ClientWidth = 412
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pgc1: TPageControl
    Left = 0
    Top = 0
    Width = 441
    Height = 497
    ActivePage = ts1
    TabOrder = 0
    object ts1: TTabSheet
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1095#1072#1089#1090#1086#1090
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object pnl2: TPanel
        Left = 3
        Top = 3
        Width = 398
        Height = 254
        TabOrder = 0
        object grpMaxFreq: TGroupBox
          Left = 8
          Top = 0
          Width = 378
          Height = 57
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object lblHz1: TLabel
            Left = 324
            Top = 28
            Width = 12
            Height = 13
            Caption = #1043#1094
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object TrackBarMaxFreq: TTrackBar
            Left = 29
            Top = 18
            Width = 244
            Height = 25
            Cursor = crHandPoint
            Max = 20
            Min = 11
            PageSize = 5
            Position = 11
            TabOrder = 0
            ThumbLength = 15
            TickMarks = tmTopLeft
            OnChange = TrackBarChange
          end
          object pnlMaxFreq: TPanel
            Left = 283
            Top = 25
            Width = 39
            Height = 18
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = 'xx.xx'
            Color = clWindow
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
        end
        object grpMinFreq: TGroupBox
          Left = 8
          Top = 63
          Width = 378
          Height = 57
          Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object lbl5: TLabel
            Left = 324
            Top = 28
            Width = 12
            Height = 13
            Caption = #1043#1094
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object TrackBarMinFreq: TTrackBar
            Left = 29
            Top = 18
            Width = 244
            Height = 25
            Cursor = crHandPoint
            Min = 5
            PageSize = 5
            Position = 5
            TabOrder = 0
            ThumbLength = 15
            TickMarks = tmTopLeft
            OnChange = TrackBarChange
          end
          object pnlMinFreq: TPanel
            Left = 279
            Top = 25
            Width = 39
            Height = 18
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = 'xx.xx'
            Color = clWindow
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
        end
        object grpDeltaFreq: TGroupBox
          Left = 8
          Top = 126
          Width = 378
          Height = 57
          Caption = #1057#1084#1077#1097#1077#1085#1080#1077' '#1095#1072#1089#1090#1086#1090#1099
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object lbl6: TLabel
            Left = 324
            Top = 28
            Width = 12
            Height = 13
            Caption = #1043#1094
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object TrackBarDeltaFreq: TTrackBar
            Left = 29
            Top = 18
            Width = 244
            Height = 25
            Cursor = crHandPoint
            Max = 4
            Min = 1
            PageSize = 5
            Position = 1
            TabOrder = 0
            ThumbLength = 15
            TickMarks = tmTopLeft
            OnChange = TrackBarChange
          end
          object pnlDeltaFreq: TPanel
            Left = 279
            Top = 25
            Width = 39
            Height = 18
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = 'xx.xx'
            Color = clWindow
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
        end
        object grpPeriod: TGroupBox
          Left = 8
          Top = 189
          Width = 378
          Height = 57
          Caption = #1055#1077#1088#1080#1086#1076' '#1087#1086#1089#1090#1086#1103#1085#1085#1086#1081' '#1095#1072#1089#1090#1086#1090#1099
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          object lbl7: TLabel
            Left = 324
            Top = 28
            Width = 19
            Height = 13
            Caption = #1057#1077#1082
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object TrackBarPeriod: TTrackBar
            Left = 29
            Top = 18
            Width = 244
            Height = 25
            Cursor = crHandPoint
            Max = 20
            Min = 2
            PageSize = 5
            Position = 2
            TabOrder = 0
            ThumbLength = 15
            TickMarks = tmTopLeft
            OnChange = TrackBarChange
          end
          object pnlPeriod: TPanel
            Left = 279
            Top = 25
            Width = 39
            Height = 18
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = 'xx.xx'
            Color = clWindow
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
        end
      end
    end
  end
  object btnOK: TButton
    Left = 223
    Top = 502
    Width = 75
    Height = 25
    Align = alCustom
    Caption = 'O&K'
    ModalResult = 1
    TabOrder = 1
    OnClick = btnOKClick
  end
  object btnCancel: TButton
    Left = 311
    Top = 502
    Width = 75
    Height = 25
    Align = alCustom
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 2
    OnClick = btnOKClick
  end
  object btnDefault: TButton
    Left = 8
    Top = 503
    Width = 75
    Height = 25
    Align = alCustom
    Caption = 'Default'
    TabOrder = 3
    OnClick = btnDefaultClick
  end
  object tmrApply: TTimer
    Left = 136
    Top = 472
  end
end
