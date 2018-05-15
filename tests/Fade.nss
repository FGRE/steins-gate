/* void Fade(Handle, Time, Opacity, Tempo, Wait) */
chapter main
{
    CreateColor("color1", 0, 0, 0, 1024, 576, "red");
    WaitKey();
    Fade("color1", 1500, 0, "null", "true");
    Fade("color1", 1500, 1000, "null", "false");
    WaitFade("color1", null);
    Exit();
}
