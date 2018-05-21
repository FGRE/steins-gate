/* void CreateText(Handle, Priority, X, Y, Width, Height, String) */
chapter main
{
    SetFont("ＭＳ ゴシック", 60, "#FF0000", "#00FF00", 500, "RIGHTDOWN");
    CreateText("text1", 0, 0, 0, "auto", "auto", "鳳凰院凶真");
    SetFont("ＭＳ ゴシック", 60, "#00ff00", "#0000ff", 500, "LEFTUP");
    CreateText("text2", 0, 0, 60, "auto", "auto", "鳳凰院凶真");
    WaitKey();
    Delete("text1");
    Delete("text2");
    SetFont("ＭＳ ゴシック", 16, "FFFFFF", "000000", 500, "RIGHTDOWN");
    CreateText("text3", 0, 0, 0, 200, "Auto", "AAAAAAAAAAAAAAAAAAAAAAAA");
    WaitKey();
    Exit();
}
