/* void CreateScrollbar(Handle, Priority, X1, Y1, X2, Y2, unk, Min, Max, unk, unk, Type, Filename, Callback) */
/* void SetScrollbarValue(Handle, Value) */
/* void SetScrollbarWheelArea(Handle, X, Y, Width, Height) */
/* int ScrollbarValue(Handle) */
#include "nss/libtest.nss"

chapter main
{
    CreateColor("color", 1, 450, 200, 100, 100, "red");
    CreateScrollbar("scroll1", 0, 500, 0, 500, 576, 0, 10, 100, 300, 300, "VERTICAL", "cg/sys/achievements/scrollbar.png", "sc1");
    SetScrollbarValue("scroll1", 80);
    CreateScrollbar("scroll2", 0, 0, 250, 1024, 250, 0, 20, 100, 300, 300, "HORIZON", "cg/sys/achievements/scrollbar.png", "sc2");
    SetScrollSpeed("scroll2", 100);
    while (1)
    {
        select
        {
            case scroll1:
            {
            }
            case scroll2:
            {
            }
            if ($SYSTEM_keydown_t)
            {
                $brk = true;
                break;
            }
        }
        if ($brk)
        {
            break;
        }
    }
    PrintInt(ScrollbarValue("scroll1"));
    PrintInt(ScrollbarValue("scroll2"));
    Exit();
}
