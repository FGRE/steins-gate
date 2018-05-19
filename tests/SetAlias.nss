/* void SetAlias(Handle, Alias) */

chapter main
{
    CreateColor("color", 0, 0, 0, 100, 100, "green");
    SetAlias("color", "alias");
    WaitKey();
    Move("alias", 2000, 1024 - 100, 576 - 100, null, true);
    WaitKey();
    Exit();
}
