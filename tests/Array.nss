/* void Array(Handle, ...) */
#include "nss/libtest.nss"

chapter main
{
    Array($a, 0, 1, 2);
    Array($a[0], 0, 1, 2);
    /* Replaces old contents */
    Array($a[0], 3, 4, 5);
    PrintInt(Count($a[0]));
    PrintInt($a[0][2]);
    PrintInt($a/0/1);
    /* This is how arrays are actually stored */
    $a/0/1 = 100;
    PrintInt($a[0][1]);
    /* No such thing as out of bounds: a new element is created */
    $a[3] = 10;
    PrintInt(Count($a));
    /* It works in depth too */
    $b[1][3][4] = 14;
    $b[0][3][4] = 15;
    PrintInt(Count($b));
    /* Doesn't destroy in depth */
    Array($b, 0, 1, 2);
    PrintInt($b[0][3][4]);
    /* You can even skip indices */
    $a/9 = 14;
    /* But count doesnt depend on the highest index */
    PrintInt(Count($a));
    PrintInt($a[9]);
    PrintInt($a[8]);
    /* $c is both a variable and an array */
    $c = "foo";
    Array($c, 4, 5, 6);
    Print($c + "bar");
    Exit();
}
