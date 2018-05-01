/* void CreateTexture(Handle, Priority, X, Y, Source) */
chapter main
{
    /* From cg.npa */
    CreateTexture("texture1", 1, 0, 0, "cg/bg/bg07a1.jpg");
    CreateTexture("texture2", 2, 0, 0, "cg/st/crs_ala01a.png");
    WaitKey();
    /* CreateTexture also accepts SCREEN */
    LoadImage("image1", "SCREEN");
    Delete("texture1");
    Delete("texture2");
    WaitKey();
    /* From Image */
    CreateTexture("texture3", 0, 0, 0, "image1");
    WaitKey();
    Exit();
}
