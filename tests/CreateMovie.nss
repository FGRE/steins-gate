/* void CreateMovie(Handle, Priority, X, Y, Loop, Alpha, File, Audio); */

#include "nss/libtest.nss"

chapter main
{
    WaitKey();
    CreateMovie("movie", 0, 0, 0, "true", "false", "dx/demo.ngs", "true");
    /* Doesn't autoplay */
    Request("movie", "Play");
    WaitKey();
    Print(PassageTime("movie"));
    Exit();
}
