chapter main
{
    CreateWindow("foo", 0, 100, 100, 1024 - 200, 576 - 200, false);
    CreateTexture("foo/tex", 0, 0, 0, "cg/bg/bg31n0.jpg");
    WaitKey();
    Move("foo", 1000, 0, 0, null, false);
    WaitKey();
    Exit();
}
