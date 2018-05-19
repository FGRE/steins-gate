#include "nss/libtest.nss"

chapter main
{
    $var1 = "foo";
    $var2 = "bar";
    VariableValue("$", "var1", "fooey");
    Print($var1);
    Print(VariableValue("$", "var2"));
    Exit();
}
