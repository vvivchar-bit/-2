   #include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
TBtnNClick *Btn;
TSG *Grid1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Grid1 = NULL;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Btn = new TBtnNClick(this);
    Btn->Parent = this;
    Btn->Left = 70;
    Btn->Top = 100;
    Btn->Width = 200;
    Btn->Height = 30;
    Btn->Name = "BtnNClick1";
    Btn->Caption = "Натисни мене";
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if (Grid1 == NULL)
    {
        Grid1 = new TSG(this);
        Grid1->Parent = this;
        Grid1->Left = 300;
        Grid1->Top = 50;
        Grid1->Width = 320;
        Grid1->Height = 220;
        Grid1->Name = "Grid1";
        Grid1->TabStop = true;
        Grid1->Visible = true;
        Grid1->SetFocus();
    }
}
