/* void CreateColor(Handle, Priority, X, Y, Width, Height, Color) */
chapter main
{
    /* Accepts case insensitive hex in form #rrggbb */
    CreateColor("color1", 0, 0, 0, 1024, 576, "#ffFF00");
    WaitKey();
    /* Actually anything before first of "0123456789abcdef" is ignored */
    CreateColor("color2", 1, 0, 0, 1024, 576, "ZZ++--ff00ff**");
    WaitKey();
    /* Accepts case insensitive constants */
    CreateColor("color3", 2, 0, 0, 1024, 576, "rEd");
    WaitKey();
    Exit();
}
