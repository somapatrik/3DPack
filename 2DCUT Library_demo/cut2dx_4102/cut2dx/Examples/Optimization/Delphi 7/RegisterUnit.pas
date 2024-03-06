unit RegisterUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TRegisterForm = class(TForm)
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    eName: TEdit;
    eComputerID: TEdit;
    eSerialNumber: TEdit;
    bRegister: TButton;
    Button1: TButton;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  RegisterForm: TRegisterForm;

implementation

{$R *.dfm}

end.
