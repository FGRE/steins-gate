/* void CreateStencil(Handle, unk, X, Y, unk, Filename, unk) */
chapter main
{
    CreateTexture("bg", 1, 0, 0, "cg/ibg/ibg051.jpg");
    CreateStencil("ste", 0, "Center", 0, 128, "cg/st/may_amc02a.png", false);
    CreateTexture("ste/msk", 2, 0, 0, "cg/bg/bg07a1.jpg");
    WaitKey();
    Exit();
}
