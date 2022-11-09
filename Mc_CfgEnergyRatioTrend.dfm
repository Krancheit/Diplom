object FormERTrendBands: TFormERTrendBands
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1063#1072#1089#1090#1086#1090#1085#1099#1077' '#1087#1086#1083#1086#1089#1099' '#1076#1083#1103' '#1090#1088#1077#1085#1076#1072' '#1086#1090#1085#1086#1096#1077#1085#1080#1103' '#1101#1085#1077#1088#1075#1080#1081
  ClientHeight = 394
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 345
    Height = 337
    TabOrder = 0
    object Label1: TLabel
      Left = 13
      Top = 33
      Width = 139
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '(a+b+c+d+U1+U2+U3+U4)'
    end
    object Label2: TLabel
      Left = 10
      Top = 13
      Width = 143
      Height = 13
      Caption = #1055#1086#1083#1086#1089#1072' 1 ('#1101#1085#1077#1088#1075#1080#1103'-'#1076#1077#1083#1080#1084#1086#1077')'
    end
    object Label3: TLabel
      Left = 182
      Top = 13
      Width = 149
      Height = 13
      Caption = #1055#1086#1083#1086#1089#1072' 2 ('#1101#1085#1077#1088#1075#1080#1103'-'#1076#1077#1083#1080#1090#1077#1083#1100')'
    end
    object Label4: TLabel
      Left = 185
      Top = 33
      Width = 139
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '(a+b+c+d+U1+U2+U3+U4)'
    end
    object Panel1: TPanel
      Left = 0
      Top = 58
      Width = 345
      Height = 2
      BevelOuter = bvLowered
      Caption = 'Panel1'
      TabOrder = 0
    end
    object Panel2: TPanel
      Left = 171
      Top = 0
      Width = 2
      Height = 337
      BevelOuter = bvLowered
      Caption = 'Panel1'
      TabOrder = 1
    end
    object CheckBox1: TCheckBox
      Left = 19
      Top = 80
      Width = 131
      Height = 17
      Caption = #948
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = OnBandsChange
    end
    object CheckBox2: TCheckBox
      Left = 19
      Top = 112
      Width = 131
      Height = 17
      Caption = #952
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = OnBandsChange
    end
    object CheckBox3: TCheckBox
      Left = 19
      Top = 144
      Width = 131
      Height = 17
      Caption = #945
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = OnBandsChange
    end
    object CheckBox4: TCheckBox
      Left = 19
      Top = 176
      Width = 131
      Height = 17
      Caption = #946
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = OnBandsChange
    end
    object CheckBox5: TCheckBox
      Left = 19
      Top = 208
      Width = 131
      Height = 17
      Caption = 'U1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = OnBandsChange
    end
    object CheckBox6: TCheckBox
      Left = 19
      Top = 240
      Width = 131
      Height = 17
      Caption = 'U2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = OnBandsChange
    end
    object CheckBox7: TCheckBox
      Left = 19
      Top = 272
      Width = 131
      Height = 17
      Caption = 'U3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = OnBandsChange
    end
    object CheckBox8: TCheckBox
      Left = 19
      Top = 304
      Width = 131
      Height = 17
      Caption = 'U4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = OnBandsChange
    end
    object CheckBox9: TCheckBox
      Left = 194
      Top = 80
      Width = 133
      Height = 17
      Caption = #948
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      OnClick = OnBandsChange
    end
    object CheckBox10: TCheckBox
      Left = 194
      Top = 112
      Width = 133
      Height = 17
      Caption = #952
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      OnClick = OnBandsChange
    end
    object CheckBox11: TCheckBox
      Left = 194
      Top = 144
      Width = 133
      Height = 17
      Caption = #945
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 12
      OnClick = OnBandsChange
    end
    object CheckBox12: TCheckBox
      Left = 194
      Top = 176
      Width = 133
      Height = 17
      Caption = #946
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 13
      OnClick = OnBandsChange
    end
    object CheckBox13: TCheckBox
      Left = 194
      Top = 208
      Width = 133
      Height = 17
      Caption = 'U1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 14
      OnClick = OnBandsChange
    end
    object CheckBox14: TCheckBox
      Left = 194
      Top = 240
      Width = 133
      Height = 17
      Caption = 'U2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 15
      OnClick = OnBandsChange
    end
    object CheckBox15: TCheckBox
      Left = 194
      Top = 272
      Width = 133
      Height = 17
      Caption = 'U3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 16
      OnClick = OnBandsChange
    end
    object CheckBox16: TCheckBox
      Left = 194
      Top = 304
      Width = 133
      Height = 17
      Caption = 'U4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 17
      OnClick = OnBandsChange
    end
  end
  object ButtonOK: TButton
    Left = 179
    Top = 360
    Width = 78
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 1
    OnClick = OnOKClick
  end
  object ButtonCancel: TButton
    Left = 272
    Top = 360
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 2
  end
  object MultiLang1: TMultiLang
    Items = <
      item
        Component = Owner
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Bands for energy ratio trend'
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
          end>
      end
      item
        Component = GroupBox1
        PropertyName = 'Caption'
        PropertyValues = <
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
          end>
      end
      item
        Component = Panel1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Panel1'
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
          end>
      end
      item
        Component = Label1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '(a+b+c+d+U1+U2+U3+U4)'
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
          end>
      end
      item
        Component = Label2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Band 1 (divident energy value)'
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
          end>
      end
      item
        Component = Panel2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Panel1'
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
          end>
      end
      item
        Component = CheckBox1
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948
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
          end>
      end
      item
        Component = CheckBox2
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #952
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
          end>
      end
      item
        Component = CheckBox3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #945
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
          end>
      end
      item
        Component = CheckBox4
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #946
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
          end>
      end
      item
        Component = CheckBox5
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U1'
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
          end>
      end
      item
        Component = CheckBox6
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U2'
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
          end>
      end
      item
        Component = CheckBox7
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U3'
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
          end>
      end
      item
        Component = CheckBox8
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U4'
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
          end>
      end
      item
        Component = Label3
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Band 2 (divisor energy value)'
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
          end>
      end
      item
        Component = Label4
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = '(a+b+c+d+U1+U2+U3+U4)'
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
          end>
      end
      item
        Component = CheckBox9
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #948
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
          end>
      end
      item
        Component = CheckBox10
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #952
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
          end>
      end
      item
        Component = CheckBox11
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #945
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
          end>
      end
      item
        Component = CheckBox12
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = #946
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
          end>
      end
      item
        Component = CheckBox13
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U1'
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
          end>
      end
      item
        Component = CheckBox14
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U2'
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
          end>
      end
      item
        Component = CheckBox15
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U3'
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
          end>
      end
      item
        Component = CheckBox16
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'U4'
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
          end>
      end
      item
        Component = ButtonOK
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'OK'
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
          end>
      end
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
      'Italian')
    CurrentLang = 'Russian'
    StringItems.LangCount = 3
    StringItems = <>
    Left = 72
    Top = 352
  end
end
