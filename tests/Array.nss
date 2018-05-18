/* void Array(Handle, ...) */
#include "nss/libtest.nss"

chapter main
{
    Array($a, 0, 1, 2);
    Array($a[0], 0, 1, 2);
    /* Destroys old array */
    Array($a[0], 3, 4, 5);
    PrintInt(Count($a[0]));
    PrintInt($a[0][2]);
    Exit();
}
