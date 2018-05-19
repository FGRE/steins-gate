chapter main
{
    /* S;G doesn't seem to support floats */
    $a = 10 / 3;
    Array($b, 4, 5, 6);
    AssocArray($b, "zero", "one", "two");
    Array($b[1], "foo", "bar");
    Array($c, 7, 8, 9);
    AssocArray($b[1], "foo1", "bar1");    
    Save(99);
    Exit();
}
