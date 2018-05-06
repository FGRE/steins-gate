/* void CreateEffect(Handle, Priority, X, Y, Width, Height, Effect); */
chapter main
{
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg07a1.jpg");
    CreateEffect("effect", 2, 0, 0, 300, 300, "NegaPosi");
    WaitKey();
    SetTone("texture", "NegaPosi");
    WaitKey();
    /* Seems to affect screen content no matter what */
    Delete("texture");
    WaitKey();
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg02e1.jpg");
    WaitKey();
    Exit();
}
