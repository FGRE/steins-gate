/* void CreateWindow(Handle, unk, X, Y, Width, Height, unk) */
chapter main
{
    CreateWindow("foo", 0, 100, 100, 1024 - 200, 576 - 200, false);
    CreateTexture("foo/tex", 100, 0, 0, "cg/bg/bg31n0.jpg");
    CreateColor("color", 50, 0, 0, 200, 200, "red");
    WaitKey();
    Move("foo", 1000, 0, 0, null, false);
    WaitKey();
    Exit();
}
