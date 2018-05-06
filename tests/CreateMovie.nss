/* void CreateMovie(Handle, Priority, X, Y, Loop, Alpha, File, Audio); */

#include "nss/libtest.nss"

chapter main
{
    CreateMovie("movie", 0, 0, 0, "true", "false", "dx/demo.ngs", "true");
    WaitKey();
    /* Doesn't autoplay */
    Request("movie", "Play");
    WaitKey();
    Print(PassageTime("movie"));
    Delete("movie");
    Exit();
}
