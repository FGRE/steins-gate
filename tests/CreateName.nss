/* void CreateName(Handle) */
chapter main
{
    CreateName("foo");
    CreateName("foo/bar");
    CreateName("foo/bar/baz");
    CreateTexture("foo/bar/baz/tex", 0, 0, 0, "cg/bg/tit001.jpg");
    WaitKey();
    Exit();
}
