 #include <vcl.h>
#pragma hdrstop

#include "TSG.h"
#include <ctime>

#pragma package(smart_init)

__fastcall TSG::TSG(TComponent* Owner)
    : TStringGrid(Owner)
{
    DefaultColWidth = 60;
    DefaultRowHeight = 30;
    ColCount = 5;
    RowCount = 5;
    FixedCols = 0;
    FixedRows = 0;
    TabStop = true;
    Options = Options << goDrawFocusSelected;

    for (int r = 0; r < 50; r++)
        for (int c = 0; c < 50; c++)
            FCellFontSize[r][c] = 12;

    Font->Size = 12;

    srand(time(NULL));
}

void __fastcall TSG::KeyDown(WORD &Key, TShiftState Shift)
{
    if (Key == VK_F11)
    {
        for (int r = 0; r < RowCount; r++)
            for (int c = 0; c < ColCount; c++)
                Cells[c][r] = IntToStr(rand() % 21);

        Repaint();
        Key = 0;
        return;
    }

    if (Key == VK_ESCAPE)
    {
        for (int r = 0; r < RowCount; r++)
            for (int c = 0; c < ColCount; c++)
            {
                Cells[c][r] = "";
                FCellFontSize[r][c] = 12;
            }

        Repaint();
        Key = 0;
        return;
    }

    TStringGrid::KeyDown(Key, Shift);
}

void __fastcall TSG::MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TStringGrid::MouseDown(Button, Shift, X, Y);

    if (Button == mbLeft)
    {
        int ACol, ARow;
        MouseToCell(X, Y, ACol, ARow);

        if (ACol >= 0 && ARow >= 0 && ACol < ColCount && ARow < RowCount)
        {
            FCellFontSize[ARow][ACol] *= 2;

            if (FCellFontSize[ARow][ACol] > 48)
                FCellFontSize[ARow][ACol] = 48;

            Repaint();
        }

        SetFocus();
    }
}

void __fastcall TSG::DrawCell(int ACol, int ARow, const TRect &Rect, TGridDrawState State)
{
    Canvas->Brush->Color = clWhite;
    Canvas->FillRect(Rect);

    Canvas->Font->Assign(Font);
    Canvas->Font->Size = FCellFontSize[ARow][ACol];

    String text = Cells[ACol][ARow];

    int x = Rect.Left + 4;
    int y = Rect.Top + 4;

    Canvas->TextRect(Rect, x, y, text);

    Canvas->Brush->Style = bsClear;
    Canvas->Rectangle(Rect);
    Canvas->Brush->Style = bsSolid;
}
