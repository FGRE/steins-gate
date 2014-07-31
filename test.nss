chapter main
{
    $a = 3;
    $b = $a - 1;
    $b -= 1;
    $a += 1;
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    func("herp", "derp");
    CreateTexture("TEST", 600, 0, 0, "cg/bg/bg10a2u.jpg");
}

function func($herp, $derp)
{
    WriteFile($herp, $derp);
}
