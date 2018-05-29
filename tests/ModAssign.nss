#include "nss/libtest.nss"

chapter main
{
    $var = 11;
    PrintInt($var);
    $var %= 2;
    PrintInt($var);
    $var = 8;
    $var %= 3;
    PrintInt($var);
    $var = 15;
    $var %= 4;
    PrintInt($var);
    Exit();
}
