/* void SetTone(Handle, Tone); */
chapter main
{
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg07a1.jpg");
    WaitKey();
    SetTone("texture", "Monochrome");
    WaitKey();
    SetTone("texture", "NegaPosi");
    WaitKey();
    SetTone("texture", "Sepia");
    WaitKey();
    SetTone("texture", "KitanoBlue");
    WaitKey();
    Delete("texture");
    WaitKey();
    Exit();
}
