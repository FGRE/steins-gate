function Print($str)
{
    $txt = ReadFile("debug.out");
    $out = $txt + $str + "\n";
    WriteFile("debug.out", $out);
}
