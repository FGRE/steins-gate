chapter main
{
    $a = 3;
    $b = $a - 1;
    $b -= 1;
    $a += 1;
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    func("herp", "derp");
    WaitKey(3000);
    CreateTexture("TEST", 600, 0, 0, "cg/bg/bg10a2u.jpg");
    Wait(3000);
}

function func($herp, $derp)
{
    WriteFile($herp, $derp);
}
