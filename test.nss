chapter main
{
    $a = 3;
    $b = $a - 1;
    $b -= 1;
    $a += 1;
    StArray();
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    WaitKey(3000);
    CreateTexture("TEST", 600, 0, 0, "cg/ev/EV_Z01A.jpg");
    Move("TEST", 0, 210, -70, "null", "true");
    SetVertex("TEST", 306, 404);
    Zoom("TEST", 0, 5000, 5000, "null", "true");
    Request("TEST", "Smoothing");
    Move("TEST", 1330, 0, 0, "Axl2", false);
    Zoom("TEST", 1330, 1050, 1050, "Axl2", false);
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
