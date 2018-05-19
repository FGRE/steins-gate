/* void VariableValue(Type, Identifier, Value) */
/* Value VariableValue(Type, Identifier) */
#include "nss/libtest.nss"

chapter main
{
    $var1 = "foo";
    $var2 = "bar";
    VariableValue("$", "var1", "fooey");
    Print($var1);
    Print(VariableValue("$", "var2"));
    /* It seems to support only one level of indexing */
    $a[3] = "value";
    Print(VariableValue("$", "a[3]"));
    Exit();
}
