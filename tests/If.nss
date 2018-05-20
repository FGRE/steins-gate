#include "nss/libtest.nss"

function f($i)
{
    if ($i == 0)
    {
        Print("zero");
    }
    else if ($i == 1)
    {
        Print("one");
    }
    else if ($i == 2)
    {
        Print("two");   
    }
    else
    {
        Print(">2");
    }
}

chapter main
{
    f(0);
    f(1);
    f(2);
    f(3);
    Exit();
}
