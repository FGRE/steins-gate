chapter main
{
    $a = 3;
    $b = $a - 1;
    $b -= 1;
    $a += 1;
    CreateTexture("DERP", 500, "center", "middle", "cg/ibg/ibg003.png");
    SetAlias("DERP", "DERP");
    Wait(1000);
    Delete("@DERP");
    CreateMovie("Movie", 11100, 0, 0, "false", "false", "dx/timeleapbg.ngs", "true");
    Request("Movie", "Play");
    Wait(DurationTime("Movie"));
    Delete("Movie");
    CreateSound("TestSE", "SE", "sound/se/cosupure.ogg");
    Request("TestSE", "Play");
    Wait(DurationTime("TestSE"));
    StArray();
    CreateTexture("TEST0", 500, 0, 0, "cg/ev/EV_C02C.jpg");
    ApplyBlur("TEST0", "SEMIHEAVY");
    WaitKey(3000);
    Delete("TEST0");
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    Fade("TEST2", 0, 0, "derp", "true");
    Fade("TEST2", 1000, 1000, "derp", "true");
    WaitKey(2000);
    Fade("TEST2", 1000, 0, "derp", "true");
    CreateTexture("TEST", 600, 0, 0, "cg/ev/EV_Z01A.jpg");
    Move("TEST", 0, 210, -70, "null", "true");
    SetVertex("TEST", 306, 404);
    Zoom("TEST", 0, 5000, 5000, "null", "true");
    Request("TEST", "Smoothing");
    Move("TEST", 1330, 0, 0, "Axl2", "false");
    Zoom("TEST", 1330, 1050, 1050, "Axl2", "true");
    CreateTexture("TEST3", 9000, 0, 0, "cg/bg/BG_BLACK.jpg");
    DrawTransition("TEST3", 1000, 0, 250, 0, "null", "cg/data/mask17.png", "true");
    WaitKey(3000);
    func("herp", "derp");
}

function func($herp, $derp)
{
    CreateProcess("TEST3", 0, 0, 0, "thread");
    Request("TEST3", "Start");
}

function thread()
{
    VariableValue("$", "herp", "cherp");
    $temp = VariableValue("$", "derp");
    WriteFile($herp, $temp);
}
