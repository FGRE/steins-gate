/* void Shake(Handle, Time, XWidth, YWidth, unk, unk, unk, Tempo, Wait) */

#include "nss/function_stand.nss"

chapter main
{
    #GameLoading = "SteinsGate";
    StArray();
    PosSt("STBUF5", 294, @0);
    St("STBUF5", 1800, @0, @0, "MAY_AMB02");
    FadeSt("STBUF5", 133, true);
    WaitKey();
    /* Rapidly move position from current to current + (XWidth, YWidth) */
    Shake("@STBUF5*", 150, 10, 6, 0, 0, 1000, null, true);
    WaitKey();
    Exit();
}
