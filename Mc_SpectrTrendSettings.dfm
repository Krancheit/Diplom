object FormSpectrTrendSettings: TFormSpectrTrendSettings
  Left = 411
  Top = 225
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' '#1090#1088#1077#1085#1076#1072
  ClientHeight = 595
  ClientWidth = 400
  Color = clBtnFace
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
  object ButtonDefault: TButton
    Left = 31
    Top = 562
    Width = 75
    Height = 25
    Caption = '&'#1057#1090#1072#1085#1076#1072#1088#1090
    TabOrder = 0
    OnClick = ButtonDefaultClick
  end
  object ButtonOK: TButton
    Left = 230
    Top = 562
    Width = 75
    Height = 25
    Caption = 'O&K'
    ModalResult = 1
    TabOrder = 1
    OnClick = ButtonOKClick
  end
  object ButtonCancel: TButton
    Left = 311
    Top = 562
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 2
    OnClick = ButtonOKClick
  end
  object GroupBox7: TGroupBox
    Left = 392
    Top = 586
    Width = 96
    Height = 75
    Caption = 'GroupBox7'
    TabOrder = 3
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 3
    Width = 392
    Height = 553
    ActivePage = TabSheet1
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = #1041#1072#1079#1086#1074#1099#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object LabelScaleUnits: TLabel
        Left = 245
        Top = -2
        Width = 50
        Height = 13
        Caption = #1084#1082#1042'^2/'#1043#1094
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        Visible = False
      end
      object LabelMkv: TLabel
        Left = 307
        Top = -2
        Width = 21
        Height = 13
        Caption = #1084#1082#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        Visible = False
      end
      object GroupBoxCSA: TGroupBox
        Left = 3
        Top = 133
        Width = 367
        Height = 387
        Caption = ' '#1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1087#1077#1082#1090#1088#1072#1083#1100#1085#1086#1075#1086' '#1090#1088#1077#1085#1076#1072'  '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
        TabOrder = 4
        object GroupBox3: TGroupBox
          Left = 13
          Top = 330
          Width = 341
          Height = 47
          Caption = #1057#1087#1077#1082#1090#1088#1072#1083#1100#1085#1072#1103' '#1101#1085#1090#1088#1086#1087#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object Label6: TLabel
            Left = 10
            Top = 20
            Width = 136
            Height = 13
            Caption = #1064#1080#1088#1080#1085#1072' '#1086#1082#1085#1072' '#1089#1075#1083#1072#1078#1080#1074#1072#1085#1080#1103
          end
          object Label8: TLabel
            Left = 203
            Top = 20
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
          object PanelEntSmoothing: TPanel
            Left = 154
            Top = 18
            Width = 27
            Height = 18
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = '0.5'
            Color = clWindow
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object UpDownEntSmoothing: TUpDown
            Left = 184
            Top = 15
            Width = 13
            Height = 21
            Min = 1
            Max = 4
            Position = 4
            TabOrder = 1
            TabStop = True
            OnChangingEx = UpDownEntropySmoothingChangingEx
          end
        end
      end
      object GroupBoxTime: TGroupBox
        Left = 4
        Top = 10
        Width = 367
        Height = 55
        Caption = ' '#1042#1088#1077#1084#1077#1085#1085#1086#1081' '#1086#1090#1088#1077#1079#1086#1082' '#1085#1072' '#1087#1086#1083#1085#1086#1084' '#1101#1082#1088#1072#1085#1077' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
        TabOrder = 0
        object TrackBarTime: TTrackBar
          Left = 6
          Top = 18
          Width = 284
          Height = 25
          Cursor = crHandPoint
          Max = 100
          Min = 1
          PageSize = 5
          Frequency = 5
          Position = 1
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarTimeChange
        end
        object UpDownTime: TUpDown
          Left = 340
          Top = 23
          Width = 13
          Height = 21
          Min = 250
          Max = 450
          Position = 250
          TabOrder = 2
          TabStop = True
          OnChangingEx = UpDownTimeChangingEx
        end
        object PanelTime: TPanel
          Left = 293
          Top = 24
          Width = 46
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = '0:01:34'
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
      object GroupBoxFreq: TGroupBox
        Left = 16
        Top = 152
        Width = 342
        Height = 81
        Caption = ' '#1042#1099#1074#1086#1076#1080#1090#1100' '#1074' '#1087#1086#1083#1086#1089#1077' '#1095#1072#1089#1090#1086#1090'  '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object LabelHz: TLabel
          Left = 322
          Top = 57
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
        object LabelTo: TLabel
          Left = 10
          Top = 56
          Width = 24
          Height = 13
          Caption = #1044#1086'   '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelFrom: TLabel
          Left = 10
          Top = 28
          Width = 22
          Height = 13
          Caption = #1054#1090'   '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelHz1: TLabel
          Left = 322
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
        object TrackBarFreqTo: TTrackBar
          Left = 34
          Top = 46
          Width = 241
          Height = 25
          Cursor = crHandPoint
          Max = 40
          Min = 20
          PageSize = 5
          Position = 40
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarFreqToChange
        end
        object PanelFreqTo: TPanel
          Left = 277
          Top = 54
          Width = 25
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = '99'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object TrackBarFreqFrom: TTrackBar
          Left = 34
          Top = 18
          Width = 241
          Height = 25
          Cursor = crHandPoint
          Max = 40
          Min = 20
          PageSize = 5
          Position = 20
          TabOrder = 2
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarFreqFromChange
        end
        object PanelFreqFrom: TPanel
          Left = 277
          Top = 25
          Width = 25
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = '00'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object UpDownFrom: TUpDown
          Left = 305
          Top = 24
          Width = 13
          Height = 21
          Min = 250
          Max = 450
          Position = 250
          TabOrder = 4
          TabStop = True
          OnChangingEx = UpDownFromChangingEx
        end
        object UpDownTo: TUpDown
          Left = 305
          Top = 53
          Width = 13
          Height = 21
          Min = 250
          Max = 450
          Position = 250
          TabOrder = 5
          TabStop = True
          OnChangingEx = UpDownToChangingEx
        end
      end
      object GroupBoxColorScale: TGroupBox
        Left = 16
        Top = 237
        Width = 342
        Height = 117
        Caption = ' '#1062#1074#1077#1090#1085#1072#1103' '#1096#1082#1072#1083#1072' '#1076#1083#1103' '#1079#1085#1072#1095#1077#1085#1080#1081' '#1089#1087#1077#1082#1090#1088#1086#1074' '
        TabOrder = 2
        object LabelScaleMaximum: TLabel
          Left = 10
          Top = 17
          Width = 54
          Height = 13
          Caption = #1052#1072#1082#1089#1080#1084#1091#1084
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelScaleSensitivity: TLabel
          Left = 147
          Top = 17
          Width = 94
          Height = 13
          Caption = #1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelScaleGrades: TLabel
          Left = 284
          Top = 17
          Width = 48
          Height = 13
          Caption = #1043#1088#1072#1076#1072#1094#1080#1080
        end
        object EditScaleMaximum: TEdit
          Left = 10
          Top = 34
          Width = 88
          Height = 21
          TabStop = False
          ReadOnly = True
          TabOrder = 0
          Text = '100'
        end
        object ScaleMaximumUpDown: TUpDown
          Left = 99
          Top = 34
          Width = 13
          Height = 21
          Min = 50
          Max = 500
          Increment = 50
          Position = 100
          TabOrder = 1
          OnChangingEx = ScaleMaximumUpDownChangingEx
        end
        object SensitivityEdit: TEdit
          Left = 146
          Top = 34
          Width = 88
          Height = 21
          TabStop = False
          ReadOnly = True
          TabOrder = 2
          Text = '60'
        end
        object SensitivityUpDown: TUpDown
          Left = 235
          Top = 34
          Width = 13
          Height = 21
          Min = 1
          Max = 500
          Position = 1
          TabOrder = 3
          OnChangingEx = SensitivityUpDownChangingEx
        end
        object EditScaleGrades: TEdit
          Left = 283
          Top = 34
          Width = 30
          Height = 21
          TabStop = False
          ReadOnly = True
          TabOrder = 4
          Text = '256'
        end
        object UpDownScaleGrades: TUpDown
          Left = 315
          Top = 34
          Width = 13
          Height = 21
          Min = 1
          Max = 256
          Position = 256
          TabOrder = 5
          Wrap = True
          OnChangingEx = UpDownScaleGradesChangingEx
        end
        object RadioGroupTransform: TRadioGroup
          Left = 10
          Top = 60
          Width = 324
          Height = 50
          Caption = ' '#1055#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077' '#1076#1072#1085#1085#1099#1093'  '
          Columns = 3
          ItemIndex = 0
          Items.Strings = (
            #1053#1077#1090'  '
            #1050#1074'.  '#1082#1086#1088#1077#1085#1100'  '
            #1051#1086#1075#1072#1088#1080#1092#1084)
          TabOrder = 6
          OnClick = RadioGroupTransformClick
        end
      end
      object GroupBoxSEF: TGroupBox
        Left = 16
        Top = 359
        Width = 342
        Height = 98
        Caption = ' '#1043#1088#1072#1085#1080#1095#1085#1099#1077' '#1095#1072#1089#1090#1086#1090#1099' '#1089#1087#1077#1082#1090#1088#1072' ('#1043#1063#1057')  '
        TabOrder = 3
        object LabelSEFHi: TLabel
          Left = 8
          Top = 24
          Width = 75
          Height = 13
          Caption = #1042#1099#1089#1086#1082#1072#1103' '#1043#1063#1057'  '
        end
        object Label7: TLabel
          Left = 137
          Top = 24
          Width = 8
          Height = 13
          Caption = '%'
        end
        object Label9: TLabel
          Left = 137
          Top = 49
          Width = 8
          Height = 13
          Caption = '%'
        end
        object LabelSEFLo: TLabel
          Left = 8
          Top = 50
          Width = 67
          Height = 13
          Caption = #1057#1088#1077#1076#1085#1103#1103' '#1043#1063#1057
        end
        object LabelSEFFrqBand: TLabel
          Left = 184
          Top = 25
          Width = 142
          Height = 13
          AutoSize = False
          Caption = #1057#1095#1080#1090#1072#1090#1100' '#1087#1086' '#1087#1086#1083#1086#1089#1077'  '#1095#1072#1089#1090#1086#1090
        end
        object LabelFrom1: TLabel
          Left = 159
          Top = 47
          Width = 13
          Height = 13
          Caption = #1054#1090
        end
        object LabelHz2: TLabel
          Left = 230
          Top = 47
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
        object LabelTo1: TLabel
          Left = 253
          Top = 47
          Width = 17
          Height = 12
          AutoSize = False
          Caption = #1044#1086
        end
        object LabelHz3: TLabel
          Left = 316
          Top = 47
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
        object LabelInBand: TLabel
          Left = 170
          Top = 76
          Width = 65
          Height = 13
          AutoSize = False
          Caption = #1087#1086' '#1087#1086#1083#1086#1089#1077' '#1074
        end
        object LabelHz4: TLabel
          Left = 291
          Top = 75
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
        object EditSEFPercent1: TEdit
          Left = 88
          Top = 21
          Width = 30
          Height = 21
          TabStop = False
          ReadOnly = True
          TabOrder = 0
          Text = '99'
        end
        object UpDownSEFPercent1: TUpDown
          Left = 120
          Top = 20
          Width = 13
          Height = 21
          Min = 1
          Position = 1
          TabOrder = 1
          Wrap = True
          OnChangingEx = UpDownSEFPercent1ChangingEx
        end
        object UpDownSEFPercent2: TUpDown
          Left = 120
          Top = 46
          Width = 13
          Height = 21
          Min = 1
          Position = 1
          TabOrder = 2
          Wrap = True
          OnChangingEx = UpDownSEFPercent1ChangingEx
        end
        object EditSEFPercent2: TEdit
          Left = 88
          Top = 46
          Width = 30
          Height = 21
          TabStop = False
          ReadOnly = True
          TabOrder = 3
          Text = '99'
        end
        object PanelSEFFrom: TPanel
          Left = 184
          Top = 44
          Width = 27
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = '0.25'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
        object UpDownSEFFrom: TUpDown
          Left = 214
          Top = 43
          Width = 13
          Height = 21
          Max = 8
          Position = 8
          TabOrder = 5
          TabStop = True
          OnChangingEx = UpDownSEFFromChangingEx
        end
        object PanelSEFTo: TPanel
          Left = 270
          Top = 44
          Width = 27
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = '20.5'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
        end
        object UpDownSEFTo: TUpDown
          Left = 300
          Top = 43
          Width = 13
          Height = 21
          Max = 450
          Position = 250
          TabOrder = 7
          TabStop = True
          OnChangingEx = UpDownSEFToChangingEx
        end
        object CheckBoxSmoothing: TCheckBox
          Left = 38
          Top = 74
          Width = 140
          Height = 17
          Caption = #1057#1075#1083#1072#1078#1080#1074#1072#1085#1080#1077' '#1089#1087#1077#1082#1090#1088#1072
          TabOrder = 8
          OnClick = CheckBoxSmoothingClick
        end
        object PanelBandOf: TPanel
          Left = 245
          Top = 72
          Width = 27
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = '0.5'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
        end
        object UpDownBandOf: TUpDown
          Left = 274
          Top = 70
          Width = 13
          Height = 21
          Min = 1
          Max = 4
          Position = 4
          TabOrder = 10
          TabStop = True
          OnChangingEx = UpDownBandOfChangingEx
        end
      end
      object GroupBoxRelHeigh: TGroupBox
        Left = 4
        Top = 72
        Width = 367
        Height = 55
        Caption = #1042#1099#1089#1086#1090#1072' '#1089#1087#1077#1082#1090#1088#1072#1083#1100#1085#1086#1075#1086' '#1080' '#1072#1084#1087#1083#1080#1090#1091#1076#1085#1086#1075#1086' '#1090#1088#1077#1085#1076#1086#1074' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
        TabOrder = 5
        object LabelCSA: TLabel
          Left = 3
          Top = 26
          Width = 33
          Height = 13
          Caption = #1057#1087'. '#1090#1088'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelAmpTrend: TLabel
          Left = 323
          Top = 26
          Width = 41
          Height = 13
          Caption = #1040#1084#1087'. '#1090#1088'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object TrackBarRelHeight: TTrackBar
          Left = 40
          Top = 18
          Width = 277
          Height = 25
          Cursor = crHandPoint
          LineSize = 10
          Max = 100
          PageSize = 20
          Frequency = 10
          Position = 70
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarRelHeightChange
        end
      end
    end
    object TabSheetRA: TTabSheet
      Caption = #1040#1084#1087#1083#1080#1090#1091#1076#1085#1099#1081' '#1090#1088#1077#1085#1076
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox5: TGroupBox
        Left = 4
        Top = 10
        Width = 367
        Height = 241
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1090#1088#1077#1085#1076#1072' '#1072#1084#1087#1083#1080#1090#1091#1076
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
        TabOrder = 0
        object GroupBox10: TGroupBox
          Left = 12
          Top = 90
          Width = 342
          Height = 143
          Caption = #1063#1072#1089#1090#1086#1090#1085#1099#1077' '#1087#1086#1083#1086#1089#1099
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object PaintBoxBands: TPaintBox
            Left = 12
            Top = 107
            Width = 317
            Height = 23
            OnPaint = OnDrawRuler
          end
          object PaintBoxColorBar: TPaintBox
            Left = 12
            Top = 102
            Width = 317
            Height = 6
            OnPaint = OnDrawColorBar
          end
          object RadioButtonWholeBand: TRadioButton
            Left = 12
            Top = 24
            Width = 129
            Height = 25
            Caption = #1042#1089#1103' '#1087#1086#1083#1086#1089#1072' [0..20 '#1043#1094']'
            TabOrder = 0
            OnClick = OnBandsSchemeChange
          end
          object RadioButtonStandartBands: TRadioButton
            Left = 176
            Top = 24
            Width = 153
            Height = 25
            Caption = #1057#1090#1072#1085#1076#1072#1088#1090' ('#948', '#952', '#945', '#946')     '
            TabOrder = 1
            OnClick = OnBandsSchemeChange
          end
          object RadioButtonManual: TRadioButton
            Left = 12
            Top = 61
            Width = 113
            Height = 25
            Caption = #1053#1072#1089#1090#1088#1072#1080#1074#1072#1077#1084#1099#1081
            TabOrder = 2
            OnClick = OnBandsSchemeChange
          end
          object ButtonAdjustBands: TButton
            Left = 176
            Top = 61
            Width = 75
            Height = 25
            Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnClick = OnBandsClick
          end
        end
        object GroupBoxAmp: TGroupBox
          Left = 12
          Top = 21
          Width = 342
          Height = 61
          Caption = #1042#1080#1076
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object LabelMinScaleAmp: TLabel
            Left = 10
            Top = 15
            Width = 81
            Height = 13
            Caption = #1052#1080#1085'. '#1072#1084#1087#1083#1080#1090#1091#1076#1072
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object LabelMaxScaleAmp: TLabel
            Left = 146
            Top = 15
            Width = 87
            Height = 13
            Caption = #1052#1072#1082#1089'. '#1072#1084#1087#1083#1080#1090#1091#1076#1072
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object LabelScaleAmpGrades: TLabel
            Left = 284
            Top = 15
            Width = 48
            Height = 13
            Caption = #1043#1088#1072#1076#1072#1094#1080#1080
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object EditAmpScaleMin: TEdit
            Left = 10
            Top = 31
            Width = 88
            Height = 21
            TabStop = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 0
            Text = '5'
          end
          object UpDownAmpScaleMin: TUpDown
            Left = 99
            Top = 31
            Width = 13
            Height = 21
            Min = 3
            Max = 20
            Position = 5
            TabOrder = 1
            OnChangingEx = UpDownAmpScaleMinChangingEx
          end
          object EditAmpScaleMax: TEdit
            Left = 146
            Top = 31
            Width = 88
            Height = 21
            TabStop = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 2
            Text = '100'
          end
          object UpDownAmpScaleMax: TUpDown
            Left = 235
            Top = 31
            Width = 13
            Height = 21
            Min = 20
            Max = 150
            Increment = 10
            Position = 100
            TabOrder = 3
            OnChangingEx = UpDownAmpScaleMaxChangingEx
          end
          object EditAmpScaleGrades: TEdit
            Left = 283
            Top = 31
            Width = 30
            Height = 21
            TabStop = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            TabOrder = 4
            Text = '256'
          end
          object UpDownAmpScaleGrades: TUpDown
            Left = 315
            Top = 31
            Width = 13
            Height = 21
            Min = 1
            Max = 256
            Position = 256
            TabOrder = 5
            Wrap = True
            OnChangingEx = UpDownAmpScaleGradesChangingEx
          end
        end
      end
      object GroupBox6: TGroupBox
        Left = 4
        Top = 257
        Width = 367
        Height = 172
        Caption = #1058#1088#1077#1085#1076' '#1086#1090#1085#1086#1096#1077#1085#1080#1103' '#1101#1085#1077#1088#1075#1080#1081' '#1076#1080#1072#1087#1072#1079#1086#1085#1086#1074
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
        TabOrder = 1
        object GroupBox4: TGroupBox
          Left = 12
          Top = 92
          Width = 342
          Height = 69
          Caption = #1052#1072#1082#1089#1080#1084#1091#1084' '#1072#1084#1087#1083#1080#1090#1091#1076#1099' '#1085#1072' '#1101#1082#1088#1072#1085#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object TrackBarRAAmp: TTrackBar
            Left = 11
            Top = 35
            Width = 241
            Height = 25
            Cursor = crHandPoint
            Max = 40
            Min = 20
            PageSize = 5
            Position = 20
            TabOrder = 0
            ThumbLength = 15
            TickMarks = tmTopLeft
            OnChange = TrackBarMaxAmpChange
          end
          object PanelRAAmp: TPanel
            Left = 255
            Top = 42
            Width = 25
            Height = 18
            BevelInner = bvLowered
            BevelOuter = bvLowered
            Caption = '00'
            Color = clWindow
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
          object UpDownRAAmp: TUpDown
            Left = 281
            Top = 39
            Width = 13
            Height = 21
            Min = 250
            Max = 450
            Position = 250
            TabOrder = 2
            TabStop = True
            OnChangingEx = UpDownRAAmpChangeEx
          end
          object CheckBoxMaxAmpAutoAdjust: TCheckBox
            Left = 12
            Top = 20
            Width = 145
            Height = 17
            Caption = #1040#1074#1090#1086#1088#1077#1075#1091#1083#1080#1088#1086#1074#1082#1072
            TabOrder = 3
            OnClick = OnAutoAdjustClick
          end
        end
        object CheckBoxERTrend1: TCheckBox
          Left = 20
          Top = 30
          Width = 86
          Height = 17
          Caption = #948' - '#1080#1085#1076#1077#1082#1089' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = OnRAParamsChange
        end
        object ComboBoxERStyle1: TComboBox
          Left = 127
          Top = 28
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 2
          OnChange = OnRAParamsChange
        end
        object ButtonRatioSettings: TButton
          Left = 214
          Top = 61
          Width = 75
          Height = 25
          Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = OnERTrendBandsClick
        end
        object CheckBoxERTrend2: TCheckBox
          Left = 214
          Top = 26
          Width = 65
          Height = 25
          Caption = #945' / '#946'   '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = OnRAParamsChange
        end
        object ComboBoxERStyle2: TComboBox
          Left = 277
          Top = 28
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 5
          OnClick = OnRAParamsChange
        end
        object CheckBoxERTrend3: TCheckBox
          Left = 20
          Top = 61
          Width = 101
          Height = 25
          Caption = #1053#1072#1089#1090#1088#1072#1080#1074#1072#1077#1084#1099#1081
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnClick = OnRAParamsChange
        end
        object ComboBoxERStyle3: TComboBox
          Left = 127
          Top = 64
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 7
          OnClick = OnRAParamsChange
        end
      end
    end
    object TabSheetView: TTabSheet
      Caption = #1042#1080#1076
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBoxHigherSEF: TGroupBox
        Left = 3
        Top = 441
        Width = 367
        Height = 78
        Caption = #1055#1088#1086#1095#1077#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object CheckBoxHigherSEF: TCheckBox
          Left = 10
          Top = 26
          Width = 249
          Height = 17
          Caption = #1054#1073#1088#1077#1079#1072#1090#1100' '#1089#1087#1077#1082#1090#1088' '#1074#1099#1096#1077' '#1074#1099#1089#1086#1082#1086#1081' '#1043#1063#1057
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBoxClick
        end
        object CheckBoxCutAmpTrend: TCheckBox
          Left = 10
          Top = 49
          Width = 321
          Height = 25
          Caption = #1054#1073#1088#1077#1079#1072#1090#1100' '#1072#1084#1087#1083'. '#1090#1088#1077#1085#1076' '#1074#1099#1096#1077' '#1077#1075#1086' '#1076#1086#1083#1080' '#1086#1090' '#1086#1073#1097#1077#1081' '#1101#1085#1077#1088#1075#1080#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = OnRAParamsChange
        end
      end
      object GroupBoxSEFTrends: TGroupBox
        Left = 3
        Top = 12
        Width = 367
        Height = 54
        Caption = #1058#1088#1077#1085#1076#1099' '#1075#1088#1072#1085#1080#1095#1085#1099#1093' '#1095#1072#1089#1090#1086#1090' '#1089#1087#1077#1082#1090#1088#1086#1074'  ('#1043#1063#1057') '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object CheckBoxSEF1: TCheckBox
          Left = 10
          Top = 24
          Width = 90
          Height = 17
          Caption = #1042#1099#1089#1086#1082#1072#1103' '#1043#1063#1057
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBoxClick
        end
        object CheckBoxSEF2: TCheckBox
          Left = 220
          Top = 24
          Width = 90
          Height = 17
          Caption = #1057#1088#1077#1076#1085#1103#1103' '#1043#1063#1057
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = CheckBoxClick
        end
        object ComboBoxLineSEF1: TComboBox
          Left = 100
          Top = 21
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 2
        end
        object ComboBoxLineSEF2: TComboBox
          Left = 310
          Top = 21
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 3
        end
      end
      object GroupBoxPeaks: TGroupBox
        Left = 3
        Top = 72
        Width = 367
        Height = 54
        Caption = #1058#1088#1077#1085#1076#1099' '#1084#1072#1082#1089#1080#1084#1091#1084#1072' '#1080' '#1074#1090#1086#1088#1086#1075#1086' '#1087#1080#1082#1072' '#1089#1087#1077#1082#1090#1088#1086#1074
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object CheckBoxPeakMain: TCheckBox
          Left = 10
          Top = 24
          Width = 90
          Height = 17
          Caption = #1052#1072#1082#1089#1080#1084#1091#1084' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBoxClick
        end
        object CheckBoxPeakSecondary: TCheckBox
          Left = 220
          Top = 24
          Width = 90
          Height = 17
          Caption = #1042#1090#1086#1088#1086#1081' '#1087#1080#1082
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = CheckBoxClick
        end
        object ComboBoxLinePeakMain: TComboBox
          Left = 100
          Top = 21
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 2
        end
        object ComboBoxLinePeakSecondary: TComboBox
          Left = 310
          Top = 21
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 3
        end
      end
      object GroupBoxIndicators: TGroupBox
        Left = 3
        Top = 326
        Width = 367
        Height = 108
        Caption = #1055#1072#1085#1077#1083#1100' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1086#1074
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        object CheckBoxIndicators: TCheckBox
          Left = 10
          Top = 39
          Width = 70
          Height = 17
          Caption = #1042#1082#1083#1102#1095#1077#1085#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBoxIndicatorsClick
        end
        object GroupBoxDigits: TGroupBox
          Left = 110
          Top = 13
          Width = 244
          Height = 88
          Caption = #1042#1099#1074#1086#1076#1080#1090#1100' '#1094#1080#1092#1088#1086#1074#1099#1077' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1099
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object CheckBoxDSEF1: TCheckBox
            Left = 8
            Top = 20
            Width = 99
            Height = 17
            Caption = #1042#1099#1089#1086#1082#1072#1103' '#1043#1063#1057
            TabOrder = 0
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDSEF2: TCheckBox
            Left = 126
            Top = 20
            Width = 95
            Height = 17
            Caption = #1057#1088#1077#1076#1085#1103#1103' '#1043#1063#1057
            TabOrder = 1
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDMax: TCheckBox
            Left = 8
            Top = 43
            Width = 95
            Height = 17
            Caption = #1052#1072#1082#1089#1080#1084#1091#1084
            TabOrder = 2
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDEntropy: TCheckBox
            Left = 126
            Top = 43
            Width = 94
            Height = 17
            Caption = #1069#1085#1090#1088#1086#1087#1080#1103
            TabOrder = 3
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDTotalAmp: TCheckBox
            Left = 8
            Top = 66
            Width = 94
            Height = 17
            Caption = #1042#1089#1103' '#1072#1084#1087#1083#1080#1090#1091#1076#1072
            TabOrder = 4
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDDeltaIndex: TCheckBox
            Left = 126
            Top = 66
            Width = 94
            Height = 17
            Caption = #948' - '#1080#1085#1076#1077#1082#1089'  '
            TabOrder = 5
            OnClick = CheckBoxIndicatorsClick
          end
        end
      end
      object GroupBoxRulers: TGroupBox
        Left = 3
        Top = 200
        Width = 367
        Height = 119
        Caption = #1051#1080#1085#1077#1081#1082#1080' '#1080' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        object LabelRuler: TLabel
          Left = 10
          Top = 19
          Width = 73
          Height = 13
          Caption = #1063#1072#1089#1090'. '#1083#1080#1085#1077#1081#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelBand: TLabel
          Left = 10
          Top = 69
          Width = 96
          Height = 13
          Caption = #1048#1085#1076#1080#1082#1072#1090#1086#1088#1099' '#1087#1086#1083#1086#1089
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label1: TLabel
          Left = 10
          Top = 44
          Width = 111
          Height = 13
          Caption = #1051#1080#1085#1077#1081#1082#1080' '#1086#1090#1085'. '#1101#1085#1077#1088#1075#1080#1081
        end
        object Label4: TLabel
          Left = 10
          Top = 93
          Width = 82
          Height = 13
          Caption = #1062#1074#1077#1090#1085#1099#1077' '#1096#1082#1072#1083#1099
        end
        object CheckBoxScaleLeft: TCheckBox
          Left = 136
          Top = 18
          Width = 62
          Height = 17
          Caption = #1057#1083#1077#1074#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBoxClick
        end
        object CheckBoxBandLeft: TCheckBox
          Left = 136
          Top = 68
          Width = 62
          Height = 17
          Caption = #1057#1083#1077#1074#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = CheckBoxClick
        end
        object CheckBoxScaleRight: TCheckBox
          Left = 268
          Top = 18
          Width = 57
          Height = 17
          Caption = #1057#1087#1088#1072#1074#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = CheckBoxClick
        end
        object CheckBoxBandRight: TCheckBox
          Left = 268
          Top = 68
          Width = 57
          Height = 17
          Caption = #1057#1087#1088#1072#1074#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = CheckBoxClick
        end
        object CheckBoxRARulerLeft: TCheckBox
          Left = 136
          Top = 43
          Width = 62
          Height = 17
          Caption = #1057#1083#1077#1074#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = OnRAParamsChange
        end
        object CheckBoxRARulerRight: TCheckBox
          Left = 268
          Top = 43
          Width = 57
          Height = 17
          Caption = #1057#1087#1088#1072#1074#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          OnClick = OnRAParamsChange
        end
        object CheckBoxScalePanel: TCheckBox
          Left = 136
          Top = 92
          Width = 97
          Height = 17
          Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnClick = CheckBoxClick
        end
      end
      object GroupBox8: TGroupBox
        Left = 3
        Top = 134
        Width = 367
        Height = 57
        Caption = #1058#1088#1077#1085#1076' '#1089#1087#1077#1082#1090#1088#1072#1083#1100#1085#1086#1081' '#1101#1085#1090#1088#1086#1087#1080#1080
        TabOrder = 5
        object CheckBoxEntropy: TCheckBox
          Left = 10
          Top = 24
          Width = 90
          Height = 17
          Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBoxClick
        end
        object ComboBoxLineEntropy: TComboBox
          Left = 100
          Top = 22
          Width = 45
          Height = 22
          Style = csOwnerDrawFixed
          TabOrder = 1
        end
      end
    end
    object TabSheetSpectra: TTabSheet
      Caption = #1057#1087#1077#1082#1090#1088#1099
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object LabelUseInterval: TLabel
        Left = 23
        Top = 3
        Width = 3
        Height = 13
      end
      object GroupBox1: TGroupBox
        Left = 4
        Top = 8
        Width = 368
        Height = 87
        Caption = #1042#1088#1077#1084#1077#1085#1085#1086#1081' '#1080#1085#1090#1077#1088#1074#1072#1083' '#1076#1083#1103' '#1086#1076#1085#1086#1075#1086' '#1089#1087#1077#1082#1090#1088#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object Label3: TLabel
          Left = 336
          Top = 26
          Width = 6
          Height = 13
          Caption = #1089
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 3
          Top = 56
          Width = 92
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = '   '#1055#1077#1088#1077#1089#1077#1095#1077#1085#1080#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelAlphaSec: TLabel
          Left = 248
          Top = 56
          Width = 29
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = '99.9'
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
        end
        object LabelSecP: TLabel
          Left = 281
          Top = 56
          Width = 21
          Height = 13
          Caption = #1089#1077#1082')'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelRecalc: TLabel
          Left = 168
          Top = 56
          Width = 69
          Height = 13
          Caption = '('#1057#1095#1077#1090' '#1082#1072#1078#1076#1099#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object TrackBarPrimTime: TTrackBar
          Left = 6
          Top = 18
          Width = 273
          Height = 25
          Cursor = crHandPoint
          Max = 100
          Min = 1
          Frequency = 5
          Position = 1
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarPrimTimeChange
        end
        object UpDownPrimTime: TUpDown
          Left = 317
          Top = 23
          Width = 13
          Height = 21
          Min = 250
          Max = 450
          Position = 250
          TabOrder = 1
          OnChangingEx = UpDownPrimTimeChangingEx
        end
        object PanelPrimTime: TPanel
          Left = 283
          Top = 24
          Width = 30
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Color = clWindow
          TabOrder = 2
        end
        object EditAlpha: TEdit
          Left = 99
          Top = 53
          Width = 28
          Height = 21
          TabStop = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '0.5'
        end
        object UpDownAlpha: TUpDown
          Left = 131
          Top = 53
          Width = 13
          Height = 21
          Max = 99
          Increment = 50
          Position = 99
          TabOrder = 4
          OnChangingEx = UpDownAlphaChangingEx
        end
      end
      object GroupBox2: TGroupBox
        Left = 4
        Top = 107
        Width = 368
        Height = 83
        Caption = #1059#1089#1088#1077#1076#1085#1077#1085#1080#1077' '#1089#1086#1089#1077#1076#1085#1080#1093' '#1089#1087#1077#1082#1090#1088#1086#1074
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object LabelWindow: TLabel
          Left = 14
          Top = 27
          Width = 71
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = #1058#1080#1087' '#1086#1082#1085#1072
        end
        object Label5: TLabel
          Left = 195
          Top = 27
          Width = 87
          Height = 13
          AutoSize = False
          Caption = #1063#1080#1089#1083#1086' '#1089#1087#1077#1082#1090#1088#1086#1074
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelNoAveraging: TLabel
          Left = 19
          Top = 40
          Width = 132
          Height = 13
          AutoSize = False
          Caption = #1041#1077#1079' '#1091#1089#1088#1077#1076#1085#1077#1085#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object LabelSegmentValue: TLabel
          Left = 245
          Top = 59
          Width = 29
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = '99.9'
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
        end
        object LabelSec3: TLabel
          Left = 278
          Top = 59
          Width = 18
          Height = 13
          Caption = #1089#1077#1082
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelSegment: TLabel
          Left = 30
          Top = 59
          Width = 217
          Height = 13
          AutoSize = False
          Caption = #1069#1087#1086#1093#1072' '#1089#1080#1075#1085#1072#1083#1072' '#1076#1083#1103' '#1091#1089#1088#1077#1076#1085#1077#1085#1085#1086#1075#1086' '#1089#1087#1077#1082#1090#1088#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object ComboBoxWindow: TComboBox
          Left = 88
          Top = 23
          Width = 80
          Height = 21
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnChange = ComboBoxWindowChange
          Items.Strings = (
            #1058#1088#1077#1091#1075#1086#1083#1100#1085#1086#1077
            #1041#1083#1101#1082#1084#1077#1085)
        end
        object PanelNSp: TPanel
          Left = 283
          Top = 25
          Width = 30
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object UpDownNSp: TUpDown
          Left = 317
          Top = 23
          Width = 13
          Height = 21
          Max = 5
          TabOrder = 2
          OnChangingEx = UpDownNSpChangingEx
        end
      end
      object GroupBoxSpectrumEstimator: TGroupBox
        Left = 4
        Top = 203
        Width = 368
        Height = 136
        Caption = #1057#1087#1077#1082#1090#1088#1072#1083#1100#1085#1072#1103' '#1086#1094#1077#1085#1082#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object LabelAROrder: TLabel
          Left = 292
          Top = 92
          Width = 61
          Height = 13
          Caption = #1055#1086#1088#1103#1076#1086#1082' '#1040#1056
        end
        object LabelSec: TLabel
          Left = 334
          Top = 109
          Width = 18
          Height = 13
          Caption = #1089#1077#1082
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelCorrWindow: TLabel
          Left = 292
          Top = 33
          Width = 65
          Height = 13
          Caption = #1050#1086#1088#1088'. "'#1086#1082#1085#1086'"'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelSec1: TLabel
          Left = 334
          Top = 52
          Width = 18
          Height = 13
          Caption = #1089#1077#1082
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object RadioButtonPeriodogram: TRadioButton
          Left = 14
          Top = 25
          Width = 193
          Height = 12
          Caption = #1057#1075#1083#1072#1078#1077#1085#1085#1072#1103' '#1087#1077#1088#1080#1086#1076#1086#1075#1088#1072#1084#1084#1072
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = True
          OnClick = RadioButtonPeriodogramClick
        end
        object RadioButtonAutoregressive: TRadioButton
          Left = 14
          Top = 81
          Width = 200
          Height = 12
          Caption = #1040#1074#1090#1086#1088#1077#1075#1088#1077#1089#1089#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = RadioButtonPeriodogramClick
        end
        object TrackBarAROrder: TTrackBar
          Left = 6
          Top = 99
          Width = 280
          Height = 25
          Cursor = crHandPoint
          Max = 100
          PageSize = 5
          Frequency = 5
          TabOrder = 2
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarCorrWindowChange
        end
        object PanelAROrder: TPanel
          Left = 290
          Top = 106
          Width = 41
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = ' xx.xx'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object TrackBarCorrWindow: TTrackBar
          Left = 6
          Top = 40
          Width = 280
          Height = 25
          Cursor = crHandPoint
          Max = 100
          PageSize = 5
          Frequency = 5
          TabOrder = 4
          ThumbLength = 15
          TickMarks = tmTopLeft
          OnChange = TrackBarCorrWindowChange
        end
        object PanelCorrWindow: TPanel
          Left = 290
          Top = 48
          Width = 41
          Height = 18
          BevelInner = bvLowered
          BevelOuter = bvLowered
          Caption = ' xx.xx'
          Color = clWindow
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
        end
      end
      object ButtonApply: TButton
        Left = 293
        Top = 350
        Width = 75
        Height = 25
        Caption = '&'#1055#1088#1080#1084#1077#1085#1080#1090#1100
        Enabled = False
        TabOrder = 3
        OnClick = ButtonOKClick
      end
    end
  end
  object MultiLang1: TMultiLang
    Items = <
      item
        Component = ButtonCancel
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cancel'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1090#1084#1077#1085#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Annulla'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Annuler'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'L'#1094's&chen'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cerrar'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cancel'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = ButtonOK
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'O&K'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = ButtonDefault
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Default'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&'#1057#1090#1072#1085#1076#1072#1088#1090
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Predefinita'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&D'#1080'faut'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Standard'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Predefinido'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Default'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = Owner
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectral trends settings'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' '#1090#1088#1077#1085#1076#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Impostazione trend spettrali'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Settings for spectrums'#39' trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Settings for spectrums'#39' trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Settings for spectrums'#39' trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Settings for spectrums'#39' trend'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end>
    Languages.Strings = (
      'English'
      'Russian'
      'Italian'
      'French'
      'German'
      'Spanish'
      'Polish')
    CurrentLang = 'Russian'
    StringItems.LangCount = 7
    StringItems = <>
    Left = 116
    Top = 541
  end
  object TimerApply: TTimer
    Enabled = False
    Interval = 200
    OnTimer = TimerApplyTimer
    Left = 151
    Top = 540
  end
end
