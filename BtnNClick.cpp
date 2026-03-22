    #include <vcl.h>
#pragma hdrstop

#include "BtnNClick.h"

#pragma package(smart_init)

__fastcall TBtnNClick::TBtnNClick(TComponent* Owner)
    : TButton(Owner)
{
    NClick = 0;
}

void __fastcall TBtnNClick::Click()
{
    NClick++;
    Caption = Name + " (" + IntToStr(NClick) + ") клацань";
    TButton::Click();
}
