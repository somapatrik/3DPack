program Project1;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  RegisterUnit in 'RegisterUnit.pas' {RegisterForm},
  About in 'About.pas' {AboutBox};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TRegisterForm, RegisterForm);
  Application.CreateForm(TAboutBox, AboutBox);
  Application.Run;
end.
