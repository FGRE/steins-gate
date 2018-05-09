/* void Zoom(Handle, Time, XScale, YScale, Tempo, Wait) */
chapter main
{
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg07a1.jpg");
    WaitKey();
    Zoom("texture", 1000, 200, 200, null, true);
    WaitKey();
    Rotate("texture", 2000, 0, 0, 360, null, true);
    WaitKey();
    Zoom("texture", 1000, @800, @800, null, true);
    WaitKey();
    SetVertex("texture", 1000, 100);
    Zoom("texture", 1000, @1000, @1000, null, true);
    WaitKey();
    Exit();
}
