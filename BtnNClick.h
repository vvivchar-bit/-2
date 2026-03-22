 #ifndef BtnNClickH
#define BtnNClickH

#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>

class PACKAGE TBtnNClick : public TButton
{
private:
    int NClick;

public:
    __fastcall TBtnNClick(TComponent* Owner);
    DYNAMIC void __fastcall Click();
};

#endif
