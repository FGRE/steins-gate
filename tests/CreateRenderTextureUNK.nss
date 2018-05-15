/* void CreateUNK(Handle, Width, Height, Color) 
   void UNK(Handle, X, Y, Source) */
chapter main
{
    CreateRenderTexture("unk", 2050, 576, "#FF00FF");
    DrawToTexture("unk", 0, 0, "cg/ev/EV_C13BL.jpg");
    CreateTexture("tex", 0, 0, 0, "unk");
    WaitKey();
    Move("tex", 4000, -1025, 0, null, true);
    /* You can update it even after call to CreateTexture */
    DrawToTexture("unk", 1025, 0, "cg/ev/EV_C13BR.jpg");
    WaitKey();
    Exit();
}
