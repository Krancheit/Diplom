object FrameSpectrTrend: TFrameSpectrTrend
  Left = 0
  Top = 0
  Width = 451
  Height = 304
  Align = alClient
  PopupMenu = PopupMenu1
  TabOrder = 0
  object PanelBorder: TPanel
    Left = 0
    Top = 0
    Width = 451
    Height = 304
    Align = alClient
    Caption = ' '
    ParentColor = True
    TabOrder = 0
    object PanelSpectrTrend: TPanel
      Left = 47
      Top = 1
      Width = 492
      Height = 521
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      ExplicitWidth = 737
      ExplicitHeight = 302
      object PanelHorSpTrendRuler: TPanel
        Left = 0
        Top = 508
        Width = 492
        Height = 13
        Align = alBottom
        BevelOuter = bvNone
        Caption = ' '
        TabOrder = 0
        ExplicitTop = 289
        ExplicitWidth = 737
        object PaintBoxHorRuler: TPaintBox
          Left = 0
          Top = 2
          Width = 492
          Height = 11
          Align = alClient
          Color = clInfoBk
          ParentColor = False
          ExplicitLeft = 4
          ExplicitTop = 1
          ExplicitWidth = 363
        end
        object PanelHorBorder: TPanel
          Left = 0
          Top = 0
          Width = 492
          Height = 2
          Align = alTop
          Caption = ' '
          TabOrder = 0
          ExplicitWidth = 737
        end
      end
      object PanelTrends: TPanelEx
        Left = 0
        Top = 0
        Width = 492
        Height = 508
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        BevelInnerLeft = bvNone
        BevelOuterLeft = bvNone
        BevelInnerTop = bvNone
        BevelOuterTop = bvNone
        BevelInnerRight = bvNone
        BevelOuterRight = bvNone
        BevelInnerBottom = bvNone
        BevelOuterBottom = bvNone
        ClearBackGround = False
        MarginLeft = 0
        MarginTop = 0
        MarginRight = 0
        MarginBottom = 0
        ExplicitWidth = 737
        ExplicitHeight = 289
        object PaintBoxTrends: TPaintBox
          Left = 2
          Top = 0
          Width = 490
          Height = 508
          Align = alClient
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsItalic]
          ParentColor = False
          ParentFont = False
          ExplicitLeft = 4
          ExplicitTop = -4
          ExplicitWidth = 361
          ExplicitHeight = 289
        end
        object LabelTotalAmpP: TLabel
          Left = 20
          Top = 208
          Width = 39
          Height = 13
          Caption = #1042#1089#1103' '#1040#1084#1087
          Visible = False
        end
        object LabelSelectedAmpP: TLabel
          Left = 20
          Top = 224
          Width = 42
          Height = 13
          Caption = #1042#1099#1073' '#1040#1084#1087
          Visible = False
        end
        object LabelRelEnergyP: TLabel
          Left = 21
          Top = 240
          Width = 47
          Height = 13
          Caption = #1054#1090#1085' '#1069#1085#1088#1075
          Visible = False
        end
        object PanelInPoint: TPanel
          Left = 33
          Top = 19
          Width = 257
          Height = 156
          BevelInner = bvRaised
          BevelOuter = bvNone
          Color = clSilver
          ParentBackground = False
          TabOrder = 0
          Visible = False
          DesignSize = (
            257
            156)
          object LabelHz: TLabel
            Left = 83
            Top = 39
            Width = 12
            Height = 13
            Caption = #1043#1094
          end
          object LabelMkvHz: TLabel
            Left = 152
            Top = 39
            Width = 48
            Height = 13
            Caption = #1084#1082#1042'^2/'#1043#1094
          end
          object LabelChName: TLabel
            Left = 22
            Top = 11
            Width = 85
            Height = 14
            Alignment = taCenter
            AutoSize = False
            Caption = '123456789012'
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clGray
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentColor = False
            ParentFont = False
            Visible = False
          end
          object LabelCursor: TLabel
            Left = 8
            Top = 39
            Width = 36
            Height = 13
            Caption = #1050#1091#1088#1089#1086#1088
          end
          object Label4: TLabel
            Left = 82
            Top = 39
            Width = 11
            Height = 13
            Caption = '%'
          end
          object Label14: TLabel
            Left = 152
            Top = 39
            Width = 18
            Height = 13
            Caption = #1084#1082#1042
          end
          object Label15: TLabel
            Left = 208
            Top = 32
            Width = 77
            Height = 13
            Caption = #1044#1077#1083#1100#1090#1072' '#1080#1085#1076#1077#1082#1089
            Visible = False
          end
          object PanelFreq: TPanel
            Left = 51
            Top = 37
            Width = 30
            Height = 15
            BevelOuter = bvLowered
            Caption = '99.9'
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clGray
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentBackground = False
            ParentFont = False
            TabOrder = 0
          end
          object PanelValue: TPanel
            Left = 107
            Top = 37
            Width = 39
            Height = 15
            BevelOuter = bvLowered
            Caption = 'xx.xx'
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clGray
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentBackground = False
            ParentFont = False
            TabOrder = 1
          end
          object PanelTime: TPanel
            Left = 158
            Top = 11
            Width = 60
            Height = 15
            Anchors = []
            BevelOuter = bvLowered
            Caption = '99:99:99'
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clLime
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentBackground = False
            ParentFont = False
            TabOrder = 2
          end
          object PanelCSAData: TPanel
            Left = 0
            Top = 54
            Width = 257
            Height = 102
            BevelOuter = bvNone
            TabOrder = 3
            object LabelSEFHi: TLabel
              Left = 7
              Top = 28
              Width = 20
              Height = 13
              Caption = #1043#1063#1057
            end
            object LabelSEFLo: TLabel
              Left = 7
              Top = 50
              Width = 20
              Height = 13
              Caption = #1043#1063#1057
            end
            object LabelHz2: TLabel
              Left = 82
              Top = 28
              Width = 12
              Height = 13
              Caption = #1043#1094
            end
            object LabelHz3: TLabel
              Left = 82
              Top = 50
              Width = 12
              Height = 13
              Caption = #1043#1094
            end
            object LabelTotallAmp: TLabel
              Left = 122
              Top = 28
              Width = 77
              Height = 13
              Caption = #1055#1086#1083#1085'. '#1072#1084#1087'. '#1069#1069#1043
            end
            object LabelMkv: TLabel
              Left = 235
              Top = 28
              Width = 18
              Height = 13
              Caption = #1084#1082#1042
            end
            object LabelMax: TLabel
              Left = 7
              Top = 7
              Width = 29
              Height = 13
              Caption = #1052#1072#1082#1089'.'
            end
            object LabelHz1: TLabel
              Left = 82
              Top = 7
              Width = 12
              Height = 13
              Caption = #1043#1094
            end
            object LabelMkvHz1: TLabel
              Left = 148
              Top = 7
              Width = 41
              Height = 13
              Caption = #1084#1082#1042' '#1030'/'#1043#1094
            end
            object Label2: TLabel
              Left = 122
              Top = 50
              Width = 49
              Height = 13
              Caption = #1069#1085#1090#1088#1086#1087#1080#1103
            end
            object PanelCEFPerCentHi: TPanel
              Left = 27
              Top = 27
              Width = 20
              Height = 15
              BevelOuter = bvNone
              Caption = '95'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
            end
            object PanelCEFPerCentLo: TPanel
              Left = 27
              Top = 49
              Width = 20
              Height = 15
              BevelOuter = bvNone
              Caption = '95'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
            end
            object PanelSEFFrqHi: TPanel
              Left = 50
              Top = 27
              Width = 30
              Height = 15
              BevelOuter = bvLowered
              Caption = '99.9'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 2
            end
            object PanelSEFFrqLo: TPanel
              Left = 50
              Top = 49
              Width = 30
              Height = 15
              BevelOuter = bvLowered
              Caption = '99.9'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 3
            end
            object PanelTotAmp: TPanel
              Left = 201
              Top = 27
              Width = 30
              Height = 15
              BevelOuter = bvLowered
              Caption = '999'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 4
            end
            object PanelMaxFrq: TPanel
              Left = 50
              Top = 5
              Width = 30
              Height = 15
              BevelOuter = bvLowered
              Caption = '99.9'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 5
            end
            object PanelMaxValue: TPanel
              Left = 106
              Top = 5
              Width = 39
              Height = 15
              BevelOuter = bvLowered
              Caption = 'xx.xx'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 6
            end
            object PanelEntropy: TPanel
              Left = 201
              Top = 49
              Width = 30
              Height = 15
              BevelOuter = bvLowered
              Caption = '999'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 7
            end
          end
          object PanelRAData: TPanel
            Left = 0
            Top = 58
            Width = 326
            Height = 99
            BevelOuter = bvNone
            TabOrder = 4
            object GroupBoxEnergiesInBands: TGroupBox
              Left = 5
              Top = 1
              Width = 135
              Height = 89
              Caption = #1069#1085#1077#1088#1075#1080#1103' '#1087#1086' '#1087#1086#1083#1086#1089#1072#1084
              TabOrder = 0
              object Label3: TLabel
                Left = 41
                Top = 16
                Width = 18
                Height = 13
                Caption = #1084#1082#1042
              end
              object LabelPerCent: TLabel
                Left = 116
                Top = 16
                Width = 11
                Height = 13
                Caption = '%'
              end
              object Label5: TLabel
                Left = 41
                Top = 33
                Width = 18
                Height = 13
                Caption = #1084#1082#1042
              end
              object Label6: TLabel
                Left = 116
                Top = 33
                Width = 11
                Height = 13
                Caption = '%'
              end
              object Label7: TLabel
                Left = 41
                Top = 50
                Width = 18
                Height = 13
                Caption = #1084#1082#1042
              end
              object Label8: TLabel
                Left = 116
                Top = 50
                Width = 11
                Height = 13
                Caption = '%'
              end
              object Label9: TLabel
                Left = 41
                Top = 67
                Width = 18
                Height = 13
                Caption = #1084#1082#1042
              end
              object Label10: TLabel
                Left = 116
                Top = 67
                Width = 11
                Height = 13
                Caption = '%'
              end
              object Panel2: TPanel
                Left = 6
                Top = 15
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 0
              end
              object Panel3: TPanel
                Left = 83
                Top = 15
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 1
              end
              object Panel4: TPanel
                Left = 6
                Top = 32
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 2
              end
              object Panel5: TPanel
                Left = 83
                Top = 32
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 3
              end
              object Panel6: TPanel
                Left = 6
                Top = 49
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 4
              end
              object Panel7: TPanel
                Left = 83
                Top = 49
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 5
              end
              object Panel8: TPanel
                Left = 6
                Top = 66
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 6
              end
              object Panel9: TPanel
                Left = 83
                Top = 66
                Width = 30
                Height = 15
                BevelOuter = bvLowered
                Caption = '99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 7
              end
            end
            object GroupBoxEnergyRatio: TGroupBox
              Left = 146
              Top = 1
              Width = 106
              Height = 89
              Caption = #1054#1090#1085#1086#1096'. '#1101#1085#1077#1088#1075#1080#1081
              TabOrder = 1
              object Label11: TLabel
                Left = 8
                Top = 16
                Width = 39
                Height = 13
                Caption = #948' - '#1080#1085#1076'.'
              end
              object Label12: TLabel
                Left = 8
                Top = 33
                Width = 31
                Height = 13
                Caption = #945' / '#946'   '
              end
              object Label13: TLabel
                Left = 8
                Top = 50
                Width = 34
                Height = 13
                Caption = #1055#1086#1083#1100#1079'.'
              end
              object Panel10: TPanel
                Left = 56
                Top = 15
                Width = 40
                Height = 15
                BevelOuter = bvLowered
                Caption = '99.99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 0
              end
              object Panel11: TPanel
                Left = 56
                Top = 32
                Width = 40
                Height = 15
                BevelOuter = bvLowered
                Caption = '99.99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 1
              end
              object Panel12: TPanel
                Left = 56
                Top = 49
                Width = 40
                Height = 15
                BevelOuter = bvLowered
                Caption = '99.99'
                Color = clSkyBlue
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'MS Sans Serif'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 2
              end
            end
          end
        end
        object Panel1: TPanel
          Left = 0
          Top = 0
          Width = 2
          Height = 289
          Align = alLeft
          Caption = ' '
          TabOrder = 1
        end
        object PanelScreenBorder: TPanel
          Left = 296
          Top = 0
          Width = 2
          Height = 254
          ParentBackground = False
          TabOrder = 2
          Visible = False
        end
      end
    end
    object PanelFreqInd: TPanelEx
      Left = 1
      Top = 1
      Width = 46
      Height = 302
      Align = alLeft
      BevelOuter = bvNone
      Caption = ' '
      TabOrder = 1
      BevelInnerLeft = bvNone
      BevelOuterLeft = bvNone
      BevelInnerTop = bvNone
      BevelOuterTop = bvNone
      BevelInnerRight = bvNone
      BevelOuterRight = bvNone
      BevelInnerBottom = bvNone
      BevelOuterBottom = bvNone
      ClearBackGround = False
      MarginLeft = 0
      MarginTop = 0
      MarginRight = 0
      MarginBottom = 0
      object PaintBoxFreqInd: TPaintBox
        Left = 0
        Top = 0
        Width = 44
        Height = 521
        Align = alClient
        Color = clSilver
        ParentColor = False
        ExplicitLeft = -2
        ExplicitHeight = 302
      end
      object PanelVertBorderS: TPanel
        Left = 44
        Top = 0
        Width = 2
        Height = 521
        Align = alRight
        Caption = ' '
        TabOrder = 0
        ExplicitHeight = 302
      end
    end
    object PanelViewDigits: TPanel
      Left = 266
      Top = 1
      Width = 184
      Height = 302
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 2
      object PanelViewDigitsLowBorder: TPanel
        Left = 0
        Top = 508
        Width = 184
        Height = 13
        Align = alBottom
        BevelOuter = bvNone
        Color = clInfoBk
        TabOrder = 0
        ExplicitTop = 289
      end
    end
    object PanelR: TPanel
      Left = 43
      Top = 1
      Width = 223
      Height = 302
      Align = alRight
      BevelOuter = bvNone
      BorderWidth = 1
      Padding.Left = 5
      Padding.Right = 5
      ParentColor = True
      TabOrder = 3
      Visible = False
      object PanelIndicatorsDef: TPanel
        Left = 119
        Top = 1
        Width = 98
        Height = 519
        Align = alRight
        BevelOuter = bvNone
        Padding.Left = 5
        Padding.Right = 5
        ParentColor = True
        TabOrder = 0
        ExplicitHeight = 300
      end
      object PanelBars: TPanel
        Left = 11
        Top = 1
        Width = 108
        Height = 519
        Align = alRight
        BevelOuter = bvNone
        ParentBackground = False
        ParentColor = True
        TabOrder = 1
        ExplicitHeight = 300
      end
    end
  end
  object PanelProgress: TPanel
    Left = 62
    Top = 243
    Width = 185
    Height = 43
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 78
      Height = 13
      Align = alClient
      Alignment = taCenter
      Caption = #1057#1086#1093#1088#1072#1085#1077#1085#1080#1077'...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object JvProgressBar1: TJvProgressBar
      Left = 1
      Top = 14
      Width = 183
      Height = 28
      Align = alBottom
      TabOrder = 0
    end
  end
  object PanelButtons: TPanel
    Left = 408
    Top = 240
    Width = 86
    Height = 51
    BevelOuter = bvNone
    TabOrder = 2
    object ButtonSTSave: TBitBtn
      Left = 0
      Top = -1
      Width = 87
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      DoubleBuffered = True
      Glyph.Data = {
        96090000424D9609000000000000360000002800000028000000140000000100
        18000000000060090000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAEAEAE3E3E3E3E3
        E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3
        E3E3E3E3E3E3E3E3F8F8F8FFFFFFFFFFFFEAEAEAE3E3E3E3E3E3E3E3E3E3E3E3
        E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3
        E3F8F8F8FFFFFFFFFFFFFFFFFFFFFFFF3636383636383535379A9A9B9A9A9B9A
        9A9B9A9A9B9A9A9B9A9A9B9A9A9B9A9A9B9A9A9B818182363638363638353537
        E3E3E3FFFFFFFFFFFF5857575857575857575857575857575857575857575857
        57585757585757585757585757585757585757585757585757E3E3E3FFFFFFFF
        FFFFFFFFFFFFFFFF3636389A9A9BCDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF363638FFFFFF363638E3E3E3FFFFFFFFFF
        FF585757585757585757E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0
        DFDEE0DFDEE0DFDE585757585757585757E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF
        363638363638CDCDCDE2C9B1D9B798D9B798D9B798D9B798D9B798D9B798D9B7
        98D9B798E2C9B1363638363638363638E3E3E3FFFFFFFFFFFF58575758575758
        5757E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE
        585757585757585757E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF363638363638CDCD
        CDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF36
        3638363638363638E3E3E3FFFFFFFFFFFF585757585757585757E0DFDEE0DFDE
        E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE5857575857575857
        57E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF363638363638CDCDCDFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF363638363638363638
        E3E3E3FFFFFFFFFFFF585757585757585757E0DFDEE0DFDEE0DFDEE0DFDEE0DF
        DEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE585757585757585757E3E3E3FFFFFFFF
        FFFFFFFFFFFFFFFF363638363638CDCDCDECDBCBECDBCBECDBCBECDBCBECDBCB
        ECDBCBECDBCBECDBCBECDBCBFAF6F2363638363638363638E3E3E3FFFFFFFFFF
        FF585757585757585757E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0
        DFDEE0DFDEE0DFDE585757585757585757E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF
        363638363638CDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFF363638363638363638E3E3E3FFFFFFFFFFFF58575758575758
        5757E0DFDEE4E3E2E4E3E2E4E3E2E0DFDEE0DFDEE4E3E2E0DFDEE0DFDEE0DFDE
        585757585757585757E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF3636383636385B5B
        5DCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCD36
        3638363638363638E3E3E3FFFFFFFFFFFF585757585757585757E0DFDEE0DFDE
        E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE5857575857575857
        57E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF36363836363836363836363836363836
        3638363638363638363638363638363638363638363638363638363638363638
        E3E3E3FFFFFFFFFFFF5857575857575857575857575857575857575857575857
        57585757585757585757585757585757585757585757585757E3E3E3FFFFFFFF
        FFFFFFFFFFFFFFFF363638363638363638363638363638363638363638363638
        363638363638363638363638363638363638363638363638E3E3E3FFFFFFFFFF
        FF58575758575758575758575758575758575758575758575758575758575758
        5757585757585757585757585757585757E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF
        363638363638363638FBFBFBF1F1F1E9E8E8E0DFDED9D6D4D0CDCB918F8E5857
        57565555B1ABA6363638363638363638E3E3E3FFFFFFFFFFFF58575758575758
        5757E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE
        585757585757585757E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF3636383636383636
        38FBFBFBF1F1F1E9E8E8E0DFDED9D6D4D0CDCB7F7D7D353537353537B1ABA636
        3638363638363638E3E3E3FFFFFFFFFFFF585757585757585757E0DFDEE0DFDE
        E0DFDEE0DFDEE0DFDEE0DFDEE0DFDE585757585757E0DFDE5857575857575857
        57E3E3E3FFFFFFFFFFFFFFFFFFFFFFFF363638363638363638FBFBFBF1F1F1E9
        E8E8E0DFDED9D6D4D0CDCB7F7D7D353537353537B1ABA6363638363638363638
        E3E3E3FFFFFFFFFFFF585757585757585757E0DFDEE0DFDEE0DFDEE0DFDEE0DF
        DEE0DFDEE0DFDE585757585757E0DFDE585757585757585757E3E3E3FFFFFFFF
        FFFFFFFFFFFFFFFF363638363638363638FBFBFBF1F1F1E9E8E8E0DFDED9D6D4
        D0CDCB7F7D7D353537353537B1ABA6363638363638363638E9E9E9FFFFFFFFFF
        FF585757585757585757E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE58
        5757585757E0DFDE585757585757585757E9E9E9FFFFFFFFFFFFFFFFFFFFFFFF
        363638363638363638FBFBFBF1F1F1E9E8E8E0DFDED9D6D4D0CDCB7F7D7D3535
        37353537B1ABA6363638363638939393FDFDFDFFFFFFFFFFFF58575758575758
        5757E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE585757585757E0DFDE
        585757585757E0DFDEFDFDFDFFFFFFFFFFFFFFFFFFFFFFFF3636383636383636
        38FBFBFBF1F1F1E9E8E8E0DFDED9D6D4D0CDCBA4A19F7B7878777473B1ABA636
        36383D3D3EF4F4F4FFFFFFFFFFFFFFFFFF585757585757585757E0DFDEE0DFDE
        E0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDEE0DFDE585757585757F4F4
        F4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      NumGlyphs = 2
      ParentDoubleBuffered = False
      TabOrder = 0
      Visible = False
    end
    object ButtonSTExport: TBitBtn
      Left = 0
      Top = 25
      Width = 87
      Height = 25
      Caption = #1069#1082#1089#1087#1086#1088#1090
      DoubleBuffered = True
      Enabled = False
      ParentDoubleBuffered = False
      TabOrder = 1
      Visible = False
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 206
    Top = 200
    object MenuItemSettings: TMenuItem
      Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1080
    end
  end
  object MultiLang1: TMultiLang
    Items = <
      item
        Component = MenuItemSettings
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Settings'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1059#1089#1090#1072#1085#1086#1074#1082#1080
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Impostazioni'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Einstellungen'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Configurations'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Configuraciones'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelCursor
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cursor'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1050#1091#1088#1089#1086#1088
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cursore'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cursor'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Curseur'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cursor'
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
          end>
      end
      item
        Component = LabelMkvHz
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V '#1030'/Hz'
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
            PropStringValue = #181'V '#1030'/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V '#1030'/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V '#1030'/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V '#1030'/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelRelEnergyP
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Rel. en.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1090#1085' '#1069#1085#1088#1075
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'En. rel.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Rel En'
            PropVariantValue = 'Rel En'
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'En rel'
            PropVariantValue = #1049'n rel'
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'En rel'
            PropVariantValue = 'En rel'
            MemoryStream = {}
          end>
      end
      item
        Component = LabelSelectedAmpP
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Sel. amp.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1099#1073' '#1040#1084#1087
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp. sel.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'vor Umf'
            PropVariantValue = 'vor Umf'
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp ch'
            PropVariantValue = 'Amp cho'
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp sel'
            PropVariantValue = 'Amp sel'
            MemoryStream = {}
          end>
      end
      item
        Component = LabelTotalAmpP
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Tot. amp.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1042#1089#1103' '#1040#1084#1087
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp. tot.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Ges Umf'
            PropVariantValue = 'Ges Umf'
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Amp tot'
            PropVariantValue = 'Amp tot'
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Tot Amp'
            PropVariantValue = 'Amp tot'
            MemoryStream = {}
          end>
      end
      item
        Component = PanelBorder
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
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
        Component = PanelSpectrTrend
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
        Component = PanelHorSpTrendRuler
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
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
        Component = PanelHorBorder
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
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
        Component = PanelTrends
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
        Component = PanelInPoint
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
        Component = LabelChName
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '123456789012'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '123456789012'
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
        Component = PanelFreq
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
        Component = PanelValue
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'xx.xx'
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
            PropStringValue = '99:99:99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99:99:99'
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
        Component = Panel1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
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
        Component = PanelScreenBorder
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
        Component = PanelFreqInd
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
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
        Component = PanelVertBorderS
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = ' '
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
        Component = PanelViewDigits
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
        Component = PanelViewDigitsLowBorder
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
        Component = PanelProgress
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
        Component = PanelButtons
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
            PropStringValue = 'Saving...'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1086#1093#1088#1072#1085#1077#1085#1080#1077'...'
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
        Component = ButtonSTSave
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Save'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1057#1086#1093#1088#1072#1085#1080#1090#1100
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
        Component = ButtonSTExport
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Export'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1069#1082#1089#1087#1086#1088#1090
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
        Component = Label14
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
        Component = PanelCSAData
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
        Component = LabelSEFHi
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1063#1057
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
        Component = LabelSEFLo
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'SEF'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1043#1063#1057
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
        Component = LabelTotallAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Total EEG amp.'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1055#1086#1083#1085'. '#1072#1084#1087'. '#1069#1069#1043
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
        Component = LabelMax
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Max'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1052#1072#1082#1089'.'
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
        Component = LabelMkvHz1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #181'V '#1030'/Hz'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1084#1082#1042' '#1030'/'#1043#1094
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
            PropStringValue = 'Spec. entropy'
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
        Component = PanelCEFPerCentHi
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '95'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '95'
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
        Component = PanelCEFPerCentLo
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '95'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '95'
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
        Component = PanelSEFFrqHi
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
        Component = PanelSEFFrqLo
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
        Component = PanelTotAmp
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '999'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '999'
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
        Component = PanelMaxFrq
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
        Component = PanelMaxValue
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'xx.xx'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'xx.xx'
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
        Component = PanelEntropy
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '999'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '999'
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
        Component = PanelRAData
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
        Component = GroupBoxEnergiesInBands
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Energies in bands'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1069#1085#1077#1088#1075#1080#1103' '#1087#1086' '#1087#1086#1083#1086#1089#1072#1084
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
        Component = LabelPerCent
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
        Component = Label7
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
        Component = Label10
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
        Component = Panel2
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
        Component = Panel3
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
        Component = Panel4
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
        Component = Panel5
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
        Component = Panel6
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
        Component = Panel7
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
        Component = Panel8
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
        Component = Panel9
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
        Component = GroupBoxEnergyRatio
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Energy ratio'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #1054#1090#1085#1086#1096'. '#1101#1085#1077#1088#1075#1080#1081
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
        Component = Label11
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - index'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948' - '#1080#1085#1076'.'
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
        Component = Label12
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
        Component = Label13
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
            PropStringValue = #1055#1086#1083#1100#1079'.'
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
        Component = Panel10
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.99'
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
        Component = Panel11
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.99'
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
        Component = Panel12
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.99'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '99.99'
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
        Component = Label15
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Delta index'
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
      'German'
      'French'
      'Spanish')
    CurrentLang = 'Russian'
    StringItems.LangCount = 6
    StringItems = <>
    Left = 305
    Top = 223
  end
  object TimerCursor: TTimer
    Enabled = False
    Interval = 300
    Left = 264
    Top = 184
  end
end
