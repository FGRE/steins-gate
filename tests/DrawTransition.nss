/* void DrawTransition(Handle, Time, Start, End, Boundary, Tempo, Filename, Wait) */
chapter main
{
    CreateTexture("texture", 1, 0, 0, "cg/bg/bg07a1.jpg");
    WaitKey();
    DrawTransition("texture", 2000, 1000, 750, 250, "null", "cg/data_inv/mask17.png", "true");
    DrawTransition("texture", 2000, 750, 1000, 250, "null", "cg/data_inv/mask17.png", "true");
    WaitKey();
    Exit();
}
