/* void SetShade(Handle, Shade) */
chapter main
{
    Array($A, "EXTRALIGHT", "LIGHT", "MEDIUM", "SEMIHEAVY", "HEAVY",  "EXTRAHEAVY", "NOMORE");
    CreateTexture("tex", 100, 0, 0, "cg/bg/BG13A3.jpg");
    WaitKey();
    $i = 0;
    while ($i < Count($A))
    {
        SetShade("tex", $A[$i]);
        WaitKey();
        $i++;
    }
    Exit();
}
