object FormFreqBands: TFormFreqBands
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1050#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1103' '#1095#1072#1089#1090#1086#1090#1085#1099#1093' '#1087#1086#1083#1086#1089
  ClientHeight = 384
  ClientWidth = 738
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
  object BasePanel: TPanel
    Left = 0
    Top = 0
    Width = 738
    Height = 384
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object PanelBands: TPanel
      Left = 0
      Top = 0
      Width = 738
      Height = 384
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      object LabelBand: TLabel
        Left = 128
        Top = 24
        Width = 36
        Height = 13
        Caption = #1055#1086#1083#1086#1089#1072
      end
      object CheckBox1: TCheckBox
        Left = 24
        Top = 24
        Width = 17
        Height = 25
        TabOrder = 0
        OnClick = OnSwitchBand
      end
      object CheckBox2: TCheckBox
        Left = 32
        Top = 32
        Width = 17
        Height = 25
        TabOrder = 1
        OnClick = OnSwitchBand
      end
      object CheckBox3: TCheckBox
        Left = 40
        Top = 40
        Width = 17
        Height = 25
        TabOrder = 2
        OnClick = OnSwitchBand
      end
      object CheckBox4: TCheckBox
        Left = 48
        Top = 48
        Width = 17
        Height = 25
        TabOrder = 3
        OnClick = OnSwitchBand
      end
      object ButtonOK: TButton
        Left = 564
        Top = 190
        Width = 75
        Height = 25
        Caption = 'OK'
        ModalResult = 1
        TabOrder = 4
        OnClick = OnOKClick
      end
      object Button1: TButton
        Left = 650
        Top = 190
        Width = 75
        Height = 25
        Caption = #1054#1090#1084#1077#1085#1072
        ModalResult = 2
        TabOrder = 5
      end
    end
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
            PropStringValue = 'Frequency bands config'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Frequency bands config'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = BasePanel
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
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = PanelBands
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
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = CheckBox1
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
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = CheckBox2
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
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = CheckBox3
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
            PropType = ptString
            PropOrdValue = 0
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = CheckBox4
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
            PropType = ptString
            PropOrdValue = 0
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
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'OK'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = Button1
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
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Cancel'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end
      item
        Component = LabelBand
        PropertyName = 'Caption'
        PropertyValues = <
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Band'
            PropVariantValue = ''
            MemoryStream = {}
          end
          item
            PropType = ptNull
            PropOrdValue = 0
            PropVariantValue = ''
          end
          item
            PropType = ptString
            PropOrdValue = 0
            PropStringValue = 'Band'
            PropVariantValue = ''
            MemoryStream = {}
          end>
      end>
    Languages.Strings = (
      'English'
      'Russian'
      'Italian')
    CurrentLang = 'Russian'
    StringItems.LangCount = 3
    StringItems = <>
    Left = 192
    Top = 88
  end
end
