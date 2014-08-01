chapter main
{
    $a = 3;
    $b = $a - 1;
    $b -= 1;
    $a += 1;
    StArray();
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    WaitKey(3000);
    CreateTexture("TEST", 600, 0, 0, "cg/bg/bg10a2u.jpg");
    Wait(3000);
    func("herp", "derp");
}

function func($herp, $derp)
{
    CreateProcess("TEST3", 0, 0, 0, "thread");
}

function thread()
{
    VariableValue("$", "herp", "cherp");
    $temp = VariableValue("$", "derp");
    WriteFile($herp, $temp);
}
