   #ifndef TSGH
#define TSGH

#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Winapi.Windows.hpp>

class PACKAGE TSG : public TStringGrid
{
private:
    int FCellFontSize[50][50];

protected:
    DYNAMIC void __fastcall KeyDown(WORD &Key, TShiftState Shift);
    DYNAMIC void __fastcall MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y);
    virtual void __fastcall DrawCell(int ACol, int ARow, const TRect &Rect, TGridDrawState State);

public:
    __fastcall TSG(TComponent* Owner);
};

#endif
