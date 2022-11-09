object FormSpectrTrendSettings: TFormSpectrTrendSettings
  Left = 487
  Top = 203
  BorderStyle = bsDialog
  Caption = 'Spectral trends settings'
  ClientHeight = 595
  ClientWidth = 400
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonDefault: TButton
    Left = 31
    Top = 562
    Width = 75
    Height = 25
    Caption = '&Default'
    TabOrder = 0
    OnClick = ButtonDefaultClick
  end
  object ButtonOK: TButton
    Left = 223
    Top = 565
    Width = 75
    Height = 25
    Caption = 'O&K'
    ModalResult = 1
    TabOrder = 1
    OnClick = ButtonOKClick
  end
  object ButtonCancel: TButton
    Left = 311
    Top = 565
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
    OnClick = ButtonOKClick
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 3
    Width = 392
    Height = 553
    ActivePage = TabSheetView
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = 'Common'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object LabelScaleUnits: TLabel
        Left = 245
        Top = -2
        Width = 43
        Height = 13
        Caption = #181'V^2/Hz'
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
        Width = 13
        Height = 13
        Caption = #181'V'
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
        Caption = 'CSA parameters '
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
          Caption = 'Specrtal entropy'
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
            Width = 117
            Height = 13
            Caption = 'Smoothing window width'
          end
          object Label8: TLabel
            Left = 203
            Top = 20
            Width = 13
            Height = 13
            Caption = 'Hz'
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
        Caption = 'Length of time segment on screen  '
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
        Caption = ' View in frequency band  '
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
          Width = 13
          Height = 13
          Caption = 'Hz'
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
          Width = 13
          Height = 13
          Caption = 'To'
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
          Width = 23
          Height = 13
          Caption = 'From'
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
          Width = 13
          Height = 13
          Caption = 'Hz'
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
        Caption = 'Color scale for spectrum values '
        TabOrder = 2
        object LabelScaleMaximum: TLabel
          Left = 10
          Top = 17
          Width = 44
          Height = 13
          Caption = 'Maximum'
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
          Width = 47
          Height = 13
          Caption = 'Sensitivity'
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
          Width = 34
          Height = 13
          Caption = 'Grades'
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
          Caption = ' Data transform '
          Columns = 3
          ItemIndex = 0
          Items.Strings = (
            'None '
            'Square root '
            'Logarythm')
          TabOrder = 6
          OnClick = RadioGroupTransformClick
        end
      end
      object GroupBoxSEF: TGroupBox
        Left = 16
        Top = 359
        Width = 342
        Height = 98
        Caption = 'Spectrum edge frequencies (SEF)  '
        TabOrder = 3
        object LabelSEFHi: TLabel
          Left = 8
          Top = 24
          Width = 48
          Height = 13
          Caption = 'High SEF '
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
          Width = 54
          Height = 13
          Caption = 'Middle SEF'
        end
        object LabelSEFFrqBand: TLabel
          Left = 184
          Top = 25
          Width = 142
          Height = 13
          AutoSize = False
          Caption = 'Calculate in frequency band '
        end
        object LabelFrom1: TLabel
          Left = 159
          Top = 47
          Width = 23
          Height = 13
          Caption = 'From'
        end
        object LabelHz2: TLabel
          Left = 230
          Top = 47
          Width = 13
          Height = 13
          Caption = 'Hz'
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
          Caption = 'To'
        end
        object LabelHz3: TLabel
          Left = 316
          Top = 47
          Width = 13
          Height = 13
          Caption = 'Hz'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelInBand: TLabel
          Left = 167
          Top = 76
          Width = 65
          Height = 13
          AutoSize = False
          Caption = 'over band of'
        end
        object LabelHz4: TLabel
          Left = 291
          Top = 75
          Width = 13
          Height = 13
          Caption = 'Hz'
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
          Caption = 'Smoothing of spectrum '
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
        Caption = 'Height of CSA trend and amplitudes trend '
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
          Width = 21
          Height = 13
          Caption = 'CSA'
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
          Width = 24
          Height = 13
          Caption = 'Amp.'
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
      Caption = 'Amplitude trend'
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
        Caption = 'Relative amplitude trend'
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
          Caption = 'Frequency bands'
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
            Caption = 'Whole band [0..20 Hz]'
            TabOrder = 0
            OnClick = OnBandsSchemeChange
          end
          object RadioButtonStandartBands: TRadioButton
            Left = 176
            Top = 24
            Width = 153
            Height = 25
            Caption = 'Standart bands ('#948', '#952', '#945', '#946')     '
            TabOrder = 1
            OnClick = OnBandsSchemeChange
          end
          object RadioButtonManual: TRadioButton
            Left = 12
            Top = 61
            Width = 113
            Height = 25
            Caption = 'Manual'
            TabOrder = 2
            OnClick = OnBandsSchemeChange
          end
          object ButtonAdjustBands: TButton
            Left = 176
            Top = 61
            Width = 75
            Height = 25
            Caption = 'Adjust'
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
          Caption = 'View'
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
            Width = 68
            Height = 13
            Caption = 'Min. amplitude'
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
            Width = 74
            Height = 13
            Caption = 'Max. amplitude '
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
            Width = 34
            Height = 13
            Caption = 'Grades'
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
        Caption = 'Energy ratio trend'
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
          Caption = 'Maximum amplitude on screen'
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
            Caption = 'Auto adjust'
            TabOrder = 3
            OnClick = OnAutoAdjustClick
          end
        end
        object CheckBoxERTrend1: TCheckBox
          Left = 20
          Top = 30
          Width = 86
          Height = 17
          Caption = #948' - index  '
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
          Caption = 'Adjust'
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
          Caption = 'User'
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
      Caption = 'View'
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
        Caption = 'Misc'
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
          Caption = 'Cut CSA higher than high SEF'
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
          Caption = 'Cut amplitude trend above its part of total energy'
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
        Caption = 'Trends of  spectrum edge frequencies  (SEF) '
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
          Caption = 'High SEF '
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
          Caption = 'Middle SEF'
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
        Caption = 'Trends of maximum and second peak of spectra'
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
          Caption = 'Maximum '
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
          Caption = 'Second peak '
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
        Caption = 'Panel of indicators '
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
          Caption = 'Enabled'
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
          Caption = 'Display also digital Indicators '
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
            Caption = 'High SEF'
            TabOrder = 0
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDSEF2: TCheckBox
            Left = 126
            Top = 20
            Width = 95
            Height = 17
            Caption = 'Middle SEF'
            TabOrder = 1
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDMax: TCheckBox
            Left = 8
            Top = 43
            Width = 95
            Height = 17
            Caption = 'Maximum'
            TabOrder = 2
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDEntropy: TCheckBox
            Left = 126
            Top = 43
            Width = 94
            Height = 17
            Caption = 'Entropy'
            TabOrder = 3
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDTotalAmp: TCheckBox
            Left = 8
            Top = 66
            Width = 94
            Height = 17
            Caption = 'Total amplitude'
            TabOrder = 4
            OnClick = CheckBoxIndicatorsClick
          end
          object CheckBoxDDeltaIndex: TCheckBox
            Left = 126
            Top = 66
            Width = 94
            Height = 17
            Caption = #948' - index   '
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
        Caption = 'Rulers and indicators'
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
          Width = 49
          Height = 13
          Caption = 'CSA rulers'
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
          Width = 90
          Height = 13
          Caption = 'Indicators of bands'
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
          Width = 82
          Height = 13
          Caption = 'Rel. energy rulers'
        end
        object Label4: TLabel
          Left = 10
          Top = 93
          Width = 64
          Height = 13
          Caption = 'Colored scale'
        end
        object CheckBoxScaleLeft: TCheckBox
          Left = 136
          Top = 18
          Width = 62
          Height = 17
          Caption = 'Left '
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
          Caption = 'Left'
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
          Caption = 'Right'
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
          Caption = 'Right'
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
          Caption = 'Left '
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
          Caption = 'Right'
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
          Caption = 'Display'
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
        Caption = 'Spectrum entropy trend'
        TabOrder = 5
        object CheckBoxEntropy: TCheckBox
          Left = 10
          Top = 24
          Width = 90
          Height = 17
          Caption = 'Display'
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
      Caption = 'Spectra'
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
        Caption = 'Time Interval for one spectrum '
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
          Width = 5
          Height = 13
          Caption = 's'
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
          Caption = '   Intersection '
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
          Width = 8
          Height = 13
          Caption = 's)'
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
          Width = 79
          Height = 13
          Caption = '(Calculate every '
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
        Caption = 'Averaging of neighbour spectra '
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
          Caption = 'Window'
        end
        object Label5: TLabel
          Left = 195
          Top = 27
          Width = 87
          Height = 13
          AutoSize = False
          Caption = 'Used spectra'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object LabelNoAveraging: TLabel
          Left = 19
          Top = 27
          Width = 127
          Height = 13
          AutoSize = False
          Caption = 'No averaging'
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
          Width = 5
          Height = 13
          Caption = 's'
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
          Caption = 'Signal epoch for an averaged spectrum:'
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
            'Triangular'
            'Blackman')
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
        Caption = 'Spectrum estimator '
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
          Width = 42
          Height = 13
          Caption = 'AR order'
        end
        object LabelSec: TLabel
          Left = 334
          Top = 109
          Width = 5
          Height = 13
          Caption = 's'
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
          Width = 71
          Height = 13
          Caption = 'Corr. "window"'
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
          Width = 5
          Height = 13
          Caption = 's'
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
          Caption = 'Smoothed periodogram'
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
          Caption = 'Autoregression '
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
        Caption = '&Apply'
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
        Component = GroupBoxFreq
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' View in frequency band  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '#1042#1099#1074#1086#1076#1080#1090#1100' '#1074' '#1087#1086#1083#1086#1089#1077' '#1095#1072#1089#1090#1086#1090'  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Frequenza (asse verticale) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Fr'#1081'quence (axe verticale) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Frequenz (vertikale achse) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Frecuencia (eje vertical) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Frequency band  '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = GroupBoxTime
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Length of time segment on screen  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '#1042#1088#1077#1084#1077#1085#1085#1086#1081' '#1086#1090#1088#1077#1079#1086#1082' '#1085#1072' '#1087#1086#1083#1085#1086#1084' '#1101#1082#1088#1072#1085#1077' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Intervallo temporale (asse orizzontale) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Intervalle de Temp (axe horizontale)'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Zeitintervall (Horizontale achse) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Intervalo de tiempo (eje horizontal) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Length of time segment on screen  '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = TabSheet1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Common'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1041#1072#1079#1086#1074#1099#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Parametri generali'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Param'#1080'trer g'#1081'n'#1081'raux Trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Trend parameter'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Par'#1073'metros generales trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Base parameters '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = TabSheetView
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1080#1076
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Visualizza'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectres'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spektren'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Espectros'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectrums'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelFrom
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'From'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1090'   '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Da'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'De'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Von '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'De'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'From'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelHz
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelHz1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelTo
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'To'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1044#1086'   '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'A'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'A'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Zu  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'A'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'To'
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
      end
      item
        Component = LabelScaleUnits
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V^2/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1084#1082#1042'^2/'#1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V^2/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'mkV^2/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'mkV^2/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'mkV^2/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'uV^2/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = GroupBoxColorScale
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Color scale for spectrum values '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '#1062#1074#1077#1090#1085#1072#1103' '#1096#1082#1072#1083#1072' '#1076#1083#1103' '#1079#1085#1072#1095#1077#1085#1080#1081' '#1089#1087#1077#1082#1090#1088#1086#1074' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Scala colori per valori spettrali '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Color scale for spectrums'#39' values '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Color scale for spectrums'#39' values '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Color scale for spectrums'#39' values '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Color scale for spectrums'#39' values '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelScaleMaximum
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1072#1082#1089#1080#1084#1091#1084
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Massimo'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelScaleSensitivity
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sensitivity'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sensibilit'#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sensitivity'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sensitivity'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sensitivity'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sensitivity'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelScaleGrades
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1088#1072#1076#1072#1094#1080#1080
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Livelli'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = TabSheetRA
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amplitude trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1040#1084#1087#1083#1080#1090#1091#1076#1085#1099#1081' '#1090#1088#1077#1085#1076
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amplitude trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = GroupBoxSEF
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectrum edge frequencies (SEF)  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '#1043#1088#1072#1085#1080#1095#1085#1099#1077' '#1095#1072#1089#1090#1086#1090#1099' '#1089#1087#1077#1082#1090#1088#1072' ('#1043#1063#1057')  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Frequenza limite dello spettro (SEF)  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Spectrum Edge Frequencies (SEF)  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Spectrum Edge Frequencies (SEF)  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Spectrum Edge Frequencies (SEF)  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Spectrum Edge Frequencies (SEF)  '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelSEFHi
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1099#1089#1086#1082#1072#1103' '#1043#1063#1057'  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' SEF superiore'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelSEFLo
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1088#1077#1076#1085#1103#1103' '#1043#1063#1057
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' SEF media '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = RadioGroupTransform
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Data transform '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '#1055#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077' '#1076#1072#1085#1085#1099#1093'  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Trasformazione dati'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Data Transform '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Data Transform '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Data Transform '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' Data Transform '
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = RadioGroupTransform
        PropertyName = 'Items'
        PropertyValues = <
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E142C00000020D09FD180D0B5D0BED0B1D180D0B0D0
              B7D0BED0B2D0B0D0BDD0B8D0B520D0B4D0B0D0BDD0BDD18BD185202007436F6C
              756D6E730203094974656D496E64657802000D4974656D732E537472696E6773
              0106054E6F6E6520060C53717561726520726F6F742006094C6F676172797468
              6D00085461624F7264657202060000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E06102044617461207472616E73666F726D2007436F
              6C756D6E730203094974656D496E64657802000D4974656D732E537472696E67
              73011408000000D09DD0B5D18220201415000000D09AD0B22E2020D0BAD0BED1
              80D0B5D0BDD18C202012080000001B043E04330430044004380444043C040008
              5461624F7264657202060000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E06102044617461207472616E73666F726D2007436F
              6C756D6E730203094974656D496E64657802000D4974656D732E537472696E67
              730106074E657373756E6106105261646963652071756164726174612006094C
              6F67617269746D6F00085461624F7264657202060000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E142C00000020D09FD180D0B5D0BED0B1D180D0B0D0
              B7D0BED0B2D0B0D0BDD0B8D0B520D0B4D0B0D0BDD0BDD18BD185202007436F6C
              756D6E730203094974656D496E64657802000D4974656D732E537472696E6773
              0106054E6F6E6520060C53717561726520726F6F742006094C6F676172797468
              6D00085461624F7264657202060000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E06102044617461205472616E73666F726D2007436F
              6C756D6E730203094974656D496E64657802000D4974656D732E537472696E67
              730106054E6F6E6520060C53717561726520726F6F742006094C6F6761727974
              686D00085461624F7264657202060000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E06102044617461205472616E73666F726D2007436F
              6C756D6E730203094974656D496E64657802000D4974656D732E537472696E67
              730106054E6F6E6520060C53717561726520726F6F742006094C6F6761727974
              686D00085461624F7264657202060000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300B54526164696F47726F757013526164696F47726F75705472616E73
              666F726D044C656674020A03546F70023C055769647468034401064865696768
              7402320743617074696F6E06102044617461205472616E73666F726D2007436F
              6C756D6E730203094974656D496E64657802000D4974656D732E537472696E67
              730106054E6F6E6520060C53717561726520726F6F742006094C6F6761727974
              686D00085461624F7264657202060000}
          end>
      end
      item
        Component = GroupBoxCSA
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'CSA parameters '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '#1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1087#1077#1082#1090#1088#1072#1083#1100#1085#1086#1075#1086' '#1090#1088#1077#1085#1076#1072'  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Parametri CSA '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' CSA parameters '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelMkv
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1084#1082#1042
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelInBand
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'over band of'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1087#1086' '#1087#1086#1083#1086#1089#1077' '#1074
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'su bande di'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'over band of'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelFrom1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'From'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1090
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Da'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'From'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelTo1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'To'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1044#1086
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'A'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'To'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelHz2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelHz3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelHz4
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxSmoothing
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothing of spectrum '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1075#1083#1072#1078#1080#1074#1072#1085#1080#1077' '#1089#1087#1077#1082#1090#1088#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothing dello spettro'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothing of spectrum '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSEFFrqBand
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Calculate in frequency band '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1095#1080#1090#1072#1090#1100' '#1087#1086' '#1087#1086#1083#1086#1089#1077'  '#1095#1072#1089#1090#1086#1090
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Calcola nella banda di freq.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Calculate in frequency band '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelInBand
        PropertyName = 'Left'
        PropertyValues = <
          item
            PropType = ptOrd
            PropOrdValue = 167
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptOrd
            PropOrdValue = 170
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptOrd
            PropOrdValue = 167
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelTime
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0:01:34'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0:01:34'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0:01:34'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelFreqTo
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelFreqFrom
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '00'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '00'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '00'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label7
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '%'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '%'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '%'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label9
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '%'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '%'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '%'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelSEFFrom
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.25'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.25'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.25'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelSEFTo
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '20.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '20.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '20.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelBandOf
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = TabSheetSpectra
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectra'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087#1077#1082#1090#1088#1099
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectra'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelUseInterval
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox5
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Relative amplitude trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1090#1088#1077#1085#1076#1072' '#1072#1084#1087#1083#1080#1090#1091#1076
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Relative amplitude trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox10
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Frequency bands'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1063#1072#1089#1090#1086#1090#1085#1099#1077' '#1087#1086#1083#1086#1089#1099
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Frequency bands'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = RadioButtonWholeBand
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Whole band [0..20 Hz]'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1089#1103' '#1087#1086#1083#1086#1089#1072' [0..20 '#1043#1094']'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Whole band [0..20 Hz]'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = RadioButtonStandartBands
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Standart bands ('#948', '#952', '#945', '#946')     '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1090#1072#1085#1076#1072#1088#1090' ('#948', '#952', '#945', '#946')     '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Standart bands ('#948', '#952', '#945', '#946')     '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = RadioButtonManual
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Manual'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1053#1072#1089#1090#1088#1072#1080#1074#1072#1077#1084#1099#1081
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Manual'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = ButtonAdjustBands
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Adjust'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1053#1072#1089#1090#1088#1086#1080#1090#1100
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Adjust'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox6
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Energy ratio trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1058#1088#1077#1085#1076' '#1086#1090#1085#1086#1096#1077#1085#1080#1103' '#1101#1085#1077#1088#1075#1080#1081' '#1076#1080#1072#1087#1072#1079#1086#1085#1086#1074
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Energy ratio trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox4
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum amplitude on screen'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1072#1082#1089#1080#1084#1091#1084' '#1072#1084#1087#1083#1080#1090#1091#1076#1099' '#1085#1072' '#1101#1082#1088#1072#1085#1077
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum amplitude on screen'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelRAAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '00'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '00'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '00'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxMaxAmpAutoAdjust
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Auto adjust'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1040#1074#1090#1086#1088#1077#1075#1091#1083#1080#1088#1086#1074#1082#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Auto adjust'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxERTrend1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - index  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - '#1080#1085#1076#1077#1082#1089' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - index  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = ButtonRatioSettings
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Adjust'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1053#1072#1089#1090#1088#1086#1080#1090#1100
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Adjust'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxERTrend2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #945' / '#946'   '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #945' / '#946'   '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #945' / '#946'   '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxERTrend3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'User'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1053#1072#1089#1090#1088#1072#1080#1074#1072#1077#1084#1099#1081
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'User'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Time Interval for one spectrum '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1088#1077#1084#1077#1085#1085#1086#1081' '#1080#1085#1090#1077#1088#1074#1072#1083' '#1076#1083#1103' '#1086#1076#1085#1086#1075#1086' '#1089#1087#1077#1082#1090#1088#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Time Interval for one spectrum '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1089
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '   Intersection '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '   '#1055#1077#1088#1077#1089#1077#1095#1077#1085#1080#1077
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '   Intersection '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelAlphaSec
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.9'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.9'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.9'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSecP
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's)'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1089#1077#1082')'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's)'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelRecalc
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '(Calculate every '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '('#1057#1095#1077#1090' '#1082#1072#1078#1076#1099#1077
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '(Calculate every '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelPrimTime
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Averaging of neighbour spectra '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1059#1089#1088#1077#1076#1085#1077#1085#1080#1077' '#1089#1086#1089#1077#1076#1085#1080#1093' '#1089#1087#1077#1082#1090#1088#1086#1074
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Averaging of neighbour spectra '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelWindow
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Window'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1058#1080#1087' '#1086#1082#1085#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Window'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label5
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Used spectra'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1063#1080#1089#1083#1086' '#1089#1087#1077#1082#1090#1088#1086#1074
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Used spectra'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelNoAveraging
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'No averaging'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1041#1077#1079' '#1091#1089#1088#1077#1076#1085#1077#1085#1080#1103
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'No averaging'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSegmentValue
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.9'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.9'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.9'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSec3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1089#1077#1082
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSegment
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Signal epoch for an averaged spectrum:'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1069#1087#1086#1093#1072' '#1089#1080#1075#1085#1072#1083#1072' '#1076#1083#1103' '#1091#1089#1088#1077#1076#1085#1077#1085#1085#1086#1075#1086' '#1089#1087#1077#1082#1090#1088#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Signal epoch for an averaged spectrum:'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelNSp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxSpectrumEstimator
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectrum estimator '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087#1077#1082#1090#1088#1072#1083#1100#1085#1072#1103' '#1086#1094#1077#1085#1082#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectrum estimator '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelAROrder
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'AR order'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1086#1088#1103#1076#1086#1082' '#1040#1056
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'AR order'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSec
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1089#1077#1082
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelCorrWindow
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Corr. "window"'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1050#1086#1088#1088'. "'#1086#1082#1085#1086'"'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Corr. "window"'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelSec1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1089#1077#1082
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 's'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = RadioButtonPeriodogram
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothed periodogram'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1075#1083#1072#1078#1077#1085#1085#1072#1103' '#1087#1077#1088#1080#1086#1076#1086#1075#1088#1072#1084#1084#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothed periodogram'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = RadioButtonAutoregressive
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Autoregression '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1040#1074#1090#1086#1088#1077#1075#1088#1077#1089#1089#1080#1103
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Autoregression '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelAROrder
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelCorrWindow
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = ButtonApply
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Apply'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&'#1055#1088#1080#1084#1077#1085#1080#1090#1100
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '&Apply'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxHigherSEF
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Misc'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1088#1086#1095#1077#1077
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Misc'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxSEFTrends
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Trends of  spectrum edge frequencies  (SEF) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1058#1088#1077#1085#1076#1099' '#1075#1088#1072#1085#1080#1095#1085#1099#1093' '#1095#1072#1089#1090#1086#1090' '#1089#1087#1077#1082#1090#1088#1086#1074'  ('#1043#1063#1057') '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Trends of  spectrum edge frequencies  (SEF) '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxSEF1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1099#1089#1086#1082#1072#1103' '#1043#1063#1057
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxSEF2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1088#1077#1076#1085#1103#1103' '#1043#1063#1057
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxPeaks
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Trends of maximum and second peak of spectra'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1058#1088#1077#1085#1076#1099' '#1084#1072#1082#1089#1080#1084#1091#1084#1072' '#1080' '#1074#1090#1086#1088#1086#1075#1086' '#1087#1080#1082#1072' '#1089#1087#1077#1082#1090#1088#1086#1074
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Trends of maximum and second peak of spectra'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxPeakMain
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1072#1082#1089#1080#1084#1091#1084' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxPeakSecondary
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Second peak '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1090#1086#1088#1086#1081' '#1087#1080#1082
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Second peak '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxIndicators
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Panel of indicators '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1072#1085#1077#1083#1100' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1086#1074
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Panel of indicators '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxIndicators
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Enabled'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1082#1083#1102#1095#1077#1085#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Enabled'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxDigits
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Display also digital Indicators '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1099#1074#1086#1076#1080#1090#1100' '#1094#1080#1092#1088#1086#1074#1099#1077' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1099
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Display also digital Indicators '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxDSEF1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1099#1089#1086#1082#1072#1103' '#1043#1063#1057
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'High SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxDSEF2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1088#1077#1076#1085#1103#1103' '#1043#1063#1057
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Middle SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxDMax
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1072#1082#1089#1080#1084#1091#1084
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Maximum'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxDEntropy
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Entropy'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1069#1085#1090#1088#1086#1087#1080#1103
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Second peak'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxRulers
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Rulers and indicators'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1051#1080#1085#1077#1081#1082#1080' '#1080' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1099
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Rulers and indicators'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelRuler
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'CSA rulers'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1063#1072#1089#1090'. '#1083#1080#1085#1077#1081#1082#1080
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'CSA rulers'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelBand
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Indicators of bands'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1048#1085#1076#1080#1082#1072#1090#1086#1088#1099' '#1087#1086#1083#1086#1089
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Indicators of bands'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxScaleLeft
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Left '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1083#1077#1074#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Left '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxBandLeft
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Left'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1083#1077#1074#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Left'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxScaleRight
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Right'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087#1088#1072#1074#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Right'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxBandRight
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Right'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087#1088#1072#1074#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Right'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1080#1076
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'View'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelMinScaleAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Min. amplitude'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1080#1085'. '#1072#1084#1087#1083#1080#1090#1091#1076#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Min. amplitude'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelMaxScaleAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Max. amplitude '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1072#1082#1089'. '#1072#1084#1087#1083#1080#1090#1091#1076#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Max. amplitude '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelScaleAmpGrades
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1088#1072#1076#1072#1094#1080#1080
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Grades'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBoxRelHeigh
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Height of CSA trend and amplitudes trend '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1099#1089#1086#1090#1072' '#1089#1087#1077#1082#1090#1088#1072#1083#1100#1085#1086#1075#1086' '#1080' '#1072#1084#1087#1083#1080#1090#1091#1076#1085#1086#1075#1086' '#1090#1088#1077#1085#1076#1086#1074' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Height of CSA trend and amplitudes trend '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelCSA
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'CSA'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087'. '#1090#1088'.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'CSA'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = LabelAmpTrend
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1040#1084#1087'. '#1090#1088'.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxRARulerLeft
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Left '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1083#1077#1074#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Left '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxRARulerRight
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Right'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087#1088#1072#1074#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Right'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Rel. energy rulers'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1051#1080#1085#1077#1081#1082#1080' '#1086#1090#1085'. '#1101#1085#1077#1088#1075#1080#1081
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Rel. energy rulers'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxScalePanel
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Display'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Display'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label4
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Colored scale'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1062#1074#1077#1090#1085#1099#1077' '#1096#1082#1072#1083#1099
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Colored scale'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox8
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectrum entropy trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1058#1088#1077#1085#1076' '#1089#1087#1077#1082#1090#1088#1072#1083#1100#1085#1086#1081' '#1101#1085#1090#1088#1086#1087#1080#1080
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Spectrum entropy trend'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxEntropy
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Display'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Display'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxHigherSEF
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cut CSA higher than high SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1073#1088#1077#1079#1072#1090#1100' '#1089#1087#1077#1082#1090#1088' '#1074#1099#1096#1077' '#1074#1099#1089#1086#1082#1086#1081' '#1043#1063#1057
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cut CSA higher than high SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxCutAmpTrend
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cut amplitude trend above its part of total energy'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1073#1088#1077#1079#1072#1090#1100' '#1072#1084#1087#1083'. '#1090#1088#1077#1085#1076' '#1074#1099#1096#1077' '#1077#1075#1086' '#1076#1086#1083#1080' '#1086#1090' '#1086#1073#1097#1077#1081' '#1101#1085#1077#1088#1075#1080#1080
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cut amplitude trend above its part of total energy'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = GroupBox3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Specrtal entropy'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1087#1077#1082#1090#1088#1072#1083#1100#1085#1072#1103' '#1101#1085#1090#1088#1086#1087#1080#1103
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Specrtal entropy'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label6
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothing window width'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1064#1080#1088#1080#1085#1072' '#1086#1082#1085#1072' '#1089#1075#1083#1072#1078#1080#1074#1072#1085#1080#1103
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Smoothing window width'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = PanelEntSmoothing
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '0.5'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = Label8
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1094
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = ComboBoxWindow
        PropertyName = 'Items'
        PropertyValues = <
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300954436F6D626F426F780E436F6D626F426F7857696E646F77044C65
              6674025803546F7002170557696474680250064865696768740215055374796C
              65070E637344726F70446F776E4C6973740C466F6E742E43686172736574070F
              44454641554C545F434841525345540A466F6E742E436F6C6F72070C636C5769
              6E646F77546578740B466F6E742E48656967687402F509466F6E742E4E616D65
              060D4D532053616E732053657269660A466F6E742E5374796C650B000A506172
              656E74466F6E7408085461624F7264657202000D4974656D732E537472696E67
              7301060A547269616E67756C61720608426C61636B6D616E000000}
          end
          item
            PropType = ptClass
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {
              545046300954436F6D626F426F780E436F6D626F426F7857696E646F77044C65
              6674025803546F7002170557696474680250064865696768740215055374796C
              65070E637344726F70446F776E4C6973740C466F6E742E43686172736574070F
              44454641554C545F434841525345540A466F6E742E436F6C6F72070C636C5769
              6E646F77546578740B466F6E742E48656967687402F509466F6E742E4E616D65
              060D4D532053616E732053657269660A466F6E742E5374796C650B000A506172
              656E74466F6E7408085461624F7264657202000D4974656D732E537472696E67
              7301120B000000220440043504430433043E043B044C043D043E043504120700
              000011043B044D043A043C0435043D04000000}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxDTotalAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Total amplitude'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1089#1103' '#1072#1084#1087#1083#1080#1090#1091#1076#1072
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end>
      end
      item
        Component = CheckBoxDDeltaIndex
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - index   '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - '#1080#1085#1076#1077#1082#1089'  '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
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
    CurrentLang = 'English'
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
