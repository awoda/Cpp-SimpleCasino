object SaveState: TSaveState
  Left = 393
  Top = 188
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsSingle
  Caption = 'Serio?'
  ClientHeight = 65
  ClientWidth = 185
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 13
    Top = 8
    Width = 164
    Height = 18
    Caption = 'Jeste'#347' ma'#322#261' kaczuszk'#261'?'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Microsoft Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 8
    Top = 32
    Width = 81
    Height = 25
    Caption = 'Tak'
    ModalResult = 6
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 32
    Width = 81
    Height = 25
    Caption = 'Nie'
    TabOrder = 1
    OnClick = Button2Click
  end
end
