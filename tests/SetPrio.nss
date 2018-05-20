chapter main
{
    CreateColor("color1", 0, 0, 0, 1024, 576, "red");
    CreateColor("color2", 1, 0, 0, 1024, 576, "green");
    WaitKey();
    SetPrio("color1", 2);
    WaitKey();
    SetPrio("color1", 0);
    WaitKey();
    Exit();
}
