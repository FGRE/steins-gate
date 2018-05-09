/* void Rotate(Handle, Time, unk, unk, Angle, Tempo, Wait) */
chapter main
{
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg07a1.jpg");
    WaitKey();
    Rotate("texture", 1000, 0, 0, 180, null, true);
    /* Angle is absolute unless @ is used */
    Rotate("texture", 1000, 0, 0, 360, null, true);
    Rotate("texture", 2000, 0, 0, @-360, null, true);
    WaitKey();
    /* SetVertex sets center of rotation */
    SetVertex("texture", 0, 0);
    Move("texture", 500, 100, 100, null, true);
    WaitKey();
    Zoom("texture", 1000, 200, 200, null, true);
    WaitKey();
    Rotate("texture", 2000, 0, 0, @-360, null, true);
    WaitKey();
    Exit();
}
