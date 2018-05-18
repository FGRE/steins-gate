/* void Move(Handle, Time, X, Y, Tempo, Wait) */
chapter main
{
    CreateColor("color", 1, -100, -100, 100, 100, "red");
    Array($tempo, "Axl1", "Axl2", "Axl3", "Dxl1", "Dxl2", "Dxl3", "AxlDxl", "DxlAxl", "AxlAuto", "DxlAuto");
    $i = 0;
    while ($i < Count($tempo))
    {
        WaitKey();
        Move("color", 0, 0, 0, null, true);
        CreateText("text", 0, Center, 0, "auto", "auto", $tempo[$i]);
        WaitKey();
        Move("color", 1500, 1024 - 100, 576 - 100, $tempo[$i], false);
        $i++;
    }
    WaitKey();
    Exit();
}
