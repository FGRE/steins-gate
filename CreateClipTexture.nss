/* void CreateClipTexture(Handle, Priority, X, Y, CX, CY, Width, Height, Source) */
chapter main
{
    CreateClipTexture("texture1", 0, 100, 100, 0, 0, 400, 400, "cg/ibg/ibg007.jpg");
    WaitKey();
    Exit();
}
