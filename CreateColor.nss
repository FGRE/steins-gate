/* void CreateColor(Handle, Priority, X, Y, Width, Height, Color) */
chapter main
{
    /* Accepts hex in form #rrggbb */
    CreateColor("color1", 0, 0, 0, 1024, 576, "#ffFF00");
    WaitKey();
    /* Case insensitive */
    CreateColor("color2", 1, 0, 0, 1024, 576, "rEd");
    WaitKey();
    Exit();
}
