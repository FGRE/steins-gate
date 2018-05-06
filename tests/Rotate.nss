/* void Rotate(Handle, Time, unk, unk, Angle, Tempo, Wait) */
chapter main
{
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg07a1.jpg");
    WaitKey();
    Rotate("texture", 2000, 0, 0, 180, null, true);
    /* Angle is absolute unless @ is used */
    Rotate("texture", 2000, 0, 0, 360, null, true);
    Rotate("texture", 4000, 0, 0, @-360, null, true);
    WaitKey();
    /* SetVertex sets center of rotation */
    SetVertex("texture", 0, 0);
    Rotate("texture", 2000, 0, 0, @-360, null, true);
    WaitKey();
    Exit();
}
